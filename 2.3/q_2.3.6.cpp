/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.3.6.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.3 p.63の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  増加部分列の長さに対するその時点での整数の最小値の表を作り、
  数列を1つずつ進めて表を更新する。
  最終的に表で最小値が更新された最も末尾寄りの値が回答になる。
 */

#include <cstdio>
#include <climits>
#include <algorithm>

#define	N	5

int
main()
{
	const int a[N] = {4, 2, 3, 1, 5};

	int b[N];

	std::fill(b, b + N, INT_MAX);

	for (int i(0); i < N; ++i) {
		*std::upper_bound(b, b + N, a[i]) = a[i];
	}

	std::printf("%lu\n", std::lower_bound(b, b + N, INT_MAX) - b);

	return 0;
}
