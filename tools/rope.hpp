#ifndef TOOLS_ROPE_HPP
#define TOOLS_ROPE_HPP

#include <ext/rope>

namespace tools {
  template <typename T>
  using rope = __gnu_cxx::rope<T>;
}

#endif
