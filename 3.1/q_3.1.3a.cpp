/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_3.1.3a.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§3.1 p.131の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  牛舎と牛舎の感覚に対して二分探索を行う。

  - 牛を置ける頭数が多い場合/要求通りの場合は探索範囲先頭を末尾よりに移動する。
  - 牛を置ける頭数が少ない場合は探索範囲末尾を先頭よりに移動する。

  備考:
  計算量が同等の別解を考えた後、書籍の説明を読んでこちらの解法を考えた。
 */

#include <cstdio>

int
count_cow(const int* x,
		  int l,
		  int w)
{
	int p(0);	// 前の牛の牛舎
	int r(1);	// 牛の頭数

	for (int i(1); i < l; ++i) {
		if (x[i] - x[p] < w) continue;
		++r;
		p = i;
	}

	return r;
}

#define	N	5
#define	M	3

int
main()
{
	const int x[N] = {1, 2, 4, 8, 9};	// ソート済みとする

	int s(x[0] - 1);	// M以上を配置できる牛舎の最短間隔の末尾
	int e(x[N-1] + 1);	// M未満を配置できる牛舎の最長間隔の先頭
	int i;
	int k;

	while (s + 1 < e) {
		i = (s + e) / 2;
		k = count_cow(x, N, i);
		if (M <= k) s = i;
		else e = i;
	}

	std::printf("%d\n", s);

	return 0;
}
