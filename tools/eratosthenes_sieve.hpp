#ifndef TOOLS_ERATOSTHENES_SIEVE_HPP
#define TOOLS_ERATOSTHENES_SIEVE_HPP

#include <cassert>
#include "tools/non_bool_integral.hpp"
#include "tools/simpler_segmented_sieve.hpp"

namespace tools {
  template <tools::non_bool_integral T>
  class eratosthenes_sieve {
    tools::detail::simpler_segmented_sieve::impl<T> m_impl;

    T n() const {
      return this->m_impl.r();
    }

  public:
    using prime_view = typename tools::detail::simpler_segmented_sieve::impl<T>::large_prime_view;

    eratosthenes_sieve() = default;
    explicit eratosthenes_sieve(const T n) : m_impl(1, n) {
      assert(n >= 1);
    }

    bool is_prime(const T i) const {
      assert(1 <= i && i <= this->n());
      return this->m_impl.is_prime(i);
    }

    prime_view prime_range(const T l, const T r) const {
      assert(1 <= l && l <= r && r <= this->n());
      return this->m_impl.large_prime_range(l, r);
    }
  };
}

#endif
