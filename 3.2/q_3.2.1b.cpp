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

int
main()
{
	int n(10);
	int S(15);
	const int a[] = {5, 1, 3, 5, 10, 7, 4, 9, 2, 8};

//	int n(5);
//	int S(11);
//	const int a[] = {1, 2, 3, 4, 5};

	int t(a[0]);
	int s(0);
	int e(1);
	int h(n+1);

	while (s < n) {
		while (t < S && e < n) t += a[e++];
		if (S <= t && e - s < h) h = e - s;
		t -= a[s++];
	}

	if (h <= n) {
		std::printf("Yes (%d)\n", h);
	}
	else {
		std::printf("No\n");
	}

	return 0;
}
