#ifndef TOOLS_FLOOR_LOG_HPP
#define TOOLS_FLOOR_LOG_HPP

namespace tools {

  /**
   * floor of logarithm
   * License: CC0
   * @author anqooqie
   * @param base $b$
   * @param antilogarithm $x$
   * @return $\left\lfloor \log_b(x) \right\rfloor$
   */
  template <typename T>
  T floor_log(const T& base, T antilogarithm) {
    i64 logarithm = 0;
    while (antilogarithm >= base) {
      ++logarithm;
      antilogarithm /= base;
    }
    return logarithm;
  }
}

#endif
