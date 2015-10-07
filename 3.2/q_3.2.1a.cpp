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

int
main()
{
	int n(10);
	int S(15);
	const int a[] = {5, 1, 3, 5, 10, 7, 4, 9, 2, 8};

//	int n(5);
//	int S(11);
//	const int a[] = {1, 2, 3, 4, 5};

	int b[16];

	b[0] = a[0];
	for (int i(1); i < n; ++i) b[i] = b[i-1] + a[i];

	int h(n+1);

	for (int i(0); i < n; ++i) {
		int s(i);	// S未満の先頭
		int e(n);	// S以上の末尾
		while (s + 1 < e) {
			int j = (s + e) / 2;
			if (S <= b[j] - b[i]) e = j;
			else s = j;
		}
		if (e == n) continue;
		if (e - i < h) h = e - i;
	}

	if (h <= n) {
		std::printf("Yes (%d)\n", h);
	}
	else {
		std::printf("No\n");
	}

	return 0;
}
