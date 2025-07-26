#ifndef TOOLS_ONLINE_CUMSUM_HPP
#define TOOLS_ONLINE_CUMSUM_HPP

#include <algorithm>
#include <cassert>
#include <iostream>
#include <type_traits>
#include <vector>
#include "tools/group.hpp"
#include "tools/is_monoid.hpp"
#include "tools/is_group.hpp"

namespace tools {
  template <typename X, bool Forward = true>
  class online_cumsum {
    using M = ::std::conditional_t<::tools::is_monoid_v<X>, X, ::tools::group::plus<X>>;
    using T = typename M::T;
    ::std::vector<T> m_vector;
    ::std::vector<T> m_cumsum;
    int m_processed;

  public:
    online_cumsum() : online_cumsum(0) {
    }
    online_cumsum(const int n) : m_vector(n, M::e()), m_cumsum(n + 1, M::e()), m_processed(Forward ? 0 : n) {
    }

    int size() const {
      return this->m_vector.size();
    }
    T& operator[](const int i) {
      assert(0 <= i && i < this->size());
      return this->m_vector[i];
    }

    auto begin() { return this->m_vector.begin(); }
    auto begin() const { return this->m_vector.begin(); }
    auto cbegin() const { return this->m_vector.cbegin(); }
    auto end() { return this->m_vector.end(); }
    auto end() const { return this->m_vector.end(); }
    auto cend() const { return this->m_vector.cend(); }
    auto rbegin() { return this->m_vector.rbegin(); }
    auto rbegin() const { return this->m_vector.rbegin(); }
    auto crbegin() const { return this->m_vector.crbegin(); }
    auto rend() { return this->m_vector.rend(); }
    auto rend() const { return this->m_vector.rend(); }
    auto crend() const { return this->m_vector.crend(); }

    T prod(const int l, const int r) {
      assert(0 <= l && l <= r && r <= this->size());
      if constexpr (Forward) {
        for (; this->m_processed < r; ++this->m_processed) {
          this->m_cumsum[this->m_processed + 1] = M::op(this->m_cumsum[this->m_processed], this->m_vector[this->m_processed]);
        }
        if constexpr (::tools::is_group_v<M>) {
          return M::op(M::inv(this->m_cumsum[l]), this->m_cumsum[r]);
        } else {
          assert(l == 0);
          return this->m_cumsum[r];
        }
      } else {
        for (; this->m_processed > l; --this->m_processed) {
          this->m_cumsum[this->m_processed - 1] = M::op(this->m_vector[this->m_processed - 1], this->m_cumsum[this->m_processed]);
        }
        if constexpr (::tools::is_group_v<M>) {
          return M::op(this->m_cumsum[l], M::inv(this->m_cumsum[r]));
        } else {
          assert(r == this->size());
          return this->m_cumsum[l];
        }
      }
    }
    template <typename Y = X> requires (!::tools::is_monoid_v<Y>)
    T sum(const int l, const int r) {
      return this->prod(l, r);
    }

    friend ::std::istream& operator>>(::std::istream& is, ::tools::online_cumsum<X, Forward>& self) {
      if constexpr (Forward) {
        ::std::fill(self.m_cumsum.begin(), self.m_cumsum.begin() + self.m_processed, M::e());
        self.m_processed = 0;
      } else {
        ::std::fill(self.m_cumsum.begin() + self.m_processed, self.m_cumsum.end(), M::e());
        self.m_processed = self.size();
      }
      for (auto it = self.begin(); it != self.end(); ++it) {
        is >> *it;
      }
      return is;
    }
  };
}

#endif
