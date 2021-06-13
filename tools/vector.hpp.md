---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tools/matrix.hpp
    title: tools/matrix.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/vector.hpp\"\n\n\n\n#include <vector>\n#include <cstddef>\n\
    #include <cassert>\n\nnamespace tools {\n  template <typename T>\n  class vector\
    \ {\n  private:\n    ::std::vector<T> m_values;\n\n  public:\n    vector() = default;\n\
    \    vector(const ::tools::vector<T>&) = default;\n    vector(::tools::vector<T>&&)\
    \ = default;\n    ~vector() = default;\n    ::tools::vector<T>& operator=(const\
    \ ::tools::vector<T>&) = default;\n    ::tools::vector<T>& operator=(::tools::vector<T>&&)\
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
    \ result;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_VECTOR_HPP\n#define TOOLS_VECTOR_HPP\n\n#include <vector>\n\
    #include <cstddef>\n#include <cassert>\n\nnamespace tools {\n  template <typename\
    \ T>\n  class vector {\n  private:\n    ::std::vector<T> m_values;\n\n  public:\n\
    \    vector() = default;\n    vector(const ::tools::vector<T>&) = default;\n \
    \   vector(::tools::vector<T>&&) = default;\n    ~vector() = default;\n    ::tools::vector<T>&\
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
    \ result;\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/vector.hpp
  requiredBy:
  - tools/matrix.hpp
  timestamp: '2021-06-13 16:51:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/vector.hpp
layout: document
redirect_from:
- /library/tools/vector.hpp
- /library/tools/vector.hpp.html
title: tools/vector.hpp
---
