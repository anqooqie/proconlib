---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: tools/vector.hpp
    title: tools/vector.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/matrix.hpp\"\n\n\n\n#include <vector>\n#include <cstddef>\n\
    #include <cassert>\n#include <algorithm>\n#line 1 \"tools/vector.hpp\"\n\n\n\n\
    #line 7 \"tools/vector.hpp\"\n\nnamespace tools {\n  template <typename T>\n \
    \ class vector {\n  private:\n    ::std::vector<T> m_values;\n\n  public:\n  \
    \  vector() = default;\n    vector(const ::tools::vector<T>&) = default;\n   \
    \ vector(::tools::vector<T>&&) = default;\n    ~vector() = default;\n    ::tools::vector<T>&\
    \ operator=(const ::tools::vector<T>&) = default;\n    ::tools::vector<T>& operator=(::tools::vector<T>&&)\
    \ = default;\n\n    vector(::std::size_t dim) : m_values(dim) {\n    }\n    vector(::std::size_t\
    \ dim, const T& value) : m_values(dim, value) {\n    }\n\n    T& at(const ::std::size_t\
    \ i) {\n      return this->m_values[i];\n    }\n    T at(const ::std::size_t i)\
    \ const {\n      return this->m_values[i];\n    }\n\n    ::std::size_t dim() const\
    \ {\n      return this->m_values.size();\n    }\n\n    friend ::tools::vector<T>&\
    \ operator+(::tools::vector<T>& self) {\n      return self;\n    }\n    friend\
    \ const ::tools::vector<T>& operator+(const ::tools::vector<T>& self) {\n    \
    \  return self;\n    }\n    friend ::tools::vector<T> operator+(const ::tools::vector<T>&\
    \ lhs, const ::tools::vector<T>& rhs) {\n      assert(lhs.dim() == rhs.dim());\n\
    \      ::tools::vector<T> result(lhs);\n      for (::std::size_t i = 0; i < lhs.dim();\
    \ ++i) {\n        result.m_values[i] += rhs.m_values[i];\n      }\n      return\
    \ result;\n    }\n    friend ::tools::vector<T> operator-(const ::tools::vector<T>&\
    \ self) {\n      ::tools::vector<T> result(self);\n      for (::std::size_t i\
    \ = 0; i < self.dim(); ++i) {\n        result.m_values[i] *= -1;\n      }\n  \
    \    return result;\n    }\n    friend ::tools::vector<T> operator-(const ::tools::vector<T>&\
    \ lhs, const ::tools::vector<T>& rhs) {\n      assert(lhs.dim() == rhs.dim());\n\
    \      ::tools::vector<T> result(lhs);\n      for (::std::size_t i = 0; i < lhs.dim();\
    \ ++i) {\n        result.m_values[i] -= rhs.m_values[i];\n      }\n      return\
    \ result;\n    }\n  };\n}\n\n\n#line 9 \"tools/matrix.hpp\"\n\nnamespace tools\
    \ {\n  template <typename T>\n  class matrix {\n  private:\n    ::std::vector<T>\
    \ m_values;\n    ::std::size_t m_rows;\n    ::std::size_t m_cols;\n\n  public:\n\
    \    matrix() = default;\n    matrix(const ::tools::matrix<T>&) = default;\n \
    \   matrix(::tools::matrix<T>&&) = default;\n    ~matrix() = default;\n    ::tools::matrix<T>&\
    \ operator=(const ::tools::matrix<T>&) = default;\n    ::tools::matrix<T>& operator=(::tools::matrix<T>&&)\
    \ = default;\n\n    matrix(::std::size_t rows, ::std::size_t cols) :\n      m_values(rows\
    \ * cols), m_rows(rows), m_cols(cols) {\n    }\n    matrix(::std::size_t rows,\
    \ ::std::size_t cols, const T& value) :\n      m_values(rows * cols, value), m_rows(rows),\
    \ m_cols(cols) {\n    }\n\n    T& at(const ::std::size_t y, const ::std::size_t\
    \ x) {\n      return this->m_values[y * this->m_cols + x];\n    }\n    T at(const\
    \ ::std::size_t y, const ::std::size_t x) const {\n      return this->m_values[y\
    \ * this->m_cols + x];\n    }\n\n    ::std::size_t rows() const {\n      return\
    \ this->m_rows;\n    }\n    ::std::size_t cols() const {\n      return this->m_cols;\n\
    \    }\n\n    friend ::tools::matrix<T>& operator+(::tools::matrix<T>& self) {\n\
    \      return self;\n    }\n    friend const ::tools::matrix<T>& operator+(const\
    \ ::tools::matrix<T>& self) {\n      return self;\n    }\n    friend ::tools::matrix<T>\
    \ operator+(const ::tools::matrix<T>& lhs, const ::tools::matrix<T>& rhs) {\n\
    \      assert(lhs.m_rows == rhs.m_rows);\n      assert(lhs.m_cols == rhs.m_cols);\n\
    \      ::tools::matrix<T> result(lhs);\n      for (::std::size_t i = 0; i < lhs.m_values.size();\
    \ ++i) {\n        result.m_values[i] += rhs.m_values[i];\n      }\n      return\
    \ result;\n    }\n    friend ::tools::matrix<T> operator-(const ::tools::matrix<T>&\
    \ self) {\n      ::tools::matrix<T> result(self);\n      for (::std::size_t i\
    \ = 0; i < self.m_values.size(); ++i) {\n        result.m_values[i] *= -1;\n \
    \     }\n      return result;\n    }\n    friend ::tools::matrix<T> operator-(const\
    \ ::tools::matrix<T>& lhs, const ::tools::matrix<T>& rhs) {\n      assert(lhs.m_rows\
    \ == rhs.m_rows);\n      assert(lhs.m_cols == rhs.m_cols);\n      ::tools::matrix<T>\
    \ result(lhs);\n      for (::std::size_t i = 0; i < lhs.m_values.size(); ++i)\
    \ {\n        result.m_values[i] -= rhs.m_values[i];\n      }\n      return result;\n\
    \    }\n    friend ::tools::matrix<T> operator*(const ::tools::matrix<T>& lhs,\
    \ const ::tools::matrix<T>& rhs) {\n      assert(lhs.m_cols == rhs.m_rows);\n\
    \      ::tools::matrix<T> result(lhs.m_rows, rhs.m_cols, 0);\n      for (::std::size_t\
    \ i = 0; i < lhs.m_rows; ++i) {\n        for (::std::size_t j = 0; j < rhs.m_cols;\
    \ ++j) {\n          for (::std::size_t k = 0; k < lhs.m_cols; ++k) {\n       \
    \     result.at(i, j) += lhs.at(i, k) * rhs.at(k, j);\n          }\n        }\n\
    \      }\n      return result;\n    }\n    friend ::tools::vector<T> operator*(const\
    \ ::tools::matrix<T>& lhs, const ::tools::vector<T>& rhs) {\n      assert(lhs.m_cols\
    \ == rhs.dim());\n      ::tools::vector<T> result(lhs.m_rows, 0);\n      for (::std::size_t\
    \ i = 0; i < lhs.m_rows; ++i) {\n        for (::std::size_t j = 0; j < lhs.m_cols;\
    \ ++j) {\n          result.at(i) += lhs.at(i, j) * rhs.at(j);\n        }\n   \
    \   }\n      return result;\n    }\n\n    static ::tools::matrix<T> e(const ::std::size_t\
    \ n) {\n      ::tools::matrix<T> result(n, n);\n      ::std::fill(result.m_values.begin(),\
    \ result.m_values.end(), 0);\n      for (::std::size_t i = 0; i < n; ++i) {\n\
    \        result.at(i, i) = 1;\n      }\n      return result;\n    }\n  };\n}\n\
    \n\n"
  code: "#ifndef TOOLS_MATRIX_HPP\n#define TOOLS_MATRIX_HPP\n\n#include <vector>\n\
    #include <cstddef>\n#include <cassert>\n#include <algorithm>\n#include \"tools/vector.hpp\"\
    \n\nnamespace tools {\n  template <typename T>\n  class matrix {\n  private:\n\
    \    ::std::vector<T> m_values;\n    ::std::size_t m_rows;\n    ::std::size_t\
    \ m_cols;\n\n  public:\n    matrix() = default;\n    matrix(const ::tools::matrix<T>&)\
    \ = default;\n    matrix(::tools::matrix<T>&&) = default;\n    ~matrix() = default;\n\
    \    ::tools::matrix<T>& operator=(const ::tools::matrix<T>&) = default;\n   \
    \ ::tools::matrix<T>& operator=(::tools::matrix<T>&&) = default;\n\n    matrix(::std::size_t\
    \ rows, ::std::size_t cols) :\n      m_values(rows * cols), m_rows(rows), m_cols(cols)\
    \ {\n    }\n    matrix(::std::size_t rows, ::std::size_t cols, const T& value)\
    \ :\n      m_values(rows * cols, value), m_rows(rows), m_cols(cols) {\n    }\n\
    \n    T& at(const ::std::size_t y, const ::std::size_t x) {\n      return this->m_values[y\
    \ * this->m_cols + x];\n    }\n    T at(const ::std::size_t y, const ::std::size_t\
    \ x) const {\n      return this->m_values[y * this->m_cols + x];\n    }\n\n  \
    \  ::std::size_t rows() const {\n      return this->m_rows;\n    }\n    ::std::size_t\
    \ cols() const {\n      return this->m_cols;\n    }\n\n    friend ::tools::matrix<T>&\
    \ operator+(::tools::matrix<T>& self) {\n      return self;\n    }\n    friend\
    \ const ::tools::matrix<T>& operator+(const ::tools::matrix<T>& self) {\n    \
    \  return self;\n    }\n    friend ::tools::matrix<T> operator+(const ::tools::matrix<T>&\
    \ lhs, const ::tools::matrix<T>& rhs) {\n      assert(lhs.m_rows == rhs.m_rows);\n\
    \      assert(lhs.m_cols == rhs.m_cols);\n      ::tools::matrix<T> result(lhs);\n\
    \      for (::std::size_t i = 0; i < lhs.m_values.size(); ++i) {\n        result.m_values[i]\
    \ += rhs.m_values[i];\n      }\n      return result;\n    }\n    friend ::tools::matrix<T>\
    \ operator-(const ::tools::matrix<T>& self) {\n      ::tools::matrix<T> result(self);\n\
    \      for (::std::size_t i = 0; i < self.m_values.size(); ++i) {\n        result.m_values[i]\
    \ *= -1;\n      }\n      return result;\n    }\n    friend ::tools::matrix<T>\
    \ operator-(const ::tools::matrix<T>& lhs, const ::tools::matrix<T>& rhs) {\n\
    \      assert(lhs.m_rows == rhs.m_rows);\n      assert(lhs.m_cols == rhs.m_cols);\n\
    \      ::tools::matrix<T> result(lhs);\n      for (::std::size_t i = 0; i < lhs.m_values.size();\
    \ ++i) {\n        result.m_values[i] -= rhs.m_values[i];\n      }\n      return\
    \ result;\n    }\n    friend ::tools::matrix<T> operator*(const ::tools::matrix<T>&\
    \ lhs, const ::tools::matrix<T>& rhs) {\n      assert(lhs.m_cols == rhs.m_rows);\n\
    \      ::tools::matrix<T> result(lhs.m_rows, rhs.m_cols, 0);\n      for (::std::size_t\
    \ i = 0; i < lhs.m_rows; ++i) {\n        for (::std::size_t j = 0; j < rhs.m_cols;\
    \ ++j) {\n          for (::std::size_t k = 0; k < lhs.m_cols; ++k) {\n       \
    \     result.at(i, j) += lhs.at(i, k) * rhs.at(k, j);\n          }\n        }\n\
    \      }\n      return result;\n    }\n    friend ::tools::vector<T> operator*(const\
    \ ::tools::matrix<T>& lhs, const ::tools::vector<T>& rhs) {\n      assert(lhs.m_cols\
    \ == rhs.dim());\n      ::tools::vector<T> result(lhs.m_rows, 0);\n      for (::std::size_t\
    \ i = 0; i < lhs.m_rows; ++i) {\n        for (::std::size_t j = 0; j < lhs.m_cols;\
    \ ++j) {\n          result.at(i) += lhs.at(i, j) * rhs.at(j);\n        }\n   \
    \   }\n      return result;\n    }\n\n    static ::tools::matrix<T> e(const ::std::size_t\
    \ n) {\n      ::tools::matrix<T> result(n, n);\n      ::std::fill(result.m_values.begin(),\
    \ result.m_values.end(), 0);\n      for (::std::size_t i = 0; i < n; ++i) {\n\
    \        result.at(i, i) = 1;\n      }\n      return result;\n    }\n  };\n}\n\
    \n#endif\n"
  dependsOn:
  - tools/vector.hpp
  isVerificationFile: false
  path: tools/matrix.hpp
  requiredBy: []
  timestamp: '2021-06-13 16:51:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/matrix.hpp
layout: document
redirect_from:
- /library/tools/matrix.hpp
- /library/tools/matrix.hpp.html
title: tools/matrix.hpp
---
