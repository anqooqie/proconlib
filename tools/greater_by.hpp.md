---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/greater_by.hpp\"\n\n\n\nnamespace tools {\n\n  template\
    \ <class F>\n  class greater_by {\n  private:\n    F selector;\n\n  public:\n\
    \    greater_by(const F& selector) : selector(selector) {\n    }\n\n    template\
    \ <class T>\n    bool operator()(const T& x, const T& y) const {\n      return\
    \ selector(x) > selector(y);\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_GREATER_BY_HPP\n#define TOOLS_GREATER_BY_HPP\n\nnamespace tools\
    \ {\n\n  template <class F>\n  class greater_by {\n  private:\n    F selector;\n\
    \n  public:\n    greater_by(const F& selector) : selector(selector) {\n    }\n\
    \n    template <class T>\n    bool operator()(const T& x, const T& y) const {\n\
    \      return selector(x) > selector(y);\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/greater_by.hpp
  requiredBy: []
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/greater_by.hpp
layout: document
title: std::greater by key
---

It compares two values by a given key selector.

### Usage
```cpp
std::sort(a.begin(), a.end(), tools::greater_by([](int a_i) { return std::abs(x); }));
```

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
tools::greater_by<F> comp(F f);
```

It creates a comparator.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator()
```cpp
template <typename T>
bool comp(T x, T y);
```

It returns `true` if `f(x) > f(y)`.
Otherwise, it returns `false`.

### Constraints
- `f` has `operator()(T x)`
- `f(x)` is comparable

### Time Complexity
- $O(1)$ if `f(x)` takes constant time