---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/fix.test.cpp
    title: tests/fix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/fix.hpp\"\n\n\n\n#include <utility>\n#include <type_traits>\n\
    \nnamespace tools {\n  template <typename F>\n  struct fix : F {\n    template\
    \ <typename G>\n    fix(G&& g) : F({::std::forward<G>(g)}) {\n    }\n\n    template\
    \ <typename... Args>\n    decltype(auto) operator()(Args&&... args) const {\n\
    \      return F::operator()(*this, ::std::forward<Args>(args)...);\n    }\n  };\n\
    \n  template <typename F>\n  fix(F&&) -> fix<::std::decay_t<F>>;\n}\n\n\n"
  code: "#ifndef TOOLS_FIX_HPP\n#define TOOLS_FIX_HPP\n\n#include <utility>\n#include\
    \ <type_traits>\n\nnamespace tools {\n  template <typename F>\n  struct fix :\
    \ F {\n    template <typename G>\n    fix(G&& g) : F({::std::forward<G>(g)}) {\n\
    \    }\n\n    template <typename... Args>\n    decltype(auto) operator()(Args&&...\
    \ args) const {\n      return F::operator()(*this, ::std::forward<Args>(args)...);\n\
    \    }\n  };\n\n  template <typename F>\n  fix(F&&) -> fix<::std::decay_t<F>>;\n\
    }\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/fix.hpp
  requiredBy: []
  timestamp: '2021-05-16 02:11:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/fix.test.cpp
documentation_of: tools/fix.hpp
layout: document
title: Fixed point combinator
---

```cpp
template <typename G>
(see below) fix(G g);
```

It returns a fixed point of its argument function.
When `f(args...)` is invocable and `g(f, args...)` is invocable, `tools::fix(g)(args...)` returns `f(args...)`.

## Usage
```cpp
tools::fix([&](auto&& fib, const int n) -> int {
  return n >= 2 ? fib(n - 2) + fib(n - 1) : n;
})(10);
```

## References
- [C++のラムダで再帰する - koturnの日記](https://koturn.hatenablog.com/entry/2018/06/10/060000)

## Constraints
- `g(f, args...)` is invocable.
- `f(args...)` is invocable.

## Time Complexity
- It depends on `g`.

## License
- According to the source, "ブログ上のコードはコピペ自由です．"

## Author
- koturn