#ifndef TOOLS_UTIL_HPP
#define TOOLS_UTIL_HPP

// To see the details of my library, visit my GitHub Pages.
// https://anqooqie.github.io/proconlib/

#ifdef LOCAL
  #ifndef _GLIBCXX_DEBUG
    #define _GLIBCXX_DEBUG
  #endif
#else
  #ifndef NDEBUG
    #define NDEBUG
  #endif
#endif

#include <bits/stdc++.h>
#include "tools/resize.hpp"
#include "tools/fill.hpp"

using i64 = ::std::int_fast64_t;
using u64 = ::std::uint_fast64_t;
using i32 = ::std::int_fast32_t;
using u32 = ::std::uint_fast32_t;

#define ALL(x) ::std::begin((x)), ::std::end((x))
#define REP(i, n) for (::std::int_fast64_t i = 0; i < static_cast<::std::int_fast64_t>(n); ++i)

namespace tools {
  namespace detail {
    namespace util {
      template <typename T>
      class has_mod {
      private:
        template <typename U>
        static auto check(U x) -> decltype(x.mod(), ::std::true_type{});
        static ::std::false_type check(...);

      public:
        static const bool value = decltype(check(::std::declval<T>()))::value;
      };

      template <typename T>
      ::std::istream& read(::std::istream& is, T& container) {
        for (auto& v : container) {
          is >> v;
        }
        return is;
      }

      template <typename T>
      ::std::ostream& debug_print(::std::ostream& os, const T& container) {
        ::std::string delimiter = "";
        os << '[';
        for (const auto& v : container) {
          os << delimiter << v;
          delimiter = ", ";
        }
        os << ']';
        return os;
      }
    }
  }
}

template <class T, class Allocator>
::std::istream& operator>>(::std::istream& is, ::std::vector<T, Allocator>& vector) {
  return ::tools::detail::util::read(is, vector);
}
template <class T, ::std::size_t N>
::std::istream& operator>>(::std::istream& is, ::std::array<T, N>& array) {
  return ::tools::detail::util::read(is, array);
}
template <class T, class Allocator>
::std::ostream& operator<<(::std::ostream& os, const ::std::vector<T, Allocator>& vector) {
  return ::tools::detail::util::debug_print(os, vector);
}
template <class T, ::std::size_t N>
::std::ostream& operator<<(::std::ostream& os, const ::std::array<T, N>& array) {
  return ::tools::detail::util::debug_print(os, array);
}
template <class Key, class Hash, class Pred, class Allocator>
::std::ostream& operator<<(::std::ostream& os, const ::std::unordered_set<Key, Hash, Pred, Allocator>& unordered_set) {
  return ::tools::detail::util::debug_print(os, unordered_set);
}

template <class T, class Container>
::std::ostream& operator<<(::std::ostream& os, ::std::stack<T, Container>& stack) {
  ::std::stack<T, Container> other;
  ::std::string delimiter = "";
  os << '[';
  while (!stack.empty()) {
    os << delimiter << stack.top();
    delimiter = ", ";
    other.push(stack.top());
    stack.pop();
  }
  os << ']';

  while (!other.empty()) {
    stack.push(other.top());
    other.pop();
  }

  return os;
}

template <class T, class Container>
::std::ostream& operator<<(::std::ostream& os, ::std::queue<T, Container>& queue) {
  ::std::queue<T, Container> other = queue;
  ::std::string delimiter = "";
  os << '[';
  while (!queue.empty()) {
    os << delimiter << queue.front();
    delimiter = ", ";
    queue.pop();
  }
  os << ']';

  queue = ::std::move(other);
  return os;
}

template <class T1, class T2>
::std::istream& operator>>(::std::istream& is, ::std::pair<T1, T2>& pair) {
  return is >> pair.first >> pair.second;
}
template <class T1, class T2>
::std::ostream& operator<<(::std::ostream& os, const ::std::pair<T1, T2>& pair) {
  return os << '[' << pair.first << ", " << pair.second << ']';
}
template <int I = 0, typename... Args>
::std::istream& operator>>(::std::istream& is, const ::std::tuple<Args...>& tuple) {
  if constexpr (I < int(sizeof...(Args))) {
    is >> ::std::get<I>(tuple);
    return operator>><I + 1>(is, tuple);
  } else {
    return is;
  }
}
template <int I = -1, typename... Args>
::std::ostream& operator<<(::std::ostream& os, const ::std::tuple<Args...>& tuple) {
  if constexpr (I == -1) {
    os << '[';
  } else if constexpr (I == int(sizeof...(Args))) {
    os << ']';
  } else if constexpr (I == 0) {
    os << ::std::get<I>(tuple);
  } else {
    os << ", " << ::std::get<I>(tuple);
  }

  if constexpr (I < int(sizeof...(Args))) {
    return operator<<<I + 1>(os, tuple);
  } else {
    return os;
  }
}

template <typename T>
auto operator>>(::std::istream& is, T& x) -> ::std::enable_if_t<::tools::detail::util::has_mod<T>::value, ::std::istream&> {
  ::std::int_fast64_t n;
  is >> n;
  x = T(n);
  return is;
}
template <typename T>
auto operator<<(::std::ostream& os, const T& x) -> ::std::enable_if_t<::tools::detail::util::has_mod<T>::value, ::std::ostream&> {
  return os << x.val();
}

#endif
