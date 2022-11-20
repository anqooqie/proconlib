#ifndef TOOLS_EXTEND_INPUT_HPP
#define TOOLS_EXTEND_INPUT_HPP

// WARNING:
// This file adds functions to std namespace for convenience.
// Strictly speaking, it is not allowed in C++.
// It makes the program ill-formed to include this file, and may cause undefined behavior.

#include <array>
#include <iostream>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>
#include "tools/has_mod.hpp"

namespace tools {
  namespace detail {
    namespace extend_input {
      template <typename T>
      ::std::istream& read(::std::istream& is, T& container) {
        for (auto& v : container) {
          is >> v;
        }
        return is;
      }
    }
  }
}

namespace std {
  template <class T, ::std::size_t N>
  ::std::istream& operator>>(::std::istream& is, ::std::array<T, N>& array) {
    return ::tools::detail::extend_input::read(is, array);
  }

  template <class T1, class T2>
  ::std::istream& operator>>(::std::istream& is, ::std::pair<T1, T2>& pair) {
    return is >> pair.first >> pair.second;
  }

  template <int I = 0, typename... Args>
  ::std::istream& operator>>(::std::istream& is, ::std::tuple<Args...>& tuple) {
    if constexpr (I < int(sizeof...(Args))) {
        is >> ::std::get<I>(tuple);
        return operator>><I + 1>(is, tuple);
      } else {
      return is;
    }
  }

  template <class T, class Allocator>
  ::std::istream& operator>>(::std::istream& is, ::std::vector<T, Allocator>& vector) {
    return ::tools::detail::extend_input::read(is, vector);
  }

  template <typename T>
  ::std::enable_if_t<::tools::has_mod_v<T>, ::std::istream&> operator>>(::std::istream& is, T& x) {
    long long n;
    is >> n;
    x = T(n);
    return is;
  }
}

#endif
