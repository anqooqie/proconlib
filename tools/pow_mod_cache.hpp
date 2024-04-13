#ifndef TOOLS_POW_MOD_CACHE_HPP
#define TOOLS_POW_MOD_CACHE_HPP

#include <vector>
#include <optional>
#include <utility>
#include <type_traits>
#include <cstddef>
#include <algorithm>
#include <cassert>
#include "tools/ssize.hpp"
#include "tools/find_cycle.hpp"
#include "tools/mod.hpp"
#include "tools/floor.hpp"
#include "tools/ceil.hpp"

namespace tools {

  template <class M>
  class pow_mod_cache {
    ::std::vector<M> m_pow;
    ::std::vector<M> m_cumsum;
    ::std::vector<M> m_inv_pow;
    ::std::vector<M> m_inv_cumsum;
    ::std::optional<::std::pair<long long, long long>> m_period;

  public:
    pow_mod_cache() = default;
    explicit pow_mod_cache(const M base) : m_pow({M(1), base}), m_cumsum({M::raw(0)}), m_inv_pow({M(1)}), m_inv_cumsum({M::raw(0)}) {
      if (base == M(-1)) {
        if (M::mod() > 2) {
          this->m_period = ::std::make_pair(0LL, 2LL);
        } else {
          this->m_period = ::std::make_pair(0LL, 1LL);
          this->m_pow.resize(1);
        }
        this->m_inv_pow.clear();
        this->m_inv_cumsum.clear();
      }
    }
    template <typename Z, ::std::enable_if_t<::std::is_integral_v<Z>, ::std::nullptr_t> = nullptr>
    explicit pow_mod_cache(const Z base) : pow_mod_cache(M(base)) {
    }

    M operator[](const long long n) {
      if (!this->m_period) {
        if (::std::max<long long>(::tools::ssize(this->m_pow) - 1, n) - ::std::min<long long>(n, -(::tools::ssize(this->m_inv_pow) - 1)) + 1 < M::mod() - 1) {
          if (n >= 0) {
            const long long size = ::tools::ssize(this->m_pow);
            this->m_pow.resize(::std::max(size, n + 1));
            for (long long i = size; i < ::tools::ssize(this->m_pow); ++i) {
              this->m_pow[i] = this->m_pow[i - 1] * this->m_pow[1];
            }
            return this->m_pow[n];
          } else {
            if (this->m_inv_pow.size() == 1) {
              this->m_inv_pow.push_back(this->m_pow[1].inv());
            }
            const long long size = ::tools::ssize(this->m_inv_pow);
            this->m_inv_pow.resize(::std::max(size, -n + 1));
            for (long long i = size; i < ::tools::ssize(this->m_inv_pow); ++i) {
              this->m_inv_pow[i] = this->m_inv_pow[i - 1] * this->m_inv_pow[1];
            }
            return this->m_inv_pow[-n];
          }
        }

        this->m_period = ::tools::find_cycle(this->m_pow[0], [&](const M& prev) { return prev * this->m_pow[1]; });
        const long long size = ::tools::ssize(this->m_pow);
        this->m_pow.resize(this->m_period->first + this->m_period->second);
        for (long long i = size; i < ::tools::ssize(this->m_pow); ++i) {
          this->m_pow[i] = this->m_pow[i - 1] * this->m_pow[1];
        }
        this->m_inv_pow.clear();
        this->m_inv_cumsum.clear();
      }

      if (this->m_period->first == 0) {
        return this->m_pow[::tools::mod(n, this->m_period->second)];
      } else {
        assert(n >= 0);
        if (n < this->m_period->first + this->m_period->second) {
          return this->m_pow[n];
        } else {
          return this->m_pow[(n - this->m_period->first) % this->m_period->second + this->m_period->first];
        }
      }
    }

    M sum(const long long l, const long long r) {
      if (l >= r) return M::raw(0);

      (*this)[r - 1];
      (*this)[l];

      {
        const long long size = ::tools::ssize(this->m_cumsum);
        this->m_cumsum.resize(this->m_pow.size() + 1);
        for (long long i = size; i < ::tools::ssize(this->m_cumsum); ++i) {
          this->m_cumsum[i] = this->m_cumsum[i - 1] + this->m_pow[i - 1];
        }
      }

      if (!this->m_period) {
        const long long size = ::tools::ssize(this->m_inv_cumsum);
        this->m_inv_cumsum.resize(this->m_inv_pow.size() + 1);
        for (long long i = size; i < ::tools::ssize(this->m_inv_cumsum); ++i) {
          this->m_inv_cumsum[i] = this->m_inv_cumsum[i - 1] + this->m_pow[i - 1];
        }

        if (l >= 0) {
          return this->m_cumsum[r] - this->m_cumsum[l];
        } else if (r <= 0) {
          return this->m_inv_cumsum[-l] - this->m_inv_cumsum[-r];
        } else {
          return (this->m_inv_cumsum[-l] - this->m_inv_cumsum[1]) + (this->m_cumsum[r] - this->m_cumsum[0]);
        }
      }

      static const auto cumsum = [&](const long long ll, const long long rr) {
        return this->m_cumsum[rr] - this->m_cumsum[ll];
      };

      if (l >= 0) {
        static const auto f = [&](const long long x) {
          if (x <= this->m_period->first + this->m_period->second) {
            return cumsum(0, x);
          } else {
            return cumsum(0, this->m_period->first) +
              cumsum(this->m_period->first, this->m_period->first + this->m_period->second) * ((x - this->m_period->first) / this->m_period->second) +
              cumsum(this->m_period->first, (x - this->m_period->first) % this->m_period->second + this->m_period->first);
          }
        };
        return f(r) - f(l);
      } else {
        const auto& n = this->m_period->second;
        return cumsum(::tools::mod(l, n), n) + cumsum(0, ::tools::mod(r, n)) + cumsum(0, n) * M(::tools::floor(r, n) - ::tools::ceil(l, n));
      }
    }
  };
}

#endif
