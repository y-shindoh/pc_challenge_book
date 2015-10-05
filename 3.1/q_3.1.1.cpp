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

int
main()
{
	int n(5);
	const int a[] = {2, 3, 3, 5, 6};
	int k(3);

	int s(-1);	// k未満の末尾
	int e(n);	// k以上の先頭
	int i;

	while (s + 1 < e) {
		i = (s + e) / 2;
		if (k <= a[i]) {
			e = i;
		}
		else if (a[i] < k) {
			s = i;
		}
	}

	std::printf("%d\n", e);

	return 0;
}
