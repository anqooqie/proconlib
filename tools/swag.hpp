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
    ::std::stack<T> stack1;
    T stack1_prod;
    ::std::stack<::std::pair<T, T>> stack2;

    T stack2_prod() const {
      return this->stack2.empty() ? M::e() : this->stack2.top().second;
    }

  public:
    swag() : stack1_prod(M::e()) {
    }
    swag(const ::tools::swag<M>&) = default;
    swag(::tools::swag<M>&&) = default;
    ~swag() = default;
    ::tools::swag<M>& operator=(const ::tools::swag<M>&) = default;
    ::tools::swag<M>& operator=(::tools::swag<M>&&) = default;

    bool empty() const {
      return this->stack1.empty() && this->stack2.empty();
    }

    void push(const T& x) {
      this->stack1_prod = M::op(this->stack1_prod, x);
      this->stack1.push(x);
    }

    template <typename... Args>
    void emplace(Args&&... args) {
      this->push(T(::std::forward<Args>(args)...));
    }

    void pop() {
      assert(!this->empty());
      if (this->stack2.empty()) {
        while (!this->stack1.empty()) {
          this->stack2.emplace(
            this->stack1.top(),
            M::op(this->stack1.top(), this->stack2_prod())
            );
          this->stack1.pop();
        }
        this->stack1_prod = M::e();
      }
      this->stack2.pop();
    }

    T prod() const {
      return M::op(this->stack2_prod(), this->stack1_prod);
    }
  };
}

#endif
