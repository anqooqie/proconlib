---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/random_tree.test.cpp
    title: tests/random_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://twitter.com/anta_prg/status/869633557362163712
  bundledCode: "#line 1 \"tools/random_tree.hpp\"\n\n\n\n#include <cstddef>\n#include\
    \ <cassert>\n#include <vector>\n#include <utility>\n#include <numeric>\n#include\
    \ <random>\n\n// Source: https://twitter.com/anta_prg/status/869633557362163712\n\
    // License: unknown\n// Author: anta\n\nnamespace tools {\n\n  template <typename\
    \ T>\n  class random_tree {\n  private:\n    ::std::size_t m_size;\n\n  public:\n\
    \    random_tree() = default;\n    random_tree(const ::tools::random_tree<T>&)\
    \ = default;\n    random_tree(::tools::random_tree<T>&&) = default;\n    ~random_tree()\
    \ = default;\n    ::tools::random_tree<T>& operator=(const ::tools::random_tree<T>&)\
    \ = default;\n    ::tools::random_tree<T>& operator=(::tools::random_tree<T>&&)\
    \ = default;\n\n    random_tree(const ::std::size_t n) : m_size(n) {\n      assert(n\
    \ >= 1);\n    }\n\n    ::std::size_t size() const {\n      return this->m_size;\n\
    \    }\n\n    template <typename R>\n    ::std::vector<::std::pair<T, T>> operator()(R&\
    \ engine) const {\n      ::std::vector<::std::pair<T, T>> edges;\n\n      ::std::vector<T>\
    \ perm(this->size());\n      ::std::iota(perm.begin(), perm.end(), 0);\n     \
    \ for (::std::size_t i = 0; i + 1 < this->size(); ++i) {\n        const auto x\
    \ = ::std::uniform_int_distribution<::std::size_t>(0, this->size() - i - 2)(engine);\n\
    \        const auto y = ::std::uniform_int_distribution<::std::size_t>(0, this->size()\
    \ - 1)(engine);\n        ::std::swap(perm[i + 1], perm[i + 1 + x]);\n        if\
    \ (y < i + 1) ::std::swap(perm[i], perm[y]);\n        edges.emplace_back(perm[i],\
    \ perm[i + 1]);\n      }\n\n      return edges;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_RANDOM_TREE_HPP\n#define TOOLS_RANDOM_TREE_HPP\n\n#include\
    \ <cstddef>\n#include <cassert>\n#include <vector>\n#include <utility>\n#include\
    \ <numeric>\n#include <random>\n\n// Source: https://twitter.com/anta_prg/status/869633557362163712\n\
    // License: unknown\n// Author: anta\n\nnamespace tools {\n\n  template <typename\
    \ T>\n  class random_tree {\n  private:\n    ::std::size_t m_size;\n\n  public:\n\
    \    random_tree() = default;\n    random_tree(const ::tools::random_tree<T>&)\
    \ = default;\n    random_tree(::tools::random_tree<T>&&) = default;\n    ~random_tree()\
    \ = default;\n    ::tools::random_tree<T>& operator=(const ::tools::random_tree<T>&)\
    \ = default;\n    ::tools::random_tree<T>& operator=(::tools::random_tree<T>&&)\
    \ = default;\n\n    random_tree(const ::std::size_t n) : m_size(n) {\n      assert(n\
    \ >= 1);\n    }\n\n    ::std::size_t size() const {\n      return this->m_size;\n\
    \    }\n\n    template <typename R>\n    ::std::vector<::std::pair<T, T>> operator()(R&\
    \ engine) const {\n      ::std::vector<::std::pair<T, T>> edges;\n\n      ::std::vector<T>\
    \ perm(this->size());\n      ::std::iota(perm.begin(), perm.end(), 0);\n     \
    \ for (::std::size_t i = 0; i + 1 < this->size(); ++i) {\n        const auto x\
    \ = ::std::uniform_int_distribution<::std::size_t>(0, this->size() - i - 2)(engine);\n\
    \        const auto y = ::std::uniform_int_distribution<::std::size_t>(0, this->size()\
    \ - 1)(engine);\n        ::std::swap(perm[i + 1], perm[i + 1 + x]);\n        if\
    \ (y < i + 1) ::std::swap(perm[i], perm[y]);\n        edges.emplace_back(perm[i],\
    \ perm[i + 1]);\n      }\n\n      return edges;\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/random_tree.hpp
  requiredBy: []
  timestamp: '2022-07-09 11:13:10+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/random_tree.test.cpp
documentation_of: tools/random_tree.hpp
layout: document
title: Random tree generator
---

It will generate random trees.

### References
- [あんたさんはTwitterを使っています: 「@DEGwer3456 https://t.co/iKbySxrK2D できました」 / Twitter](https://twitter.com/anta_prg/status/869633557362163712)

### License
- unknown

### Author
- anta

## Constructor
```cpp
random_tree<T> dist(std::size_t n);
```

It creates a generator to generate random trees with $n$ vertices.
The type parameter `<T>` will be used as the type of vertex numbers.

### Constraints
- $n \geq 1$

### Time Complexity
- $O(1)$

## size
```cpp
std::size_t dist.size();
```

It returns $n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator()
```cpp
template <typename R>
std::vector<std::pair<T, T>> dist.operator()(R& engine);
```

It returns edges of a randomly generated tree with $n$ vertices.

### Constraints
- `engine` is a pseudorandom number generator.

### Time Complexity
- $O(n)$
