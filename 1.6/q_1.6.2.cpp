/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_1.6.2.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§1.6の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

#include <cstddef>
#include <cstdio>

int
main(void)
{
	int L(10);
	int n(3);
	int x[] = {2, 6, 7};

	int max(0);
	int min(0);

	for (int i(0); i < n; ++i) {
		if (x[i] < L - x[i]) {
			if (max < L - x[i]) max = 10 - x[i];
			if (min < x[i]) min = x[i];
		}
		else {
			if (max < x[i]) max = x[i];
			if (min < L - x[i]) min = L - x[i];
		}
	}

	std::printf("min = %d\n", min);
	std::printf("max = %d\n", max);

	return 0;
}
