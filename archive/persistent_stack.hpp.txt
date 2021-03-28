#ifndef PERSISTENT_STACK_HPP
#define PERSISTENT_STACK_HPP

#include <memory>
#include <cstddef>
#include <iterator>
#include <utility>
#include <vector>
#include <algorithm>
#include <type_traits>
#include <string>

/*
usage:

tools::persistent_stack<std::int_fast64_t> stack;
stack = stack.push(42);
stack = stack.pop();
*/

namespace tools {
  template <typename T>
  class persistent_stack {
  private:
    class node {
    public:
      std::shared_ptr<node> next;
      T value;
      node(const std::shared_ptr<node>& next, const T& value) :
        next(next), value(value) {
      }
    };

    std::shared_ptr<node> m_root;
    std::size_t m_size;

    persistent_stack(const std::shared_ptr<node>& root, const std::size_t size) :
      m_root(root), m_size(size) {
    }

  public:
    class iterator {
      friend class persistent_stack<T>;

    private:
      std::shared_ptr<node> ptr;

      iterator(const std::shared_ptr<node>& ptr) :
        ptr(ptr) {
      }

    public:
      bool operator==(const iterator& other) const {
        return this->ptr == other.ptr;
      }
      bool operator!=(const iterator& other) const {
        return !(*this == other);
      }
      T operator*() const {
        return this->ptr->value;
      }
      iterator& operator++() {
        this->ptr = this->ptr->next;
        return *this;
      }
      using difference_type = std::ptrdiff_t;
      using value_type = T;
      using pointer = T*;
      using reference = T&;
      using iterator_category = std::input_iterator_tag;
    };

    persistent_stack() :
      m_root(), m_size(0) {
    }

    const T& top() const {
      return this->m_root->value;
    }

    bool empty() const {
      return this->m_size == 0;
    }

    std::size_t size() const {
      return this->m_size;
    }

    persistent_stack<T> push(const T& x) const {
      return persistent_stack<T>(std::make_shared<node>(this->m_root, x), this->m_size + 1);
    }

    template <class... Args>
    persistent_stack<T> emplace(Args&&... args) const {
      return persistent_stack<T>(std::make_shared<node>(this->m_root, T(std::forward<Args>(args)...)), this->m_size + 1);
    }

    persistent_stack<T> pop() const {
      return persistent_stack<T>(this->m_root->next, this->m_size - 1);
    }

    iterator begin() const {
      return iterator(this->m_root);
    }

    iterator end() const {
      return iterator(std::shared_ptr<node>());
    }

    bool operator==(const persistent_stack<T>& other) const {
      if (this->m_size != other.m_size) return false;
      for (auto it1 = this->begin(), it2 = other.begin(); it1 != this->end() && it2 != other.end(); ++it1, ++it2) {
        if (*it1 != *it2) return false;
      }
      return true;
    }
    bool operator!=(const persistent_stack<T>& other) const {
      return !(*this == other);
    }
    bool operator<(const persistent_stack<T>& other) const {
      if (this->m_size < other.m_size) return true;
      for (auto it1 = this->begin(), it2 = other.begin(); it1 != this->end() && it2 != other.end(); ++it1, ++it2) {
        if (*it1 < *it2) return true;
        if (*it1 > *it2) return false;
      }
      return false;
    }

    explicit operator std::vector<T>() const {
      std::vector<T> vector;
      vector.reserve(this->m_size);
      std::copy(this->begin(), this->end(), std::back_inserter(vector));
      std::reverse(vector.begin(), vector.end());
      return vector;
    }

    template <typename U = T, typename std::enable_if<std::is_same<U, char>::value, std::nullptr_t>::type = nullptr>
    explicit operator std::string() const {
      const std::vector<char> vector = static_cast<std::vector<char>>(*this);
      return std::string(vector.begin(), vector.end());
    }

    using value_type = T;
    using size_type = std::size_t;
    using reference = T&;
    using const_reference = const T&;
  };
}

#endif
