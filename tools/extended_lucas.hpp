#ifndef TOOLS_EXTENDED_LUCAS_HPP
#define TOOLS_EXTENDED_LUCAS_HPP

#include <vector>
#include <cassert>
#include <utility>
#include <iterator>
#include "tools/int128_t.hpp"
#include "tools/prime_factorization.hpp"
#include "tools/run_length.hpp"
#include "tools/garner.hpp"

// Source: https://hitonanode.github.io/cplib-cpp/number/combination.hpp.html
// License: MIT
// Author: hitonanode

// MIT License
// 
// Copyright (c) 2019 Ryotaro Sato
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

namespace tools {

  template <class M>
  class extended_lucas {
    struct combination_prime_pow {
      int p, q, m;
      ::std::vector<int> fac, invfac, ppow;

      long long ej(long long n) const {
        long long ret = 0;
        while (n) ret += n, n /= this->p;
        return ret;
      }

      combination_prime_pow(const int p_, const int q_) : p(p_), q(q_), m(1), ppow{1} {
        for (int t = 0; t < this->q; ++t) this->m *= this->p, this->ppow.push_back(this->m);
        this->fac.assign(this->m, 1);
        this->invfac.assign(this->m, 1);
        for (int i = 1; i < this->m; ++i) this->fac[i] = static_cast<long long>(this->fac[i - 1]) * (i % this->p ? i : 1) % this->m;
        this->invfac[this->m - 1] = this->fac[this->m - 1]; // Same as Wilson's theorem
        assert(1LL * this->fac.back() * this->invfac.back() % this->m == 1);
        for (int i = this->m - 1; i; --i) this->invfac[i - 1] = static_cast<long long>(this->invfac[i]) * (i % this->p ? i : 1) % this->m;
      }

      int nCr(long long n, long long r) const {
        assert(0 <= r && r <= n);
        if (this->p == 2 && this->q == 1) return !((~n) & r); // Lucas
        long long k = n - r;
        const long long e0 = this->ej(n / this->p) - this->ej(r / this->p) - this->ej(k / this->p);
        if (e0 >= q) return 0;

        long long ret = this->ppow[e0];
        if (this->q == 1) { // Lucas
          while (n) {
            ret = ::tools::int128_t(ret) * this->fac[n % this->p] * this->invfac[r % this->p] * this->invfac[k % this->p] % this->p;
            n /= this->p, r /= this->p, k /= this->p;
          }
          return static_cast<int>(ret);
        } else {
          if ((p > 2 || q < 3) && (this->ej(n / this->m) - this->ej(r / this->m) - this->ej(k / this->m)) & 1) ret = this->m - ret;
          while (n) {
            ret = ::tools::int128_t(ret) * this->fac[n % this->m] * this->invfac[r % this->m] * this->invfac[k % this->m] % this->m;
            n /= this->p, r /= this->p, k /= this->p;
          }
          return static_cast<int>(ret);
        }
      }
    };

    ::std::vector<combination_prime_pow> cpps;

  public:
    extended_lucas() {
      const auto prime_factors = ::tools::prime_factorization(M::mod());
      ::std::vector<::std::pair<int, int>> distinct_prime_factors;
      ::tools::run_length(prime_factors.begin(), prime_factors.end(), ::std::back_inserter(distinct_prime_factors));
      for (const auto& [p, q] : distinct_prime_factors) {
        this->cpps.emplace_back(p, q);
      }
    }

    M combination(const long long n, const long long r) const {
      if (n < 0 || r < 0 || n < r) return M::raw(0);
      ::std::vector<::std::pair<int, int>> rs;
      for (const auto& cpp : this->cpps) rs.emplace_back(cpp.nCr(n, r), cpp.m);
      return ::tools::garner<M>(rs.begin(), rs.end()).first;
    }
  };
}

#endif
