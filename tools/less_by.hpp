#ifndef TOOLS_LESS_BY_HPP
#define TOOLS_LESS_BY_HPP

#include <functional>

namespace tools {

  template <typename F>
  class less_by {
    F m_selector;

  public:
    less_by() = default;
    explicit less_by(const F& selector) : m_selector(selector) {
    }

    template <typename T>
    bool operator()(const T& x, const T& y) const {
      return ::std::invoke(this->m_selector, x) < ::std::invoke(this->m_selector, y);
    }
  };
}

#endif
