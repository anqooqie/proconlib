#ifndef TOOLS_VECTOR2_HPP
#define TOOLS_VECTOR2_HPP

#include <array>
#include <functional>
#include <utility>
#include <cstddef>
#include "tools/detail/vector_static_common.hpp"
#include "tools/detail/vector_common.hpp"
#include "tools/tuple_hash.hpp"

namespace tools {
  template <typename T>
  class vector2 {
  public:
    T x;
    T y;

  private:
    ::std::array<::std::reference_wrapper<T>, 2> m_refs;

  public:
    vector2(const T& x, const T& y) : x(x), y(y), m_refs({::std::ref(this->x), ::std::ref(this->y)}) {}
    vector2() : vector2(T(), T()) {}
    vector2(const ::tools::vector2<T>& other) : vector2(other.x, other.y) {}
    ~vector2() = default;

    TOOLS_DETAIL_VECTOR_STATIC_COMMON(::tools::vector2<T>)
    TOOLS_DETAIL_VECTOR_COMMON(::tools::vector2<T>)

  public:
    T outer_product(const ::tools::vector2<T>& other) const {
      return this->x * other.y - this->y * other.x;
    }

    ::tools::vector2<T> turned90() const {
      return ::tools::vector2<T>(-this->y, this->x);
    }

    ::tools::vector2<T> turned270() const {
      return ::tools::vector2<T>(this->y, -this->x);
    }

    static ::std::array<::tools::vector2<T>, 4> four_directions() {
      return ::std::array<::tools::vector2<T>, 4>({
        ::tools::vector2<T>(T(1), T(0)),
        ::tools::vector2<T>(T(0), T(1)),
        ::tools::vector2<T>(T(-1), T(0)),
        ::tools::vector2<T>(T(0), T(-1))
      });
    }

    static ::std::array<::tools::vector2<T>, 8> eight_directions() {
      return ::std::array<::tools::vector2<T>, 8>({
        ::tools::vector2<T>(T(1), T(0)),
        ::tools::vector2<T>(T(1), T(1)),
        ::tools::vector2<T>(T(0), T(1)),
        ::tools::vector2<T>(T(-1), T(1)),
        ::tools::vector2<T>(T(-1), T(0)),
        ::tools::vector2<T>(T(-1), T(-1)),
        ::tools::vector2<T>(T(0), T(-1)),
        ::tools::vector2<T>(T(1), T(-1))
      });
    }
  };
}

namespace std {
  template <typename T>
  struct hash<::tools::vector2<T>> {
    using result_type = ::std::size_t;
    using argument_type = ::tools::vector2<T>;
    ::std::size_t operator()(const ::tools::vector2<T>& key) const {
      static const ::tools::tuple_hash<T, T> hasher;
      return hasher(::std::make_tuple(key.x, key.y));
    }
  };
}

#endif
