#ifndef TOOLS_LESS_BY_HPP
#define TOOLS_LESS_BY_HPP

namespace tools {

  /**
   * `std::less` by key
   * License: CC0
   *
   * Usage:
   * ```
   * std::sort(a.begin(), a.end(), tools::less_by([](int a_i) { return std::abs(x); }));
   * ```
   *
   * @author anqooqie
   * @param <F> type of selector
   */
  template <class F>
  class less_by {
  private:
    F selector;

  public:
    less_by(const F& selector) : selector(selector) {
    }

    template <class T>
    bool operator()(const T& x, const T& y) const {
      return selector(x) < selector(y);
    }
  };
}

#endif
