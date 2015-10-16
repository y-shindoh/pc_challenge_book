/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_3.4.8b.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§3.4 p.186の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  書籍ではセグメント木を用いたDPを紹介しているが、
  ここでは単純なDPの実装で済ませる。
 */

#include <cstdio>
#include <algorithm>
#define	N	40
#define	M	6

int
main()
{
	const int st[M][2] = {{20, 30},
						  {1, 10},
						  {10, 20},
						  {20, 30},
						  {15, 25},
						  {30, 40}};

	int dp[M+1];	// ソータの利用回数 => 到達した最遠地点
	int k(0);

	dp[0] = 1;
	std::fill(dp + 1, dp + M + 1, -1);

	for (int i(0); i < M; ++i) {
		for (int j(k); 0 <= j; --j) {
			if (dp[j] < st[i][0]) continue;		// 接続失敗
			if (st[i][1] <= dp[j+1]) continue;	// 接続不要
			dp[j+1] = st[i][1];
			if (k < j + 1) k = j + 1;
		}
	}

	for (int i(0); i <= k; ++i) {
		if (dp[i] < N) continue;
		std::printf("%d\n", i);
		break;
	}

	return 0;
}
