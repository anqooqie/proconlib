#ifndef TOOLS_GREATER_BY_FIRST_HPP
#define TOOLS_GREATER_BY_FIRST_HPP

#include <utility>

namespace tools {

  class greater_by_first {
  public:
    template <class T1, class T2>
    bool operator()(const ::std::pair<T1, T2>& x, const ::std::pair<T1, T2>& y) const {
      return x.first > y.first;
    }
  };
}

#endif
