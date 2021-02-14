#ifndef TOOLS_FIND_CYCLE_HPP
#define TOOLS_FIND_CYCLE_HPP

#include <utility>
#include <cstdint>

namespace tools {

  /**
   * Floyd's cycle-finding algorithm
   * License: CC0
   * @author anqooqie
   * @param seed the initial state
   * @param f the function which generates the next state
   * @return the length of head and the length of cycle
   */
  template <typename T, typename F>
  ::std::pair<::std::int_fast64_t, ::std::int_fast64_t> find_cycle(const T& seed, const F& f) {
    ::std::int_fast64_t i = 1;
    ::std::int_fast64_t j = 2;
    T x = f(seed);
    T y = f(f(seed));
    for (; x != y; ++i, j += 2, x = f(x), y = f(f(y)));

    i = 0;
    x = seed;
    for (; x != y; ++i, ++j, x = f(x), y = f(y));

    const ::std::int_fast64_t head = i;

    ++i;
    j = i + 1;
    x = f(x);
    y = f(f(y));
    for (; x != y; ++i, j += 2, x = f(x), y = f(f(y)));

    const ::std::int_fast64_t cycle = j - i;

    return ::std::make_pair(head, cycle);
  }
}

#endif
