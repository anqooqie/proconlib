#ifndef TOOLS_SWAG_HPP
#define TOOLS_SWAG_HPP

#include <stack>
#include <utility>
#include <cassert>

namespace tools {
  template <typename M>
  class swag {
  private:
    using T = typename M::T;
    ::std::stack<::std::pair<T, T>> m_head;
    ::std::stack<::std::pair<T, T>> m_tail;

    T head_prod() const {
      return this->m_head.empty() ? M::e() : this->m_head.top().second;
    }
    T tail_prod() const {
      return this->m_tail.empty() ? M::e() : this->m_tail.top().second;
    }

  public:
    swag() = default;
    swag(const ::tools::swag<M>&) = default;
    swag(::tools::swag<M>&&) = default;
    ~swag() = default;
    ::tools::swag<M>& operator=(const ::tools::swag<M>&) = default;
    ::tools::swag<M>& operator=(::tools::swag<M>&&) = default;

    bool empty() const {
      return this->m_head.empty() && this->m_tail.empty();
    }

    void push_back(const T& x) {
      this->m_tail.emplace(x, M::op(this->tail_prod(), x));
    }

    template <typename... Args>
    void emplace_back(Args&&... args) {
      this->push_back(T(::std::forward<Args>(args)...));
    }

    void pop_back() {
      assert(!this->empty());
      if (this->m_tail.empty()) {
        ::std::stack<T> tmp;
        while (tmp.size() + 1 < this->m_head.size()) {
          tmp.push(this->m_head.top().first);
          this->m_head.pop();
        }
        while (!this->m_head.empty()) {
          this->m_tail.emplace(this->m_head.top().first, M::op(this->tail_prod(), this->m_head.top().first));
          this->m_head.pop();
        }
        while (!tmp.empty()) {
          this->m_head.emplace(tmp.top(), M::op(tmp.top(), this->head_prod()));
          tmp.pop();
        }
      }
      this->m_tail.pop();
    }

    void push_front(const T& x) {
      this->m_head.emplace(x, M::op(x, this->head_prod()));
    }

    template <typename... Args>
    void emplace_front(Args&&... args) {
      this->push_front(T(::std::forward<Args>(args)...));
    }

    void pop_front() {
      assert(!this->empty());
      if (this->m_head.empty()) {
        ::std::stack<T> tmp;
        while (this->m_tail.size() > tmp.size() + 1) {
          tmp.push(this->m_tail.top().first);
          this->m_tail.pop();
        }
        while (!this->m_tail.empty()) {
          this->m_head.emplace(this->m_tail.top().first, M::op(this->m_tail.top().first, this->head_prod()));
          this->m_tail.pop();
        }
        while (!tmp.empty()) {
          this->m_tail.emplace(tmp.top(), M::op(this->tail_prod(), tmp.top()));
          tmp.pop();
        }
      }
      this->m_head.pop();
    }

    T prod() const {
      return M::op(this->head_prod(), this->tail_prod());
    }
  };
}

#endif
