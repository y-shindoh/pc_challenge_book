/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	q_3.1.3b.cpp
 * @brief	「プログラミングコンテストチャレンジブック」の§3.1 p.131の問題の回答
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ .
 */

/*
  メモ:
  牛舎間の距離をminヒープに置き、
  同ヒープの要素数が牛の数より1小さくなるまで、以下の操作を繰り返す。

  1. 最小要素をminヒープから取り出す。
  2. 最小要素の隣接要素のうち小さい要素をminヒープから取り出す。
  3. これら2つの要素の和をminヒープに追加する。

  操作が終了した時点のminヒープの最小値が求める値。
 */

#include <cstdio>
#include <cassert>
#include <queue>
#include <vector>
#include <unordered_set>
#include <utility>

struct Node
{
	int v_;
	Node* p_;
	Node* n_;

	Node(int v,
		 Node* p = 0)
		: v_(v), p_(p), n_(0)
		{
			;
		}
};

typedef	std::pair<int, Node*>	VN;

int
main()
{
	int N(5);
	int M(3);	// 2以上
	const int x[] = {1, 2, 4, 8, 9};

	int w;
	Node* l(0);
	Node* c;
	Node* p(0);
	Node* n;

	std::priority_queue<VN, std::vector<VN>, std::greater<VN> > heap;
	std::unordered_set<Node*> used;

	for (int i(1); i < N; ++i) {
		w = x[i] - x[i-1];
		c = new Node(w, p);
		if (!l) l = c;
		if (p) p->n_ = c;
		p = c;
		heap.push(VN(w, c));
	}

	int u(0);

	while (M + u <= heap.size()) {
		VN vn = heap.top();
		heap.pop();
		c = vn.second;
		if (0 < used.count(c)) {
			--u;
			continue;
		}
		if (c->n_ && (!c->p_ || c->n_->v_ <= c->p_->v_)) {
			n = c->n_;
			heap.push(VN(vn.first + n->v_, c));
			c->n_ = n->n_;
			if (n->n_) n->n_->p_ = c;
			used.insert(n);
			delete n;
			++u;
		}
		else {
			assert(c->p_);
			p = c->p_;
			heap.push(VN(vn.first + p->v_, c));
			c->p_ = p->p_;
			if (!p->p_) l = c;
			else p->p_->n_ = c;
			used.insert(p);
			delete p;
			++u;
		}
	}

	while ('-') {
		VN vn = heap.top();
		if (0 == used.count(vn.second)) break;
		heap.pop();
	}

	std::printf("%d\n", heap.top().first);

	c = l;
	while(c) {
		n = c->n_;
		delete c;
		c = n;
	}

	return 0;
}
