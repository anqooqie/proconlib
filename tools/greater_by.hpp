#ifndef TOOLS_GREATER_BY_HPP
#define TOOLS_GREATER_BY_HPP

#include <functional>

namespace tools {

  template <typename F>
  class greater_by {
    F m_selector;

  public:
    greater_by() = default;
    explicit greater_by(const F& selector) : m_selector(selector) {
    }

    template <typename T>
    bool operator()(const T& x, const T& y) const {
      return ::std::invoke(this->m_selector, x) > ::std::invoke(this->m_selector, y);
    }
  };
}

#endif
