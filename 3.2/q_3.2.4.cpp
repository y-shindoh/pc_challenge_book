/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_3.2.4.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§3.2 p.141の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  最初の行の操作を決めると、
  次の行は最初の行の影響を受けて操作が一意に決まる。
  同様にさらに次の次の行は次の行の影響を受けて操作が一意に決まる。
  これを繰り返す。

  各行を独立に決めていくと O(2^MN) の計算量となるが、
  前の行に依存する形では O(MN 2^N) の計算量となる。
 */

#include <cstdio>
#include <cstring>

#define	M	4
#define	N	4

int
calc(const int b[M][N],
	 int x[M][N],
	 int y[M][N],
	 int h = 0,
	 int k = 0)
{
	// 最終的な盤の状態のチェック (最終行だけ確認すれば十分)
	if (M * N <= h) {
		for (int j(0); j < N; ++j) {
			if (b[M-1][j] == 0) {
				if (x[M-1][j] % 2 != 0) return -1;
			}
			else {
				if (x[M-1][j] % 2 == 0) return -1;
			}
		}
		return k;	// ひっくり返した回数
	}

	// 作業領域の初期化
	if (h == 0) {
		for (int i(0); i < M; ++i) {
			std::memset((void*)x[i], 0, sizeof(int) * N);
			std::memset((void*)y[i], 0, sizeof(int) * N);
		}
	}

	int r;
	int i = h / M;
	int j = h % N;

	// 上の行がないか上の行が既に白
	if (i == 0 || (0 < i && ((b[i-1][j] == 0 && x[i-1][j] % 2 == 0) || (b[i-1][j] == 1 && x[i-1][j] % 2 == 1)))) {
		r = calc(b, x, y, h + 1, k);
		if (0 <= r) return r;
	}

	// 上の行がないか上の行がまだ黒 => ひっくり返して
	if (i == 0 || (0 < i && ((b[i-1][j] == 0 && x[i-1][j] % 2 == 1) || (b[i-1][j] == 1 && x[i-1][j] % 2 == 0)))) {
		++x[i][j];
		if (0 < i) ++x[i-1][j];
		if (0 < j) ++x[i][j-1];
		if (i+1 < M) ++x[i+1][j];
		if (j+1 < N) ++x[i][j+1];
		++y[i][j];

		r = calc(b, x, y, h + 1, k + 1);
		if (0 <= r) return r;

		--x[i][j];
		if (0 < i) --x[i-1][j];
		if (0 < j) --x[i][j-1];
		if (i+1 < M) --x[i+1][j];
		if (j+1 < N) --x[i][j+1];
		--y[i][j];
	}

	return -1;
}

int
main()
{
	int b[M][N] = {{1, 0, 0, 1},
				   {0, 1, 1, 0},
				   {0, 1, 1, 0},
				   {1, 0, 0, 1}};

	int x[M][N];
	int y[M][N];

	int r = calc(b, x, y);

	std::printf("<<%d>>\n", r);

	for (int i(0); i < M; ++i) {
		for (int j(0); j < N; ++j) {
			if (0 < j) std::printf(" ");
			std::printf("%d", y[i][j]);
		}
		std::printf("\n");
	}

	return 0;
}
