#ifndef TOOLS_GARNER3_HPP
#define TOOLS_GARNER3_HPP

#include <cstdint>
#include <cassert>
#include "atcoder/modint.hpp"
#include "tools/prod_mod.hpp"

namespace tools {

  inline ::std::int_fast64_t garner3(const ::atcoder::static_modint<167772161>& a, const ::atcoder::static_modint<469762049>& b, const ::atcoder::static_modint<754974721>& c, const ::std::int_fast64_t m) {
    assert(m >= 1);

    using mint1 = ::atcoder::static_modint<167772161>; // 5 * 2^25 + 1
    using mint2 = ::atcoder::static_modint<469762049>; // 7 * 2^26 + 1
    using mint3 = ::atcoder::static_modint<754974721>; // 45 * 2^24 + 1
    using u64 = ::std::uint_fast64_t;
    static const mint2 m1_inv_mod_m2 = mint2::raw(mint1::mod()).inv();
    static const mint3 m1_m2_inv_mod_m3 = (mint3::raw(mint1::mod()) * mint3::raw(mint2::mod())).inv();

    static const auto plus_mod = [](u64 x, const u64 y, const u64 mod) {
      x += y;
      if (x >= mod) x -= mod;
      return x; 
    };

    // t1 = (b - a) / 167772161; (mod 469762049)
    // t2 = (c - a - t1 * 167772161) / 167772161 / 469762049; (mod 754974721)
    // return a + t1 * 167772161 + t2 * 167772161 * 469762049; (mod m)
    const mint2 t1 = (b - mint2::raw(a.val())) * m1_inv_mod_m2;
    const mint3 t2 = (c - mint3::raw(a.val()) - mint3::raw(t1.val()) * mint3::raw(mint1::mod())) * m1_m2_inv_mod_m3;
    ::std::uint_fast64_t r = ::tools::prod_mod(t2.val(), u64(mint1::mod()) * u64(mint2::mod()), m);
    r = plus_mod(r, u64(t1.val()) * u64(mint1::mod()), m);
    r = plus_mod(r, a.val(), m);
    return r;
  }
}

#endif
