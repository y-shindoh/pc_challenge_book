/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.2.1.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.2の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

#include <cstddef>
#include <cstdio>
//#include <algorithm>

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

		for (int j(C[i]); 0 <= j; --j) {
			if (A < V[i] * j) continue;
			if (A == V[i] * j) return j;
			// 題意に曖昧性があるので、ちゃんと探索する
			int x = calculate(V, C, i, A - V[i] * j);
			if (x < 0) continue;
			return x + j;
		}

//		int x(0);
//		int y(0);
//
//		for (int i(N-1); 0 <= i; --i) {
//			int t = std::min<int>((A - x) / V[i], C[i]);
//			x += t * V[i];
//			y += t;
//			if (x == A) return y;
//		}
	}

	return -1;
}

int
main()
{
	const int V[] = {1, 5, 10, 50, 100, 500};
	const int C[] = {3, 2, 1, 3, 0, 2};
	int N(6);
	int A(620);

	int r = calculate(V, C, N, A);

	std::printf("%d\n", r);

	return 0;
}
