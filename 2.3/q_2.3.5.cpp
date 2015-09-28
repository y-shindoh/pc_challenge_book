/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.3.5.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.3の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  合計値に対するその時点の整数を何回使ったかの表を作り、
  整数の種類を1つずつ増やしていき表を更新する。
  最終的に指定した合計値があるかどうかを確認する。
  (注意: 自力では計算量の爆発しやすい解法しか思いつかなかった)
 */

#include <cstddef>
#include <cstdio>
#include <climits>
#include <vector>

int
main()
{
	const int n(3);
	const int a[] = {3, 5, 8};
	const int m[] = {3, 2, 2};
	const int K(17);

	std::vector<int> b;
	int h, k;

	b.resize(K+1, INT_MAX);
	b[0] = 0;

	for (int i(0); i < n; ++i) {
		if (0 < i) {
			for (int j(0); j < K; ++j) {
				if (b[j] == INT_MAX) continue;
				b[j] = 0;
			}
		}
		for (int j(0); j < K; ++j) {
			if (b[j] == INT_MAX) continue;
			if (m[i] <= b[j]) continue;
			k = j + a[i];	// 合計値
			if (K < k) break;
			h = b[j] + 1;	// 整数の使用回数
			if (b[k] <= h) continue;
			b[k] = h;
		}
		if (b[K] != INT_MAX) break;
	}

	if (b[K] != INT_MAX) {
		std::printf("FOUND!\n");
	}
	else {
		std::printf("NOT FOUND!\n");
	}

	return 0;
}
