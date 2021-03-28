#ifndef TOOLS_LESS_BY_HPP
#define TOOLS_LESS_BY_HPP

namespace tools {

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
