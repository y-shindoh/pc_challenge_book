/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_3.4.1b.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§3.5 p.188の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  Dinic法。
 */

#include <cstddef>
#include <cstdio>
#include "maximum_flow.hpp"

#define	V	5

int
main()
{
	ys::MaximumFlow<size_t, double> solver(V);

	solver.add_edge(0, 1, 10.0);
	solver.add_edge(0, 2, 2.0);
	solver.add_edge(1, 2, 6.0);
	solver.add_edge(1, 3, 6.0);
	solver.add_edge(2, 4, 5.0);
	solver.add_edge(3, 2, 3.0);
	solver.add_edge(3, 4, 8.0);

	std::printf("%G\n", solver.execute(0, 4));

	return 0;
}
