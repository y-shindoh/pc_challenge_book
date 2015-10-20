/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	maximum_flow.hpp
 * @brief	最大流問題のDinic法のテンプレート
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	http://www.amazon.co.jp/2-ebook/dp/B00CY9256C/ を参考に実装した。
 */

#ifndef	__MAXIMUM_FLOW_HPP__
#define	__MAXIMUM_FLOW_HPP__	"maximum_flow.hpp"

#include <cassert>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

namespace ys
{
	/**
	 * @class	Dinic法のテンプレート
	 * @note	型 @a N_TYPE には符号なし整数を指定すること。
	 * @note	型 @a C_TYPE には容量を扱うに十分な幅の型を指定すること。
	 */
	template<typename N_TYPE, typename C_TYPE>
	class MaximumFlow
	{
	private:

		/**
		 * 辺を示す構造
		 * @note	要素は「行き先の頂点」「空き容量」「逆辺のインデックス」を示す。
		 */
		typedef	std::tuple<N_TYPE, C_TYPE, N_TYPE>	Edge;

		std::vector< std::vector<Edge> > graph_;	///< グラフ
		std::vector<int> level_;					///< 各ノードの深さ
		std::vector<N_TYPE> iteration_;				///< 各ノードの探索状況
		std::queue<N_TYPE> queue_;					///< BFSの作業領域
		C_TYPE max_capacity_;						///< 辺の容量の最大値

		/**
		 * 各ノードに深さの情報を付与
		 * @param[in]	from	探索の始点
		 */
		void
		bf_search(N_TYPE from)
			{
				assert(from < (N_TYPE)graph_.size());

				std::fill(level_.begin(), level_.end(), ~(N_TYPE)0);
				level_[from] = (N_TYPE)0;
				queue_.push(from);

				while (0 < queue_.size()) {
					N_TYPE v = queue_.front();
					queue_.pop();

					for (auto& e : graph_[v]) {
						N_TYPE n = std::get<0>(e);				// 次の頂点
						C_TYPE c = std::get<1>(e);				// 空き容量
						if (c <= (C_TYPE)0) continue;			// 空き容量なし => スキップ
						if (level_[n] != ~(N_TYPE)0) continue;	// 深さ確定済み => スキップ
						level_[n] = level_[v] + (N_TYPE)1;
						queue_.push(n);
					}
				}
			}

		/**
		 * 流量決定の1試行を実施
		 * @param[in]	from	探索の始点
		 * @param[in]	to	探索の終点
		 * @param[in]	flow	流量の最大値 (キャパシティを無視した値)
		 * @return	実際の流量
		 */
		C_TYPE
		df_search(N_TYPE from,
				  N_TYPE to,
				  C_TYPE flow)
			{
				assert(from < (N_TYPE)graph_.size());
				assert(to < (N_TYPE)graph_.size());
				assert((C_TYPE)0 <= flow);

				if (from == to) return flow;

				for (N_TYPE& i = iteration_[from]; i < (N_TYPE)graph_[from].size(); ++i) {
					N_TYPE n = std::get<0>(graph_[from][i]);	// 次の頂点
					C_TYPE& c = std::get<1>(graph_[from][i]);	// 空き容量
					N_TYPE r = std::get<2>(graph_[from][i]);	// 逆辺のインデックス

					if (level_[n] <= level_[from]) continue;	// 深さの順序が違う => スキップ
					if (c <= (C_TYPE)0) continue;				// 空き容量なし => スキップ

					// 探索 (深さ優先)
					C_TYPE d = df_search(n, to, std::min(flow, c));
					if (d <= (C_TYPE)0) continue;	// 変化なし => 次の頂点
					c -= d;
					std::get<1>(graph_[n][r]) += d;
					return d;
				}

				return (C_TYPE)0;
			}

	public:

		/**
		 * コンストラクタ
		 * @param[in]	length	ノードの総数
		 * @param[in]	max_capacity	辺の容量の最大値 (事前に分かっている場合に代入)
		 */
		MaximumFlow(N_TYPE length,
					const C_TYPE max_capacity = (C_TYPE)0)
			: graph_(length), level_(length), iteration_(length), max_capacity_(max_capacity)
			{
				assert(0 < length);
			}

		/**
		 * デストラクタ
		 */
		virtual
		~MaximumFlow()
			{
				;
			}

		/**
		 * グラフに辺を追加 (同時に逆辺も追加)
		 * @param[in]	from	辺の始点
		 * @param[in]	to	辺の終点
		 * @param[in]	capacity	辺の容量
		 */
		void
		add_edge(N_TYPE from,
				 N_TYPE to,
				 C_TYPE capacity)
			{
				assert(from < (N_TYPE)graph_.size());
				assert(to < (N_TYPE)graph_.size());
				assert((C_TYPE)0 <= capacity);

				N_TYPE m = graph_[from].size();
				N_TYPE n = graph_[to].size();

				graph_[from].push_back(Edge(to, capacity, n));
				graph_[to].push_back(Edge(from, (C_TYPE)0, m));

				if (max_capacity_ < capacity) max_capacity_ = capacity;
			}

		/**
		 * 流量の算出
		 * @param[in]	from	探索の始点
		 * @param[in]	to	探索の終点
		 * @return	実際の流量
		 */
		C_TYPE
		execute(N_TYPE from,
				N_TYPE to)
			{
				assert(from < (N_TYPE)graph_.size());
				assert(to < (N_TYPE)graph_.size());

				C_TYPE flow(0);
				C_TYPE f;

				while ('-') {
					bf_search(from);
					if (level_[to] == ~(N_TYPE)0) return flow;	// 探索不要
					std::fill(iteration_.begin(), iteration_.end(), (N_TYPE)0);
					while ('-') {
						f = df_search(from, to, max_capacity_);
						if (f <= (C_TYPE)0) break;
						flow += f;
					}
				}
			}
	};
};

#endif	// __MAXIMUM_FLOW_HPP__
