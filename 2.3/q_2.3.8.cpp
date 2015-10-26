/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.3.8.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.3 p.67の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  縦軸の個数・横軸の商品の種類数に対し、各要素が組み合わせ数となる表bを作る。
  この票の初期値を b[0][*] = 1, それ以外を 0 とする。
  表を更新する際、横軸を右に進める (b[i][j] => b[i][j+1]) が、
  この時 b[i][j+1] = b[i][j] + b[i-1][j] + ... + b[i-a[j-1]][j] の形で値を求める。
  (計算時は b[i][j+1] = b[i-1][j+1] + b[i][j] - b[i-a[j]-1][j] の漸化式を用いる)
  最終的に b[m][n] が解となる。
 */

#include <cstdio>
#include <cstring>
#include <algorithm>

#define	N	3
#define	M	3
#define	D	10000

int
main()
{
	const int a[N] = {1, 2, 3};

	int b[M+1][N+1];

	std::memset((void*)b, 0, sizeof(b));
	std::fill(b[0], b[0] + N + 1, 1);	// 0個選ぶ組み合わせは常に1つ

	for (int j(1); j <= N; ++j) {
		for (int i(1); i <= M; ++i) {
			b[i][j] = b[i-1][j] + b[i][j-1];
			if (a[j-1] < i) b[i][j] -= b[i-a[j-1]-1][j-1];
			//b[i][j] %= D;
		}
	}

	std::printf("%d\n", b[M][N]);

	return 0;
}
