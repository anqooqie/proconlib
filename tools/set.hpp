#ifndef TOOLS_SET_HPP
#define TOOLS_SET_HPP

#include <functional>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#include <cstddef>
#include <iterator>
#include <initializer_list>
#include <utility>
#include <algorithm>

namespace tools {
  template <typename Key, typename Compare = std::less<Key>>
  class set {
    using pbds_tree = ::__gnu_pbds::tree<Key, ::__gnu_pbds::null_type, Compare, ::__gnu_pbds::rb_tree_tag, ::__gnu_pbds::tree_order_statistics_node_update>;

    pbds_tree m_set;

  public:
    using key_type = Key;
    using value_type = Key;
    using key_compare = Compare;
    using value_compare = Compare;
    using reference = Key&;
    using const_reference = const Key&;
    using iterator = typename pbds_tree::iterator;
    using const_iterator = iterator;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using pointer = Key*;
    using const_pointer = const Key*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = reverse_iterator;

    explicit set(const Compare& comp = Compare()) : m_set(comp) {
    }
    template <typename InputIterator>
    set(const InputIterator first, const InputIterator last, const Compare& comp = Compare()) : set(comp) {
      this->insert(first, last);
    }
    set(const std::initializer_list<Key> init, const Compare& comp = Compare()) : set(comp) {
      this->insert(init);
    }

    iterator begin() const {
      return this->m_set.begin();
    }
    iterator cbegin() const {
      return this->begin();
    }
    iterator end() const {
      return this->m_set.end();
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
    std::pair<iterator, bool> insert(const Key& x) {
      return this->m_set.insert(x);
    }
    iterator insert([[maybe_unused]] const iterator position, const Key& x) {
      return this->insert(x).first;
    }
    template <typename InputIterator>
    void insert(const InputIterator first, const InputIterator last) {
      for (auto it = first; it != last; ++it) {
        this->insert(*it);
      }
    }
    void insert(const std::initializer_list<Key> init) {
      for (const auto& x : init) {
        this->insert(x);
      }
    }
    template <class... Args>
    std::pair<iterator, bool> emplace(Args&&... args) {
      return this->insert(Key(std::forward<Args>(args)...));
    }
    template <class... Args>
    iterator emplace_hint([[maybe_unused]] const iterator hint, Args&&... args) {
      return this->emplace(std::forward<Args>(args)...).first;
    }
    iterator erase(const iterator position) {
      return this->m_set.erase(position);
    }
    size_type erase(const Key& x) {
      return this->m_set.erase(x);
    }
    iterator erase(const iterator first, const iterator last) {
      const size_type n = std::distance(first, last);
      auto it = first;
      for (size_type i = 0; i < n; ++i) {
        it = this->erase(it);
      }
      return it;
    }
    void swap(tools::set<Key, Compare>& st) {
      this->m_set.swap(st.m_set);
    }
    template <typename C2>
    void merge(tools::set<Key, C2>& source) {
      this->insert(source.begin(), source.end());
      source.clear();
    }

    size_type count(const Key& x) const {
      return this->contains(x);
    }
    iterator find(const Key& x) const {
      return this->m_set.find(x);
    }
    bool contains(const Key& x) const {
      return this->find(x) != this->end();
    }
    std::pair<iterator, iterator> equal_range(const Key& x) const {
      return std::make_pair(this->lower_bound(x), this->upper_bound(x));
    }
    iterator lower_bound(const Key& x) const {
      return this->m_set.lower_bound(x);
    }
    iterator upper_bound(const Key& x) const {
      return this->m_set.upper_bound(x);
    }

    Compare key_comp() const {
      return this->m_set.get_cmp_fn();
    }
    Compare value_comp() const {
      return this->key_comp();
    }

    friend bool operator==(const tools::set<Key, Compare>& x, const tools::set<Key, Compare>& y) {
      return std::equal(x.begin(), x.end(), y.begin(), y.end());
    }
    friend bool operator!=(const tools::set<Key, Compare>& x, const tools::set<Key, Compare>& y) {
      return !(x == y);
    }
    friend bool operator<(const tools::set<Key, Compare>& x, const tools::set<Key, Compare>& y) {
      return std::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
    }
    friend bool operator<=(const tools::set<Key, Compare>& x, const tools::set<Key, Compare>& y) {
      return !(y < x);
    }
    friend bool operator>(const tools::set<Key, Compare>& x, const tools::set<Key, Compare>& y) {
      return y < x;
    }
    friend bool operator>=(const tools::set<Key, Compare>& x, const tools::set<Key, Compare>& y) {
      return !(x < y);
    }

    iterator find_by_order(const size_type order) const {
      return this->m_set.find_by_order(order);
    }
    size_type order_of_key(const Key& x) const {
      return this->m_set.order_of_key(x);
    }
  };
}

#endif
