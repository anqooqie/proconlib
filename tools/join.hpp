#ifndef TOOLS_JOIN_HPP
#define TOOLS_JOIN_HPP

#include <ranges>
#include <string>
#include <sstream>

namespace tools {
  template <::std::ranges::range R>
  ::std::string join(R&& e, const ::std::string& delimiter) {
    ::std::ostringstream ss;
    auto it = ::std::ranges::begin(e);
    const auto end = ::std::ranges::end(e);
    if (it != end) {
      ss << *it;
      for (++it; it != end; ++it) {
        ss << delimiter << *it;
      }
    }
    return ss.str();
  }
}

#endif
