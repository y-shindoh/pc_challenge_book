/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.3.4.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.3 p.60の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  各価値合計に対する最小の重さ合計を示す表を作り、
  品物を1つずつ増やしていき表を更新する。
  最終的な表の中の最大の価値合計を求めれば良い。
 */

#include <cstdio>
#include <climits>
#include <algorithm>

#define	N	4
#define	W	5
#define	MAX_V	100

int
main()
{
	const int wv[N][2] = {{2, 3}, {1, 2}, {3, 4}, {2, 2}};

	int h, k;
	int b[N*MAX_V+1];
	int l = N * MAX_V;

	b[0] = 0;
	std::fill(b + 1, b + N * MAX_V + 1, W + 1);

	for (int i(0); i < N; ++i) {
		for (int j(l - wv[i][1]); 0 <= j; --j) {
			if (W < b[j]) continue;
			h = j + wv[i][1];
			k = b[j] + wv[i][0];
			if (b[h] <= k) continue;
			b[h] = k;
		}
	}

	for (int i(l+1); 0 <= i; --i) {
		if (W < b[i]) continue;
		std::printf("%d (%d)\n", i, b[i]);
		break;
	}

	return 0;
}
