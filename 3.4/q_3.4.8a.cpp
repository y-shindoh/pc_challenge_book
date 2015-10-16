/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_3.4.8a.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§3.4 p.186の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  書籍にはDPを用いる手法が掲載されているが、まずは単純な幅優先探索で処理する。
 */

#include <climits>
#include <cstdio>
#include <utility>
#include <queue>
#include <vector>

typedef	std::pair<int, int>	CI;

#define	N	40
#define	M	6

int
main()
{
	const int st[M+1][2] = {{1, 1},
							{20, 30},
							{1, 10},
							{10, 20},
							{20, 30},
							{15, 25},
							{30, 40}};
	std::priority_queue< CI, std::vector<CI>, std::greater<CI> > queue;
	int r(INT_MAX);

	queue.push(CI(0, 0));

	while (0 < queue.size()) {
		CI ci = queue.top();
		queue.pop();
		int c = ci.first;
		int i = ci.second;
		if (N <= st[i][1]) {
			if (c < r) r = c;
			continue;
		}
		if (r <= c) continue;
		for (int j(i+1); j <= M; ++j) {
			if (st[i][1] >= st[j][1]) continue;	// 探索不要
			if (st[i][1] < st[j][0]) continue;	// 接続失敗
			queue.push(CI(c+1, j));
		}
	}

	std::printf("%d\n", r);

	return 0;
}
