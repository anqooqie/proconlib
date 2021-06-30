#ifndef TOOLS_MEX_HPP
#define TOOLS_MEX_HPP

#include <iostream>
#include "tools/interval_set.hpp"

namespace tools {
  template <typename T>
  class mex {
  private:
    ::tools::interval_set<T, true> m_intervals;

  public:
    void insert(const T& x) {
      this->m_intervals.insert(x, x);
    }

    void insert(const T& l, const T& r) {
      this->m_intervals.insert(l, r);
    }

    void erase(const T& x) {
      this->m_intervals.erase(x, x);
    }

    void erase(const T& l, const T& r) {
      this->m_intervals.erase(l, r);
    }

    T query(const T& min) const {
      auto it = this->m_intervals.find(min);
      return it != this->m_intervals.end() ? it->second + 1 : min;
    }

    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::mex<T>& self) {
      return os << self.m_intervals;
    }
  };
}

#endif
