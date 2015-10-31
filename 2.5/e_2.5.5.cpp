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

#define	__UNION_FIND_TREE_WITH_SIZE__	1

#include <cstddef>
#include <cstdio>
#include <climits>
#include <queue>
#include "union_find_tree.hpp"

#define	V	7	// 頂点数
#define	E	20	// 辺数

typedef	std::pair<int, int>	CV;	// コストと辺のペア

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
	ys::UnionFindTree<int> uftree(V);

	for (int i(0); i < E; ++i) queue.push(CV(edge[i][2], i));

	CV cv;
	int e;
	int c(0);

	while (0 < queue.size()) {
		cv = queue.top();
		queue.pop();
		e = cv.second;
		if (uftree.same(edge[e][0], edge[e][1])) continue;
		uftree.unite(edge[e][0], edge[e][1]);
		c += cv.first;
	}

	if (uftree.size(0) == V) {
		std::printf("FOUND! (%d)\n", c);
	}
	else {
		std::printf("NOT FOUND!\n");
	}

	return 0;
}
