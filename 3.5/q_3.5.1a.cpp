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
#include <climits>
#include <vector>
#include <tuple>
#include <algorithm>

typedef	std::tuple<int, int, int>	Edge;	// 行き先の頂点, 空き容量, 逆辺のインデックス

/**
 * グラフに辺を追加 (同時に逆辺も追加)
 * @param[in,out]	graph	グラフ
 * @param[in]	from	辺の始点
 * @param[in]	to	辺の終点
 * @param[in]	capacity	辺の容量
 */
void
AddEdge(std::vector< std::vector<Edge> >& graph,
		int from,
		int to,
		int capacity)
{
	graph[from].push_back(Edge(to, capacity, graph[to].size()));
	graph[to].push_back(Edge(from, 0, graph[from].size() - 1));
}

/**
 * 流量決定の1試行を実施
 * @param[in,out]	graph	グラフ
 * @param[in,out]	used	ノードの探索状況
 * @param[in]	from	探索の始点
 * @param[in]	to	探索の終点
 * @param[in]	flow	流量の最大値 (キャパシティを無視した値)
 * @return	実際の流量
 */
int
MaxFlowSubroutine(std::vector< std::vector<Edge> >& graph,
				  std::vector<bool>& used,
				  int from,
				  int to,
				  int flow = INT_MAX)
{
	if (from == to) return flow;

	used[from] = true;

	for (int i = 0; i < graph[from].size(); ++i) {
		int n = std::get<0>(graph[from][i]);	// 次の頂点
		int& c = std::get<1>(graph[from][i]);	// 空き容量
		int r = std::get<2>(graph[from][i]);	// 逆辺のインデックス

		if (used[n]) continue;	// 探索済み => スキップ
		if (c <= 0) continue;	// 空き容量なし => スキップ

		// 探索 (深さ優先)
		int d = MaxFlowSubroutine(graph, used, n, to, std::min(flow, c));
		if (d <= 0) continue;	// 変化なし => 次の頂点
		c -= d;
		std::get<1>(graph[n][r]) += d;
		return d;
	}

	return 0;
}

/**
 * 流量の算出
 * @param[in,out]	graph	グラフ
 * @param[in]	from	探索の始点
 * @param[in]	to	探索の終点
 * @return	実際の流量
 */
int
MaxFlow(std::vector< std::vector<Edge> >& graph,
		int from,
		int to)
{
	int flow = 0;
	std::vector<bool> used;

	used.resize(graph.size());

	while ('-') {
		std::fill(used.begin(), used.end(), false);
		int f = MaxFlowSubroutine(graph, used, from, to);
		if (f == 0) return flow;
		flow += f;
	}
}

#define	V	5

int
main()
{
	std::vector< std::vector<Edge> > graph;

	graph.resize(V);
	AddEdge(graph, 0, 1, 10);
	AddEdge(graph, 0, 2, 2);
	AddEdge(graph, 1, 2, 6);
	AddEdge(graph, 1, 3, 6);
	AddEdge(graph, 2, 4, 5);
	AddEdge(graph, 3, 2, 3);
	AddEdge(graph, 3, 4, 8);

	std::printf("%d\n", MaxFlow(graph, 0, 4));

	return 0;
}
