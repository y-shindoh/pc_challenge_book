/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.5.4.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.5 p.104の例題
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  各牛iの牛0からの最長距離d[i]を求める。
  このため、各牛の最長距離を制限するルールだけを考える。

  具体的には、牛A, ADの最長距離が既に制限されている時に、
  以下のルールで牛B, BDの最長距離が制限される。

  (1) B ≦ A => d[B] ≦ d[A] => d[B] = d[a]
  (2) A ≦ B => d[A] ≦ d[B] => d[B] = ∞
  (3) BD ≦ AD & DL => d[BD] ≦ d[AD] => d[BD] = d[AD]
  (4) AD ≦ BD & DL => d[BD] ≦ d[AD] + DL => d[BD] = d[AD] + DL
  (5) BD ≦ AD & DD => d[AD] ≧ d[BD] + DD => d[BD] = d[AD] - DD
  (6) AD ≦ BD & DD => d[AD] + DD ≦ d[BD] => d[BD] = ∞

  上記 (1) と (3) は同じ処理になる。
  また (2) と (6) は、初期値と同じ値を設定することになり、不要と考えられる。

  備考:
  解けなかったので、書籍の解答を参考にした。
  (が、それだけでは理解できなかったので、けっきょく自分で考えた)
 */

#include <cstddef>
#include <cstdio>
#include <climits>
#include <algorithm>

#define	V	4	// 頂点数 (牛の頭数)
#define	E	6	// エッジ数

int
main()
{
	// 辺の始点, 終点, 距離 (0以上)
	int edge[E][3] = {{0, 2, 10},	// 1->3: 10 (DL, (4))
					  {1, 3, 20},	// 2->4: 20 (DL, (4))
					  {2, 1, -3},	// 3->2:  3 (DD, (5))
					  {1, 0, 0},	// 2->1:  0 (--, (1))
					  {2, 1, 0},	// 3->2:  0 (--, (1))
					  {3, 2, 0}};	// 4->3:  0 (--, (1))
	int d[V];	// 0からの最長距離

	d[0] = 0;
	std::fill<int*>(d+1, d+V, INT_MAX);

	bool flag(true);
	int s, g, c;

	while (flag) {
		flag = false;
		for (int i(0); i < E; ++i) {
			s = edge[i][0];
			g = edge[i][1];
			c = edge[i][2];
			if (d[s] == INT_MAX) continue;
			if (d[g] <= d[s] + c) continue;
			d[g] = d[s] + c;
			flag = true;
		}
	}

	for (int i(0); i < V; ++i) {
		if (0 < i) std::printf(", ");
		if (d[i] != INT_MAX) {
			std::printf("%d", d[i]);
		}
		else {
			std::printf("-");
		}
	}
	std::printf("\n");

	for (int i(1); i < V; ++i) {
		if (0 <= d[i-1] && d[i-1] <= d[i]) continue;
		d[V-1] = -1;	// 最初の並びが適さない
		break;
	}

	if (d[V-1] == INT_MAX) {
		d[V-1] = -2;	// 最後の牛がいくらでも遠くに行ける
	}

	std::printf("=> %d\n", d[V-1]);

	return 0;
}
