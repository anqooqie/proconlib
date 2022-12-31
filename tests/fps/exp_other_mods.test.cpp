#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <cstddef>
#include <limits>
#include <initializer_list>
#include <type_traits>
#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/assert_that.hpp"
#include "tools/prime_factorization.hpp"
#include "tools/fps.hpp"
#include "tools/pow.hpp"

template <typename F>
class monoid {
private:
  using M = typename F::value_type;

public:
  using T = F;
  inline static std::size_t N;
  static T op(const T& f, const T& g) {
    return f * g;
  }
  static T e() {
    T f(N);
    f[0] = M(1);
    return f;
  }
};

std::size_t lpf(const int x) {
  if (x == 1) return std::numeric_limits<std::size_t>::max();
  return tools::prime_factorization(x)[0];
}

void solve(const std::initializer_list<int> il) {
  const auto specific = [](const auto& a) {
    using F = std::decay_t<decltype(a)>;
    using M = typename F::value_type;
    monoid<F>::N = a.size();

    if (a.size() > lpf(M::mod())) return;

    F expected(a.size());
    M fact(1);
    for (std::size_t i = 0; i < a.size(); ++i, fact *= M(i)) {
      expected += tools::pow<monoid<F>>(a, i) / fact;
    }
    assert_that(a.exp() == expected);
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

  solve({0, 1, 2, 3, 4});
  solve({0});
  solve({0, 264704197});
  solve({0, 682152023, 451794314});
  solve({0, 627477696, 504915182, 841612625});
  solve({0, 729561619, 415335212, 437019262, 878914770});
  solve({0, 173330281, 220603612, 817609646, 512965573, 521724489});
  solve({0, 841413509, 58432763, 698722376, 544666771, 190469745, 876171369});
  solve({0, 251229786, 256388306, 355236246, 511734336, 908168265, 367810644, 342843868});
  solve({0, 118232767, 222490630, 398642533, 451309769, 425956381, 488484142, 913374112, 586809});
  solve({0, 907649120, 290651129, 813718295, 770591820, 913049957, 587190944, 411145555, 899491439, 722412549});

  std::cout << "Hello World" << '\n';
  return 0;
}
