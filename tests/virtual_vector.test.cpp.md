---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':question:'
    path: tools/virtual_vector.hpp
    title: Lazy evaluation read-only std::vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"tests/virtual_vector.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#include <array>\n#include <cstddef>\n#include <vector>\n\
    #line 1 \"tools/assert_that.hpp\"\n\n\n\n#line 5 \"tools/assert_that.hpp\"\n#include\
    \ <cstdlib>\n\n#define assert_that_impl(cond, file, line, func) do {\\\n  if (!cond)\
    \ {\\\n    ::std::cerr << file << ':' << line << \": \" << func << \": Assertion\
    \ `\" << #cond << \"' failed.\" << '\\n';\\\n    ::std::exit(EXIT_FAILURE);\\\n\
    \  }\\\n} while (false)\n#define assert_that(...) assert_that_impl((__VA_ARGS__),\
    \ __FILE__, __LINE__, __func__)\n\n\n#line 1 \"tools/virtual_vector.hpp\"\n\n\n\
    \n#line 5 \"tools/virtual_vector.hpp\"\n#include <type_traits>\n#include <memory>\n\
    #include <iterator>\n#include <cassert>\n#include <algorithm>\n\nnamespace tools\
    \ {\n  template <typename F>\n  class virtual_vector {\n  public:\n    using size_type\
    \ = ::std::size_t;\n\n    class iterator {\n      const virtual_vector<F> *m_parent;\n\
    \      size_type m_i;\n\n    public:\n      using reference = decltype(::std::declval<F>()(::std::declval<size_type>()));\n\
    \      using value_type = ::std::remove_const_t<::std::remove_reference_t<reference>>;\n\
    \      using difference_type = ::std::ptrdiff_t;\n      using pointer = const\
    \ value_type*;\n      using iterator_category = ::std::random_access_iterator_tag;\n\
    \n      iterator() = default;\n      iterator(const virtual_vector<F> * const\
    \ parent, const size_type i) : m_parent(parent), m_i(i) {\n      }\n\n      reference\
    \ operator*() const {\n        return (*this->m_parent)[this->m_i];\n      }\n\
    \      pointer operator->() const {\n        return &(*(*this));\n      }\n\n\
    \      iterator& operator++() {\n        ++this->m_i;\n        return *this;\n\
    \      }\n      iterator operator++(int) {\n        const auto self = *this;\n\
    \        ++*this;\n        return self;\n      }\n      iterator& operator--()\
    \ {\n        --this->m_i;\n        return *this;\n      }\n      iterator operator--(int)\
    \ {\n        const auto self = *this;\n        --*this;\n        return self;\n\
    \      }\n      iterator& operator+=(const difference_type n) {\n        this->m_i\
    \ += n;\n        return *this;\n      }\n      iterator& operator-=(const difference_type\
    \ n) {\n        this->m_i -= n;\n        return *this;\n      }\n      friend\
    \ iterator operator+(const iterator self, const difference_type n) {\n       \
    \ return iterator(self.m_parent, self.m_i + n);\n      }\n      friend iterator\
    \ operator+(const difference_type n, const iterator self) {\n        return self\
    \ + n;\n      }\n      friend iterator operator-(const iterator self, const difference_type\
    \ n) {\n        return iterator(self.m_parent, self.m_i - n);\n      }\n     \
    \ friend difference_type operator-(const iterator lhs, const iterator rhs) {\n\
    \        assert(lhs.m_parent == rhs.m_parent);\n        return static_cast<difference_type>(lhs.m_i)\
    \ - static_cast<difference_type>(rhs.m_i);\n      }\n      reference operator[](const\
    \ difference_type n) const {\n        return *(*this + n);\n      }\n\n      friend\
    \ bool operator==(const iterator lhs, const iterator rhs) {\n        assert(lhs.m_parent\
    \ == rhs.m_parent);\n        return lhs.m_i == rhs.m_i;\n      }\n      friend\
    \ bool operator!=(const iterator lhs, const iterator rhs) {\n        assert(lhs.m_parent\
    \ == rhs.m_parent);\n        return lhs.m_i != rhs.m_i;\n      }\n      friend\
    \ bool operator<(const iterator lhs, const iterator rhs) {\n        assert(lhs.m_parent\
    \ == rhs.m_parent);\n        return lhs.m_i < rhs.m_i;\n      }\n      friend\
    \ bool operator<=(const iterator lhs, const iterator rhs) {\n        assert(lhs.m_parent\
    \ == rhs.m_parent);\n        return lhs.m_i <= rhs.m_i;\n      }\n      friend\
    \ bool operator>(const iterator lhs, const iterator rhs) {\n        assert(lhs.m_parent\
    \ == rhs.m_parent);\n        return lhs.m_i > rhs.m_i;\n      }\n      friend\
    \ bool operator>=(const iterator lhs, const iterator rhs) {\n        assert(lhs.m_parent\
    \ == rhs.m_parent);\n        return lhs.m_i >= rhs.m_i;\n      }\n    };\n\n \
    \   using const_reference = decltype(::std::declval<F>()(::std::declval<size_type>()));\n\
    \    using value_type = ::std::remove_const_t<::std::remove_reference_t<const_reference>>;\n\
    \    using reference = value_type&;\n    using const_iterator = iterator;\n  \
    \  using difference_type = ::std::ptrdiff_t;\n    using allocator_type = ::std::allocator<value_type>;\n\
    \    using pointer = value_type*;\n    using const_pointer = const value_type*;\n\
    \    using reverse_iterator = ::std::reverse_iterator<iterator>;\n    using const_reverse_iterator\
    \ = ::std::reverse_iterator<const_iterator>;\n\n  private:\n    size_type m_size;\n\
    \    F m_selector;\n\n  public:\n    virtual_vector() = default;\n    virtual_vector(const\
    \ size_type n, const F& selector) : m_size(n), m_selector(selector) {\n    }\n\
    \n    iterator begin() noexcept { return iterator(this, 0); }\n    const_iterator\
    \ begin() const noexcept { return const_iterator(this, 0); }\n    const_iterator\
    \ cbegin() const noexcept { return const_iterator(this, 0); }\n    iterator end()\
    \ noexcept { return iterator(this, this->size()); }\n    const_iterator end()\
    \ const noexcept { return const_iterator(this, this->size()); }\n    const_iterator\
    \ cend() const noexcept { return const_iterator(this, this->size()); }\n    reverse_iterator\
    \ rbegin() noexcept { return ::std::make_reverse_iterator(this->end()); }\n  \
    \  const_reverse_iterator rbegin() const noexcept { return ::std::make_reverse_iterator(this->end());\
    \ }\n    const_reverse_iterator crbegin() const noexcept { return ::std::make_reverse_iterator(this->cend());\
    \ }\n    reverse_iterator rend() noexcept { return ::std::make_reverse_iterator(this->begin());\
    \ }\n    const_reverse_iterator rend() const noexcept { return ::std::make_reverse_iterator(this->begin());\
    \ }\n    const_reverse_iterator crend() const noexcept { return ::std::make_reverse_iterator(this->cbegin());\
    \ }\n\n    size_type size() const noexcept { return this->m_size; }\n    bool\
    \ empty() const noexcept { return this->size() == 0; }\n\n    const_reference\
    \ operator[](const size_type n) const { assert(n < this->size()); return this->m_selector(n);\
    \ }\n    const_reference at(const size_type n) const { return (*this)[n]; }\n\
    \    const_reference front() const { return *this->begin(); }\n    const_reference\
    \ back() const { return *this->rbegin(); }\n\n    template <typename G>\n    friend\
    \ bool operator==(const virtual_vector<F>& x, const virtual_vector<G>& y) { return\
    \ ::std::equal(x.begin(), x.end(), y.begin(), y.end()); }\n    template <typename\
    \ G>\n    friend bool operator!=(const virtual_vector<F>& x, const virtual_vector<G>&\
    \ y) { return !(x == y); }\n    template <typename G>\n    friend bool operator<(const\
    \ virtual_vector<F>& x, const virtual_vector<G>& y) { return ::std::lexicographical_compare(x.begin(),\
    \ x.end(), y.begin(), y.end()); }\n    template <typename G>\n    friend bool\
    \ operator<=(const virtual_vector<F>& x, const virtual_vector<G>& y) { return\
    \ !(x > y); }\n    template <typename G>\n    friend bool operator>(const virtual_vector<F>&\
    \ x, const virtual_vector<G>& y) { return y < x; }\n    template <typename G>\n\
    \    friend bool operator>=(const virtual_vector<F>& x, const virtual_vector<G>&\
    \ y) { return !(x < y); }\n  };\n}\n\n\n#line 9 \"tests/virtual_vector.test.cpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  std::array<int, 5> a{1, 2, 3, 4, 5};\n  const tools::virtual_vector v(5, [a](const\
    \ std::size_t i) -> const int& { return a[i]; });\n  assert_that(std::equal(v.begin(),\
    \ v.end(), a.begin(), a.end()));\n\n  std::vector<int> b{1, 2, 3, 4, 5};\n  const\
    \ tools::virtual_vector u(5, [b](const std::size_t i) -> const int& { return b[i];\
    \ });\n  assert_that(v == u);\n\n  std::cout << \"Hello World\" << '\\n';\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include <array>\n#include <cstddef>\n#include <vector>\n\
    #include \"tools/assert_that.hpp\"\n#include \"tools/virtual_vector.hpp\"\n\n\
    int main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  std::array<int, 5> a{1, 2, 3, 4, 5};\n  const tools::virtual_vector v(5, [a](const\
    \ std::size_t i) -> const int& { return a[i]; });\n  assert_that(std::equal(v.begin(),\
    \ v.end(), a.begin(), a.end()));\n\n  std::vector<int> b{1, 2, 3, 4, 5};\n  const\
    \ tools::virtual_vector u(5, [b](const std::size_t i) -> const int& { return b[i];\
    \ });\n  assert_that(v == u);\n\n  std::cout << \"Hello World\" << '\\n';\n  return\
    \ 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/virtual_vector.hpp
  isVerificationFile: true
  path: tests/virtual_vector.test.cpp
  requiredBy: []
  timestamp: '2024-08-31 13:46:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/virtual_vector.test.cpp
layout: document
redirect_from:
- /verify/tests/virtual_vector.test.cpp
- /verify/tests/virtual_vector.test.cpp.html
title: tests/virtual_vector.test.cpp
---
