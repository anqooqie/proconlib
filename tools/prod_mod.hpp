#ifndef TOOLS_PROD_MOD_HPP
#define TOOLS_PROD_MOD_HPP

namespace tools {

  /**
   * x * y (mod m)
   * License: CC0
   * @author anqooqie
   * @param <T1> type of x
   * @param <T2> type of y
   * @param <T3> type of m
   * @param x x
   * @param y y
   * @param m m
   * @return x * y (mod m)
   */
  template <typename T1, typename T2, typename T3>
  constexpr T3 prod_mod(const T1 x, const T2 y, const T3 m) {
    using u128 = unsigned __int128;
    u128 prod_mod = u128(x >= 0 ? x : -x) * u128(y >= 0 ? y : -y) % u128(m);
    if (((x >= 0) ^ (y >= 0)) == 1) prod_mod = u128(m) - prod_mod;
    return prod_mod;
  }
}

#endif
