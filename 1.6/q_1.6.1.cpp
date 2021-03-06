/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_1.6.1.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§1.6の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

#include <cstddef>
#include <cstdio>

int
main(void)
{
	int a[] = {10, 5, 4, 3, 2};	// 降順ソート済み (計算量 O(n log n))
	int n(5);
	int r(0);

	// 探索 (計算量 O(n))
	for (int i(0); i + 2 < n; ++i) {
		if (a[i] >= a[i+1] + a[i+2]) continue;		// 三角形不成立
		r = a[i] + a[i+1] + a[i+2];
		break;	// ソーティング済みのため、探索範囲が限定されている
	}

	std::printf("%d\n", r);

	return 0;
}
