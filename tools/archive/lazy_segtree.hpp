#ifndef LAZY_SEGTREE_HPP
#define LAZY_SEGTREE_HPP

#include <functional>
#include <vector>
#include <cstddef>
#include <iterator>
#include "monoid.hpp"
#include "ceil_log2.hpp"
#include "pow2.hpp"

/*
usage:

// 6要素の区間加算区間和遅延セグ木
tools::lazy_segtree<std::pair<i64, i64>, i64> lazy_segtree(
  tools::monoid<std::pair<i64, i64>>(
    [](const std::pair<i64, i64>& t1, const std::pair<i64, i64>& t2) {
      return std::make_pair(t1.first + t2.first, t1.second + t2.second);
    },
    std::make_pair(0, 0)
  ),
  tools::group<i64>::plus(),
  [](const std::pair<i64, i64>& t, const i64& e) {
    return std::make_pair(t.first, t.second + t.first * e);
  },
  6,
  std::make_pair(1, 0)
);

// [0, 3)に一様に30を加算
lazy_segtree.update(0, 3, 30);

// [2, 6)の和を取得
std::cout << lazy_segtree.query(2, 6).second << std::endl;
*/

// Source: beet-aizu's library ( https://github.com/beet-aizu/library/blob/96342d51c6e11256d3863af60c76cd376490aa57/segtree/basic/chien.cpp )
// Author: beet ( https://twitter.com/beet_aizu )
// License: Unknown
namespace tools {
  // # Introduction
  // 遅延伝搬セグメント木は配列に対する2種類のクエリを高速に扱うことができる。
  // ここでは一方を区間作用クエリ、もう一方を区間集約クエリと呼ぶことにする。
  // 区間作用クエリは、与えられた区間全体に対して一様にある一つの値を作用させ、区間内の値すべてを更新するクエリである。
  // 区間集約クエリは、与えられた区間全体の値を、結合則を満たすなんらかの演算で集約して得られる値を取得するクエリである。
  // 
  // # Restriction
  // 遅延伝搬セグメント木が扱うクエリは、以下の(1)～(4)の制約を満たしていなければならない。
  // 逆に言えば、これらの制約を満たしていない場合、遅延伝搬セグメント木は使えない。
  // 
  // (1) 以下の2要素はあわせて一つのモノイドを成していなければならない。
  //     * 区間集約クエリの結果がとりうる値の集合T
  //     * 区間集約クエリで値を集約するのに用いる演算f:T×T->T
  // [!] 実は半群を許容するような遅延伝搬セグメント木を作ることもできるが、モノイドを要求する方が実装が簡単になるのでこうする。
  //     仮に扱いたい対象が半群であったとしても、単位元の埋め込みで直ちに半群からモノイドを作ることができるので、実用上の問題はない。
  // [!] モノイドは可換でなくてもよい。この場合のfのオペランドの左右は、元の配列の左右と同じ。
  // 
  // (2) 以下の2要素はあわせて一つのモノイドを成していけなければならない。
  //     * 区間作用クエリで作用させる値（作用素）がとりうる値の集合E
  //     * 古い区間作用クエリの作用素と新しい区間作用クエリの作用素とをマージする演算h:E×E->E
  // [!] 実は半群を許容するような遅延伝搬セグメント木を作ることもできるが、モノイドを要求する方が実装が簡単になるのでこうする。
  //     仮に扱いたい対象が半群であったとしても、単位元の埋め込みで直ちに半群からモノイドを作ることができるので、実用上の問題はない。
  // [!] モノイドは可換でなくてもよい。この場合のhのオペランドの左右は、左が古い側で右が新しい側。
  // 
  // (3) (2)のモノイドは(1)のモノイドに作用素モノイドとして振る舞わなければならない。
  // [!] つまり複数の作用素をマージして一度に作用させても、一個ずつ順に作用させた場合と結果は変わってはいけない。
  //
  // (4) 区間作用クエリで作用素を作用させる演算をg:T×E->Tとする。
  //     任意のa, b∈Tと任意のc∈Eに対して、g(f(a, b), c) = f(g(a, c), g(b, c))
  // [!] 区間全体に対して一様に作用素を作用させた際の集約結果（左辺）が定義通り求められる（右辺）ことを意味している。
  // 
  // # Implementation Policy
  // 遅延伝搬セグメント木の各ノードに、集約結果（∈T）という値と、作用素（∈E）という値を持たせる。
  // 集約結果は、これまでのすべての区間作用クエリを反映した最新の値ではないことがある。
  // 区間集約クエリを要求されたときだけ、作用素を子孫ノードへ伝搬し、集約結果を再計算することで、高速な処理を実現するという方針をとる。
  // 
  // 遅延伝搬セグメント木を操作する際、以下の不変条件が満たされるような操作のみ行うようにする。
  // * すべての作用素は、先祖ノードすべての集約結果に作用し終わった状態でのみ存在できる。
  // * すべての作用素は、その作用素が存在するノードおよび子孫ノードの集約結果を、まだ更新していてはいけない。
  template <typename T, typename E>
  class lazy_segtree {
  private:
    ::tools::monoid<T> monoid;
    ::tools::monoid<E> operator_monoid;
    ::std::function<T(T, E)> act;

    // 完全二分木の高さ。
    ::std::size_t height;

    // 集約結果を完全二分木で持つ。
    // ノード番号1がルートを表し、ノード番号0は使わない。
    // 実装上1始まりの方が都合がよいため。
    ::std::vector<T> data;

    // 作用素を完全二分木で持つ。
    // ノード番号1がルートを表し、ノード番号0は使わない。
    // 実装上1始まりの方が都合がよいため。
    ::std::vector<E> lazy;

    // # 結果
    // このノードの作用素を作用させたときの集約結果。
    // 不変条件より、このノードの先祖ノードがすべて遅延伝搬済み（＝作用素が単位元）である場合に限って、
    // このメソッドの返り値は、このノードが表す区間に対して区間集約クエリを行ったときの値でもある。
    T reflect(const ::std::size_t node_id) const {
      return this->lazy[node_id] == this->operator_monoid.identity() ? this->data[node_id] : this->act(this->data[node_id], this->lazy[node_id]);
    }

    // # 事前条件
    // * このノードの先祖ノードはすべて遅延伝搬済みである
    // * このノードはリーフノードではない
    // 
    // # 処理内容
    // このノードの作用素を子ノードに伝搬させる。
    void propagate(const ::std::size_t node_id) {
      if(this->lazy[node_id] == this->operator_monoid.identity()) return;
      this->lazy[(node_id << 1) | 0] = this->operator_monoid.operation(this->lazy[(node_id << 1) | 0], this->lazy[node_id]);
      this->lazy[(node_id << 1) | 1] = this->operator_monoid.operation(this->lazy[(node_id << 1) | 1], this->lazy[node_id]);
      this->data[node_id] = this->reflect(node_id);
      this->lazy[node_id] = this->operator_monoid.identity();
    }

    // # 事前条件
    // * このノードはリーフノードである
    //
    // # 処理内容
    // ルートノードからこのノードまで、順番に作用素を伝搬させる。
    void thrust(const ::std::size_t node_id) {
      for (::std::size_t h = this->height; h > 0; --h) {
        this->propagate(node_id >> h);
      }
    }

    // # 処理内容
    // このノードの親ノードからルートノードまで、順番に集約結果の再計算を行う。
    // 
    // # 事後条件
    // この操作を行うと、このノードの作用素の効果が、このノードの先祖ノードの集約結果に反映される。
    // [!] 一方、このノードの作用素の効果が、このノードの子孫ノードにまで及ぶことはまだない。
    void recalc(::std::size_t node_id) {
      while (node_id >>= 1) {
        this->data[node_id] = this->monoid.operation(this->reflect((node_id << 1) | 0), this->reflect((node_id << 1) | 1));
      }
    }

    ::std::size_t capacity() const {
      return this->data.size() / 2;
    }

  public:
    lazy_segtree(
      const ::tools::monoid<T>& monoid,
      const ::tools::monoid<E>& operator_monoid,
      const ::std::function<T(T, E)>& act,
      const ::std::size_t& n
    ) :
      monoid(monoid),
      operator_monoid(operator_monoid),
      act(act),
      height(::tools::ceil_log2(n)),
      data(::tools::pow2(this->height + 1), monoid.identity()),
      lazy(::tools::pow2(this->height + 1), operator_monoid.identity()) {
    }

    template <typename U>
    lazy_segtree(
      const ::tools::monoid<T>& monoid,
      const ::tools::monoid<E>& operator_monoid,
      const ::std::function<T(T, E)>& act,
      const ::std::size_t& n,
      const U& t,
      const ::std::function<T(U)>& map
    ) :
      monoid(monoid),
      operator_monoid(operator_monoid),
      act(act),
      height(::tools::ceil_log2(n)),
      data(::tools::pow2(this->height + 1), monoid.identity()),
      lazy(::tools::pow2(this->height + 1), operator_monoid.identity()) {
      ::std::size_t node_id = this->capacity();
      for (; node_id < this->capacity() + n; ++node_id) {
        this->data[node_id] = map(t);
      }
      for (node_id = this->capacity() - 1; node_id > 0; --node_id) {
        this->data[node_id] = monoid.operation(this->data[(node_id << 1) | 0], this->data[(node_id << 1) | 1]);
      }
    }

    template <typename InputIter>
    lazy_segtree(
      const ::tools::monoid<T>& monoid,
      const ::tools::monoid<E>& operator_monoid,
      const ::std::function<T(T, E)>& act,
      const InputIter& begin,
      const InputIter& end,
      const ::std::function<T(typename InputIter::value_type)>& map
    ) :
      monoid(monoid),
      operator_monoid(operator_monoid),
      act(act),
      height(::tools::ceil_log2(::std::distance(begin, end))),
      data(::tools::pow2(this->height + 1), monoid.identity()),
      lazy(::tools::pow2(this->height + 1), operator_monoid.identity()) {
      ::std::size_t node_id = this->size();
      for (auto it = begin; it != end; ++it, ++node_id) {
        this->data[node_id] = map(*it);
      }
      for (node_id = this->capacity() - 1; node_id > 0; --node_id) {
        this->data[node_id] = monoid.operation(this->data[(node_id << 1) | 0], this->data[(node_id << 1) | 1]);
      }
    }

    // 区間作用クエリ。
    // aとbは半開区間。
    void update(const ::std::size_t a, const ::std::size_t b, const E& x) {
      if(a >= b) return;

      const ::std::size_t a_id = a + this->capacity();
      const ::std::size_t b_id = b + this->capacity() - 1;

      // リーフノードまで遅延伝搬を行う。
      // 作用素間の時系列が入れ替わらないよう、ここで古い作用素を一掃する。
      this->thrust(a_id);
      this->thrust(b_id);

      // クエリで与えられた区間をカバーできるノードに、作用素を置いていく。
      // ここで、作用素を置いたノードの先祖ノードは、今置いた作用素の効果が集約結果に反映されていない状態になってしまっている。
      for (::std::size_t l = a_id, r = b_id + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
          this->lazy[l] = this->operator_monoid.operation(this->lazy[l], x);
          ++l;
        }
        if (r & 1) {
          --r;
          this->lazy[r] = this->operator_monoid.operation(this->lazy[r], x);
        }
      }

      // そこで、作用素の効果を先祖ノードまで反映させる。
      this->recalc(a_id);
      this->recalc(b_id);
    }

    // 区間集約クエリ。
    // aとbは半開区間。
    T query(const ::std::size_t a, const ::std::size_t b) {
      if (a >= b) return this->monoid.identity();

      const ::std::size_t a_id = a + this->capacity();
      const ::std::size_t b_id = b + this->capacity() - 1;

      // リーフノードまで遅延伝搬を行う。
      this->thrust(a_id);
      this->thrust(b_id);

      // クエリで与えられた区間をカバーできるノードをかき集める。
      T vl = this->monoid.identity();
      T vr = this->monoid.identity();
      for (::std::size_t l = a_id, r = b_id + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
          vl = this->monoid.operation(vl, this->reflect(l));
          ++l;
        }
        if (r & 1) {
          --r;
          vr = this->monoid.operation(this->reflect(r), vr);
        }
      }
      return this->monoid.operation(vl, vr);
    }
  };
}

#endif
