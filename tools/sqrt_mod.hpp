#ifndef TOOLS_SQRT_MOD_HPP
#define TOOLS_SQRT_MOD_HPP

#include <optional>
#include <cassert>
#include <vector>
#include "tools/is_prime.hpp"
#include "tools/mod.hpp"
#include "tools/pow_mod.hpp"
#include "tools/prod_mod.hpp"
#include "tools/inv_mod.hpp"

namespace tools {
  inline ::std::optional<long long> sqrt_mod(long long a, const long long p) {
    assert(::tools::is_prime(p));
    a = ::tools::mod(a, p);

    if (p == 2) return a;
    if (a == 0) return 0;
    if (::tools::pow_mod(a, (p - 1) / 2, p) != 1) return ::std::nullopt;

    long long s, t;
    for (s = p - 1, t = 0; s % 2 == 0; s /= 2, ++t);

    long long u;
    for (u = 1; ::tools::pow_mod(u, (p - 1) / 2, p) == 1; ++u);

    ::std::vector<long long> u_s(t);
    u_s[0] = ::tools::pow_mod(u, s, p);
    for (long long i = 1; i < t; ++i) {
      u_s[i] = ::tools::prod_mod(u_s[i - 1], u_s[i - 1], p);
    }

    const long long ia = ::tools::inv_mod(a, p);

    long long x = ::tools::pow_mod(a, (s + 1) / 2, p);
    while (true) {
      long long t_ = 0;
      for (long long base = ::tools::prod_mod(ia, ::tools::prod_mod(x, x, p), p); base != 1; base = ::tools::prod_mod(base, base, p), ++t_);
      if (t_ == 0) break;
      x = ::tools::prod_mod(x, u_s[t - t_ - 1], p);
    }

    return x;
  }
}

#endif
