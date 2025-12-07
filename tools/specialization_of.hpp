#ifndef TOOLS_SPECIALIZATION_OF_HPP
#define TOOLS_SPECIALIZATION_OF_HPP

#include <type_traits>

namespace tools {
  namespace detail {
    namespace specialization_of {
      template <typename, template <typename...> typename>
      struct trait : std::false_type {};

      template <template <typename...> typename U, typename... Args>
      struct trait<U<Args...>, U> : std::true_type {};
    }
  }

  template <typename T, template <typename...> typename U>
  concept specialization_of = tools::detail::specialization_of::trait<T, U>::value;
}

#endif
