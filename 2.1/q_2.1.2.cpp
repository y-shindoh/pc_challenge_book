/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.1.2.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.1の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  左上の地点から右下の地点を走査し、
  「W」があれば、その都度、再帰処理を実施する。
  再帰処理は、8近傍にある「W」を対象としたもので、
  再帰の形で自身を呼ぶ前に「W」を「.」に置き換えることで、
  再帰が無限にならないように抑制する。
 */

#include <cstddef>
#include <cstdio>

/**
 * 深さ優先探索のサンプル実装
 * @note	この処理の場合は幅優先探索の方が美しいのでは?
 */
template<typename TYPE, size_t H, size_t W>
void
replace(TYPE ground[H][W],
		size_t i,
		size_t j)
{
	if (!ground[i][j]) return;

	ground[i][j] = (TYPE)0;

	for (size_t h = 0 < i ? i - 1 : i; h < i + 2 && h < H; ++h) {
		for (size_t k = 0 < j ? j - 1 : j; k < j + 2 && k < W; ++k) {
			if (!ground[h][k]) continue;
			replace<TYPE, H, W>(ground, h , k);
		}
	}
}

#define	N	((size_t)10)
#define	M	((size_t)12)

int
main(void)
{
	bool ground[N][M] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
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
			replace<bool, N, M>(ground, i, j);
		}
	}

	std::printf("%lu\n", k);

	return 0;
}
