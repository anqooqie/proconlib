// competitive-verifier: STANDALONE

#include <iostream>
#include "tools/assert_that.hpp"
#include "tools/polynomial.hpp"

using ll = long long;
struct AG {
  using T = tools::polynomial<ll>;
  static T op(const T& x, const T& y) {
    return x + y;
  }
  static T e() {
    return T{};
  }
  static T inv(const T& x) {
    return -x;
  }
};
struct MM {
  using T = tools::polynomial<ll>;
  static T op(const T& x, const T& y) {
    return x * y;
  }
  static T e() {
    return T{1};
  }
};

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  tools::polynomial<AG, MM> a{{1, 2}, {3, 4}};
  tools::polynomial<AG, MM> b{{5, 6}, {7, 8}};
  tools::polynomial<AG, MM> c{{5, 16, 12}, {22, 60, 40}, {21, 52, 32}};

  assert_that(a * b == c);

  return 0;
}
