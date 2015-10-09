/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_3.3.2.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§3.2 p.162の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  0, ..., N-1 の順に要素を見るとし、各時点で以下の式が成立する。

    既出の要素と今の要素の総数 - 既出の小さな要素の総数 = 既出の大きな要素の総数

  この時、N-1 までの和を考えると、以下の式が成立する。

    Σ既出の大きな要素の総数 = 要素の交換の総数

  また、最初の式における「既出の小さな要素の総数」は、
  BITで要素そのものを追加することで容易に算出できるようになる。

  備考:
  問題を勘違いしたことと、BITの使いどころの理解が浅かったことから、
  自力では解けなかった。
 */

#include <cstddef>
#include <cstdio>
#include "binary_indexed_tree.hpp"

int
main()
{
	int n(4);
	const int a[] = {4, 3, 1, 4, 2};

	ys::BinaryIndexedTree<size_t> bit;
	size_t r(0);

	bit.prepare(n+1);

	for (size_t i(0); i < (size_t)n; ++i) {
		r += i - bit.sum(a[i]);
		bit.add(a[i], 1);
	}

	std::printf("%lu\n", r);

	return 0;
}
