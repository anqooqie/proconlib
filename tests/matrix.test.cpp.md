---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/matrix.hpp
    title: tools/matrix.hpp
  - icon: ':heavy_check_mark:'
    path: tools/vector.hpp
    title: tools/vector.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_7_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_7_D
  bundledCode: "#line 1 \"tests/matrix.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_7_D\"\
    \n\n#include <cstdint>\n#include <iostream>\n#line 1 \"tools/matrix.hpp\"\n\n\n\
    \n#include <vector>\n#include <cstddef>\n#include <cassert>\n#line 8 \"tools/matrix.hpp\"\
    \n#include <string>\n#line 1 \"tools/vector.hpp\"\n\n\n\n#line 6 \"tools/vector.hpp\"\
    \n#include <type_traits>\n#include <cmath>\n#line 11 \"tools/vector.hpp\"\n\n\
    namespace tools {\n  template <typename T>\n  class vector {\n  private:\n   \
    \ ::std::vector<T> m_values;\n\n  public:\n    vector() = default;\n    vector(const\
    \ ::tools::vector<T>&) = default;\n    vector(::tools::vector<T>&&) = default;\n\
    \    ~vector() = default;\n    ::tools::vector<T>& operator=(const ::tools::vector<T>&)\
    \ = default;\n    ::tools::vector<T>& operator=(::tools::vector<T>&&) = default;\n\
    \n    vector(::std::size_t dim) : m_values(dim) {\n    }\n    vector(::std::size_t\
    \ dim, const T& value) : m_values(dim, value) {\n    }\n\n    T& operator[](const\
    \ ::std::size_t i) {\n      return this->m_values[i];\n    }\n    T operator[](const\
    \ ::std::size_t i) const {\n      return this->m_values[i];\n    }\n\n    ::std::size_t\
    \ dim() const {\n      return this->m_values.size();\n    }\n\n    double norm()\
    \ const {\n      return ::std::sqrt(static_cast<double>(this->squared_norm()));\n\
    \    }\n    T squared_norm() const {\n      return this->inner_product(*this);\n\
    \    }\n    template <typename SFINAE_T = T, typename ::std::enable_if<::std::is_same<SFINAE_T,\
    \ double>::value, ::std::nullptr_t>::type = nullptr>\n    ::tools::vector<double>\
    \ normalized() const {\n      return *this / this->norm();\n    }\n\n    T inner_product(const\
    \ ::tools::vector<T>& other) const {\n      assert(this->dim() == other.dim());\n\
    \      T result(0);\n      for (::std::size_t i = 0; i < this->dim(); ++i) {\n\
    \        result += this->m_values[i] * other.m_values[i];\n      }\n      return\
    \ result;\n    }\n\n    friend ::tools::vector<T>& operator+(::tools::vector<T>&\
    \ self) {\n      return self;\n    }\n    friend const ::tools::vector<T>& operator+(const\
    \ ::tools::vector<T>& self) {\n      return self;\n    }\n    friend ::tools::vector<T>\
    \ operator+(const ::tools::vector<T>& lhs, const ::tools::vector<T>& rhs) {\n\
    \      return ::tools::vector<T>(lhs) += rhs;\n    }\n    friend ::tools::vector<T>\
    \ operator-(const ::tools::vector<T>& self) {\n      return ::tools::vector<T>(self)\
    \ *= T(-1);\n    }\n    friend ::tools::vector<T> operator-(const ::tools::vector<T>&\
    \ lhs, const ::tools::vector<T>& rhs) {\n      return ::tools::vector<T>(lhs)\
    \ -= rhs;\n    }\n    friend ::tools::vector<T> operator*(const ::tools::vector<T>&\
    \ lhs, const T& rhs) {\n      return ::tools::vector<T>(lhs) *= rhs;\n    }\n\
    \    friend ::tools::vector<T> operator*(const T& lhs, const ::tools::vector<T>&\
    \ rhs) {\n      return ::tools::vector<T>(rhs) *= lhs;\n    }\n    friend ::tools::vector<T>\
    \ operator/(const ::tools::vector<T>& lhs, const T& rhs) {\n      return ::tools::vector<T>(lhs)\
    \ /= rhs;\n    }\n    ::tools::vector<T>& operator+=(const ::tools::vector<T>&\
    \ other) {\n      assert(this->dim() == other.dim());\n      for (::std::size_t\
    \ i = 0; i < this->dim(); ++i) {\n        this->m_values[i] += other.m_values[i];\n\
    \      }\n      return *this;\n    }\n    ::tools::vector<T>& operator-=(const\
    \ ::tools::vector<T>& other) {\n      assert(this->dim() == other.dim());\n  \
    \    for (::std::size_t i = 0; i < this->dim(); ++i) {\n        this->m_values[i]\
    \ -= other.m_values[i];\n      }\n      return *this;\n    }\n    ::tools::vector<T>&\
    \ operator*=(const T& c) {\n      for (::std::size_t i = 0; i < this->dim(); ++i)\
    \ {\n        this->m_values[i] *= c;\n      }\n      return *this;\n    }\n  \
    \  ::tools::vector<T>& operator/=(const T& c) {\n      const T c_inv = T(1) /\
    \ c;\n      for (::std::size_t i = 0; i < this->dim(); ++i) {\n        this->m_values[i]\
    \ *= c_inv;\n      }\n      return *this;\n    }\n    friend bool operator==(const\
    \ ::tools::vector<T>& lhs, const ::tools::vector<T>& rhs) {\n      if (lhs.dim()\
    \ != rhs.dim()) {\n        return false;\n      }\n      for (::std::size_t i\
    \ = 0; i < lhs.dim(); ++i) {\n        if (lhs.m_values[i] != rhs.m_values[i])\
    \ {\n          return false;\n        }\n      }\n      return true;\n    }\n\
    \    friend bool operator!=(const ::tools::vector<T>& lhs, const ::tools::vector<T>&\
    \ rhs) {\n      return !(lhs == rhs);\n    }\n\n    friend ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::tools::vector<T>& self) {\n      os << '(';\n      ::std::string\
    \ delimiter = \"\";\n      for (const T& value : self.m_values) {\n        os\
    \ << delimiter << value;\n        delimiter = \", \";\n      }\n      return os\
    \ << ')';\n    }\n    friend ::std::istream& operator>>(::std::istream& is, ::tools::vector<T>&\
    \ self) {\n      for (T& value : self.m_values) {\n        is >> value;\n    \
    \  }\n      return is;\n    }\n  };\n}\n\n\n#line 11 \"tools/matrix.hpp\"\n\n\
    namespace tools {\n  template <typename T>\n  class matrix {\n  private:\n   \
    \ ::std::vector<T> m_values;\n    ::std::size_t m_rows;\n    ::std::size_t m_cols;\n\
    \n  public:\n    matrix() = default;\n    matrix(const ::tools::matrix<T>&) =\
    \ default;\n    matrix(::tools::matrix<T>&&) = default;\n    ~matrix() = default;\n\
    \    ::tools::matrix<T>& operator=(const ::tools::matrix<T>&) = default;\n   \
    \ ::tools::matrix<T>& operator=(::tools::matrix<T>&&) = default;\n\n    matrix(::std::size_t\
    \ rows, ::std::size_t cols) :\n      m_values(rows * cols), m_rows(rows), m_cols(cols)\
    \ {\n    }\n    matrix(::std::size_t rows, ::std::size_t cols, const T& value)\
    \ :\n      m_values(rows * cols, value), m_rows(rows), m_cols(cols) {\n    }\n\
    \n    typename ::std::vector<T>::iterator operator[](const ::std::size_t r) {\n\
    \      return this->m_values.begin() + r * this->m_cols;\n    }\n    typename\
    \ ::std::vector<T>::const_iterator operator[](const ::std::size_t r) const {\n\
    \      return this->m_values.begin() + r * this->m_cols;\n    }\n\n    ::std::size_t\
    \ rows() const {\n      return this->m_rows;\n    }\n    ::std::size_t cols()\
    \ const {\n      return this->m_cols;\n    }\n\n    friend ::tools::matrix<T>&\
    \ operator+(::tools::matrix<T>& self) {\n      return self;\n    }\n    friend\
    \ const ::tools::matrix<T>& operator+(const ::tools::matrix<T>& self) {\n    \
    \  return self;\n    }\n    friend ::tools::matrix<T> operator+(const ::tools::matrix<T>&\
    \ lhs, const ::tools::matrix<T>& rhs) {\n      return ::tools::matrix<T>(lhs)\
    \ += rhs;\n    }\n    friend ::tools::matrix<T> operator-(const ::tools::matrix<T>&\
    \ self) {\n      return ::tools::matrix<T>(self) *= T(-1);\n    }\n    friend\
    \ ::tools::matrix<T> operator-(const ::tools::matrix<T>& lhs, const ::tools::matrix<T>&\
    \ rhs) {\n      return ::tools::matrix<T>(lhs) - rhs;\n    }\n    friend ::tools::matrix<T>\
    \ operator*(const ::tools::matrix<T>& lhs, const ::tools::matrix<T>& rhs) {\n\
    \      assert(lhs.m_cols == rhs.m_rows);\n      ::tools::matrix<T> result(lhs.m_rows,\
    \ rhs.m_cols, T(0));\n      for (::std::size_t i = 0; i < lhs.m_rows; ++i) {\n\
    \        for (::std::size_t k = 0; k < lhs.m_cols; ++k) {\n          for (::std::size_t\
    \ j = 0; j < rhs.m_cols; ++j) {\n            result[i][j] += lhs[i][k] * rhs[k][j];\n\
    \          }\n        }\n      }\n      return result;\n    }\n    friend ::tools::vector<T>\
    \ operator*(const ::tools::matrix<T>& lhs, const ::tools::vector<T>& rhs) {\n\
    \      assert(lhs.m_cols == rhs.dim());\n      ::tools::vector<T> result(lhs.m_rows,\
    \ T(0));\n      for (::std::size_t i = 0; i < lhs.m_rows; ++i) {\n        for\
    \ (::std::size_t j = 0; j < lhs.m_cols; ++j) {\n          result[i] += lhs[i][j]\
    \ * rhs[j];\n        }\n      }\n      return result;\n    }\n    friend ::tools::matrix<T>\
    \ operator*(const ::tools::matrix<T>& lhs, const T& rhs) {\n      return ::tools::matrix<T>(lhs)\
    \ * rhs;\n    }\n    friend ::tools::matrix<T> operator/(const ::tools::matrix<T>&\
    \ lhs, const T& rhs) {\n      return ::tools::matrix<T>(lhs) / rhs;\n    }\n \
    \   ::tools::matrix<T> operator+=(const ::tools::matrix<T>& other) {\n      assert(this->m_rows\
    \ == other.m_rows);\n      assert(this->m_cols == other.m_cols);\n      for (::std::size_t\
    \ i = 0; i < this->m_values.size(); ++i) {\n        this->m_values[i] += other.m_values[i];\n\
    \      }\n      return *this;\n    }\n    ::tools::matrix<T> operator-=(const\
    \ ::tools::matrix<T>& other) {\n      assert(this->m_rows == other.m_rows);\n\
    \      assert(this->m_cols == other.m_cols);\n      for (::std::size_t i = 0;\
    \ i < this->m_values.size(); ++i) {\n        this->m_values[i] -= other.m_values[i];\n\
    \      }\n      return *this;\n    }\n    ::tools::matrix<T> operator*=(const\
    \ ::tools::matrix<T>& other) {\n      return *this = *this * other;\n    }\n \
    \   ::tools::matrix<T> operator*=(const T& c) {\n      for (::std::size_t i =\
    \ 0; i < this->m_values.size(); ++i) {\n        this->m_values[i] *= c;\n    \
    \  }\n      return *this;\n    }\n    ::tools::matrix<T> operator/=(const T& c)\
    \ {\n      const T c_inv = T(1) / c;\n      for (::std::size_t i = 0; i < this->m_values.size();\
    \ ++i) {\n        this->m_values[i] *= c_inv;\n      }\n      return *this;\n\
    \    }\n\n    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::matrix<T>&\
    \ self) {\n      for (::std::size_t r = 0; r < self.m_rows; ++r) {\n        os\
    \ << '[';\n        ::std::string delimiter = \"\";\n        for (::std::size_t\
    \ c = 0; c < self.m_cols; ++c) {\n          os << delimiter << self[r][c];\n \
    \         delimiter = \", \";\n        }\n        os << ']' << '\\n';\n      }\n\
    \      return os;\n    }\n    friend ::std::istream& operator>>(::std::istream&\
    \ is, ::tools::matrix<T>& self) {\n      for (T& value : self.m_values) {\n  \
    \      is >> value;\n      }\n      return is;\n    }\n\n    ::std::int_fast64_t\
    \ gauss_jordan() {\n      ::std::size_t rank = 0;\n      for (::std::size_t c\
    \ = 0; c < this->m_cols; ++c) {\n        ::std::size_t pivot;\n        for (pivot\
    \ = rank; pivot < this->m_rows && (*this)[pivot][c] == T(0); ++pivot);\n     \
    \   if (pivot == this->m_rows) continue;\n\n        if (pivot != rank) {\n   \
    \       for (::std::size_t cc = c; cc < this->m_cols; ++cc) {\n            ::std::swap((*this)[rank][cc],\
    \ (*this)[pivot][cc]);\n          }\n        }\n\n        {\n          const T\
    \ scale_inv = T(1) / (*this)[rank][c];\n          for (::std::size_t cc = c; cc\
    \ < this->m_cols; ++cc) {\n            (*this)[rank][cc] *= scale_inv;\n     \
    \     }\n        }\n\n        for (::std::size_t r = rank + 1; r < this->m_rows;\
    \ ++r) {\n          const T scale = (*this)[r][c];\n          for (::std::size_t\
    \ cc = c; cc < this->m_cols; ++cc) {\n            (*this)[r][cc] -= (*this)[rank][cc]\
    \ * scale;\n          }\n        }\n\n        ++rank;\n      }\n      return rank;\n\
    \    }\n\n    ::tools::matrix<T> solve(const ::tools::vector<T>& b) const {\n\
    \      assert(this->m_rows == b.dim());\n      assert(this->m_cols >= 1);\n  \
    \    ::tools::matrix<T> Ab(this->m_rows, this->m_cols + 1);\n      for (::std::size_t\
    \ r = 0; r < this->m_rows; ++r) {\n        for (::std::size_t c = 0; c < this->m_cols;\
    \ ++c) {\n          Ab[r][c] = (*this)[r][c];\n        }\n        Ab[r][this->m_cols]\
    \ = b[r];\n      }\n\n      Ab.gauss_jordan();\n\n      ::std::vector<::std::size_t>\
    \ ranks(Ab.cols());\n      for (::std::size_t r = 0, cl = 0, cr = 0; r <= Ab.rows();\
    \ ++r, cl = cr) {\n        for (; cr < Ab.cols() && (r == Ab.rows() || Ab[r][cr]\
    \ == T(0)); ++cr);\n        for (::std::size_t c = cl; c < cr; ++c) {\n      \
    \    ranks[c] = r;\n        }\n      }\n\n      if (ranks[Ab.cols() - 2] < ranks[Ab.cols()\
    \ - 1]) {\n        return ::tools::matrix<T>(this->m_rows, 0);\n      }\n\n  \
    \    ::std::vector<::tools::vector<T>> answers(this->m_cols);\n      ::std::size_t\
    \ free = this->m_cols - ranks.back() - 1;\n\n      for (::std::size_t l = this->m_cols,\
    \ r = this->m_cols; r > 0; r = l) {\n        for (; l > 0 && ranks[l - 1] == ranks[r\
    \ - 1]; --l);\n        for (::std::size_t c = r - 1; c > l; --c) {\n         \
    \ answers[c] = tools::vector<T>(this->m_cols - ranks.back() + 1, T(0));\n    \
    \      answers[c][free] = T(1);\n          --free;\n        }\n        if (ranks[l]\
    \ > 0) {\n          answers[l] = ::tools::vector<T>(this->m_cols - ranks.back()\
    \ + 1, T(0));\n          answers[l][this->m_cols - ranks.back()] = Ab[ranks[l]\
    \ - 1][Ab.cols() - 1];\n          for (::std::size_t c = l + 1; c < Ab.cols()\
    \ - 1; ++c) {\n            answers[l] -= Ab[ranks[l] - 1][c] * answers[c];\n \
    \         }\n        } else {\n          answers[l] = ::tools::vector<T>(this->m_cols\
    \ - ranks.back() + 1, T(0));\n          answers[l][free] = T(1);\n          --free;\n\
    \        }\n      }\n\n      ::tools::matrix<T> answer(this->m_cols, this->m_cols\
    \ - ranks.back() + 1);\n      for (::std::size_t r = 0; r < this->m_cols; ++r)\
    \ {\n        for (::std::size_t c = 0; c < this->m_cols - ranks.back() + 1; ++c)\
    \ {\n          answer[r][c] = answers[r][c];\n        }\n      }\n\n      return\
    \ answer;\n    }\n\n    static ::tools::matrix<T> e(const ::std::size_t n) {\n\
    \      ::tools::matrix<T> result(n, n, T(0));\n      for (::std::size_t i = 0;\
    \ i < n; ++i) {\n        result[i][i] = 1;\n      }\n      return result;\n  \
    \  }\n  };\n}\n\n\n#line 6 \"tests/matrix.test.cpp\"\n\nusing i64 = std::int_fast64_t;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  i64 n, m, l;\n  std::cin >> n >> m >> l;\n\n  tools::matrix<i64> A(n, m),\
    \ B(m, l);\n  std::cin >> A >> B;\n\n  const tools::matrix<i64> C = A * B;\n \
    \ for (i64 r = 0; r < n; ++r) {\n    std::string delimiter = \"\";\n    for (i64\
    \ c = 0; c < l; ++c) {\n      std::cout << delimiter << C[r][c];\n      delimiter\
    \ = \" \";\n    }\n    std::cout << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_7_D\"\n\n\
    #include <cstdint>\n#include <iostream>\n#include \"tools/matrix.hpp\"\n\nusing\
    \ i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  i64 n, m, l;\n  std::cin >> n >> m >> l;\n\n  tools::matrix<i64> A(n, m),\
    \ B(m, l);\n  std::cin >> A >> B;\n\n  const tools::matrix<i64> C = A * B;\n \
    \ for (i64 r = 0; r < n; ++r) {\n    std::string delimiter = \"\";\n    for (i64\
    \ c = 0; c < l; ++c) {\n      std::cout << delimiter << C[r][c];\n      delimiter\
    \ = \" \";\n    }\n    std::cout << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/matrix.hpp
  - tools/vector.hpp
  isVerificationFile: true
  path: tests/matrix.test.cpp
  requiredBy: []
  timestamp: '2021-10-26 00:02:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/matrix.test.cpp
layout: document
redirect_from:
- /verify/tests/matrix.test.cpp
- /verify/tests/matrix.test.cpp.html
title: tests/matrix.test.cpp
---
