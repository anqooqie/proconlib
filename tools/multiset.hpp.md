---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/set.hpp
    title: Alias for __gnu_pbds::tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/multiset.test.cpp
    title: tests/multiset.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/multiset.hpp\"\n\n\n\n#include <functional>\n#include\
    \ <utility>\n#include <cstddef>\n#include <iterator>\n#include <limits>\n#include\
    \ <initializer_list>\n#include <vector>\n#include <algorithm>\n#line 1 \"tools/set.hpp\"\
    \n\n\n\n#line 5 \"tools/set.hpp\"\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #include <ext/pb_ds/tree_policy.hpp>\n#include <ext/pb_ds/tag_and_trait.hpp>\n\
    \nnamespace tools {\n  template <typename Key, typename Compare = ::std::less<Key>>\n\
    \  using set = ::__gnu_pbds::tree<Key, ::__gnu_pbds::null_type, Compare, ::__gnu_pbds::rb_tree_tag,\
    \ ::__gnu_pbds::tree_order_statistics_node_update>;\n}\n\n\n#line 13 \"tools/multiset.hpp\"\
    \n\nnamespace tools {\n  template <typename Key, typename Compare = ::std::less<Key>>\n\
    \  class multiset {\n  private:\n    class PairCompare {\n    private:\n     \
    \ Compare m_key_comp;\n\n    public:\n      PairCompare() = default;\n      explicit\
    \ PairCompare(const Compare& key_comp) : m_key_comp(key_comp) {\n      }\n   \
    \   PairCompare(const PairCompare&) = default;\n      PairCompare(PairCompare&&)\
    \ = default;\n      ~PairCompare() = default;\n      PairCompare& operator=(const\
    \ PairCompare&) = default;\n      PairCompare& operator=(PairCompare&&) = default;\n\
    \n      bool operator()(const ::std::pair<Key, ::std::size_t>& lhs, const ::std::pair<Key,\
    \ ::std::size_t>& rhs) const {\n        if (this->m_key_comp(lhs.first, rhs.first))\
    \ return true;\n        if (this->m_key_comp(rhs.first, lhs.first)) return false;\n\
    \        return lhs.second < rhs.second;\n      }\n\n      Compare key_comp()\
    \ const {\n        return this->m_key_comp;\n      }\n    };\n\n    ::std::size_t\
    \ m_next_id;\n    ::tools::set<::std::pair<Key, ::std::size_t>, PairCompare> m_set;\n\
    \n  public:\n    class iterator {\n    private:\n      typename ::tools::set<::std::pair<Key,\
    \ ::std::size_t>, PairCompare>::iterator m_it;\n\n    public:\n      using difference_type\
    \ = ::std::ptrdiff_t;\n      using value_type = Key;\n      using reference =\
    \ Key&;\n      using pointer = Key*;\n      using iterator_category = ::std::bidirectional_iterator_tag;\n\
    \n      iterator() = default;\n      iterator(const typename ::tools::set<::std::pair<Key,\
    \ ::std::size_t>, PairCompare>::iterator it) : m_it(it) {\n      }\n      iterator(const\
    \ iterator&) = default;\n      iterator(iterator&&) = default;\n      ~iterator()\
    \ = default;\n      iterator& operator=(const iterator&) = default;\n      iterator&\
    \ operator=(iterator&&) = default;\n\n      typename ::tools::set<::std::pair<Key,\
    \ ::std::size_t>, PairCompare>::iterator base() const {\n        return this->m_it;\n\
    \      }\n\n      Key operator*() const {\n        return this->m_it->first;\n\
    \      }\n      iterator& operator++() {\n        ++this->m_it;\n        return\
    \ *this;\n      }\n      iterator operator++(int) {\n        const auto self =\
    \ *this;\n        ++*this;\n        return self;\n      }\n      iterator& operator--()\
    \ {\n        --this->m_it;\n        return *this;\n      }\n      iterator operator--(int)\
    \ {\n        const auto self = *this;\n        --*this;\n        return self;\n\
    \      }\n\n      friend bool operator==(const iterator lhs, const iterator rhs)\
    \ {\n        return lhs.m_it == rhs.m_it;\n      }\n      friend bool operator!=(const\
    \ iterator lhs, const iterator rhs) {\n        return lhs.m_it != rhs.m_it;\n\
    \      }\n    };\n\n    class reverse_iterator {\n    private:\n      iterator\
    \ m_base;\n\n    public:\n      using difference_type = ::std::ptrdiff_t;\n  \
    \    using value_type = Key;\n      using reference = Key&;\n      using pointer\
    \ = Key*;\n      using iterator_category = ::std::bidirectional_iterator_tag;\n\
    \n      reverse_iterator() = default;\n      reverse_iterator(const iterator base)\
    \ : m_base(base) {\n      }\n      reverse_iterator(const reverse_iterator&) =\
    \ default;\n      reverse_iterator(reverse_iterator&&) = default;\n      ~reverse_iterator()\
    \ = default;\n      reverse_iterator& operator=(const reverse_iterator&) = default;\n\
    \      reverse_iterator& operator=(reverse_iterator&&) = default;\n\n      iterator\
    \ base() const {\n        return this->m_base;\n      }\n\n      Key operator*()\
    \ const {\n        return *::std::prev(this->m_base);\n      }\n      reverse_iterator&\
    \ operator++() {\n        --this->m_base;\n        return *this;\n      }\n  \
    \    reverse_iterator operator++(int) {\n        const auto self = *this;\n  \
    \      ++*this;\n        return self;\n      }\n      reverse_iterator& operator--()\
    \ {\n        ++this->m_base;\n        return *this;\n      }\n      reverse_iterator\
    \ operator--(int) {\n        const auto self = *this;\n        --*this;\n    \
    \    return self;\n      }\n\n      friend bool operator==(const reverse_iterator\
    \ lhs, const reverse_iterator rhs) {\n        return lhs.m_base == rhs.m_base;\n\
    \      }\n      friend bool operator!=(const reverse_iterator lhs, const reverse_iterator\
    \ rhs) {\n        return lhs.m_base != rhs.m_base;\n      }\n    };\n\n  private:\n\
    \    ::std::pair<iterator, bool> internal_insert(const Key& x) {\n      const\
    \ auto [it, inserted] = this->m_set.insert(::std::make_pair(x, this->m_next_id++));\n\
    \      return ::std::make_pair(iterator(it), inserted);\n    }\n\n  public:\n\
    \    ::std::size_t count(const Key& x) const {\n      return this->m_set.order_of_key(::std::make_pair(x,\
    \ ::std::numeric_limits<::std::size_t>::max())) - this->m_set.order_of_key(::std::make_pair(x,\
    \ 0));\n    }\n    iterator lower_bound(const Key& x) const {\n      return iterator(this->m_set.lower_bound(::std::make_pair(x,\
    \ 0)));\n    }\n    iterator upper_bound(const Key& x) const {\n      return iterator(this->m_set.upper_bound(::std::make_pair(x,\
    \ ::std::numeric_limits<::std::size_t>::max())));\n    }\n    Compare key_comp()\
    \ const {\n      return this->m_set.get_cmp_fn().key_comp();\n    }\n\n    explicit\
    \ multiset(const Compare& comp = Compare()) : m_next_id(0), m_set(PairCompare(comp))\
    \ {\n    }\n    template <typename InputIterator>\n    multiset(InputIterator\
    \ first, InputIterator last, const Compare& comp = Compare()) : multiset(comp)\
    \ {\n      for (auto it = first; it != last; ++it) {\n        this->internal_insert(*it);\n\
    \      }\n    }\n    multiset(::std::initializer_list<Key> init, const Compare&\
    \ comp = Compare()) : multiset(comp) {\n      for (auto& x : init) {\n       \
    \ this->internal_insert(x);\n      }\n    }\n    multiset(const ::tools::multiset<Key,\
    \ Compare>&) = default;\n    multiset(::tools::multiset<Key, Compare>&&) = default;\n\
    \    ~multiset() = default;\n    ::tools::multiset<Key, Compare>& operator=(const\
    \ ::tools::multiset<Key, Compare>&) = default;\n    ::tools::multiset<Key, Compare>&\
    \ operator=(::tools::multiset<Key, Compare>&&) = default;\n\n    iterator begin()\
    \ const {\n      return iterator(this->m_set.begin());\n    }\n    iterator cbegin()\
    \ const {\n      return this->begin();\n    }\n    iterator end() const {\n  \
    \    return iterator(this->m_set.end());\n    }\n    iterator cend() const {\n\
    \      return this->end();\n    }\n    reverse_iterator rbegin() const {\n   \
    \   return reverse_iterator(this->end());\n    }\n    reverse_iterator crbegin()\
    \ const {\n      return this->rbegin();\n    }\n    reverse_iterator rend() const\
    \ {\n      return reverse_iterator(this->begin());\n    }\n    reverse_iterator\
    \ crend() const {\n      return this->rend();\n    }\n\n    bool empty() const\
    \ {\n      return this->m_set.empty();\n    }\n    ::std::size_t size() const\
    \ {\n      return this->m_set.size();\n    }\n    ::std::size_t max_size() const\
    \ {\n      return this->m_set.max_size();\n    }\n\n    void clear() {\n     \
    \ this->m_set.clear();\n    }\n    iterator insert(const Key& x) {\n      return\
    \ this->internal_insert(x).first;\n    }\n    iterator insert([[maybe_unused]]\
    \ const iterator position, const Key& x) {\n      return this->insert(x);\n  \
    \  }\n    template <typename InputIterator>\n    void insert(InputIterator first,\
    \ InputIterator last) {\n      for (auto it = first; it != last; ++it) {\n   \
    \     this->internal_insert(*it);\n      }\n    }\n    void insert(::std::initializer_list<Key>\
    \ init) {\n      for (auto& x : init) {\n        this->internal_insert(x);\n \
    \     }\n    }\n    template <class... Args>\n    ::std::pair<iterator, bool>\
    \ emplace(Args&&... args) {\n      return this->internal_insert(Key(::std::forward<Args>(args)...));\n\
    \    }\n    iterator erase(iterator position) {\n      return iterator(this->m_set.erase(position.base()));\n\
    \    }\n    iterator erase(iterator first, iterator last) {\n      const ::std::size_t\
    \ n = ::std::distance(first, last);\n      auto it = first;\n      for (::std::size_t\
    \ i = 0; i < n; ++i) {\n        it = this->erase(it);\n      }\n      return it;\n\
    \    }\n    ::std::size_t erase(const Key& x) {\n      ::std::size_t n = 0;\n\
    \      for (auto it = this->lower_bound(x); it != this->end() && !this->key_comp()(x,\
    \ *it); it = this->erase(it)) {\n        ++n;\n      }\n      return n;\n    }\n\
    \    void swap(::tools::multiset<Key, Compare>& st) {\n      ::std::swap(this->m_next_id,\
    \ st.m_next_id);\n      this->m_set.swap(st.m_set);\n    }\n\n    iterator find(const\
    \ Key& x) const {\n      const auto it = this->lower_bound(x);\n      if (it ==\
    \ this->end() || this->key_comp()(x, *it)) return this->end();\n      return it;\n\
    \    }\n    bool contains(const Key& x) const {\n      return this->find(x) !=\
    \ this->end();\n    }\n    ::std::pair<iterator, iterator> equal_range(const Key&\
    \ x) const {\n      return ::std::make_pair(this->lower_bound(x), this->upper_bound(x));\n\
    \    }\n\n    Compare value_comp() const {\n      return this->key_comp();\n \
    \   }\n\n    using key_type = Key;\n    using value_type = Key;\n    using key_compare\
    \ = Compare;\n    using value_compare = Compare;\n    using reference = Key&;\n\
    \    using const_reference = const Key&;\n    using const_iterator = iterator;\n\
    \    using size_type = ::std::size_t;\n    using difference_type = ::std::ptrdiff_t;\n\
    \    using pointer = Key*;\n    using const_pointer = const Key*;\n    using const_reverse_iterator\
    \ = reverse_iterator;\n\n    friend bool operator==(const ::tools::multiset<Key,\
    \ Compare>& x, const ::tools::multiset<Key, Compare>& y) {\n      ::std::vector<Key>\
    \ x2(x.begin(), x.end());\n      ::std::sort(x2.begin(), x2.end());\n      ::std::vector<Key>\
    \ y2(y.begin(), y.end());\n      ::std::sort(y2.begin(), y2.end());\n      return\
    \ ::std::equal(x2.begin(), x2.end(), y2.begin(), y2.end());\n    }\n    friend\
    \ bool operator!=(const ::tools::multiset<Key, Compare>& x, const ::tools::multiset<Key,\
    \ Compare>& y) {\n      return !(x == y);\n    }\n    friend bool operator<(const\
    \ ::tools::multiset<Key, Compare>& x, const ::tools::multiset<Key, Compare>& y)\
    \ {\n      ::std::vector<Key> x2(x.begin(), x.end());\n      ::std::sort(x2.begin(),\
    \ x2.end());\n      ::std::vector<Key> y2(y.begin(), y.end());\n      ::std::sort(y2.begin(),\
    \ y2.end());\n      return ::std::lexicographical_compare(x2.begin(), x2.end(),\
    \ y2.begin(), y2.end());\n    }\n    friend bool operator<=(const ::tools::multiset<Key,\
    \ Compare>& x, const ::tools::multiset<Key, Compare>& y) {\n      return !(y <\
    \ x);\n    }\n    friend bool operator>(const ::tools::multiset<Key, Compare>&\
    \ x, const ::tools::multiset<Key, Compare>& y) {\n      return y < x;\n    }\n\
    \    friend bool operator>=(const ::tools::multiset<Key, Compare>& x, const ::tools::multiset<Key,\
    \ Compare>& y) {\n      return !(x < y);\n    }\n\n    iterator find_by_order(const\
    \ ::std::size_t order) const {\n      return iterator(this->m_set.find_by_order(order));\n\
    \    }\n    ::std::size_t order_of_key(const Key& x) const {\n      return this->m_set.order_of_key(::std::make_pair(x,\
    \ 0));\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_MULTISET_HPP\n#define TOOLS_MULTISET_HPP\n\n#include <functional>\n\
    #include <utility>\n#include <cstddef>\n#include <iterator>\n#include <limits>\n\
    #include <initializer_list>\n#include <vector>\n#include <algorithm>\n#include\
    \ \"tools/set.hpp\"\n\nnamespace tools {\n  template <typename Key, typename Compare\
    \ = ::std::less<Key>>\n  class multiset {\n  private:\n    class PairCompare {\n\
    \    private:\n      Compare m_key_comp;\n\n    public:\n      PairCompare() =\
    \ default;\n      explicit PairCompare(const Compare& key_comp) : m_key_comp(key_comp)\
    \ {\n      }\n      PairCompare(const PairCompare&) = default;\n      PairCompare(PairCompare&&)\
    \ = default;\n      ~PairCompare() = default;\n      PairCompare& operator=(const\
    \ PairCompare&) = default;\n      PairCompare& operator=(PairCompare&&) = default;\n\
    \n      bool operator()(const ::std::pair<Key, ::std::size_t>& lhs, const ::std::pair<Key,\
    \ ::std::size_t>& rhs) const {\n        if (this->m_key_comp(lhs.first, rhs.first))\
    \ return true;\n        if (this->m_key_comp(rhs.first, lhs.first)) return false;\n\
    \        return lhs.second < rhs.second;\n      }\n\n      Compare key_comp()\
    \ const {\n        return this->m_key_comp;\n      }\n    };\n\n    ::std::size_t\
    \ m_next_id;\n    ::tools::set<::std::pair<Key, ::std::size_t>, PairCompare> m_set;\n\
    \n  public:\n    class iterator {\n    private:\n      typename ::tools::set<::std::pair<Key,\
    \ ::std::size_t>, PairCompare>::iterator m_it;\n\n    public:\n      using difference_type\
    \ = ::std::ptrdiff_t;\n      using value_type = Key;\n      using reference =\
    \ Key&;\n      using pointer = Key*;\n      using iterator_category = ::std::bidirectional_iterator_tag;\n\
    \n      iterator() = default;\n      iterator(const typename ::tools::set<::std::pair<Key,\
    \ ::std::size_t>, PairCompare>::iterator it) : m_it(it) {\n      }\n      iterator(const\
    \ iterator&) = default;\n      iterator(iterator&&) = default;\n      ~iterator()\
    \ = default;\n      iterator& operator=(const iterator&) = default;\n      iterator&\
    \ operator=(iterator&&) = default;\n\n      typename ::tools::set<::std::pair<Key,\
    \ ::std::size_t>, PairCompare>::iterator base() const {\n        return this->m_it;\n\
    \      }\n\n      Key operator*() const {\n        return this->m_it->first;\n\
    \      }\n      iterator& operator++() {\n        ++this->m_it;\n        return\
    \ *this;\n      }\n      iterator operator++(int) {\n        const auto self =\
    \ *this;\n        ++*this;\n        return self;\n      }\n      iterator& operator--()\
    \ {\n        --this->m_it;\n        return *this;\n      }\n      iterator operator--(int)\
    \ {\n        const auto self = *this;\n        --*this;\n        return self;\n\
    \      }\n\n      friend bool operator==(const iterator lhs, const iterator rhs)\
    \ {\n        return lhs.m_it == rhs.m_it;\n      }\n      friend bool operator!=(const\
    \ iterator lhs, const iterator rhs) {\n        return lhs.m_it != rhs.m_it;\n\
    \      }\n    };\n\n    class reverse_iterator {\n    private:\n      iterator\
    \ m_base;\n\n    public:\n      using difference_type = ::std::ptrdiff_t;\n  \
    \    using value_type = Key;\n      using reference = Key&;\n      using pointer\
    \ = Key*;\n      using iterator_category = ::std::bidirectional_iterator_tag;\n\
    \n      reverse_iterator() = default;\n      reverse_iterator(const iterator base)\
    \ : m_base(base) {\n      }\n      reverse_iterator(const reverse_iterator&) =\
    \ default;\n      reverse_iterator(reverse_iterator&&) = default;\n      ~reverse_iterator()\
    \ = default;\n      reverse_iterator& operator=(const reverse_iterator&) = default;\n\
    \      reverse_iterator& operator=(reverse_iterator&&) = default;\n\n      iterator\
    \ base() const {\n        return this->m_base;\n      }\n\n      Key operator*()\
    \ const {\n        return *::std::prev(this->m_base);\n      }\n      reverse_iterator&\
    \ operator++() {\n        --this->m_base;\n        return *this;\n      }\n  \
    \    reverse_iterator operator++(int) {\n        const auto self = *this;\n  \
    \      ++*this;\n        return self;\n      }\n      reverse_iterator& operator--()\
    \ {\n        ++this->m_base;\n        return *this;\n      }\n      reverse_iterator\
    \ operator--(int) {\n        const auto self = *this;\n        --*this;\n    \
    \    return self;\n      }\n\n      friend bool operator==(const reverse_iterator\
    \ lhs, const reverse_iterator rhs) {\n        return lhs.m_base == rhs.m_base;\n\
    \      }\n      friend bool operator!=(const reverse_iterator lhs, const reverse_iterator\
    \ rhs) {\n        return lhs.m_base != rhs.m_base;\n      }\n    };\n\n  private:\n\
    \    ::std::pair<iterator, bool> internal_insert(const Key& x) {\n      const\
    \ auto [it, inserted] = this->m_set.insert(::std::make_pair(x, this->m_next_id++));\n\
    \      return ::std::make_pair(iterator(it), inserted);\n    }\n\n  public:\n\
    \    ::std::size_t count(const Key& x) const {\n      return this->m_set.order_of_key(::std::make_pair(x,\
    \ ::std::numeric_limits<::std::size_t>::max())) - this->m_set.order_of_key(::std::make_pair(x,\
    \ 0));\n    }\n    iterator lower_bound(const Key& x) const {\n      return iterator(this->m_set.lower_bound(::std::make_pair(x,\
    \ 0)));\n    }\n    iterator upper_bound(const Key& x) const {\n      return iterator(this->m_set.upper_bound(::std::make_pair(x,\
    \ ::std::numeric_limits<::std::size_t>::max())));\n    }\n    Compare key_comp()\
    \ const {\n      return this->m_set.get_cmp_fn().key_comp();\n    }\n\n    explicit\
    \ multiset(const Compare& comp = Compare()) : m_next_id(0), m_set(PairCompare(comp))\
    \ {\n    }\n    template <typename InputIterator>\n    multiset(InputIterator\
    \ first, InputIterator last, const Compare& comp = Compare()) : multiset(comp)\
    \ {\n      for (auto it = first; it != last; ++it) {\n        this->internal_insert(*it);\n\
    \      }\n    }\n    multiset(::std::initializer_list<Key> init, const Compare&\
    \ comp = Compare()) : multiset(comp) {\n      for (auto& x : init) {\n       \
    \ this->internal_insert(x);\n      }\n    }\n    multiset(const ::tools::multiset<Key,\
    \ Compare>&) = default;\n    multiset(::tools::multiset<Key, Compare>&&) = default;\n\
    \    ~multiset() = default;\n    ::tools::multiset<Key, Compare>& operator=(const\
    \ ::tools::multiset<Key, Compare>&) = default;\n    ::tools::multiset<Key, Compare>&\
    \ operator=(::tools::multiset<Key, Compare>&&) = default;\n\n    iterator begin()\
    \ const {\n      return iterator(this->m_set.begin());\n    }\n    iterator cbegin()\
    \ const {\n      return this->begin();\n    }\n    iterator end() const {\n  \
    \    return iterator(this->m_set.end());\n    }\n    iterator cend() const {\n\
    \      return this->end();\n    }\n    reverse_iterator rbegin() const {\n   \
    \   return reverse_iterator(this->end());\n    }\n    reverse_iterator crbegin()\
    \ const {\n      return this->rbegin();\n    }\n    reverse_iterator rend() const\
    \ {\n      return reverse_iterator(this->begin());\n    }\n    reverse_iterator\
    \ crend() const {\n      return this->rend();\n    }\n\n    bool empty() const\
    \ {\n      return this->m_set.empty();\n    }\n    ::std::size_t size() const\
    \ {\n      return this->m_set.size();\n    }\n    ::std::size_t max_size() const\
    \ {\n      return this->m_set.max_size();\n    }\n\n    void clear() {\n     \
    \ this->m_set.clear();\n    }\n    iterator insert(const Key& x) {\n      return\
    \ this->internal_insert(x).first;\n    }\n    iterator insert([[maybe_unused]]\
    \ const iterator position, const Key& x) {\n      return this->insert(x);\n  \
    \  }\n    template <typename InputIterator>\n    void insert(InputIterator first,\
    \ InputIterator last) {\n      for (auto it = first; it != last; ++it) {\n   \
    \     this->internal_insert(*it);\n      }\n    }\n    void insert(::std::initializer_list<Key>\
    \ init) {\n      for (auto& x : init) {\n        this->internal_insert(x);\n \
    \     }\n    }\n    template <class... Args>\n    ::std::pair<iterator, bool>\
    \ emplace(Args&&... args) {\n      return this->internal_insert(Key(::std::forward<Args>(args)...));\n\
    \    }\n    iterator erase(iterator position) {\n      return iterator(this->m_set.erase(position.base()));\n\
    \    }\n    iterator erase(iterator first, iterator last) {\n      const ::std::size_t\
    \ n = ::std::distance(first, last);\n      auto it = first;\n      for (::std::size_t\
    \ i = 0; i < n; ++i) {\n        it = this->erase(it);\n      }\n      return it;\n\
    \    }\n    ::std::size_t erase(const Key& x) {\n      ::std::size_t n = 0;\n\
    \      for (auto it = this->lower_bound(x); it != this->end() && !this->key_comp()(x,\
    \ *it); it = this->erase(it)) {\n        ++n;\n      }\n      return n;\n    }\n\
    \    void swap(::tools::multiset<Key, Compare>& st) {\n      ::std::swap(this->m_next_id,\
    \ st.m_next_id);\n      this->m_set.swap(st.m_set);\n    }\n\n    iterator find(const\
    \ Key& x) const {\n      const auto it = this->lower_bound(x);\n      if (it ==\
    \ this->end() || this->key_comp()(x, *it)) return this->end();\n      return it;\n\
    \    }\n    bool contains(const Key& x) const {\n      return this->find(x) !=\
    \ this->end();\n    }\n    ::std::pair<iterator, iterator> equal_range(const Key&\
    \ x) const {\n      return ::std::make_pair(this->lower_bound(x), this->upper_bound(x));\n\
    \    }\n\n    Compare value_comp() const {\n      return this->key_comp();\n \
    \   }\n\n    using key_type = Key;\n    using value_type = Key;\n    using key_compare\
    \ = Compare;\n    using value_compare = Compare;\n    using reference = Key&;\n\
    \    using const_reference = const Key&;\n    using const_iterator = iterator;\n\
    \    using size_type = ::std::size_t;\n    using difference_type = ::std::ptrdiff_t;\n\
    \    using pointer = Key*;\n    using const_pointer = const Key*;\n    using const_reverse_iterator\
    \ = reverse_iterator;\n\n    friend bool operator==(const ::tools::multiset<Key,\
    \ Compare>& x, const ::tools::multiset<Key, Compare>& y) {\n      ::std::vector<Key>\
    \ x2(x.begin(), x.end());\n      ::std::sort(x2.begin(), x2.end());\n      ::std::vector<Key>\
    \ y2(y.begin(), y.end());\n      ::std::sort(y2.begin(), y2.end());\n      return\
    \ ::std::equal(x2.begin(), x2.end(), y2.begin(), y2.end());\n    }\n    friend\
    \ bool operator!=(const ::tools::multiset<Key, Compare>& x, const ::tools::multiset<Key,\
    \ Compare>& y) {\n      return !(x == y);\n    }\n    friend bool operator<(const\
    \ ::tools::multiset<Key, Compare>& x, const ::tools::multiset<Key, Compare>& y)\
    \ {\n      ::std::vector<Key> x2(x.begin(), x.end());\n      ::std::sort(x2.begin(),\
    \ x2.end());\n      ::std::vector<Key> y2(y.begin(), y.end());\n      ::std::sort(y2.begin(),\
    \ y2.end());\n      return ::std::lexicographical_compare(x2.begin(), x2.end(),\
    \ y2.begin(), y2.end());\n    }\n    friend bool operator<=(const ::tools::multiset<Key,\
    \ Compare>& x, const ::tools::multiset<Key, Compare>& y) {\n      return !(y <\
    \ x);\n    }\n    friend bool operator>(const ::tools::multiset<Key, Compare>&\
    \ x, const ::tools::multiset<Key, Compare>& y) {\n      return y < x;\n    }\n\
    \    friend bool operator>=(const ::tools::multiset<Key, Compare>& x, const ::tools::multiset<Key,\
    \ Compare>& y) {\n      return !(x < y);\n    }\n\n    iterator find_by_order(const\
    \ ::std::size_t order) const {\n      return iterator(this->m_set.find_by_order(order));\n\
    \    }\n    ::std::size_t order_of_key(const Key& x) const {\n      return this->m_set.order_of_key(::std::make_pair(x,\
    \ 0));\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/set.hpp
  isVerificationFile: false
  path: tools/multiset.hpp
  requiredBy: []
  timestamp: '2022-10-01 21:52:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/multiset.test.cpp
documentation_of: tools/multiset.hpp
layout: document
title: __gnu_pbds::tree allowing duplicated values
---

`tools::multiset<Key, Compare = std::less<Key>>` is almost like `__gnu_pbds::tree<Key, __gnu_pbds::null_type, Compare, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>` but allows duplicated values.

## Constraints
- It requires GCC.

## Time Complexity
- Not applicable

## License
- CC0

## Author
- anqooqie
