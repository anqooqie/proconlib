#ifndef TOOLS_MULTISET_HPP
#define TOOLS_MULTISET_HPP

#include <functional>
#include <utility>
#include <cstddef>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#include <iterator>
#include <initializer_list>
#include <limits>
#include <algorithm>

namespace tools {
  template <typename Key, typename Compare = ::std::less<Key>>
  class multiset {
    class PairCompare {
      Compare m_key_comp;

    public:
      PairCompare() = default;
      explicit PairCompare(const Compare& key_comp) : m_key_comp(key_comp) {
      }

      bool operator()(const ::std::pair<Key, ::std::size_t>& lhs, const ::std::pair<Key, ::std::size_t>& rhs) const {
        if (this->m_key_comp(lhs.first, rhs.first)) return true;
        if (this->m_key_comp(rhs.first, lhs.first)) return false;
        return lhs.second < rhs.second;
      }

      Compare key_comp() const {
        return this->m_key_comp;
      }
    };
    using pbds_tree = ::__gnu_pbds::tree<::std::pair<Key, ::std::size_t>, ::__gnu_pbds::null_type, PairCompare, ::__gnu_pbds::rb_tree_tag, ::__gnu_pbds::tree_order_statistics_node_update>;

    ::std::size_t m_next_id;
    pbds_tree m_set;

  public:
    using key_type = Key;
    using value_type = Key;
    using key_compare = Compare;
    using value_compare = Compare;
    using reference = Key&;
    using const_reference = const Key&;
    class iterator {
      typename pbds_tree::iterator m_it;

    public:
      using difference_type = ::std::ptrdiff_t;
      using value_type = Key;
      using reference = const Key&;
      using pointer = const Key*;
      using iterator_category = ::std::bidirectional_iterator_tag;

      iterator() = default;
      iterator(const typename pbds_tree::iterator it) : m_it(it) {
      }

      typename pbds_tree::iterator base() const {
        return this->m_it;
      }

      reference operator*() const {
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
    using const_iterator = iterator;
    using size_type = ::std::size_t;
    using difference_type = ::std::ptrdiff_t;
    using pointer = Key*;
    using const_pointer = const Key*;
    using reverse_iterator = ::std::reverse_iterator<iterator>;
    using const_reverse_iterator = reverse_iterator;

    explicit multiset(const Compare& comp = Compare()) : m_next_id(0), m_set(PairCompare(comp)) {
    }
    template <typename InputIterator>
    multiset(const InputIterator first, const InputIterator last, const Compare& comp = Compare()) : multiset(comp) {
      this->insert(first, last);
    }
    multiset(const ::std::initializer_list<Key> init, const Compare& comp = Compare()) : multiset(comp) {
      this->insert(init);
    }

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
    size_type size() const {
      return this->m_set.size();
    }
    size_type max_size() const {
      return this->m_set.max_size();
    }

    void clear() {
      this->m_set.clear();
    }
    iterator insert(const Key& x) {
      return iterator(this->m_set.insert(::std::make_pair(x, this->m_next_id++)).first);
    }
    iterator insert([[maybe_unused]] const iterator position, const Key& x) {
      return this->insert(x);
    }
    template <typename InputIterator>
    void insert(const InputIterator first, const InputIterator last) {
      for (auto it = first; it != last; ++it) {
        this->insert(*it);
      }
    }
    void insert(const ::std::initializer_list<Key> init) {
      for (const auto& x : init) {
        this->insert(x);
      }
    }
    template <class... Args>
    iterator emplace(Args&&... args) {
      return this->insert(Key(::std::forward<Args>(args)...));
    }
    template <class... Args>
    iterator emplace_hint([[maybe_unused]] const iterator hint, Args&&... args) {
      return this->emplace(::std::forward<Args>(args)...);
    }
    iterator erase(const iterator position) {
      return iterator(this->m_set.erase(position.base()));
    }
    size_type erase(const Key& x) {
      size_type n = 0;
      for (auto it = this->lower_bound(x); it != this->end() && !this->key_comp()(x, *it); it = this->erase(it)) {
        ++n;
      }
      return n;
    }
    iterator erase(const iterator first, const iterator last) {
      const size_type n = ::std::distance(first, last);
      auto it = first;
      for (size_type i = 0; i < n; ++i) {
        it = this->erase(it);
      }
      return it;
    }
    void swap(::tools::multiset<Key, Compare>& st) {
      ::std::swap(this->m_next_id, st.m_next_id);
      this->m_set.swap(st.m_set);
    }
    template <typename C2>
    void merge(::tools::multiset<Key, C2>& source) {
      this->insert(source.begin(), source.end());
      source.clear();
    }

    size_type count(const Key& x) const {
      return this->m_set.order_of_key(::std::make_pair(x, ::std::numeric_limits<::std::size_t>::max())) - this->m_set.order_of_key(::std::make_pair(x, 0));
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
    iterator lower_bound(const Key& x) const {
      return iterator(this->m_set.lower_bound(::std::make_pair(x, 0)));
    }
    iterator upper_bound(const Key& x) const {
      return iterator(this->m_set.upper_bound(::std::make_pair(x, ::std::numeric_limits<::std::size_t>::max())));
    }

    Compare key_comp() const {
      return this->m_set.get_cmp_fn().key_comp();
    }
    Compare value_comp() const {
      return this->key_comp();
    }

    friend bool operator==(const ::tools::multiset<Key, Compare>& x, const ::tools::multiset<Key, Compare>& y) {
      return ::std::equal(x.begin(), x.end(), y.begin(), y.end());
    }
    friend bool operator!=(const ::tools::multiset<Key, Compare>& x, const ::tools::multiset<Key, Compare>& y) {
      return !(x == y);
    }
    friend bool operator<(const ::tools::multiset<Key, Compare>& x, const ::tools::multiset<Key, Compare>& y) {
      return ::std::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
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

    iterator find_by_order(const size_type order) const {
      return iterator(this->m_set.find_by_order(order));
    }
    size_type order_of_key(const Key& x) const {
      return this->m_set.order_of_key(::std::make_pair(x, 0));
    }
  };
}

#endif
