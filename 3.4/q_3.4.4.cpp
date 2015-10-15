/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_3.4.4.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§3.4 p.180の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  行列を用いた解法が書籍に掲載されていたが、後回し。
 */

#include <cstdio>

// 通常のDP (計算量は O(n))
size_t
fib(size_t n)
{
	if (n <= 1) return n;

	size_t p2(0);
	size_t p1(1);
	size_t c;

	for (size_t i(2); i <= n; ++i) {
		c = p1 + p2;
		c %= 10000;
		p2 = p1;
		p1 = c;
	}

	return c;
}

// 行列を用いたDB


int
main()
{
	int n(10);

	std::printf("%lu\n", fib(n));
	std::printf("後回し。\n");

	return 0;
}
