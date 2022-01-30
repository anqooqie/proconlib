#ifndef TOOLS_DETAIL_ELEMENT_2D_HPP
#define TOOLS_DETAIL_ELEMENT_2D_HPP

#include <type_traits>
#include <cstddef>
#include <vector>
#include <optional>
#include <variant>
#include <cassert>
#include "tools/vector2.hpp"
#include "tools/is_rational.hpp"
#include "tools/signum.hpp"

namespace tools {
  template <typename T>
  class directed_line_segment_2d;

  template <typename T>
  class half_line_2d;

  template <typename T>
  class line_2d;

  template <typename T>
  class directed_line_segment_2d {
  private:
    ::tools::vector2<T> m_p1;
    ::tools::vector2<T> m_p2;

  public:
    directed_line_segment_2d() = default;
    directed_line_segment_2d(const ::tools::directed_line_segment_2d<T>&) = default;
    directed_line_segment_2d(::tools::directed_line_segment_2d<T>&&) = default;
    ~directed_line_segment_2d() = default;
    ::tools::directed_line_segment_2d<T>& operator=(const ::tools::directed_line_segment_2d<T>&) = default;
    ::tools::directed_line_segment_2d<T>& operator=(::tools::directed_line_segment_2d<T>&&) = default;

    directed_line_segment_2d(const ::tools::vector2<T>& p1, const ::tools::vector2<T>& p2);

    const ::tools::vector2<T>& p1() const;
    const ::tools::vector2<T>& p2() const;

    ::tools::vector2<T> to_vector() const;
    ::tools::half_line_2d<T> to_half_line() const;
    ::tools::line_2d<T> to_line() const;
    ::std::conditional_t<::std::is_floating_point_v<T>, T, double> length() const;
    T squared_length() const;
    template <typename U = T, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t> = nullptr>
    ::tools::vector2<T> midpoint() const;
    bool contains(const ::tools::vector2<T>& p) const;

    template <typename U = T, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t> = nullptr>
    ::std::optional<::tools::vector2<T>> cross_point(const ::tools::directed_line_segment_2d<T>& other) const;
    template <typename U = T, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t> = nullptr>
    ::std::optional<::tools::vector2<T>> cross_point(const ::tools::half_line_2d<T>& other) const;
    template <typename U = T, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t> = nullptr>
    ::std::optional<::tools::vector2<T>> cross_point(const ::tools::line_2d<T>& other) const;
    template <typename U = T, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t> = nullptr>
    ::std::optional<::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>> intersection(const ::tools::directed_line_segment_2d<T>& other) const;
    template <typename U = T, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t> = nullptr>
    ::std::optional<::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>> intersection(const ::tools::half_line_2d<T>& other) const;
    template <typename U = T, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t> = nullptr>
    ::std::optional<::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>> intersection(const ::tools::line_2d<T>& other) const;

    ::tools::directed_line_segment_2d<T> operator+() const;
    ::tools::directed_line_segment_2d<T> operator-() const;

    template <typename U>
    friend bool operator==(const ::tools::directed_line_segment_2d<U>& lhs, const ::tools::directed_line_segment_2d<U>& rhs);
    template <typename U>
    friend bool operator!=(const ::tools::directed_line_segment_2d<U>& lhs, const ::tools::directed_line_segment_2d<U>& rhs);
  };

  template <typename T>
  class half_line_2d {
  private:
    ::tools::vector2<T> m_a;
    ::tools::vector2<T> m_d;

  public:
    half_line_2d() = default;
    half_line_2d(const ::tools::half_line_2d<T>&) = default;
    half_line_2d(::tools::half_line_2d<T>&&) = default;
    ~half_line_2d() = default;
    ::tools::half_line_2d<T>& operator=(const ::tools::half_line_2d<T>&) = default;
    ::tools::half_line_2d<T>& operator=(::tools::half_line_2d<T>&&) = default;

    half_line_2d(const ::tools::vector2<T>& a, const ::tools::vector2<T>& d);

    const ::tools::vector2<T>& a() const;
    const ::tools::vector2<T>& d() const;

    ::tools::line_2d<T> to_line() const;
    bool contains(const ::tools::vector2<T>& p) const;

    template <typename U = T, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t> = nullptr>
    ::std::optional<::tools::vector2<T>> cross_point(const ::tools::directed_line_segment_2d<T>& other) const;
    template <typename U = T, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t> = nullptr>
    ::std::optional<::tools::vector2<T>> cross_point(const ::tools::half_line_2d<T>& other) const;
    template <typename U = T, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t> = nullptr>
    ::std::optional<::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>> intersection(const ::tools::directed_line_segment_2d<T>& other) const;
    template <typename U = T, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t> = nullptr>
    ::std::optional<::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>, ::tools::half_line_2d<T>>> intersection(const ::tools::half_line_2d<T>& other) const;

    template <typename U>
    friend bool operator==(const ::tools::half_line_2d<U>& lhs, const ::tools::half_line_2d<U>& rhs);
    template <typename U>
    friend bool operator!=(const ::tools::half_line_2d<U>& lhs, const ::tools::half_line_2d<U>& rhs);
  };

  template <typename T>
  class line_2d {
  private:
    T m_a;
    T m_b;
    T m_c;

  public:
    line_2d() = default;
    line_2d(const ::tools::line_2d<T>&) = default;
    line_2d(::tools::line_2d<T>&&) = default;
    ~line_2d() = default;
    ::tools::line_2d<T>& operator=(const ::tools::line_2d<T>&) = default;
    ::tools::line_2d<T>& operator=(::tools::line_2d<T>&&) = default;

    line_2d(const T& a, const T& b, const T& c);

    const T& a() const;
    const T& b() const;
    const T& c() const;

    bool contains(const ::tools::vector2<T>& p) const;
    bool is_parallel_to(const ::tools::line_2d<T>& other) const;

    bool crosses(const ::tools::line_2d<T>& other) const;
    template <typename U = T, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t> = nullptr>
    ::std::optional<::tools::vector2<T>> cross_point(const ::tools::line_2d<T>& other) const;
    bool intersects(const ::tools::line_2d<T>& other) const;
    template <typename U = T, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t> = nullptr>
    ::std::optional<::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>> intersection(const ::tools::directed_line_segment_2d<T>& other) const;
    template <typename U = T, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t> = nullptr>
    ::std::optional<::std::variant<::tools::vector2<T>, ::tools::line_2d<T>>> intersection(const ::tools::line_2d<T>& other) const;

    template <typename U>
    friend bool operator==(const ::tools::line_2d<T>& lhs, const ::tools::line_2d<T>& rhs);
    template <typename U>
    friend bool operator!=(const ::tools::line_2d<T>& lhs, const ::tools::line_2d<T>& rhs);

    static ::tools::line_2d<T> through(const ::tools::vector2<T>& p1, const ::tools::vector2<T>& p2);
  };

  template <typename T>
  directed_line_segment_2d<T>::directed_line_segment_2d(const ::tools::vector2<T>& p1, const ::tools::vector2<T>& p2) :
    m_p1(p1),
    m_p2(p2) {
    assert(p1 != p2);
  }

  template <typename T>
  const ::tools::vector2<T>& directed_line_segment_2d<T>::p1() const {
    return this->m_p1;
  }

  template <typename T>
  const ::tools::vector2<T>& directed_line_segment_2d<T>::p2() const {
    return this->m_p2;
  }

  template <typename T>
  ::tools::vector2<T> directed_line_segment_2d<T>::to_vector() const {
    return this->m_p2 - this->m_p1;
  }

  template <typename T>
  ::tools::half_line_2d<T> directed_line_segment_2d<T>::to_half_line() const {
    return ::tools::half_line_2d<T>(this->m_p1, this->m_p2 - this->m_p1);
  }

  template <typename T>
  ::tools::line_2d<T> directed_line_segment_2d<T>::to_line() const {
    return ::tools::line_2d<T>::through(this->m_p1, this->m_p2);
  }

  template <typename T>
  ::std::conditional_t<::std::is_floating_point_v<T>, T, double> directed_line_segment_2d<T>::length() const {
    return this->to_vector().norm();
  }

  template <typename T>
  T directed_line_segment_2d<T>::squared_length() const {
    return this->to_vector().squared_norm();
  }

  template <typename T>
  template <typename U, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t>>
  ::tools::vector2<T> directed_line_segment_2d<T>::midpoint() const {
    return (this->m_p1 + this->m_p2) / T(2);
  }

  template <typename T>
  bool directed_line_segment_2d<T>::contains(const ::tools::vector2<T>& p) const {
    if (p == this->m_p1 || p == this->m_p2) return true;
    const ::tools::line_2d<T> l = this->to_line();
    if (!l.contains(p)) return false;
    const T d = (p - this->m_p1).inner_product(this->to_vector());
    return T(0) <= d && d <= this->squared_length();
  }

  template <typename T>
  template <typename U, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t>>
  ::std::optional<::tools::vector2<T>> directed_line_segment_2d<T>::cross_point(const ::tools::directed_line_segment_2d<T>& other) const {
    using result_t = ::std::optional<::tools::vector2<T>>;
    const auto intersection = this->intersection(other);
    struct {
      result_t operator()(const ::tools::vector2<T>& v) {
        return result_t(v);
      }
      result_t operator()(const ::tools::directed_line_segment_2d<T>&) {
        return result_t();
      }
    } visitor;
    return intersection ? ::std::visit(visitor, *intersection) : result_t();
  }

  template <typename T>
  template <typename U, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t>>
  ::std::optional<::tools::vector2<T>> directed_line_segment_2d<T>::cross_point(const ::tools::half_line_2d<T>& other) const {
    using result_t = ::std::optional<::tools::vector2<T>>;
    const auto intersection = this->intersection(other);
    struct {
      result_t operator()(const ::tools::vector2<T>& v) {
        return result_t(v);
      }
      result_t operator()(const ::tools::directed_line_segment_2d<T>&) {
        return result_t();
      }
    } visitor;
    return intersection ? ::std::visit(visitor, *intersection) : result_t();
  }

  template <typename T>
  template <typename U, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t>>
  ::std::optional<::tools::vector2<T>> directed_line_segment_2d<T>::cross_point(const ::tools::line_2d<T>& other) const {
    using result_t = ::std::optional<::tools::vector2<T>>;
    const auto intersection = this->intersection(other);
    struct {
      result_t operator()(const ::tools::vector2<T>& v) {
        return result_t(v);
      }
      result_t operator()(const ::tools::directed_line_segment_2d<T>&) {
        return result_t();
      }
    } visitor;
    return intersection ? ::std::visit(visitor, *intersection) : result_t();
  }

  template <typename T>
  template <typename U, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t>>
  ::std::optional<::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>> directed_line_segment_2d<T>::intersection(const ::tools::directed_line_segment_2d<T>& other) const {
    using variant_t = ::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>;
    using result_t = ::std::optional<variant_t>;
    const ::tools::line_2d<T> l1 = this->to_line();
    const ::tools::line_2d<T> l2 = other.to_line();
    if (l1 == l2) {
      const ::tools::vector2<T> base = this->to_vector();
      const ::tools::directed_line_segment_2d<T> fixed_other = base.inner_product(other.to_vector()) > T(0) ? other : -other;
      const T d1(0);
      const T d2 = base.inner_product(base);
      const T d3 = base.inner_product(fixed_other.m_p1 - this->m_p1);
      const T d4 = base.inner_product(fixed_other.m_p2 - this->m_p1);
      if (d1 == d4) return result_t(variant_t(this->m_p1));
      if (d2 == d3) return result_t(variant_t(this->m_p2));
      if (d3 <= d1 && d2 <= d4) return result_t(variant_t(*this));
      if (d1 <= d3 && d4 <= d2) return result_t(variant_t(fixed_other));
      if (d3 <= d1 && d1 <= d4 && d4 <= d2) return result_t(variant_t(::tools::directed_line_segment_2d<T>(this->m_p1, fixed_other.m_p2)));
      if (d1 <= d3 && d3 <= d2 && d2 <= d4) return result_t(variant_t(::tools::directed_line_segment_2d<T>(fixed_other.m_p1, this->m_p2)));
      return result_t();
    }
    if (l1.is_parallel_to(l2)) return result_t();
    if (this->m_p1 == other.m_p1 || this->m_p1 == other.m_p2) return result_t(variant_t(this->m_p1));
    if (this->m_p2 == other.m_p1 || this->m_p2 == other.m_p2) return result_t(variant_t(this->m_p2));
    if (((other.m_p1.y - this->m_p1.y) * (this->m_p2.x - this->m_p1.x) - (this->m_p2.y - this->m_p1.y) * (other.m_p1.x - this->m_p1.x)) *
        ((other.m_p2.y - this->m_p1.y) * (this->m_p2.x - this->m_p1.x) - (this->m_p2.y - this->m_p1.y) * (other.m_p2.x - this->m_p1.x)) > T(0) ||
        ((this->m_p1.y - other.m_p1.y) * (other.m_p2.x - other.m_p1.x) - (other.m_p2.y - other.m_p1.y) * (this->m_p1.x - other.m_p1.x)) *
        ((this->m_p2.y - other.m_p1.y) * (other.m_p2.x - other.m_p1.x) - (other.m_p2.y - other.m_p1.y) * (this->m_p2.x - other.m_p1.x)) > T(0)) return result_t();
    return result_t(variant_t(*l1.cross_point(l2)));
  }

  template <typename T>
  template <typename U, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t>>
  ::std::optional<::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>> directed_line_segment_2d<T>::intersection(const ::tools::half_line_2d<T>& other) const {
    using variant_t = ::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>;
    using result_t = ::std::optional<variant_t>;
    const ::tools::line_2d<T> l1 = this->to_line();
    const ::tools::line_2d<T> l2 = other.to_line();
    if (l1 == l2) {
      const bool has_same_direction = other.d().inner_product(this->to_vector()) > T(0);
      const T d1 = other.d().inner_product(this->m_p1 - other.a());
      const T d2 = other.d().inner_product(this->m_p2 - other.a());
      if (has_same_direction) {
        if (d2 < T(0)) return result_t();
        if (d2 == T(0)) return result_t(variant_t(other.a()));
        if (d1 < T(0)) return result_t(variant_t(directed_line_segment_2d<T>(other.a(), this->m_p2)));
        return result_t(variant_t(*this));
      } else {
        if (d1 > T(0)) return result_t();
        if (d1 == T(0)) return result_t(variant_t(other.a()));
        if (d2 > T(0)) return result_t(variant_t(directed_line_segment_2d<T>(this->m_p1, other.a())));
        return result_t(variant_t(*this));
      }
    }
    if (other.contains(this->m_p1)) return result_t(variant_t(this->m_p1));
    if (other.contains(this->m_p2)) return result_t(variant_t(this->m_p2));
    if ((l2.a() * this->m_p1.x + l2.b() * this->m_p1.y + l2.c()) * (l2.a() * this->m_p2.x + l2.b() * this->m_p2.y + l2.c()) > T(0)) return result_t();
    const ::tools::vector2<T> possible_cross_point = *l1.cross_point(l2);
    if (other.d().inner_product(possible_cross_point - other.a()) < T(0)) return result_t();
    return result_t(variant_t(possible_cross_point));
  }

  template <typename T>
  template <typename U, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t>>
  ::std::optional<::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>> directed_line_segment_2d<T>::intersection(const ::tools::line_2d<T>& other) const {
    using variant_t = ::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>;
    using result_t = ::std::optional<variant_t>;
    const ::tools::line_2d<T> this_line = this->to_line();
    if (this_line == other) return result_t(variant_t(*this));
    if (other.contains(this->m_p1)) return result_t(variant_t(this->m_p1));
    if (other.contains(this->m_p2)) return result_t(variant_t(this->m_p2));
    if ((other.a() * this->m_p1.x + other.b() * this->m_p1.y + other.c()) * (other.a() * this->m_p2.x + other.b() * this->m_p2.y + other.c()) > T(0)) return result_t();
    return result_t(variant_t(*this_line.cross_point(other)));
  }

  template <typename T>
  ::tools::directed_line_segment_2d<T> directed_line_segment_2d<T>::operator+() const {
    return *this;
  }

  template <typename T>
  ::tools::directed_line_segment_2d<T> directed_line_segment_2d<T>::operator-() const {
    return ::tools::directed_line_segment_2d<T>(this->m_p2, this->m_p1);
  }

  template <typename T>
  bool operator==(const ::tools::directed_line_segment_2d<T>& lhs, const ::tools::directed_line_segment_2d<T>& rhs) {
    return lhs.p1() == rhs.p1() && lhs.p2() == rhs.p2();
  }

  template <typename T>
  bool operator!=(const ::tools::directed_line_segment_2d<T>& lhs, const ::tools::directed_line_segment_2d<T>& rhs) {
    return !(lhs == rhs);
  }

  template <typename T>
  half_line_2d<T>::half_line_2d(const ::tools::vector2<T>& a, const ::tools::vector2<T>& d) :
    m_a(a),
    m_d(d) {
    assert(d != ::tools::vector2<T>(T(0), T(0)));
  }

  template <typename T>
  const ::tools::vector2<T>& half_line_2d<T>::a() const {
    return this->m_a;
  }

  template <typename T>
  const ::tools::vector2<T>& half_line_2d<T>::d() const {
    return this->m_d;
  }

  template <typename T>
  ::tools::line_2d<T> half_line_2d<T>::to_line() const {
    return ::tools::line_2d<T>::through(this->m_a, this->m_a + this->m_d);
  }

  template <typename T>
  bool half_line_2d<T>::contains(const ::tools::vector2<T>& p) const {
    const ::tools::line_2d<T> l = this->to_line();
    return l.a() * p.x + l.b() * p.y + l.c() == T(0) && this->m_d.inner_product(p - this->m_a) >= T(0);
  }

  template <typename T>
  template <typename U, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t>>
  ::std::optional<::tools::vector2<T>> half_line_2d<T>::cross_point(const ::tools::directed_line_segment_2d<T>& other) const {
    return other.cross_point(*this);
  }

  template <typename T>
  template <typename U, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t>>
  ::std::optional<::tools::vector2<T>> half_line_2d<T>::cross_point(const ::tools::half_line_2d<T>& other) const {
    using result_t = ::std::optional<::tools::vector2<T>>;
    const auto intersection = this->intersection(other);
    struct {
      result_t operator()(const ::tools::vector2<T>& v) {
        return result_t(v);
      }
      result_t operator()(const ::tools::directed_line_segment_2d<T>&) {
        return result_t();
      }
      result_t operator()(const ::tools::half_line_2d<T>&) {
        return result_t();
      }
    } visitor;
    return intersection ? ::std::visit(visitor, *intersection) : result_t();
  }

  template <typename T>
  template <typename U, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t>>
  ::std::optional<::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>> half_line_2d<T>::intersection(const ::tools::directed_line_segment_2d<T>& other) const {
    return other.intersection(*this);
  }

  template <typename T>
  template <typename U, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t>>
  ::std::optional<::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>, ::tools::half_line_2d<T>>> half_line_2d<T>::intersection(const ::tools::half_line_2d<T>& other) const {
    using variant_t = ::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>, ::tools::half_line_2d<T>>;
    using result_t = ::std::optional<variant_t>;
    const ::tools::line_2d<T> l1 = this->to_line();
    const ::tools::line_2d<T> l2 = other.to_line();
    if (l1 == l2) {
      if (this->d().inner_product(other.d()) > T(0)) {
        switch (::tools::signum(this->d().inner_product(other.a() - this->a()))) {
        case 1:
        case 0:
          return result_t(variant_t(other));
        default:
          return result_t(variant_t(*this));
        }
      } else {
        switch (::tools::signum(this->d().inner_product(other.a() - this->a()))) {
        case 1:
          return result_t(variant_t(::tools::directed_line_segment_2d<T>(this->a(), other.a())));
        case 0:
          return result_t(variant_t(this->a()));
        default:
          return result_t();
        }
      }
    } else if (l1.is_parallel_to(l2)) {
      return result_t();
    } else {
      const ::tools::vector2<T> possible_cross_point = *l1.cross_point(l2);
      if (this->d().inner_product(possible_cross_point - this->a()) < T(0) || other.d().inner_product(possible_cross_point - other.a()) < T(0)) {
        return result_t();
      }
      return result_t(variant_t(possible_cross_point));
    }
  }

  template <typename T>
  bool operator==(const ::tools::half_line_2d<T>& lhs, const ::tools::half_line_2d<T>& rhs) {
    return lhs.a() == rhs.a() && lhs.d().x * rhs.d().y == rhs.d().x * lhs.d().y;
  }

  template <typename T>
  bool operator!=(const ::tools::half_line_2d<T>& lhs, const ::tools::half_line_2d<T>& rhs) {
    return !(lhs == rhs);
  }

  template <typename T>
  line_2d<T>::line_2d(const T& a, const T& b, const T& c) :
    m_a(a),
    m_b(b),
    m_c(c) {
    assert(a != T(0) || b != T(0));
  }

  template <typename T>
  const T& line_2d<T>::a() const {
    return this->m_a;
  }

  template <typename T>
  const T& line_2d<T>::b() const {
    return this->m_b;
  }

  template <typename T>
  const T& line_2d<T>::c() const {
    return this->m_c;
  }

  template <typename T>
  bool line_2d<T>::contains(const ::tools::vector2<T>& p) const {
    return this->m_a * p.x + this->m_b * p.y + this->m_c == T(0);
  }

  template <typename T>
  bool line_2d<T>::is_parallel_to(const ::tools::line_2d<T>& other) const {
    return this->a() * other.b() == this->b() * other.a();
  }

  template <typename T>
  bool line_2d<T>::crosses(const ::tools::line_2d<T>& other) const {
    return this->a() * other.b() != other.a() * this->b();
  }

  template <typename T>
  template <typename U, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t>>
  ::std::optional<::tools::vector2<T>> line_2d<T>::cross_point(const ::tools::line_2d<T>& other) const {
    using result_t = ::std::optional<::tools::vector2<T>>;
    if (!this->crosses(other)) return result_t();
    return result_t(::tools::vector2<T>(
      (this->b() * other.c() - other.b() * this->c()) / (this->a() * other.b() - other.a() * this->b()),
      (other.a() * this->c() - this->a() * other.c()) / (this->a() * other.b() - other.a() * this->b())
    ));
  }

  template <typename T>
  bool line_2d<T>::intersects(const ::tools::line_2d<T>& other) const {
    return this == other || this->crosses(other);
  }

  template <typename T>
  template <typename U, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t>>
  ::std::optional<::std::variant<::tools::vector2<T>, ::tools::line_2d<T>>> line_2d<T>::intersection(const ::tools::line_2d<T>& other) const {
    using variant_t = ::std::variant<::tools::vector2<T>, ::tools::line_2d<T>>;
    using result_t = ::std::optional<variant_t>;
    if (this == other) return result_t(variant_t(*this));
    if (this->crosses(other)) return result_t(variant_t(*this->cross_point(other)));
    return result_t();
  }

  template <typename T>
  template <typename U, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t>>
  ::std::optional<::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>> line_2d<T>::intersection(const ::tools::directed_line_segment_2d<T>& other) const {
    return other.intersection(*this);
  }

  template <typename T>
  bool operator==(const ::tools::line_2d<T>& lhs, const ::tools::line_2d<T>& rhs) {
    return lhs.b() * rhs.c() == lhs.c() * rhs.b() && lhs.c() * rhs.a() == lhs.a() * rhs.c() && lhs.a() * rhs.b() == lhs.b() * rhs.a();
  }

  template <typename T>
  bool operator!=(const ::tools::line_2d<T>& lhs, const ::tools::line_2d<T>& rhs) {
    return !(lhs == rhs);
  }

  template <typename T>
  ::tools::line_2d<T> line_2d<T>::through(const ::tools::vector2<T>& p1, const ::tools::vector2<T>& p2) {
    return ::tools::line_2d<T>(p1.y - p2.y, p2.x - p1.x, (p2.y - p1.y) * p1.x - (p2.x - p1.x) * p1.y);
  }
}

#endif
