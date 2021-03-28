#ifndef TOOLS_JOIN_HPP
#define TOOLS_JOIN_HPP

#include <string>
#include <sstream>

namespace tools {

  template <typename Iterator>
  ::std::string join(const Iterator begin, const Iterator end, const ::std::string delimiter) {
    ::std::ostringstream ss;
    ::std::string current_delimiter = "";
    for (Iterator it = begin; it != end; ++it) {
      ss << current_delimiter << *it;
      current_delimiter = delimiter;
    }
    return ss.str();
  }
}

#endif
