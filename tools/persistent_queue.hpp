#ifndef TOOLS_PERSISTENT_QUEUE_HPP
#define TOOLS_PERSISTENT_QUEUE_HPP

#include <vector>
#include <cstddef>
#include <cassert>
#include <type_traits>
#include <limits>

namespace tools {
  template <typename T>
  class persistent_queue_buffer;

  namespace detail {
    namespace persistent_queue {
      template <typename T>
      struct node;
    }
  }

  template <typename T>
  class persistent_queue;

  template <typename T>
  class persistent_queue_buffer {
  private:
    ::std::vector<::tools::detail::persistent_queue::node<T>> m_nodes;
    ::std::vector<::tools::persistent_queue<T>> m_queues;

  public:
    persistent_queue_buffer() = default;
    persistent_queue_buffer(const ::tools::persistent_queue_buffer<T>&) = default;
    persistent_queue_buffer(::tools::persistent_queue_buffer<T>&&) = default;
    ~persistent_queue_buffer() = default;
    ::tools::persistent_queue_buffer<T>& operator=(const ::tools::persistent_queue_buffer<T>&) = default;
    ::tools::persistent_queue_buffer<T>& operator=(::tools::persistent_queue_buffer<T>&&) = default;

    bool empty() const {
      return this->m_queues.empty();
    }

    ::std::size_t size() const {
      return this->m_queues.size();
    }

    ::tools::persistent_queue<T> operator[](const ::std::size_t i) const {
      assert(i < this->size());
      return this->m_queues[i];
    }

    const ::tools::persistent_queue<T>& front() const {
      assert(!this->empty());
      return this->m_queues.front();
    }

    const ::tools::persistent_queue<T>& back() const {
      assert(!this->empty());
      return this->m_queues.back();
    }

    void push_back(const ::tools::persistent_queue<T>& x) {
      this->m_queues.push_back(x);
    }

    template <typename... Args>
    ::tools::persistent_queue<T>& emplace_back(Args&&... args) {
      return this->m_queues.emplace_back(this, ::std::forward<Args>(args)...);
    }

    void pop_back() {
      this->m_queues.pop_back();
    }

    void clear() {
      this->m_queues.clear();
    }

    friend ::tools::persistent_queue<T>;
  };

  namespace detail {
    namespace persistent_queue {
      template <typename T>
      struct node {
      private:
        ::std::vector<::std::size_t> m_ancestors;
        ::std::size_t m_depth;
        T m_value;

      public:
        node() = default;
        node(const ::tools::detail::persistent_queue::node<T>&) = default;
        node(::tools::detail::persistent_queue::node<T>&&) = default;
        ~node() = default;
        ::tools::detail::persistent_queue::node<T>& operator=(const ::tools::detail::persistent_queue::node<T>&) = default;
        ::tools::detail::persistent_queue::node<T>& operator=(::tools::detail::persistent_queue::node<T>&&) = default;

        node(const ::std::vector<::std::size_t>& ancestors, const ::std::size_t depth, const T& value) : m_ancestors(ancestors), m_depth(depth), m_value(value) {
        }

        const ::std::vector<::std::size_t>& ancestors() const {
          return this->m_ancestors;
        }
        ::std::size_t depth() const {
          return this->m_depth;
        }
        const T& value() const {
          return this->m_value;
        }
      };
    }
  }

  template <typename T>
  class persistent_queue {
  private:
    static const ::std::size_t EMPTY = ::std::numeric_limits<::std::size_t>::max();
    ::tools::persistent_queue_buffer<T> *m_buffer;
    ::std::size_t m_front;
    ::std::size_t m_back;

    persistent_queue(::tools::persistent_queue_buffer<T> * const buffer, const ::std::size_t front, const ::std::size_t back) : m_buffer(buffer), m_front(front), m_back(back) {
    }

  public:
    persistent_queue() = default;
    persistent_queue(const ::tools::persistent_queue<T>&) = default;
    persistent_queue(::tools::persistent_queue<T>&&) = default;
    ~persistent_queue() = default;
    ::tools::persistent_queue<T>& operator=(const ::tools::persistent_queue<T>&) = default;
    ::tools::persistent_queue<T>& operator=(::tools::persistent_queue<T>&&) = default;

    explicit persistent_queue(::tools::persistent_queue_buffer<T> * const buffer) : m_buffer(buffer), m_front(EMPTY), m_back(EMPTY) {
    }

    bool empty() const {
      return this->m_front == EMPTY && this->m_back == EMPTY;
    }

    ::std::size_t size() const {
      return this->empty() ? 0 : this->m_buffer->m_nodes[this->m_back].depth() - this->m_buffer->m_nodes[this->m_front].depth() + 1;
    }

    T front() const {
      assert(!this->empty());
      return this->m_buffer->m_nodes[this->m_front].value();
    }

    T back() const {
      assert(!this->empty());
      return this->m_buffer->m_nodes[this->m_back].value();
    }

    ::tools::persistent_queue<T> push(const T& x) const {
      ::std::vector<::std::size_t> ancestors;
      if (!this->empty()) {
        ::std::size_t i = 0;
        ::std::size_t v = this->m_back;
        while (true) {
          ancestors.push_back(v);
          if (this->m_buffer->m_nodes[v].ancestors().size() <= i) break;
          v = this->m_buffer->m_nodes[v].ancestors()[i];
          ++i;
        }
      }
      this->m_buffer->m_nodes.emplace_back(ancestors, this->empty() ? 0 : this->m_buffer->m_nodes[this->m_back].depth() + 1, x);
      return ::tools::persistent_queue<T>(this->m_buffer, this->empty() ? this->m_buffer->m_nodes.size() - 1 : this->m_front, this->m_buffer->m_nodes.size() - 1);
    }

    ::tools::persistent_queue<T> pop() const {
      assert(!this->empty());
      if (this->size() == 1) {
        return ::tools::persistent_queue<T>(this->m_buffer, EMPTY, EMPTY);
      }
      ::std::size_t v = this->m_back;
      for (::std::size_t d = this->size() - 2, i = 0; d > 0; d /= 2, ++i) {
        if (d % 2 == 1) {
          v = this->m_buffer->m_nodes[v].ancestors()[i];
        }
      }
      return ::tools::persistent_queue<T>(this->m_buffer, v, this->m_back);
    }

    template <typename... Args>
    ::tools::persistent_queue<T> emplace(Args&&... args) const {
      return this->push(T(::std::forward<Args>(args)...));
    }
  };
}

#endif
