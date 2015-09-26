/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_1.6.3.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§1.6の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

#include <cstddef>
#include <cstdio>
#include <unordered_set>

int
main(void)
{
	int n(3);
	int m(10);
//	int m(9);
	int k[] = {1, 3, 5};

	std::unordered_set<int> buffer;

	// 2回実施時の数値の算出 (O(n^2))
	for (size_t i(0); i < n; ++i) {
		for (size_t j(0); j < n; ++j) {
			buffer.insert(k[i] * k[j]);
		}
	}

	// 4回実施時の数値の算出 (O(n^2))
	for (auto it = buffer.begin(); it != buffer.end(); ++it) {
		if (buffer.find(m - *it) == buffer.end()) continue;
		std::printf("FOUND!\n");
		return 0;
	}

	std::printf("NOT FOUND!\n");

	return 0;
}
