#ifndef TOOLS_NOW_HPP
#define TOOLS_NOW_HPP

#include <chrono>

namespace tools {
  inline long long now() {
    return ::std::chrono::duration_cast<::std::chrono::nanoseconds>(::std::chrono::high_resolution_clock::now().time_since_epoch()).count();
  }
}

#endif
