#ifndef TOOLS_GARNER2_HPP
#define TOOLS_GARNER2_HPP

#include <cstdint>
#include <cassert>
#include "atcoder/modint.hpp"

namespace tools {

  inline ::std::int_fast64_t garner2(const ::atcoder::static_modint<167772161>& a, const ::atcoder::static_modint<469762049>& b) {
    using mint1 = ::atcoder::static_modint<167772161>; // 5 * 2^25 + 1
    using mint2 = ::atcoder::static_modint<469762049>; // 7 * 2^26 + 1
    using u64 = ::std::uint_fast64_t;
    static constexpr u64 m1_m2 = u64(mint1::mod()) * u64(mint2::mod());
    static const mint2 m1_inv_mod_m2 = mint2::raw(mint1::mod()).inv();

    // t = (b - a) / 167772161; (mod 469762049)
    // return a + t * 167772161; (mod m)
    const mint2 t = (b - mint2::raw(a.val())) * m1_inv_mod_m2;
    u64 r = t.val();
    r *= mint1::mod();
    r += a.val();
    if (r >= m1_m2) r -= m1_m2;
    return r;
  }
}

#endif
