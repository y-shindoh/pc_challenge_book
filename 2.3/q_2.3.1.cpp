/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.3.1.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.3の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  各重さに対する最大の価値合計を示す表を作り、
  品物を1つずつ増やしていき表を更新する。
  最終的な表の中の最大の価値合計を求めれば良い。
 */

#include <cstddef>
#include <cstdio>
#include <vector>

int
main()
{
	const int n(4);
	const int wv[][2] = {{2, 3}, {1, 2}, {3, 4}, {2, 2}};
	const int W(5);

	int k;
	std::vector<int> b;

	b.resize(W+1, -1);
	b[0] = 0;

	for (int i(0); i < n; ++i) {
		for (int j(W-1); 0 <= j; --j) {	// 重複更新を避けるため、後ろから更新
			if (b[j] < 0) continue;
			k = j + wv[i][0];
			if (W < k) continue;
			if (b[k] < b[j] + wv[i][1]) {
				b[k] = b[j] + wv[i][1];
			}
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
