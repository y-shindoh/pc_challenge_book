/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	binary_indexed_tree.hpp
 * @brief	binary indexed treeのテンプレート
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	http://anctgcc.hatenablog.com/entry/2014/12/03/194140 を参考に実装した。
 */

#ifndef	__BINARY_INDEXED_TREE_HPP__
#define	__BINARY_INDEXED_TREE_HPP__	"binary_indexed_tree.hpp"

#include <cstddef>
#include <cassert>
#include <vector>

namespace ys
{
	/**
	 * @class	binary inde treeのテンプレート・クラス
	 * @note	テンプレートの型 @a TYPE には整数・浮動小数点型を指定すること。
	 * @note	各メソッドの計算量について、
				n は size_t の値中にある1のビット数、
				m は配列の要素数と考える。
	 */
	template<typename TYPE>
	class BinaryIndexedTree
	{
	private:

		std::vector<TYPE> data_;	///< BIT本体

	public:

		/**
		 * コンストラクタ
		 */
		BinaryIndexedTree()
			{
				;
			}

		/**
		 * デストラクタ
		 */
		virtual
		~BinaryIndexedTree()
			{
				;
			}

		/**
		 * 指定区間の値を加算
		 * @param[in]	i	区間のインデックス
		 * @param[in]	v	加算する値
		 * @note	最悪計算量は O(log n) となる。
		 */
		void
		add(size_t i,
			const TYPE& v)
			{
				if (i == 0) {	// 本来は使わない
					data_[i] += v;
					return;
				}

				const size_t l(data_.size());

				while (i < l) {
					data_[i] += v;		// 該当パスに加算
					i += i & (~i + 1);	// i の最下位の桁を繰り上げ
				}
			}

		/**
		 * BITの構築
		 * @param[in]	length	BITの長さ
		 * @note	長さ @a length が設定された全区間 @a 0 のBITを構築する。
		 */
		void
		prepare(size_t length)
			{
				assert(0 < length);

				if (!data_.empty()) data_.clear();
				data_.resize(length, (TYPE)0);
			}

		/**
		 * BITの構築
		 * @param[in]	data	各エッジのコストの配列
		 * @param[in]	length	引数 @a data の長さ
		 * @note	引数 @a data は各エッジの終点ノードをインデックスと考える。
		 * @note	計算量は O(n log n) となる。
		 */
		void
		prepare(const TYPE* data,
				size_t length)
			{
				assert(data);
				assert(0 < length);

				if (!data_.empty()) data_.clear();
				data_.resize(length, (TYPE)0);

				for (size_t i(0); i < length; ++i) {
					add(i, data[i]);
				}
			}

		/**
		 * 0からのパス (連続するエッジをつなげたもの) の総コスト
		 * @param[in]	i	最後のエッジの終点ノード
		 * @return	総コスト
		 * @note	本メソッド実施前に @a prepare() を実行すること。
		 * @note	最悪計算量は O(log n) となる。
		 */
		TYPE
		sum(size_t i) const
			{
				assert(i < data_.size());

				TYPE v(data_[0]);

				while (0 < i) {
					v += data_[i];	// 部分パスを加算
					i &= i - 1;		// i の最下位ビットを0に変更
				}

				return v;
			}

		/**
		 * パス (連続するエッジをつなげたもの) の総コスト
		 * @param[in]	from	最初のエッジの始点ノード
		 * @param[in]	to	最後のエッジの終点ノード
		 * @return	総コスト
		 * @note	本メソッド実施前に @a prepare() を実行すること。
		 * @note	最悪計算量は O(log n) となる。
		 */
		TYPE
		sum(size_t from,
			size_t to) const
			{
				assert(from <= to);
				assert(from < data_.size());
				assert(to < data_.size());

				return sum(to) - sum(from);
			}
	};
};

#endif	// __BINARY_INDEXED_TREE_HPP__
