#ifndef TOOLS_MEX_HPP
#define TOOLS_MEX_HPP

#include <map>
#include <utility>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <string>

namespace tools {
  template <typename T>
  class mex {
  private:
    // closed intervals
    ::std::map<T, T> m_intervals;

  public:
    // The method accepts a half-open interval.
    void add(const T& l, T r) {
      --r;

      if (l > r) {
        return;
      }

      const auto [lower_bound, min] = [&]() {
        const auto l_next_it = this->m_intervals.lower_bound(l);

        if (l_next_it == this->m_intervals.begin()) {
          return ::std::make_pair(l_next_it, l);
        }

        const auto l_prev_it = ::std::prev(l_next_it);
        if (l_prev_it->second + 1 < l) {
          return ::std::make_pair(l_next_it, l);
        }

        return ::std::make_pair(l_prev_it, l_prev_it->first);
      }();

      const auto [upper_bound, max] = [&]() {
        const auto r_next_it = this->m_intervals.upper_bound(r + 1);

        if (r_next_it == this->m_intervals.begin()) {
          return ::std::make_pair(r_next_it, r);
        }

        const auto r_prev_it = ::std::prev(r_next_it);
        if (r_prev_it->second + 1 < l) {
          return ::std::make_pair(r_next_it, r);
        }

        return ::std::make_pair(r_next_it, ::std::max(r, r_prev_it->second));
      }();

      this->m_intervals.erase(lower_bound, upper_bound);
      this->m_intervals.emplace(min, max);
    }

    void add(const T& x) {
      this->add(x, x + 1);
    }

    T query(const T& min) const {
      auto it = this->m_intervals.upper_bound(min);
      if (it == this->m_intervals.begin()) {
        return min;
      }
      --it;
      return min <= it->second ? it->second + 1 : min;
    }

    T query() const {
      return this->query(0);
    }

    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::mex<T>& self) {
      ::std::string delimiter = "";
      for (const auto& [l, r] : self.m_intervals) {
        os << delimiter << '[' << l << ", " << r << ']';
        delimiter = ", ";
      }
      return os;
    }
  };
}

#endif
