/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_3.3.1a.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§3.2 p.156の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  素直に実装すると、 O(N * C) の計算量になる。

  備考:
  高速に解く手法を思いつかなかったので、とりあえずの簡単な解法。
 */

#include <cstdio>
#include <cmath>
#include <vector>

int
main()
{
//	int N(2);
//	int C(1);
//	const int L[] = {10, 5};
//	const int S[] = {1};
//	const int A[] = {90};

	int N(3);
	int C(2);
	const int L[] = {5, 5, 5};
	const int S[] = {1, 2};
	const int A[] = {270, 90};

	std::vector<int> a;

	a.resize(N-1, 180);
	for (int i(0); i < C; ++i) {
		a[S[i]-1] = A[i];

		double x(0);
		double y(L[0]);
		double t(180.0);
		for (int j(0); j + 1 < N; ++j) {
			t += (double)a[j] - 180.0;
			x += L[j+1] * std::sin(2 * M_PI * t / 360.0);
			y += L[j+1] * -1 * std::cos(2 * M_PI * t / 360.0);
		}

		std::printf("[%d] %f, %f\n", i, x, y);
	}

	return 0;
}
