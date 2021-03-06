/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.1.1.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.1の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  整数 a[0], ..., a[n] に対し、各整数を足す・足さないで深さ優先探索を行う。
 */

#include <cstddef>
#include <cstdio>
#include <vector>

/**
 * 深さ優先探索 (DFS) のサンプル実装
 */
template<typename TYPE>
bool
check(const TYPE* data,
	  std::vector<bool>& flags,	// 事前にfalseで埋めておくこと!
	  const TYPE value,
	  size_t length,
	  size_t index = 0)
{
	if (value == 0) return true;
	if (length <= index) return false;

	flags[index] = true;
	bool result = check<TYPE>(data, flags, value - data[index], length, index + 1);
	if (result) return true;

	flags[index] = false;
	result = check<TYPE>(data, flags, value, length, index + 1);
	if (result) return true;

	return false;
}

int
main(void)
{
	size_t n(4);
	int a[] = {1, 2, 4, 7};
	int k(13);
//	int k(15);

	std::vector<bool> flags(n, false);

	if (check<int>(a, flags, k, n)) {
		bool flag(false);
		std::printf("Yes (");
		for (size_t i(0); i < n; ++i) {
			if (!flags[i]) continue;
			if (flag) std::printf(", ");
			std::printf("%d", a[i]);
			flag = true;
		}
		std::printf(")\n");
	}
	else {
		std::printf("No\n");
	}

	return 0;
}
