#ifndef TOOLS_GREATER_BY_HPP
#define TOOLS_GREATER_BY_HPP

namespace tools {

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
