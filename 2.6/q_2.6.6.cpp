/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.6.6.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.6 p.115の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  通常の計算方法だと計算量が大きいので、繰り返し二乗法を使う。

  備考:
  繰り返し二乗法を知らなかったため、書籍の説明を読んで解いた。
 */

#include <cstddef>
#include <cstdio>
#include <cassert>
#include <vector>

template<typename TYPE>
TYPE
power_number(TYPE base,
			 TYPE exponet,
			 TYPE divisor = (TYPE)0)
{
	TYPE r(1);

	if (0 < divisor) base %= divisor;

	for (TYPE i(0); 0 < exponet; ++i) {
		if (exponet & ((TYPE)1 << i)) {
			r *= base;	// オリジナルの base の 2^i をかける
			if (0 < divisor) r %= divisor;
			exponet &= ~((TYPE)1 << i);
		}
		base *= base;
		if (0 < divisor) base %= divisor;
	}

	return r;
}

template<typename TYPE>
bool
is_prime(TYPE number)
{
	if (number <= (TYPE)1) return false;
	if (number == (TYPE)2) return true;
	if (number % (TYPE)2 == 0) return false;

	for (TYPE i(3); i * i <= number; i += (TYPE)2) {
		if (0 < number % i) continue;
		return false;
	}

	return true;
}

typedef	unsigned long long	ull;

int
main()
{
	ull n(17);
//	ull n(561);
//	ull n(4);
	ull y; // := x^n

	for (ull x(2); x < n; ++x) {
		y = power_number<ull>(x, n);	// 可読性のため桁あふれ対策なし

		if (x % n == y % n) {
			if (is_prime<ull>(x)) {
				std::printf("No (n = %llu, x = %llu, x^n = %llu)\n", n, x, y);
			}
			else {
				std::printf("YES (n = %llu, x = %llu, x^n = %llu)\n", n, x, y);
			}

			return 0;
		}
	}

	std::printf("NO\n");

	return 0;
}
