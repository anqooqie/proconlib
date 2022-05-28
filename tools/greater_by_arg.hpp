#ifndef TOOLS_GREATER_BY_ARG_HPP
#define TOOLS_GREATER_BY_ARG_HPP

#include "tools/less_by_arg.hpp"
#include "tools/vector2.hpp"

namespace tools {

  template <typename T>
  class greater_by_arg {
  private:
    ::tools::less_by_arg<T> m_comp;

  public:
    greater_by_arg() = default;
    greater_by_arg(const ::tools::greater_by_arg<T>&) = default;
    greater_by_arg(::tools::greater_by_arg<T>&&) = default;
    ~greater_by_arg() = default;
    ::tools::greater_by_arg<T>& operator=(const ::tools::greater_by_arg<T>&) = default;
    ::tools::greater_by_arg<T>& operator=(::tools::greater_by_arg<T>&&) = default;

    greater_by_arg(const ::tools::vector2<T>& o, const ::tools::vector2<T>& d) : m_comp(o, d) {
    }

    bool operator()(const ::tools::vector2<T>& a, const ::tools::vector2<T>& b) const {
      return this->m_comp(b, a);
    }
  };
}

#endif
