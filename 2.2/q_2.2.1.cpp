/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.2.1.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.2 p.42の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

#include <cstdio>
#include <algorithm>

/*
  メモ:
  額の大きな硬貨を優先的に多く使う。
 */

int
calculate(const int* V,
		  const int* C,
		  const int N,
		  const int A)
{
	if (0 < N) {
		const int i = N - 1;

		// 2000円札が入力される場合も考慮して、ここではちゃんと探索
		for (int j = std::min(A / V[i], C[i]); 0 <= j; --j) {
			if (A == V[i] * j) return j;
			int x = calculate(V, C, i, A - V[i] * j);
			if (x < 0) continue;
			return x + j;
		}
	}

	return -1;
}

#define	N	6

int
main()
{
	const int V[N] = {1, 5, 10, 50, 100, 500};
	const int C[N] = {3, 2, 1, 3, 0, 2};
	int A(620);

	int r = calculate(V, C, N, A);

	std::printf("%d\n", r);

	return 0;
}
