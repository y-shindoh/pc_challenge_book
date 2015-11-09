/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_3.2.2.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§3.2 p.137の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  しゃくとり法のパターン。計算量は O(n)。
 */

#include <cstdio>
#include <algorithm>

#define	P	5
#define	N	2	// ページの種類 (計算量は O(n))

int
main()
{
	const int a[] = {0, 1, 1, 1, 0};	// ID付け替え済み (計算量は O(n))

	int b[N];	// ページの種類ごとの区間内出現数
	int w(N+1);	// 区間のページ数 (最小値)
	int k(0);	// 区間内のページの種類数
	int s(0);	// 区間の先頭
	int e(0);	// 区間の末尾+1

	std::fill(b, b + N, 0);

	while (s < P) {
		while (k < N && e < P) {
			if (b[a[e]] == 0) ++k;
			++b[a[e++]];
		}
		if (N <= k && e - s < w) w = e - s;
		if (b[a[s]] == 1) --k;
		--b[a[s++]];
	}

	if (w <= N) {
		std::printf("Yes (%d)\n", w);
	}
	else {
		std::printf("No\n");
	}

	return 0;
}
