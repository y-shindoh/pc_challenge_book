/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.1.1.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.1の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

#include <cstddef>
#include <cstdio>
#include <bitset>

#define	N	((size_t)10)
#define	M	((size_t)12)

/**
 * 深さ優先探索のサンプル実装
 * @note	この処理の場合は幅優先探索の方が美しいのでは?
 */
void
replace(int ground[N][M],
		size_t i,
		size_t j)
{
	if (!ground[i][j]) return;
	ground[i][j] = 0;
	if (0 < i && ground[i-1][j]) replace(ground, i-1, j);
	if (i+1 < N && ground[i+1][j]) replace(ground, i+1, j);
	if (0 < j && ground[i][j-1]) replace(ground, i, j-1);
	if (j+1 < M && ground[i][j+1]) replace(ground, i, j+1);
	if (0 < i && 0 < j && ground[i-1][j-1]) replace(ground, i-1, j-1);
	if (0 < i && j+1 < M && ground[i-1][j+1]) replace(ground, i-1, j+1);
	if (i+1 < N && 0 < j && ground[i+1][j-1]) replace(ground, i+1, j-1);
	if (i+1 < N && j+1 < M && ground[i+1][j+1]) replace(ground, i+1, j+1);
}

int
main(void)
{
	int ground[N][M] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
						{0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1},
						{0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0},
						{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
						{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
						{0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
						{0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0},
						{1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
						{0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
						{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0}};

	size_t k(0);

	for (size_t i(0); i < N; ++i) {
		for (size_t j(0); j < M; ++j) {
			if (!ground[i][j]) continue;
			++k;
			replace(ground, i, j);
		}
	}

	std::printf("%lu\n", k);

	return 0;
}
