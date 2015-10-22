/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.2.4.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.2 p.47の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  一番左の点xに注目する。
  右方向に移動し、xからR以内の最も遠い点yを見つける。
  点が見つからなかった場合は、xに印をつけて、xの右隣の点に注目を移す。
  点が見つかった場合は、yに印をつけて、
  右方向に移動し、yからR以内の最も遠い点zを見つけ、その右隣の点に注目を移す。
  以上、xが配列末尾を超えるまでこれを繰り返す。
 */

#include <cstddef>
#include <cstdio>
#include <vector>
#include <queue>

#define	N	6

int
main()
{
	int R(10);
	const int X[N] = {1, 7, 15, 20, 30, 50};

	int x(0);
	int y;
	int z;
	int c(0);

	while (x < N) {
		++c;
		y = x;
		while (y + 1 < N && X[y+1] <= X[x] + R) ++y;
		if (x == y) {
			++x;
		}
		else {
			z = y;
			while (z + 1 < N && X[z+1] <= X[y] + R) ++z;
			x = z + 1;
		}
	}

	std::printf("%d\n", c);

	return 0;
}
