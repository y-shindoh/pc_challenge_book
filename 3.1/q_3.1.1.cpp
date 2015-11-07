/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_3.1.1.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§3.1 p.128の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  二部探索して、a_i-1の値がk未満、a_iの値がk以上となる位置iを見つける。
 */

#include <cstdio>
#include <algorithm>

#define	N	5
#define	K	3

int
main()
{
	const int a[N] = {2, 3, 3, 5, 6};

	int s(-1);	// K未満の先頭 (先頭に INT_MIN を仮想的に追加したイメージ)
	int e(N);	// K以上の末尾 (末尾に INT_MAX を仮想的に追加したイメージ)
	int i;

	while (s + 1 < e) {
		i = (s + e) / 2;

		if (a[i] < K) s = i;
		else e = i;
	}

	std::printf("%d ", e);
	std::printf("(%lu)\n", (size_t)(std::lower_bound(a, a + N, K) - a));

	return 0;
}
