#ifndef TOOLS_EXTENDED_LUCAS_HPP
#define TOOLS_EXTENDED_LUCAS_HPP

#include <vector>
#include <cstdint>
#include <cassert>
#include <utility>
#include "tools/prime_factorization.hpp"
#include "tools/garner.hpp"

namespace tools {

  // Source: https://w.atwiki.jp/uwicoder/pages/2118.html#id_6779f709
  // License: unknown
  // Author: uwi

  template <class M>
  class extended_lucas {
  private:
    class prime_power {
    private:
      ::std::vector<::std::int_fast64_t> fact;
      ::std::vector<::std::int_fast64_t> ifact;

    public:
      ::std::int_fast64_t p;
      ::std::int_fast64_t q;
      ::std::int_fast64_t P;

      prime_power(const ::std::int_fast64_t p, const ::std::int_fast64_t q) : p(p), q(q) {
        this->P = 1;
        for (::std::int_fast64_t i = 0; i < q; ++i) {
          this->P *= p;
        }

        this->fact.resize(this->P + 1);
        this->ifact.resize(this->P + 1);

        this->fact[0] = 1 % this->P;
        for (::std::int_fast64_t i = 1; i <= this->P; ++i) {
          this->fact[i] = this->fact[i - 1] * (i % p == 0 ? 1 : i) % this->P;
        }
        for (::std::int_fast64_t i = 0; i <= this->P; ++i) {
          ::std::int_fast64_t ret = 1 % this->P;
          ::std::int_fast64_t mul = this->fact[i];
          for (::std::int_fast64_t n = this->P / p * (p - 1) - 1; n > 0; n /= 2) {
            if ((n & 1) == 1) {
              ret = (ret * mul) % P;
            }
            mul = (mul * mul) % P;
          }
          this->ifact[i] = ret;
        }
      }

      ::std::int_fast64_t combination(::std::int_fast64_t n, ::std::int_fast64_t r) const {
        assert(0 <= r && r <= n);

        ::std::int_fast64_t z = n - r;
        ::std::int_fast64_t e0 = 0;
        for (::std::int_fast64_t u = n / this->p; u > 0; u /= this->p) e0 += u;
        for (::std::int_fast64_t u = r / this->p; u > 0; u /= this->p) e0 -= u;
        for (::std::int_fast64_t u = z / this->p; u > 0; u /= this->p) e0 -= u;
 
        ::std::int_fast64_t em = 0;
        for (::std::int_fast64_t u = n / this->P; u > 0; u /= this->p) em += u;
        for (::std::int_fast64_t u = r / this->P; u > 0; u /= this->p) em -= u;
        for (::std::int_fast64_t u = z / this->P; u > 0; u /= this->p) em -= u;
 
        ::std::int_fast64_t ret = 1 % this->P;
        while (n > 0) {
          ret = ret * this->fact[n % this->P] % this->P * this->ifact[r % this->P] % this->P * this->ifact[z % this->P] % this->P;
          n /= this->p;
          r /= this->p;
          z /= this->p;
        }
        for (::std::int_fast64_t i = 0; i < e0; ++i) {
          ret = ret * this->p % this->P;
        }
        if (!(this->p == 2 && this->q >= 3) && (em & 1) == 1) {
          ret = (this->P - ret) % this->P;
        }
        return ret;
      }
    };

    ::std::vector<::tools::extended_lucas<M>::prime_power> prime_powers;

  public:
    extended_lucas() {
      for (const auto& [p, q] : ::tools::prime_factorization(M::mod())) {
        this->prime_powers.emplace_back(p, q);
      }
    }
    extended_lucas(const ::tools::extended_lucas<M>&) = default;
    extended_lucas(::tools::extended_lucas<M>&&) = default;
    ~extended_lucas() = default;
    ::tools::extended_lucas<M>& operator=(const ::tools::extended_lucas<M>&) = default;
    ::tools::extended_lucas<M>& operator=(::tools::extended_lucas<M>&&) = default;

    M combination(const ::std::int_fast64_t n, const ::std::int_fast64_t r) const {
      if (n < 0 || r < 0 || r > n) return M::raw(0);

      ::std::vector<std::pair<::std::int_fast64_t, ::std::int_fast64_t>> answers;
      answers.reserve(this->prime_powers.size());
      for (const auto& prime_power : this->prime_powers) {
        answers.emplace_back(prime_power.combination(n, r), prime_power.P);
      }

      return ::tools::garner<M>(answers.begin(), answers.end())->first;
    }
  };
}

#endif
