#ifndef TOOLS_RECTNAGLE_UNION_AREA_HPP
#define TOOLS_RECTNAGLE_UNION_AREA_HPP

#include <cassert>
#include <limits>
#include <tuple>
#include <utility>
#include <vector>
#include "atcoder/lazysegtree.hpp"
#include "tools/compressor.hpp"

namespace tools {
  template <typename T>
  class rectangle_union_area {
    using S = std::pair<int, T>;
    static S op(const S& x, const S& y) {
      return x.first < y.first ? x : x.first > y.first ? y : S(x.first, x.second + y.second);
    }
    static S e() {
      return S(std::numeric_limits<int>::max(), 0);
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

    std::vector<std::tuple<T, T, T, T>> m_rectangles;

  public:
    rectangle_union_area() = default;

    int size() const {
      return this->m_rectangles.size();
    }

    int add_rectangle(const T l, const T r, const T d, const T u) {
      assert(l < r);
      assert(d < u);
      this->m_rectangles.emplace_back(l, r, d, u);
      return this->m_rectangles.size() - 1;
    }

    template <typename Self>
    decltype(auto) get_rectangle(this Self&& self, const int k) {
      assert(0 <= k && k < self.m_rectangles.size());
      if constexpr (std::is_lvalue_reference_v<Self&&>) {
        return static_cast<const std::tuple<T, T, T, T>&>(self.m_rectangles[k]);
      } else {
        return std::tuple<T, T, T, T>(std::forward_like<Self>(self.m_rectangles[k]));
      }
    }

    template <typename Self>
    decltype(auto) rectangles(this Self&& self) {
      if constexpr (std::is_lvalue_reference_v<Self&&>) {
        return static_cast<const std::vector<std::tuple<T, T, T, T>>&>(self.m_rectangles);
      } else {
        return std::vector<std::tuple<T, T, T, T>>(std::forward_like<Self>(self.m_rectangles));
      }
    }

    T query() const {
      std::vector<T> x_list, y_list;
      for (const auto& [l, r, d, u] : this->m_rectangles) {
        x_list.push_back(l);
        x_list.push_back(r);
        y_list.push_back(d);
        y_list.push_back(u);
      }
      tools::compressor<T> x_comp(x_list), y_comp(y_list);

      std::vector<std::pair<std::vector<int>, std::vector<int>>> sorted_rectangles(x_comp.size() + 1);
      for (int i = 0; i < this->size(); ++i) {
        const auto& [l, r, d, u] = this->m_rectangles[i];
        sorted_rectangles[x_comp.compress(l)].first.push_back(i);
        sorted_rectangles[x_comp.compress(r)].second.push_back(i);
      }

      std::vector<S> v;
      for (decltype(y_comp.size()) i = 0; i + 1 < y_comp.size(); ++i) {
        v.emplace_back(0, y_comp.decompress(i + 1) - y_comp.decompress(i));
      }
      atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> lazy_segtree(v);
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
