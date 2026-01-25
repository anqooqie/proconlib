#ifndef TOOLS_MODINT_COMPATIBLE_HPP
#define TOOLS_MODINT_COMPATIBLE_HPP

#include <concepts>
#include <type_traits>

namespace tools {
  template <typename T>
  concept modint_compatible = std::regular<std::remove_cv_t<T>>
    && std::equality_comparable<std::remove_cv_t<T>>
    && std::constructible_from<std::remove_cv_t<T>, bool>
    && std::constructible_from<std::remove_cv_t<T>, char>
    && std::constructible_from<std::remove_cv_t<T>, int>
    && std::constructible_from<std::remove_cv_t<T>, long long>
    && std::constructible_from<std::remove_cv_t<T>, unsigned int>
    && std::constructible_from<std::remove_cv_t<T>, unsigned long long>
    && requires(std::remove_cv_t<T> a, std::remove_cv_t<T> b, int v_int, long long v_ll) {
      { std::remove_cv_t<T>::mod() } -> std::convertible_to<int>;
      { std::remove_cv_t<T>::raw(v_int) } -> std::same_as<std::remove_cv_t<T>>;
      { a.val() } -> std::convertible_to<int>;
      { ++a } -> std::same_as<std::remove_cv_t<T>&>;
      { --a } -> std::same_as<std::remove_cv_t<T>&>;
      { a++ } -> std::same_as<std::remove_cv_t<T>>;
      { a-- } -> std::same_as<std::remove_cv_t<T>>;
      { a += b } -> std::same_as<std::remove_cv_t<T>&>;
      { a -= b } -> std::same_as<std::remove_cv_t<T>&>;
      { a *= b } -> std::same_as<std::remove_cv_t<T>&>;
      { a /= b } -> std::same_as<std::remove_cv_t<T>&>;
      { +a } -> std::same_as<std::remove_cv_t<T>>;
      { -a } -> std::same_as<std::remove_cv_t<T>>;
      { a.pow(v_ll) } -> std::same_as<std::remove_cv_t<T>>;
      { a.inv() } -> std::same_as<std::remove_cv_t<T>>;
      { a + b } -> std::same_as<std::remove_cv_t<T>>;
      { a - b } -> std::same_as<std::remove_cv_t<T>>;
      { a * b } -> std::same_as<std::remove_cv_t<T>>;
      { a / b } -> std::same_as<std::remove_cv_t<T>>;
    };
}

#endif
