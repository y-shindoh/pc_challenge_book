/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_3.2.3.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§3.2 p.139の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  全ての転回幅を試すのは避けられないので、
  1回の試行が O(N) で済むよう、
  各牛が何回回転の影響を受けているかを O(1) で算出できるように処理を行う。

  備考:
  素直な実装の O(n^3) 版から O(n^2) 版を連想するらしいが、
  発熱中だったこともあってか、すぐにはそれに気づけなかった。
 */

#include <cstdio>
#include <cstring>

// O(n^3) 版
int
calc(const char* a,
	 int* b,
	 int N,
	 int K)
{
	std::memset((void*)b, 0, sizeof(int) * N);
	int k(0);

	for (int i(0); i + K <= N; ++i) {
		if (a[i] == 'F') {
			if (b[i] % 2 == 1) {
				for (int j(0); j < K; ++j) ++b[i+j];
				++k;
			}
		}
		else {
			if (b[i] % 2 == 0) {
				for (int j(0); j < K; ++j) ++b[i+j];
				++k;
			}
		}
	}

	for (int i(0); i < N; ++i) {
		if (a[i] == 'F' && b[i] % 2 != 0) return -1;
		if (a[i] == 'B' && b[i] % 2 != 1) return -1;
	}

	return k;
}

// O(n^2) 版
int
calc(const char* a,
	 bool* b,
	 int N,
	 int K)
{
	std::memset((void*)b, 0, sizeof(bool) * N);
	int t(0);
	int k(0);

	for (int i(0); i + K <= N; ++i) {
		if (a[i] == 'F') {
			if (t % 2 == 1) {
				b[i] = true;
				++t, ++k;
			}
		}
		else {
			if (t % 2 == 0) {
				b[i] = true;
				++t, ++k;
			}
		}
		if (K - 1 <= i && b[i-K+1]) --t;
	}

	for (int i(N-K+1); i < N; ++i) {
		if (a[i] == 'F') {
			if (t % 2 == 1) return -1;
		}
		else {
			if (t % 2 == 0) return -1;
		}
		if (K - 1 <= i && b[i-K+1]) --t;
	}

	return k;
}

int
main()
{
	int N(7);
	const char a[] = "BBFBFBB";
//	int b[16];
	bool b[16];

	for (int k(N); 0 < k; --k) {
		int m = calc(a, b, N, k);
		if (m < 0) continue;
		std::printf("K = %d\n", k);
		std::printf("M = %d\n", m);
		break;
	}

	return 0;
}
