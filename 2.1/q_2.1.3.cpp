/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.1.3.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.1の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  幅優先探索でSからGまでの経路を見つける。
  テーブルを用い、各地点のSからの最短距離を保存する。
  また、同テーブルに未到達の点に特殊な値を埋め込むことで、
  各地点の到達・未到達を判断できるようにする。
 */

#include <cstddef>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <queue>

#define	INFINITY	(~(size_t)0)

typedef	std::pair<size_t, size_t> Point;

template<size_t H, size_t W>
size_t
search(const char board[H][W+1],
	   size_t count[H][W],
	   const Point& s,
	   const Point& g)
{
	Point p;
	size_t x, y;
	std::queue<Point> queue;
	queue.push(s);

	while (0 < queue.size()) {
		p = queue.front();
		queue.pop();
		if (p == g) break;
		x = p.first;
		y = p.second;
		if (0 < x && board[x-1][y] != '#' && count[x-1][y] == INFINITY) {
			count[x-1][y] = count[x][y] + 1;
			queue.push(Point(x-1,y));
		}
		if (x + 1 < H && board[x+1][y] != '#' && count[x+1][y] == INFINITY) {
			count[x+1][y] = count[x][y] + 1;
			queue.push(Point(x+1,y));
		}
		if (0 < y && board[x][y-1] != '#' && count[x][y-1] == INFINITY) {
			count[x][y-1] = count[x][y] + 1;
			queue.push(Point(x,y-1));
		}
		if (y + 1 < W && board[x][y+1] != '#' && count[x][y+1] == INFINITY) {
			count[x][y+1] = count[x][y] + 1;
			queue.push(Point(x,y+1));
		}
	}

	return count[g.first][g.second];
}

#define	N	((size_t)10)
#define	M	((size_t)10)

int
main(void)
{
	const char board[N][M+1] = {"#S######.#",
								"......#..#",
								".#.##.##.#",
								".#........",
								"##.##.####",
								"....#....#",
								".#######.#",
								"....#.....",
								".####.###.",
								"....#...G#"};
	size_t count[N][M];
	Point s, g;

	for (size_t i(0); i < N; ++i) {
		std::fill(count[i], count[i] + M, INFINITY);
		for (size_t j(0); j < M; ++j) {
			switch (board[i][j]) {
			case 'S':
				s = Point(i, j);
				count[i][j] = 0;
				break;
			case 'G':
				g = Point(i, j);
				break;
			}
		}
	}

	size_t r = search<N, M>(board, count, s, g);

	std::printf("%lu\n", r);

	return 0;
}
