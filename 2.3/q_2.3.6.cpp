/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.3.6.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.3 p.63の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  増加部分列の長さに対するその時点での整数の最小値の表を作り、
  数列を1つずつ進めて表を更新する。
  最終的に表で最小値が更新された最も末尾寄りの値が回答になる。

  備考:
  表の更新は、二分探索で実装したほうが速い。
 */

#include <cstddef>
#include <cstdio>
#include <climits>
#include <vector>

int
main()
{
	int n(5);
	const int a[] = {4, 2, 3, 1, 5};

	std::vector<int> b;
	int k(0);

	b.resize(n+1, INT_MAX);
	b[0] = INT_MIN;

	for (int i(0); i < n; ++i) {
		for (int j(k); 0 <= j; --j) {
			if (b[j] > a[i]) continue;
			if (b[j+1] <= a[i]) continue;
			if (k + 1 < n && k <= j) k = j + 1;
			b[j+1] = a[i];
			break;	// これより短い箇所は見なくて良い
		}
	}

	for (int i(n); 0 < i; --i) {
		if (b[i] == INT_MAX) continue;
		std::printf("%d\n", i);
		break;
	}

	return 0;
}
