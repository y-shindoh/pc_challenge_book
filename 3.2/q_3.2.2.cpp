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
#include <cstring>

int
main()
{
	int P(5);
	int n(2);	// ページの種類 (計算量は O(n))
	const int a[] = {0, 1, 1, 1, 0};	// ID付け替え済み (計算量は O(n))

	int b[16];
	int w(n+1);
	int k(0);
	int s(0);
	int e(1);

	std::memset((void*)b, 0, sizeof(b));
	++b[a[0]];
	++k;

	while (s < P) {
		while (k < n && e < P) {
			if (b[a[e]] == 0) ++k;
			++b[a[e++]];
		}
		if (n <= k && e - s < w) w = e - s;
		if (b[a[s]] == 1) --k;
		--b[a[s++]];
	}

	if (w <= n) {
		std::printf("Yes (%d)\n", w);
	}
	else {
		std::printf("No\n");
	}

	return 0;
}
