#ifndef TOOLS_POW_MOD_CACHE_HPP
#define TOOLS_POW_MOD_CACHE_HPP

#include <vector>
#include <optional>
#include <utility>
#include <cstdint>
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
  private:
    ::std::vector<M> m_pow;
    ::std::vector<M> m_cumsum;
    ::std::vector<M> m_inv_pow;
    ::std::vector<M> m_inv_cumsum;
    ::std::optional<::std::pair<::std::int_fast64_t, ::std::int_fast64_t>> m_period;

  public:
    pow_mod_cache() = default;
    pow_mod_cache(const ::tools::pow_mod_cache<M>&) = default;
    pow_mod_cache(::tools::pow_mod_cache<M>&&) = default;
    ~pow_mod_cache() = default;
    ::tools::pow_mod_cache<M>& operator=(const ::tools::pow_mod_cache<M>&) = default;
    ::tools::pow_mod_cache<M>& operator=(::tools::pow_mod_cache<M>&&) = default;

    M operator[](const ::std::int_fast64_t n) {
      if (!this->m_period) {
        if (::std::max<::std::int_fast64_t>(::tools::ssize(this->m_pow) - 1, n) - ::std::min<::std::int_fast64_t>(n, -(::tools::ssize(this->m_inv_pow) - 1)) + 1 < M::mod() - 1) {
          if (n >= 0) {
            const ::std::int_fast64_t size = ::tools::ssize(this->m_pow);
            this->m_pow.resize(::std::max(size, n + 1));
            for (::std::int_fast64_t i = size; i < ::tools::ssize(this->m_pow); ++i) {
              this->m_pow[i] = this->m_pow[i - 1] * this->m_pow[1];
            }
            return this->m_pow[n];
          } else {
            if (this->m_inv_pow.size() == 1) {
              this->m_inv_pow.push_back(this->m_pow[1].inv());
            }
            const ::std::int_fast64_t size = ::tools::ssize(this->m_inv_pow);
            this->m_inv_pow.resize(::std::max(size, -n + 1));
            for (::std::int_fast64_t i = size; i < ::tools::ssize(this->m_inv_pow); ++i) {
              this->m_inv_pow[i] = this->m_inv_pow[i - 1] * this->m_inv_pow[1];
            }
            return this->m_inv_pow[-n];
          }
        }

        this->m_period = ::std::make_optional(::tools::find_cycle(this->m_pow[0], [&](const M& prev) { return prev * this->m_pow[1]; }));
        const ::std::int_fast64_t size = ::tools::ssize(this->m_pow);
        this->m_pow.resize(this->m_period->first + this->m_period->second);
        for (::std::int_fast64_t i = size; i < ::tools::ssize(this->m_pow); ++i) {
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

    M sum(const ::std::int_fast64_t l, const ::std::int_fast64_t r) {
      if (l >= r) return M::raw(0);

      (*this)[r - 1];
      (*this)[l];

      {
        const ::std::int_fast64_t size = ::tools::ssize(this->m_cumsum);
        this->m_cumsum.resize(this->m_pow.size() + 1);
        for (::std::int_fast64_t i = size; i < ::tools::ssize(this->m_cumsum); ++i) {
          this->m_cumsum[i] = this->m_cumsum[i - 1] + this->m_pow[i - 1];
        }
      }

      if (!this->m_period) {
        const ::std::int_fast64_t size = ::tools::ssize(this->m_inv_cumsum);
        this->m_inv_cumsum.resize(this->m_inv_pow.size() + 1);
        for (::std::int_fast64_t i = size; i < ::tools::ssize(this->m_inv_cumsum); ++i) {
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

      static const auto cumsum = [&](const ::std::int_fast64_t ll, const ::std::int_fast64_t rr) {
        return this->m_cumsum[rr] - this->m_cumsum[ll];
      };

      if (l >= 0) {
        static const auto f = [&](const ::std::int_fast64_t x) {
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

    explicit pow_mod_cache(const M& base) : m_pow({M(1), base}), m_cumsum({M(0)}), m_inv_pow({M(1)}), m_inv_cumsum({M(0)}) {
    }
    explicit pow_mod_cache(const ::std::int_fast64_t base) : pow_mod_cache(M(base)) {
    }
  };
}

#endif
