---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tools/pow_mod_cache.hpp
    title: Precompute $b^n \pmod{M}$
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/find_cycle.test.cpp
    title: tests/find_cycle.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/find_cycle.hpp\"\n\n\n\n#include <utility>\n#include\
    \ <cstdint>\n\nnamespace tools {\n\n  template <typename T, typename F>\n  ::std::pair<::std::int_fast64_t,\
    \ ::std::int_fast64_t> find_cycle(const T& seed, const F& f) {\n    ::std::int_fast64_t\
    \ i = 1;\n    ::std::int_fast64_t j = 2;\n    T x = f(seed);\n    T y = f(f(seed));\n\
    \    for (; x != y; ++i, j += 2, x = f(x), y = f(f(y)));\n\n    i = 0;\n    x\
    \ = seed;\n    for (; x != y; ++i, ++j, x = f(x), y = f(y));\n\n    const ::std::int_fast64_t\
    \ head = i;\n\n    ++i;\n    j = i + 1;\n    x = f(x);\n    y = f(f(y));\n   \
    \ for (; x != y; ++i, j += 2, x = f(x), y = f(f(y)));\n\n    const ::std::int_fast64_t\
    \ cycle = j - i;\n\n    return ::std::make_pair(head, cycle);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_FIND_CYCLE_HPP\n#define TOOLS_FIND_CYCLE_HPP\n\n#include <utility>\n\
    #include <cstdint>\n\nnamespace tools {\n\n  template <typename T, typename F>\n\
    \  ::std::pair<::std::int_fast64_t, ::std::int_fast64_t> find_cycle(const T& seed,\
    \ const F& f) {\n    ::std::int_fast64_t i = 1;\n    ::std::int_fast64_t j = 2;\n\
    \    T x = f(seed);\n    T y = f(f(seed));\n    for (; x != y; ++i, j += 2, x\
    \ = f(x), y = f(f(y)));\n\n    i = 0;\n    x = seed;\n    for (; x != y; ++i,\
    \ ++j, x = f(x), y = f(y));\n\n    const ::std::int_fast64_t head = i;\n\n   \
    \ ++i;\n    j = i + 1;\n    x = f(x);\n    y = f(f(y));\n    for (; x != y; ++i,\
    \ j += 2, x = f(x), y = f(f(y)));\n\n    const ::std::int_fast64_t cycle = j -\
    \ i;\n\n    return ::std::make_pair(head, cycle);\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/find_cycle.hpp
  requiredBy:
  - tools/pow_mod_cache.hpp
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/find_cycle.test.cpp
documentation_of: tools/find_cycle.hpp
layout: document
title: Floyd's cycle-finding algorithm
---

```cpp
template <typename T, typename F>
std::pair<std::int_fast64_t, std::int_fast64_t> find_cycle(T seed, F f);
```

It returns the length of head and the length of cycle.

## Parameters
- `seed`
    - the initial state
- `f`
    - the function which generates the next state

## License
- CC0

## Author
- anqooqie
