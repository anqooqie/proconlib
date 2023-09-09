#ifndef TOOLS_RECTNAGLE_UNION_AREA_HPP
#define TOOLS_RECTNAGLE_UNION_AREA_HPP

#include <utility>
#include <limits>
#include <vector>
#include <tuple>
#include <cstddef>
#include <cassert>
#include "atcoder/lazysegtree.hpp"
#include "tools/compressor.hpp"

namespace tools {
  template <typename T>
  class rectangle_union_area {
  private:
    using S = ::std::pair<int, T>;
    static S op(const S& x, const S& y) {
      return x.first < y.first ? x : x.first > y.first ? y : S(x.first, x.second + y.second);
    }
    static S e() {
      return S(::std::numeric_limits<int>::max(), 0);
    }
    using F = int;
    static S mapping(const F& f, const S& x) {
      return S(f + x.first, x.second);
    }
    static F composition(const F& f, const F& g) {
      return f + g;
    }
    static F id() {
      return 0;
    }

    ::std::vector<::std::tuple<T, T, T, T>> m_rectangles;

  public:
    rectangle_union_area() = default;
    rectangle_union_area(const ::tools::rectangle_union_area<T>&) = default;
    rectangle_union_area(::tools::rectangle_union_area<T>&&) = default;
    ~rectangle_union_area() = default;
    ::tools::rectangle_union_area<T>& operator=(const ::tools::rectangle_union_area<T>&) = default;
    ::tools::rectangle_union_area<T>& operator=(::tools::rectangle_union_area<T>&&) = default;

    ::std::size_t size() const {
      return this->m_rectangle.size();
    }

    ::std::size_t add_rectangle(const T l, const T r, const T d, const T u) {
      assert(l < r);
      assert(d < u);
      this->m_rectangles.emplace_back(l, r, d, u);
      return this->m_rectangles.size() - 1;
    }

    const ::std::tuple<T, T, T, T>& get_rectangle(const ::std::size_t k) const {
      assert(k < this->m_rectangles.size());
      return this->m_rectangles[k];
    }

    const ::std::vector<::std::tuple<T, T, T, T>>& rectangles() const {
      return this->m_rectangles;
    }

    T query() const {
      ::std::vector<T> x_list, y_list;
      for (const auto& [l, r, d, u] : this->m_rectangles) {
        x_list.push_back(l);
        x_list.push_back(r);
        y_list.push_back(d);
        y_list.push_back(u);
      }
      ::tools::compressor<T> x_comp(x_list), y_comp(y_list);

      ::std::vector<::std::pair<::std::vector<::std::size_t>, ::std::vector<::std::size_t>>> sorted_rectangles(x_comp.size() + 1);
      for (::std::size_t i = 0; i < this->m_rectangles.size(); ++i) {
        const auto& [l, r, d, u] = this->m_rectangles[i];
        sorted_rectangles[x_comp.compress(l)].first.push_back(i);
        sorted_rectangles[x_comp.compress(r)].second.push_back(i);
      }

      ::std::vector<S> v;
      for (decltype(y_comp.size()) i = 0; i + 1 < y_comp.size(); ++i) {
        v.emplace_back(0, y_comp.decompress(i + 1) - y_comp.decompress(i));
      }
      ::atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> lazy_segtree(v);
      const T H = lazy_segtree.all_prod().second;

      T answer = 0;
      for (decltype(x_comp.size()) i = 0; i + 1 < x_comp.size(); ++i) {
        for (const auto k : sorted_rectangles[i].first) {
          const auto& [l, r, d, u] = this->m_rectangles[k];
          lazy_segtree.apply(y_comp.compress(d), y_comp.compress(u), 1);
        }
        for (const auto k : sorted_rectangles[i].second) {
          const auto& [l, r, d, u] = this->m_rectangles[k];
          lazy_segtree.apply(y_comp.compress(d), y_comp.compress(u), -1);
        }
        answer += (x_comp.decompress(i + 1) - x_comp.decompress(i)) * (H - (lazy_segtree.all_prod().first > 0 ? 0 : lazy_segtree.all_prod().second));
      }

      return answer;
    }
  };
}

#endif
