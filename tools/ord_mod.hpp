#ifndef TOOLS_ORD_MOD_HPP
#define TOOLS_ORD_MOD_HPP

#include <vector>
#include <cassert>
#include <cstddef>
#include <map>
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
    std::vector<T> m_p;
    std::vector<T> m_e;
    std::vector<std::vector<T>> m_E;

    std::size_t n() const {
      return this->m_p.size();
    }

  public:
    ord_mod() = default;
    ord_mod(const T P) : m_P(P) {
      assert(tools::is_prime(P));

      const auto factors = tools::prime_factorization(P - 1);
      for (std::size_t l = 0, r = 0; l < factors.size(); l = r) {
        for (; r < factors.size() && factors[l] == factors[r]; ++r);
        this->m_p.push_back(factors[l]);
        this->m_e.push_back(r - l);
      }

      this->m_E.resize(this->n() + 1);
      for (std::size_t l = 0; l <= this->n(); ++l) {
        this->m_E[l].resize(this->n() + 1);
        this->m_E[l][l] = 1;
      }
      for (std::size_t l = 0; l + 1 <= this->n(); ++l) {
        this->m_E[l][l + 1] = tools::pow(this->m_p[l], this->m_e[l]);
      }
      for (std::size_t l = 0; l + 2 <= this->n(); ++l) {
        for (std::size_t r = l + 2; r <= this->n(); ++r) {
          this->m_E[l][r] = this->m_E[l][r - 1] * this->m_E[r - 1][r];
        }
      }
    }

    T query(const T x) const {
      assert(1 <= x && x < this->m_P);

      T m = 1;
      tools::fix([&](auto&& dfs, const std::size_t l, const std::size_t r, const T Xbar_l_r) -> void {
        switch (r - l) {
        case 0:
          return;
        case 1:
          {
            std::size_t f_l;
            T v;
            for (f_l = 0, v = Xbar_l_r; v != 1; ++f_l, v = tools::pow_mod(v, this->m_p[l], this->m_P));
            m *= tools::pow(this->m_p[l], f_l);
          }
          return;
        default:
          {
            const auto m = (l + r) / 2;
            dfs(l, m, tools::pow_mod(Xbar_l_r, this->m_E[m][r], this->m_P));
            dfs(m, r, tools::pow_mod(Xbar_l_r, this->m_E[l][m], this->m_P));
          }
          return;
        }
      })(0, this->n(), x);

      return m;
    }

    std::map<T, T> count() const {
      std::vector<T> E{1};
      for (const auto e_i : this->m_e) {
        E.push_back(E.back() * (e_i + 1));
      }

      std::vector<T> A(E.back());
      A[0] = 1;
      for (std::size_t i = 0; i < this->n(); ++i) {
        for (T f = 1; f <= this->m_e[i]; ++f) {
          for (T s = 0; s < E[i]; ++s) {
            A[f * E[i] + s] = A[(f - 1) * E[i] + s] * this->m_p[i];
          }
        }
      }
      for (auto&& A_i : A) A_i = (this->m_P - 1) / A_i;

      auto B = A;
      for (std::size_t i = 0; i < this->n(); ++i) {
        for (T s = 0, s_end = E.back() / E[i + 1]; s < s_end; ++s) {
          for (T t = 0; t < E[i]; ++t) {
            for (T f = 0; f < this->m_e[i]; ++f) {
              B[s * E[i + 1] + f * E[i] + t] -= B[s * E[i + 1] + (f + 1) * E[i] + t];
            }
          }
        }
      }

      std::map<T, T> result;
      for (T i = 0; i < E.back(); ++i) {
        result.emplace(A[i], B[i]);
      }
      return result;
    }
  };
}

#endif
