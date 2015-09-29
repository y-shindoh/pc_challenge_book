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
  この票の初期値を b[0][0] = 1, それ以外を 0 とする。
  表を更新する際、横軸を右に進める (b[i][j] => b[i][j+1]) が、
  この時 b[i][j+1] = b[i][j] + b[i][j-1] + ... + b[i][0] の形で値を求める。
  最終的に b[m][n] が解となる。
 */

#include <cstddef>
#include <cstdio>
#include <vector>

int
main()
{
	int n(3);
	int m(3);
	const int a[] = {1, 2, 3};
	int M(10000);

	std::vector< std::vector<int> > b;
	b.resize(n+1);
	b[0].resize(m+1);
	for (int i(0); i <= n; ++i) {
		b[0][i] = 1;
	}
	for (int i(1); i <= n; ++i) {
		b[i].resize(m+1, 0);
	}

	int h;

	for (int i(1); i <= m; ++i) {
		for (int j(1); j <= n; ++j) {
			for (int k(0); k <= a[j-1]; ++k) {
				h = i - k;
				if (h < 0) break;
				b[i][j] += b[h][j-1];
			}
			b[i][j] %= M;
		}
	}

	std::printf("%d\n", b[n][m]);

	return 0;
}
