/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_3.4.1a.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§3.5 p.188の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  Ford-Fulkerson法。
 */

#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>

#define	V	5

struct edge { int to, cap, rev; };	// 行き先, 容量, 逆辺のインデックス

std::vector<edge> G[V];	// グラフの隣接リスト
bool used[V];			// DFSで既に調べたかのフラグ

void add_edge(int from, int to, int cap)
{
	G[from].push_back((edge){to, cap, (int)G[to].size()});
	G[to].push_back((edge){from, 0, (int)G[from].size() - 1});
}

/**
 * @param[in]	v	探索の始点
 * @param[in]	t	探索の終点
 * @param[in]	f	流量の最大値 (キャパシティを無視した値)
 * @return	実際の流量
 */
int dfs(int v, int t, int f = INT_MAX)
{
	if (v == t) return f;
	used[v] = true;
	for (int i = 0; i < G[v].size(); ++i) {
		edge &e = G[v][i];
		if (used[e.to]) continue;	// 探索済み
		if (e.cap <= 0) continue;	// 空き容量なし
		int d = dfs(e.to, t, std::min(f, e.cap));
		if (d > 0) {
			e.cap -= d;
			G[e.to][e.rev].cap += d;
			return d;
		}
	}
	return 0;
}

int max_flow(int s, int t)
{
	int flow = 0;
	while ('-') {
		std::memset((void*)used, 0, sizeof(bool) * V);
		int f = dfs(s, t);
		if (f == 0) return flow;
		flow += f;
	}
}

int
main()
{
	add_edge(0, 1, 10);
	add_edge(0, 2, 2);
	add_edge(1, 2, 6);
	add_edge(1, 3, 6);
	add_edge(2, 4, 5);
	add_edge(3, 2, 3);
	add_edge(3, 4, 8);

	std::printf("%d\n", max_flow(0, 4));

	return 0;
}
