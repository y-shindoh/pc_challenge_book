/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_3.1.2.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§3.1 p.129の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  0〜ΣL_i/Kを対象とした二部探索を使う。
  本数が多いか適切な場合は始点を終点よりに、本数が少ない場合は終点を始点よりに移動する。
 */

#include <cstdio>

int
main()
{
	int N(4);
	int K(11);
	const double L[] = {8.02, 7.43, 4.57, 5.39};

	double s(0.0);	// K本以下
	double e(0.0);	// K本を超える
	double t;
	int n;

	for (int i(0); i < N; ++i) e += L[i];
	e /= (double)N;

	while (s + 0.01 <= e) {
		t = (s + e) / 2.0;
		n = 0;
		for (int i(0); i < N; ++i) n += (int)(L[i] / t);
		if (n < K) e = t;
		else s = t;
	}

	std::printf("%.2f\n", (int)(s * 100) / 100.0);

	return 0;
}
