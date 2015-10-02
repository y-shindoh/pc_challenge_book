/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.5.2.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.5 p.102の例題
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  最短経路問題の各手法において、
  各コストの保存時に上位2番目までのコストを保持すれば良い。

  備考:
  最初に考えたのは計算量の多い解だった。
 */

#include <cstddef>
#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
#include <utility>

typedef	std::pair<int, int>	CV;	// 累計コストと頂点のペア

#define	V	4	// 頂点数
#define	E	4	// 辺数
#define	S	0	// スタートの頂点

int
main()
{
	// 辺の始点, 終点, コスト (0以上)
	int edge[E][3] = {{0, 1, 100},	// 1->2: 100
					  {1, 2, 250},	// 2->3: 250
					  {1, 3, 200},	// 2->4: 200
					  {2, 3, 100}};	// 3->4: 100
	int d[V][2];	// 各頂点の累計コスト上位2件

	int v, c;
	CV cv;
	std::priority_queue<CV, std::vector<CV>, std::greater<CV> > queue;

	for (int i(0); i < V; ++i) d[i][0] = d[i][1] = INT_MAX;
	queue.push(CV(0, S));

	while (0 < queue.size()) {
		cv = queue.top();
		c = cv.first;
		v = cv.second;
		queue.pop();
		if (d[v][1] <= c) continue;
		if (c < d[v][0]) {
			d[v][1] = d[v][0];
			d[v][0] = c;
		}
		else {
			d[v][1] = c;
		}
		for (int i(0); i < E; ++i) {
			if (edge[i][0] < v) continue;
			if (v < edge[i][0]) break;
			if (d[edge[i][1]][1] <= c + edge[i][2]) continue;
			queue.push(CV(c + edge[i][2], edge[i][1]));
		}
	}

	for (int h(0); h < 2; ++h) {
		std::printf("<<%d>>\n", h);
		for (int i(0); i < V; ++i) {
			if (0 < i) std::printf(", ");
			if (d[i][h] != INT_MAX) {
				std::printf("%d", d[i][h]);
			}
			else {
				std::printf("-");
			}
		}
		std::printf("\n");
	}

	return 0;
}
