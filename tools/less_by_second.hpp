#ifndef TOOLS_LESS_BY_SECOND_HPP
#define TOOLS_LESS_BY_SECOND_HPP

#include <utility>

namespace tools {

  class less_by_second {
  public:
    template <class T1, class T2>
    bool operator()(const ::std::pair<T1, T2>& x, const ::std::pair<T1, T2>& y) const {
      return x.second < y.second;
    }
  };
}

#endif
