#ifndef TOOLS_JOIN_HPP
#define TOOLS_JOIN_HPP

#include <string>
#include <sstream>
#include <iterator>

namespace tools {

  template <typename Iterator>
  ::std::string join(const Iterator begin, const Iterator end, const ::std::string& delimiter) {
    ::std::ostringstream ss;
    if (begin != end) {
      ss << *begin;
      for (auto it = ::std::next(begin); it != end; ++it) {
        ss << delimiter << *it;
      }
    }
    return ss.str();
  }

  template <typename Iterator, typename F>
  ::std::string join(const Iterator begin, const Iterator end, const F& mapper, const ::std::string& delimiter) {
    ::std::ostringstream ss;
    if (begin != end) {
      ss << mapper(*begin);
      for (auto it = ::std::next(begin); it != end; ++it) {
        ss << delimiter << mapper(*it);
      }
    }
    return ss.str();
  }
}

#endif
