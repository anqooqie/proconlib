#ifndef TOOLS_CONVOLUTION_HPP
#define TOOLS_CONVOLUTION_HPP

#include <type_traits>
#include <vector>
#include <cassert>
#include <cstddef>
#include "atcoder/modint.hpp"
#include "atcoder/convolution.hpp"
#include "tools/pow2.hpp"
#include "tools/garner3.hpp"

namespace tools {

  template <typename InputIterator, typename OutputIterator>
  void convolution(const InputIterator& a_begin, const InputIterator& a_end, const InputIterator& b_begin, const InputIterator& b_end, OutputIterator result) {
    using mint = ::std::decay_t<decltype(*a_begin)>;
    using mint1 = ::atcoder::static_modint<167772161>;
    using mint2 = ::atcoder::static_modint<469762049>;
    using mint3 = ::atcoder::static_modint<754974721>;

    ::std::vector<mint> a(a_begin, a_end);
    ::std::vector<mint> b(b_begin, b_end);

    // Well-known NTT-friendly primes:
    // 998244353 = 119 * 2^23 + 1
    // 754974721 = 45 * 2^24 + 1
    // 167772161 = 5 * 2^25 + 1
    // 469762049 = 7 * 2^26 + 1
    if (mint::mod() == 998244353 || mint::mod() == mint1::mod() || mint::mod() == mint2::mod() || mint::mod() == mint3::mod()) {
      for (const auto& c_i : ::atcoder::convolution(a, b)) {
        *result = c_i;
        ++result;
      }
      return;
    }

    assert(a.size() + b.size() <= ::tools::pow2(24) + 1);
    // min(a.size(), b.size()) * ((mint::mod() - 1) ** 2) < 167772161 * 469762049 * 754974721 also must holds.
    // We can solve the above equation and finds that mint::mod() <= 2663300487.
    // However, atcoder::modint requires that mint::mod() <= 2000001000 in the first place, so no need for another assertion.

    ::std::vector<mint1> a1;
    ::std::vector<mint2> a2;
    ::std::vector<mint3> a3;
    a1.reserve(a.size());
    a2.reserve(a.size());
    a3.reserve(a.size());
    for (const auto& a_i : a) {
      a1.emplace_back(a_i.val());
      a2.emplace_back(a_i.val());
      a3.emplace_back(a_i.val());
    }

    ::std::vector<mint1> b1;
    ::std::vector<mint2> b2;
    ::std::vector<mint3> b3;
    b1.reserve(b.size());
    b2.reserve(b.size());
    b3.reserve(b.size());
    for (const auto& b_i : b) {
      b1.emplace_back(b_i.val());
      b2.emplace_back(b_i.val());
      b3.emplace_back(b_i.val());
    }

    const ::std::vector<mint1> c1 = ::atcoder::convolution(a1, b1);
    const ::std::vector<mint2> c2 = ::atcoder::convolution(a2, b2);
    const ::std::vector<mint3> c3 = ::atcoder::convolution(a3, b3);
    for (::std::size_t i = 0; i + 1 < a.size() + b.size(); ++i) {
      *result = ::tools::garner3(c1[i], c2[i], c3[i], mint::mod());
      ++result;
    }
  }
}

#endif
