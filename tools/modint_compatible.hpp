#ifndef TOOLS_MODINT_COMPATIBLE_HPP
#define TOOLS_MODINT_COMPATIBLE_HPP

#include <concepts>

namespace tools {
  template <typename T>
  concept modint_compatible = std::regular<T>
    && std::equality_comparable<T>
    && std::constructible_from<T, bool>
    && std::constructible_from<T, char>
    && std::constructible_from<T, int>
    && std::constructible_from<T, long long>
    && std::constructible_from<T, unsigned int>
    && std::constructible_from<T, unsigned long long>
    && requires(T a, T b, int v_int, long long v_ll) {
      { T::mod() } -> std::convertible_to<int>;
      { T::raw(v_int) } -> std::same_as<T>;
      { a.val() } -> std::convertible_to<int>;
      { ++a } -> std::same_as<T&>;
      { --a } -> std::same_as<T&>;
      { a++ } -> std::same_as<T>;
      { a-- } -> std::same_as<T>;
      { a += b } -> std::same_as<T&>;
      { a -= b } -> std::same_as<T&>;
      { a *= b } -> std::same_as<T&>;
      { a /= b } -> std::same_as<T&>;
      { +a } -> std::same_as<T>;
      { -a } -> std::same_as<T>;
      { a.pow(v_ll) } -> std::same_as<T>;
      { a.inv() } -> std::same_as<T>;
      { a + b } -> std::same_as<T>;
      { a - b } -> std::same_as<T>;
      { a * b } -> std::same_as<T>;
      { a / b } -> std::same_as<T>;
    };
}

#endif
