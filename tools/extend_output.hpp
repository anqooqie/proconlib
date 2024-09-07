#ifndef TOOLS_EXTEND_OUTPUT_HPP
#define TOOLS_EXTEND_OUTPUT_HPP

// WARNING:
// This file adds functions to std namespace for convenience.
// Strictly speaking, it is not allowed in C++.
// It makes the program ill-formed to include this file, and may cause undefined behavior.

#include <array>
#include <iostream>
#include <map>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include "tools/has_mod.hpp"

namespace tools {
  namespace detail {
    namespace extend_output {
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

namespace std {
  template <class T, ::std::size_t N>
  ::std::ostream& operator<<(::std::ostream& os, const ::std::array<T, N>& array) {
    return ::tools::detail::extend_output::debug_print(os, array);
  }
  
  template <class Key, class T, class Compare, class Allocator>
  ::std::ostream& operator<<(::std::ostream& os, const ::std::map<Key, T, Compare, Allocator>& map) {
    return ::tools::detail::extend_output::debug_print(os, map);
  }

  template <typename T>
  ::std::ostream& operator<<(::std::ostream& os, const ::std::optional<T>& optional) {
    if (optional) {
      return os << *optional;
    } else {
      return os << "null";
    }
  }
  
  template <class T1, class T2>
  ::std::ostream& operator<<(::std::ostream& os, const ::std::pair<T1, T2>& pair) {
    return os << '[' << pair.first << ", " << pair.second << ']';
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
  
  template <class Key, class Compare, class Allocator>
  ::std::ostream& operator<<(::std::ostream& os, const ::std::set<Key, Compare, Allocator>& set) {
    return ::tools::detail::extend_output::debug_print(os, set);
  }

  template <class T, class Container>
  ::std::ostream& operator<<(::std::ostream& os, ::std::stack<T, Container>& stack) {
    ::std::stack<T, Container> other;
    while (!stack.empty()) {
      other.push(stack.top());
      stack.pop();
    }
  
    ::std::string delimiter = "";
    os << '[';
    while (!other.empty()) {
      os << delimiter << other.top();
      delimiter = ", ";
      stack.push(other.top());
      other.pop();
    }
    os << ']';
  
    return os;
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
  
  template <class Key, class T, class Hash, class Pred, class Allocator>
  ::std::ostream& operator<<(::std::ostream& os, const ::std::unordered_map<Key, T, Hash, Pred, Allocator>& unordered_map) {
    return ::tools::detail::extend_output::debug_print(os, unordered_map);
  }
  
  template <class Key, class Hash, class Pred, class Allocator>
  ::std::ostream& operator<<(::std::ostream& os, const ::std::unordered_set<Key, Hash, Pred, Allocator>& unordered_set) {
    return ::tools::detail::extend_output::debug_print(os, unordered_set);
  }
  
  template <class T, class Allocator>
  ::std::ostream& operator<<(::std::ostream& os, const ::std::vector<T, Allocator>& vector) {
    return ::tools::detail::extend_output::debug_print(os, vector);
  }
  
  template <typename T>
  ::std::enable_if_t<::tools::has_mod_v<T>, ::std::ostream&> operator<<(::std::ostream& os, const T& x) {
    return os << x.val();
  }
}

#endif
