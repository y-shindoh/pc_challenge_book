/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.6.1.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.6 p.107の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  2点間を長辺とした三角形の、他辺の最大公倍数を求めれば良い。
  (ユークリッドの互除法を用いれば少ない計算量で求まる)
  「最大公倍数 - 1」が答えになる。

  備考:
  もう少し計算量の多い手法を考えてしまった。
 */

#include <cstdio>
#include <cassert>
#include <algorithm>

template<typename TYPE>
TYPE
gcd(TYPE a,
	TYPE b)
{
	assert(0 <= a);
	assert(0 <= b);
	assert(0 < a || 0 < b);

	if (a < b) std::swap<TYPE>(a, b);

	while (0 < b) {
		a %= b;
		std::swap<TYPE>(a, b);
	}

	return a;
}

int
main()
{
	const int P1[2] = {1, 11};
	const int P2[2] = {5, 3};

	int x = std::max<int>(P1[0], P2[0]) - std::min<int>(P1[0], P2[0]);
	int y = std::max<int>(P1[1], P2[1]) - std::min<int>(P1[1], P2[1]);
	unsigned int d = gcd<unsigned int>(x, y);

	std::printf("%u\n", d - 1);

	return 0;
}
