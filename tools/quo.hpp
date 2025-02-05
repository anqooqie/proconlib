#ifndef TOOLS_QUO_H
#define TOOLS_QUO_H

#include <cassert>
#include <type_traits>

namespace tools {

  template <typename M, typename N>
  constexpr ::std::common_type_t<M, N> quo(const M a, const N b) {
    assert(b != 0);

    if (a >= 0) {
      return a / b;
    } else {
      if (b >= 0) {
        return (a + 1) / b - 1;
      } else {
        return (a + 1) / b + 1;
      }
    }
  }
}

#endif
