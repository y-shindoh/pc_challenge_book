/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.3.3.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.3の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  各重さに対する最大の価値合計を示す表を作り、
  品物を1種類ずつ増やしていき表を更新する。
  最終的な表の中の最大の価値合計を求めれば良い。
 */

#include <cstddef>
#include <cstdio>
#include <vector>

int
main()
{
	const int n(3);
	const int wv[][2] = {{3, 4}, {4, 5}, {2, 3}};
	const int W(7);

	int k;
	std::vector<int> b;

	b.resize(W+1, -1);
	b[0] = 0;

	for (int i(0); i < n; ++i) {
		for (int j(0); j < W; ++j) {
			if (b[j] < 0) continue;
			k = j + wv[i][0];
			if (W < k) break;
			if (b[k] >= b[j] + wv[i][1]) continue;
			b[k] = b[j] + wv[i][1];
		}
	}

	k = 0;

	for (int i(1); i <= W; ++i) {
		if (b[k] >= b[i]) continue;
		k = i;
	}

	std::printf("%d\n", b[k]);

	return 0;
}
