#ifndef TOOLS_JOIN_HPP
#define TOOLS_JOIN_HPP

#include <ranges>
#include <sstream>

namespace tools {
  template <::std::ranges::range R, typename T>
  ::std::string join(R&& e, const T& d) {
    ::std::ostringstream ss;
    auto it = ::std::ranges::begin(e);
    const auto end = ::std::ranges::end(e);
    if (it != end) {
      ss << *it;
      for (++it; it != end; ++it) {
        ss << d << *it;
      }
    }
    return ss.str();
  }
}

#endif
