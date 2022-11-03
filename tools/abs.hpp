#ifndef TOOLS_ABS_HPP
#define TOOLS_ABS_HPP

namespace tools {
  constexpr float abs(const float x) {
    return x < 0 ? -x : x;
  }
  constexpr double abs(const double x) {
    return x < 0 ? -x : x;
  }
  constexpr long double abs(const long double x) {
    return x < 0 ? -x : x;
  }
  constexpr int abs(const int x) {
    return x < 0 ? -x : x;
  }
  constexpr long abs(const long x) {
    return x < 0 ? -x : x;
  }
  constexpr long long abs(const long long x) {
    return x < 0 ? -x : x;
  }
}

#endif
