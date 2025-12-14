#ifndef TOOLS_GETTER_RESULT_HPP
#define TOOLS_GETTER_RESULT_HPP

#include <type_traits>

namespace tools {
  template <typename T, typename U>
  struct getter_result {
    using type = std::conditional_t<std::is_lvalue_reference_v<T>, const U&, U>;
  };

  template <typename T, typename U>
  using getter_result_t = typename tools::getter_result<T, U>::type;
}

#endif
