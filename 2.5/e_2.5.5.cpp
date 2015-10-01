/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	e_2.5.5.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.5 p.101の例題
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  最小全域木問題のクラスカル法。
 */

#include <cstddef>
#include <cstdio>
#include <climits>
#include <unordered_set>
#include <queue>

#define	V	7	// 頂点数
#define	E	20	// 辺数
#define	S	0	// スタートの頂点

typedef	std::pair<int, int>	CV;	// 累計コストと頂点のペア

int
main()
{
	// 辺の始点, 終点, コスト (0以上)
	int edge[E][3] = {{0, 1, 2},	// A->B: 2
					  {0, 2, 5},	// A->C: 5
					  {1, 0, 2},	// B->A: 2
					  {1, 2, 4},	// B->C: 4
					  {1, 3, 6},	// B->D: 6
					  {1, 4, 10},	// B->E: 10
					  {2, 0, 5},	// C->A: 5
					  {2, 1, 4},	// C->B: 4
					  {2, 3, 2},	// C->D: 2
					  {3, 1, 6},	// D->B: 6
					  {3, 2, 2},	// D->C: 2
					  {3, 5, 1},	// D->F: 1
					  {4, 1, 10},	// E->B: 10
					  {4, 5, 3},	// E->F: 3
					  {4, 6, 5},	// E->G: 5
					  {5, 3, 1},	// F->D: 1
					  {5, 4, 3},	// F->E: 3
					  {5, 6, 9},	// F->G: 9
					  {6, 4, 5},	// G->E: 5
					  {6, 5, 9}};	// G->F: 9

	std::priority_queue<CV, std::vector<CV>, std::greater<CV> > queue;
	std::unordered_set<int> used;

	used.insert(S);
	for (int i(0); i < E; ++i) {
		if (edge[i][0] < S) continue;
		if (S < edge[i][0]) break;
		queue.push(CV(edge[i][2], edge[i][1]));
	}

	CV cv;
	int t;
	int c(0);

	while (0 < queue.size()) {
		cv = queue.top();
		queue.pop();
		t = cv.second;
		if (0 < used.count(t)) continue;
		used.insert(t);
		c += cv.first;
		if (used.size() == V) break;
		for (int i(0); i < E; ++i) {
			if (edge[i][0] < t) continue;
			if (t < edge[i][0]) break;
			if (0 < used.count(edge[i][1])) continue;
			queue.push(CV(edge[i][2], edge[i][1]));
		}
	}

	if (used.size() == V) {
		std::printf("FOUND! (%d)\n", c);
	}
	else {
		std::printf("NOT FOUND!\n");
	}

	return 0;
}
