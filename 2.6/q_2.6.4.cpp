/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.6.4.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.6 p.111の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  エラトステネスのふるいを使う。
 */

#include <cstddef>
#include <cstdio>
#include <vector>

int
main()
{
//	size_t n(11);
	size_t n(1000000);

	std::vector<size_t> r;
	bool f;

	if (2 <= n) {
		r.push_back(2);

		for (size_t i(3); i <= n; i += 2) {
			f = true;
			for (auto it = r.begin(); it != r.end() && *it * *it <= i; ++it) {
				if (0 < i % *it) continue;
				f = false;
				break;
			}
			if (f) r.push_back(i);
		}
	}

	std::printf("%lu => %lu\n", n, r.size());

	return 0;
}
