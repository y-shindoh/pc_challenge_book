/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_3.4.5.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§3.4 p.182の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  行列を用いた解法が書籍に掲載されていたが、後回し。
 */

#include <cstdio>
#include <utility>

int
main()
{
//	int N(1);
	int N(2);

	size_t ee[2];	// 赤: 偶数, 緑: 偶数
	size_t eo[2];	// 赤: 偶数, 緑: 奇数
	size_t oe[2];	// 赤: 奇数, 緑: 偶数
	size_t oo[2];	// 赤: 奇数, 緑: 奇数

	size_t c(0);
	size_t n(1);

	ee[c] = 1;
	eo[c] = oe[c] = oo[c] = 0;

	for (int i(0); i < N; ++i) {
		ee[n] = ee[c] * 2 + oe[c] + eo[c];
		eo[n] = eo[c] * 2 + oo[c] + ee[c];
		oe[n] = oe[c] * 2 + ee[c] + oo[c];
		oo[n] = oo[c] * 2 + eo[c] + oe[c];

//		ee[n] %= 10007;
//		eo[n] %= 10007;
//		oe[n] %= 10007;
//		oo[n] %= 10007;

		c ^= (size_t)1;
		n ^= (size_t)1;
	}

	std::printf("%lu\n", ee[c]);

	return 0;
}
