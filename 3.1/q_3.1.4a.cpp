/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_3.1.4a.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§3.1 p.132の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  求める平均値をAとすると、式 ΣV / ΣW = A が成立する。
  この式を変形すると、ΣV = ΣAW ⇒ ΣV-AW = 0 となる。
  この時、
  Aが小さすぎた場合は ΣV-AW ≧ 0 に、
  Aが大きすぎた場合は ΣV-AW ≦ 0 になる。

  また、ΣV-AW の各項は指定個しか使わないので、
  各 V-AW の大きい方から指定個だけ使うようにする。

  備考:
  自力で考えたのはDPを用いた O(kn) の解法。
  本解法は書籍のもの。
 */

#include <cstdio>
#include <climits>
#include <algorithm>

double
evaluate(const std::pair<int, int>* wv,
		 int l,
		 int k,
		 double m,
		 double* b)
{
	for (int i(0); i < l; ++i) {
		b[i] = wv[i].second - m * wv[i].first;
	}

	std::sort<double*>(b, b + l);

	double r(0);

	for (int i(0); i < k; ++i) {
		int j = l - i - 1;
		r += b[j];
	}

	return r;
}

int
main()
{
	int n(3);
	int k(2);
	const std::pair<int, int> wv[] = {std::pair<int, int>(2, 2),
									  std::pair<int, int>(5, 3),
									  std::pair<int, int>(2, 1)};

	double s(INT_MAX);	// 最良値の上限
	double e(0.0);		// 最良値より上の値の下限
	double t;

	for (int i(0); i < n; ++i) {
		t = (double)wv[i].second / (double)wv[i].first;
		if (t < s) s = t;
		if (e < t) e = t;
	}

	double a;
	double b[3];

	while (s + 0.01 <= e) {
		t = (s + e) / 2.0;
		a = evaluate(wv, n, k, t, b);
		if (0.0 <= a) s = t;
		else e = t;
	}

	std::printf("%.2f\n", (int)(s * 100) / 100.0);

	return 0;
}
