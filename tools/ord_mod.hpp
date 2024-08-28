#ifndef TOOLS_ORD_MOD_HPP
#define TOOLS_ORD_MOD_HPP

#include <vector>
#include <cassert>
#include <cstddef>
#include "tools/is_prime.hpp"
#include "tools/prime_factorization.hpp"
#include "tools/pow.hpp"
#include "tools/fix.hpp"
#include "tools/pow_mod.hpp"

namespace tools {
  template <typename T>
  class ord_mod {
  private:
    T m_P;
    ::std::vector<T> m_p;
    ::std::vector<T> m_e;
    ::std::vector<::std::vector<T>> m_E;

    ::std::size_t n() const {
      return this->m_p.size();
    }

  public:
    ord_mod() = default;
    ord_mod(const T P) : m_P(P) {
      assert(::tools::is_prime(P));

      const auto factors = ::tools::prime_factorization(P - 1);
      for (::std::size_t l = 0, r = 0; l < factors.size(); l = r) {
        for (; r < factors.size() && factors[l] == factors[r]; ++r);
        this->m_p.push_back(factors[l]);
        this->m_e.push_back(r - l);
      }

      this->m_E.resize(this->n() + 1);
      for (::std::size_t l = 0; l <= this->n(); ++l) {
        this->m_E[l].resize(this->n() + 1);
        this->m_E[l][l] = 1;
      }
      for (::std::size_t l = 0; l + 1 <= this->n(); ++l) {
        this->m_E[l][l + 1] = ::tools::pow(this->m_p[l], this->m_e[l]);
      }
      for (::std::size_t l = 0; l + 2 <= this->n(); ++l) {
        for (::std::size_t r = l + 2; r <= this->n(); ++r) {
          this->m_E[l][r] = this->m_E[l][r - 1] * this->m_E[r - 1][r];
        }
      }
    }

    T query(const T x) const {
      assert(1 <= x && x < this->m_P);

      T m = 1;
      ::tools::fix([&](auto&& dfs, const ::std::size_t l, const ::std::size_t r, const T Xbar_l_r) -> void {
        switch (r - l) {
        case 0:
          return;
        case 1:
          {
            ::std::size_t f_l;
            T v;
            for (f_l = 0, v = Xbar_l_r; v != 1; ++f_l, v = ::tools::pow_mod(v, this->m_p[l], this->m_P));
            m *= ::tools::pow(this->m_p[l], f_l);
          }
          return;
        default:
          {
            const auto m = (l + r) / 2;
            dfs(l, m, ::tools::pow_mod(Xbar_l_r, this->m_E[m][r], this->m_P));
            dfs(m, r, ::tools::pow_mod(Xbar_l_r, this->m_E[l][m], this->m_P));
          }
          return;
        }
      })(0, this->n(), x);

      return m;
    }
  };
}

#endif
