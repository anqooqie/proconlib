#ifndef TOOLS_CONVOLUTION_HPP
#define TOOLS_CONVOLUTION_HPP

#include <type_traits>
#include <vector>
#include <cstddef>
#include <array>
#include <cstdint>
#include "atcoder/modint.hpp"
#include "atcoder/convolution.hpp"
#include "tools/garner.hpp"

namespace tools {

  template <typename InputIterator, typename OutputIterator>
  void convolution(const InputIterator& a_begin, const InputIterator& a_end, const InputIterator& b_begin, const InputIterator& b_end, OutputIterator result) {
    using mint = ::std::decay_t<decltype(*a_begin)>;
    using mint1 = ::atcoder::static_modint<754974721>;
    using mint2 = ::atcoder::static_modint<167772161>;
    using mint3 = ::atcoder::static_modint<469762049>;

    ::std::vector<mint> a(a_begin, a_end);
    ::std::vector<mint> b(b_begin, b_end);

    if (mint::mod() == 998244353) {
      for (const auto& c_i : ::atcoder::convolution(a, b)) {
        *result = c_i;
        ++result;
      }
      return;
    }

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
    for (::std::size_t i = 0; i < a.size() + b.size() - 1; ++i) {
      const ::std::array<::std::pair<::std::int_fast64_t, ::std::int_fast64_t>, 3> ntt({{
        {c1[i].val(), mint1::mod()},
        {c2[i].val(), mint2::mod()},
        {c3[i].val(), mint3::mod()},
      }});
      *result = ::tools::garner<mint>(ntt.begin(), ntt.end()).first;
      ++result;
    }
  }
}

#endif
