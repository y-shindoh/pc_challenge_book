/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_3.4.2.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§3.4 p.175の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  DPを用いる。
  「現在位置」と「使用済みチケット」をインデックスとした2次元配列に、
  最短時間を格納する。
 */

#include <cstdio>
#include <climits>
#include <cfloat>
#include <algorithm>

#define	N 2
#define	M 4

int
main()
{
	int a(1);
	int b(0);
	const int t[N] = {3, 1};
	const int g[M][M] = {{INT_MAX, INT_MAX, 3, 2},
						 {INT_MAX, INT_MAX, 3, 5},
						 {3, 3, INT_MAX, INT_MAX},
						 {2, 5, INT_MAX, INT_MAX}};

	double dp[M][1 << N];
	int h;

	for (int i(0); i < M; ++i) std::fill(dp[i], dp[i] + (1 << N), DBL_MAX);
	dp[a][0] = 0.0;

	for (int s(0); s < (1 << N); ++s) {
		for (int i(0); i < M; ++i) {
			if (dp[i][s] == DBL_MAX) continue;		// パスなし
			for (int j(0); j < M; ++j) {
				if (g[i][j] == INT_MAX) continue;	// 追加エッジなし
				for (int k(0); k < N; ++k) {
					h = 1 << k;
					if (s & h) continue;			// 使用済みチケット
					dp[j][s|h] = std::min(dp[j][s|h], dp[i][s] + (double)g[i][j] / (double)t[k]);
				}
			}
		}
	}

	h = 0;
	for (int s(1); s < (1 << N); ++s) {
		if (dp[b][h] <= dp[b][s]) continue;
		h = s;
	}

	if (dp[b][h] != DBL_MAX) {
		std::printf("%f\n", dp[b][h]);
	}
	else {
		std::printf("到達不能。\n");
	}

	return 0;
}
