#ifndef TOOLS_FACT_MOD_CACHE_HPP
#define TOOLS_FACT_MOD_CACHE_HPP

#include <vector>
#include <cassert>
#include <algorithm>
#include <cmath>
#include "tools/is_prime.hpp"
#include "tools/ssize.hpp"

namespace tools {

  template <class M>
  class fact_mod_cache {
    ::std::vector<M> m_inv;
    ::std::vector<M> m_fact;
    ::std::vector<M> m_fact_inv;

  public:
    fact_mod_cache() : m_inv({M::raw(0), M::raw(1)}), m_fact({M::raw(1), M::raw(1)}), m_fact_inv({M::raw(1), M::raw(1)}) {
      assert(::tools::is_prime(M::mod()));
    }
    explicit fact_mod_cache(const long long max) : fact_mod_cache() {
      this->fact(::std::min<long long>(max, M::mod() - 1));
      this->fact_inv(::std::min<long long>(max, M::mod() - 1));
    }

    M inv(const long long n) {
      assert(n % M::mod() != 0);
      const long long size = ::tools::ssize(this->m_inv);
      this->m_inv.resize(::std::clamp<long long>(::std::abs(n) + 1, size, M::mod()));
      for (long long i = size; i < ::tools::ssize(this->m_inv); ++i) {
        this->m_inv[i] = -this->m_inv[M::mod() % i] * M::raw(M::mod() / i);
      }
      M result = this->m_inv[::std::abs(n) % M::mod()];
      if (n < 0) result = -result;
      return result;
    }
    M fact(const long long n) {
      assert(n >= 0);
      const long long size = ::tools::ssize(this->m_fact);
      this->m_fact.resize(::std::clamp<long long>(n + 1, size, M::mod()));
      for (long long i = size; i < ::tools::ssize(this->m_fact); ++i) {
        this->m_fact[i] = this->m_fact[i - 1] * M::raw(i);
      }
      return n < M::mod() ? this->m_fact[n] : M::raw(0);
    }
    M fact_inv(const long long n) {
      assert(0 <= n && n < M::mod());
      const long long size = ::tools::ssize(this->m_fact_inv);
      this->m_fact_inv.resize(::std::max<long long>(size, n + 1));
      this->inv(this->m_fact_inv.size() - 1);
      for (long long i = size; i < ::tools::ssize(this->m_fact_inv); ++i) {
        this->m_fact_inv[i] = this->m_fact_inv[i - 1] * this->m_inv[i];
      }
      return this->m_fact_inv[n];
    }

    M binomial(long long n, long long r) {
      if (r < 0) return M::raw(0);
      if (0 <= n && n < r) return M::raw(0);
      if (n < 0) return M(1 - ((r & 1) << 1)) * this->binomial(-n + r - 1, r);

      this->fact(::std::min<long long>(n, M::mod() - 1));
      this->fact_inv(::std::min<long long>(n, M::mod() - 1));
      const auto c = [&](const long long nn, const long long rr) {
        return 0 <= rr && rr <= nn ? this->m_fact[nn] * this->m_fact_inv[nn - rr] * this->m_fact_inv[rr] : M::raw(0);
      };

      M result(1);
      while (n > 0 || r > 0) {
        result *= c(n % M::mod(), r % M::mod());
        n /= M::mod();
        r /= M::mod();
      }

      return result;
    }
    M combination(const long long n, const long long r) {
      if (!(0 <= r && r <= n)) return M::raw(0);
      return this->binomial(n, r);
    }
    M permutation(const long long n, const long long r) {
      if (!(0 <= r && r <= n)) return M::raw(0);
      return this->binomial(n, r) * this->fact(r);
    }
    M combination_with_repetition(const long long n, const long long r) {
      if (n < 0 || r < 0) return M::raw(0);
      return this->binomial(n + r - 1, r);
    }
  };
}

#endif
