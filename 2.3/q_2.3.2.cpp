/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.3.2.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.3の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  1つめの文字列のi番目、2つ目の文字列のj番目までに関する
  最長一致部分文字列の長さを算出して保持するテーブルを作り、
  テーブルの右下を参照する。
 */

#include <cstddef>
#include <cstdio>
#include <cstring>
#include <vector>

int
main()
{
	int n(4);
	const char s[] = "abcd";

	int m(4);
	const char t[] = "becd";

	int** b;

	b = new int*[n];
	for (int i(0); i < n; ++i) {
		b[i] = new int[m];
		std::memset((void*)b[i], 0, sizeof(int) * m);
	}

	for (int i(0); i < n; ++i) {
		for (int j(0); j < m; ++j) {
			// 文字の一致状況は関係ない
			if (0 < i && b[i][j] < b[i-1][j]) b[i][j] = b[i-1][j];
			if (0 < j && b[i][j] < b[i][j-1]) b[i][j] = b[i][j-1];
			// 文字が一致している時
			if (s[i] == t[j]) {
				if (0 < i && 0 < j) {
					if (b[i][j] < b[i-1][j-1] + 1) b[i][j] = b[i-1][j-1] + 1;
				}
				else {
					if (b[i][j] < 1) b[i][j] = 1;
				}
			}
		}
	}

	std::printf("%d\n", b[n-1][m-1]);

	for (int i(0); i < n; ++i) {
		delete [] b[i];
	}
	delete [] b;


	return 0;
}
