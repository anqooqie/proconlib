// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include <iostream>
#include <vector>
#include <type_traits>
#include "atcoder/modint.hpp"
#include "tools/assert_that.hpp"
#include "tools/polynomial.hpp"

template <typename M>
std::vector<M> naive(const tools::polynomial<M>& f, const std::vector<M>& p) {
  std::vector<M> res;
  for (const auto& p_i : p) {
    res.push_back(f(p_i));
  }
  return res;
}

template <typename M = void>
void verify_not_wa(const std::vector<int>& oc, const ::std::vector<int>& op) {
  if constexpr (std::is_same_v<M, void>) {

    verify_not_wa<atcoder::static_modint<1>>(oc, op);
    verify_not_wa<atcoder::static_modint<2>>(oc, op);
    verify_not_wa<atcoder::static_modint<735134400>>(oc, op);
    verify_not_wa<atcoder::static_modint<999634589>>(oc, op);
    verify_not_wa<atcoder::static_modint<1000000007>>(oc, op);
    verify_not_wa<atcoder::dynamic_modint<0>>(oc, op);
    verify_not_wa<atcoder::dynamic_modint<1>>(oc, op);
    verify_not_wa<atcoder::dynamic_modint<2>>(oc, op);
    verify_not_wa<atcoder::dynamic_modint<3>>(oc, op);
    verify_not_wa<atcoder::dynamic_modint<4>>(oc, op);
    verify_not_wa<atcoder::dynamic_modint<5>>(oc, op);

  } else {
    tools::polynomial<M> f(oc.begin(), oc.end());
    std::vector<M> p(op.begin(), op.end());

    assert_that(f.multipoint_evaluation(p.begin(), p.end()) == naive(f, p));
  }
}

template <typename M = void>
void verify_not_tle(const int n, const int m) {
  if constexpr (std::is_same_v<M, void>) {

    verify_not_tle<atcoder::static_modint<1>>(n, m);
    verify_not_tle<atcoder::static_modint<2>>(n, m);
    verify_not_tle<atcoder::static_modint<735134400>>(n, m);
    verify_not_tle<atcoder::static_modint<999634589>>(n, m);
    verify_not_tle<atcoder::static_modint<1000000007>>(n, m);
    verify_not_tle<atcoder::dynamic_modint<0>>(n, m);
    verify_not_tle<atcoder::dynamic_modint<1>>(n, m);
    verify_not_tle<atcoder::dynamic_modint<2>>(n, m);
    verify_not_tle<atcoder::dynamic_modint<3>>(n, m);
    verify_not_tle<atcoder::dynamic_modint<4>>(n, m);
    verify_not_tle<atcoder::dynamic_modint<5>>(n, m);

  } else {
    tools::polynomial<M> f(n);
    ++f.back();
    std::vector<M> p(m);
    for (int i = 0; i < m; ++i) p[i] = M(i);

    std::vector<M> expected(m);
    for (int i = 0; i < m; ++i) expected[i] = M(i).pow(n - 1);

    assert_that(f.multipoint_evaluation(p.begin(), p.end()) == expected);
  }
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

  verify_not_wa(std::vector<int>{1, 2, 3, 4}, std::vector<int>{5, 6, 7, 8, 9});
  verify_not_wa(std::vector<int>{1000000}, std::vector<int>{1000000});

  verify_not_tle(131072, 131072);

  std::cout << "Hello World" << '\n';
  return 0;
}
