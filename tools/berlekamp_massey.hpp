#ifndef TOOLS_BERLEKAMP_MASSEY_HPP
#define TOOLS_BERLEKAMP_MASSEY_HPP

#include <cstddef>
#include <algorithm>
#include <utility>
#include <cassert>
#include "tools/polynomial.hpp"

namespace tools {
  template <typename K>
  ::tools::polynomial<K> berlekamp_massey(const ::tools::polynomial<K>& A) {
    ::tools::polynomial<K> C{K(1)};
    ::tools::polynomial<K> B{K(1)};
    ::std::size_t L = 0;
    ::std::size_t m = 1;
    K b(1);

    for (::std::size_t n = 0; n < A.size(); ++n) {
      K d(0);
      for (::std::size_t i = 0; i <= L; ++i) {
        d += C[i] * A[n - i];
      }

      if (d == K(0)) {
        ++m;
      } else {
        const auto update_C = [&]() {
          C.resize(::std::max(C.size(), B.size() + m));
          const auto coeff = d / b;
          for (::std::size_t i = 0; i < B.size(); ++i) {
            C[i + m] -= coeff * B[i];
          }
        };
        if (2 * L <= n) {
          const auto T = C;
          update_C();
          L = n + 1 - L;
          B = ::std::move(T);
          b = d;
          m = 1;
        } else {
          update_C();
          ++m;
        }
      }
    }

    assert(!C.empty());
    assert(C[0] == K(1));
    #ifndef NDEBUG
      for (::std::size_t n = C.size() - 1; n < A.size(); ++n) {
        K d(0);
        for (::std::size_t i = 0; i < C.size(); ++i) {
          d += C[i] * A[n - i];
        }
        assert(d == K(0));
      }
    #endif

    return C;
  }
}

#endif
