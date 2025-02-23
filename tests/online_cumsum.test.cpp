// competitive-verifier: STANDALONE

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/assert_that.hpp"
#include "tools/matrix.hpp"
#include "tools/online_cumsum.hpp"

using mint = atcoder::modint998244353;
using matrix2x2 = tools::matrix<mint, 2, 2>;
struct M {
  using T = matrix2x2;
  static T op(const T& x, const T& y) {
    return x * y;
  }
  static T e() {
    return T::e();
  }
};
struct G {
  using T = matrix2x2;
  static T op(const T& x, const T& y) {
    return x * y;
  }
  static T e() {
    return T::e();
  }
  static T inv(const T& x) {
    return *x.inv();
  }
};

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  {
    tools::online_cumsum<int> a;
    assert_that(a.size() == 0);
    assert_that(a.prod(0, 0) == 0);
    assert_that(a.sum(0, 0) == 0);
  }
  {
    tools::online_cumsum<int> a(1);
    assert_that(a.size() == 1);
    assert_that(a.prod(0, 0) == 0);
    a[0] = 1;
    assert_that(a[0] == 1);
    assert_that(a.prod(0, 0) == 0);
    assert_that(a.prod(1, 1) == 0);
    assert_that(a.prod(0, 1) == 1);
    assert_that(a.sum(0, 1) == 1);
  }
  {
    tools::online_cumsum<int> a(2);
    assert_that(a.size() == 2);
    assert_that(a.prod(0, 0) == 0);
    a[0] = 1;
    assert_that(a[0] == 1);
    assert_that(a.prod(0, 0) == 0);
    assert_that(a.prod(1, 1) == 0);
    assert_that(a.prod(0, 1) == 1);
    a[1] = 2;
    assert_that(a[0] == 1);
    assert_that(a[1] == 2);
    assert_that(a.prod(0, 0) == 0);
    assert_that(a.prod(1, 1) == 0);
    assert_that(a.prod(2, 2) == 0);
    assert_that(a.prod(0, 1) == 1);
    assert_that(a.prod(1, 2) == 2);
    assert_that(a.prod(0, 2) == 3);
    assert_that(a.sum(0, 2) == 3);
  }
  {
    tools::online_cumsum<int, false> a;
    assert_that(a.size() == 0);
    assert_that(a.prod(0, 0) == 0);
    assert_that(a.sum(0, 0) == 0);
  }
  {
    tools::online_cumsum<int, false> a(1);
    assert_that(a.size() == 1);
    assert_that(a.prod(1, 1) == 0);
    a[0] = 1;
    assert_that(a[0] == 1);
    assert_that(a.prod(1, 1) == 0);
    assert_that(a.prod(0, 0) == 0);
    assert_that(a.prod(0, 1) == 1);
    assert_that(a.sum(0, 1) == 1);
  }
  {
    tools::online_cumsum<int, false> a(2);
    assert_that(a.size() == 2);
    assert_that(a.prod(2, 2) == 0);
    a[1] = 1;
    assert_that(a[1] == 1);
    assert_that(a.prod(2, 2) == 0);
    assert_that(a.prod(1, 1) == 0);
    assert_that(a.prod(1, 2) == 1);
    a[0] = 2;
    assert_that(a[1] == 1);
    assert_that(a[0] == 2);
    assert_that(a.prod(2, 2) == 0);
    assert_that(a.prod(1, 1) == 0);
    assert_that(a.prod(0, 0) == 0);
    assert_that(a.prod(1, 2) == 1);
    assert_that(a.prod(0, 1) == 2);
    assert_that(a.prod(0, 2) == 3);
    assert_that(a.sum(0, 2) == 3);
  }
  {
    tools::online_cumsum<M> a;
    assert_that(a.size() == 0);
    assert_that(a.prod(0, 0) == M::e());
  }
  {
    tools::online_cumsum<M> a(1);
    assert_that(a.size() == 1);
    assert_that(a.prod(0, 0) == M::e());
    a[0] = matrix2x2 {
      {1, 2},
      {3, 4},
    };
    assert_that(a.prod(0, 0) == M::e());
    assert_that(a.prod(0, 1) == a[0]);
  }
  {
    tools::online_cumsum<M> a(2);
    assert_that(a.size() == 2);
    assert_that(a.prod(0, 0) == M::e());
    a[0] = matrix2x2 {
      {1, 2},
      {3, 4},
    };
    assert_that(a.prod(0, 0) == M::e());
    assert_that(a.prod(0, 1) == a[0]);
    a[1] = matrix2x2 {
      {5, 6},
      {7, 8},
    };
    assert_that(a.prod(0, 0) == M::e());
    assert_that(a.prod(0, 1) == a[0]);
    assert_that(a.prod(0, 2) == a[0] * a[1]);
  }
  {
    tools::online_cumsum<M, false> a;
    assert_that(a.size() == 0);
    assert_that(a.prod(0, 0) == M::e());
  }
  {
    tools::online_cumsum<M, false> a(1);
    assert_that(a.size() == 1);
    assert_that(a.prod(1, 1) == M::e());
    a[0] = matrix2x2 {
      {1, 2},
      {3, 4},
    };
    assert_that(a.prod(1, 1) == M::e());
    assert_that(a.prod(0, 1) == a[0]);
  }
  {
    tools::online_cumsum<M, false> a(2);
    assert_that(a.size() == 2);
    assert_that(a.prod(2, 2) == M::e());
    a[1] = matrix2x2 {
      {1, 2},
      {3, 4},
    };
    assert_that(a.prod(2, 2) == M::e());
    assert_that(a.prod(1, 2) == a[1]);
    a[0] = matrix2x2 {
      {5, 6},
      {7, 8},
    };
    assert_that(a.prod(2, 2) == M::e());
    assert_that(a.prod(1, 2) == a[1]);
    assert_that(a.prod(0, 2) == a[0] * a[1]);
  }
  {
    tools::online_cumsum<G> a;
    assert_that(a.size() == 0);
    assert_that(a.prod(0, 0) == G::e());
  }
  {
    tools::online_cumsum<G> a(1);
    assert_that(a.size() == 1);
    assert_that(a.prod(0, 0) == G::e());
    a[0] = matrix2x2 {
      {1, 2},
      {3, 4},
    };
    assert_that(a.prod(0, 0) == G::e());
    assert_that(a.prod(1, 1) == G::e());
    assert_that(a.prod(0, 1) == a[0]);
  }
  {
    tools::online_cumsum<G> a(2);
    assert_that(a.size() == 2);
    assert_that(a.prod(0, 0) == G::e());
    a[0] = matrix2x2 {
      {1, 2},
      {3, 4},
    };
    assert_that(a.prod(0, 0) == G::e());
    assert_that(a.prod(1, 1) == G::e());
    assert_that(a.prod(0, 1) == a[0]);
    a[1] = matrix2x2 {
      {5, 6},
      {7, 8},
    };
    assert_that(a.prod(0, 0) == G::e());
    assert_that(a.prod(1, 1) == G::e());
    assert_that(a.prod(2, 2) == G::e());
    assert_that(a.prod(0, 1) == a[0]);
    assert_that(a.prod(1, 2) == a[1]);
    assert_that(a.prod(0, 2) == a[0] * a[1]);
  }
  {
    tools::online_cumsum<G, false> a;
    assert_that(a.size() == 0);
    assert_that(a.prod(0, 0) == G::e());
  }
  {
    tools::online_cumsum<G, false> a(1);
    assert_that(a.size() == 1);
    assert_that(a.prod(1, 1) == G::e());
    a[0] = matrix2x2 {
      {1, 2},
      {3, 4},
    };
    assert_that(a.prod(1, 1) == G::e());
    assert_that(a.prod(0, 0) == G::e());
    assert_that(a.prod(0, 1) == a[0]);
  }
  {
    tools::online_cumsum<G, false> a(2);
    assert_that(a.size() == 2);
    assert_that(a.prod(2, 2) == G::e());
    a[1] = matrix2x2 {
      {1, 2},
      {3, 4},
    };
    assert_that(a.prod(2, 2) == G::e());
    assert_that(a.prod(1, 1) == G::e());
    assert_that(a.prod(1, 2) == a[1]);
    a[0] = matrix2x2 {
      {5, 6},
      {7, 8},
    };
    assert_that(a.prod(2, 2) == G::e());
    assert_that(a.prod(1, 1) == G::e());
    assert_that(a.prod(0, 0) == G::e());
    assert_that(a.prod(1, 2) == a[1]);
    assert_that(a.prod(0, 1) == a[0]);
    assert_that(a.prod(0, 2) == a[0] * a[1]);
  }

  return 0;
}
