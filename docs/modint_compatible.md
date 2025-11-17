---
title: Concept for a type compatible with atcoder::static_modint
documentation_of: //tools/modint_compatible.hpp
---

```cpp
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
```

It is a concept that represents a type compatible with `atcoder::static_modint`.
For example, it accepts `atcoder::dynamic_modint` and `tools::modint_for_rolling_hash`.

### Constraints
- None

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
