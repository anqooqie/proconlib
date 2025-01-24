// competitive-verifier: STANDALONE

#include <initializer_list>
#include <type_traits>
#include <numeric>
#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/assert_that.hpp"
#include "tools/fps.hpp"

void solve(const std::initializer_list<int> il) {
  const auto specific = [](const auto& a) {
    using M = std::decay_t<decltype(*a.begin())>;
    if (std::gcd(a[0].val(), M::mod()) != 1) return;
    tools::fps<M> expected(a.size());
    expected[0] = M(1);
    assert_that(a * a.inv() == expected);
  };

  specific(tools::fps<atcoder::static_modint<1>>(il.begin(), il.end()));
  specific(tools::fps<atcoder::static_modint<2>>(il.begin(), il.end()));
  specific(tools::fps<atcoder::static_modint<735134400>>(il.begin(), il.end()));
  specific(tools::fps<atcoder::static_modint<999634589>>(il.begin(), il.end()));
  specific(tools::fps<atcoder::static_modint<1000000007>>(il.begin(), il.end()));
  specific(tools::fps<atcoder::dynamic_modint<0>>(il.begin(), il.end()));
  specific(tools::fps<atcoder::dynamic_modint<1>>(il.begin(), il.end()));
  specific(tools::fps<atcoder::dynamic_modint<2>>(il.begin(), il.end()));
  specific(tools::fps<atcoder::dynamic_modint<3>>(il.begin(), il.end()));
  specific(tools::fps<atcoder::dynamic_modint<4>>(il.begin(), il.end()));
  specific(tools::fps<atcoder::dynamic_modint<5>>(il.begin(), il.end()));
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  atcoder::dynamic_modint<0>::set_mod(1);
  atcoder::dynamic_modint<1>::set_mod(2);
  atcoder::dynamic_modint<2>::set_mod(735134400);
  atcoder::dynamic_modint<3>::set_mod(999634589);
  atcoder::dynamic_modint<4>::set_mod(1000000007);
  atcoder::dynamic_modint<5>::set_mod(998244353);

  solve({5, 4, 3, 2, 1});
  solve({192279221});
  solve({264704198, 120999146});
  solve({682152024, 451794314, 2028037});
  solve({627477697, 504915182, 841612625, 594492394});
  solve({729561620, 415335212, 437019262, 878914770, 692819383});
  solve({173330282, 220603612, 817609646, 512965573, 521724489, 141011335});
  solve({841413510, 58432763, 698722376, 544666771, 190469745, 876171369, 379243778});
  solve({251229787, 256388306, 355236246, 511734336, 908168265, 367810644, 342843868, 180913440});
  solve({118232768, 222490630, 398642533, 451309769, 425956381, 488484142, 913374112, 586809, 283205947});
  solve({907649121, 290651129, 813718295, 770591820, 913049957, 587190944, 411145555, 899491439, 722412549, 182227749});

  return 0;
}
