#ifndef TOOLS_ALPHABETICAL_ORDER_HPP
#define TOOLS_ALPHABETICAL_ORDER_HPP

#include <array>
#include <cassert>
#include <limits>

namespace tools {
  constexpr int alphabetical_order(const char c) noexcept {
    static constexpr auto map = []() {
      std::array<int, std::numeric_limits<unsigned char>::max() + 1> m{};
      m.fill(-1);

      constexpr char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      constexpr char lower[] = "abcdefghijklmnopqrstuvwxyz";
      for (int i = 0; i < 26; ++i) {
        m[static_cast<unsigned char>(upper[i])] = i;
        m[static_cast<unsigned char>(lower[i])] = i;
      }
      return m;
    }();

    assert(map[static_cast<unsigned char>(c)] != -1);
    return map[static_cast<unsigned char>(c)];
  }
}

#endif
