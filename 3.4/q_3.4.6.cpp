/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_3.4.6.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§3.4 p.183の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  行列を用いた解法が書籍に掲載されていたが、後回し。
 */

#include <cstddef>
#include <cstdio>
#include <algorithm>

#define	N	4
#define	K	2

int
main()
{
	size_t dp[2][N];
	size_t g[][2] = {{0, 1},
					 {0, 2},
					 {1, 2},
					 {2, 3},
					 {3, 0}};

	size_t c(0);
	size_t n(1);

	std::fill(dp[c], dp[c] + N, (size_t)1);

	for (size_t i(0); i < K; ++i) {
		std::fill(dp[n], dp[n] + N, (size_t)0);
		for (size_t j(0); j < sizeof(g) / sizeof(g[0]); ++j) {
			dp[n][g[j][1]] += dp[c][g[j][0]];
			//dp[n][g[j][1]] %= (size_t)10007;
		}
		c ^= (size_t)1;
		n ^= (size_t)1;
	}

	size_t r(0);

	for (size_t i(0); i < N; ++i) r += dp[c][i];

	std::printf("%lu\n", r);

	return 0;
}
