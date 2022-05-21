#ifndef TOOLS_FACT_MOD_CACHE_HPP
#define TOOLS_FACT_MOD_CACHE_HPP

#include <vector>
#include <cstdint>
#include <cassert>
#include <algorithm>
#include <cmath>
#include "tools/is_prime.hpp"
#include "tools/ssize.hpp"
#include "tools/signum.hpp"

namespace tools {

  template <class M>
  class fact_mod_cache {
  private:
    using i64 = ::std::int_fast64_t;
    ::std::vector<M> m_inv;
    ::std::vector<M> m_fact;
    ::std::vector<M> m_fact_inv;

  public:
    fact_mod_cache() : m_inv({M::raw(0), M::raw(1)}), m_fact({M::raw(1), M::raw(1)}), m_fact_inv({M::raw(1), M::raw(1)}) {
      assert(::tools::is_prime(M::mod()));
    }
    fact_mod_cache(const ::tools::fact_mod_cache<M>&) = default;
    fact_mod_cache(::tools::fact_mod_cache<M>&&) = default;
    ~fact_mod_cache() = default;
    ::tools::fact_mod_cache<M>& operator=(const ::tools::fact_mod_cache<M>&) = default;
    ::tools::fact_mod_cache<M>& operator=(::tools::fact_mod_cache<M>&&) = default;

    M inv(const i64 n) {
      assert(n % M::mod() != 0);
      const i64 size = ::tools::ssize(this->m_inv);
      this->m_inv.resize(::std::clamp<i64>(::std::abs(n) + 1, size, M::mod()));
      for (i64 i = size; i < ::tools::ssize(this->m_inv); ++i) {
        this->m_inv[i] = -this->m_inv[M::mod() % i] * M::raw(M::mod() / i);
      }
      return ::tools::signum(n) * this->m_inv[::std::abs(n) % M::mod()];
    }
    M fact(const i64 n) {
      assert(n >= 0);
      const i64 size = ::tools::ssize(this->m_fact);
      this->m_fact.resize(::std::clamp<i64>(n + 1, size, M::mod()));
      for (i64 i = size; i < ::tools::ssize(this->m_fact); ++i) {
        this->m_fact[i] = this->m_fact[i - 1] * M::raw(i);
      }
      return n < M::mod() ? this->m_fact[n] : M::raw(0);
    }
    M fact_inv(const i64 n) {
      assert(0 <= n && n < M::mod());
      const i64 size = ::tools::ssize(this->m_fact_inv);
      this->m_fact_inv.resize(::std::max<i64>(size, n + 1));
      this->inv(this->m_fact_inv.size() - 1);
      for (i64 i = size; i < ::tools::ssize(this->m_fact_inv); ++i) {
        this->m_fact_inv[i] = this->m_fact_inv[i - 1] * this->m_inv[i];
      }
      return this->m_fact_inv[n];
    }

    explicit fact_mod_cache(const i64 max) : fact_mod_cache() {
      this->fact(::std::min<i64>(max, M::mod() - 1));
      this->fact_inv(::std::min<i64>(max, M::mod() - 1));
    }

    M combination(i64 n, i64 r) {
      if (!(0 <= r && r <= n)) return M::raw(0);

      this->fact(::std::min<i64>(n, M::mod() - 1));
      this->fact_inv(::std::min<i64>(n, M::mod() - 1));
      const auto c = [&](const i64 nn, const i64 rr) {
        return 0 <= rr && rr <= nn ? this->m_fact[nn] * this->m_fact_inv[nn - rr] * this->m_fact_inv[rr] : M::raw(0);
      };

      M answer(1);
      while (n > 0 || r > 0) {
        answer *= c(n % M::mod(), r % M::mod());
        n /= M::mod();
        r /= M::mod();
      }

      return answer;
    }
    M permutation(const i64 n, const i64 r) {
      if (!(0 <= r && r <= n)) return M::raw(0);
      return this->combination(n, r) * this->fact(r);
    }
  };
}

#endif
