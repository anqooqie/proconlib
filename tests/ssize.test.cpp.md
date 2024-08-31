---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':heavy_check_mark:'
    path: tools/binary_heap.hpp
    title: Binary heap
  - icon: ':question:'
    path: tools/ceil_log2.hpp
    title: $\left\lceil \log_2(x) \right\rceil$
  - icon: ':question:'
    path: tools/pow2.hpp
    title: $2^x$
  - icon: ':question:'
    path: tools/ssize.hpp
    title: Polyfill of std::ssize
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"tests/ssize.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#line 1 \"tools/assert_that.hpp\"\n\n\n\n#line 5 \"tools/assert_that.hpp\"\
    \n#include <cstdlib>\n\n#define assert_that_impl(cond, file, line, func) do {\\\
    \n  if (!cond) {\\\n    ::std::cerr << file << ':' << line << \": \" << func <<\
    \ \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\n    ::std::exit(EXIT_FAILURE);\\\
    \n  }\\\n} while (false)\n#define assert_that(...) assert_that_impl((__VA_ARGS__),\
    \ __FILE__, __LINE__, __func__)\n\n\n#line 1 \"tools/binary_heap.hpp\"\n\n\n\n\
    #include <functional>\n#include <type_traits>\n#include <unordered_map>\n#include\
    \ <cstddef>\n#include <vector>\n#include <utility>\n#include <algorithm>\n#include\
    \ <limits>\n#include <cassert>\n#line 14 \"tools/binary_heap.hpp\"\n#include <string>\n\
    #line 1 \"tools/pow2.hpp\"\n\n\n\n#line 6 \"tools/pow2.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(1) << x;\n  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 1 \"tools/ceil_log2.hpp\"\
    \n\n\n\n#line 7 \"tools/ceil_log2.hpp\"\n#include <tuple>\n#include <array>\n\
    #include <cstdint>\n\n// Source: https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567\n\
    // License: CC BY-SA 3.0\n// Author: dgobbi\n\nnamespace tools {\n\n  template\
    \ <typename T>\n  T ceil_log2(T x) {\n    static_assert(::std::is_integral_v<T>);\n\
    \    assert(x > 0);\n    if constexpr (::std::is_signed_v<T>) {\n      return\
    \ static_cast<T>(::tools::ceil_log2<::std::make_unsigned_t<T>>(x));\n    } else\
    \ {\n      const auto log2 = [](const int w) {\n        if (w == 8) return 3;\n\
    \        if (w == 16) return 4;\n        if (w == 32) return 5;\n        if (w\
    \ == 64) return 6;\n        return -1;\n      };\n      static_assert(log2(::std::numeric_limits<T>::digits)\
    \ >= 0);\n\n      constexpr auto t = ::std::make_tuple(\n        ::std::array<::std::uint8_t,\
    \ 3>({\n          UINT8_C(0xf0),\n          UINT8_C(0x0c),\n          UINT8_C(0x02)\n\
    \        }),\n        ::std::array<::std::uint16_t, 4>({\n          UINT16_C(0xff00),\n\
    \          UINT16_C(0x00f0),\n          UINT16_C(0x000c),\n          UINT16_C(0x0002)\n\
    \        }),\n        ::std::array<::std::uint32_t, 5>({\n          UINT32_C(0xffff0000),\n\
    \          UINT32_C(0x0000ff00),\n          UINT32_C(0x000000f0),\n          UINT32_C(0x0000000c),\n\
    \          UINT32_C(0x00000002)\n        }),\n        ::std::array<::std::uint64_t,\
    \ 6>({\n          UINT64_C(0xffffffff00000000),\n          UINT64_C(0x00000000ffff0000),\n\
    \          UINT64_C(0x000000000000ff00),\n          UINT64_C(0x00000000000000f0),\n\
    \          UINT64_C(0x000000000000000c),\n          UINT64_C(0x0000000000000002)\n\
    \        })\n      );\n\n      T y = (((x & (x - 1)) == 0) ? 0 : 1);\n      T\
    \ j = ::std::numeric_limits<T>::digits / 2;\n\n      for (const auto t_i : ::std::get<log2(::std::numeric_limits<T>::digits)\
    \ - 3>(t)) {\n        T k = (((x & t_i) == 0) ? 0 : j);\n        y += k;\n   \
    \     x >>= k;\n        j >>= 1;\n      }\n\n      return y;\n    }\n  }\n}\n\n\
    \n#line 17 \"tools/binary_heap.hpp\"\n\nnamespace tools {\n\n  template <class\
    \ Key, class Priority, class Compare = ::std::less<Priority>, bool UseVectorToStoreKeys\
    \ = ::std::is_integral_v<Key>>\n  class binary_heap {\n  private:\n    Compare\
    \ m_compare;\n    ::std::unordered_map<Key, ::std::size_t> m_heap_index;\n   \
    \ ::std::vector<::std::size_t> m_heap_index_fast;\n    ::std::vector<::std::pair<Key,\
    \ Priority>> m_heap;\n    ::std::size_t m_size;\n\n    void swap(::std::size_t\
    \ x, ::std::size_t y) {\n      if constexpr (UseVectorToStoreKeys) {\n       \
    \ ::std::swap(this->m_heap_index_fast[this->m_heap[x].first], this->m_heap_index_fast[this->m_heap[y].first]);\n\
    \      } else {\n        ::std::swap(this->m_heap_index[this->m_heap[x].first],\
    \ this->m_heap_index[this->m_heap[y].first]);\n      }\n      ::std::swap(this->m_heap[x],\
    \ this->m_heap[y]);\n    }\n\n    void upheap(::std::size_t i) {\n      for (;\
    \ i > 1 && this->m_compare(this->m_heap[i / 2].second, this->m_heap[i].second);\
    \ i /= 2) {\n        this->swap(i / 2, i);\n      }\n    }\n\n    void downheap(::std::size_t\
    \ i) {\n      auto calc_next_i = [this](const ::std::size_t self) {\n        const\
    \ std::array<::std::size_t, 3> targets = {self, self * 2, self * 2 + 1};\n   \
    \     return *::std::max_element(\n          targets.begin(),\n          std::next(targets.begin(),\
    \ self * 2 + 1 <= this->m_size ? 3 : self * 2 <= this->m_size ? 2 : 1),\n    \
    \      [this](const ::std::size_t x, const ::std::size_t y) {\n            return\
    \ this->m_compare(this->m_heap[x].second, this->m_heap[y].second);\n         \
    \ }\n        );\n      };\n      for (::std::size_t next_i; i != (next_i = calc_next_i(i));\
    \ i = next_i) {\n        this->swap(i, next_i);\n      }\n    }\n\n    ::std::size_t\
    \ get_internal_index(const Key& k) const {\n      if constexpr (UseVectorToStoreKeys)\
    \ {\n        if (::std::size_t(k) < this->m_heap_index_fast.size()) {\n      \
    \    return this->m_heap_index_fast[k];\n        } else {\n          return ::std::numeric_limits<::std::size_t>::max();\n\
    \        }\n      } else {\n        if (const auto it = this->m_heap_index.find(k);\
    \ it != this->m_heap_index.end()) {\n          return it->second;\n        } else\
    \ {\n          return ::std::numeric_limits<::std::size_t>::max();\n        }\n\
    \      }\n    }\n\n  public:\n    explicit binary_heap(const Compare& compare\
    \ = Compare()) : m_compare(compare), m_heap_index(), m_heap_index_fast(), m_heap(1),\
    \ m_size(0) {\n    }\n    binary_heap(const binary_heap&) = default;\n    binary_heap(binary_heap&&)\
    \ = default;\n    ~binary_heap() = default;\n    binary_heap& operator=(const\
    \ binary_heap&) = default;\n    binary_heap& operator=(binary_heap&&) = default;\n\
    \n    bool empty() const noexcept {\n      return this->m_size == 0;\n    }\n\n\
    \    ::std::size_t size() const noexcept {\n      return this->m_size;\n    }\n\
    \n    const ::std::pair<Key, Priority>& top() const {\n      assert(!this->empty());\n\
    \      return this->m_heap[1];\n    }\n\n    bool contains(const Key& k) const\
    \ {\n      if constexpr (UseVectorToStoreKeys) {\n        if (::std::size_t(k)\
    \ < this->m_heap_index_fast.size()) {\n          return this->m_heap_index_fast[k]\
    \ != ::std::numeric_limits<::std::size_t>::max();\n        } else {\n        \
    \  return false;\n        }\n      } else {\n        return this->m_heap_index.find(k)\
    \ != this->m_heap_index.end();\n      }\n    }\n\n    Priority at(const Key& k)\
    \ const {\n      if constexpr (UseVectorToStoreKeys) {\n        return this->m_heap[this->m_heap_index_fast[k]].second;\n\
    \      } else {\n        return this->m_heap[this->m_heap_index.at(k)].second;\n\
    \      }\n    }\n\n    bool push(const ::std::pair<Key, Priority>& x) {\n    \
    \  ::std::size_t internal_index = this->get_internal_index(x.first);\n\n     \
    \ if (internal_index != ::std::numeric_limits<::std::size_t>::max()) {\n     \
    \   const Priority prev_priority = this->m_heap[internal_index].second;\n    \
    \    this->m_heap[internal_index].second = x.second;\n        if (this->m_compare(prev_priority,\
    \ x.second)) {\n          this->upheap(internal_index);\n        } else if (this->m_compare(x.second,\
    \ prev_priority)) {\n          this->downheap(internal_index);\n        }\n  \
    \    } else {\n        if (this->m_size + 1 == this->m_heap.size()) {\n      \
    \    this->m_heap.resize(this->m_heap.size() * 2);\n        }\n        ++this->m_size;\n\
    \n        if constexpr (UseVectorToStoreKeys) {\n          if (::std::size_t(x.first)\
    \ >= this->m_heap_index_fast.size()) {\n            this->m_heap_index_fast.resize(::tools::pow2(::tools::ceil_log2(x.first\
    \ + 1)), ::std::numeric_limits<::std::size_t>::max());\n          }\n        \
    \  this->m_heap_index_fast[x.first] = this->m_size;\n        } else {\n      \
    \    this->m_heap_index.emplace(x.first, this->m_size);\n        }\n        this->m_heap[this->m_size]\
    \ = x;\n        this->upheap(this->m_size);\n      }\n\n      return internal_index\
    \ == ::std::numeric_limits<::std::size_t>::max();\n    }\n\n    template <typename...\
    \ Args>\n    bool emplace(Args&&... args) {\n      return this->push(::std::make_pair(::std::forward<Args>(args)...));\n\
    \    }\n\n    void pop() {\n      assert(!this->empty());\n      const Key k =\
    \ this->m_heap[1].first;\n      if (this->m_size > 1) {\n        this->swap(1,\
    \ this->m_size);\n      }\n\n      if constexpr (UseVectorToStoreKeys) {\n   \
    \     this->m_heap_index_fast[k] = ::std::numeric_limits<::std::size_t>::max();\n\
    \      } else {\n        this->m_heap_index.erase(k);\n      }\n      --this->m_size;\n\
    \n      if (this->m_size >= 1) {\n        this->downheap(1);\n      }\n    }\n\
    \n    ::std::size_t erase(const Key& k) {\n      ::std::size_t internal_index\
    \ = this->get_internal_index(k);\n      if (internal_index == ::std::numeric_limits<::std::size_t>::max())\
    \ {\n        return 0;\n      }\n\n      const Priority prev_priority = this->m_heap[internal_index].second;\n\
    \      const Priority new_priority = this->m_heap[this->m_size].second;\n\n  \
    \    if (internal_index < this->m_size) {\n        this->swap(internal_index,\
    \ this->m_size);\n      }\n\n      if constexpr (UseVectorToStoreKeys) {\n   \
    \     this->m_heap_index_fast[k] = ::std::numeric_limits<::std::size_t>::max();\n\
    \      } else {\n        this->m_heap_index.erase(k);\n      }\n      --this->m_size;\n\
    \n      if (internal_index <= this->m_size) {\n        if (this->m_compare(prev_priority,\
    \ new_priority)) {\n          this->upheap(internal_index);\n        } else if\
    \ (this->m_compare(new_priority, prev_priority)) {\n          this->downheap(internal_index);\n\
    \        }\n      }\n\n      return 1;\n    }\n\n    friend ::std::ostream& operator<<(::std::ostream&\
    \ os, binary_heap& self) {\n      std::string delimiter = \"\";\n      os << '[';\n\
    \      for (::std::size_t i = 1; i <= self.m_size; ++i) {\n        os << delimiter\
    \ << '[' << self.m_heap[i].first << \", \" << self.m_heap[i].second << ']';\n\
    \        delimiter = \", \";\n      }\n      os << ']';\n      return os;\n  \
    \  }\n  };\n}\n\n\n#line 1 \"tools/ssize.hpp\"\n\n\n\n#line 6 \"tools/ssize.hpp\"\
    \n\nnamespace tools {\n\n  template <typename C>\n  constexpr auto ssize(const\
    \ C& c) -> ::std::common_type_t<::std::ptrdiff_t, ::std::make_signed_t<decltype(c.size())>>\
    \ {\n    return c.size();\n  }\n}\n\n\n#line 7 \"tests/ssize.test.cpp\"\n\nint\
    \ main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  assert_that(tools::ssize(std::vector<int>({1, 2, 3})) == 3);\n\n  tools::binary_heap<int,\
    \ int> heap;\n  heap.emplace(1, 1);\n  heap.emplace(2, 2);\n  heap.emplace(3,\
    \ 3);\n  assert_that(tools::ssize(heap) == 3);\n\n  std::cout << \"Hello World\"\
    \ << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include \"tools/assert_that.hpp\"\n#include \"tools/binary_heap.hpp\"\
    \n#include \"tools/ssize.hpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  assert_that(tools::ssize(std::vector<int>({1, 2, 3})) == 3);\n\n  tools::binary_heap<int,\
    \ int> heap;\n  heap.emplace(1, 1);\n  heap.emplace(2, 2);\n  heap.emplace(3,\
    \ 3);\n  assert_that(tools::ssize(heap) == 3);\n\n  std::cout << \"Hello World\"\
    \ << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/binary_heap.hpp
  - tools/pow2.hpp
  - tools/ceil_log2.hpp
  - tools/ssize.hpp
  isVerificationFile: true
  path: tests/ssize.test.cpp
  requiredBy: []
  timestamp: '2024-08-31 13:46:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/ssize.test.cpp
layout: document
redirect_from:
- /verify/tests/ssize.test.cpp
- /verify/tests/ssize.test.cpp.html
title: tests/ssize.test.cpp
---
