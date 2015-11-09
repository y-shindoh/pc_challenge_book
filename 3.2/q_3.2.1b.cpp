/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_3.2.1b.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§3.2 p.135の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  しゃくとり法のパターン。計算量は O(n)。
 */

#include <cstdio>

#define	N	10
#define	S	15
//#define	N	5
//#define	S	11

int
main()
{
	const int a[N] = {5, 1, 3, 5, 10, 7, 4, 9, 2, 8};
//	const int a[N] = {1, 2, 3, 4, 5};

	int s(0);	// 部分列の先頭
	int e(0);	// 部分列の末尾+1
	int c(0);	// 部分列の要素の和
	int l(N+1);	// 部分列の長さ (最小値)

	while (s < N) {
		if (e < N && c < S) {
			c += a[e++];
		}
		else {
			if (S <= c && e - s < l) l = e - s;
			c -= a[s++];
		}
	}

	if (l <= N) {
		std::printf("Yes (%d)\n", l);
	}
	else {
		std::printf("No\n");
	}

	return 0;
}
