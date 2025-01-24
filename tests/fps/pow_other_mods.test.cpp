// competitive-verifier: STANDALONE

#include <cstddef>
#include <initializer_list>
#include <type_traits>
#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/assert_that.hpp"
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

void solve(const std::initializer_list<int> il, const long long k) {
  const auto specific = [&](const auto& a) {
    using F = std::decay_t<decltype(a)>;
    monoid<F>::N = a.size();

    assert_that(a.pow(k) == tools::pow<monoid<F>>(a, k));
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

  solve({0, 0, 9, 12}, 3);
  solve({1, 1}, 2);
  solve({0, 0}, 0);
  solve({0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, 536870912);
  solve({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 576460752303423488);

  return 0;
}
