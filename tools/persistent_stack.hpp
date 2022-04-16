#ifndef TOOLS_PERSISTENT_STACK_HPP
#define TOOLS_PERSISTENT_STACK_HPP

#include <cstddef>
#include <vector>
#include <limits>
#include <cassert>
#include <type_traits>

namespace tools {
  template <typename T>
  class persistent_stack {
  private:
    struct node {
      ::std::size_t parent;
      ::std::size_t depth;
      T value;
    };

  public:
    class buffer {
    private:
      ::std::vector<::tools::persistent_stack<T>::node> m_nodes;

    public:
      buffer() = default;
      buffer(const ::tools::persistent_stack<T>::buffer&) = default;
      buffer(::tools::persistent_stack<T>::buffer&&) = default;
      ~buffer() = default;
      ::tools::persistent_stack<T>::buffer& operator=(const ::tools::persistent_stack<T>::buffer&) = default;
      ::tools::persistent_stack<T>::buffer& operator=(::tools::persistent_stack<T>::buffer&&) = default;

      friend ::tools::persistent_stack<T>;
    };

  private:
    static const ::std::size_t EMPTY = ::std::numeric_limits<::std::size_t>::max();
    ::tools::persistent_stack<T>::buffer *m_buffer;
    ::std::size_t m_top;

    persistent_stack(::tools::persistent_stack<T>::buffer& buffer, const ::std::size_t top) : m_buffer(&buffer), m_top(top) {
    }

  public:
    persistent_stack() = default;
    persistent_stack(const ::tools::persistent_stack<T>&) = default;
    persistent_stack(::tools::persistent_stack<T>&&) = default;
    ~persistent_stack() = default;
    ::tools::persistent_stack<T>& operator=(const ::tools::persistent_stack<T>&) = default;
    ::tools::persistent_stack<T>& operator=(::tools::persistent_stack<T>&&) = default;

    explicit persistent_stack(::tools::persistent_stack<T>::buffer& buffer) : m_buffer(&buffer), m_top(EMPTY) {
    }

    bool empty() const {
      return this->m_top == EMPTY;
    }

    ::std::size_t size() const {
      return this->empty() ? 0 : this->m_buffer->m_nodes[this->m_top].depth + 1;
    }

    T top() const {
      assert(!this->empty());
      return this->m_buffer->m_nodes[this->m_top].value;
    }

    ::tools::persistent_stack<T> push(const T& x) const {
      this->m_buffer->m_nodes.emplace_back();
      this->m_buffer->m_nodes.back().parent = this->m_top;
      this->m_buffer->m_nodes.back().depth = this->empty() ? 0 : this->m_buffer->m_nodes[this->m_top].depth + 1;
      this->m_buffer->m_nodes.back().value = x;
      return ::tools::persistent_stack<T>(*this->m_buffer, this->m_buffer->m_nodes.size() - 1);
    }

    ::tools::persistent_stack<T> pop() const {
      assert(!this->empty());
      return ::tools::persistent_stack<T>(*this->m_buffer, this->m_buffer->m_nodes[this->m_top].parent);
    }

    template <typename... Args>
    ::tools::persistent_stack<T> emplace(Args&&... args) const {
      return this->push(T(::std::forward<Args>(args)...));
    }
  };
}

#endif
