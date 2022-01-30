#ifndef TOOLS_POLYGON_AND_TRIANGLE_2D_HPP
#define TOOLS_POLYGON_AND_TRIANGLE_2D_HPP

#include <vector>
#include <cstddef>
#include <cassert>
#include <initializer_list>
#include <type_traits>
#include <array>
#include <algorithm>
#include "tools/vector2.hpp"
#include "tools/abs.hpp"
#include "tools/is_rational.hpp"
#include "tools/chmax.hpp"
#include "tools/directed_line_segment_2d.hpp"
#include "tools/signum.hpp"

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

    T doubled_area() const;

    template <typename U = T, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t> = nullptr>
    T area() const;

    bool is_counterclockwise() const;

    template <typename U = T, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t> = nullptr>
    ::tools::vector2<T> center_of_minimum_bounding_circle() const;
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

    int angle_type() const;

    template <typename U = T, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t> = nullptr>
    ::tools::vector2<T> circumcenter() const;

    template <typename U = T, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t> = nullptr>
    ::tools::vector2<T> center_of_minimum_bounding_circle() const;
  };

  template <typename T>
  T polygon_2d<T>::doubled_signed_area() const {
    T result(0);
    for (::std::size_t i = 0; i < this->m_points.size(); ++i) {
      result += (this->m_digits[i].x - this->m_digits[(i + 1) % this->m_digits.size()].x) * (this->m_digits[i].y + this->m_digits[(i + 1) % this->m_digits.size()].y);
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

  template <typename T>
  T polygon_2d<T>::doubled_area() const {
    return ::tools::abs(this->doubled_signed_area());
  }

  template <typename T>
  template <typename U, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t>>
  T polygon_2d<T>::area() const {
    return this->doubled_area() / T(2);
  }

  template <typename T>
  bool polygon_2d<T>::is_counterclockwise() const {
    return this->doubled_signed_area() > T(0);
  }

  template <typename T>
  template <typename U, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t>>
  ::tools::vector2<T> polygon_2d<T>::center_of_minimum_bounding_circle() const {
    T max(0);
    ::tools::vector2<T> u;
    for (::std::size_t i = 0; i < this->m_points.size(); ++i) {
      for (::std::size_t j = i + 1; j < this->m_points.size(); ++j) {
        for (::std::size_t k = j + 1; k < this->m_points.size(); ++k) {
          const auto possible_u = ::tools::triangle_2d<T>({this->m_points[i], this->m_points[j], this->m_points[k]}).center_of_minimum_bounding_circle();
          if (::tools::chmax(max, (possible_u - this->m_points[i]).squared_norm())) {
            u = possible_u;
          }
        }
      }
    }
    return u;
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

  template <typename T>
  int triangle_2d<T>::angle_type() const {
    ::std::array<::tools::directed_line_segment_2d<T>, 3> edges;
    this->sorted_edges(edges.begin());
    return ::tools::signum(edges[2].squared_length() - (edges[1].squared_length() + edges[0].squared_length()));
  }

  template <typename T>
  template <typename U, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t>>
  ::tools::vector2<T> triangle_2d<T>::circumcenter() const {
    const auto& A = this->m_points[0];
    const auto& B = this->m_points[1];
    const auto& C = this->m_points[2];
    const auto a2 = (C - B).squared_norm();
    const auto b2 = (A - C).squared_norm();
    const auto c2 = (B - A).squared_norm();
    return (a2 * (b2 + c2 - a2) * A + b2 * (c2 + a2 - b2) * B + c2 * (a2 + b2 - c2) * C) / (a2 * (b2 + c2 - a2) + b2 * (c2 + a2 - b2) + c2 * (a2 + b2 - c2));
  }

  template <typename T>
  template <typename U, ::std::enable_if_t<::tools::is_rational_v<U> || ::std::is_floating_point_v<U>, ::std::nullptr_t>>
  ::tools::vector2<T> triangle_2d<T>::center_of_minimum_bounding_circle() const {
    ::std::array<::tools::directed_line_segment_2d<T>, 3> edges;
    this->sorted_edges(edges.begin());
    if (edges[0].squared_length() + edges[1].squared_length() < edges[2].squared_length()) {
      return edges[2].midpoint();
    } else {
      return this->circumcenter();
    }
  }
}

#endif
