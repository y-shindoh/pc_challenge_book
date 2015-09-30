/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.5.1.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.5 p.93の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  各ノードの色を保持する配列を用意し、配列を 0, 1, ... の順に埋めていく。
  このとき、各ノードの色は隣接行列を参照して隣接ノードと同じにならないようにする。
  全体的な処理としては単純なバック・トラッキングとなる。
 */

#include <cstdio>

//#define	N	3
#define	N	4
#define	C	((char)2)

bool
search(const char t[N][N],
	   char* b,
	   int i = 0)
{
	if (N <= i) return true;

	bool flag;

	for (char h(0); h < C; ++h) {
		flag = true;
		for (int j(0); j < i; ++j) {
			if (!t[j][i]) continue;
			if (b[j] != h) continue;
			flag = false;
			break;
		}
		if (!flag) continue;
		b[i] = h;
		if (search(t, b, i+1)) return true;
	}

	return false;
}

int
main()
{
	char b[N];

#if	(N == 3)
	const char t[3][3] = {{0, 1, 1},
						  {1, 0, 1},
						  {1, 1, 0}};
#else	// N == 3
	const char t[4][4] = {{0, 1, 0, 1},
						  {1, 0, 1, 0},
						  {0, 1, 0, 1},
						  {1, 0, 1, 0}};
#endif	// N == 3

	if (search(t, b)) {
		std::printf("Yes (");
		for (int i(0); i < N; ++i) {
			if (0 < i) std::printf(", ");
			std::printf("%d", (int)b[i]);
		}
		std::printf(")\n");
	}
	else {
		std::printf("No\n");
	}

	return 0;
}
