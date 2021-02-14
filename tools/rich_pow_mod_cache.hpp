#ifndef TOOLS_RICH_POW_MOD_CACHE_HPP
#define TOOLS_RICH_POW_MOD_CACHE_HPP

#include <cstdint>
#include <vector>
#include <numeric>
#include <cassert>
#include <iterator>
#include "tools/find_cycle.hpp"
#include "tools/mod.hpp"

namespace tools {

  /**
   * b^n mod m, but provides a rich interface by using the pigeonhole principle
   * License: CC0
   *
   * Usage:
   * ```
   * // calculates 10^n (mod 3), for every n
   * tools::rich_pow_mod_cache<atcoder::static_modint<3>> cache(10);
   *
   * // obtains 10^123456789 (mod 3), that is 1
   * cache[123456789];
   *
   * // obtains 10^10000 + 10^10001 + 10^10002 (mod 3), that is 0
   * cache.sum(10000, 10003);
   * ```
   *
   * @author anqooqie
   * @param <M> `atcoder::modint`
   */
  template <class M>
  class rich_pow_mod_cache {
  private:
    bool m_exists_inv;
    ::std::int_fast64_t m_head;
    ::std::int_fast64_t m_cycle;
    ::std::vector<M> m_data;
    ::std::vector<M> m_cumsum;

    M cumsum(const ::std::int_fast64_t l, const ::std::int_fast64_t r) const {
      return this->m_cumsum[r] - this->m_cumsum[l];
    }

  public:
    rich_pow_mod_cache() = default;
    rich_pow_mod_cache(const rich_pow_mod_cache&) = default;
    rich_pow_mod_cache(rich_pow_mod_cache&&) = default;
    ~rich_pow_mod_cache() = default;
    rich_pow_mod_cache& operator=(const rich_pow_mod_cache&) = default;
    rich_pow_mod_cache& operator=(rich_pow_mod_cache&&) = default;

    explicit rich_pow_mod_cache(const M& base) :
      m_exists_inv(::std::gcd(base.val(), M::mod()) == 1) {

      const auto [head, cycle] = ::tools::find_cycle(M(1), [&base](const M& prev) { return prev * base; });
      this->m_head = head;
      this->m_cycle = cycle;

      // if modular multiplicative inverses exist, head must be 0 according to Carmichael's theorem
      assert(!this->m_exists_inv || this->m_head == 0);

      this->m_data.reserve(head + cycle);
      this->m_data.emplace_back(1);
      for (::std::int_fast64_t i = 1; i < head + cycle; ++i) {
        this->m_data.push_back(this->m_data.back() * base);
      }
      this->m_cumsum.reserve(head + cycle + 1);
      this->m_cumsum.emplace_back(0);
      ::std::partial_sum(this->m_data.begin(), this->m_data.end(), ::std::back_inserter(this->m_cumsum));
    }

    explicit rich_pow_mod_cache(const ::std::int_fast64_t base) :
      rich_pow_mod_cache(M(base)) {
    }

    M operator[](const ::std::int_fast64_t i) const {
      if (i >= 0) {
        if (i < this->m_head + this->m_cycle) {
          return this->m_data[i];
        } else {
          return this->m_data[(i - this->m_head) % this->m_cycle + this->m_head];
        }
      } else {
        assert(this->m_exists_inv);
        return this->m_data[::tools::mod(i, this->m_cycle)];
      }
    }

    M sum(const ::std::int_fast64_t l, const ::std::int_fast64_t r) const {
      if (l <= r) {
        if (l >= 0) {
          static const auto f = [&](const ::std::int_fast64_t x) {
            if (x <= this->m_head + this->m_cycle) {
              return this->cumsum(0, x);
            } else {
              return this->cumsum(0, this->m_head) +
                this->cumsum(this->m_head, this->m_head + this->m_cycle) * ((x - this->m_head) / this->m_cycle) +
                this->cumsum(this->m_head, (x - this->m_head) % this->m_cycle + this->m_head);
            }
          };
          return f(r) - f(l);
        } else {
          assert(this->m_exists_inv);
          return (this->cumsum(0, this->m_cycle) * ((r - l) / this->m_cycle) + this->cumsum(0, (r - l) % this->m_cycle)) * (*this)[l];
        }
      } else {
        return M(0);
      }
    }
  };
}

#endif
