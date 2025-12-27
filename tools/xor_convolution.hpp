#ifndef TOOLS_XOR_CONVOLUTION_HPP
#define TOOLS_XOR_CONVOLUTION_HPP

#include <cassert>
#include <iterator>
#include <ranges>
#include <type_traits>
#include <utility>
#include <vector>
#include "tools/has_single_bit.hpp"
#include "tools/modint_compatible.hpp"

namespace tools {
  namespace detail::xor_convolution {
    template <typename T>
    void fwht(std::vector<T>& a) {
      const int N = a.size();
      assert(tools::has_single_bit(N));

      for (int w = 1; w < N; w <<= 1) {
        for (int i = 0; i < N; ++i) {
          if ((i & w) == 0) {
            T x = a[i];
            T y = a[i | w];
            a[i] = x + y;
            a[i | w] = x - y;
          }
        }
      }
    }
  }

  template <std::ranges::input_range R1, std::ranges::input_range R2>
  std::vector<std::common_type_t<std::ranges::range_value_t<R1>, std::ranges::range_value_t<R2>>> xor_convolution(R1&& a_orig, R2&& b_orig) {
    using T = std::common_type_t<std::ranges::range_value_t<R1>, std::ranges::range_value_t<R2>>;
    auto a = std::forward<R1>(a_orig) | std::ranges::to<std::vector<T>>();
    auto b = std::forward<R2>(b_orig) | std::ranges::to<std::vector<T>>();
    const int N = a.size();
    assert(std::ssize(b) == N);
    assert(tools::has_single_bit(N));

    tools::detail::xor_convolution::fwht(a);
    tools::detail::xor_convolution::fwht(b);

    std::vector<T> c(N);
    for (int i = 0; i < N; ++i) {
      c[i] = a[i] * b[i];
    }
    tools::detail::xor_convolution::fwht(c);

    if constexpr (tools::modint_compatible<T>) {
      assert(T::mod() % 2 == 1);
      const auto inv_N = T(N).inv();
      for (int i = 0; i < N; ++i) {
        c[i] *= inv_N;
      }
    } else {
      for (int i = 0; i < N; ++i) {
        c[i] /= T(N);
      }
    }
    return c;
  }
}

#endif
