#ifndef TOOLS_FIX_HPP
#define TOOLS_FIX_HPP

#include <utility>
#include <type_traits>

namespace tools {
  template <typename F>
  struct fix : F {
    template <typename G>
    fix(G&& g) : F({std::forward<G>(g)}) {
    }

    template <typename... Args>
    decltype(auto) operator()(Args&&... args) const {
      return F::operator()(*this, std::forward<Args>(args)...);
    }
  };

  template <typename F>
  fix(F&&) -> fix<std::decay_t<F>>;
}

#endif
