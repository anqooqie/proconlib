#ifndef TOOLS_PERSISTENT_QUEUE_HPP
#define TOOLS_PERSISTENT_QUEUE_HPP

#include <vector>
#include <cstddef>
#include <limits>
#include <cassert>
#include <type_traits>

namespace tools {
  template <typename T>
  class persistent_queue {
  private:
    struct node {
      ::std::vector<::std::size_t> ancestors;
      ::std::size_t depth;
      T value;
    };

  public:
    class buffer {
    private:
      ::std::vector<::tools::persistent_queue<T>::node> m_nodes;

    public:
      buffer() = default;
      buffer(const ::tools::persistent_queue<T>::buffer&) = default;
      buffer(::tools::persistent_queue<T>::buffer&&) = default;
      ~buffer() = default;
      ::tools::persistent_queue<T>::buffer& operator=(const ::tools::persistent_queue<T>::buffer&) = default;
      ::tools::persistent_queue<T>::buffer& operator=(::tools::persistent_queue<T>::buffer&&) = default;

      friend ::tools::persistent_queue<T>;
    };

  private:
    static const ::std::size_t EMPTY = ::std::numeric_limits<::std::size_t>::max();
    ::tools::persistent_queue<T>::buffer *m_buffer;
    ::std::size_t m_front;
    ::std::size_t m_back;

    persistent_queue(::tools::persistent_queue<T>::buffer& buffer, const ::std::size_t front, const ::std::size_t back) : m_buffer(&buffer), m_front(front), m_back(back) {
    }

  public:
    persistent_queue() = default;
    persistent_queue(const ::tools::persistent_queue<T>&) = default;
    persistent_queue(::tools::persistent_queue<T>&&) = default;
    ~persistent_queue() = default;
    ::tools::persistent_queue<T>& operator=(const ::tools::persistent_queue<T>&) = default;
    ::tools::persistent_queue<T>& operator=(::tools::persistent_queue<T>&&) = default;

    explicit persistent_queue(::tools::persistent_queue<T>::buffer& buffer) : m_buffer(&buffer), m_front(EMPTY), m_back(EMPTY) {
    }

    bool empty() const {
      return this->m_front == EMPTY && this->m_back == EMPTY;
    }

    ::std::size_t size() const {
      return this->empty() ? 0 : this->m_buffer->m_nodes[this->m_back].depth - this->m_buffer->m_nodes[this->m_front].depth + 1;
    }

    T front() const {
      assert(!this->empty());
      return this->m_buffer->m_nodes[this->m_front].value;
    }

    T back() const {
      assert(!this->empty());
      return this->m_buffer->m_nodes[this->m_back].value;
    }

    ::tools::persistent_queue<T> push(const T& x) const {
      this->m_buffer->m_nodes.emplace_back();
      this->m_buffer->m_nodes.back().depth = this->empty() ? 0 : this->m_buffer->m_nodes[this->m_back].depth + 1;
      this->m_buffer->m_nodes.back().value = x;
      if (!this->empty()) {
        ::std::size_t i = 0;
        ::std::size_t v = this->m_back;
        while (true) {
          this->m_buffer->m_nodes.back().ancestors.push_back(v);
          if (this->m_buffer->m_nodes[v].ancestors.size() <= i) break;
          v = this->m_buffer->m_nodes[v].ancestors[i];
          ++i;
        }
      }
      return ::tools::persistent_queue<T>(*this->m_buffer, this->empty() ? this->m_buffer->m_nodes.size() - 1 : this->m_front, this->m_buffer->m_nodes.size() - 1);
    }

    ::tools::persistent_queue<T> pop() const {
      assert(!this->empty());
      if (this->size() == 1) {
        return ::tools::persistent_queue<T>(*this->m_buffer, EMPTY, EMPTY);
      }
      ::std::size_t v = this->m_back;
      for (::std::size_t d = this->size() - 2, i = 0; d > 0; d /= 2, ++i) {
        if (d % 2 == 1) {
          v = this->m_buffer->m_nodes[v].ancestors[i];
        }
      }
      return ::tools::persistent_queue<T>(*this->m_buffer, v, this->m_back);
    }

    template <typename... Args>
    ::tools::persistent_queue<T> emplace(Args&&... args) const {
      return this->push(T(::std::forward<Args>(args)...));
    }
  };
}

#endif
