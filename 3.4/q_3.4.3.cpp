/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_3.4.3.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§3.4 p.177の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  書籍のコードを書き写してみた。
  右下のところから左へ・上へと辿って処理する。
  この際、各マスにおける置き方の可能性を全て網羅する。
  (最終的に右下と左上は他のマスに置いたブロックの影響を受けるかもともと黒)

  また、変数 used は
  注目しているマスで置くブロックが影響しているか否かを示している。
  (逆を言うと、状態のほとんどはその時々の注目点に対し直接的な意味を持たない)

  備考:
  まだ良くわかっていない…。
 */

#include <cstdio>
#include <algorithm>

#define	N 3
#define	M 3

int
main()
{
	const bool color[N][M] = {{0, 0, 0},
							  {0, 1, 0},
							  {0, 0, 0}};
	int dp[2][1 << M];	// NxMの盤を2に集約
	int c(0);	// 更新元
	int n(1);	// 更新先

	std::fill(dp[c] + 1, dp[c] + (1 << M), 0);	// 途中経過を気にしないなら不要
	dp[c][0] = 1;	// 初期値

	for (int i(N-1); 0 <= i; --i) {
		for (int j(M-1); 0 <= j; --j) {
			// 以下、dp[n] が (i, j) のマスを表現している。
			for (int used(0); used < (1 << M); ++used) {
				if ((used & (1 << j)) || color[i][j]) {
					// 他で置かれる仮定 or 黒 => 置く必要なし
					dp[n][used] = dp[c][used & ~(1 << j)];
				}
				else {
					// 他で置かれない仮定 and 白 => 置いてみる
					int res(0);
					// 横向き右に置く
					if (j + 1 < M && !(used & (1 << (j + 1))) && !color[i][j+1]) {
						res += dp[c][used | (1 << (j + 1))];
					}
					// 縦向き下に置く
					if (i + 1 < N && !color[i+1][j]) {
						res += dp[c][used | (1 << j)];
					}
					dp[n][used] = res;
					//dp[n][used] %= M;
				}
			}
			c ^= 1;
			n ^= 1;
		}
	}

	std::printf("%d\n", dp[c][0]);

	return 0;
}
