#ifndef TOOLS_GARNER3_HPP
#define TOOLS_GARNER3_HPP

#include <cassert>
#include "tools/is_prime.hpp"
#include "tools/prod_mod.hpp"

namespace tools {

  template <typename M, typename M1, typename M2, typename M3>
  M garner3(const M1& a, const M2& b, const M3& c, const M m) {
    using ull = unsigned long long;
    static const M2 m1_inv_mod_m2 = M2::raw(M1::mod()).inv();
    static const M3 m1_m2_inv_mod_m3 = (M3::raw(M1::mod()) * M3::raw(M2::mod())).inv();

    static const auto plus_mod = [](ull x, const ull y, const ull mod) {
      assert(x < mod);
      assert(y < mod);

      x += y;
      if (x >= mod) x -= mod;
      return x; 
    };

    assert(m >= 1);
    assert(M1::mod() < M2::mod());
    assert(M2::mod() < M3::mod());
    assert(::tools::is_prime(M1::mod()));
    assert(::tools::is_prime(M2::mod()));
    assert(::tools::is_prime(M3::mod()));

    // t1 = (b - a) / M1; (mod M2)
    // t2 = (c - a - t1 * M1) / M1 / M2; (mod M3)
    // return a + t1 * M1 + t2 * M1 * M2; (mod m)
    const M2 t1 = (b - M2::raw(a.val())) * m1_inv_mod_m2;
    const M3 t2 = (c - M3::raw(a.val()) - M3::raw(t1.val()) * M3::raw(M1::mod())) * m1_m2_inv_mod_m3;
    ull r = ::tools::prod_mod(t2.val(), ull(M1::mod()) * ull(M2::mod()), m);
    assert(r < ull(m));
    r = plus_mod(r, ull(t1.val()) * ull(M1::mod()) % m, m);
    assert(r < ull(m));
    r = plus_mod(r, a.val() % m, m);
    assert(r < ull(m));
    return r;
  }
}

#endif
