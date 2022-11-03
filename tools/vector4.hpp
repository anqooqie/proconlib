#ifndef TOOLS_VECTOR4_HPP
#define TOOLS_VECTOR4_HPP

#include <array>
#include <functional>
#include <utility>
#include <cstddef>
#include "tools/detail/vector_static_common.hpp"
#include "tools/detail/vector_common.hpp"
#include "tools/tuple_hash.hpp"

namespace tools {
  template <typename T>
  class vector4 {
  public:
    T x;
    T y;
    T z;
    T w;

  private:
    ::std::array<::std::reference_wrapper<T>, 4> m_refs;

  public:
    vector4(const T& x, const T& y, const T& z, const T& w) : x(x), y(y), z(z), w(w), m_refs({::std::ref(this->x), ::std::ref(this->y), ::std::ref(this->z), ::std::ref(this->w)}) {}
    vector4() : vector4(T(), T(), T(), T()) {}
    vector4(const ::tools::vector4<T>& other) : vector4(other.x, other.y, other.z, other.w) {}
    ~vector4() = default;

    TOOLS_DETAIL_VECTOR_STATIC_COMMON(::tools::vector4<T>)
    TOOLS_DETAIL_VECTOR_COMMON(::tools::vector4<T>)
  };
}

namespace std {
  template <typename T>
  struct hash<::tools::vector4<T>> {
    using result_type = ::std::size_t;
    using argument_type = ::tools::vector4<T>;
    ::std::size_t operator()(const ::tools::vector4<T>& key) const {
      static const ::tools::tuple_hash<T, T, T, T> hasher;
      return hasher(::std::make_tuple(key.x, key.y, key.z, key.w));
    }
  };
}

#endif
