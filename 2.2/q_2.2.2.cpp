/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.2.2.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.2の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  スタートから見て、終了が最も早い仕事を選ぶ。
  次にその終了より後で終了が最も早い仕事を選ぶ。
  これを繰り返して仕事がなくなるまで探索する。
 */

#include <cstddef>
#include <cstdio>
#include <climits>

int
main()
{
	const int s[] = {1, 2, 4, 6, 8};
	const int t[] = {3, 5, 7, 9, 10};
	int n(5);

	int c(0);
	int x(-1);
	int y;

	while ('-') {
		y = INT_MAX;
		for (int i(0); i < n; ++i) {
			if (s[i] <= x) continue;
			if (t[i] < y) y = t[i];
		}
		if (y == INT_MAX) break;
		++c;
		x = y;
	}

	std::printf("%d\n", c);

	return 0;
}
