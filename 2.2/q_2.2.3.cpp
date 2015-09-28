/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.2.3.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.2の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  文字列Sの先頭と末尾の文字を比較し、
  小さいものを取り出してTの末尾に追加する。
  ただし、同じ文字の場合は、
  次の位置の文字 (※) が小さいものの側を取り出すようにする。
  ※は繰り返す可能性あり。
 */

#include <cstddef>
#include <cstdio>
#include <cstring>

int compare(const char* S,
			int i,
			int j)
{
	while (i < j) {
		if (S[i] < S[j]) return -1;
		if (S[j] < S[i]) return 1;
		++i;
		--j;
	}

	return 0;
}

int
main()
{
	int N(6);
	char S[] = "ACDBCB";
	char T[7];

	std::memset((void*)T, 0, sizeof(T));
	std::printf("S: '%s'\n", S);
	std::printf("T: '%s'\n", T);

	int i(0);
	int j(N-1);

	for (int k(0); k < N; ++k) {
		if (compare(S, i, j) <= 0) {
			T[k] = S[i];
			++i;
		}
		else {
			T[k] = S[j];
			S[j] = '\0';
			--j;
		}

		std::printf("S: '%s'\n", S + i);
		std::printf("T: '%s'\n", T);
	}

	return 0;
}
