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

  備考:
  幅優先探索は std::priority_queue を使って、
  コストの和の小さい順に処理すれば、より効率的に探索できる。
 */

#include <cstdio>
#include <climits>
#include <vector>
#include <deque>
#include <algorithm>

// 普通の幅優先探索
int
search1(const int g[5][5],
		int n,
		std::vector< std::vector<int> >& b)
{

	std::deque< std::pair<int, int> > queue;
	std::pair<int, int> ns;
	int i, s, t;

	queue.push_back(std::pair<int, int>(0, 0));

	while (0 < queue.size()) {
		ns = queue.front();
		queue.pop_front();
		i = ns.first;
		s = ns.second;
		if (s == ((1 << n) - 1)) continue;
		for (int j(0); j < n; ++j) {
			if (g[i][j] == INT_MAX) continue;
			if (s & (1 << j)) continue;
			t = s | (1 << j);
			if (b[j][t] <= b[i][s] + g[i][j]) continue;
			b[j][t] = b[i][s] + g[i][j];
			queue.push_back(std::pair<int, int>(j, t));
		}
	}

	return b[0][(1 << n) - 1];
}

// メモ化
int
search2(const int g[5][5],
		int n,
		std::vector< std::vector<int> >& b,
		int i,
		int s)
{
	if (b[i][s] == INT_MAX) {
		int v(INT_MAX);
		int k;

		for (int j(0); j < n; ++j) {
			k = 1 << j;
			if (!(s & k)) continue;
			if (g[j][i] == INT_MAX) continue;				// パス無し
			if (search2(g, n, b, j, s & ~k) < 0) continue;	// パス無し
			v = std::min(v, search2(g, n, b, j, s & ~k) + g[j][i]);
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
int
search3(const int g[5][5],
		int n,
		std::vector< std::vector<int> >& b)
{
	int k;

	for (int s(0); s < (1 << n); ++s) {
		for (int i(0); i < n; ++i) {
			if (b[i][s] == INT_MAX) continue;
			for (int j(0); j < n; ++j) {
				if (g[i][j] == INT_MAX) continue;
				k = 1 << j;
				if (s & k) continue;
				b[j][s|k] = std::min(b[j][s|k], b[i][s] + g[i][j]);
			}
		}
	}

	return b[0][(1 << n) - 1];
}

int
main()
{
	int n(5);
	const int g[5][5] = {{INT_MAX, 3, INT_MAX, 4, INT_MAX},
						 {INT_MAX, INT_MAX, 5, INT_MAX, INT_MAX},
						 {4, INT_MAX, INT_MAX, 5, INT_MAX},
						 {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 3},
						 {7, 6, INT_MAX, INT_MAX, INT_MAX}};

	std::vector< std::vector<int> > b;

	b.resize(n);
	for (int i(0); i < n; ++i) b[i].resize(1 << n, INT_MAX);
	b[0][0] = 0;
	std::printf("%d\n", search1(g, n, b));

	for (int i(0); i < n; ++i) std::fill(b[i].begin(), b[i].end(), INT_MAX);
	b[0][0] = 0;
	std::printf("%d\n", search2(g, n, b, 0, (1 << n) - 1));

	for (int i(0); i < n; ++i) std::fill(b[i].begin(), b[i].end(), INT_MAX);
	b[0][0] = 0;
	std::printf("%d\n", search3(g, n, b));

	return 0;
}
