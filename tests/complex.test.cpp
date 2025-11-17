// competitive-verifier: STANDALONE

#include <complex>
#include <iostream>
#include <string>
#include "tools/complex.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  static_assert(tools::complex<std::complex<float>>);
  static_assert(tools::complex<std::complex<double>>);
  static_assert(tools::complex<std::complex<long double>>);

  static_assert(!tools::complex<float>);
  static_assert(!tools::complex<double>);
  static_assert(!tools::complex<long double>);

  static_assert(!tools::complex<int>);
  static_assert(!tools::complex<std::string>);

  return 0;
}
