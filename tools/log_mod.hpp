#ifndef TOOLS_LOG_MOD_HPP
#define TOOLS_LOG_MOD_HPP

#include <optional>
#include <cassert>
#include <numeric>
#include <unordered_map>
#include "tools/mod.hpp"
#include "tools/floor_log2.hpp"
#include "tools/prod_mod.hpp"
#include "tools/inv_mod.hpp"
#include "tools/ceil_sqrt.hpp"
#include "tools/pow_mod.hpp"

namespace tools {
  inline std::optional<long long> log_mod(long long a, long long b, long long m) {
    assert(m >= 1);
    a = tools::mod(a, m);
    b = tools::mod(b, m);

    const auto d = tools::floor_log2(m);
    long long a_d;
    {
      auto& a_x = a_d;
      a_x = 1;
      for (long long x = 0; x < d; ++x, a_x = tools::prod_mod(a_x, a, m)) {
        if (a_x == b) return x;
      }
    }

    if (m == 1 || b == 1) return 0;

    const auto g = std::gcd(a_d, m);
    if (b % g != 0) return std::nullopt;
    if (m == g) return d;

    m /= g;
    a %= m;
    b = tools::prod_mod(b, tools::inv_mod(a_d, m), m);

    const auto p = tools::ceil_sqrt(m);
    std::unordered_map<long long, long long> map;
    for (long long q = 0, a_q = 1; q < p; ++q, a_q = tools::prod_mod(a_q, a, m)) {
      if (map.find(a_q) == map.end()) {
        map.emplace(a_q, q);
      }
    }

    const auto aux = tools::pow_mod(tools::inv_mod(a, m), p, m);
    for (long long i = 0, aux_i = 1; i < p; ++i, aux_i = tools::prod_mod(aux_i, aux, m)) {
      if (const auto it = map.find(tools::prod_mod(b, aux_i, m)); it != map.end()) {
        return d + p * i + it->second;
      }
    }

    return std::nullopt;
  }
}

#endif
