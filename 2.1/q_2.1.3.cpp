/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_2.1.3.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§2.1の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

#include <cstddef>
#include <cstdio>
#include <utility>
#include <deque>

#define	N	((size_t)10)
#define	M	((size_t)10)

#define	INFINITY	(~(size_t)0)

typedef	std::pair<size_t, size_t> Point;

size_t
search(const char board[N][M+1],
	   size_t count[N][M],
	   const Point& s,
	   const Point& g)
{
	Point p;
	size_t x, y;
	std::deque<Point> queue;
	queue.push_back(s);

	while (0 < queue.size()) {
		p = queue.front();
		queue.pop_front();
		if (p == g) break;
		x = p.first;
		y = p.second;
		if (0 < x && board[x-1][y] != '#' && count[x-1][y] == INFINITY) {
			count[x-1][y] = count[x][y] + 1;
			queue.push_back(Point(x-1,y));
		}
		if (x + 1 < N && board[x+1][y] != '#' && count[x+1][y] == INFINITY) {
			count[x+1][y] = count[x][y] + 1;
			queue.push_back(Point(x+1,y));
		}
		if (0 < y && board[x][y-1] != '#' && count[x][y-1] == INFINITY) {
			count[x][y-1] = count[x][y] + 1;
			queue.push_back(Point(x,y-1));
		}
		if (y + 1 < M && board[x][y+1] != '#' && count[x][y+1] == INFINITY) {
			count[x][y+1] = count[x][y] + 1;
			queue.push_back(Point(x,y+1));
		}
	}

	return count[g.first][g.second];
}

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
		for (size_t j(0); j < M; ++j) {
			count[i][j] = INFINITY;
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

	size_t r = search(board, count, s, g);

	std::printf("%lu\n", r);

	return 0;
}
