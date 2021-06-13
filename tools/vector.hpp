#ifndef TOOLS_VECTOR_HPP
#define TOOLS_VECTOR_HPP

#include <vector>
#include <cstddef>
#include <cassert>

namespace tools {
  template <typename T>
  class vector {
  private:
    ::std::vector<T> m_values;

  public:
    vector() = default;
    vector(const ::tools::vector<T>&) = default;
    vector(::tools::vector<T>&&) = default;
    ~vector() = default;
    ::tools::vector<T>& operator=(const ::tools::vector<T>&) = default;
    ::tools::vector<T>& operator=(::tools::vector<T>&&) = default;

    vector(::std::size_t dim) : m_values(dim) {
    }
    vector(::std::size_t dim, const T& value) : m_values(dim, value) {
    }

    T& at(const ::std::size_t i) {
      return this->m_values[i];
    }
    T at(const ::std::size_t i) const {
      return this->m_values[i];
    }

    ::std::size_t dim() const {
      return this->m_values.size();
    }

    friend ::tools::vector<T>& operator+(::tools::vector<T>& self) {
      return self;
    }
    friend const ::tools::vector<T>& operator+(const ::tools::vector<T>& self) {
      return self;
    }
    friend ::tools::vector<T> operator+(const ::tools::vector<T>& lhs, const ::tools::vector<T>& rhs) {
      assert(lhs.dim() == rhs.dim());
      ::tools::vector<T> result(lhs);
      for (::std::size_t i = 0; i < lhs.dim(); ++i) {
        result.m_values[i] += rhs.m_values[i];
      }
      return result;
    }
    friend ::tools::vector<T> operator-(const ::tools::vector<T>& self) {
      ::tools::vector<T> result(self);
      for (::std::size_t i = 0; i < self.dim(); ++i) {
        result.m_values[i] *= -1;
      }
      return result;
    }
    friend ::tools::vector<T> operator-(const ::tools::vector<T>& lhs, const ::tools::vector<T>& rhs) {
      assert(lhs.dim() == rhs.dim());
      ::tools::vector<T> result(lhs);
      for (::std::size_t i = 0; i < lhs.dim(); ++i) {
        result.m_values[i] -= rhs.m_values[i];
      }
      return result;
    }
  };
}

#endif
