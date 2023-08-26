---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/wavelet_matrix.hpp
    title: Wavelet matrix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/wavelet_matrix/kth_smallest.test.cpp
    title: tests/wavelet_matrix/kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/wavelet_matrix/next_points.test.cpp
    title: tests/wavelet_matrix/next_points.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/wavelet_matrix/prev_points.test.cpp
    title: tests/wavelet_matrix/prev_points.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/wavelet_matrix/range_freq.test.cpp
    title: tests/wavelet_matrix/range_freq.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/wavelet_matrix/range_prod.test.cpp
    title: tests/wavelet_matrix/range_prod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://nyaannyaan.github.io/library/data-structure-2d/wavelet-matrix.hpp.html
  bundledCode: "#line 1 \"tools/bit_vector.hpp\"\n\n\n\n#include <cstdint>\n#include\
    \ <vector>\n#include <immintrin.h>\n\n// Source: https://nyaannyaan.github.io/library/data-structure-2d/wavelet-matrix.hpp.html\n\
    // License: CC0 1.0 Universal\n// Author: Nyaan\n\nnamespace tools {\n  class\
    \ bit_vector {\n  private:\n    using u32 = ::std::uint32_t;\n    using i64 =\
    \ ::std::int64_t;\n    using u64 = ::std::uint64_t;\n\n    static constexpr u32\
    \ w = 64;\n    ::std::vector<u64> m_block;\n    ::std::vector<u32> m_count;\n\
    \    u32 m_size, m_zeros;\n\n  public:\n    bit_vector() {}\n    explicit bit_vector(int\
    \ _n) { init(_n); }\n    __attribute__((optimize(\"O3\", \"unroll-loops\"))) void\
    \ init(int _n) {\n      m_size = m_zeros = _n;\n      m_block.resize(m_size /\
    \ w + 1, 0);\n      m_count.resize(m_block.size(), 0);\n    }\n\n    u32 size()\
    \ const { return m_size; }\n    inline u32 get(u32 i) const { return u32(m_block[i\
    \ / w] >> (i % w)) & 1u; }\n    inline void set(u32 i) { m_block[i / w] |= 1LL\
    \ << (i % w); }\n\n    __attribute__((target(\"popcnt\"))) void build() {\n  \
    \    for (u32 i = 1; i < m_block.size(); ++i)\n        m_count[i] = m_count[i\
    \ - 1] + _mm_popcnt_u64(m_block[i - 1]);\n      m_zeros = rank0(m_size);\n   \
    \ }\n\n    u32 zeros() const { return m_zeros; }\n    inline u32 rank0(u32 i)\
    \ const { return i - rank1(i); }\n    __attribute__((target(\"bmi2,popcnt\")))\
    \ inline u32 rank1(u32 i) const {\n      return m_count[i / w] + _mm_popcnt_u64(_bzhi_u64(m_block[i\
    \ / w], i % w));\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_BIT_VECTOR_HPP\n#define TOOLS_BIT_VECTOR_HPP\n\n#include <cstdint>\n\
    #include <vector>\n#include <immintrin.h>\n\n// Source: https://nyaannyaan.github.io/library/data-structure-2d/wavelet-matrix.hpp.html\n\
    // License: CC0 1.0 Universal\n// Author: Nyaan\n\nnamespace tools {\n  class\
    \ bit_vector {\n  private:\n    using u32 = ::std::uint32_t;\n    using i64 =\
    \ ::std::int64_t;\n    using u64 = ::std::uint64_t;\n\n    static constexpr u32\
    \ w = 64;\n    ::std::vector<u64> m_block;\n    ::std::vector<u32> m_count;\n\
    \    u32 m_size, m_zeros;\n\n  public:\n    bit_vector() {}\n    explicit bit_vector(int\
    \ _n) { init(_n); }\n    __attribute__((optimize(\"O3\", \"unroll-loops\"))) void\
    \ init(int _n) {\n      m_size = m_zeros = _n;\n      m_block.resize(m_size /\
    \ w + 1, 0);\n      m_count.resize(m_block.size(), 0);\n    }\n\n    u32 size()\
    \ const { return m_size; }\n    inline u32 get(u32 i) const { return u32(m_block[i\
    \ / w] >> (i % w)) & 1u; }\n    inline void set(u32 i) { m_block[i / w] |= 1LL\
    \ << (i % w); }\n\n    __attribute__((target(\"popcnt\"))) void build() {\n  \
    \    for (u32 i = 1; i < m_block.size(); ++i)\n        m_count[i] = m_count[i\
    \ - 1] + _mm_popcnt_u64(m_block[i - 1]);\n      m_zeros = rank0(m_size);\n   \
    \ }\n\n    u32 zeros() const { return m_zeros; }\n    inline u32 rank0(u32 i)\
    \ const { return i - rank1(i); }\n    __attribute__((target(\"bmi2,popcnt\")))\
    \ inline u32 rank1(u32 i) const {\n      return m_count[i / w] + _mm_popcnt_u64(_bzhi_u64(m_block[i\
    \ / w], i % w));\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/bit_vector.hpp
  requiredBy:
  - tools/wavelet_matrix.hpp
  timestamp: '2023-06-25 00:33:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/wavelet_matrix/range_freq.test.cpp
  - tests/wavelet_matrix/next_points.test.cpp
  - tests/wavelet_matrix/kth_smallest.test.cpp
  - tests/wavelet_matrix/range_prod.test.cpp
  - tests/wavelet_matrix/prev_points.test.cpp
documentation_of: tools/bit_vector.hpp
layout: document
title: Bit vector
---

It is a bit vector.

### License
- CC0 1.0 Universal

### Author
- Nyaan

## Constructor
```cpp
bit_vector bv(int n);
```

It creates a bit vector of length $n$ filled with $0$.

### Constraints
- $n \geq 0$

### Time Complexity
- $O(n)$

## init
```cpp
void bv.init(int n);
```

It makes `bv` a bit vector of length $n$ filled with $0$.

### Constraints
- $n \geq 0$

### Time Complexity
- $O(n)$

## size
```cpp
std::uint32_t bv.size();
```

It returns $n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## get
```cpp
std::uint32_t bv.get(std::uint32_t i);
```

It returns the $i$-th bit of the bit vector. (i.e., $0$ or $1$)

### Constraints
- $0 \leq i < n$

### Time Complexity
- $O(1)$

## set
```cpp
void bv.set(std::uint32_t i);
```

It updates the $i$-th bit of the bit vector to $1$.

### Constraints
- $0 \leq i < n$

### Time Complexity
- $O(1)$

## build
```cpp
void bv.build();
```

It builts the internal auxiliary data structure for the `rank` operation.

### Constraints
- None

### Time Complexity
- $O(n)$

## zeros
```cpp
std::uint32_t bv.zeros();
```

It returns the number of zero bits in the bit vector.

### Constraints
- `bv.build()` has been called ever.
- `bv.init()` has not been called after the last call of `bv.build()`.
- `bv.set()` has not been called after the last call of `bv.build()`.

### Time Complexity
- $O(1)$

## rank0
```cpp
std::uint32_t bv.rank0(std::uint32_t r);
```

It returns $\|\\{i \in \mathbb{N} \mid 0 \leq i < r \land \mathrm{bv.get}(i) = 0\\}\|$.

### Constraints
- $0 \leq r \leq n$
- `bv.build()` has been called ever.
- `bv.init()` has not been called after the last call of `bv.build()`.
- `bv.set()` has not been called after the last call of `bv.build()`.

### Time Complexity
- $O(1)$

## rank1
```cpp
std::uint32_t bv.rank1(std::uint32_t r);
```

It returns $\|\\{i \in \mathbb{N} \mid 0 \leq i < r \land \mathrm{bv.get}(i) = 1\\}\|$.

### Constraints
- $0 \leq r \leq n$
- `bv.build()` has been called ever.
- `bv.init()` has not been called after the last call of `bv.build()`.
- `bv.set()` has not been called after the last call of `bv.build()`.

### Time Complexity
- $O(1)$
