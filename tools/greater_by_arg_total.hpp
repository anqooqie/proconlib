#ifndef TOOLS_GREATER_BY_ARG_TOTAL_HPP
#define TOOLS_GREATER_BY_ARG_TOTAL_HPP

#include "tools/less_by_arg_total.hpp"
#include "tools/vector2.hpp"

namespace tools {

  template <typename T>
  class greater_by_arg_total {
  private:
    ::tools::less_by_arg_total<T> m_comp;

  public:
    greater_by_arg_total() = default;
    greater_by_arg_total(const ::tools::greater_by_arg_total<T>&) = default;
    greater_by_arg_total(::tools::greater_by_arg_total<T>&&) = default;
    ~greater_by_arg_total() = default;
    ::tools::greater_by_arg_total<T>& operator=(const ::tools::greater_by_arg_total<T>&) = default;
    ::tools::greater_by_arg_total<T>& operator=(::tools::greater_by_arg_total<T>&&) = default;

    greater_by_arg_total(const ::tools::vector2<T>& o, const ::tools::vector2<T>& d) : m_comp(o, d) {
    }

    bool operator()(const ::tools::vector2<T>& a, const ::tools::vector2<T>& b) const {
      return this->m_comp(b, a);
    }
  };
}

#endif
