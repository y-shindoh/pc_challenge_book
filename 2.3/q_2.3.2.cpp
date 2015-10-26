/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.3.2.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.3 p.56の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  1つめの文字列のi番目、2つ目の文字列のj番目までを使った場合の
  最長一致部分文字列長を算出して保持するテーブルを作り、
  テーブルの右下を参照する。
 */

#include <cstddef>
#include <cstdio>
#include <cstring>
#include <vector>

#define	N	4
#define	M	4

int
main()
{
	const char s[N+1] = "abcd";
	const char t[M+1] = "becd";

	int b[N][M];

	for (int i(0); i < N; ++i) {
		std::memset((void*)b[i], 0, sizeof(int) * (size_t)M);
	}

	for (int i(0); i < N; ++i) {
		for (int j(0); j < M; ++j) {
			// 文字の一致状況は関係ない
			if (0 < i && b[i][j] < b[i-1][j]) b[i][j] = b[i-1][j];
			if (0 < j && b[i][j] < b[i][j-1]) b[i][j] = b[i][j-1];
			// 文字が一致している時
			if (s[i] == t[j]) {
				if (0 < i && 0 < j) {
					if (b[i][j] < b[i-1][j-1] + 1) b[i][j] = b[i-1][j-1] + 1;
				}
				else {
					b[i][j] = 1;
				}
			}
		}
	}

	std::printf("%d\n", b[N-1][M-1]);

	return 0;
}
