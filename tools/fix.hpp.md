---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/avl_tree.hpp
    title: Reversible self-balancing binary search tree based on AVL tree
  - icon: ':heavy_check_mark:'
    path: tools/detail/avl_tree_impl.hpp
    title: tools/detail/avl_tree_impl.hpp
  - icon: ':heavy_check_mark:'
    path: tools/lazy_avl_tree.hpp
    title: Lazy reversible self-balancing binary search tree based on AVL tree
  - icon: ':heavy_check_mark:'
    path: tools/persistent_dual_segtree.hpp
    title: Persistent dual segment tree
  - icon: ':heavy_check_mark:'
    path: tools/stirling_1st.hpp
    title: Stirling numbers of the first kind $s(n, k) \pmod{P}$ for $0 \leq k \leq
      n$
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/avl_tree/binary_search.test.cpp
    title: tests/avl_tree/binary_search.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/avl_tree/reverse.test.cpp
    title: tests/avl_tree/reverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/avl_tree/set.test.cpp
    title: tests/avl_tree/set.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fix.test.cpp
    title: tests/fix.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/lazy_avl_tree.test.cpp
    title: tests/lazy_avl_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/persistent_dual_segtree.test.cpp
    title: tests/persistent_dual_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/stirling_1st.test.cpp
    title: tests/stirling_1st.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/undoable_dsu.test.cpp
    title: tests/undoable_dsu.test.cpp
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
  requiredBy:
  - tools/stirling_1st.hpp
  - tools/detail/avl_tree_impl.hpp
  - tools/persistent_dual_segtree.hpp
  - tools/avl_tree.hpp
  - tools/lazy_avl_tree.hpp
  timestamp: '2021-05-16 02:11:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/lazy_avl_tree.test.cpp
  - tests/stirling_1st.test.cpp
  - tests/persistent_dual_segtree.test.cpp
  - tests/avl_tree/reverse.test.cpp
  - tests/avl_tree/set.test.cpp
  - tests/avl_tree/binary_search.test.cpp
  - tests/undoable_dsu.test.cpp
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
