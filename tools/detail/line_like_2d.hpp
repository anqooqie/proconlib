#ifndef TOOLS_LINE_LIKE_2D_HPP
#define TOOLS_LINE_LIKE_2D_HPP

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <optional>
#include <type_traits>
#include <variant>
#include <vector>
#include "tools/is_rational.hpp"
#include "tools/signum.hpp"
#include "tools/vector2.hpp"

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

    bool contains(const ::tools::vector2<T>& p) const;
    ::std::conditional_t<::std::is_floating_point_v<T>, T, double> length() const; 
    template <typename U = T>
    ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::tools::vector2<T>>>
    cross_point(const ::tools::directed_line_segment_2d<T>& other) const;
    template <typename U = T>
    ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::tools::vector2<T>>>
    cross_point(const ::tools::half_line_2d<T>& other) const;
    template <typename U = T>
    ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::tools::vector2<T>>>
    cross_point(const ::tools::line_2d<T>& other) const;
    template <typename U = T>
    ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::tools::vector2<T>>
    midpoint() const;
    const ::tools::vector2<T>& p1() const;
    const ::tools::vector2<T>& p2() const;
    template <typename U = T>
    ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, T>
    squared_distance(const ::tools::directed_line_segment_2d<T>& other) const;
    T squared_length() const;
    ::tools::half_line_2d<T> to_half_line() const;
    ::tools::line_2d<T> to_line() const;
    ::tools::vector2<T> to_vector() const;

    ::tools::directed_line_segment_2d<T> operator+() const;
    ::tools::directed_line_segment_2d<T> operator-() const;
    template <typename U>
    friend ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::std::variant<::tools::vector2<U>, ::tools::directed_line_segment_2d<U>>>>
    operator&(const ::tools::directed_line_segment_2d<U>& lhs, const ::tools::directed_line_segment_2d<U>& rhs);
    template <typename U>
    friend ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::std::variant<::tools::vector2<U>, ::tools::directed_line_segment_2d<U>>>>
    operator&(const ::tools::directed_line_segment_2d<U>& lhs, const ::tools::half_line_2d<U>& rhs);
    template <typename U>
    friend ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::std::variant<::tools::vector2<U>, ::tools::directed_line_segment_2d<U>>>>
    operator&(const ::tools::directed_line_segment_2d<U>& lhs, const ::tools::line_2d<U>& rhs);
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
    bool contains(const ::tools::vector2<T>& p) const;
    template <typename U = T>
    ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::tools::vector2<T>>>
    cross_point(const ::tools::directed_line_segment_2d<T>& other) const;
    template <typename U = T>
    ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::tools::vector2<T>>>
    cross_point(const ::tools::half_line_2d<T>& other) const;
    template <typename U = T>
    ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::tools::vector2<T>>>
    cross_point(const ::tools::line_2d<T>& other) const;
    const ::tools::vector2<T>& d() const;
    ::tools::line_2d<T> to_line() const;

    template <typename U>
    friend ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::std::variant<::tools::vector2<U>, ::tools::directed_line_segment_2d<U>>>>
    operator&(const ::tools::half_line_2d<U>& lhs, const ::tools::directed_line_segment_2d<U>& rhs);
    template <typename U>
    friend ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::std::variant<::tools::vector2<U>, ::tools::directed_line_segment_2d<U>, ::tools::half_line_2d<U>>>>
    operator&(const ::tools::half_line_2d<U>& lhs, const ::tools::half_line_2d<U>& rhs);
    template <typename U>
    friend ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::std::variant<::tools::vector2<U>, ::tools::half_line_2d<U>>>>
    operator&(const ::tools::half_line_2d<U>& lhs, const ::tools::line_2d<U>& rhs);
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
    template <typename U = T>
    ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::tools::vector2<T>>>
    cross_point(const ::tools::directed_line_segment_2d<T>& other) const;
    template <typename U = T>
    ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::tools::vector2<T>>>
    cross_point(const ::tools::half_line_2d<T>& other) const;
    template <typename U = T>
    ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::tools::vector2<T>>>
    cross_point(const ::tools::line_2d<T>& other) const;
    bool crosses(const ::tools::line_2d<T>& other) const;
    bool is_parallel_to(const ::tools::line_2d<T>& other) const;
    ::tools::vector2<T> normal() const;
    template <typename U = T>
    ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::tools::vector2<T>>
    projection(const ::tools::vector2<T>& p) const;

    template <typename U>
    friend ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::std::variant<::tools::vector2<U>, ::tools::directed_line_segment_2d<U>>>>
    operator&(const ::tools::line_2d<U>& lhs, const ::tools::directed_line_segment_2d<U>& rhs);
    template <typename U>
    friend ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::std::variant<::tools::vector2<U>, ::tools::half_line_2d<U>>>>
    operator&(const ::tools::line_2d<U>& lhs, const ::tools::half_line_2d<U>& rhs);
    template <typename U>
    friend ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::std::variant<::tools::vector2<U>, ::tools::line_2d<U>>>>
    operator&(const ::tools::line_2d<U>& lhs, const ::tools::line_2d<U>& rhs);
    template <typename U>
    friend bool operator==(const ::tools::line_2d<U>& lhs, const ::tools::line_2d<U>& rhs);
    template <typename U>
    friend bool operator!=(const ::tools::line_2d<U>& lhs, const ::tools::line_2d<U>& rhs);

    static ::tools::line_2d<T> through(const ::tools::vector2<T>& p1, const ::tools::vector2<T>& p2);
  };

  template <typename T>
  directed_line_segment_2d<T>::directed_line_segment_2d(const ::tools::vector2<T>& p1, const ::tools::vector2<T>& p2) :
    m_p1(p1),
    m_p2(p2) {
    assert(p1 != p2);
  }

  template <typename T>
  bool directed_line_segment_2d<T>::contains(const ::tools::vector2<T>& p) const {
    if (p == this->m_p1 || p == this->m_p2) return true;
    const ::tools::line_2d<T> l = this->to_line();
    if (!l.contains(p)) return false;
    const T d = (p - this->m_p1).inner_product(this->to_vector());
    return T(0) <= d && d <= this->squared_length();
  }

  template <typename T> template <typename U>
  ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::tools::vector2<T>>>
  directed_line_segment_2d<T>::cross_point(const ::tools::directed_line_segment_2d<T>& other) const {
    using result_t = ::std::optional<::tools::vector2<T>>;
    const auto intersection = *this & other;
    struct {
      result_t operator()(const ::tools::vector2<T>& v) {
        return result_t(v);
      }
      result_t operator()(const ::tools::directed_line_segment_2d<T>&) {
        return ::std::nullopt;
      }
    } visitor;
    return intersection ? ::std::visit(visitor, *intersection) : ::std::nullopt;
  }

  template <typename T> template <typename U>
  ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::tools::vector2<T>>>
  directed_line_segment_2d<T>::cross_point(const ::tools::half_line_2d<T>& other) const {
    using result_t = ::std::optional<::tools::vector2<T>>;
    const auto intersection = *this & other;
    struct {
      result_t operator()(const ::tools::vector2<T>& v) {
        return result_t(v);
      }
      result_t operator()(const ::tools::directed_line_segment_2d<T>&) {
        return ::std::nullopt;
      }
    } visitor;
    return intersection ? ::std::visit(visitor, *intersection) : ::std::nullopt;
  }

  template <typename T> template <typename U>
  ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::tools::vector2<T>>>
  directed_line_segment_2d<T>::cross_point(const ::tools::line_2d<T>& other) const {
    using result_t = ::std::optional<::tools::vector2<T>>;
    const auto intersection = *this & other;
    struct {
      result_t operator()(const ::tools::vector2<T>& v) {
        return result_t(v);
      }
      result_t operator()(const ::tools::directed_line_segment_2d<T>&) {
        return result_t();
      }
    } visitor;
    return intersection ? ::std::visit(visitor, *intersection) : ::std::nullopt;
  }

  template <typename T>
  ::std::conditional_t<::std::is_floating_point_v<T>, T, double> directed_line_segment_2d<T>::length() const {
    return this->to_vector().norm();
  }

  template <typename T> template <typename U>
  ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::tools::vector2<T>>
  directed_line_segment_2d<T>::midpoint() const {
    return (this->m_p1 + this->m_p2) / T(2);
  }

  template <typename T>
  const ::tools::vector2<T>& directed_line_segment_2d<T>::p1() const {
    return this->m_p1;
  }

  template <typename T>
  const ::tools::vector2<T>& directed_line_segment_2d<T>::p2() const {
    return this->m_p2;
  }

  template <typename T> template <typename U>
  ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, T>
  directed_line_segment_2d<T>::squared_distance(const ::tools::directed_line_segment_2d<T>& other) const {
    if (*this & other) {
      return T(0);
    }

    const auto l1 = this->to_line();
    const auto l2 = other.to_line();
    const auto x1 = [&]() {
      const auto x = l2.projection(this->m_p1);
      const auto d = other.to_vector().inner_product(x - other.m_p1);
      return d < T(0) ? other.m_p1 : other.squared_length() < d ? other.m_p2 : x;
    }();
    const auto x2 = [&]() {
      const auto x = l2.projection(this->m_p2);
      const auto d = other.to_vector().inner_product(x - other.m_p1);
      return d < T(0) ? other.m_p1 : other.squared_length() < d ? other.m_p2 : x;
    }();
    const auto x3 = [&]() {
      const auto x = l1.projection(other.m_p1);
      const auto d = this->to_vector().inner_product(x - this->m_p1);
      return d < T(0) ? this->m_p1 : this->squared_length() < d ? this->m_p2 : x;
    }();
    const auto x4 = [&]() {
      const auto x = l1.projection(other.m_p2);
      const auto d = this->to_vector().inner_product(x - this->m_p1);
      return d < T(0) ? this->m_p1 : this->squared_length() < d ? this->m_p2 : x;
    }();

    return ::std::min({(this->m_p1 - x1).squared_norm(), (this->m_p2 - x2).squared_norm(), (other.m_p1 - x3).squared_norm(), (other.m_p2 - x4).squared_norm()});
  }

  template <typename T>
  T directed_line_segment_2d<T>::squared_length() const {
    return this->to_vector().squared_norm();
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
  ::tools::vector2<T> directed_line_segment_2d<T>::to_vector() const {
    return this->m_p2 - this->m_p1;
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
  ::std::enable_if_t<::tools::is_rational_v<T> || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>>>
  operator&(const ::tools::directed_line_segment_2d<T>& lhs, const ::tools::directed_line_segment_2d<T>& rhs) {
    using variant_t = ::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>;
    using result_t = ::std::optional<variant_t>;
    const ::tools::line_2d<T> l1 = lhs.to_line();
    const ::tools::line_2d<T> l2 = rhs.to_line();
    if (l1 == l2) {
      const ::tools::vector2<T> base = lhs.to_vector();
      const ::tools::directed_line_segment_2d<T> fixed_rhs = base.inner_product(rhs.to_vector()) > T(0) ? rhs : -rhs;
      const T d1(0);
      const T d2 = base.inner_product(base);
      const T d3 = base.inner_product(fixed_rhs.m_p1 - lhs.m_p1);
      const T d4 = base.inner_product(fixed_rhs.m_p2 - lhs.m_p1);
      if (d1 == d4) return result_t(variant_t(lhs.m_p1));
      if (d2 == d3) return result_t(variant_t(lhs.m_p2));
      if (d3 <= d1 && d2 <= d4) return result_t(variant_t(lhs));
      if (d1 <= d3 && d4 <= d2) return result_t(variant_t(fixed_rhs));
      if (d3 <= d1 && d1 <= d4 && d4 <= d2) return result_t(variant_t(::tools::directed_line_segment_2d<T>(lhs.m_p1, fixed_rhs.m_p2)));
      if (d1 <= d3 && d3 <= d2 && d2 <= d4) return result_t(variant_t(::tools::directed_line_segment_2d<T>(fixed_rhs.m_p1, lhs.m_p2)));
      return ::std::nullopt;
    }
    if (l1.is_parallel_to(l2)) return ::std::nullopt;
    if (lhs.m_p1 == rhs.m_p1 || lhs.m_p1 == rhs.m_p2) return result_t(variant_t(lhs.m_p1));
    if (lhs.m_p2 == rhs.m_p1 || lhs.m_p2 == rhs.m_p2) return result_t(variant_t(lhs.m_p2));
    if (((rhs.m_p1.y - lhs.m_p1.y) * (lhs.m_p2.x - lhs.m_p1.x) - (lhs.m_p2.y - lhs.m_p1.y) * (rhs.m_p1.x - lhs.m_p1.x)) *
        ((rhs.m_p2.y - lhs.m_p1.y) * (lhs.m_p2.x - lhs.m_p1.x) - (lhs.m_p2.y - lhs.m_p1.y) * (rhs.m_p2.x - lhs.m_p1.x)) > T(0) ||
        ((lhs.m_p1.y - rhs.m_p1.y) * (rhs.m_p2.x - rhs.m_p1.x) - (rhs.m_p2.y - rhs.m_p1.y) * (lhs.m_p1.x - rhs.m_p1.x)) *
        ((lhs.m_p2.y - rhs.m_p1.y) * (rhs.m_p2.x - rhs.m_p1.x) - (rhs.m_p2.y - rhs.m_p1.y) * (lhs.m_p2.x - rhs.m_p1.x)) > T(0)) return ::std::nullopt;
    return result_t(variant_t(*l1.cross_point(l2)));
  }

  template <typename T>
  ::std::enable_if_t<::tools::is_rational_v<T> || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>>>
  operator&(const ::tools::directed_line_segment_2d<T>& lhs, const ::tools::half_line_2d<T>& rhs) {
    using variant_t = ::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>;
    using result_t = ::std::optional<variant_t>;
    const ::tools::line_2d<T> l1 = lhs.to_line();
    const ::tools::line_2d<T> l2 = rhs.to_line();
    if (l1 == l2) {
      const bool has_same_direction = rhs.d().inner_product(lhs.to_vector()) > T(0);
      const T d1 = rhs.d().inner_product(lhs.m_p1 - rhs.a());
      const T d2 = rhs.d().inner_product(lhs.m_p2 - rhs.a());
      if (has_same_direction) {
        if (d2 < T(0)) return ::std::nullopt;
        if (d2 == T(0)) return result_t(variant_t(rhs.a()));
        if (d1 < T(0)) return result_t(variant_t(::tools::directed_line_segment_2d<T>(rhs.a(), lhs.m_p2)));
        return result_t(variant_t(lhs));
      } else {
        if (d1 > T(0)) return ::std::nullopt;
        if (d1 == T(0)) return result_t(variant_t(rhs.a()));
        if (d2 > T(0)) return result_t(variant_t(::tools::directed_line_segment_2d<T>(lhs.m_p1, rhs.a())));
        return result_t(variant_t(lhs));
      }
    }
    if (rhs.contains(lhs.m_p1)) return result_t(variant_t(lhs.m_p1));
    if (rhs.contains(lhs.m_p2)) return result_t(variant_t(lhs.m_p2));
    if ((l2.a() * lhs.m_p1.x + l2.b() * lhs.m_p1.y + l2.c()) * (l2.a() * lhs.m_p2.x + l2.b() * lhs.m_p2.y + l2.c()) > T(0)) return ::std::nullopt;
    const ::tools::vector2<T> possible_cross_point = *l1.cross_point(l2);
    if (rhs.d().inner_product(possible_cross_point - rhs.a()) < T(0)) return ::std::nullopt;
    return result_t(variant_t(possible_cross_point));
  }

  template <typename T>
  ::std::enable_if_t<::tools::is_rational_v<T> || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>>>
  operator&(const ::tools::directed_line_segment_2d<T>& lhs, const ::tools::line_2d<T>& rhs) {
    using variant_t = ::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>;
    using result_t = ::std::optional<variant_t>;
    const ::tools::line_2d<T> lhs_line = lhs.to_line();
    if (lhs_line == rhs) return result_t(variant_t(lhs));
    if (rhs.contains(lhs.m_p1)) return result_t(variant_t(lhs.m_p1));
    if (rhs.contains(lhs.m_p2)) return result_t(variant_t(lhs.m_p2));
    if ((rhs.a() * lhs.m_p1.x + rhs.b() * lhs.m_p1.y + rhs.c()) * (rhs.a() * lhs.m_p2.x + rhs.b() * lhs.m_p2.y + rhs.c()) > T(0)) return ::std::nullopt;
    return result_t(variant_t(*lhs_line.cross_point(rhs)));
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
  bool half_line_2d<T>::contains(const ::tools::vector2<T>& p) const {
    const ::tools::line_2d<T> l = this->to_line();
    return l.a() * p.x + l.b() * p.y + l.c() == T(0) && this->m_d.inner_product(p - this->m_a) >= T(0);
  }

  template <typename T> template <typename U>
  ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::tools::vector2<T>>>
  half_line_2d<T>::cross_point(const ::tools::directed_line_segment_2d<T>& other) const {
    return other.cross_point(*this);
  }

  template <typename T> template <typename U>
  ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::tools::vector2<T>>>
  half_line_2d<T>::cross_point(const ::tools::half_line_2d<T>& other) const {
    using result_t = ::std::optional<::tools::vector2<T>>;
    const auto intersection = *this & other;
    struct {
      result_t operator()(const ::tools::vector2<T>& v) {
        return result_t(v);
      }
      result_t operator()(const ::tools::directed_line_segment_2d<T>&) {
        return ::std::nullopt;
      }
      result_t operator()(const ::tools::half_line_2d<T>&) {
        return ::std::nullopt;
      }
    } visitor;
    return intersection ? ::std::visit(visitor, *intersection) : ::std::nullopt;
  }

  template <typename T> template <typename U>
  ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::tools::vector2<T>>>
  half_line_2d<T>::cross_point(const ::tools::line_2d<T>& other) const {
    using result_t = ::std::optional<::tools::vector2<T>>;
    const auto intersection = *this & other;
    struct {
      result_t operator()(const ::tools::vector2<T>& v) {
        return result_t(v);
      }
      result_t operator()(const ::tools::half_line_2d<T>&) {
        return ::std::nullopt;
      }
    } visitor;
    return intersection ? ::std::visit(visitor, *intersection) : ::std::nullopt;
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
  ::std::enable_if_t<::tools::is_rational_v<T> || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>>>
  operator&(const ::tools::half_line_2d<T>& lhs, const ::tools::directed_line_segment_2d<T>& rhs) {
    return rhs & lhs;
  }

  template <typename T>
  ::std::enable_if_t<::tools::is_rational_v<T> || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>, ::tools::half_line_2d<T>>>>
  operator&(const ::tools::half_line_2d<T>& lhs, const ::tools::half_line_2d<T>& rhs) {
    using variant_t = ::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>, ::tools::half_line_2d<T>>;
    using result_t = ::std::optional<variant_t>;
    const ::tools::line_2d<T> l1 = lhs.to_line();
    const ::tools::line_2d<T> l2 = rhs.to_line();
    if (l1 == l2) {
      if (lhs.d().inner_product(rhs.d()) > T(0)) {
        switch (::tools::signum(lhs.d().inner_product(rhs.a() - lhs.a()))) {
        case 1:
        case 0:
          return result_t(variant_t(rhs));
        default:
          return result_t(variant_t(lhs));
        }
      } else {
        switch (::tools::signum(lhs.d().inner_product(rhs.a() - lhs.a()))) {
        case 1:
          return result_t(variant_t(::tools::directed_line_segment_2d<T>(lhs.a(), rhs.a())));
        case 0:
          return result_t(variant_t(lhs.a()));
        default:
          return ::std::nullopt;
        }
      }
    } else if (l1.is_parallel_to(l2)) {
      return ::std::nullopt;
    } else {
      const ::tools::vector2<T> possible_cross_point = *l1.cross_point(l2);
      if (lhs.d().inner_product(possible_cross_point - lhs.a()) < T(0) || rhs.d().inner_product(possible_cross_point - rhs.a()) < T(0)) {
        return ::std::nullopt;
      }
      return result_t(variant_t(possible_cross_point));
    }
  }

  template <typename T>
  ::std::enable_if_t<::tools::is_rational_v<T> || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>, ::tools::half_line_2d<T>>>>
  operator&(const ::tools::half_line_2d<T>& lhs, const ::tools::line_2d<T>& rhs) {
    using variant_t = ::std::variant<::tools::vector2<T>, ::tools::half_line_2d<T>>;
    using result_t = ::std::optional<variant_t>;
    const auto lhs_line = lhs.to_line();
    if (lhs_line == rhs) return result_t(variant_t(lhs));
    const auto possible_cross_point = lhs_line.cross_point(rhs);
    return possible_cross_point && lhs.m_d.inner_product(*possible_cross_point - lhs.m_a) >= T(0)
      ? result_t(variant_t(*possible_cross_point))
      : ::std::nullopt;
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

  template <typename T> template <typename U>
  ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::tools::vector2<T>>>
  line_2d<T>::cross_point(const ::tools::directed_line_segment_2d<T>& other) const {
    return other.cross_point(*this);
  }

  template <typename T> template <typename U>
  ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::tools::vector2<T>>>
  line_2d<T>::cross_point(const ::tools::half_line_2d<T>& other) const {
    return other.cross_point(*this);
  }

  template <typename T> template <typename U>
  ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::optional<::tools::vector2<T>>>
  line_2d<T>::cross_point(const ::tools::line_2d<T>& other) const {
    using result_t = ::std::optional<::tools::vector2<T>>;
    if (!this->crosses(other)) return ::std::nullopt;
    return result_t(::tools::vector2<T>(
      (this->m_b * other.m_c - other.m_b * this->m_c) / (this->m_a * other.m_b - other.m_a * this->m_b),
      (other.m_a * this->m_c - this->m_a * other.m_c) / (this->m_a * other.m_b - other.m_a * this->m_b)
    ));
  }

  template <typename T>
  bool line_2d<T>::crosses(const ::tools::line_2d<T>& other) const {
    return this->m_a * other.m_b != other.m_a * this->m_b;
  }

  template <typename T>
  bool line_2d<T>::is_parallel_to(const ::tools::line_2d<T>& other) const {
    return this->m_a * other.m_b == this->m_b * other.m_a;
  }

  template <typename T>
  ::tools::vector2<T> line_2d<T>::normal() const {
    return ::tools::vector2<T>(this->m_a, this->m_b);
  }

  template <typename T> template <typename U>
  ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::tools::vector2<T>>
  line_2d<T>::projection(const ::tools::vector2<T>& p) const {
    return *::tools::half_line_2d<T>(p, this->normal()).to_line().cross_point(*this);
  }

  template <typename T>
  ::std::enable_if_t<::tools::is_rational_v<T> || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>>>
  operator&(const ::tools::line_2d<T>& lhs, const ::tools::directed_line_segment_2d<T>& rhs) {
    return rhs & lhs;
  }

  template <typename T>
  ::std::enable_if_t<::tools::is_rational_v<T> || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>, ::tools::half_line_2d<T>>>>
  operator&(const ::tools::line_2d<T>& lhs, const ::tools::half_line_2d<T>& rhs) {
    return rhs & lhs;
  }

  template <typename T>
  ::std::enable_if_t<::tools::is_rational_v<T> || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>, ::tools::line_2d<T>>>>
  operator&(const ::tools::line_2d<T>& lhs, const ::tools::line_2d<T>& rhs) {
    using variant_t = ::std::variant<::tools::vector2<T>, ::tools::line_2d<T>>;
    using result_t = ::std::optional<variant_t>;
    if (lhs == rhs) return result_t(variant_t(lhs));
    const auto possible_cross_point = lhs.cross_point(rhs);
    return possible_cross_point ? result_t(variant_t(*possible_cross_point)) : ::std::nullopt;
  }

  template <typename T>
  bool operator==(const ::tools::line_2d<T>& lhs, const ::tools::line_2d<T>& rhs) {
    return lhs.m_b * rhs.m_c == lhs.m_c * rhs.m_b && lhs.m_c * rhs.m_a == lhs.m_a * rhs.m_c && lhs.m_a * rhs.m_b == lhs.m_b * rhs.m_a;
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
