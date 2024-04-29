---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: tools/bell.hpp
    title: Bell numbers
  - icon: ':heavy_check_mark:'
    path: tools/stirling_1st.hpp
    title: Signed Stirling numbers of the first kind
  - icon: ':question:'
    path: tools/stirling_2nd.hpp
    title: Stirling numbers of the second kind
  - icon: ':question:'
    path: tools/twelvefold_way.hpp
    title: Twelvefold way
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bell/all.test.cpp
    title: tests/bell/all.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bell/consistent.test.cpp
    title: tests/bell/consistent.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bell/fixed_n.test.cpp
    title: tests/bell/fixed_n.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/stirling_1st/consistent.test.cpp
    title: tests/stirling_1st/consistent.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/stirling_1st/fixed_k.test.cpp
    title: tests/stirling_1st/fixed_k.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/stirling_1st/fixed_n.test.cpp
    title: tests/stirling_1st/fixed_n.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/stirling_2nd/all.test.cpp
    title: tests/stirling_2nd/all.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/stirling_2nd/consistent.test.cpp
    title: tests/stirling_2nd/consistent.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/stirling_2nd/fixed_k.test.cpp
    title: tests/stirling_2nd/fixed_k.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/stirling_2nd/fixed_n.test.cpp
    title: tests/stirling_2nd/fixed_n.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/labeled_ball_labeled_box_at_least_1.test.cpp
    title: tests/twelvefold_way/labeled_ball_labeled_box_at_least_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/labeled_ball_labeled_box_at_most_1.test.cpp
    title: tests/twelvefold_way/labeled_ball_labeled_box_at_most_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/labeled_ball_labeled_box_unrestricted.test.cpp
    title: tests/twelvefold_way/labeled_ball_labeled_box_unrestricted.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/labeled_ball_unlabeled_box_at_least_1.test.cpp
    title: tests/twelvefold_way/labeled_ball_unlabeled_box_at_least_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/labeled_ball_unlabeled_box_at_most_1.test.cpp
    title: tests/twelvefold_way/labeled_ball_unlabeled_box_at_most_1.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/labeled_ball_unlabeled_box_unrestricted.test.cpp
    title: tests/twelvefold_way/labeled_ball_unlabeled_box_unrestricted.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/unlabeled_ball_labeled_box_at_least_1.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_labeled_box_at_least_1.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/unlabeled_ball_labeled_box_at_most_1.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_labeled_box_at_most_1.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/unlabeled_ball_labeled_box_unrestricted.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_labeled_box_unrestricted.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_least_1.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_least_1.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_most_1.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_most_1.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/unlabeled_ball_unlabeled_box_unrestricted.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_unlabeled_box_unrestricted.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/virtual_vector.test.cpp
    title: tests/virtual_vector.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/virtual_vector.hpp\"\n\n\n\n#include <cstddef>\n#include\
    \ <type_traits>\n#include <memory>\n#include <iterator>\n#include <cassert>\n\
    #include <algorithm>\n\nnamespace tools {\n  template <typename F>\n  class virtual_vector\
    \ {\n  public:\n    using size_type = ::std::size_t;\n\n    class iterator {\n\
    \      const virtual_vector<F> *m_parent;\n      size_type m_i;\n\n    public:\n\
    \      using reference = decltype(::std::declval<F>()(::std::declval<size_type>()));\n\
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
    \ y) { return !(x < y); }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_VIRTUAL_VECTOR_HPP\n#define TOOLS_VIRTUAL_VECTOR_HPP\n\n#include\
    \ <cstddef>\n#include <type_traits>\n#include <memory>\n#include <iterator>\n\
    #include <cassert>\n#include <algorithm>\n\nnamespace tools {\n  template <typename\
    \ F>\n  class virtual_vector {\n  public:\n    using size_type = ::std::size_t;\n\
    \n    class iterator {\n      const virtual_vector<F> *m_parent;\n      size_type\
    \ m_i;\n\n    public:\n      using reference = decltype(::std::declval<F>()(::std::declval<size_type>()));\n\
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
    \ y) { return !(x < y); }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/virtual_vector.hpp
  requiredBy:
  - tools/stirling_1st.hpp
  - tools/stirling_2nd.hpp
  - tools/twelvefold_way.hpp
  - tools/bell.hpp
  timestamp: '2024-04-20 12:05:28+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/stirling_2nd/all.test.cpp
  - tests/stirling_2nd/fixed_k.test.cpp
  - tests/stirling_2nd/consistent.test.cpp
  - tests/stirling_2nd/fixed_n.test.cpp
  - tests/virtual_vector.test.cpp
  - tests/stirling_1st/fixed_k.test.cpp
  - tests/stirling_1st/consistent.test.cpp
  - tests/stirling_1st/fixed_n.test.cpp
  - tests/bell/all.test.cpp
  - tests/bell/consistent.test.cpp
  - tests/bell/fixed_n.test.cpp
  - tests/twelvefold_way/labeled_ball_unlabeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/labeled_ball_unlabeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/labeled_ball_labeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/labeled_ball_labeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/labeled_ball_labeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/unlabeled_ball_labeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/unlabeled_ball_unlabeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/unlabeled_ball_labeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/labeled_ball_unlabeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/unlabeled_ball_labeled_box_at_most_1.test.cpp
documentation_of: tools/virtual_vector.hpp
layout: document
title: Lazy evaluation read-only std::vector
---

It is almost same as `const std::vector{f(0), f(1), ..., f(n - 1)}`, but evaluate values when needed.
Hence, the time taken to construct it can be $o(n)$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <typename F>
virtual_vector<F> v(std::size_t n, F f);
```

### Constraints
- $n \geq 0$
- $f$ takes `std::size_t` and returns `const T&` where `T` is any type.

### Time Complexity
- Same as the time taken to copy `f`

## Methods based on const std::vector&lt;T&gt;
```cpp
virtual_vector<F>::const_iterator v.begin();
virtual_vector<F>::const_iterator v.end();
virtual_vector<F>::const_iterator v.cbegin();
virtual_vector<F>::const_iterator v.cend();
virtual_vector<F>::const_reverse_iterator v.rbegin();
virtual_vector<F>::const_reverse_iterator v.rend();
virtual_vector<F>::const_reverse_iterator v.crbegin();
virtual_vector<F>::const_reverse_iterator v.crend();

std::size_t v.size();
bool v.empty();

const T& v.operator[](std::size_t i);
const T& v.at(std::size_t i);
const T& v.front();
const T& v.back();

bool operator==(virtual_vector<F> v, virtual_vector<G> u);
bool operator!=(virtual_vector<F> v, virtual_vector<G> u);
bool operator<(virtual_vector<F> v, virtual_vector<G> u);
bool operator<=(virtual_vector<F> v, virtual_vector<G> u);
bool operator>(virtual_vector<F> v, virtual_vector<G> u);
bool operator>=(virtual_vector<F> v, virtual_vector<G> u);
```

They are methods based on `const std::vector<T>`.

### Constraints
- Same as ones of `const std::vector<T>`

### Time Complexity
- Same as ones of `const std::vector<T>`
