#ifndef TOOLS_MAKE_WIDER_HPP
#define TOOLS_MAKE_WIDER_HPP

#include <limits>
#include <type_traits>
#include "tools/is_signed.hpp"
#include "tools/make_signed.hpp"
#include "tools/make_unsigned.hpp"
#include "tools/non_bool_integral.hpp"
#include "tools/uint128_t.hpp"

namespace tools {
  namespace detail::make_wider {
    template <typename T>
    struct safe_make_signed {
      using type = tools::make_signed_t<T>;
    };
    template <>
    struct safe_make_signed<void> {
      using type = void;
    };
    template <typename T>
    using safe_make_signed_t = typename safe_make_signed<T>::type;
  }

  template <tools::non_bool_integral T>
  class make_wider {
    using R = std::remove_cv_t<T>;
    using U = tools::make_unsigned_t<R>;
    using W = std::conditional_t<std::numeric_limits<U>::digits * 2 <= std::numeric_limits<unsigned char>::digits, unsigned char,
              std::conditional_t<std::numeric_limits<U>::digits * 2 <= std::numeric_limits<unsigned short>::digits, unsigned short,
              std::conditional_t<std::numeric_limits<U>::digits * 2 <= std::numeric_limits<unsigned int>::digits, unsigned int,
              std::conditional_t<std::numeric_limits<U>::digits * 2 <= std::numeric_limits<unsigned long>::digits, unsigned long,
              std::conditional_t<std::numeric_limits<U>::digits * 2 <= std::numeric_limits<unsigned long long>::digits, unsigned long long,
              std::conditional_t<std::numeric_limits<U>::digits * 2 <= std::numeric_limits<tools::uint128_t>::digits, tools::uint128_t,
              void>>>>>>;
    using signedness_recovered = std::conditional_t<tools::is_signed_v<R>, tools::detail::make_wider::safe_make_signed_t<W>, W>;
    using const_recovered = std::conditional_t<std::is_const_v<T>, std::add_const_t<signedness_recovered>, signedness_recovered>;
    using volatile_recovered = std::conditional_t<std::is_volatile_v<T>, std::add_volatile_t<const_recovered>, const_recovered>;

  public:
    using type = volatile_recovered;
  };

  template <tools::non_bool_integral T>
  using make_wider_t = typename tools::make_wider<T>::type;
}

#endif
