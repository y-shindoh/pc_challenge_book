/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.3.7.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.3 p.66の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  j個の要素のi分割の各パターンを考えると、以下のいずれかになる。

  (1) 全ての分割の要素数が2以上のパターン = j-i個の要素のi分割のパターンに対して全分割に1を足したもの
  (2) 要素数が1の分割があるパターン = j-1個の要素のi-1分割に1つの要素からなる分割を足したもの

  このアイディアを用いてDPを実行し、要素Nの1〜Mの分割数の総和を求めれば良い。

  備考:
  自力では分からなかっため、書籍の説明を読んだがやはり分からず、説明を参考に自力で解いた。
 */

#include <cstdio>
#include <climits>
#include <algorithm>

#define	N	4
#define	M	3
#define	D	10000

int
calculate(int b[M+1][N+1],
		  int i,
		  int j)
{
	if (b[i][j] != INT_MIN) return b[i][j];
	b[i][j] = 0;
	if (0 <= j - i) b[i][j] += calculate(b, i, j-i);
	if (0 < i && 0 < j) b[i][j] += calculate(b ,i-1, j-1);
	//b[i][j] %= D;
	return b[i][j];
}

int
main()
{
	int b[M+1][N+1];
	int r(0);

	b[1][0] = 0;							// 要素がない
	std::fill(b[1] + 1, b[1] + N + 1, 1);	// 要素あり1分割
	for (int i(2); i <= M; ++i) {
		b[i][0] = 0;						// 要素がない
		std::fill(b[i] + 1, b[i] + N + 1, INT_MIN);
	}

	// 要素Nの時の全分割を算出
	for (int i(1); i <= M; ++i) {
		r += calculate(b, i, N);
		//r %= D;
	}

	std::printf("%d\n", r);

	return 0;
}
