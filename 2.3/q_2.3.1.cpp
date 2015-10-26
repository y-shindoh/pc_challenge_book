/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.3.1.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.3 p.52の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  各重さに対する最大の価値合計を示す表を作り、
  品物を1つずつ増やしていき表を更新する。
  最終的な表の中の最大の価値合計を求めれば良い。
 */

#include <cstdio>
#include <algorithm>

#define	N	4
#define	W	5

int
main()
{
	const int wv[N][2] = {{2, 3}, {1, 2}, {3, 4}, {2, 2}};
	int b[W+1];
	int k;

	b[0] = 0;
	std::fill(b + 1, b + W + 1, -1);

	for (int i(0); i < N; ++i) {
		for (int j(W-1); 0 <= j; --j) {
			if (b[j] < 0) continue;
			k = j + wv[i][0];
			if (W < k) continue;
			if (b[j] + wv[i][1] <= b[k]) continue;
			b[k] = b[j] + wv[i][1];
		}
	}

	k = 0;
	for (int i(0); i <= W; ++i) {
		if (b[i] <= b[k]) continue;
		k = i;
	}

	std::printf("%d\n", b[k]);

	return 0;
}
