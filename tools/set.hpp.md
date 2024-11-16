---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/set.test.cpp
    title: tests/set.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/set.hpp\"\n\n\n\n#include <functional>\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #include <ext/pb_ds/tree_policy.hpp>\n#include <ext/pb_ds/tag_and_trait.hpp>\n\
    #include <cstddef>\n#include <iterator>\n#include <initializer_list>\n#include\
    \ <utility>\n#include <algorithm>\n\nnamespace tools {\n  template <typename Key,\
    \ typename Compare = ::std::less<Key>>\n  class set {\n    using pbds_tree = ::__gnu_pbds::tree<Key,\
    \ ::__gnu_pbds::null_type, Compare, ::__gnu_pbds::rb_tree_tag, ::__gnu_pbds::tree_order_statistics_node_update>;\n\
    \n    pbds_tree m_set;\n\n  public:\n    using key_type = Key;\n    using value_type\
    \ = Key;\n    using key_compare = Compare;\n    using value_compare = Compare;\n\
    \    using reference = Key&;\n    using const_reference = const Key&;\n    using\
    \ iterator = typename pbds_tree::iterator;\n    using const_iterator = iterator;\n\
    \    using size_type = ::std::size_t;\n    using difference_type = ::std::ptrdiff_t;\n\
    \    using pointer = Key*;\n    using const_pointer = const Key*;\n    using reverse_iterator\
    \ = ::std::reverse_iterator<iterator>;\n    using const_reverse_iterator = reverse_iterator;\n\
    \n    explicit set(const Compare& comp = Compare()) : m_set(comp) {\n    }\n \
    \   template <typename InputIterator>\n    set(const InputIterator first, const\
    \ InputIterator last, const Compare& comp = Compare()) : set(comp) {\n      this->insert(first,\
    \ last);\n    }\n    set(const ::std::initializer_list<Key> init, const Compare&\
    \ comp = Compare()) : set(comp) {\n      this->insert(init);\n    }\n\n    iterator\
    \ begin() const {\n      return this->m_set.begin();\n    }\n    iterator cbegin()\
    \ const {\n      return this->begin();\n    }\n    iterator end() const {\n  \
    \    return this->m_set.end();\n    }\n    iterator cend() const {\n      return\
    \ this->end();\n    }\n    reverse_iterator rbegin() const {\n      return reverse_iterator(this->end());\n\
    \    }\n    reverse_iterator crbegin() const {\n      return this->rbegin();\n\
    \    }\n    reverse_iterator rend() const {\n      return reverse_iterator(this->begin());\n\
    \    }\n    reverse_iterator crend() const {\n      return this->rend();\n   \
    \ }\n\n    bool empty() const {\n      return this->m_set.empty();\n    }\n  \
    \  size_type size() const {\n      return this->m_set.size();\n    }\n    size_type\
    \ max_size() const {\n      return this->m_set.max_size();\n    }\n\n    void\
    \ clear() {\n      this->m_set.clear();\n    }\n    ::std::pair<iterator, bool>\
    \ insert(const Key& x) {\n      return this->m_set.insert(x);\n    }\n    iterator\
    \ insert([[maybe_unused]] const iterator position, const Key& x) {\n      return\
    \ this->insert(x).first;\n    }\n    template <typename InputIterator>\n    void\
    \ insert(const InputIterator first, const InputIterator last) {\n      for (auto\
    \ it = first; it != last; ++it) {\n        this->insert(*it);\n      }\n    }\n\
    \    void insert(const ::std::initializer_list<Key> init) {\n      for (const\
    \ auto& x : init) {\n        this->insert(x);\n      }\n    }\n    template <class...\
    \ Args>\n    ::std::pair<iterator, bool> emplace(Args&&... args) {\n      return\
    \ this->insert(Key(::std::forward<Args>(args)...));\n    }\n    template <class...\
    \ Args>\n    iterator emplace_hint([[maybe_unused]] const iterator hint, Args&&...\
    \ args) {\n      return this->emplace(::std::forward<Args>(args)...).first;\n\
    \    }\n    iterator erase(const iterator position) {\n      return this->m_set.erase(position);\n\
    \    }\n    size_type erase(const Key& x) {\n      return this->m_set.erase(x);\n\
    \    }\n    iterator erase(const iterator first, const iterator last) {\n    \
    \  const size_type n = ::std::distance(first, last);\n      auto it = first;\n\
    \      for (size_type i = 0; i < n; ++i) {\n        it = this->erase(it);\n  \
    \    }\n      return it;\n    }\n    void swap(::tools::set<Key, Compare>& st)\
    \ {\n      this->m_set.swap(st.m_set);\n    }\n    template <typename C2>\n  \
    \  void merge(::tools::set<Key, C2>& source) {\n      this->insert(source.begin(),\
    \ source.end());\n      source.clear();\n    }\n\n    size_type count(const Key&\
    \ x) const {\n      return this->contains(x);\n    }\n    iterator find(const\
    \ Key& x) const {\n      return this->m_set.find(x);\n    }\n    bool contains(const\
    \ Key& x) const {\n      return this->find(x) != this->end();\n    }\n    ::std::pair<iterator,\
    \ iterator> equal_range(const Key& x) const {\n      return ::std::make_pair(this->lower_bound(x),\
    \ this->upper_bound(x));\n    }\n    iterator lower_bound(const Key& x) const\
    \ {\n      return this->m_set.lower_bound(x);\n    }\n    iterator upper_bound(const\
    \ Key& x) const {\n      return this->m_set.upper_bound(x);\n    }\n\n    Compare\
    \ key_comp() const {\n      return this->m_set.get_cmp_fn();\n    }\n    Compare\
    \ value_comp() const {\n      return this->key_comp();\n    }\n\n    friend bool\
    \ operator==(const ::tools::set<Key, Compare>& x, const ::tools::set<Key, Compare>&\
    \ y) {\n      return ::std::equal(x.begin(), x.end(), y.begin(), y.end());\n \
    \   }\n    friend bool operator!=(const ::tools::set<Key, Compare>& x, const ::tools::set<Key,\
    \ Compare>& y) {\n      return !(x == y);\n    }\n    friend bool operator<(const\
    \ ::tools::set<Key, Compare>& x, const ::tools::set<Key, Compare>& y) {\n    \
    \  return ::std::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());\n\
    \    }\n    friend bool operator<=(const ::tools::set<Key, Compare>& x, const\
    \ ::tools::set<Key, Compare>& y) {\n      return !(y < x);\n    }\n    friend\
    \ bool operator>(const ::tools::set<Key, Compare>& x, const ::tools::set<Key,\
    \ Compare>& y) {\n      return y < x;\n    }\n    friend bool operator>=(const\
    \ ::tools::set<Key, Compare>& x, const ::tools::set<Key, Compare>& y) {\n    \
    \  return !(x < y);\n    }\n\n    iterator find_by_order(const size_type order)\
    \ const {\n      return this->m_set.find_by_order(order);\n    }\n    size_type\
    \ order_of_key(const Key& x) const {\n      return this->m_set.order_of_key(x);\n\
    \    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_SET_HPP\n#define TOOLS_SET_HPP\n\n#include <functional>\n#include\
    \ <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n#include\
    \ <ext/pb_ds/tag_and_trait.hpp>\n#include <cstddef>\n#include <iterator>\n#include\
    \ <initializer_list>\n#include <utility>\n#include <algorithm>\n\nnamespace tools\
    \ {\n  template <typename Key, typename Compare = ::std::less<Key>>\n  class set\
    \ {\n    using pbds_tree = ::__gnu_pbds::tree<Key, ::__gnu_pbds::null_type, Compare,\
    \ ::__gnu_pbds::rb_tree_tag, ::__gnu_pbds::tree_order_statistics_node_update>;\n\
    \n    pbds_tree m_set;\n\n  public:\n    using key_type = Key;\n    using value_type\
    \ = Key;\n    using key_compare = Compare;\n    using value_compare = Compare;\n\
    \    using reference = Key&;\n    using const_reference = const Key&;\n    using\
    \ iterator = typename pbds_tree::iterator;\n    using const_iterator = iterator;\n\
    \    using size_type = ::std::size_t;\n    using difference_type = ::std::ptrdiff_t;\n\
    \    using pointer = Key*;\n    using const_pointer = const Key*;\n    using reverse_iterator\
    \ = ::std::reverse_iterator<iterator>;\n    using const_reverse_iterator = reverse_iterator;\n\
    \n    explicit set(const Compare& comp = Compare()) : m_set(comp) {\n    }\n \
    \   template <typename InputIterator>\n    set(const InputIterator first, const\
    \ InputIterator last, const Compare& comp = Compare()) : set(comp) {\n      this->insert(first,\
    \ last);\n    }\n    set(const ::std::initializer_list<Key> init, const Compare&\
    \ comp = Compare()) : set(comp) {\n      this->insert(init);\n    }\n\n    iterator\
    \ begin() const {\n      return this->m_set.begin();\n    }\n    iterator cbegin()\
    \ const {\n      return this->begin();\n    }\n    iterator end() const {\n  \
    \    return this->m_set.end();\n    }\n    iterator cend() const {\n      return\
    \ this->end();\n    }\n    reverse_iterator rbegin() const {\n      return reverse_iterator(this->end());\n\
    \    }\n    reverse_iterator crbegin() const {\n      return this->rbegin();\n\
    \    }\n    reverse_iterator rend() const {\n      return reverse_iterator(this->begin());\n\
    \    }\n    reverse_iterator crend() const {\n      return this->rend();\n   \
    \ }\n\n    bool empty() const {\n      return this->m_set.empty();\n    }\n  \
    \  size_type size() const {\n      return this->m_set.size();\n    }\n    size_type\
    \ max_size() const {\n      return this->m_set.max_size();\n    }\n\n    void\
    \ clear() {\n      this->m_set.clear();\n    }\n    ::std::pair<iterator, bool>\
    \ insert(const Key& x) {\n      return this->m_set.insert(x);\n    }\n    iterator\
    \ insert([[maybe_unused]] const iterator position, const Key& x) {\n      return\
    \ this->insert(x).first;\n    }\n    template <typename InputIterator>\n    void\
    \ insert(const InputIterator first, const InputIterator last) {\n      for (auto\
    \ it = first; it != last; ++it) {\n        this->insert(*it);\n      }\n    }\n\
    \    void insert(const ::std::initializer_list<Key> init) {\n      for (const\
    \ auto& x : init) {\n        this->insert(x);\n      }\n    }\n    template <class...\
    \ Args>\n    ::std::pair<iterator, bool> emplace(Args&&... args) {\n      return\
    \ this->insert(Key(::std::forward<Args>(args)...));\n    }\n    template <class...\
    \ Args>\n    iterator emplace_hint([[maybe_unused]] const iterator hint, Args&&...\
    \ args) {\n      return this->emplace(::std::forward<Args>(args)...).first;\n\
    \    }\n    iterator erase(const iterator position) {\n      return this->m_set.erase(position);\n\
    \    }\n    size_type erase(const Key& x) {\n      return this->m_set.erase(x);\n\
    \    }\n    iterator erase(const iterator first, const iterator last) {\n    \
    \  const size_type n = ::std::distance(first, last);\n      auto it = first;\n\
    \      for (size_type i = 0; i < n; ++i) {\n        it = this->erase(it);\n  \
    \    }\n      return it;\n    }\n    void swap(::tools::set<Key, Compare>& st)\
    \ {\n      this->m_set.swap(st.m_set);\n    }\n    template <typename C2>\n  \
    \  void merge(::tools::set<Key, C2>& source) {\n      this->insert(source.begin(),\
    \ source.end());\n      source.clear();\n    }\n\n    size_type count(const Key&\
    \ x) const {\n      return this->contains(x);\n    }\n    iterator find(const\
    \ Key& x) const {\n      return this->m_set.find(x);\n    }\n    bool contains(const\
    \ Key& x) const {\n      return this->find(x) != this->end();\n    }\n    ::std::pair<iterator,\
    \ iterator> equal_range(const Key& x) const {\n      return ::std::make_pair(this->lower_bound(x),\
    \ this->upper_bound(x));\n    }\n    iterator lower_bound(const Key& x) const\
    \ {\n      return this->m_set.lower_bound(x);\n    }\n    iterator upper_bound(const\
    \ Key& x) const {\n      return this->m_set.upper_bound(x);\n    }\n\n    Compare\
    \ key_comp() const {\n      return this->m_set.get_cmp_fn();\n    }\n    Compare\
    \ value_comp() const {\n      return this->key_comp();\n    }\n\n    friend bool\
    \ operator==(const ::tools::set<Key, Compare>& x, const ::tools::set<Key, Compare>&\
    \ y) {\n      return ::std::equal(x.begin(), x.end(), y.begin(), y.end());\n \
    \   }\n    friend bool operator!=(const ::tools::set<Key, Compare>& x, const ::tools::set<Key,\
    \ Compare>& y) {\n      return !(x == y);\n    }\n    friend bool operator<(const\
    \ ::tools::set<Key, Compare>& x, const ::tools::set<Key, Compare>& y) {\n    \
    \  return ::std::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());\n\
    \    }\n    friend bool operator<=(const ::tools::set<Key, Compare>& x, const\
    \ ::tools::set<Key, Compare>& y) {\n      return !(y < x);\n    }\n    friend\
    \ bool operator>(const ::tools::set<Key, Compare>& x, const ::tools::set<Key,\
    \ Compare>& y) {\n      return y < x;\n    }\n    friend bool operator>=(const\
    \ ::tools::set<Key, Compare>& x, const ::tools::set<Key, Compare>& y) {\n    \
    \  return !(x < y);\n    }\n\n    iterator find_by_order(const size_type order)\
    \ const {\n      return this->m_set.find_by_order(order);\n    }\n    size_type\
    \ order_of_key(const Key& x) const {\n      return this->m_set.order_of_key(x);\n\
    \    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/set.hpp
  requiredBy: []
  timestamp: '2024-11-16 14:14:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/set.test.cpp
documentation_of: tools/set.hpp
layout: document
title: __gnu_pbds::tree, but more compatible with std::set
---

`tools::set<Key, Compare = std::less<Key>>` is almost like `__gnu_pbds::tree<Key, __gnu_pbds::null_type, Compare, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>`, but its interface is more compatible with `std::set<Key, Compare>`.

### Constraints
- It requires libstdc++, usually bundled with GCC.

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
