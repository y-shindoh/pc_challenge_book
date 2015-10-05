/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_3.1.4b.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§3.1 p.132の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  使った商品数と重さ・価値のDPテーブルを、価値/重さが最良値になる条件で更新し、
  最終的な価値/重さの最良値を導き出す。
 */

#include <cstdio>
#include <climits>

int
main()
{
	int n(3);
	int k(2);
	const int wv[][2] = {{2, 2},
						 {5, 3},
						 {2, 1}};

	int b[2+1][2];
	b[0][0] = b[0][1] = 0;
	for (int i(1); i <= k; ++i) {
		b[i][0] = INT_MAX;
		b[i][1] = 0;
	}

	int v, w;

	for (int h(0); h < n; ++h) {
		for (int i(k - 1); 0 <= i; --i) {	// 計算量は O(kn)。
			if (b[i][0] == INT_MAX) continue;
			w = b[i][0] + wv[h][0];
			v = b[i][1] + wv[h][1];
			if ((double)v / (double)w <= (double)b[i+1][1] / (double)b[i+1][0]) continue;
			b[i+1][0] = w;
			b[i+1][1] = v;
		}
	}

	std::printf("%d / %d = %f\n", b[k][1], b[k][0], (double)b[k][1] / (double)b[k][0]);

	return 0;
}
