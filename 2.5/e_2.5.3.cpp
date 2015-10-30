/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	e_2.5.3.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.5 p.98の例題
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  単一始点最短経路問題のワーシャル-フロイド法の実装。
 */

#include <cstdio>
#include <climits>
#include <algorithm>

#define	V	7	// 頂点数
#define	E	20	// 辺数
#define	S	0	// スタートの頂点

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
	int d[V][V];	// 各頂点間の最小累計コスト

	int k(0);

	for (int i(0); i < V; ++i) {
		d[i][i] = 0;
		std::fill(d[i] + 1, d[i] + V, INT_MAX);
		while (k < E && edge[k][0] < i) ++k;
		if (E <= k || edge[k][0] != i) continue;
		for (int j(0); j < V; ++j) {
			while (k < E && edge[k][0] == i && edge[k][1] < j) ++k;
			if (E <= k || edge[k][0] != i || edge[k][1] != j) continue;
			d[i][j] = edge[k][2];
		}
	}

	for (int k(0); k < V; ++k) {
		for (int i(0); i < V; ++i) {
			for (int j(0); j < V; ++j) {
				if (d[i][k] == INT_MAX || d[k][j] == INT_MAX) continue;
				if (d[i][j] <= d[i][k] + d[k][j]) continue;
				d[i][j] = d[i][k] + d[k][j];
			}
		}
	}

	for (int j(0); j < V; ++j) {
		if (0 < j) std::printf(", ");
		if (d[S][j] != INT_MAX) {
			std::printf("%d", d[S][j]);
		}
		else {
			std::printf("-");
		}
	}
	std::printf("\n");

	return 0;
}
