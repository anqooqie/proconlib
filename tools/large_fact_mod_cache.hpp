#ifndef TOOLS_LARGE_FACT_MOD_CACHE_HPP
#define TOOLS_LARGE_FACT_MOD_CACHE_HPP

#include <vector>
#include <cassert>
#include <iterator>
#include <utility>
#include <algorithm>
#include "tools/is_prime.hpp"
#include "tools/pow_mod_cache.hpp"
#include "tools/ceil.hpp"
#include "tools/ceil_log2.hpp"
#include "tools/pow2.hpp"
#include "tools/sample_point_shift.hpp"

namespace tools {

  template <class M>
  class large_fact_mod_cache {
    int m_K;
    ::std::vector<M> m_factbs;

  public:
    large_fact_mod_cache() {
      const long long P = M::mod();
      assert(::tools::is_prime(P));
      ::tools::pow_mod_cache<M> pow2(2);

      long long K = 0;
      const long long Q = 200000;
      for (; ::tools::ceil(P * ::tools::ceil_log2(P), ::tools::pow2(K)) + Q * ::tools::pow2(K) > ::tools::ceil(P * ::tools::ceil_log2(P), ::tools::pow2(K + 1)) + Q * ::tools::pow2(K + 1); ++K);
      this->m_K = K;

      ::std::vector<M> f_im1{M(1)};
      ::std::vector<M> f_i;
      for (int i = 1; i <= K; ++i, f_i.swap(f_im1)) {
        ::tools::sample_point_shift(f_im1.begin(), f_im1.end(), pow2[i - 1], 3 * ::tools::pow2(i - 1), ::std::back_inserter(f_im1));
        f_i.resize(::tools::pow2(i));
        for (int j = 0; j < ::tools::pow2(i); ++j) {
          f_i[j] = f_im1[2 * j] * f_im1[2 * j + 1] * pow2[i - 1] * (M(2) * M(j) + M(1));
        }
      }

      this->m_factbs = ::std::move(f_im1);
      if (::tools::pow2(K) <= P / ::tools::pow2(K)) {
        ::tools::sample_point_shift(this->m_factbs.begin(), this->m_factbs.end(), pow2[K], P / ::tools::pow2(K) + 1 - ::tools::pow2(K), ::std::back_inserter(this->m_factbs));
      }
      this->m_factbs.insert(this->m_factbs.begin(), M(1));
      for (int i = 1; i < ::std::ssize(this->m_factbs); ++i) {
        this->m_factbs[i] *= this->m_factbs[i - 1] * pow2[K] * M(i);
      }
    }

    M fact(const long long nll) const {
      assert(nll >= 0);
      if (nll >= M::mod()) return M::raw(0);

      const auto n = static_cast<int>(nll);
      const auto prev = (n >> this->m_K) << this->m_K;
      const auto next = ((n >> this->m_K) + 1) << this->m_K;
      if (n - prev <= ::std::min(next, M::mod() - 1) - n) {
        auto res = this->m_factbs[prev >> this->m_K];
        int i;
        for (M m(i = prev + 1); i <= n; ++i, ++m) {
          res *= m;
        }
        return res;
      } else {
        if (next <= M::mod() - 1) {
          auto res = this->m_factbs[next >> this->m_K].inv();
          int i;
          for (M m(i = n + 1); i <= next; ++i, ++m) {
            res *= m;
          }
          return res.inv();
        } else {
          M res(-1);
          int i;
          for (M m(i = n + 1); i < M::mod(); ++i, ++m) {
            res *= m;
          }
          return res.inv();
        }
      }
    }

    M binomial(long long n, long long r) const {
      if (r < 0) return M::raw(0);
      if (0 <= n && n < r) return M::raw(0);
      if (n < 0) return M(1 - ((r & 1) << 1)) * this->binomial(-n + r - 1, r);

      const auto c = [&](const long long nn, const long long rr) {
        return 0 <= rr && rr <= nn ? this->fact(nn) / (this->fact(nn - rr) * this->fact(rr)) : M::raw(0);
      };

      M result(1);
      while (n > 0 || r > 0) {
        result *= c(n % M::mod(), r % M::mod());
        n /= M::mod();
        r /= M::mod();
      }

      return result;
    }
    M combination(const long long n, const long long r) const {
      if (!(0 <= r && r <= n)) return M::raw(0);
      return this->binomial(n, r);
    }
    M permutation(const long long n, const long long r) const {
      if (!(0 <= r && r <= n)) return M::raw(0);
      return this->binomial(n, r) * this->fact(r);
    }
    M combination_with_repetition(const long long n, const long long r) const {
      if (n < 0 || r < 0) return M::raw(0);
      return this->binomial(n + r - 1, r);
    }
  };
}

#endif
