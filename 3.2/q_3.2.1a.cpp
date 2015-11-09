/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_3.2.1a.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§3.2 p.135の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  二分探索のパターン。計算量は O(n log n)。
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

	int b[N+1];

	b[0] = 0;
	for (int i(1); i < N+1; ++i) b[i] = b[i-1] + a[i-1];

	int h(N+1);

	for (int i(0); i < N; ++i) {
		int s(i);	// S未満の先頭
		int e(N+1);	// S以上の末尾
		while (s + 1 < e) {
			int j = (s + e) / 2;
			if (S <= b[j] - b[i]) e = j;
			else s = j;
		}
		if (e == N + 1) break;		// S以上の和が見つからなかった
		if (b[e] - b[i] < S) break;	// S以上の和が見つからなかった (本来は不要)
		if (h <= e - i) continue;	// 以前見つけた和の部分列の長さ以上
		h = e - i;
	}

	if (h <= N) {
		std::printf("Yes (%d)\n", h);
	}
	else {
		std::printf("No\n");
	}

	return 0;
}
