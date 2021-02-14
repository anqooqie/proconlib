#ifndef DETAIL_ELEMENT_2D_HPP
#define DETAIL_ELEMENT_2D_HPP

#include <vector>
#include <stdexcept>
#include "../vector2.hpp"
#include "../variant.hpp"
#include "../optional.hpp"
#include "../signum.hpp"

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
    vector2<T> m_p1;
    vector2<T> m_p2;

  public:
    directed_line_segment_2d();
    directed_line_segment_2d(const vector2<T>& p1, const vector2<T>& p2);

    const vector2<T>& p1() const;
    const vector2<T>& p2() const;

    vector2<T> to_vector() const;
    half_line_2d<T> to_half_line() const;
    line_2d<T> to_line() const;
    double length() const;
    T squared_length() const;
    vector2<T> midpoint() const;
    bool contains(const vector2<T>& p) const;

    optional<vector2<T>> cross_point(const directed_line_segment_2d<T>& other) const;
    optional<vector2<T>> cross_point(const half_line_2d<T>& other) const;
    optional<vector2<T>> cross_point(const line_2d<T>& other) const;
    std::vector<variant<vector2<T>, directed_line_segment_2d<T>>> intersection(const directed_line_segment_2d<T>& other) const;
    std::vector<variant<vector2<T>, directed_line_segment_2d<T>>> intersection(const half_line_2d<T>& other) const;
    std::vector<variant<vector2<T>, directed_line_segment_2d<T>>> intersection(const line_2d<T>& other) const;

    directed_line_segment_2d<T> operator+() const;
    directed_line_segment_2d<T> operator-() const;
    bool operator==(const directed_line_segment_2d<T>& other) const;
  };
}

namespace tools {
  template <typename T>
  class half_line_2d {
  private:
    vector2<T> m_a;
    vector2<T> m_d;

  public:
    half_line_2d();
    half_line_2d(const vector2<T>& a, const vector2<T>& d);

    const vector2<T>& a() const;
    const vector2<T>& d() const;

    line_2d<T> to_line() const;
    bool contains(const vector2<T>& p) const;

    optional<vector2<T>> cross_point(const directed_line_segment_2d<T>& other) const;
    optional<vector2<T>> cross_point(const half_line_2d<T>& other) const;
    std::vector<variant<vector2<T>, directed_line_segment_2d<T>>> intersection(const directed_line_segment_2d<T>& other) const;
    std::vector<variant<vector2<T>, directed_line_segment_2d<T>, half_line_2d<T>>> intersection(const half_line_2d<T>& other) const;

    bool operator==(const half_line_2d<T>& other) const;
  };
}

namespace tools {
  template <typename T>
  class line_2d {
  private:
    T m_a;
    T m_b;
    T m_c;

  public:
    line_2d();
    line_2d(const T& a, const T& b, const T& c);

    const T& a() const;
    const T& b() const;
    const T& c() const;

    bool contains(const vector2<T>& p) const;
    bool is_parallel_to(const line_2d<T>& other) const;

    bool crosses(const line_2d<T>& other) const;
    optional<vector2<T>> cross_point(const line_2d<T>& other) const;
    vector2<T> unsafe_cross_point(const line_2d<T>& other) const;
    bool intersects(const line_2d<T>& other) const;
    std::vector<variant<vector2<T>, line_2d<T>>> intersection(const line_2d<T>& other) const;
    std::vector<variant<vector2<T>, directed_line_segment_2d<T>>> intersection(const directed_line_segment_2d<T>& other) const;

    bool operator==(const line_2d<T>& other) const;

    static line_2d<T> through(const vector2<T>& p1, const vector2<T>& p2);
  };
}

namespace tools {
  template <typename T>
  directed_line_segment_2d<T>::directed_line_segment_2d() :
    directed_line_segment_2d(vector2<T>(), vector2<T>()) {
  }

  template <typename T>
  directed_line_segment_2d<T>::directed_line_segment_2d(const vector2<T>& p1, const vector2<T>& p2) :
    m_p1(p1),
    m_p2(p2) {
    if (p1 == p2) throw std::domain_error("Two ends must differ.");
  }

  template <typename T>
  const vector2<T>& directed_line_segment_2d<T>::p1() const {
    return this->m_p1;
  }

  template <typename T>
  const vector2<T>& directed_line_segment_2d<T>::p2() const {
    return this->m_p2;
  }

  template <typename T>
  vector2<T> directed_line_segment_2d<T>::to_vector() const {
    return this->m_p2 - this->m_p1;
  }

  template <typename T>
  half_line_2d<T> directed_line_segment_2d<T>::to_half_line() const {
    return half_line_2d<T>(this->m_p1, this->m_p2 - this->m_p1);
  }

  template <typename T>
  line_2d<T> directed_line_segment_2d<T>::to_line() const {
    return line_2d<T>::through(this->m_p1, this->m_p2);
  }

  template <typename T>
  double directed_line_segment_2d<T>::length() const {
    return this->to_vector().norm();
  }

  template <typename T>
  T directed_line_segment_2d<T>::squared_length() const {
    return this->to_vector().squared_norm();
  }

  template <typename T>
  vector2<T> directed_line_segment_2d<T>::midpoint() const {
    return (this->m_p1 + this->m_p2) / 2;
  }

  template <typename T>
  bool directed_line_segment_2d<T>::contains(const vector2<T>& p) const {
    if (p == this->m_p1 || p == this->m_p2) return true;
    const line_2d<T> l = this->to_line();
    if (!l.contains(p)) return false;
    const T d = (p - this->m_p1).inner_product(this->to_vector());
    return 0 <= d && d <= this->squared_length();
  }

  template <typename T>
  optional<vector2<T>> directed_line_segment_2d<T>::cross_point(const directed_line_segment_2d<T>& other) const {
    const std::vector<variant<vector2<T>, directed_line_segment_2d<T>>> intersections = this->intersection(other);
    struct {
      optional<vector2<T>> operator()(const vector2<T>& v) {
        return optional<vector2<T>>(v);
      }
      optional<vector2<T>> operator()(const directed_line_segment_2d<T>&) {
        return optional<vector2<T>>();
      }
    } visitor;
    return intersections.size() == 1 ? intersections.front().template visit<optional<vector2<T>>>(visitor) : optional<vector2<T>>();
  }

  template <typename T>
  optional<vector2<T>> directed_line_segment_2d<T>::cross_point(const half_line_2d<T>& other) const {
    const std::vector<variant<vector2<T>, directed_line_segment_2d<T>>> intersections = this->intersection(other);
    struct {
      optional<vector2<T>> operator()(const vector2<T>& v) {
        return optional<vector2<T>>(v);
      }
      optional<vector2<T>> operator()(const directed_line_segment_2d<T>&) {
        return optional<vector2<T>>();
      }
    } visitor;
    return intersections.size() == 1 ? intersections.front().template visit<optional<vector2<T>>>(visitor) : optional<vector2<T>>();
  }

  template <typename T>
  optional<vector2<T>> directed_line_segment_2d<T>::cross_point(const line_2d<T>& other) const {
    const std::vector<variant<vector2<T>, directed_line_segment_2d<T>>> intersections = this->intersection(other);
    struct {
      optional<vector2<T>> operator()(const vector2<T>& v) {
        return optional<vector2<T>>(v);
      }
      optional<vector2<T>> operator()(const directed_line_segment_2d<T>&) {
        return optional<vector2<T>>();
      }
    } visitor;
    return intersections.size() == 1 ? intersections.front().template visit<optional<vector2<T>>>(visitor) : optional<vector2<T>>();
  }

  template <typename T>
  std::vector<variant<vector2<T>, directed_line_segment_2d<T>>> directed_line_segment_2d<T>::intersection(const directed_line_segment_2d<T>& other) const {
    typedef variant<vector2<T>, directed_line_segment_2d<T>> variant_t;
    typedef std::vector<variant_t> result_t;
    const line_2d<T> l1 = this->to_line();
    const line_2d<T> l2 = other.to_line();
    if (l1 == l2) {
      const vector2<T> base = this->to_vector();
      const directed_line_segment_2d<T> fixed_other = base.inner_product(other.to_vector()) > 0 ? other : -other;
      const T d1 = 0;
      const T d2 = base.inner_product(base);
      const T d3 = base.inner_product(fixed_other.m_p1 - this->m_p1);
      const T d4 = base.inner_product(fixed_other.m_p2 - this->m_p2);
      if (d1 == d4) return result_t({this->m_p1});
      if (d2 == d3) return result_t({this->m_p2});
      if (d3 <= d1 && d2 <= d4) return result_t({*this});
      if (d1 <= d3 && d4 <= d2) return result_t({fixed_other});
      if (d3 <= d1 && d1 <= d4 && d4 <= d2) return result_t({directed_line_segment_2d<T>(this->m_p1, fixed_other.m_p2)});
      if (d1 <= d3 && d3 <= d2 && d2 <= d4) return result_t({directed_line_segment_2d<T>(fixed_other.m_p1, this->m_p2)});
      return result_t();
    }
    if (l1.is_parallel_to(l2)) return result_t();
    if (this->m_p1 == other.m_p1 || this->m_p1 == other.m_p2) return result_t({this->m_p1});
    if (this->m_p2 == other.m_p1 || this->m_p2 == other.m_p2) return result_t({this->m_p2});
    if (((other.m_p1.y - this->m_p1.y) * (this->m_p2.x - this->m_p1.x) - (this->m_p2.y - this->m_p1.y) * (other.m_p1.x - this->m_p1.x)) *
        ((other.m_p2.y - this->m_p1.y) * (this->m_p2.x - this->m_p1.x) - (this->m_p2.y - this->m_p1.y) * (other.m_p2.x - this->m_p1.x)) > 0 ||
        ((this->m_p1.y - other.m_p1.y) * (other.m_p2.x - other.m_p1.x) - (other.m_p2.y - other.m_p1.y) * (this->m_p1.x - other.m_p1.x)) *
        ((this->m_p2.y - other.m_p1.y) * (other.m_p2.x - other.m_p1.x) - (other.m_p2.y - other.m_p1.y) * (this->m_p2.x - other.m_p1.x)) > 0) return result_t();
    return result_t({variant_t(l1.unsafe_cross_point(l2))});
  }

  template <typename T>
  std::vector<variant<vector2<T>, directed_line_segment_2d<T>>> directed_line_segment_2d<T>::intersection(const half_line_2d<T>& other) const {
    typedef variant<vector2<T>, directed_line_segment_2d<T>> variant_t;
    typedef std::vector<variant_t> result_t;
    const line_2d<T> l1 = this->to_line();
    const line_2d<T> l2 = other.to_line();
    if (l1 == l2) {
      const bool has_same_direction = other.d().inner_product(this->to_vector()) > 0;
      const T d1 = other.d().inner_product(this->m_p1 - other.a());
      const T d2 = other.d().inner_product(this->m_p2 - other.a());
      if (has_same_direction) {
        if (d2 < 0) return result_t();
        if (d2 == 0) return result_t({other.a()});
        if (d1 < 0) return result_t({directed_line_segment_2d<T>(other.a(), this->m_p2)});
        return result_t({*this});
      } else {
        if (d1 > 0) return result_t();
        if (d1 == 0) return result_t({other.a()});
        if (d2 > 0) return result_t({directed_line_segment_2d<T>(this->m_p1, other.a())});
        return result_t({*this});
      }
    }
    if (other.contains(this->m_p1)) return result_t({this->m_p1});
    if (other.contains(this->m_p2)) return result_t({this->m_p2});
    if ((l2.a() * this->m_p1.x + l2.b() * this->m_p1.y + l2.c()) * (l2.a() * this->m_p2.x + l2.b() * this->m_p2.y + l2.c()) > 0) return result_t();
    const vector2<T> possible_cross_point = l1.unsafe_cross_point(l2);
    if (other.d().inner_product(possible_cross_point - other.a()) < 0) return result_t();
    return result_t({variant_t(possible_cross_point)});
  }

  template <typename T>
  std::vector<variant<vector2<T>, directed_line_segment_2d<T>>> directed_line_segment_2d<T>::intersection(const line_2d<T>& other) const {
    typedef variant<vector2<T>, directed_line_segment_2d<T>> variant_t;
    typedef std::vector<variant_t> result_t;
    const line_2d<T> this_line = this->to_line();
    if (this_line == other) return result_t({*this});
    if (other.contains(this->m_p1)) return result_t({this->m_p1});
    if (other.contains(this->m_p2)) return result_t({this->m_p2});
    if ((other.a() * this->m_p1.x + other.b() * this->m_p1.y + other.c()) * (other.a() * this->m_p2.x + other.b() * this->m_p2.y + other.c()) > 0) return result_t();
    return result_t({variant_t(this_line.unsafe_cross_point(other))});
  }

  template <typename T>
  directed_line_segment_2d<T> directed_line_segment_2d<T>::operator+() const {
    return *this;
  }

  template <typename T>
  directed_line_segment_2d<T> directed_line_segment_2d<T>::operator-() const {
    return directed_line_segment_2d(this->m_p2, this->m_p1);
  }

  template <typename T>
  bool directed_line_segment_2d<T>::operator==(const tools::directed_line_segment_2d<T>& other) const {
    return this->p1() == other.p1() && this->p2() == other.p2();
  }
}

namespace tools {
  template <typename T>
  half_line_2d<T>::half_line_2d() :
    half_line_2d(vector2<T>(0, 0), vector2<T>(1, 0)) {
  }

  template <typename T>
  half_line_2d<T>::half_line_2d(const vector2<T>& a, const vector2<T>& d) :
    m_a(a),
    m_d(d) {
    if (d == vector2<T>(0, 0)) throw std::domain_error("d cannot be zero vector.");
  }

  template <typename T>
  const vector2<T>& half_line_2d<T>::a() const {
    return this->m_a;
  }

  template <typename T>
  const vector2<T>& half_line_2d<T>::d() const {
    return this->m_d;
  }

  template <typename T>
  line_2d<T> half_line_2d<T>::to_line() const {
    return line_2d<T>::through(this->m_a, this->m_a + this->m_d);
  }

  template <typename T>
  bool half_line_2d<T>::contains(const vector2<T>& p) const {
    const line_2d<T> l = this->to_line();
    return l.a() * p.x + l.b() * p.y + l.c() == 0 && this->m_d.inner_product(p - this->m_a) >= 0;
  }

  template <typename T>
  optional<vector2<T>> half_line_2d<T>::cross_point(const directed_line_segment_2d<T>& other) const {
    return other.cross_point(*this);
  }

  template <typename T>
  optional<vector2<T>> half_line_2d<T>::cross_point(const half_line_2d<T>& other) const {
    const std::vector<variant<vector2<T>, directed_line_segment_2d<T>, half_line_2d<T>>> intersections = this->intersection(other);
    struct {
      optional<vector2<T>> operator()(const vector2<T>& v) {
        return optional<vector2<T>>(v);
      }
      optional<vector2<T>> operator()(const directed_line_segment_2d<T>&) {
        return optional<vector2<T>>();
      }
      optional<vector2<T>> operator()(const half_line_2d<T>&) {
        return optional<vector2<T>>();
      }
    } visitor;
    return intersections.size() == 1 ? intersections.front().template visit<optional<vector2<T>>>(visitor) : optional<vector2<T>>();
  }

  template <typename T>
  std::vector<variant<vector2<T>, directed_line_segment_2d<T>>> half_line_2d<T>::intersection(const directed_line_segment_2d<T>& other) const {
    return other.intersection(*this);
  }

  template <typename T>
  std::vector<variant<vector2<T>, directed_line_segment_2d<T>, half_line_2d<T>>> half_line_2d<T>::intersection(const half_line_2d<T>& other) const {
    typedef std::vector<variant<vector2<T>, directed_line_segment_2d<T>, half_line_2d<T>>> result_t;
    const line_2d<T> l1 = this->to_line();
    const line_2d<T> l2 = other.to_line();
    if (l1 == l2) {
      if (this->d().inner_product(other.d()) > 0) {
        switch (tools::signum(this->d().inner_product(other.a() - this->a()))) {
        case 1:
        case 0:
          return result_t({other});
        case -1:
          return result_t({*this});
        default:
          throw std::runtime_error("Cannot happen.");
        }
      } else {
        switch (tools::signum(this->d().inner_product(other.a() - this->a()))) {
        case 1:
          return result_t({directed_line_segment_2d<T>(this->a(), other.a())});
        case 0:
          return result_t({this->a()});
        case -1:
          return result_t();
        default:
          throw std::runtime_error("Cannot happen.");
        }
      }
    } else if (l1.is_parallel_to(l2)) {
      return result_t();
    } else {
      const vector2<T> possible_cross_point = l1.unsafe_cross_point(l2);
      if (this->d().inner_product(possible_cross_point - this->a()) < 0 || other.d().inner_product(possible_cross_point - other.a()) < 0) {
        return result_t();
      }
      return result_t({possible_cross_point});
    }
  }

  template <typename T>
  bool half_line_2d<T>::operator==(const tools::half_line_2d<T>& other) const {
    return this->a() == other.a() && this->d().x * other.d().y == other.d().x * this->d().y;
  }
}

namespace tools {
  template <typename T>
  line_2d<T>::line_2d() :
    line_2d(T(0), T(1), T(0)) {
  }

  template <typename T>
  line_2d<T>::line_2d(const T& a, const T& b, const T& c) :
    m_a(a),
    m_b(b),
    m_c(c) {
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
  bool line_2d<T>::contains(const vector2<T>& p) const {
    return this->m_a * p.x + this->m_b * p.y + this->m_c == 0;
  }

  template <typename T>
  bool line_2d<T>::is_parallel_to(const line_2d<T>& other) const {
    return this->a() * other.b() == this->b() * other.a() && (this->b() * other.c() != this->c() * other.b() || this->c() * other.a() != this->a() * other.c());
  }

  template <typename T>
  bool line_2d<T>::crosses(const line_2d<T>& other) const {
    return this->a() * other.b() - other.a() * this->b() != 0;
  }

  template <typename T>
  optional<vector2<T>> line_2d<T>::cross_point(const line_2d<T>& other) const {
    if (!this->crosses(other)) return optional<vector2<T>>();
    return optional<vector2<T>>(this->unsafe_cross_point(other));
  }

  template <typename T>
  vector2<T> line_2d<T>::unsafe_cross_point(const line_2d<T>& other) const {
    return vector2<T>(
      (this->b() * other.c() - other.b() * this->c()) / (this->a() * other.b() - other.a() * this->b()),
      (other.a() * this->c() - this->a() * other.c()) / (this->a() * other.b() - other.a() * this->b())
    );
  }

  template <typename T>
  bool line_2d<T>::intersects(const line_2d<T>& other) const {
    return this == other || this->crosses(other);
  }

  template <typename T>
  std::vector<variant<vector2<T>, line_2d<T>>> line_2d<T>::intersection(const line_2d<T>& other) const {
    typedef std::vector<variant<vector2<T>, line_2d<T>>> result_t;
    if (this == other) return result_t({*this});
    if (this->crosses(other)) return result_t({this->unsafe_cross_point(other)});
    return result_t();
  }

  template <typename T>
  std::vector<variant<vector2<T>, directed_line_segment_2d<T>>> line_2d<T>::intersection(const directed_line_segment_2d<T>& other) const {
    return other.intersection(*this);
  }

  template <typename T>
  bool line_2d<T>::operator==(const tools::line_2d<T>& other) const {
    return this->b() * other.c() == this->c() * other.b() && this->c() * other.a() == this->a() * other.c() && this->a() * other.b() == this->b() * other.a();
  }

  template <typename T>
  line_2d<T> line_2d<T>::through(const vector2<T>& p1, const vector2<T>& p2) {
    return line_2d(p1.y - p2.y, p2.x - p1.x, (p2.y - p1.y) * p1.x - (p2.x - p1.x) * p1.y);
  }
}

#endif
