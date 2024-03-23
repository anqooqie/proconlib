#ifndef TOOLS_ONLINE_CUMSUM_HPP
#define TOOLS_ONLINE_CUMSUM_HPP

#include <type_traits>
#include <vector>
#include <cstddef>
#include <cassert>
#include "tools/is_group.hpp"
#include "tools/group.hpp"

namespace tools {
  template <typename GT, bool Forward = true>
  class online_cumsum {
    using G = ::std::conditional_t<::tools::is_group_v<GT>, GT, ::tools::group::plus<GT>>;
    using T = typename G::T;
    ::std::vector<T> m_vector;
    ::std::vector<T> m_cumsum;
    ::std::size_t m_processed;

  public:
    online_cumsum() : online_cumsum(0) {
    }
    online_cumsum(const ::std::size_t n) : m_vector(n, G::e()), m_cumsum(n + 1, G::e()), m_processed(Forward ? 0 : n) {
    }

    ::std::size_t size() const {
      return this->m_vector.size();
    }
    T& operator[](const ::std::size_t i) {
      return this->m_vector[i];
    }
    T sum(const ::std::size_t l, const ::std::size_t r) {
      assert(l <= r && r <= this->size());
      if constexpr (Forward) {
        for (; this->m_processed < r; ++this->m_processed) {
          this->m_cumsum[this->m_processed + 1] = G::op(this->m_cumsum[this->m_processed], this->m_vector[this->m_processed]);
        }
        return G::op(G::inv(this->m_cumsum[l]), this->m_cumsum[r]);
      } else {
        for (; this->m_processed > l; --this->m_processed) {
          this->m_cumsum[this->m_processed - 1] = G::op(this->m_vector[this->m_processed - 1], this->m_cumsum[this->m_processed]);
        }
        return G::op(this->m_cumsum[l], G::inv(this->m_cumsum[r]));
      }
    }
  };
}

#endif
