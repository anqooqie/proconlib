#ifndef TOOLS_VECTOR3_HPP
#define TOOLS_VECTOR3_HPP

#include <array>
#include <functional>
#include <utility>
#include <cstddef>
#include "tools/detail/vector_static_common.hpp"
#include "tools/detail/vector_common.hpp"
#include "tools/tuple_hash.hpp"

namespace tools {
  template <typename T>
  class vector3 {
  public:
    T x;
    T y;
    T z;

  private:
    ::std::array<::std::reference_wrapper<T>, 3> m_refs;

  public:
    vector3(const T& x, const T& y, const T& z) : x(x), y(y), z(z), m_refs({::std::ref(this->x), ::std::ref(this->y), ::std::ref(this->z)}) {}
    vector3() : vector3(T(), T(), T()) {}
    vector3(const ::tools::vector3<T>& other) : vector3(other.x, other.y, other.z) {}
    vector3(::tools::vector3<T>&& other) : x(::std::move(other.x)), y(::std::move(other.y)), z(::std::move(other.z)), m_refs({::std::ref(this->x), ::std::ref(this->y), ::std::ref(this->z)}) {}
    ~vector3() = default;

    TOOLS_DETAIL_VECTOR_STATIC_COMMON(::tools::vector3<T>)
    TOOLS_DETAIL_VECTOR_COMMON(::tools::vector3<T>)

  public:
    ::tools::vector3<T> outer_product(const ::tools::vector3<T>& other) const {
      return ::tools::vector3<T>(this->x * other.y - this->y * other.x, this->y * other.z - this->z * other.y, this->z * other.x - this->x * other.z);
    }
  };
}

namespace std {
  template <typename T>
  void swap(::tools::vector3<T>& x, ::tools::vector3<T>& y) {
    x.swap(y);
  }

  template <typename T>
  struct hash<::tools::vector3<T>> {
    using result_type = ::std::size_t;
    using argument_type = ::tools::vector3<T>;
    ::std::size_t operator()(const ::tools::vector3<T>& key) const {
      static const ::tools::tuple_hash<T, T, T> hasher;
      return hasher(::std::make_tuple(key.x, key.y, key.z));
    }
  };
}

#endif
