/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_3.2.7.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§3.2 p.149の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  商品を2つのグループに分け、それぞれの全パターンを列挙。
  一方を重さでソーティングし、その重さ以下で最大の価値を算出。
  もう一方の全パターンの各要素に対し、
  ソーティング済みの全パターンを二分探索。
  最大の価値の和を算出する。
 */

#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

typedef std::pair<int, int> WV;

void
fill_wv(const int* w,
		const int* v,
		std::vector<WV>& wv,
		int n,
		int i = 0,
		int t_w = 0,
		int t_v = 0)
{
	if (n <= i) {
		wv.push_back(WV(t_w, t_v));
		return;
	}

	fill_wv(w, v, wv, n, i+1, t_w, t_v);
	fill_wv(w, v, wv, n, i+1, t_w + w[i], t_v + v[i]);
}

int
main()
{
	int n(4);
	const int w[] = {2, 1, 3, 2};
	const int v[] = {3, 2, 4, 2};
	int W(5);

	int m(n/2);

	std::vector<WV> wv1;
	std::vector<WV> wv2;

	fill_wv(w, v, wv1, m);	// O(2^m)
	fill_wv(w + m, v + m, wv2, n - m);	// O(2^(n-m))

	std::sort(wv2.begin(), wv2.end());	// O((n-m) log (n-m))

	int m_v(0);
	for (int i(0); i < wv2.size(); ++i) {	// O(n-m)
		if (wv2[i].second < m_v) wv2[i].second = m_v;
		else m_v = wv2[i].second;
	}

	// O(2^m * (n-m))
	m_v = 0;
	for (int i(0); i < wv1.size(); ++i) {
		int s(-1);			// W以下の先頭
		int e(wv2.size());	// W超の末尾
		int j;
		while (s + 1 < e) {
			j = (s + e) / 2;
			if (wv1[i].first + wv2[j].first <= W) {
				s = j;
			}
			else {
				e = j;
			}
		}
		if (s < 0) continue;
		if ((n - m) * (n - m) <= s) continue;
		if (wv1[i].second + wv2[s].second <= m_v) continue;
		m_v = wv1[i].second + wv2[s].second;
	}

	std::printf("%d\n", m_v);

	return 0;
}
