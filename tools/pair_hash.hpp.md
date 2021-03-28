---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tools/vector2.hpp
    title: tools/vector2.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://www.boost.org/LICENSE_1_0.txt
    - https://github.com/boostorg/container_hash/blob/boost-1.71.0/include/boost/container_hash/hash.hpp
  bundledCode: "#line 1 \"tools/pair_hash.hpp\"\n\n\n\n#include <cstddef>\n#include\
    \ <utility>\n#include <random>\n#include <functional>\n#include <cstdint>\n\n\
    namespace tools {\n\n  /**\n   * hash of `std::pair<T1, T2>`\n   * License: Boost\
    \ Software License, Version 1.0 ( http://www.boost.org/LICENSE_1_0.txt )\n   *\
    \ Reference: Boost, Version 1.71.0 ( https://github.com/boostorg/container_hash/blob/boost-1.71.0/include/boost/container_hash/hash.hpp\
    \ )\n   * @author Daniel James\n   * @param <T1> first type of `key`\n   * @param\
    \ <T2> second type of `key`\n   * @param key value of `std::pair<T1, T2>`\n  \
    \ * @return hash of `key`\n   */\n  template <class T1, class T2>\n  struct pair_hash\
    \ {\n    using result_type = ::std::size_t;\n    using argument_type = ::std::pair<T1,\
    \ T2>;\n    ::std::size_t operator()(const ::std::pair<T1, T2>& key) const {\n\
    \      static const ::std::size_t salt = ::std::random_device()();\n      static\
    \ const ::std::hash<T1> hasher1 = ::std::hash<T1>();\n      static const ::std::hash<T2>\
    \ hasher2 = ::std::hash<T2>();\n      static const ::std::hash<::std::size_t>\
    \ hasher3 = ::std::hash<::std::size_t>();\n      ::std::size_t result = 0;\n \
    \     result ^= hasher1(key.first) + static_cast<::std::size_t>(0x9e3779b9) +\
    \ (result << static_cast<::std::size_t>(6)) + (result >> static_cast<::std::size_t>(2));\n\
    \      result ^= hasher2(key.second) + static_cast<::std::size_t>(0x9e3779b9)\
    \ + (result << static_cast<::std::size_t>(6)) + (result >> static_cast<::std::size_t>(2));\n\
    \      result ^= hasher3(salt) + static_cast<::std::size_t>(0x9e3779b9) + (result\
    \ << static_cast<::std::size_t>(6)) + (result >> static_cast<::std::size_t>(2));\n\
    \      return result;\n    }\n  };\n\n  /**\n   * hash of `std::pair<std::uint64_t,\
    \ std::uint64_t>`\n   * License: CC0\n   *\n   * Usage:\n   * ```\n   * using\
    \ u64 = std::uint64_t;\n   * std::unordered_map<std::pair<u64, u64>, int, tools::pair_hash<u64,\
    \ u64>> map;\n   * ```\n   *\n   * @author anqooqie\n   * @param value of `std::pair<std::uint64_t,\
    \ std::uint64_t>`\n   * @return hash of `key`\n   */\n  template <>\n  struct\
    \ pair_hash<::std::uint64_t, ::std::uint64_t> {\n    using result_type = ::std::size_t;\n\
    \    using argument_type = ::std::pair<::std::uint64_t, ::std::uint64_t>;\n  \
    \  ::std::size_t operator()(const ::std::pair<::std::uint64_t, ::std::uint64_t>&\
    \ key) const {\n      static const ::std::hash<::std::uint64_t> hasher = ::std::hash<::std::uint64_t>();\n\
    \      return hasher(((key.first << static_cast<::std::uint64_t>(32)) | (key.first\
    \ >> static_cast<::std::uint64_t>(32))) ^ key.second);\n    }\n  };\n\n  /**\n\
    \   * hash of `std::pair<std::int64_t, std::int64_t>`\n   * License: CC0\n   *\n\
    \   * Usage:\n   * ```\n   * using i64 = std::int64_t;\n   * std::unordered_map<std::pair<i64,\
    \ i64>, int, tools::pair_hash<i64, i64>> map;\n   * ```\n   *\n   * @author anqooqie\n\
    \   * @param value of `std::pair<std::int64_t, std::int64_t>`\n   * @return hash\
    \ of `key`\n   */\n  template <>\n  struct pair_hash<::std::int64_t, ::std::int64_t>\
    \ {\n    using result_type = ::std::size_t;\n    using argument_type = ::std::pair<::std::int64_t,\
    \ ::std::int64_t>;\n    ::std::size_t operator()(const ::std::pair<::std::int64_t,\
    \ ::std::int64_t>& key) const {\n      static const ::tools::pair_hash<::std::uint64_t,\
    \ ::std::uint64_t> hasher = ::tools::pair_hash<::std::uint64_t, ::std::uint64_t>();\n\
    \      return hasher(::std::make_pair<::std::uint64_t, ::std::uint64_t>(key.first,\
    \ key.second));\n    }\n  };\n\n  /**\n   * hash of `std::pair<std::uint32_t,\
    \ std::uint32_t>`\n   * License: CC0\n   *\n   * Usage:\n   * ```\n   * using\
    \ u32 = std::uint32_t;\n   * std::unordered_map<std::pair<u32, u32>, int, tools::pair_hash<u32,\
    \ u32>> map;\n   * ```\n   *\n   * @author anqooqie\n   * @param value of `std::pair<std::uint32_t,\
    \ std::uint32_t>`\n   * @return hash of `key`\n   */\n  template <>\n  struct\
    \ pair_hash<::std::uint32_t, ::std::uint32_t> {\n    using result_type = ::std::size_t;\n\
    \    using argument_type = ::std::pair<::std::uint32_t, ::std::uint32_t>;\n  \
    \  ::std::size_t operator()(const ::std::pair<::std::uint32_t, ::std::uint32_t>&\
    \ key) const {\n      static const ::std::hash<::std::uint64_t> hasher = ::std::hash<::std::uint64_t>();\n\
    \      return hasher((static_cast<::std::uint64_t>(key.first) << static_cast<::std::uint64_t>(32))\
    \ | static_cast<::std::uint64_t>(key.second));\n    }\n  };\n\n  /**\n   * hash\
    \ of `std::pair<std::int32_t, std::int32_t>`\n   * License: CC0\n   *\n   * Usage:\n\
    \   * ```\n   * using i32 = std::int32_t;\n   * std::unordered_map<std::pair<i32,\
    \ i32>, int, tools::pair_hash<i32, i32>> map;\n   * ```\n   *\n   * @author anqooqie\n\
    \   * @param value of `std::pair<std::int32_t, std::int32_t>`\n   * @return hash\
    \ of `key`\n   */\n  template <>\n  struct pair_hash<::std::int32_t, ::std::int32_t>\
    \ {\n    using result_type = ::std::size_t;\n    using argument_type = ::std::pair<::std::int32_t,\
    \ ::std::int32_t>;\n    ::std::size_t operator()(const ::std::pair<::std::int32_t,\
    \ ::std::int32_t>& key) const {\n      static const ::tools::pair_hash<::std::uint32_t,\
    \ ::std::uint32_t> hasher = ::tools::pair_hash<::std::uint32_t, ::std::uint32_t>();\n\
    \      return hasher(::std::make_pair<::std::uint32_t, ::std::uint32_t>(key.first,\
    \ key.second));\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_PAIR_HASH_HPP\n#define TOOLS_PAIR_HASH_HPP\n\n#include <cstddef>\n\
    #include <utility>\n#include <random>\n#include <functional>\n#include <cstdint>\n\
    \nnamespace tools {\n\n  /**\n   * hash of `std::pair<T1, T2>`\n   * License:\
    \ Boost Software License, Version 1.0 ( http://www.boost.org/LICENSE_1_0.txt )\n\
    \   * Reference: Boost, Version 1.71.0 ( https://github.com/boostorg/container_hash/blob/boost-1.71.0/include/boost/container_hash/hash.hpp\
    \ )\n   * @author Daniel James\n   * @param <T1> first type of `key`\n   * @param\
    \ <T2> second type of `key`\n   * @param key value of `std::pair<T1, T2>`\n  \
    \ * @return hash of `key`\n   */\n  template <class T1, class T2>\n  struct pair_hash\
    \ {\n    using result_type = ::std::size_t;\n    using argument_type = ::std::pair<T1,\
    \ T2>;\n    ::std::size_t operator()(const ::std::pair<T1, T2>& key) const {\n\
    \      static const ::std::size_t salt = ::std::random_device()();\n      static\
    \ const ::std::hash<T1> hasher1 = ::std::hash<T1>();\n      static const ::std::hash<T2>\
    \ hasher2 = ::std::hash<T2>();\n      static const ::std::hash<::std::size_t>\
    \ hasher3 = ::std::hash<::std::size_t>();\n      ::std::size_t result = 0;\n \
    \     result ^= hasher1(key.first) + static_cast<::std::size_t>(0x9e3779b9) +\
    \ (result << static_cast<::std::size_t>(6)) + (result >> static_cast<::std::size_t>(2));\n\
    \      result ^= hasher2(key.second) + static_cast<::std::size_t>(0x9e3779b9)\
    \ + (result << static_cast<::std::size_t>(6)) + (result >> static_cast<::std::size_t>(2));\n\
    \      result ^= hasher3(salt) + static_cast<::std::size_t>(0x9e3779b9) + (result\
    \ << static_cast<::std::size_t>(6)) + (result >> static_cast<::std::size_t>(2));\n\
    \      return result;\n    }\n  };\n\n  /**\n   * hash of `std::pair<std::uint64_t,\
    \ std::uint64_t>`\n   * License: CC0\n   *\n   * Usage:\n   * ```\n   * using\
    \ u64 = std::uint64_t;\n   * std::unordered_map<std::pair<u64, u64>, int, tools::pair_hash<u64,\
    \ u64>> map;\n   * ```\n   *\n   * @author anqooqie\n   * @param value of `std::pair<std::uint64_t,\
    \ std::uint64_t>`\n   * @return hash of `key`\n   */\n  template <>\n  struct\
    \ pair_hash<::std::uint64_t, ::std::uint64_t> {\n    using result_type = ::std::size_t;\n\
    \    using argument_type = ::std::pair<::std::uint64_t, ::std::uint64_t>;\n  \
    \  ::std::size_t operator()(const ::std::pair<::std::uint64_t, ::std::uint64_t>&\
    \ key) const {\n      static const ::std::hash<::std::uint64_t> hasher = ::std::hash<::std::uint64_t>();\n\
    \      return hasher(((key.first << static_cast<::std::uint64_t>(32)) | (key.first\
    \ >> static_cast<::std::uint64_t>(32))) ^ key.second);\n    }\n  };\n\n  /**\n\
    \   * hash of `std::pair<std::int64_t, std::int64_t>`\n   * License: CC0\n   *\n\
    \   * Usage:\n   * ```\n   * using i64 = std::int64_t;\n   * std::unordered_map<std::pair<i64,\
    \ i64>, int, tools::pair_hash<i64, i64>> map;\n   * ```\n   *\n   * @author anqooqie\n\
    \   * @param value of `std::pair<std::int64_t, std::int64_t>`\n   * @return hash\
    \ of `key`\n   */\n  template <>\n  struct pair_hash<::std::int64_t, ::std::int64_t>\
    \ {\n    using result_type = ::std::size_t;\n    using argument_type = ::std::pair<::std::int64_t,\
    \ ::std::int64_t>;\n    ::std::size_t operator()(const ::std::pair<::std::int64_t,\
    \ ::std::int64_t>& key) const {\n      static const ::tools::pair_hash<::std::uint64_t,\
    \ ::std::uint64_t> hasher = ::tools::pair_hash<::std::uint64_t, ::std::uint64_t>();\n\
    \      return hasher(::std::make_pair<::std::uint64_t, ::std::uint64_t>(key.first,\
    \ key.second));\n    }\n  };\n\n  /**\n   * hash of `std::pair<std::uint32_t,\
    \ std::uint32_t>`\n   * License: CC0\n   *\n   * Usage:\n   * ```\n   * using\
    \ u32 = std::uint32_t;\n   * std::unordered_map<std::pair<u32, u32>, int, tools::pair_hash<u32,\
    \ u32>> map;\n   * ```\n   *\n   * @author anqooqie\n   * @param value of `std::pair<std::uint32_t,\
    \ std::uint32_t>`\n   * @return hash of `key`\n   */\n  template <>\n  struct\
    \ pair_hash<::std::uint32_t, ::std::uint32_t> {\n    using result_type = ::std::size_t;\n\
    \    using argument_type = ::std::pair<::std::uint32_t, ::std::uint32_t>;\n  \
    \  ::std::size_t operator()(const ::std::pair<::std::uint32_t, ::std::uint32_t>&\
    \ key) const {\n      static const ::std::hash<::std::uint64_t> hasher = ::std::hash<::std::uint64_t>();\n\
    \      return hasher((static_cast<::std::uint64_t>(key.first) << static_cast<::std::uint64_t>(32))\
    \ | static_cast<::std::uint64_t>(key.second));\n    }\n  };\n\n  /**\n   * hash\
    \ of `std::pair<std::int32_t, std::int32_t>`\n   * License: CC0\n   *\n   * Usage:\n\
    \   * ```\n   * using i32 = std::int32_t;\n   * std::unordered_map<std::pair<i32,\
    \ i32>, int, tools::pair_hash<i32, i32>> map;\n   * ```\n   *\n   * @author anqooqie\n\
    \   * @param value of `std::pair<std::int32_t, std::int32_t>`\n   * @return hash\
    \ of `key`\n   */\n  template <>\n  struct pair_hash<::std::int32_t, ::std::int32_t>\
    \ {\n    using result_type = ::std::size_t;\n    using argument_type = ::std::pair<::std::int32_t,\
    \ ::std::int32_t>;\n    ::std::size_t operator()(const ::std::pair<::std::int32_t,\
    \ ::std::int32_t>& key) const {\n      static const ::tools::pair_hash<::std::uint32_t,\
    \ ::std::uint32_t> hasher = ::tools::pair_hash<::std::uint32_t, ::std::uint32_t>();\n\
    \      return hasher(::std::make_pair<::std::uint32_t, ::std::uint32_t>(key.first,\
    \ key.second));\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/pair_hash.hpp
  requiredBy:
  - tools/vector2.hpp
  timestamp: '2021-02-14 17:58:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/pair_hash.hpp
layout: document
redirect_from:
- /library/tools/pair_hash.hpp
- /library/tools/pair_hash.hpp.html
title: tools/pair_hash.hpp
---
