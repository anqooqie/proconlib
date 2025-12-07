#ifndef TOOLS_RATIONAL_BINARY_SEARCH_HPP
#define TOOLS_RATIONAL_BINARY_SEARCH_HPP

#include <tuple>
#include <cassert>

namespace tools {
  template <typename T, typename F>
  std::tuple<T, T, T, T> rational_binary_search(const T& p1, const T& q1, const T& p2, const T& q2, const F& f, const T& N) {
    assert(q1 >= T(0));
    assert(q2 >= T(0));
    assert(N > T(0));
    assert(p1 * q2 < p2 * q1);
    const bool f1 = f(p1, q1);
    const bool f2 = f(p2, q2);
    assert(f1 != f2);
    const auto g = [&](const T& p, const T& q) {
      assert(q > T(0));
      if (p * q1 < p1 * q) return f1;
      if (p2 * q < p * q2) return f2;
      return f(p, q);
    };

    bool d = g(T(0), T(1)) == f1;
    T p3, q3, p4, q4;
    if (d) {
      p3 = T(0);
      q3 = T(1);
      p4 = T(1);
      q4 = T(0);
    } else {
      p3 = T(-1);
      q3 = T(0);
      p4 = T(0);
      q4 = T(1);
    }

    while (q3 <= N - q4) {
      if (d) {
        T ng(1);
        if (q4 == T(0)) {
          for (; g(p3 + ng * p4, q3) == f1; ng *= T(2));
        } else {
          const T max = (N - q3) / q4;
          for (; ng <= max && g(p3 + ng * p4, q3 + ng * q4) == f1; ng = (ng == max ? ng + T(1) : ng <= max / T(2) ? T(2) * ng : max));
          if (ng == max + T(1)) {
            --ng;
            p3 += ng * p4;
            q3 += ng * q4;
            break;
          }
        }
        T ok(0);
        while (ng - ok > T(1)) {
          const auto mid = ok + (ng - ok) / T(2);
          if (g(p3 + mid * p4, q3 + mid * q4) == f1) {
            ok = mid;
          } else {
            ng = mid;
          }
        }
        std::tie(p3, q3, p4, q4) = std::make_tuple(p3 + ok * p4, q3 + ok * q4, p3 + ng * p4, q3 + ng * q4);
      } else {
        T ng(1);
        if (q3 == T(0)) {
          for (; g(ng * p3 + p4, q4) == f2; ng *= T(2));
        } else {
          const T max = (N - q4) / q3;
          for (; ng <= max && g(ng * p3 + p4, ng * q3 + q4) == f2; ng = (ng == max ? ng + T(1) : ng <= max / T(2) ? T(2) * ng : max));
          if (ng == max + T(1)) {
            --ng;
            p4 += ng * p3;
            q4 += ng * q3;
            break;
          }
        }
        T ok(0);
        while (ng - ok > T(1)) {
          const auto mid = ok + (ng - ok) / T(2);
          if (g(mid * p3 + p4, mid * q3 + q4) == f2) {
            ok = mid;
          } else {
            ng = mid;
          }
        }
        std::tie(p3, q3, p4, q4) = std::make_tuple(ng * p3 + p4, ng * q3 + q4, ok * p3 + p4, ok * q3 + q4);
      }
      d = !d;
    }

    return std::make_tuple(p3, q3, p4, q4);
  }
}

#endif
