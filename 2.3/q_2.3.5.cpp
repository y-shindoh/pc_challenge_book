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
  計算量は O(nK) で、書籍と変わらない。
 */

#include <cstddef>
#include <cstdio>
#include <climits>
#include <vector>

int
main()
{
	const int n(3);
	const int a[] = {3, 5, 8};
	const int m[] = {3, 2, 2};
	const int K(17);

	std::vector<int> b;

	b.resize(K+1, INT_MAX);
	b[0] = 0;

	for (int i(0); i < n; ++i) {
		if (0 < i) {
			for (int j(0); j < K; ++j) {
				if (b[j] == INT_MAX) continue;
				b[j] = 0;		// 整数の使用回数をリセット
			}
		}
		for (int j(0); j < K; ++j) {
			if (b[j] == INT_MAX) continue;
			if (m[i] <= b[j]) continue;
			int k = j + a[i];	// 合計値
			if (K < k) break;
			int h = b[j] + 1;	// 整数の使用回数
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
