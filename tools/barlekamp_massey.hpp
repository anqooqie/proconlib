#ifndef TOOLS_BARLEKAMP_MASSEY_HPP
#define TOOLS_BARLEKAMP_MASSEY_HPP

#include <type_traits>
#include <vector>
#include <cstddef>
#include <algorithm>
#include <utility>

namespace tools {
  template <typename InputIterator, typename OutputIterator>
  void barlekamp_massey(InputIterator begin, InputIterator end, OutputIterator result) {
    using M = ::std::decay_t<decltype(*begin)>;
    ::std::vector<M> A(begin, end);
    ::std::vector<M> C({M(1)});
    ::std::vector<M> B({M(1)});
    ::std::size_t L = 0;
    ::std::size_t m = 1;
    M b(1);

    for (::std::size_t n = 0; n < A.size(); ++n) {
      M d(0);
      for (::std::size_t i = 0; i <= L; ++i) {
        d += C[i] * A[n - i];
      }

      if (d == M(0)) {
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

    for (const auto& C_i : C) {
      *result = C_i;
      ++result;
    }
  }
}

#endif
