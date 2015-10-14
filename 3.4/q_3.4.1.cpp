/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_3.4.1.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§3.4 p.173の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  探索の状態 (到達済みの頂点) をビット表現することを除き、特記事項なし。
 */

#include <cstdio>
#include <climits>
#include <functional>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

// 普通の幅優先探索
template<int N>
int
search1(const int g[N][N],
		int b = 0)
{
	typedef	std::tuple<int, int, int>	CNS;	// コスト+位置+状態

	std::priority_queue<CNS, std::vector<CNS>, std::greater<CNS> > queue;
	CNS cns;
	int c, i, s, t;

	queue.push(CNS(0, b, 0));

	while (0 < queue.size()) {
		cns = queue.top();
		queue.pop();
		c = std::get<0>(cns);
		i = std::get<1>(cns);
		s = std::get<2>(cns);
		if (s == ((1 << N) - 1)) {
			if (i != b) continue;
			return c;
		}
		for (int j(0); j < N; ++j) {
			if (g[i][j] == INT_MAX) continue;
			t = 1 << j;
			if (s & t) continue;
			queue.push(CNS(c + g[i][j], j, s | t));
		}
	}

	return INT_MAX;
}

// メモ化
template<int N>
int
search2(const int g[N][N],
		int b[N][1<<N],
		int i,
		int s)
{
	if (b[i][s] == INT_MAX) {
		int v(INT_MAX);
		int k;

		for (int j(0); j < N; ++j) {
			k = 1 << j;
			if (!(s & k)) continue;
			if (g[j][i] == INT_MAX) continue;				// パス無し
			if (search2<N>(g, b, j, s & ~k) < 0) continue;	// パス無し
			v = std::min(v, search2<N>(g, b, j, s & ~k) + g[j][i]);
		}

		if (v == INT_MAX) {
			b[i][s] = -1;	// 成立しない条件
		}
		else {
			b[i][s] = v;
		}
	}

	return b[i][s];
}

// DP
template<int N>
int
search3(const int g[N][N],
		int b[N][1<<N])
{
	int k;

	for (int s(0); s < (1 << N) - 1; ++s) {
		for (int i(0); i < N; ++i) {
			if (b[i][s] == INT_MAX) continue;
			for (int j(0); j < N; ++j) {
				if (g[i][j] == INT_MAX) continue;
				k = 1 << j;
				if (s & k) continue;
				b[j][s|k] = std::min(b[j][s|k], b[i][s] + g[i][j]);
			}
		}
	}

	return b[0][(1 << N) - 1];
}

#define	N	5

int
main()
{
	const int g[N][N] = {{INT_MAX, 3, INT_MAX, 4, INT_MAX},
						 {INT_MAX, INT_MAX, 5, INT_MAX, INT_MAX},
						 {4, INT_MAX, INT_MAX, 5, INT_MAX},
						 {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 3},
						 {7, 6, INT_MAX, INT_MAX, INT_MAX}};
	int b[N][1 << N];


	std::printf("%d\n", search1<N>(g));

	for (int i(0); i < N; ++i) std::fill(b[i], b[i] + (1 << N), INT_MAX);
	b[0][0] = 0;
	std::printf("%d\n", search2<N>(g, b, 0, (1 << N) - 1));

	for (int i(0); i < N; ++i) std::fill(b[i], b[i] + (1 << N), INT_MAX);
	b[0][0] = 0;
	std::printf("%d\n", search3<N>(g, b));

	return 0;
}
