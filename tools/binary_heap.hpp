#ifndef TOOLS_BINARY_HEAP_HPP
#define TOOLS_BINARY_HEAP_HPP

#include <functional>
#include <unordered_map>
#include <cstddef>
#include <vector>
#include <optional>
#include <utility>
#include <type_traits>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include "tools/pow2.hpp"
#include "tools/ceil_log2.hpp"

namespace tools {

  template <class Key, class Priority, class Compare = ::std::less<Priority>>
  class binary_heap {
  private:
    Compare m_compare;
    ::std::unordered_map<Key, ::std::size_t> m_heap_index;
    ::std::vector<::std::optional<::std::size_t>> m_heap_index_fast;
    ::std::vector<::std::pair<Key, Priority>> m_heap;
    ::std::size_t m_size;

    void swap(::std::size_t x, ::std::size_t y) {
      if constexpr (::std::is_integral_v<Key>) {
        ::std::swap(*this->m_heap_index_fast[this->m_heap[x].first], *this->m_heap_index_fast[this->m_heap[y].first]);
      } else {
        ::std::swap(this->m_heap_index[this->m_heap[x].first], this->m_heap_index[this->m_heap[y].first]);
      }
      ::std::swap(this->m_heap[x], this->m_heap[y]);
    }

    void upheap(::std::size_t i) {
      for (; i > 1 && this->m_compare(this->m_heap[i / 2].second, this->m_heap[i].second); i /= 2) {
        this->swap(i / 2, i);
      }
    }

    void downheap(::std::size_t i) {
      auto calc_next_i = [this](const ::std::size_t self) {
        const std::array<::std::size_t, 3> targets = {self, self * 2, self * 2 + 1};
        return *::std::max_element(
          targets.begin(),
          std::next(targets.begin(), self * 2 + 1 <= this->m_size ? 3 : self * 2 <= this->m_size ? 2 : 1),
          [this](const ::std::size_t x, const ::std::size_t y) {
            return this->m_compare(this->m_heap[x].second, this->m_heap[y].second);
          }
        );
      };
      for (::std::size_t next_i; i != (next_i = calc_next_i(i)); i = next_i) {
        this->swap(i, next_i);
      }
    }

    ::std::optional<::std::size_t> get_internal_index(const Key& k) const {
      if constexpr (::std::is_integral_v<Key>) {
        if (::std::size_t(k) < this->m_heap_index_fast.size()) {
          return this->m_heap_index_fast[k];
        } else {
          return ::std::nullopt;
        }
      } else {
        if (auto it = this->m_heap_index.find(k); it != this->m_heap_index.end()) {
          return ::std::make_optional(it->second);
        } else {
          return ::std::nullopt;
        }
      }
    }

  public:
    explicit binary_heap(const Compare& compare = Compare()) : m_compare(compare), m_heap_index(), m_heap_index_fast(), m_heap(1), m_size(0) {
    }
    binary_heap(const binary_heap&) = default;
    binary_heap(binary_heap&&) = default;
    ~binary_heap() = default;
    binary_heap& operator=(const binary_heap&) = default;
    binary_heap& operator=(binary_heap&&) = default;

    bool empty() const noexcept {
      return this->m_size == 0;
    }

    ::std::size_t size() const noexcept {
      return this->m_size;
    }

    const ::std::pair<Key, Priority>& top() const {
      assert(!this->empty());
      return this->m_heap[1];
    }

    Priority at(const Key& k) const {
      if constexpr (::std::is_integral_v<Key>) {
        return this->m_heap[*this->m_heap_index_fast[k]].second;
      } else {
        return this->m_heap[this->m_heap_index.at(k)].second;
      }
    }

    bool push(const ::std::pair<Key, Priority>& x) {
      ::std::optional<::std::size_t> internal_index = this->get_internal_index(x.first);

      if (internal_index) {
        const Priority prev_priority = this->m_heap[*internal_index].second;
        this->m_heap[*internal_index].second = x.second;
        if (this->m_compare(prev_priority, x.second)) {
          this->upheap(*internal_index);
        } else if (this->m_compare(x.second, prev_priority)) {
          this->downheap(*internal_index);
        }
      } else {
        if (this->m_size + 1 == this->m_heap.size()) {
          this->m_heap.resize(this->m_heap.size() * 2);
        }
        ++this->m_size;

        if constexpr (::std::is_integral_v<Key>) {
          if (::std::size_t(x.first) >= this->m_heap_index_fast.size()) {
            this->m_heap_index_fast.resize(::tools::pow2(::tools::ceil_log2(x.first + 1)));
          }
          this->m_heap_index_fast[x.first] = this->m_size;
        } else {
          this->m_heap_index.emplace(x.first, this->m_size);
        }
        this->m_heap[this->m_size] = x;
        this->upheap(this->m_size);
      }

      return !internal_index;
    }

    void pop() {
      assert(!this->empty());
      const Key k = this->m_heap[1].first;
      if (this->m_size > 1) {
        this->swap(1, this->m_size);
      }

      if constexpr (::std::is_integral_v<Key>) {
        this->m_heap_index_fast[k].reset();
      } else {
        this->m_heap_index.erase(k);
      }
      --this->m_size;

      if (this->m_size >= 1) {
        this->downheap(1);
      }
    }

    ::std::size_t erase(const Key& k) {
      ::std::optional<::std::size_t> internal_index = this->get_internal_index(k);
      if (!internal_index) {
        return 0;
      }

      const Priority prev_priority = this->m_heap[*internal_index].second;
      const Priority new_priority = this->m_heap[this->m_size].second;

      if (*internal_index < this->m_size) {
        this->swap(*internal_index, this->m_size);
      }

      if constexpr (::std::is_integral_v<Key>) {
        this->m_heap_index_fast[k].reset();
      } else {
        this->m_heap_index.erase(k);
      }
      --this->m_size;

      if (*internal_index <= this->m_size) {
        if (this->m_compare(prev_priority, new_priority)) {
          this->upheap(*internal_index);
        } else if (this->m_compare(new_priority, prev_priority)) {
          this->downheap(*internal_index);
        }
      }

      return 1;
    }

    friend ::std::ostream& operator<<(::std::ostream& os, binary_heap& self) {
      std::string delimiter = "";
      os << '[';
      for (::std::size_t i = 1; i <= self.m_size; ++i) {
        os << delimiter << '[' << self.m_heap[i].first << ", " << self.m_heap[i].second << ']';
        delimiter = ", ";
      }
      os << ']';
      return os;
    }
  };
}

#endif
