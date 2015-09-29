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
  初期状態でゴールまで到達するならそこで終了。(※)
  ゴールに到達できない場合、
  到達できるガソリン・スタンドのうち給油量が最大のものに寄ったと仮定し、
  到達できる距離を増やす。
  この際、寄ったと仮定したガソリンスタンドをリストから削除し、
  また、到達できるガソリン・スタンドが増えるのでリストに追加する。
  以下、※に戻る形でループする。
  途中、リストが空になった場合はゴールに到着できないと考える。
 */

#include <cstddef>
#include <cstdio>
#include <queue>

int
main()
{
	int N(4);
	int L(25);
	int P(10);
	const int A[] = {10, 14, 20, 21};
	const int B[] = {10, 5, 2, 4};

	std::priority_queue<int> queue;	// 給油量のリスト
	int k(0);	// 最後に到達したガソリン・スタンド
	int r(0);	// 給油回数

	while (P < L) {
		for (int i(k); i < N; ++i) {
			if (P < A[i]) break;
			queue.push(B[i]);
			k = i;
		}
		if (queue.empty()) return -1;
		P += queue.top();
		queue.pop();
		++r;
	}

	std::printf("%d\n", r);

	return 0;
}
