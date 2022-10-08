#ifndef TOOLS_CONVOLUTION_HPP
#define TOOLS_CONVOLUTION_HPP

#include <type_traits>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cstddef>
#include "atcoder/modint.hpp"
#include "atcoder/convolution.hpp"
#include "tools/is_prime.hpp"
#include "tools/garner3.hpp"

namespace tools {

  template <typename InputIterator, typename OutputIterator>
  void convolution(const InputIterator a_begin, const InputIterator a_end, const InputIterator b_begin, const InputIterator b_end, OutputIterator result) {
    using M = ::std::decay_t<decltype(*a_begin)>;
    using M1 = ::atcoder::static_modint<1107296257>; // 33 * 2^25 + 1
    using M2 = ::atcoder::static_modint<1711276033>; // 51 * 2^25 + 1
    using M3 = ::atcoder::static_modint<1811939329>; // 27 * 2^26 + 1

    // return maximum 2^k s.t. x = 1 (mod 2^k)
    static const auto pow2_k = [](const unsigned long long x) {
      return (x - 1) & -(x - 1);
    };

    ::std::vector<M> a(a_begin, a_end);
    ::std::vector<M> b(b_begin, b_end);

    if (::tools::is_prime(M::mod()) && a.size() + b.size() <= pow2_k(M::mod()) + 1) {
      for (const auto& c_i : ::atcoder::convolution(a, b)) {
        *result = c_i;
        ++result;
      }
      return;
    }

    assert(a.size() + b.size() <= ::std::min({pow2_k(M1::mod()), pow2_k(M2::mod()), pow2_k(M3::mod())}) + 1);

    // No need for the following assertion because the condition always holds.
    // assert(std::min(a.size(), b.size()) * tools::square(M::mod() - 1) < M1::mod() * M2::mod() * M3::mod());

    ::std::vector<M1> a1;
    ::std::vector<M2> a2;
    ::std::vector<M3> a3;
    a1.reserve(a.size());
    a2.reserve(a.size());
    a3.reserve(a.size());
    for (const auto& a_i : a) {
      a1.emplace_back(a_i.val());
      a2.emplace_back(a_i.val());
      a3.emplace_back(a_i.val());
    }

    ::std::vector<M1> b1;
    ::std::vector<M2> b2;
    ::std::vector<M3> b3;
    b1.reserve(b.size());
    b2.reserve(b.size());
    b3.reserve(b.size());
    for (const auto& b_i : b) {
      b1.emplace_back(b_i.val());
      b2.emplace_back(b_i.val());
      b3.emplace_back(b_i.val());
    }

    const auto c1 = ::atcoder::convolution(a1, b1);
    const auto c2 = ::atcoder::convolution(a2, b2);
    const auto c3 = ::atcoder::convolution(a3, b3);
    for (::std::size_t i = 0; i + 1 < a.size() + b.size(); ++i) {
      *result = M::raw(::tools::garner3(c1[i], c2[i], c3[i], M::mod()));
      ++result;
    }
  }
}

#endif
