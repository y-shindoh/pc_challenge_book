/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_3.3.1b.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§3.2 p.156の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  セグメント木の手法で解く。
  セグメント木の各区間は、
  区間の始まりを座標 (0, 0) 角度 180度と仮定し、
  区間の終わりの座標と角度を表現する。
 */

#include <cstdio>
#include <cmath>
#include <vector>

void
update(std::vector<double>& x,
	   std::vector<double>& y,
	   std::vector<int>& a,
	   int i,
	   int n,
	   int m)
{
	i += m;
	n += m - 1;

	while (2 <= i) {
		int k = i / 2;
		i = k * 2;
		int j = i + 1;
		x[k] = x[i];
		y[k] = y[i];
		a[k] = a[i];
		if (j <= n) {
			double t = 2 * M_PI * (a[i] - 180) / 360.0;
			x[k] += std::cos(t) * x[j] - std::sin(t) * y[j];
			y[k] += std::sin(t) * x[j] + std::cos(t) * y[j];
			a[k] = (a[k] + (a[j] - 180)) % 360;
		}
		i = k;
		n /= 2;
	}
}

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

	std::vector<double> x, y;	// 各クレーンの終点の座標 (セグメント木)
	std::vector<int> a;			// 各クレーンの終点の角度

	int m(1);

	while (m <= N) m <<= 1;

	x.resize(m * 2, 0.0);
	y.resize(m * 2, 0.0);
	a.resize(m * 2, 180);

	for (int i(0); i < N; ++i) y[m+i] = (double)L[i];
	for (int i(0); i < N; i += 2) update(x, y, a, i, N, m);

	for (int k(0); k < C; ++k) {
		a[m+S[k]-1] = A[k];
		update(x, y, a, S[k]-1, N, m);
		std::printf("%f, %f (%d)\n", x[1], y[1], a[1]);
	}

	return 0;
}
