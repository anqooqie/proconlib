#ifndef TOOLS_DETAIL_GEOMETRY_2D_HPP
#define TOOLS_DETAIL_GEOMETRY_2D_HPP

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <initializer_list>
#include <limits>
#include <optional>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>
#include "tools/abs.hpp"
#include "tools/is_rational.hpp"
#include "tools/less_by.hpp"
#include "tools/signum.hpp"
#include "tools/square.hpp"
#include "tools/vector2.hpp"

namespace tools {
  template <typename T, bool Filled, bool HasRadius = true>
  class circle_2d;

  template <typename T>
  class directed_line_segment_2d;

  template <typename T>
  class half_line_2d;

  template <typename T>
  class line_2d;

  template <typename T, bool Filled>
  class polygon_2d;

  template <typename T, bool Filled>
  class triangle_2d;

  template <typename T, bool Filled, bool HasRadius>
  class circle_2d {
  private:
    ::tools::vector2<T> m_center;
    T m_radius;
    T m_squared_radius;

  public:
    circle_2d() = default;
    circle_2d(const ::tools::circle_2d<T, Filled, HasRadius>&) = default;
    circle_2d(::tools::circle_2d<T, Filled, HasRadius>&&) = default;
    ~circle_2d() = default;
    ::tools::circle_2d<T, Filled, HasRadius>& operator=(const ::tools::circle_2d<T, Filled, HasRadius>&) = default;
    ::tools::circle_2d<T, Filled, HasRadius>& operator=(::tools::circle_2d<T, Filled, HasRadius>&&) = default;

    circle_2d(const ::tools::vector2<T>& center, const T& radius_or_squared_radius);

    template <typename T_ = T, bool Filled_ = Filled>
    ::std::enable_if_t<::std::is_floating_point_v<T_> && Filled_, T> area() const;
    ::tools::vector2<T> center() const;
    template <bool HasRadius_ = HasRadius>
    ::std::enable_if_t<HasRadius_, T> radius() const;
    T squared_radius() const;
    ::std::pair<int, int> where(const ::tools::circle_2d<T, Filled, HasRadius>& other) const;
    int where(const ::tools::vector2<T>& p) const;

    template <typename T_, bool Filled_, bool HasRadius1, bool HasRadius2>
    friend bool operator==(const ::tools::circle_2d<T_, Filled_, HasRadius1>& lhs, const ::tools::circle_2d<T_, Filled_, HasRadius2>& rhs);
    template <typename T_, bool Filled_, bool HasRadius1, bool HasRadius2>
    friend bool operator!=(const ::tools::circle_2d<T_, Filled_, HasRadius1>& lhs, const ::tools::circle_2d<T_, Filled_, HasRadius2>& rhs);
  };

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
    template <typename T_ = T>
    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>
    cross_point(const ::tools::directed_line_segment_2d<T>& other) const;
    template <typename T_ = T>
    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>
    cross_point(const ::tools::half_line_2d<T>& other) const;
    template <typename T_ = T>
    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>
    cross_point(const ::tools::line_2d<T>& other) const;
    template <typename T_ = T>
    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::tools::vector2<T>>
    midpoint() const;
    const ::tools::vector2<T>& p1() const;
    const ::tools::vector2<T>& p2() const;
    template <typename T_ = T>
    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, T>
    squared_distance(const ::tools::directed_line_segment_2d<T>& other) const;
    template <typename T_ = T>
    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, T>
    squared_distance(const ::tools::half_line_2d<T>& other) const;
    template <typename T_ = T>
    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, T>
    squared_distance(const ::tools::line_2d<T>& other) const;
    template <typename T_ = T>
    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, T>
    squared_distance(const ::tools::vector2<T>& p) const;
    T squared_length() const;
    ::tools::half_line_2d<T> to_half_line() const;
    ::tools::line_2d<T> to_line() const;
    ::tools::vector2<T> to_vector() const;

    ::tools::directed_line_segment_2d<T> operator+() const;
    ::tools::directed_line_segment_2d<T> operator-() const;
    template <typename T_>
    friend ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>, ::tools::directed_line_segment_2d<T_>>>>
    operator&(const ::tools::directed_line_segment_2d<T_>& lhs, const ::tools::directed_line_segment_2d<T_>& rhs);
    template <typename T_>
    friend ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>, ::tools::directed_line_segment_2d<T_>>>>
    operator&(const ::tools::directed_line_segment_2d<T_>& lhs, const ::tools::half_line_2d<T_>& rhs);
    template <typename T_>
    friend ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>, ::tools::directed_line_segment_2d<T_>>>>
    operator&(const ::tools::directed_line_segment_2d<T_>& lhs, const ::tools::line_2d<T_>& rhs);
    template <typename T_>
    friend bool operator==(const ::tools::directed_line_segment_2d<T_>& lhs, const ::tools::directed_line_segment_2d<T_>& rhs);
    template <typename T_>
    friend bool operator!=(const ::tools::directed_line_segment_2d<T_>& lhs, const ::tools::directed_line_segment_2d<T_>& rhs);
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
    template <typename T_ = T>
    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>
    cross_point(const ::tools::directed_line_segment_2d<T>& other) const;
    template <typename T_ = T>
    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>
    cross_point(const ::tools::half_line_2d<T>& other) const;
    template <typename T_ = T>
    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>
    cross_point(const ::tools::line_2d<T>& other) const;
    const ::tools::vector2<T>& d() const;
    template <typename T_ = T>
    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, T>
    squared_distance(const ::tools::directed_line_segment_2d<T>& other) const;
    template <typename T_ = T>
    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, T>
    squared_distance(const ::tools::half_line_2d<T>& other) const;
    template <typename T_ = T>
    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, T>
    squared_distance(const ::tools::line_2d<T>& other) const;
    template <typename T_ = T>
    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, T>
    squared_distance(const ::tools::vector2<T>& p) const;
    ::tools::line_2d<T> to_line() const;

    template <typename T_>
    friend ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>, ::tools::directed_line_segment_2d<T_>>>>
    operator&(const ::tools::half_line_2d<T_>& lhs, const ::tools::directed_line_segment_2d<T_>& rhs);
    template <typename T_>
    friend ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>, ::tools::directed_line_segment_2d<T_>, ::tools::half_line_2d<T_>>>>
    operator&(const ::tools::half_line_2d<T_>& lhs, const ::tools::half_line_2d<T_>& rhs);
    template <typename T_>
    friend ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>, ::tools::half_line_2d<T_>>>>
    operator&(const ::tools::half_line_2d<T_>& lhs, const ::tools::line_2d<T_>& rhs);
    template <typename T_>
    friend bool operator==(const ::tools::half_line_2d<T_>& lhs, const ::tools::half_line_2d<T_>& rhs);
    template <typename T_>
    friend bool operator!=(const ::tools::half_line_2d<T_>& lhs, const ::tools::half_line_2d<T_>& rhs);
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
    template <typename T_ = T>
    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>
    cross_point(const ::tools::directed_line_segment_2d<T>& other) const;
    template <typename T_ = T>
    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>
    cross_point(const ::tools::half_line_2d<T>& other) const;
    template <typename T_ = T>
    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>
    cross_point(const ::tools::line_2d<T>& other) const;
    bool crosses(const ::tools::line_2d<T>& other) const;
    bool is_parallel_to(const ::tools::line_2d<T>& other) const;
    ::tools::vector2<T> normal() const;
    template <typename T_ = T>
    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::tools::vector2<T>>
    projection(const ::tools::vector2<T>& p) const;
    template <typename T_ = T>
    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, T>
    squared_distance(const ::tools::directed_line_segment_2d<T>& other) const;
    template <typename T_ = T>
    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, T>
    squared_distance(const ::tools::half_line_2d<T>& other) const;
    template <typename T_ = T>
    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, T>
    squared_distance(const ::tools::line_2d<T>& other) const;
    template <typename T_ = T>
    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, T>
    squared_distance(const ::tools::vector2<T>& p) const;

    template <typename T_>
    friend ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>, ::tools::directed_line_segment_2d<T_>>>>
    operator&(const ::tools::line_2d<T_>& lhs, const ::tools::directed_line_segment_2d<T_>& rhs);
    template <typename T_>
    friend ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>, ::tools::half_line_2d<T_>>>>
    operator&(const ::tools::line_2d<T_>& lhs, const ::tools::half_line_2d<T_>& rhs);
    template <typename T_>
    friend ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>, ::tools::line_2d<T_>>>>
    operator&(const ::tools::line_2d<T_>& lhs, const ::tools::line_2d<T_>& rhs);
    template <typename T_>
    friend bool operator==(const ::tools::line_2d<T_>& lhs, const ::tools::line_2d<T_>& rhs);
    template <typename T_>
    friend bool operator!=(const ::tools::line_2d<T_>& lhs, const ::tools::line_2d<T_>& rhs);

    static ::tools::line_2d<T> through(const ::tools::vector2<T>& p1, const ::tools::vector2<T>& p2);
  };

  template <typename T, bool Filled>
  class polygon_2d {
  protected:
    ::std::vector<::tools::vector2<T>> m_points;
    T doubled_signed_area() const;

  public:
    polygon_2d() = default;
    polygon_2d(const ::tools::polygon_2d<T, Filled>&) = default;
    polygon_2d(::tools::polygon_2d<T, Filled>&&) = default;
    ~polygon_2d() = default;
    ::tools::polygon_2d<T, Filled>& operator=(const ::tools::polygon_2d<T, Filled>&) = default;
    ::tools::polygon_2d<T, Filled>& operator=(::tools::polygon_2d<T, Filled>&&) = default;

    template <typename InputIterator>
    polygon_2d(const InputIterator& begin, const InputIterator& end);
    polygon_2d(::std::initializer_list<::tools::vector2<T>> init);

    template <typename T_ = T, bool Filled_ = Filled>
    ::std::enable_if_t<(::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>) && Filled_, T> area() const;
    template <bool Filled_ = Filled>
    ::std::enable_if_t<Filled_, T> doubled_area() const;
    bool is_counterclockwise() const;
    template <typename T_ = T>
    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::tools::circle_2d<T, Filled, false>> minimum_bounding_circle() const;
    int where(const ::tools::vector2<T>& p) const;
  };

  template <typename T, bool Filled>
  class triangle_2d : public polygon_2d<T, Filled> {
  private:
    template <typename OutputIterator>
    void sorted_edges(OutputIterator result) const;

  public:
    triangle_2d() = default;
    triangle_2d(const ::tools::triangle_2d<T, Filled>&) = default;
    triangle_2d(::tools::triangle_2d<T, Filled>&&) = default;
    ~triangle_2d() = default;
    ::tools::triangle_2d<T, Filled>& operator=(const ::tools::triangle_2d<T, Filled>&) = default;
    ::tools::triangle_2d<T, Filled>& operator=(::tools::triangle_2d<T, Filled>&&) = default;

    template <typename InputIterator>
    triangle_2d(const InputIterator& begin, const InputIterator& end);
    triangle_2d(::std::initializer_list<::tools::vector2<T>> init);

    template <typename T_ = T>
    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::tools::circle_2d<T, Filled, false>> circumcircle() const;
    template <typename T_ = T>
    ::std::enable_if_t<::std::is_floating_point_v<T_>, ::tools::circle_2d<T, Filled>> incircle() const;
    template <typename T_ = T>
    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::tools::circle_2d<T, Filled, false>> minimum_bounding_circle() const;
    int type() const;
  };

  template <typename T, bool Filled, bool HasRadius>
  circle_2d<T, Filled, HasRadius>::circle_2d(const ::tools::vector2<T>& center, const T& radius_or_squared_radius) : m_center(center) {
    assert(radius_or_squared_radius > T(0));
    if constexpr (HasRadius) {
      this->m_radius = radius_or_squared_radius;
      this->m_squared_radius = ::tools::square(this->m_radius);
    } else {
      this->m_squared_radius = radius_or_squared_radius;
    }
  }

  template <typename T, bool Filled, bool HasRadius> template <typename T_, bool Filled_>
  ::std::enable_if_t<::std::is_floating_point_v<T_> && Filled_, T> circle_2d<T, Filled, HasRadius>::area() const {
    return ::std::acos(T(-1)) * this->m_squared_radius;
  }

  template <typename T, bool Filled, bool HasRadius>
  ::tools::vector2<T> circle_2d<T, Filled, HasRadius>::center() const {
    return this->m_center;
  }

  template <typename T, bool Filled, bool HasRadius> template <bool HasRadius_>
  ::std::enable_if_t<HasRadius_, T> circle_2d<T, Filled, HasRadius>::radius() const {
    return this->m_radius;
  }

  template <typename T, bool Filled, bool HasRadius>
  T circle_2d<T, Filled, HasRadius>::squared_radius() const {
    return this->m_squared_radius;
  }

  template <typename T, bool Filled, bool HasRadius>
  ::std::pair<int, int> circle_2d<T, Filled, HasRadius>::where(const ::tools::circle_2d<T, Filled, HasRadius>& other) const {
    return ::std::make_pair([&]() {
      if (*this == other) {
        return ::std::numeric_limits<int>::max();
      }
      if constexpr (HasRadius) {
        const auto d2 = (this->m_center - other.m_center).squared_l2_norm();
        const auto& a_r = this->m_radius;
        const auto& b_r = other.m_radius;
        const ::std::array<T, 2> threshold = {::tools::square(a_r - b_r), ::tools::square(a_r + b_r)};
        if (d2 < threshold[0]) {
          return 0;
        } else if (d2 == threshold[0]) {
          return 1;
        } else if (d2 == threshold[1]) {
          return 3;
        } else if (threshold[1] < d2) {
          return 4;
        } else {
          return 2;
        }
      } else {
        const auto d2 = (this->m_center - other.m_center).squared_l2_norm();
        const auto& a_r2 = this->m_squared_radius;
        const auto& b_r2 = other.m_squared_radius;
        const auto threshold = a_r2 + b_r2 - d2;
        const auto squared_threshold = ::tools::square(threshold);
        const auto v = T(4) * a_r2 * b_r2;
        if (threshold > T(0) && v < squared_threshold) {
          return 0;
        } else if (threshold > T(0) && v == squared_threshold) {
          return 1;
        } else if (threshold < T(0) && v == squared_threshold) {
          return 3;
        } else if (threshold < T(0) && v < squared_threshold) {
          return 4;
        } else {
          return 2;
        }
      }
    }(), ::tools::signum(this->m_squared_radius - other.m_squared_radius));
  }

  template <typename T, bool Filled, bool HasRadius>
  int circle_2d<T, Filled, HasRadius>::where(const ::tools::vector2<T>& p) const {
    return ::tools::signum(this->m_squared_radius - (p - this->m_center).squared_l2_norm());
  }

  template <typename T, bool Filled, bool HasRadius1, bool HasRadius2>
  bool operator==(const ::tools::circle_2d<T, Filled, HasRadius1>& lhs, const ::tools::circle_2d<T, Filled, HasRadius2>& rhs) {
    return lhs.m_center == rhs.m_center && lhs.m_squared_radius == rhs.m_squared_radius;
  }

  template <typename T, bool Filled, bool HasRadius1, bool HasRadius2>
  bool operator!=(const ::tools::circle_2d<T, Filled, HasRadius1>& lhs, const ::tools::circle_2d<T, Filled, HasRadius2>& rhs) {
    return !(lhs == rhs);
  }

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

  template <typename T> template <typename T_>
  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>
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

  template <typename T> template <typename T_>
  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>
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

  template <typename T> template <typename T_>
  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>
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
    return this->to_vector().l2_norm();
  }

  template <typename T> template <typename T_>
  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::tools::vector2<T>>
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

  template <typename T> template <typename T_>
  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, T>
  directed_line_segment_2d<T>::squared_distance(const ::tools::directed_line_segment_2d<T>& other) const {
    if (*this & other) {
      return T(0);
    }
    return ::std::min({
      other.squared_distance(this->m_p1),
      other.squared_distance(this->m_p2),
      this->squared_distance(other.m_p1),
      this->squared_distance(other.m_p2)
    });
  }

  template <typename T> template <typename T_>
  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, T>
  directed_line_segment_2d<T>::squared_distance(const ::tools::half_line_2d<T>& other) const {
    if (*this & other) {
      return T(0);
    }
    return ::std::min({
      other.squared_distance(this->m_p1),
      other.squared_distance(this->m_p2)
    });
  }

  template <typename T> template <typename T_>
  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, T>
  directed_line_segment_2d<T>::squared_distance(const ::tools::line_2d<T>& other) const {
    if (*this & other) {
      return T(0);
    }
    return ::std::min({
      other.squared_distance(this->m_p1),
      other.squared_distance(this->m_p2)
    });
  }

  template <typename T> template <typename T_>
  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, T>
  directed_line_segment_2d<T>::squared_distance(const ::tools::vector2<T>& p) const {
    const auto x = this->to_line().projection(p);
    const auto d = this->to_vector().inner_product(x - this->m_p1);
    return (p - (d < T(0) ? this->m_p1 : this->squared_length() < d ? this->m_p2 : x)).squared_l2_norm();
  }

  template <typename T>
  T directed_line_segment_2d<T>::squared_length() const {
    return this->to_vector().squared_l2_norm();
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

  template <typename T> template <typename T_>
  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>
  half_line_2d<T>::cross_point(const ::tools::directed_line_segment_2d<T>& other) const {
    return other.cross_point(*this);
  }

  template <typename T> template <typename T_>
  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>
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

  template <typename T> template <typename T_>
  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>
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

  template <typename T> template <typename T_>
  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, T>
  half_line_2d<T>::squared_distance(const ::tools::directed_line_segment_2d<T>& other) const {
    return other.squared_distance(*this);
  }

  template <typename T> template <typename T_>
  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, T>
  half_line_2d<T>::squared_distance(const ::tools::half_line_2d<T>& other) const {
    if (*this & other) {
      return T(0);
    }
    if (const auto x = this->to_line().cross_point(other.to_line()); x) {
      if (this->m_d.inner_product(*x - this->m_a) >= T(0)) {
        return (other.m_a - *x).squared_l2_norm();
      } else if (other.m_d.inner_product(*x - other.m_a) >= T(0)) {
        return (this->m_a - *x).squared_l2_norm();
      } else {
        return (this->m_a - other.m_a).squared_l2_norm();
      }
    } else {
      if (this->m_d.inner_product(other.m_a) > T(0)) {
        return this->to_line().squared_distance(other.to_line());
      } else if (const auto x = this->to_line().projection(other.m_a); this->m_d.inner_product(x - this->m_a) >= T(0)) {
        return this->to_line().squared_distance(other.to_line());
      } else {
        return (this->m_a - other.m_a).squared_l2_norm();
      }
    }
  }

  template <typename T> template <typename T_>
  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, T>
  half_line_2d<T>::squared_distance(const ::tools::line_2d<T>& other) const {
    if (*this & other) {
      return T(0);
    }
    return other.squared_distance(this->m_a);
  }

  template <typename T> template <typename T_>
  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, T>
  half_line_2d<T>::squared_distance(const ::tools::vector2<T>& p) const {
    auto x = this->to_line().projection(p);
    const auto d = this->m_d.inner_product(x - this->m_a);
    return (p - (d < T(0) ? this->m_a : x)).squared_l2_norm();
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

  template <typename T> template <typename T_>
  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>
  line_2d<T>::cross_point(const ::tools::directed_line_segment_2d<T>& other) const {
    return other.cross_point(*this);
  }

  template <typename T> template <typename T_>
  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>
  line_2d<T>::cross_point(const ::tools::half_line_2d<T>& other) const {
    return other.cross_point(*this);
  }

  template <typename T> template <typename T_>
  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>
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

  template <typename T> template <typename T_>
  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::tools::vector2<T>>
  line_2d<T>::projection(const ::tools::vector2<T>& p) const {
    return *::tools::half_line_2d<T>(p, this->normal()).to_line().cross_point(*this);
  }

  template <typename T> template <typename T_>
  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, T>
  line_2d<T>::squared_distance(const ::tools::directed_line_segment_2d<T>& other) const {
    return other.squared_distance(*this);
  }

  template <typename T> template <typename T_>
  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, T>
  line_2d<T>::squared_distance(const ::tools::half_line_2d<T>& other) const {
    return other.squared_distance(*this);
  }

  template <typename T> template <typename T_>
  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, T>
  line_2d<T>::squared_distance(const ::tools::line_2d<T>& other) const {
    if (this->is_parallel_to(other)) {
      return ::tools::square(other.m_a * this->m_c - this->m_a * other.m_c) / (::tools::square(this->m_a) + ::tools::square(this->m_b)) / ::tools::square(other.m_a);
    } else {
      return T(0);
    }
  }

  template <typename T> template <typename T_>
  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, T>
  line_2d<T>::squared_distance(const ::tools::vector2<T>& p) const {
    return (p - this->projection(p)).squared_l2_norm();
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

  template <typename T, bool Filled>
  T polygon_2d<T, Filled>::doubled_signed_area() const {
    T result(0);
    for (::std::size_t i = 0; i < this->m_points.size(); ++i) {
      result += (this->m_points[i].x - this->m_points[(i + 1) % this->m_points.size()].x) * (this->m_points[i].y + this->m_points[(i + 1) % this->m_points.size()].y);
    }
    return result;
  }

  template <typename T, bool Filled>
  template <typename InputIterator>
  polygon_2d<T, Filled>::polygon_2d(const InputIterator& begin, const InputIterator& end) : m_points(begin, end) {
    assert(this->m_points.size() >= 3);
  }

  template <typename T, bool Filled>
  polygon_2d<T, Filled>::polygon_2d(::std::initializer_list<::tools::vector2<T>> init) : polygon_2d(init.begin(), init.end()) {
  }

  template <typename T, bool Filled> template <typename T_, bool Filled_>
  ::std::enable_if_t<(::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>) && Filled_, T> polygon_2d<T, Filled>::area() const {
    return this->doubled_area() / T(2);
  }

  template <typename T, bool Filled> template <bool Filled_>
  ::std::enable_if_t<Filled_, T> polygon_2d<T, Filled>::doubled_area() const {
    return ::tools::abs(this->doubled_signed_area());
  }

  template <typename T, bool Filled>
  bool polygon_2d<T, Filled>::is_counterclockwise() const {
    return this->doubled_signed_area() > T(0);
  }

  template <typename T, bool Filled> template <typename T_>
  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::tools::circle_2d<T, Filled, false>> polygon_2d<T, Filled>::minimum_bounding_circle() const {
    ::std::optional<::tools::circle_2d<T, Filled, false>> answer;
    for (::std::size_t i = 0; i < this->m_points.size(); ++i) {
      for (::std::size_t j = i + 1; j < this->m_points.size(); ++j) {
        for (::std::size_t k = j + 1; k < this->m_points.size(); ++k) {
          if (const auto possible_answer = ::tools::triangle_2d<T, Filled>({this->m_points[i], this->m_points[j], this->m_points[k]}).minimum_bounding_circle();
              !answer || answer->squared_radius() < possible_answer.squared_radius()) {
            answer = ::std::move(possible_answer);
          }
        }
      }
    }
    return *answer;
  }

  template <typename T, bool Filled>
  int polygon_2d<T, Filled>::where(const ::tools::vector2<T>& p) const {
    ::std::vector<::tools::directed_line_segment_2d<T>> edges;
    for (::std::size_t i = 0; i < this->m_points.size(); ++i) {
      edges.emplace_back(this->m_points[i], this->m_points[(i + 1) % this->m_points.size()]);
    }

    if (std::any_of(edges.begin(), edges.end(), [&](const auto& edge) { return edge.contains(p); })) {
      return 0;
    } else {
      bool in = false;
      for (const auto& edge : edges) {
        if ([&]() {
          const auto l = edge.to_line();
          if (l == ::tools::line_2d<T>(T(0), T(1), -p.y)) return false;
          if (p.x <= edge.p1().x && p.y == edge.p1().y) return edge.p2().y < edge.p1().y;
          if (p.x <= edge.p2().x && p.y == edge.p2().y) return edge.p1().y < edge.p2().y;
          if ((edge.p1().y - p.y) * (edge.p2().y - p.y) > T(0)) return false;
          return l.a() * (l.a() * p.x + l.b() * p.y + l.c()) < T(0);
        }()) {
          in = !in;
        }
      }
      return in ? 1 : -1;
    }
  }

  template <typename T, bool Filled>
  template <typename OutputIterator>
  void triangle_2d<T, Filled>::sorted_edges(OutputIterator result) const {
    ::std::array<::tools::directed_line_segment_2d<T>, 3> edges;
    for (int i = 0; i < 3; ++i) {
      edges[i] = ::tools::directed_line_segment_2d<T>(this->m_points[i], this->m_points[(i + 1) % 3]);
    }
    ::std::sort(edges.begin(), edges.end(), ::tools::less_by([](const auto& edge) {
      return edge.squared_length();
    }));
    for (const auto& edge : edges) {
      *result = edge;
      ++result;
    }
  }

  template <typename T, bool Filled>
  template <typename InputIterator>
  triangle_2d<T, Filled>::triangle_2d(const InputIterator& begin, const InputIterator& end) : polygon_2d<T, Filled>(begin, end) {
    assert(this->m_points.size() == 3);
  }

  template <typename T, bool Filled>
  triangle_2d<T, Filled>::triangle_2d(::std::initializer_list<::tools::vector2<T>> init) : triangle_2d(init.begin(), init.end()) {
  }

  template <typename T, bool Filled> template <typename T_>
  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::tools::circle_2d<T, Filled, false>> triangle_2d<T, Filled>::circumcircle() const {
    const auto& A = this->m_points[0];
    const auto& B = this->m_points[1];
    const auto& C = this->m_points[2];
    const auto a2 = (C - B).squared_l2_norm();
    const auto b2 = (A - C).squared_l2_norm();
    const auto c2 = (B - A).squared_l2_norm();
    const auto kA = a2 * (b2 + c2 - a2);
    const auto kB = b2 * (c2 + a2 - b2);
    const auto kC = c2 * (a2 + b2 - c2);
    const auto circumcenter = (kA * A + kB * B + kC * C) / (kA + kB + kC);
    return ::tools::circle_2d<T, Filled, false>(circumcenter, (circumcenter - A).squared_l2_norm());
  }

  template <typename T, bool Filled> template <typename T_>
  ::std::enable_if_t<::std::is_floating_point_v<T_>, ::tools::circle_2d<T, Filled>> triangle_2d<T, Filled>::incircle() const {
    const auto& A = this->m_points[0];
    const auto& B = this->m_points[1];
    const auto& C = this->m_points[2];
    const auto a = (C - B).l2_norm();
    const auto b = (A - C).l2_norm();
    const auto c = (B - A).l2_norm();
    const auto incenter = (a * A + b * B + c * C) / (a + b + c);
    return ::tools::circle_2d<T, Filled>(incenter, ::tools::abs(this->doubled_signed_area()) / (a + b + c));
  }

  template <typename T, bool Filled> template <typename T_>
  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>, ::tools::circle_2d<T, Filled, false>> triangle_2d<T, Filled>::minimum_bounding_circle() const {
    ::std::array<::tools::directed_line_segment_2d<T>, 3> edges;
    this->sorted_edges(edges.begin());
    if (edges[0].squared_length() + edges[1].squared_length() <= edges[2].squared_length()) {
      const auto center = edges[2].midpoint();
      return ::tools::circle_2d<T, Filled, false>(center, (center - edges[2].p1()).squared_l2_norm());
    } else {
      return this->circumcircle();
    }
  }

  template <typename T, bool Filled>
  int triangle_2d<T, Filled>::type() const {
    ::std::array<::tools::directed_line_segment_2d<T>, 3> edges;
    this->sorted_edges(edges.begin());
    const auto c2 = edges[2].squared_length();
    const auto a2b2 = edges[1].squared_length() + edges[0].squared_length();
    if (c2 < a2b2) {
      return 0;
    } else if (c2 == a2b2) {
      return 1;
    } else {
      return 2;
    }
  }
}

#endif
