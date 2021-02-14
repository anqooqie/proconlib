#ifndef TOOLS_FACT_MOD_CACHE_HPP
#define TOOLS_FACT_MOD_CACHE_HPP

#include <vector>
#include <cstdint>
#include <cassert>

namespace tools {

  /**
   * factorial mod
   * License: CC0
   *
   * Usage:
   * ```
   * // calculates n! (mod 3) for 0 <= n <= 5
   * tools::fact_mod_cache<atcoder::static_modint<3>> cache(5);
   *
   * // obtains 5! (mod 3), that is 0
   * cache.fact(5);
   * ```
   *
   * @author anqooqie
   * @param <M> `atcoder::modint`
   */
  template <class M>
  class fact_mod_cache {
  private:
    ::std::vector<M> m_data;
    ::std::vector<M> m_inv_data;

  public:
    fact_mod_cache() = default;
    fact_mod_cache(const fact_mod_cache&) = default;
    fact_mod_cache(fact_mod_cache&&) = default;
    ~fact_mod_cache() = default;
    fact_mod_cache& operator=(const fact_mod_cache&) = default;
    fact_mod_cache& operator=(fact_mod_cache&&) = default;

    fact_mod_cache(const ::std::int_fast64_t max) :
      m_data(max + 1),
      m_inv_data(max + 1) {
      assert(max < M::mod());
      this->m_data[0] = M(1);
      for (::std::int_fast64_t i = 1; i <= max; ++i) {
        this->m_data[i] = this->m_data[i - 1] * M(i);
      }
      this->m_inv_data[max] = this->m_data[max].inv();
      for (::std::int_fast64_t i = max - 1; i >= 0; --i) {
        this->m_inv_data[i] = this->m_inv_data[i + 1] * M(i + 1);
      }
    }

    M fact(const ::std::int_fast64_t i) const {
      return this->m_data[i];
    }

    M inv_fact(const ::std::int_fast64_t i) const {
      return this->m_inv_data[i];
    }

    M permutation(const ::std::int_fast64_t n, const ::std::int_fast64_t r) const {
      return 0 <= r && r <= n ? this->m_data[n] * this->m_inv_data[n - r] : M(0);
    }

    M combination(const ::std::int_fast64_t n, const ::std::int_fast64_t r) const {
      return 0 <= r && r <= n ? this->m_data[n] * this->m_inv_data[n - r] * this->m_inv_data[r] : M(0);
    }
  };
}

#endif
