---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/abs.hpp
    title: std::abs(x) extended for my library
  - icon: ':question:'
    path: tools/detail/vector_common.hpp
    title: tools/detail/vector_common.hpp
  - icon: ':x:'
    path: tools/vector.hpp
    title: Vector
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/matrix/determinant.test.cpp
    title: tests/matrix/determinant.test.cpp
  - icon: ':x:'
    path: tests/matrix/inv.test.cpp
    title: tests/matrix/inv.test.cpp
  - icon: ':x:'
    path: tests/matrix/multiplies.test.cpp
    title: tests/matrix/multiplies.test.cpp
  - icon: ':x:'
    path: tests/matrix/solve.test.cpp
    title: tests/matrix/solve.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/matrix.hpp\"\n\n\n\n#include <vector>\n#include <cstddef>\n\
    #include <cassert>\n#include <iostream>\n#include <string>\n#include <optional>\n\
    #line 1 \"tools/vector.hpp\"\n\n\n\n#line 6 \"tools/vector.hpp\"\n#include <initializer_list>\n\
    #line 1 \"tools/detail/vector_common.hpp\"\n\n\n\n#include <type_traits>\n#line\
    \ 7 \"tools/detail/vector_common.hpp\"\n#include <algorithm>\n#include <cmath>\n\
    #line 1 \"tools/abs.hpp\"\n\n\n\nnamespace tools {\n  constexpr float abs(const\
    \ float x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr double abs(const double\
    \ x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long double abs(const long\
    \ double x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr int abs(const int\
    \ x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long abs(const long x) {\n\
    \    return x < 0 ? -x : x;\n  }\n  constexpr long long abs(const long long x)\
    \ {\n    return x < 0 ? -x : x;\n  }\n}\n\n\n#line 12 \"tools/detail/vector_common.hpp\"\
    \n\n#define TOOLS_DETAIL_VECTOR_COMMON(V) \\\n  private:\\\n    using F = ::std::conditional_t<::std::is_floating_point_v<T>,\
    \ T, double>;\\\n\\\n  public:\\\n    V operator+() const {\\\n      return *this;\\\
    \n    }\\\n\\\n    V operator-() const {\\\n      V res = *this;\\\n      for\
    \ (auto& v : res) {\\\n        v = -v;\\\n      }\\\n      return res;\\\n   \
    \ }\\\n\\\n    V& operator+=(const V& other) {\\\n      assert(this->size() ==\
    \ other.size());\\\n      for (::std::size_t i = 0; i < this->size(); ++i) {\\\
    \n        (*this)[i] += other[i];\\\n      }\\\n      return *this;\\\n    }\\\
    \n    friend V operator+(const V& lhs, const V& rhs) {\\\n      return V(lhs)\
    \ += rhs;\\\n    }\\\n\\\n    V& operator-=(const V& other) {\\\n      assert(this->size()\
    \ == other.size());\\\n      for (::std::size_t i = 0; i < this->size(); ++i)\
    \ {\\\n        (*this)[i] -= other[i];\\\n      }\\\n      return *this;\\\n \
    \   }\\\n    friend V operator-(const V& lhs, const V& rhs) {\\\n      return\
    \ V(lhs) -= rhs;\\\n    }\\\n\\\n    V& operator*=(const T& c) {\\\n      for\
    \ (auto& v : *this) {\\\n        v *= c;\\\n      }\\\n      return *this;\\\n\
    \    }\\\n    friend V operator*(const T& lhs, const V& rhs) {\\\n      return\
    \ V(rhs) *= lhs;\\\n    }\\\n    friend V operator*(const V& lhs, const T& rhs)\
    \ {\\\n      return V(lhs) *= rhs;\\\n    }\\\n\\\n    V& operator/=(const T&\
    \ c) {\\\n      for (auto& v : *this) {\\\n        v /= c;\\\n      }\\\n    \
    \  return *this;\\\n    }\\\n    friend V operator/(const V& lhs, const T& rhs)\
    \ {\\\n      return V(lhs) /= rhs;\\\n    }\\\n\\\n    friend bool operator==(const\
    \ V& lhs, const V& rhs) {\\\n      return ::std::equal(lhs.begin(), lhs.end(),\
    \ rhs.begin());\\\n    }\\\n    friend bool operator!=(const V& lhs, const V&\
    \ rhs) {\\\n      return !(lhs == rhs);\\\n    }\\\n\\\n    T inner_product(const\
    \ V& other) const {\\\n      assert(this->size() == other.size());\\\n      T\
    \ res(0);\\\n      for (::std::size_t i = 0; i < this->size(); ++i) {\\\n    \
    \    res += (*this)[i] * other[i];\\\n      }\\\n      return res;\\\n    }\\\n\
    \\\n    T l1_norm() const {\\\n      T res(0);\\\n      for (const auto& v : *this)\
    \ {\\\n        res += ::tools::abs(v);\\\n      }\\\n      return res;\\\n   \
    \ }\\\n\\\n    T squared_l2_norm() const {\\\n      return this->inner_product(*this);\\\
    \n    }\\\n\\\n    F l2_norm() const {\\\n      return ::std::sqrt(static_cast<F>(this->squared_l2_norm()));\\\
    \n    }\\\n\\\n    template <typename T_ = T>\\\n    ::std::enable_if_t<::std::is_floating_point_v<T_>,\
    \ V> normalized() const {\\\n      return *this / this->l2_norm();\\\n    }\\\n\
    \\\n    friend ::std::ostream& operator<<(::std::ostream& os, const V& self) {\\\
    \n      os << '(';\\\n      ::std::string delimiter = \"\";\\\n      for (const\
    \ auto& v : self) {\\\n        os << delimiter << v;\\\n        delimiter = \"\
    , \";\\\n      }\\\n      return os << ')';\\\n    }\\\n\\\n    friend ::std::istream&\
    \ operator>>(::std::istream& is, V& self) {\\\n      for (auto& v : self) {\\\n\
    \        is >> v;\\\n      }\\\n      return is;\\\n    }\n\n\n#line 8 \"tools/vector.hpp\"\
    \n\nnamespace tools {\n  template <typename T>\n  class vector {\n  private:\n\
    \    ::std::vector<T> m_values;\n\n  public:\n    using reference = T&;\n    using\
    \ const_reference = const T&;\n    using size_type = ::std::size_t;\n    using\
    \ difference_type = ::std::ptrdiff_t;\n    using pointer = T*;\n    using const_pointer\
    \ = const T*;\n    using value_type = T;\n    using iterator = typename ::std::vector<T>::iterator;\n\
    \    using const_iterator = typename ::std::vector<T>::const_iterator;\n    using\
    \ reverse_iterator = typename ::std::vector<T>::reverse_iterator;\n    using const_reverse_iterator\
    \ = typename ::std::vector<T>::const_reverse_iterator;\n\n    vector() = default;\n\
    \    vector(const ::tools::vector<T>&) = default;\n    vector(::tools::vector<T>&&)\
    \ = default;\n    ~vector() = default;\n    ::tools::vector<T>& operator=(const\
    \ ::tools::vector<T>&) = default;\n    ::tools::vector<T>& operator=(::tools::vector<T>&&)\
    \ = default;\n\n    explicit vector(size_type n) : m_values(n) {}\n    vector(size_type\
    \ n, const_reference value) : m_values(n, value) {}\n    template <typename InputIter>\
    \ vector(const InputIter first, const InputIter last) : m_values(first, last)\
    \ {}\n    vector(const ::std::initializer_list<T> il) : m_values(il) {}\n\n  \
    \  iterator begin() { return this->m_values.begin(); }\n    const_iterator begin()\
    \ const { return this->m_values.begin(); }\n    iterator end() { return this->m_values.end();\
    \ }\n    const_iterator end() const { return this->m_values.end(); }\n    const_iterator\
    \ cbegin() const { return this->m_values.cbegin(); }\n    const_iterator cend()\
    \ const { return this->m_values.cend(); }\n    reverse_iterator rbegin() { return\
    \ this->m_values.rbegin(); }\n    const_reverse_iterator rbegin() const { return\
    \ this->m_values.rbegin(); }\n    const_reverse_iterator crbegin() const { return\
    \ this->m_values.crbegin(); }\n    reverse_iterator rend() { return this->m_values.rend();\
    \ }\n    const_reverse_iterator rend() const { return this->m_values.rend(); }\n\
    \    const_reverse_iterator crend() const { return this->m_values.crend(); }\n\
    \n    size_type size() const { return this->m_values.size(); }\n    bool empty()\
    \ const { return this->m_values.empty(); }\n\n    reference operator[](const size_type\
    \ n) { return this->m_values[n]; }\n    const_reference operator[](const size_type\
    \ n) const { return this->m_values[n]; }\n    reference front() { return *this->begin();\
    \ }\n    const_reference front() const { return *this->begin(); }\n    reference\
    \ back() { return *this->rbegin(); }\n    const_reference back() const { return\
    \ *this->rbegin(); }\n\n    void swap(::tools::vector<T>& other) { this->m_values.swap(other.m_values);\
    \ }\n\n    TOOLS_DETAIL_VECTOR_COMMON(::tools::vector<T>)\n  };\n}\n\n\n#line\
    \ 11 \"tools/matrix.hpp\"\n\nnamespace tools {\n  template <typename T>\n  class\
    \ matrix {\n  private:\n    ::std::vector<T> m_values;\n    ::std::size_t m_rows;\n\
    \    ::std::size_t m_cols;\n\n  public:\n    matrix() = default;\n    matrix(const\
    \ ::tools::matrix<T>&) = default;\n    matrix(::tools::matrix<T>&&) = default;\n\
    \    ~matrix() = default;\n    ::tools::matrix<T>& operator=(const ::tools::matrix<T>&)\
    \ = default;\n    ::tools::matrix<T>& operator=(::tools::matrix<T>&&) = default;\n\
    \n    matrix(::std::size_t rows, ::std::size_t cols) :\n      m_values(rows *\
    \ cols), m_rows(rows), m_cols(cols) {\n    }\n    matrix(::std::size_t rows, ::std::size_t\
    \ cols, const T& value) :\n      m_values(rows * cols, value), m_rows(rows), m_cols(cols)\
    \ {\n    }\n\n    typename ::std::vector<T>::iterator operator[](const ::std::size_t\
    \ r) {\n      return this->m_values.begin() + r * this->m_cols;\n    }\n    typename\
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
    \ rhs) {\n      return ::tools::matrix<T>(lhs) -= rhs;\n    }\n    friend ::tools::matrix<T>\
    \ operator*(const ::tools::matrix<T>& lhs, const ::tools::matrix<T>& rhs) {\n\
    \      assert(lhs.m_cols == rhs.m_rows);\n      ::tools::matrix<T> result(lhs.m_rows,\
    \ rhs.m_cols, T(0));\n      for (::std::size_t i = 0; i < lhs.m_rows; ++i) {\n\
    \        for (::std::size_t k = 0; k < lhs.m_cols; ++k) {\n          for (::std::size_t\
    \ j = 0; j < rhs.m_cols; ++j) {\n            result[i][j] += lhs[i][k] * rhs[k][j];\n\
    \          }\n        }\n      }\n      return result;\n    }\n    friend ::tools::vector<T>\
    \ operator*(const ::tools::matrix<T>& lhs, const ::tools::vector<T>& rhs) {\n\
    \      assert(lhs.m_cols == rhs.size());\n      ::tools::vector<T> result(lhs.m_rows,\
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
    \    }\n    friend bool operator==(const ::tools::matrix<T>& lhs, const ::tools::matrix<T>&\
    \ rhs) {\n      return lhs.m_cols == rhs.m_cols && lhs.m_rows == rhs.m_rows &&\
    \ lhs.m_values == rhs.m_values;\n    }\n    friend bool operator!=(const ::tools::matrix<T>&\
    \ lhs, const ::tools::matrix<T>& rhs) {\n      return !(lhs == rhs);\n    }\n\n\
    \    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::matrix<T>&\
    \ self) {\n      for (::std::size_t r = 0; r < self.m_rows; ++r) {\n        os\
    \ << '[';\n        ::std::string delimiter = \"\";\n        for (::std::size_t\
    \ c = 0; c < self.m_cols; ++c) {\n          os << delimiter << self[r][c];\n \
    \         delimiter = \", \";\n        }\n        os << ']' << '\\n';\n      }\n\
    \      return os;\n    }\n    friend ::std::istream& operator>>(::std::istream&\
    \ is, ::tools::matrix<T>& self) {\n      for (T& value : self.m_values) {\n  \
    \      is >> value;\n      }\n      return is;\n    }\n\n  private:\n    ::std::pair<::std::size_t,\
    \ T> internal_gauss_jordan() {\n      ::std::size_t rank = 0;\n      T coeff(1);\n\
    \n      for (::std::size_t c = 0; c < this->m_cols; ++c) {\n        ::std::size_t\
    \ pivot;\n        for (pivot = rank; pivot < this->m_rows && (*this)[pivot][c]\
    \ == T(0); ++pivot);\n        if (pivot == this->m_rows) continue;\n\n       \
    \ if (pivot != rank) {\n          for (::std::size_t cc = c; cc < this->m_cols;\
    \ ++cc) {\n            ::std::swap((*this)[rank][cc], (*this)[pivot][cc]);\n \
    \         }\n          coeff *= T(-1);\n        }\n\n        {\n          const\
    \ T scale_inv = T(1) / (*this)[rank][c];\n          for (::std::size_t cc = c;\
    \ cc < this->m_cols; ++cc) {\n            (*this)[rank][cc] *= scale_inv;\n  \
    \        }\n          coeff *= scale_inv;\n        }\n\n        for (::std::size_t\
    \ r = 0; r < this->m_rows; ++r) {\n          if (r == rank) continue;\n      \
    \    const T scale = (*this)[r][c];\n          if (scale == T(0)) continue;\n\
    \          for (::std::size_t cc = c; cc < this->m_cols; ++cc) {\n           \
    \ (*this)[r][cc] -= (*this)[rank][cc] * scale;\n          }\n        }\n\n   \
    \     ++rank;\n      }\n\n      return ::std::make_pair(rank, coeff);\n    }\n\
    \n  public:\n    ::std::size_t gauss_jordan() {\n      return this->internal_gauss_jordan().first;\n\
    \    }\n\n    ::tools::matrix<T> solve(const ::tools::vector<T>& b) const {\n\
    \      assert(this->m_rows == b.size());\n      assert(this->m_cols >= 1);\n \
    \     ::tools::matrix<T> Ab(this->m_rows, this->m_cols + 1);\n      for (::std::size_t\
    \ r = 0; r < this->m_rows; ++r) {\n        for (::std::size_t c = 0; c < this->m_cols;\
    \ ++c) {\n          Ab[r][c] = (*this)[r][c];\n        }\n        Ab[r][this->m_cols]\
    \ = b[r];\n      }\n\n      Ab.internal_gauss_jordan();\n\n      ::std::vector<::std::size_t>\
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
    \ answer;\n    }\n\n    T determinant() const {\n      assert(this->m_rows ==\
    \ this->m_cols);\n\n      ::tools::matrix<T> A = *this;\n      const auto [rank,\
    \ coeff] = A.internal_gauss_jordan();\n\n      return rank == A.m_rows ? T(1)\
    \ / coeff : T(0);\n    }\n\n    static ::tools::matrix<T> e(const ::std::size_t\
    \ n) {\n      ::tools::matrix<T> result(n, n, T(0));\n      for (::std::size_t\
    \ i = 0; i < n; ++i) {\n        result[i][i] = T(1);\n      }\n      return result;\n\
    \    }\n\n    ::std::optional<::tools::matrix<T>> inv() const {\n      if (this->m_rows\
    \ != this->m_cols) return ::std::nullopt;\n\n      ::tools::matrix<T> AI(this->m_rows,\
    \ this->m_cols * 2);\n      for (::std::size_t r = 0; r < this->m_rows; ++r) {\n\
    \        for (::std::size_t c = 0; c < this->m_cols; ++c) {\n          AI[r][c]\
    \ = (*this)[r][c];\n        }\n        for (::std::size_t c = this->m_cols; c\
    \ < AI.m_cols; ++c) {\n          AI[r][c] = T(0);\n        }\n        AI[r][this->m_cols\
    \ + r] = T(1);\n      }\n\n      AI.internal_gauss_jordan();\n      for (::std::size_t\
    \ i = 0; i < this->m_rows; ++i) {\n        if (AI[i][i] != T(1)) return ::std::nullopt;\n\
    \      }\n\n      ::tools::matrix<T> B(this->m_rows, this->m_cols);\n      for\
    \ (::std::size_t r = 0; r < this->m_rows; ++r) {\n        for (::std::size_t c\
    \ = 0; c < this->m_cols; ++c) {\n          B[r][c] = AI[r][this->m_cols + c];\n\
    \        }\n      }\n      return B;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_MATRIX_HPP\n#define TOOLS_MATRIX_HPP\n\n#include <vector>\n\
    #include <cstddef>\n#include <cassert>\n#include <iostream>\n#include <string>\n\
    #include <optional>\n#include \"tools/vector.hpp\"\n\nnamespace tools {\n  template\
    \ <typename T>\n  class matrix {\n  private:\n    ::std::vector<T> m_values;\n\
    \    ::std::size_t m_rows;\n    ::std::size_t m_cols;\n\n  public:\n    matrix()\
    \ = default;\n    matrix(const ::tools::matrix<T>&) = default;\n    matrix(::tools::matrix<T>&&)\
    \ = default;\n    ~matrix() = default;\n    ::tools::matrix<T>& operator=(const\
    \ ::tools::matrix<T>&) = default;\n    ::tools::matrix<T>& operator=(::tools::matrix<T>&&)\
    \ = default;\n\n    matrix(::std::size_t rows, ::std::size_t cols) :\n      m_values(rows\
    \ * cols), m_rows(rows), m_cols(cols) {\n    }\n    matrix(::std::size_t rows,\
    \ ::std::size_t cols, const T& value) :\n      m_values(rows * cols, value), m_rows(rows),\
    \ m_cols(cols) {\n    }\n\n    typename ::std::vector<T>::iterator operator[](const\
    \ ::std::size_t r) {\n      return this->m_values.begin() + r * this->m_cols;\n\
    \    }\n    typename ::std::vector<T>::const_iterator operator[](const ::std::size_t\
    \ r) const {\n      return this->m_values.begin() + r * this->m_cols;\n    }\n\
    \n    ::std::size_t rows() const {\n      return this->m_rows;\n    }\n    ::std::size_t\
    \ cols() const {\n      return this->m_cols;\n    }\n\n    friend ::tools::matrix<T>&\
    \ operator+(::tools::matrix<T>& self) {\n      return self;\n    }\n    friend\
    \ const ::tools::matrix<T>& operator+(const ::tools::matrix<T>& self) {\n    \
    \  return self;\n    }\n    friend ::tools::matrix<T> operator+(const ::tools::matrix<T>&\
    \ lhs, const ::tools::matrix<T>& rhs) {\n      return ::tools::matrix<T>(lhs)\
    \ += rhs;\n    }\n    friend ::tools::matrix<T> operator-(const ::tools::matrix<T>&\
    \ self) {\n      return ::tools::matrix<T>(self) *= T(-1);\n    }\n    friend\
    \ ::tools::matrix<T> operator-(const ::tools::matrix<T>& lhs, const ::tools::matrix<T>&\
    \ rhs) {\n      return ::tools::matrix<T>(lhs) -= rhs;\n    }\n    friend ::tools::matrix<T>\
    \ operator*(const ::tools::matrix<T>& lhs, const ::tools::matrix<T>& rhs) {\n\
    \      assert(lhs.m_cols == rhs.m_rows);\n      ::tools::matrix<T> result(lhs.m_rows,\
    \ rhs.m_cols, T(0));\n      for (::std::size_t i = 0; i < lhs.m_rows; ++i) {\n\
    \        for (::std::size_t k = 0; k < lhs.m_cols; ++k) {\n          for (::std::size_t\
    \ j = 0; j < rhs.m_cols; ++j) {\n            result[i][j] += lhs[i][k] * rhs[k][j];\n\
    \          }\n        }\n      }\n      return result;\n    }\n    friend ::tools::vector<T>\
    \ operator*(const ::tools::matrix<T>& lhs, const ::tools::vector<T>& rhs) {\n\
    \      assert(lhs.m_cols == rhs.size());\n      ::tools::vector<T> result(lhs.m_rows,\
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
    \    }\n    friend bool operator==(const ::tools::matrix<T>& lhs, const ::tools::matrix<T>&\
    \ rhs) {\n      return lhs.m_cols == rhs.m_cols && lhs.m_rows == rhs.m_rows &&\
    \ lhs.m_values == rhs.m_values;\n    }\n    friend bool operator!=(const ::tools::matrix<T>&\
    \ lhs, const ::tools::matrix<T>& rhs) {\n      return !(lhs == rhs);\n    }\n\n\
    \    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::matrix<T>&\
    \ self) {\n      for (::std::size_t r = 0; r < self.m_rows; ++r) {\n        os\
    \ << '[';\n        ::std::string delimiter = \"\";\n        for (::std::size_t\
    \ c = 0; c < self.m_cols; ++c) {\n          os << delimiter << self[r][c];\n \
    \         delimiter = \", \";\n        }\n        os << ']' << '\\n';\n      }\n\
    \      return os;\n    }\n    friend ::std::istream& operator>>(::std::istream&\
    \ is, ::tools::matrix<T>& self) {\n      for (T& value : self.m_values) {\n  \
    \      is >> value;\n      }\n      return is;\n    }\n\n  private:\n    ::std::pair<::std::size_t,\
    \ T> internal_gauss_jordan() {\n      ::std::size_t rank = 0;\n      T coeff(1);\n\
    \n      for (::std::size_t c = 0; c < this->m_cols; ++c) {\n        ::std::size_t\
    \ pivot;\n        for (pivot = rank; pivot < this->m_rows && (*this)[pivot][c]\
    \ == T(0); ++pivot);\n        if (pivot == this->m_rows) continue;\n\n       \
    \ if (pivot != rank) {\n          for (::std::size_t cc = c; cc < this->m_cols;\
    \ ++cc) {\n            ::std::swap((*this)[rank][cc], (*this)[pivot][cc]);\n \
    \         }\n          coeff *= T(-1);\n        }\n\n        {\n          const\
    \ T scale_inv = T(1) / (*this)[rank][c];\n          for (::std::size_t cc = c;\
    \ cc < this->m_cols; ++cc) {\n            (*this)[rank][cc] *= scale_inv;\n  \
    \        }\n          coeff *= scale_inv;\n        }\n\n        for (::std::size_t\
    \ r = 0; r < this->m_rows; ++r) {\n          if (r == rank) continue;\n      \
    \    const T scale = (*this)[r][c];\n          if (scale == T(0)) continue;\n\
    \          for (::std::size_t cc = c; cc < this->m_cols; ++cc) {\n           \
    \ (*this)[r][cc] -= (*this)[rank][cc] * scale;\n          }\n        }\n\n   \
    \     ++rank;\n      }\n\n      return ::std::make_pair(rank, coeff);\n    }\n\
    \n  public:\n    ::std::size_t gauss_jordan() {\n      return this->internal_gauss_jordan().first;\n\
    \    }\n\n    ::tools::matrix<T> solve(const ::tools::vector<T>& b) const {\n\
    \      assert(this->m_rows == b.size());\n      assert(this->m_cols >= 1);\n \
    \     ::tools::matrix<T> Ab(this->m_rows, this->m_cols + 1);\n      for (::std::size_t\
    \ r = 0; r < this->m_rows; ++r) {\n        for (::std::size_t c = 0; c < this->m_cols;\
    \ ++c) {\n          Ab[r][c] = (*this)[r][c];\n        }\n        Ab[r][this->m_cols]\
    \ = b[r];\n      }\n\n      Ab.internal_gauss_jordan();\n\n      ::std::vector<::std::size_t>\
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
    \ answer;\n    }\n\n    T determinant() const {\n      assert(this->m_rows ==\
    \ this->m_cols);\n\n      ::tools::matrix<T> A = *this;\n      const auto [rank,\
    \ coeff] = A.internal_gauss_jordan();\n\n      return rank == A.m_rows ? T(1)\
    \ / coeff : T(0);\n    }\n\n    static ::tools::matrix<T> e(const ::std::size_t\
    \ n) {\n      ::tools::matrix<T> result(n, n, T(0));\n      for (::std::size_t\
    \ i = 0; i < n; ++i) {\n        result[i][i] = T(1);\n      }\n      return result;\n\
    \    }\n\n    ::std::optional<::tools::matrix<T>> inv() const {\n      if (this->m_rows\
    \ != this->m_cols) return ::std::nullopt;\n\n      ::tools::matrix<T> AI(this->m_rows,\
    \ this->m_cols * 2);\n      for (::std::size_t r = 0; r < this->m_rows; ++r) {\n\
    \        for (::std::size_t c = 0; c < this->m_cols; ++c) {\n          AI[r][c]\
    \ = (*this)[r][c];\n        }\n        for (::std::size_t c = this->m_cols; c\
    \ < AI.m_cols; ++c) {\n          AI[r][c] = T(0);\n        }\n        AI[r][this->m_cols\
    \ + r] = T(1);\n      }\n\n      AI.internal_gauss_jordan();\n      for (::std::size_t\
    \ i = 0; i < this->m_rows; ++i) {\n        if (AI[i][i] != T(1)) return ::std::nullopt;\n\
    \      }\n\n      ::tools::matrix<T> B(this->m_rows, this->m_cols);\n      for\
    \ (::std::size_t r = 0; r < this->m_rows; ++r) {\n        for (::std::size_t c\
    \ = 0; c < this->m_cols; ++c) {\n          B[r][c] = AI[r][this->m_cols + c];\n\
    \        }\n      }\n      return B;\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/vector.hpp
  - tools/detail/vector_common.hpp
  - tools/abs.hpp
  isVerificationFile: false
  path: tools/matrix.hpp
  requiredBy: []
  timestamp: '2022-11-03 23:21:16+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/matrix/determinant.test.cpp
  - tests/matrix/inv.test.cpp
  - tests/matrix/multiplies.test.cpp
  - tests/matrix/solve.test.cpp
documentation_of: tools/matrix.hpp
layout: document
title: Matrix
---

It is a $n \times m$-dimensional matrix.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) matrix<T> A(std::size_t n, std::size_t m);
(2) matrix<T> A(std::size_t n, std::size_t m, T x);
```

- (1)
    - It creates a $n \times m$-dimensional matrix.
- (2)
    - It creates a $n \times m$-dimensional matrix, of which all the elements $x$.

The type parameter `<T>` represents the type of the elements.

### Constraints
- None

### Time Complexity
- $O(nm)$

## operator[]
```cpp
T& A[i][j];
```

It is the $(i, j)$-th element of the matrix.

### Constraints
- $0 \leq i < n$
- $0 \leq j < m$

### Time Complexity
- $O(1)$

## rows
```cpp
std::size_t A.rows();
```

It returns the number of the rows of the matrix.

### Constraints
- None

### Time Complexity
- $O(1)$

## cols
```cpp
std::size_t A.cols();
```

It returns the number of the columns of the matrix.

### Constraints
- None

### Time Complexity
- $O(1)$

## gauss_jordan
```cpp
std::size_t A.gauss_jordan();
```

It transforms the matrix to the reduced row echelon form, and returns the rank of the matrix.

### Constraints
- None

### Time Complexity
- $O(n m^2)$

## solve
```cpp
matrix<T> A.solve(vector<T> b);
```

It solves $A\overrightarrow{x} = \overrightarrow{b}$.
If the answers exist, the answers can be denoted as follows where $B$ is another $m \times (m - \mathrm{rank}(A) + 1)$-dimensional matrix and $c_i$ are free variables.

$$\begin{align*}
\overrightarrow{x} &= B\left(\begin{array}{c}
c_1\\
c_2\\
\vdots\\
c_{m - \mathrm{rank}(A)}\\
1
\end{array}\right)
\end{align*}$$

If the answers exist, it returns $B$.
Otherwise, it returns a $m \times 0$-dimensional matrix.

### Constraints
- None

### Time Complexity
- $O(n m^2)$

## determinant
```cpp
T A.determinant();
```

It returns $\|A\|$.

### Constraints
- $n = m$

### Time Complexity
- $O(n^3)$

## Arithmetic operations
```cpp
(1) matrix<T> +A;
(2) matrix<T> -A;
(3) matrix<T> A + B;
(4) matrix<T> A - B;
(5) matrix<T> A * c;
(6) matrix<T> c * A;
(7) matrix<T> A / c;
(8) matrix<T>& A += B;
(9) matrix<T>& A -= B;
(10) matrix<T>& A *= c;
(11) matrix<T>& A /= c;
(12) bool A == B;
(13) bool A != B;
```

It supports basic arithmetic operations on matrices where $B$ is another $n \times m$-dimensional matrix and $c$ is a scholar value.

### Constraints
- (3), (4), (8), (9), (12), (13)
    - The dimension of $B$ is equal to the dimension of $A$.
- (7), (11)
    - $c \neq 0$

### Time Complexity
- $O(nm)$

## e
```cpp
matrix<T> matrix<T>::e(::std::size_t n);
```

It returns $n \times n$-dimensional identity matrix.

### Constraints
- None

### Time Complexity
- $O(n^2)$

## inv
```cpp
std::optional<matrix<T>> A.inv();
```

If $A^{-1}$ exists, it returns $A^{-1}$.
Otherwise, it returns `std::nullopt`.

### Constraints
- None

### Time Complexity
- $O(n^3)$
