/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.3.5.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.3 p.62の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  合計値に対するその時点の整数を何回使ったかの表を作り、
  整数の種類を1つずつ増やしていき表を更新する。
  最終的に指定した合計値が出現したかどうかを確認する。

  備考:
  自力では計算量の爆発しやすい解法しか思いつかなかったため、
  書籍のヒント (DPテーブルの使い方) を少し読んで書籍とは違うコードを実装した。
  計算量は O(NK) で、書籍と変わらない。
  ※「bool値を求めるDPをすることは無駄であることが多く」は良いアドバイス。
 */

#include <cstdio>
#include <climits>
#include <algorithm>

#define	N	3
#define	K	17

int
main()
{
	const int a[N] = {3, 5, 8};
	const int m[N] = {3, 2, 2};

	int h, k;
	int b[K+1];

	b[0] = 0;
	std::fill(b + 1, b + K + 1, INT_MAX);

	for (int i(0); i < N; ++i) {
		if (0 < i) {
			std::replace_if(b, b + K,
							[] (int x) { return x != INT_MAX; },
							0);	// 整数の使用回数をリセット
		}

		for (int j(0); j < K; ++j) {
			if (b[j] == INT_MAX) continue;
			if (m[i] <= b[j]) continue;
			k = j + a[i];		// 合計値
			if (K < k) break;
			h = b[j] + 1;		// 整数の使用回数
			if (b[k] <= h) continue;
			b[k] = h;			// 整数の使用回数を更新
		}

		if (b[K] != INT_MAX) break;
	}

	if (b[K] != INT_MAX) {
		std::printf("FOUND!\n");
	}
	else {
		std::printf("NOT FOUND!\n");
	}

	return 0;
}
