/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.6.2.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.6 p.108の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:

  備考:
  再帰の説明で少し理解が進んだが、まだ甘い。
 */

#include <cstdio>

int
extgcd(int a,
	   int b,
	   int& x,
	   int& y)
{
	int d(a);

	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else {
		x = 1;
		y = 0;
	}

	return d;
}

#define	A	4
#define	B	11

int
main()
{
	int x(0);
	int y(0);
	int d = extgcd(A, B, x, y);

	if (d == 1) {
		if (0 <= x) {
			std::printf("%d * %d + ", A, x);
		}
		else {
			std::printf("%d * (%d) + ", A, x);
		}

		if (0 <= y) {
			std::printf("%d * %d = 1\n", B, y);
		}
		else {
			std::printf("%d * (%d) = 1\n", B, y);
		}
	}

	return 0;
}
