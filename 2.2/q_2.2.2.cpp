/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.2.2.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.2 p.43の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  スタートから見て、終了が最も早い仕事を選ぶ。
  次にその終了より後で開始し終了が最も早い仕事を選ぶ。
  これを繰り返して仕事がなくなるまで探索する。
 */

#include <cstdio>
#include <climits>

#define	N	5

int
main()
{
	// 入力データは終了時刻&開始時刻の昇順でソート済み (計算量 O(N log N))
	const int s[N] = {1, 2, 4, 6, 8};
	const int t[N] = {3, 5, 7, 9, 10};

	int j(0);	// 最初の1つめは確定
	int c(1);

	for (int i(1); i < N; ++i) {
		if (s[i] <= t[j]) continue;
		j = i;
		++c;
	}

	std::printf("%d\n", c);

	return 0;
}
