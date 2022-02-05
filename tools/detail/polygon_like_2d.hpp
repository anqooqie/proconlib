#ifndef TOOLS_POLYGON_LIKE_2D_HPP
#define TOOLS_POLYGON_LIKE_2D_HPP

#include <algorithm>
#include <array>
#include <cassert>
#include <cstddef>
#include <initializer_list>
#include <type_traits>
#include <vector>
#include "tools/abs.hpp"
#include "tools/chmax.hpp"
#include "tools/directed_line_segment_2d.hpp"
#include "tools/is_rational.hpp"
#include "tools/less_by.hpp"
#include "tools/vector2.hpp"

namespace tools {
  template <typename T>
  class polygon_2d;

  template <typename T>
  class triangle_2d;

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
    ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::pair<::tools::vector2<T>, T>> minimum_bounding_circle() const;
    enum class position {
      inside,
      on_edge,
      outside
    };
    typename ::tools::polygon_2d<T>::position where(const ::tools::vector2<T>& p) const;
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
    ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::tools::vector2<T>> circumcenter() const;
    template <typename U = T>
    ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::pair<::tools::vector2<T>, T>> minimum_bounding_circle() const;
    enum class triangle_type {
      acute,
      right,
      obtuse
    };
    typename ::tools::triangle_2d<T>::triangle_type type() const;
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
  ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::pair<::tools::vector2<T>, T>> polygon_2d<T>::minimum_bounding_circle() const {
    T squared_radius(0);
    ::tools::vector2<T> center;
    for (::std::size_t i = 0; i < this->m_points.size(); ++i) {
      for (::std::size_t j = i + 1; j < this->m_points.size(); ++j) {
        for (::std::size_t k = j + 1; k < this->m_points.size(); ++k) {
          const auto [possible_center, possible_squared_radius] = ::tools::triangle_2d<T>({this->m_points[i], this->m_points[j], this->m_points[k]}).minimum_bounding_circle();
          if (::tools::chmax(squared_radius, possible_squared_radius)) {
            center = possible_center;
          }
        }
      }
    }
    return ::std::make_pair(center, squared_radius);
  }

  template <typename T>
  typename ::tools::polygon_2d<T>::position polygon_2d<T>::where(const ::tools::vector2<T>& p) const {
    ::std::vector<::tools::directed_line_segment_2d<T>> edges;
    for (::std::size_t i = 0; i < this->m_points.size(); ++i) {
      edges.emplace_back(this->m_points[i], this->m_points[(i + 1) % this->m_points.size()]);
    }

    if (std::any_of(edges.begin(), edges.end(), [&](const auto& edge) { return edge.contains(p); })) {
      return ::tools::polygon_2d<T>::position::on_edge;
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
      return in ? ::tools::polygon_2d<T>::position::inside : ::tools::polygon_2d<T>::position::outside;
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
  ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::tools::vector2<T>> triangle_2d<T>::circumcenter() const {
    const auto& A = this->m_points[0];
    const auto& B = this->m_points[1];
    const auto& C = this->m_points[2];
    const auto a2 = (C - B).squared_norm();
    const auto b2 = (A - C).squared_norm();
    const auto c2 = (B - A).squared_norm();
    const auto kA = a2 * (b2 + c2 - a2);
    const auto kB = b2 * (c2 + a2 - b2);
    const auto kC = c2 * (a2 + b2 - c2);
    return (kA * A + kB * B + kC * C) / (kA + kB + kC);
  }

  template <typename T> template <typename U>
  ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::pair<::tools::vector2<T>, T>> triangle_2d<T>::minimum_bounding_circle() const {
    ::std::array<::tools::directed_line_segment_2d<T>, 3> edges;
    this->sorted_edges(edges.begin());
    if (edges[0].squared_length() + edges[1].squared_length() < edges[2].squared_length()) {
      const auto center = edges[2].midpoint();
      return ::std::make_pair(center, (center - edges[2].p1()).squared_norm());
    } else {
      const auto center = this->circumcenter();
      return ::std::make_pair(center, (center - this->m_points[0]).squared_norm());
    }
  }

  template <typename T>
  typename ::tools::triangle_2d<T>::triangle_type triangle_2d<T>::type() const {
    ::std::array<::tools::directed_line_segment_2d<T>, 3> edges;
    this->sorted_edges(edges.begin());
    const auto comp = edges[2].squared_length() - (edges[1].squared_length() + edges[0].squared_length());
    if (comp < T(0)) {
      return ::tools::triangle_2d<T>::triangle_type::acute;
    } else if (comp == T(0)) {
      return ::tools::triangle_2d<T>::triangle_type::right;
    } else {
      return ::tools::triangle_2d<T>::triangle_type::obtuse;
    }
  }
}

#endif
