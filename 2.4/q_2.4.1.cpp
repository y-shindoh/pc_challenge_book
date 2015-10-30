/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.4.1.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.4 p.73の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  初期状態に対し、到達できるガソリン・スタンドをリスト・アップする。
  この状態でゴールまで到達するならそこで終了。(※)
  ゴールに到達できない場合、
  到達できるガソリン・スタンドのうち給油量が最大のものに寄ったと仮定し、
  到達できる距離を増やす。
  この際、寄ったと仮定したガソリンスタンドをリストから削除し、
  また、到達できるガソリン・スタンドが増えるのでリストに追加する。
  以下、※に戻る形でループする。
  途中、リストが空になった場合はゴールに到着できないと考える。
 */

#include <cstdio>
#include <queue>

#define	N	4
#define	L	25
#define	P	10

int
main()
{
	const int A[N] = {10, 14, 20, 21};
	const int B[N] = {10, 5, 2, 4};

	std::priority_queue<int> queue;	// 到着済みガソリンスタンドの給油量
	int l(0);	// 移動可能距離
	int h(0);	// 最左の未到着ガソリンスタンド
	int r(0);	// 給油必要回数

	queue.push(P);

	while (0 < queue.size()) {
		l += queue.top();
		queue.pop();
		if (L <= l) break;	// 到達
		++r;
		while (h < N && A[h] <= l) queue.push(B[h++]);
	}

	if (L <= l) std::printf("%d\n", r);

	return 0;
}
