/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	union_find_tree.hpp
 * @brief	union find treeのテンプレート
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	http://www.slideshare.net/iwiwi/ss-3578491 と
			http://algoogle.hadrori.jp/algorithm/union-find.html を参考に実装した。
 */

#ifndef	__UNION_FIND_TREE_HPP__
#define	__UNION_FIND_TREE_HPP__ "union_find_tree.hpp"

#include <cstddef>
#include <cassert>
#include <vector>

//#define	__UNION_FIND_TREE_WITH_SIZE__	1

namespace ys
{
	/**
	 * @class	union find treeのテンプレート
	 * @note	テンプレートの型 @a TYPE には符号なし整数を指定すること。
	 */
	template<typename TYPE>
	class UnionFindTree
	{
	private:

		std::vector<TYPE> parent_;	///< 代表のインデックス
		std::vector<TYPE> rank_;	///< ランク
#ifdef	__UNION_FIND_TREE_WITH_SIZE__
		std::vector<TYPE> size_;	///< グループの大きさ
#endif	// __UNION_FIND_TREE_WITH_SIZE__

		/**
		 * グループ代表のインデックスの取得
		 * @param[in]	i	インデックス
		 * @return	グループ代表のインデックス
		 */
		size_t
		find(size_t i)
			{
				assert(i < parent_.size());

				size_t j = (size_t)parent_[i];

				if (i != j) {
					j = find(j);
					parent_[i] = (TYPE)j;
				}

				return j;
			}

	public:

		/**
		 * コンストラクタ
		 */
		UnionFindTree(size_t n)
			{
				parent_.reserve(n);
				rank_.resize(n, (TYPE)0);
#ifdef	__UNION_FIND_TREE_WITH_SIZE__
				size_.resize(n, (TYPE)1);
#endif	// __UNION_FIND_TREE_WITH_SIZE__

				for (size_t i(0); i < n; ++i) {
					parent_.push_back((TYPE)i);
				}
			}

		/**
		 * デストラクタ
		 */
		~UnionFindTree()
			{
				;
			}

		/**
		 * 2つのグループを統合
		 * @param[in]	i	インデックスその1
		 * @param[in]	j	インデックスその2
		 */
		void
		unite(size_t i,
			  size_t j)
			{
				assert(i < parent_.size());
				assert(j < parent_.size());

				i = find(i);
				j = find(j);
				if (i == j) return;

				if (rank_[i] < rank_[j]) {
					parent_[i] = (TYPE)j;
#ifdef	__UNION_FIND_TREE_WITH_SIZE__
					size_[j] += size_[i];
#endif	// __UNION_FIND_TREE_WITH_SIZE__
				}
				else {
					parent_[j] = (TYPE)i;
					if (rank_[i] == rank_[j]) rank_[i]++;
#ifdef	__UNION_FIND_TREE_WITH_SIZE__
					size_[i] += size_[j];
#endif	// __UNION_FIND_TREE_WITH_SIZE__
				}
			}

		/**
		 * 2つのインデックスが同一グループに所属しているか確認
		 * @param[in]	i	インデックスその1
		 * @param[in]	j	インデックスその2
		 * @return	true: 所属している, false: 所属していない
		 */
		bool
		same(size_t i,
			 size_t j)
			{
				assert(i < parent_.size());
				assert(j < parent_.size());

				return find(i) == find(j);
			}

#ifdef	__UNION_FIND_TREE_WITH_SIZE__
		/**
		 * グループの大きさを取得
		 * @param[in]	i	インデックス
		 * @return	グループの大きさ
		 */
		TYPE
		size(size_t i)
			{
				i = find(i);
				return size_[i];
			}
#endif	// __UNION_FIND_TREE_WITH_SIZE__
	};
};

#endif	// __UNION_FIND_TREE_HPP__
