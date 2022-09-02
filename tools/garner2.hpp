#ifndef TOOLS_GARNER2_HPP
#define TOOLS_GARNER2_HPP

#include <cstdint>
#include <cassert>
#include "tools/is_prime.hpp"

namespace tools {

  template <typename M1, typename M2>
  ::std::int_fast64_t garner2(const M1& a, const M2& b) {
    using u64 = ::std::uint_fast64_t;
    static constexpr u64 m1_m2 = u64(M1::mod()) * u64(M2::mod());
    static const M2 m1_inv_mod_m2 = M2::raw(M1::mod()).inv();

    assert(M1::mod() < M2::mod());
    assert(::tools::is_prime(M1::mod()));
    assert(::tools::is_prime(M2::mod()));

    // t = (b - a) / M1; (mod M2)
    // return a + t * M1;
    const M2 t = (b - M2::raw(a.val())) * m1_inv_mod_m2;
    u64 r = t.val();
    r *= M1::mod();
    r += a.val();
    if (r >= m1_m2) r -= m1_m2;
    return r;
  }
}

#endif
