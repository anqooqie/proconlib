---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/join.hpp\"\n\n\n\n#include <string>\n#include <sstream>\n\
    \nnamespace tools {\n\n  template <typename Iterator>\n  ::std::string join(const\
    \ Iterator begin, const Iterator end, const ::std::string delimiter) {\n    ::std::ostringstream\
    \ ss;\n    ::std::string current_delimiter = \"\";\n    for (Iterator it = begin;\
    \ it != end; ++it) {\n      ss << current_delimiter << *it;\n      current_delimiter\
    \ = delimiter;\n    }\n    return ss.str();\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_JOIN_HPP\n#define TOOLS_JOIN_HPP\n\n#include <string>\n#include\
    \ <sstream>\n\nnamespace tools {\n\n  template <typename Iterator>\n  ::std::string\
    \ join(const Iterator begin, const Iterator end, const ::std::string delimiter)\
    \ {\n    ::std::ostringstream ss;\n    ::std::string current_delimiter = \"\"\
    ;\n    for (Iterator it = begin; it != end; ++it) {\n      ss << current_delimiter\
    \ << *it;\n      current_delimiter = delimiter;\n    }\n    return ss.str();\n\
    \  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/join.hpp
  requiredBy: []
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/join.hpp
layout: document
title: Join elements with delimiter
---

```cpp
template <typename Iterator>
std::string join(Iterator begin, Iterator end, std::string delimiter);
```

It returns a string, that is joined elements with `delimtier`.

## License
- CC0

## Author
- anqooqie
