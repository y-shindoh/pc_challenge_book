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

#include <cstddef>
#include <cstdio>
#include <climits>
#include <vector>

#define	MAX_V	100

int
main()
{
	const int n(4);
	const int wv[][2] = {{2, 3}, {1, 2}, {3, 4}, {2, 2}};
	const int W(5);
	const int m = n * MAX_V;

	int h, k;
	std::vector<int> b;

	b.resize(m + 1, INT_MAX);
	b[0] = 0;

	for (int i(0); i < n; ++i) {
		for (int j(m-1); 0 <= j; --j) {	// 重複更新を避けるため、後ろから更新
			if (INT_MAX == b[j]) continue;
			h = b[j] + wv[i][0];
			if (W < h) continue;
			k = j + wv[i][1];
			if (b[k] > h) b[k] = h;
		}
	}

	k = 0;

	for (int i(m); 0 <= i; --i) {
		if (b[i] == INT_MAX) continue;
		k = i;
		break;
	}

	std::printf("%d\n", k);

	return 0;
}
