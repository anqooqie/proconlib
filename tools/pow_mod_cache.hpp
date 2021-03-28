#ifndef TOOLS_POW_MOD_CACHE_HPP
#define TOOLS_POW_MOD_CACHE_HPP

#include <vector>
#include <cstdint>

namespace tools {

  template <class M>
  class pow_mod_cache {
  private:
    ::std::vector<M> m_data;

  public:
    pow_mod_cache() = default;
    pow_mod_cache(const pow_mod_cache&) = default;
    pow_mod_cache(pow_mod_cache&&) = default;
    ~pow_mod_cache() = default;
    pow_mod_cache& operator=(const pow_mod_cache&) = default;
    pow_mod_cache& operator=(pow_mod_cache&&) = default;

    pow_mod_cache(const M& base, const ::std::int_fast64_t max) :
      m_data(max + 1) {
      this->m_data[0] = M(1);
      for (::std::int_fast64_t i = 1; i <= max; ++i) {
        this->m_data[i] = this->m_data[i - 1] * base;
      }
    }

    pow_mod_cache(const ::std::int_fast64_t base, const ::std::int_fast64_t max) :
      pow_mod_cache(M(base), max) {
    }

    M operator[](const ::std::int_fast64_t i) const {
      return this->m_data[i];
    }
  };
}

#endif
