#ifndef TOOLS_BOSTAN_MORI_HPP
#define TOOLS_BOSTAN_MORI_HPP

#include <cassert>
#include <cstddef>
#include <numeric>
#include "tools/modint.hpp"
#include "tools/polynomial.hpp"

namespace tools {
  template <::tools::modint M>
  M bostan_mori(::tools::polynomial<M> P, ::tools::polynomial<M> Q, unsigned long long n) {
    assert(::std::gcd(Q.empty() ? 0 : Q[0].val(), M::mod()) == 1);

    P.regularize();
    Q.regularize();

    while (n > 0) {
      // Q1(x) = Q(-x)
      auto Q1 = Q;
      for (::std::size_t i = 1; i < Q1.size(); i += 2) {
        Q1[i] = -Q1[i];
      }

      const auto PQ = P * Q1;
      const auto QQ = Q * Q1;

      P.clear();
      for (::std::size_t i = n & 1; i < PQ.size(); i += 2) {
        P.push_back(PQ[i]);
      }
      Q.clear();
      for (::std::size_t i = 0; i < QQ.size(); i += 2) {
        Q.push_back(QQ[i]);
      }

      n /= 2;
    }

    return P.pbegin()[0] / Q[0];
  }
}

#endif
