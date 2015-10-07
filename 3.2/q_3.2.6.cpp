/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_3.2.6.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§3.2 p.147の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  4つの集合 A, B, C, Dに対し、
  2つの集合 A, B のそれぞれの要素の和からなる1つの集合 AB を作り出す。
  同様に集合 CD も作り、
  AB の各要素に対して CD の要素に探索をかけ、2つの要素の和が0となるものを探す。
  計算量は O(n^2)。
 */

#include <cstdio>
#include <vector>
#include <unordered_set>
#include <algorithm>

int
main()
{
	int n(6);
	const int A[] = {-45, -41, -36, -36, 26, -32};
	const int B[] = {22, -27, 53, 30, -38, -54};
	const int C[] = {42, 56, -37, -75, -10, -6};
	const int D[] = {-16, 30, 77, -46, 62, 45};

	std::vector<int> AB;
	std::unordered_multiset<int> CD;

	AB.reserve(n*n);

	for (int i(0); i < n; ++i) {
		for (int j(0); j < n; ++j) {
			AB.push_back(A[i] + B[j]);
			CD.insert(C[i] + D[j]);
		}
	}

	int k(0);
	int m(n*n);

	for (int i(0); i < m; ++i) k += CD.count(-1 * AB[i]);

	std::printf("%d\n", k);

	return 0;
}
