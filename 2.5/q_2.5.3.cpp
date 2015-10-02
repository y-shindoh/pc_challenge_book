/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.5.3.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.5 p.103の例題
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  クラスカル法で信頼度に関する最大全域木を構築し、
  その信頼度の総和を個別に全員を徴兵した場合の費用から引く。
 */

#include <cstddef>
#include <cstdio>
#include <climits>
#include <queue>
#include "union_find_tree.hpp"

#define	N	5		// 男性の人数
#define	M	5		// 女性の人数
#define	V	(N+M)	// 頂点数 (人数)
#define	R	20		// 辺数

typedef	std::pair<int, int>	CV;	// 信頼度と辺のペア

int
main()
{
	// 辺の始点, 終点, 信頼度 (0以上)
	int edge[R][3] = {{4, N+3, 6831},	// 4 + 3: 6831
					  {1, N+3, 4583},	// 1 + 3: 4583
					  {0, N+0, 6592},	// 0 + 0: 6592
					  {0, N+1, 3063},	// 0 + 1: 3063
					  {3, N+3, 4975},	// 3 + 3: 4975
					  {1, N+3, 2049},	// 1 + 3: 2049
					  {4, N+2, 2104},	// 4 + 2: 2104
					  {2, N+2, 781}};	// 2 + 2: 781

	std::priority_queue<CV> queue;
	ys::UnionFindTree<int> uftree(V);

	for (int i(0); i < R; ++i) queue.push(CV(edge[i][2], i));

	CV cv;
	int e;
	int c(0);

	while (0 < queue.size()) {
		cv = queue.top();
		queue.pop();
		e = cv.second;
		if (uftree.same(edge[e][0], edge[e][1])) continue;	// 無効な信頼度
		uftree.unite(edge[e][0], edge[e][1]);
		c += cv.first;
	}

	std::printf("%d\n", V * 10000 - c);

	return 0;
}
