#ifndef TOOLS_NTH_TERM_HPP
#define TOOLS_NTH_TERM_HPP

#include <cstdint>
#include <type_traits>
#include <vector>
#include <cassert>
#include <iterator>
#include "tools/convolution.hpp"

namespace tools {
  template <typename InputIterator>
  auto nth_term(InputIterator a_begin, InputIterator a_end, InputIterator c_begin, InputIterator c_end, ::std::uint_fast64_t n) -> ::std::decay_t<decltype(*a_begin)> {
    using M = ::std::decay_t<decltype(*a_begin)>;
    ::std::vector<M> G(a_begin, a_end);
    ::std::vector<M> Q(c_begin, c_end);
    assert(G.size() + 1 == Q.size());
    assert(Q[0] == M(1));

    const auto d = G.size();
    if (d == 0) return M(0);

    ::std::vector<M> P;
    ::tools::convolution(G.begin(), G.end(), Q.begin(), Q.end(), ::std::back_inserter(P));
    P.resize(d);

    while (n > 0) {
      auto Q1 = Q;
      for (::std::size_t i = 1; i < Q1.size(); i += 2) {
        Q1[i] = -Q1[i];
      }
      ::std::vector<M> PQ;
      ::tools::convolution(P.begin(), P.end(), Q1.begin(), Q1.end(), ::std::back_inserter(PQ));
      ::std::vector<M> QQ;
      ::tools::convolution(Q.begin(), Q.end(), Q1.begin(), Q1.end(), ::std::back_inserter(QQ));
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

    return P[0];
  }
}

#endif
