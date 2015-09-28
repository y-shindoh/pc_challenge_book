/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.2.4.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.2の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  最も短い板と次に短い板を見つけ出し、1つのものみなす。
  これを繰り返すと板が1つになる。
  この過程を逆にたどれば良い。
 */

#include <cstddef>
#include <cstdio>
#include <vector>
#include <queue>

int
main()
{
	int N(3);
	const int L[] = {8, 5, 8};

	std::priority_queue<int, std::vector<int>, std::greater<int> > min_heap;

	for (int i(0); i < N; ++i) {
		min_heap.push(L[i]);
	}

	int x, y, z;
	int c(0);

	// 計算量は O(n log n)。
	while (1 < min_heap.size()) {
		x = min_heap.top();
		min_heap.pop();
		y = min_heap.top();
		min_heap.pop();
		z = x + y;
		min_heap.push(z);

		c += z;
		std::printf("%d = %d + %d\n", z, x, y);
	}

	std::printf("=> %d\n", c);

	return 0;
}
