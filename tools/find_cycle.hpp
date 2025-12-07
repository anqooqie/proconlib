#ifndef TOOLS_FIND_CYCLE_HPP
#define TOOLS_FIND_CYCLE_HPP

#include <utility>

namespace tools {

  template <typename T, typename F>
  std::pair<long long, long long> find_cycle(const T& seed, const F& f) {
    auto i = 1LL;
    auto j = 2LL;
    T x = f(seed);
    T y = f(f(seed));
    for (; x != y; ++i, j += 2, x = f(x), y = f(f(y)));

    i = 0;
    x = seed;
    for (; x != y; ++i, ++j, x = f(x), y = f(y));

    const auto head = i;

    ++i;
    j = i + 1;
    x = f(x);
    y = f(f(y));
    for (; x != y; ++i, j += 2, x = f(x), y = f(f(y)));

    const auto cycle = j - i;

    return std::make_pair(head, cycle);
  }
}

#endif
