#ifndef TOOLS_EXTENDED_LUCAS_HPP
#define TOOLS_EXTENDED_LUCAS_HPP

#include <vector>
#include <cassert>
#include <utility>
#include <iterator>
#include "tools/prime_factorization.hpp"
#include "tools/run_length.hpp"
#include "tools/garner.hpp"

// Source: https://w.atwiki.jp/uwicoder/pages/2118.html#id_6779f709
// License: unknown
// Author: uwi

namespace tools {
  template <class M>
  class extended_lucas {
  private:
    class prime_power {
    private:
      ::std::vector<long long> fact;
      ::std::vector<long long> ifact;

    public:
      long long p;
      long long q;
      long long P;

      prime_power(const long long p, const long long q) : p(p), q(q) {
        this->P = 1;
        for (long long i = 0; i < q; ++i) {
          this->P *= p;
        }

        this->fact.resize(this->P + 1);
        this->ifact.resize(this->P + 1);

        this->fact[0] = 1 % this->P;
        for (long long i = 1; i <= this->P; ++i) {
          this->fact[i] = this->fact[i - 1] * (i % p == 0 ? 1 : i) % this->P;
        }
        for (long long i = 0; i <= this->P; ++i) {
          long long ret = 1 % this->P;
          long long mul = this->fact[i];
          for (long long n = this->P / p * (p - 1) - 1; n > 0; n /= 2) {
            if ((n & 1) == 1) {
              ret = (ret * mul) % P;
            }
            mul = (mul * mul) % P;
          }
          this->ifact[i] = ret;
        }
      }

      long long combination(long long n, long long r) const {
        assert(0 <= r && r <= n);

        long long z = n - r;
        long long e0 = 0;
        for (long long u = n / this->p; u > 0; u /= this->p) e0 += u;
        for (long long u = r / this->p; u > 0; u /= this->p) e0 -= u;
        for (long long u = z / this->p; u > 0; u /= this->p) e0 -= u;
 
        long long em = 0;
        for (long long u = n / this->P; u > 0; u /= this->p) em += u;
        for (long long u = r / this->P; u > 0; u /= this->p) em -= u;
        for (long long u = z / this->P; u > 0; u /= this->p) em -= u;
 
        long long ret = 1 % this->P;
        while (n > 0) {
          ret = ret * this->fact[n % this->P] % this->P * this->ifact[r % this->P] % this->P * this->ifact[z % this->P] % this->P;
          n /= this->p;
          r /= this->p;
          z /= this->p;
        }
        for (long long i = 0; i < e0; ++i) {
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
      const auto prime_factors = ::tools::prime_factorization(M::mod());
      ::std::vector<::std::pair<long long, long long>> distinct_prime_factors;
      ::tools::run_length(prime_factors.begin(), prime_factors.end(), ::std::back_inserter(distinct_prime_factors));
      for (const auto& [p, q] : distinct_prime_factors) {
        this->prime_powers.emplace_back(p, q);
      }
    }
    extended_lucas(const ::tools::extended_lucas<M>&) = default;
    extended_lucas(::tools::extended_lucas<M>&&) = default;
    ~extended_lucas() = default;
    ::tools::extended_lucas<M>& operator=(const ::tools::extended_lucas<M>&) = default;
    ::tools::extended_lucas<M>& operator=(::tools::extended_lucas<M>&&) = default;

    M combination(const long long n, const long long r) const {
      if (n < 0 || r < 0 || r > n) return M::raw(0);

      ::std::vector<std::pair<long long, long long>> answers;
      answers.reserve(this->prime_powers.size());
      for (const auto& prime_power : this->prime_powers) {
        answers.emplace_back(prime_power.combination(n, r), prime_power.P);
      }

      return ::tools::garner<M>(answers.begin(), answers.end()).first;
    }
  };
}

#endif
