#ifndef TOOLS_GREATER_BY_HPP
#define TOOLS_GREATER_BY_HPP

namespace tools {

  /**
   * `std::greater` by key
   * License: CC0
   *
   * Usage:
   * ```
   * std::sort(a.begin(), a.end(), tools::greater_by([](int a_i) { return std::abs(x); }));
   * ```
   *
   * @author anqooqie
   * @param <F> type of selector
   */
  template <class F>
  class greater_by {
  private:
    F selector;

  public:
    greater_by(const F& selector) : selector(selector) {
    }

    template <class T>
    bool operator()(const T& x, const T& y) const {
      return selector(x) > selector(y);
    }
  };
}

#endif
