/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.6.3.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.6 p.110の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  特に無し。
 */

#include <cstdio>

//#define	N	53
#define	N	295927

int
main()
{
	if (0 < N) {	// 自然数を仮定
		int r(1);

		if (0 < N % 2) {
			for (int i(3); i * i <= N; i += 2) {
				if (0 < N % i) continue;
				r = i;
				break;
			}
		}
		else {
			r = 2;
		}

		if (r == 1) {
			std::printf("YES\n");
		}
		else {
			std::printf("NO (%d = %d x %d)\n", N, r, N / r);
		}
	}

	return 0;
}
