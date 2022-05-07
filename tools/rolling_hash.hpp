#ifndef TOOLS_ROLLING_HASH_HPP
#define TOOLS_ROLLING_HASH_HPP

#include <vector>
#include <cassert>
#include "tools/modint_for_rolling_hash.hpp"

namespace tools {
  class rolling_hash {
  private:
    using mint = ::tools::modint_for_rolling_hash;
    ::std::vector<mint> m_hash;

  public:
    rolling_hash() = default;
    rolling_hash(const ::tools::rolling_hash&) = default;
    rolling_hash(::tools::rolling_hash&&) = default;
    ~rolling_hash() = default;
    ::tools::rolling_hash& operator=(const ::tools::rolling_hash&) = default;
    ::tools::rolling_hash& operator=(::tools::rolling_hash&&) = default;

    template <typename InputIterator>
    rolling_hash(InputIterator begin, InputIterator end) {
      this->m_hash.push_back(mint::raw(0));
      for (auto it = begin; it != end; ++it) {
        this->m_hash.emplace_back(mint::mul(this->m_hash.back().val(), mint::base()) + *it);
      }
    }

    mint slice(const ::std::size_t l, const ::std::size_t r) const {
      assert(l <= r && r <= this->m_hash.size());
      return mint(this->m_hash[r].val() + mint::positivizer() - mint::mul(this->m_hash[l].val(), mint::pow_base(r - l)));
    }
  };
}

#endif
