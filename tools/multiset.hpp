#ifndef TOOLS_MULTISET_HPP
#define TOOLS_MULTISET_HPP

#include <functional>
#include <utility>
#include <cstddef>
#include <iterator>
#include <limits>
#include <initializer_list>
#include <vector>
#include <algorithm>
#include "tools/set.hpp"

namespace tools {
  template <typename Key, typename Compare = ::std::less<Key>>
  class multiset {
  private:
    class PairCompare {
    private:
      Compare m_key_comp;

    public:
      PairCompare() = default;
      explicit PairCompare(const Compare& key_comp) : m_key_comp(key_comp) {
      }
      PairCompare(const PairCompare&) = default;
      PairCompare(PairCompare&&) = default;
      ~PairCompare() = default;
      PairCompare& operator=(const PairCompare&) = default;
      PairCompare& operator=(PairCompare&&) = default;

      bool operator()(const ::std::pair<Key, ::std::size_t>& lhs, const ::std::pair<Key, ::std::size_t>& rhs) const {
        if (this->m_key_comp(lhs.first, rhs.first)) return true;
        if (this->m_key_comp(rhs.first, lhs.first)) return false;
        return lhs.second < rhs.second;
      }

      Compare key_comp() const {
        return this->m_key_comp;
      }
    };

    ::std::size_t m_next_id;
    ::tools::set<::std::pair<Key, ::std::size_t>, PairCompare> m_set;

  public:
    class iterator {
    private:
      typename ::tools::set<::std::pair<Key, ::std::size_t>, PairCompare>::iterator m_it;

    public:
      using difference_type = ::std::ptrdiff_t;
      using value_type = Key;
      using reference = Key&;
      using pointer = Key*;
      using iterator_category = ::std::bidirectional_iterator_tag;

      iterator() = default;
      iterator(const typename ::tools::set<::std::pair<Key, ::std::size_t>, PairCompare>::iterator it) : m_it(it) {
      }
      iterator(const iterator&) = default;
      iterator(iterator&&) = default;
      ~iterator() = default;
      iterator& operator=(const iterator&) = default;
      iterator& operator=(iterator&&) = default;

      typename ::tools::set<::std::pair<Key, ::std::size_t>, PairCompare>::iterator base() const {
        return this->m_it;
      }

      Key operator*() const {
        return this->m_it->first;
      }
      iterator& operator++() {
        ++this->m_it;
        return *this;
      }
      iterator operator++(int) {
        const auto self = *this;
        ++*this;
        return self;
      }
      iterator& operator--() {
        --this->m_it;
        return *this;
      }
      iterator operator--(int) {
        const auto self = *this;
        --*this;
        return self;
      }

      friend bool operator==(const iterator lhs, const iterator rhs) {
        return lhs.m_it == rhs.m_it;
      }
      friend bool operator!=(const iterator lhs, const iterator rhs) {
        return lhs.m_it != rhs.m_it;
      }
    };

    class reverse_iterator {
    private:
      iterator m_base;

    public:
      using difference_type = ::std::ptrdiff_t;
      using value_type = Key;
      using reference = Key&;
      using pointer = Key*;
      using iterator_category = ::std::bidirectional_iterator_tag;

      reverse_iterator() = default;
      reverse_iterator(const iterator base) : m_base(base) {
      }
      reverse_iterator(const reverse_iterator&) = default;
      reverse_iterator(reverse_iterator&&) = default;
      ~reverse_iterator() = default;
      reverse_iterator& operator=(const reverse_iterator&) = default;
      reverse_iterator& operator=(reverse_iterator&&) = default;

      iterator base() const {
        return this->m_base;
      }

      Key operator*() const {
        return *::std::prev(this->m_base);
      }
      reverse_iterator& operator++() {
        --this->m_base;
        return *this;
      }
      reverse_iterator operator++(int) {
        const auto self = *this;
        ++*this;
        return self;
      }
      reverse_iterator& operator--() {
        ++this->m_base;
        return *this;
      }
      reverse_iterator operator--(int) {
        const auto self = *this;
        --*this;
        return self;
      }

      friend bool operator==(const reverse_iterator lhs, const reverse_iterator rhs) {
        return lhs.m_base == rhs.m_base;
      }
      friend bool operator!=(const reverse_iterator lhs, const reverse_iterator rhs) {
        return lhs.m_base != rhs.m_base;
      }
    };

  private:
    ::std::pair<iterator, bool> internal_insert(const Key& x) {
      const auto [it, inserted] = this->m_set.insert(::std::make_pair(x, this->m_next_id++));
      return ::std::make_pair(iterator(it), inserted);
    }

  public:
    ::std::size_t count(const Key& x) const {
      return this->m_set.order_of_key(::std::make_pair(x, ::std::numeric_limits<::std::size_t>::max())) - this->m_set.order_of_key(::std::make_pair(x, 0));
    }
    iterator lower_bound(const Key& x) const {
      return iterator(this->m_set.lower_bound(::std::make_pair(x, 0)));
    }
    iterator upper_bound(const Key& x) const {
      return iterator(this->m_set.upper_bound(::std::make_pair(x, ::std::numeric_limits<::std::size_t>::max())));
    }
    Compare key_comp() const {
      return this->m_set.get_cmp_fn().key_comp();
    }

    explicit multiset(const Compare& comp = Compare()) : m_next_id(0), m_set(PairCompare(comp)) {
    }
    template <typename InputIterator>
    multiset(InputIterator first, InputIterator last, const Compare& comp = Compare()) : multiset(comp) {
      for (auto it = first; it != last; ++it) {
        this->internal_insert(*it);
      }
    }
    multiset(::std::initializer_list<Key> init, const Compare& comp = Compare()) : multiset(comp) {
      for (auto& x : init) {
        this->internal_insert(x);
      }
    }
    multiset(const ::tools::multiset<Key, Compare>&) = default;
    multiset(::tools::multiset<Key, Compare>&&) = default;
    ~multiset() = default;
    ::tools::multiset<Key, Compare>& operator=(const ::tools::multiset<Key, Compare>&) = default;
    ::tools::multiset<Key, Compare>& operator=(::tools::multiset<Key, Compare>&&) = default;

    iterator begin() const {
      return iterator(this->m_set.begin());
    }
    iterator cbegin() const {
      return this->begin();
    }
    iterator end() const {
      return iterator(this->m_set.end());
    }
    iterator cend() const {
      return this->end();
    }
    reverse_iterator rbegin() const {
      return reverse_iterator(this->end());
    }
    reverse_iterator crbegin() const {
      return this->rbegin();
    }
    reverse_iterator rend() const {
      return reverse_iterator(this->begin());
    }
    reverse_iterator crend() const {
      return this->rend();
    }

    bool empty() const {
      return this->m_set.empty();
    }
    ::std::size_t size() const {
      return this->m_set.size();
    }
    ::std::size_t max_size() const {
      return this->m_set.max_size();
    }

    void clear() {
      this->m_set.clear();
    }
    iterator insert(const Key& x) {
      return this->internal_insert(x).first;
    }
    iterator insert([[maybe_unused]] const iterator position, const Key& x) {
      return this->insert(x);
    }
    template <typename InputIterator>
    void insert(InputIterator first, InputIterator last) {
      for (auto it = first; it != last; ++it) {
        this->internal_insert(*it);
      }
    }
    void insert(::std::initializer_list<Key> init) {
      for (auto& x : init) {
        this->internal_insert(x);
      }
    }
    template <class... Args>
    ::std::pair<iterator, bool> emplace(Args&&... args) {
      return this->internal_insert(Key(::std::forward<Args>(args)...));
    }
    iterator erase(iterator position) {
      return iterator(this->m_set.erase(position.base()));
    }
    iterator erase(iterator first, iterator last) {
      const ::std::size_t n = ::std::distance(first, last);
      auto it = first;
      for (::std::size_t i = 0; i < n; ++i) {
        it = this->erase(it);
      }
      return it;
    }
    ::std::size_t erase(const Key& x) {
      ::std::size_t n = 0;
      for (auto it = this->lower_bound(x); it != this->end() && !this->key_comp()(x, *it); it = this->erase(it)) {
        ++n;
      }
      return n;
    }
    void swap(::tools::multiset<Key, Compare>& st) {
      ::std::swap(this->m_next_id, st.m_next_id);
      this->m_set.swap(st.m_set);
    }

    iterator find(const Key& x) const {
      const auto it = this->lower_bound(x);
      if (it == this->end() || this->key_comp()(x, *it)) return this->end();
      return it;
    }
    bool contains(const Key& x) const {
      return this->find(x) != this->end();
    }
    ::std::pair<iterator, iterator> equal_range(const Key& x) const {
      return ::std::make_pair(this->lower_bound(x), this->upper_bound(x));
    }

    Compare value_comp() const {
      return this->key_comp();
    }

    using key_type = Key;
    using value_type = Key;
    using key_compare = Compare;
    using value_compare = Compare;
    using reference = Key&;
    using const_reference = const Key&;
    using const_iterator = iterator;
    using size_type = ::std::size_t;
    using difference_type = ::std::ptrdiff_t;
    using pointer = Key*;
    using const_pointer = const Key*;
    using const_reverse_iterator = reverse_iterator;

    friend bool operator==(const ::tools::multiset<Key, Compare>& x, const ::tools::multiset<Key, Compare>& y) {
      ::std::vector<Key> x2(x.begin(), x.end());
      ::std::sort(x2.begin(), x2.end());
      ::std::vector<Key> y2(y.begin(), y.end());
      ::std::sort(y2.begin(), y2.end());
      return ::std::equal(x2.begin(), x2.end(), y2.begin(), y2.end());
    }
    friend bool operator!=(const ::tools::multiset<Key, Compare>& x, const ::tools::multiset<Key, Compare>& y) {
      return !(x == y);
    }
    friend bool operator<(const ::tools::multiset<Key, Compare>& x, const ::tools::multiset<Key, Compare>& y) {
      ::std::vector<Key> x2(x.begin(), x.end());
      ::std::sort(x2.begin(), x2.end());
      ::std::vector<Key> y2(y.begin(), y.end());
      ::std::sort(y2.begin(), y2.end());
      return ::std::lexicographical_compare(x2.begin(), x2.end(), y2.begin(), y2.end());
    }
    friend bool operator<=(const ::tools::multiset<Key, Compare>& x, const ::tools::multiset<Key, Compare>& y) {
      return !(y < x);
    }
    friend bool operator>(const ::tools::multiset<Key, Compare>& x, const ::tools::multiset<Key, Compare>& y) {
      return y < x;
    }
    friend bool operator>=(const ::tools::multiset<Key, Compare>& x, const ::tools::multiset<Key, Compare>& y) {
      return !(x < y);
    }

    iterator find_by_order(const ::std::size_t order) const {
      return iterator(this->m_set.find_by_order(order));
    }
    ::std::size_t order_of_key(const Key& x) const {
      return this->m_set.order_of_key(::std::make_pair(x, 0));
    }
  };
}

#endif
