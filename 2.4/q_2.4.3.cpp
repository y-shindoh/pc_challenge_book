/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.4.3.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.4 p.85の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  N x 3の長さのunion find treeを用い、
  各動物がA, B, Cそれぞれの場合について、同時に成立する情報をグルーピングする。
  このunion find treeにより、後の情報の矛盾を検出する。

  備考:
  自力では解けなかったため、書籍の解説の冒頭を読んでから考えた。
  (もっとも、それもすぐにはピンとこなかったのだが)
 */

#include <cstddef>
#include <cstdio>
#include <vector>
#include "union_find_tree.hpp"

int
main()
{
	int N(100);
	int K(7);
	int d[][3] = {{1, 101, 1},
				  {2, 1, 2},
				  {2, 2, 3},
				  {2, 3, 3},
				  {1, 1, 3},
				  {2, 3, 1},
				  {1, 5, 5}};

	std::vector<int> error;
	ys::UnionFindTree<unsigned int> tree((N + 1) * 3);

	for (int i(0); i < K; ++i) {
		// 入力チェック
		if ((1 != d[i][0] && 2 != d[i][0]) || (d[i][1] < 1 && N < d[i][1]) || (d[i][2] < 1 && N < d[i][2])) {
			error.push_back(i);
			continue;
		}

		if (d[i][0] == 1) {
			// 情報1 (同じ種類)
			if (tree.same(d[i][1], d[i][2] + N) || tree.same(d[i][1], d[i][2] + N * 2)) {
				error.push_back(i);	// 異なる種類の関係が成立
				continue;
			}
			else {
				for (int j(0); j < 3; ++j) {
					tree.unite(d[i][1] + N * j, d[i][2] + N * j);
				}
			}
		}
		else {
			// 情報2 (食物連鎖)
			if (tree.same(d[i][1], d[i][2]) || tree.same(d[i][1], d[i][2] + N * 2)) {
				error.push_back(i);	// 連鎖しない関係が成立
				continue;
			}
			else {
				for (int j(0); j < 3; ++j) {
					int k = (j + 1) % 3;
					tree.unite(d[i][1] + N * j, d[i][2] + N * k);
				}
			}
		}
	}

	std::printf("<<%lu>>\n", error.size());

	for (auto it = error.begin(); it != error.end(); ++it) {
		int k = *it;
		std::printf("[%d] %d, %d, %d\n", k, d[k][0], d[k][1], d[k][2]);
	}

	return 0;
}
