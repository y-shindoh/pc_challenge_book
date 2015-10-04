/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.6.5.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.6 p.113の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  エラトステネスのふるいを使う。

  備考:
  問題におけるa, bの最大値が大きく、一方で b-a の最大値が小さいことから、
  b-a だけを効率的に探索するように考える必要がある。
 */

#include <cstddef>
#include <cstdio>
#include <vector>

int
main()
{
//	size_t a(22);
//	size_t b(37);
	size_t a(22801763489);
	size_t b(22801787297);

	std::vector<size_t> r1, r2;

	if (4 <= b) r1.push_back(2);

	for (size_t i(3); i * i < b; i += 2) {
		bool f(true);
		for (auto it = r1.begin(); it != r1.end() && *it * *it <= i; ++it) {
			if (0 < i % *it) continue;
			f = false;
			break;
		}
		if (f) r1.push_back(i);;
	}

	for (size_t i(0 < a % 2 ? a : a + 1); i < b; i += 2) {
		bool f(true);
		for (auto it = r1.begin(); it != r1.end() && *it * *it <= i; ++it) {
			if (0 < i % *it) continue;
			f = false;
			break;
		}
		if (f) r2.push_back(i);
	}

	std::printf("%lu, %lu => %lu\n", a, b, r2.size());

	return 0;
}
