#ifndef TOOLS_POLYGON_LIKE_2D_HPP
#define TOOLS_POLYGON_LIKE_2D_HPP

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
#include <vector>
#include "tools/abs.hpp"
#include "tools/directed_line_segment_2d.hpp"
#include "tools/is_rational.hpp"
#include "tools/less_by.hpp"
#include "tools/signum.hpp"
#include "tools/square.hpp"
#include "tools/vector2.hpp"

namespace tools {
  template <typename T>
  class polygon_2d;

  template <typename T>
  class triangle_2d;

  template <typename T, bool HasRadius = true>
  class circle_2d;

  template <typename T>
  class polygon_2d {
  protected:
    ::std::vector<::tools::vector2<T>> m_points;

  private:
    T doubled_signed_area() const;

  public:
    polygon_2d() = default;
    polygon_2d(const ::tools::polygon_2d<T>&) = default;
    polygon_2d(::tools::polygon_2d<T>&&) = default;
    ~polygon_2d() = default;
    ::tools::polygon_2d<T>& operator=(const ::tools::polygon_2d<T>&) = default;
    ::tools::polygon_2d<T>& operator=(::tools::polygon_2d<T>&&) = default;

    template <typename InputIterator>
    polygon_2d(const InputIterator& begin, const InputIterator& end);
    polygon_2d(::std::initializer_list<::tools::vector2<T>> init);

    template <typename U = T>
    ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, T> area() const;
    T doubled_area() const;
    bool is_counterclockwise() const;
    template <typename U = T>
    ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::tools::circle_2d<T, false>> minimum_bounding_circle() const;
    int where(const ::tools::vector2<T>& p) const;
  };

  template <typename T>
  class triangle_2d : public polygon_2d<T> {
  private:
    template <typename OutputIterator>
    void sorted_edges(OutputIterator result) const;

  public:
    triangle_2d() = default;
    triangle_2d(const ::tools::triangle_2d<T>&) = default;
    triangle_2d(::tools::triangle_2d<T>&&) = default;
    ~triangle_2d() = default;
    ::tools::triangle_2d<T>& operator=(const ::tools::triangle_2d<T>&) = default;
    ::tools::triangle_2d<T>& operator=(::tools::triangle_2d<T>&&) = default;

    template <typename InputIterator>
    triangle_2d(const InputIterator& begin, const InputIterator& end);
    triangle_2d(::std::initializer_list<::tools::vector2<T>> init);

    template <typename U = T>
    ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::tools::circle_2d<T, false>> circumcircle() const;
    template <typename U = T>
    ::std::enable_if_t<::std::is_floating_point_v<U>, ::tools::circle_2d<T>> incircle() const;
    template <typename U = T>
    ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::tools::circle_2d<T, false>> minimum_bounding_circle() const;
    int type() const;
  };

  template <typename T, bool HasRadius>
  class circle_2d {
  private:
    using F = ::std::conditional<::std::is_floating_point_v<T>, T, double>;
    ::tools::vector2<T> m_center;
    T m_radius;
    T m_squared_radius;

  public:
    circle_2d() = default;
    circle_2d(const ::tools::circle_2d<T, HasRadius>&) = default;
    circle_2d(::tools::circle_2d<T, HasRadius>&&) = default;
    ~circle_2d() = default;
    ::tools::circle_2d<T, HasRadius>& operator=(const ::tools::circle_2d<T, HasRadius>&) = default;
    ::tools::circle_2d<T, HasRadius>& operator=(::tools::circle_2d<T, HasRadius>&&) = default;

    template <bool R = HasRadius, ::std::enable_if_t<R, ::std::nullptr_t> = nullptr>
    circle_2d(const ::tools::vector2<T>& center, const T& radius);
    template <bool R = HasRadius, ::std::enable_if_t<!R, ::std::nullptr_t> = nullptr>
    circle_2d(const ::tools::vector2<T>& center, const T& squared_radius);

    F area() const;
    ::tools::vector2<T> center() const;
    template <bool R = HasRadius>
    ::std::enable_if_t<R, T> radius() const;
    T squared_radius() const;
    ::std::pair<int, int> where(const ::tools::circle_2d<T, HasRadius>& other) const;
    int where(const ::tools::vector2<T>& p) const;

    template <typename U, bool R>
    friend bool operator==(const ::tools::circle_2d<U, R>& lhs, const ::tools::circle_2d<U, R>& rhs);
    template <typename U, bool R>
    friend bool operator!=(const ::tools::circle_2d<U, R>& lhs, const ::tools::circle_2d<U, R>& rhs);
  };

  template <typename T>
  T polygon_2d<T>::doubled_signed_area() const {
    T result(0);
    for (::std::size_t i = 0; i < this->m_points.size(); ++i) {
      result += (this->m_points[i].x - this->m_points[(i + 1) % this->m_points.size()].x) * (this->m_points[i].y + this->m_points[(i + 1) % this->m_points.size()].y);
    }
    return result;
  }

  template <typename T>
  template <typename InputIterator>
  polygon_2d<T>::polygon_2d(const InputIterator& begin, const InputIterator& end) : m_points(begin, end) {
    assert(this->m_points.size() >= 3);
  }

  template <typename T>
  polygon_2d<T>::polygon_2d(::std::initializer_list<::tools::vector2<T>> init) : polygon_2d(init.begin(), init.end()) {
  }

  template <typename T> template <typename U>
  ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, T> polygon_2d<T>::area() const {
    return this->doubled_area() / T(2);
  }

  template <typename T>
  T polygon_2d<T>::doubled_area() const {
    return ::tools::abs(this->doubled_signed_area());
  }

  template <typename T>
  bool polygon_2d<T>::is_counterclockwise() const {
    return this->doubled_signed_area() > T(0);
  }

  template <typename T> template <typename U>
  ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::tools::circle_2d<T, false>> polygon_2d<T>::minimum_bounding_circle() const {
    ::std::optional<::tools::circle_2d<T, false>> answer;
    for (::std::size_t i = 0; i < this->m_points.size(); ++i) {
      for (::std::size_t j = i + 1; j < this->m_points.size(); ++j) {
        for (::std::size_t k = j + 1; k < this->m_points.size(); ++k) {
          if (const auto possible_answer = ::tools::triangle_2d<T>({this->m_points[i], this->m_points[j], this->m_points[k]}).minimum_bounding_circle();
              !answer || answer->squared_radius() < possible_answer.squared_radius()) {
            answer = ::std::move(possible_answer);
          }
        }
      }
    }
    return *answer;
  }

  template <typename T>
  int polygon_2d<T>::where(const ::tools::vector2<T>& p) const {
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

  template <typename T>
  template <typename OutputIterator>
  void triangle_2d<T>::sorted_edges(OutputIterator result) const {
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

  template <typename T>
  template <typename InputIterator>
  triangle_2d<T>::triangle_2d(const InputIterator& begin, const InputIterator& end) : polygon_2d<T>(begin, end) {
    assert(this->m_points.size() == 3);
  }

  template <typename T>
  triangle_2d<T>::triangle_2d(::std::initializer_list<::tools::vector2<T>> init) : triangle_2d(init.begin(), init.end()) {
  }

  template <typename T> template <typename U>
  ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::tools::circle_2d<T, false>> triangle_2d<T>::circumcircle() const {
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
    return ::tools::circle_2d<T, false>(circumcenter, (circumcenter - A).squared_l2_norm());
  }

  template <typename T> template <typename U>
  ::std::enable_if_t<::std::is_floating_point_v<U>, ::tools::circle_2d<T>> triangle_2d<T>::incircle() const {
    const auto& A = this->m_points[0];
    const auto& B = this->m_points[1];
    const auto& C = this->m_points[2];
    const auto a = (C - B).l2_norm();
    const auto b = (A - C).l2_norm();
    const auto c = (B - A).l2_norm();
    const auto incenter = (a * A + b * B + c * C) / (a + b + c);
    return ::tools::circle_2d<T>(incenter, this->doubled_area() / (a + b + c));
  }

  template <typename T> template <typename U>
  ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::tools::circle_2d<T, false>> triangle_2d<T>::minimum_bounding_circle() const {
    ::std::array<::tools::directed_line_segment_2d<T>, 3> edges;
    this->sorted_edges(edges.begin());
    if (edges[0].squared_length() + edges[1].squared_length() <= edges[2].squared_length()) {
      const auto center = edges[2].midpoint();
      return ::tools::circle_2d<T, false>(center, (center - edges[2].p1()).squared_l2_norm());
    } else {
      return this->circumcircle();
    }
  }

  template <typename T>
  int triangle_2d<T>::type() const {
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

  template <typename T, bool HasRadius> template <bool R, ::std::enable_if_t<R, ::std::nullptr_t>>
  circle_2d<T, HasRadius>::circle_2d(const ::tools::vector2<T>& center, const T& radius) : m_center(center), m_radius(radius), m_squared_radius(radius * radius) {
    assert(radius > T(0));
  }

  template <typename T, bool HasRadius> template <bool R, ::std::enable_if_t<!R, ::std::nullptr_t>>
  circle_2d<T, HasRadius>::circle_2d(const ::tools::vector2<T>& center, const T& squared_radius) : m_center(center), m_squared_radius(squared_radius) {
    assert(squared_radius > T(0));
  }

  template <typename T, bool HasRadius>
  typename circle_2d<T, HasRadius>::F circle_2d<T, HasRadius>::area() const {
    return ::std::acos(static_cast<F>(-1)) * static_cast<F>(this->squared_radius);
  }

  template <typename T, bool HasRadius>
  ::tools::vector2<T> circle_2d<T, HasRadius>::center() const {
    return this->m_center;
  }

  template <typename T, bool HasRadius> template <bool R>
  ::std::enable_if_t<R, T> circle_2d<T, HasRadius>::radius() const {
    return this->m_radius;
  }

  template <typename T, bool HasRadius>
  T circle_2d<T, HasRadius>::squared_radius() const {
    return this->m_squared_radius;
  }

  template <typename T, bool HasRadius>
  ::std::pair<int, int> circle_2d<T, HasRadius>::where(const ::tools::circle_2d<T, HasRadius>& other) const {
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

  template <typename T, bool HasRadius>
  int circle_2d<T, HasRadius>::where(const ::tools::vector2<T>& p) const {
    return ::tools::signum(this->m_squared_radius - (p - this->m_center).squared_l2_norm());
  }

  template <typename T, bool HasRadius>
  bool operator==(const ::tools::circle_2d<T, HasRadius>& lhs, const ::tools::circle_2d<T, HasRadius>& rhs) {
    return lhs.m_center == rhs.m_center && lhs.m_squared_radius == rhs.m_squared_radius;
  }

  template <typename T, bool HasRadius>
  bool operator!=(const ::tools::circle_2d<T, HasRadius>& lhs, const ::tools::circle_2d<T, HasRadius>& rhs) {
    return !(lhs == rhs);
  }
}

#endif
