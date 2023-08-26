---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: tools/divisors.hpp
    title: List all divisors
  - icon: ':x:'
    path: tools/extended_lucas.hpp
    title: Extended Lucas' theorem
  - icon: ':x:'
    path: tools/tetration_mod.hpp
    title: $x \uparrow\uparrow y \pmod{M}$
  - icon: ':x:'
    path: tools/totient.hpp
    title: Euler's totient function
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/divisors.test.cpp
    title: tests/divisors.test.cpp
  - icon: ':x:'
    path: tests/extended_lucas.test.cpp
    title: tests/extended_lucas.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/run_length.test.cpp
    title: tests/run_length.test.cpp
  - icon: ':x:'
    path: tests/tetration_mod.test.cpp
    title: tests/tetration_mod.test.cpp
  - icon: ':x:'
    path: tests/totient.test.cpp
    title: tests/totient.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/run_length.hpp\"\n\n\n\n#include <iterator>\n#include\
    \ <cstddef>\n#include <utility>\n#include <cstdint>\n\nnamespace tools {\n  template\
    \ <typename InputIterator, typename OutputIterator>\n  void run_length(const InputIterator&\
    \ begin, const InputIterator& end, OutputIterator result) {\n    using T = typename\
    \ ::std::iterator_traits<InputIterator>::value_type;\n    if (begin == end) return;\n\
    \n    ::std::pair<T, ::std::size_t> prev;\n    for (auto [it, breaks] = ::std::make_pair(begin,\
    \ false); !breaks; breaks = it == end, it = ::std::next(it, breaks ? 0 : 1)) {\n\
    \      bool flg1, flg2;\n      if (it == begin) {\n        flg1 = false;\n   \
    \     flg2 = true;\n      } else if (it == end) {\n        flg1 = true;\n    \
    \    flg2 = false;\n      } else if (*it != prev.first) {\n        flg1 = true;\n\
    \        flg2 = true;\n      } else {\n        flg1 = false;\n        flg2 = false;\n\
    \      }\n      if (flg1 || flg2) {\n        if (flg1) {\n          *result =\
    \ prev;\n          ++result;\n        }\n        if (flg2) {\n          prev.first\
    \ = *it;\n          prev.second = 1;\n        }\n      } else {\n        ++prev.second;\n\
    \      }\n    }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_RUN_LENGTH_HPP\n#define TOOLS_RUN_LENGTH_HPP\n\n#include <iterator>\n\
    #include <cstddef>\n#include <utility>\n#include <cstdint>\n\nnamespace tools\
    \ {\n  template <typename InputIterator, typename OutputIterator>\n  void run_length(const\
    \ InputIterator& begin, const InputIterator& end, OutputIterator result) {\n \
    \   using T = typename ::std::iterator_traits<InputIterator>::value_type;\n  \
    \  if (begin == end) return;\n\n    ::std::pair<T, ::std::size_t> prev;\n    for\
    \ (auto [it, breaks] = ::std::make_pair(begin, false); !breaks; breaks = it ==\
    \ end, it = ::std::next(it, breaks ? 0 : 1)) {\n      bool flg1, flg2;\n     \
    \ if (it == begin) {\n        flg1 = false;\n        flg2 = true;\n      } else\
    \ if (it == end) {\n        flg1 = true;\n        flg2 = false;\n      } else\
    \ if (*it != prev.first) {\n        flg1 = true;\n        flg2 = true;\n     \
    \ } else {\n        flg1 = false;\n        flg2 = false;\n      }\n      if (flg1\
    \ || flg2) {\n        if (flg1) {\n          *result = prev;\n          ++result;\n\
    \        }\n        if (flg2) {\n          prev.first = *it;\n          prev.second\
    \ = 1;\n        }\n      } else {\n        ++prev.second;\n      }\n    }\n  }\n\
    }\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/run_length.hpp
  requiredBy:
  - tools/extended_lucas.hpp
  - tools/divisors.hpp
  - tools/totient.hpp
  - tools/tetration_mod.hpp
  timestamp: '2022-10-08 19:22:04+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/run_length.test.cpp
  - tests/extended_lucas.test.cpp
  - tests/totient.test.cpp
  - tests/tetration_mod.test.cpp
  - tests/divisors.test.cpp
documentation_of: tools/run_length.hpp
layout: document
title: Run-length encoding
---

```cpp
template <typename InputIterator, typename OutputIterator>
void run_length(InputIterator begin, InputIterator end, OutputIterator result);
```

It replaces consecutive elements to a pair of the element and the number of occurrences, and stores the pairs with such a format to `result`. 

## Constraints
- None

## Time Complexity
- $O(N)$ where $N$ is `end` - `begin`.

## License
- CC0

## Author
- anqooqie
