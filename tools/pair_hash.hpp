#ifndef TOOLS_PAIR_HASH_HPP
#define TOOLS_PAIR_HASH_HPP

#include <cstddef>
#include <utility>
#include <random>
#include <functional>
#include <cstdint>

namespace tools {

  /**
   * hash of `std::pair<T1, T2>`
   * License: Boost Software License, Version 1.0 ( http://www.boost.org/LICENSE_1_0.txt )
   * Reference: Boost, Version 1.71.0 ( https://github.com/boostorg/container_hash/blob/boost-1.71.0/include/boost/container_hash/hash.hpp )
   * @author Daniel James
   * @param <T1> first type of `key`
   * @param <T2> second type of `key`
   * @param key value of `std::pair<T1, T2>`
   * @return hash of `key`
   */
  template <class T1, class T2>
  struct pair_hash {
    using result_type = ::std::size_t;
    using argument_type = ::std::pair<T1, T2>;
    ::std::size_t operator()(const ::std::pair<T1, T2>& key) const {
      static const ::std::size_t salt = ::std::random_device()();
      static const ::std::hash<T1> hasher1 = ::std::hash<T1>();
      static const ::std::hash<T2> hasher2 = ::std::hash<T2>();
      static const ::std::hash<::std::size_t> hasher3 = ::std::hash<::std::size_t>();
      ::std::size_t result = 0;
      result ^= hasher1(key.first) + static_cast<::std::size_t>(0x9e3779b9) + (result << static_cast<::std::size_t>(6)) + (result >> static_cast<::std::size_t>(2));
      result ^= hasher2(key.second) + static_cast<::std::size_t>(0x9e3779b9) + (result << static_cast<::std::size_t>(6)) + (result >> static_cast<::std::size_t>(2));
      result ^= hasher3(salt) + static_cast<::std::size_t>(0x9e3779b9) + (result << static_cast<::std::size_t>(6)) + (result >> static_cast<::std::size_t>(2));
      return result;
    }
  };

  /**
   * hash of `std::pair<std::uint64_t, std::uint64_t>`
   * License: CC0
   *
   * Usage:
   * ```
   * using u64 = std::uint64_t;
   * std::unordered_map<std::pair<u64, u64>, int, tools::pair_hash<u64, u64>> map;
   * ```
   *
   * @author anqooqie
   * @param value of `std::pair<std::uint64_t, std::uint64_t>`
   * @return hash of `key`
   */
  template <>
  struct pair_hash<::std::uint64_t, ::std::uint64_t> {
    using result_type = ::std::size_t;
    using argument_type = ::std::pair<::std::uint64_t, ::std::uint64_t>;
    ::std::size_t operator()(const ::std::pair<::std::uint64_t, ::std::uint64_t>& key) const {
      static const ::std::hash<::std::uint64_t> hasher = ::std::hash<::std::uint64_t>();
      return hasher(((key.first << static_cast<::std::uint64_t>(32)) | (key.first >> static_cast<::std::uint64_t>(32))) ^ key.second);
    }
  };

  /**
   * hash of `std::pair<std::int64_t, std::int64_t>`
   * License: CC0
   *
   * Usage:
   * ```
   * using i64 = std::int64_t;
   * std::unordered_map<std::pair<i64, i64>, int, tools::pair_hash<i64, i64>> map;
   * ```
   *
   * @author anqooqie
   * @param value of `std::pair<std::int64_t, std::int64_t>`
   * @return hash of `key`
   */
  template <>
  struct pair_hash<::std::int64_t, ::std::int64_t> {
    using result_type = ::std::size_t;
    using argument_type = ::std::pair<::std::int64_t, ::std::int64_t>;
    ::std::size_t operator()(const ::std::pair<::std::int64_t, ::std::int64_t>& key) const {
      static const ::tools::pair_hash<::std::uint64_t, ::std::uint64_t> hasher = ::tools::pair_hash<::std::uint64_t, ::std::uint64_t>();
      return hasher(::std::make_pair<::std::uint64_t, ::std::uint64_t>(key.first, key.second));
    }
  };

  /**
   * hash of `std::pair<std::uint32_t, std::uint32_t>`
   * License: CC0
   *
   * Usage:
   * ```
   * using u32 = std::uint32_t;
   * std::unordered_map<std::pair<u32, u32>, int, tools::pair_hash<u32, u32>> map;
   * ```
   *
   * @author anqooqie
   * @param value of `std::pair<std::uint32_t, std::uint32_t>`
   * @return hash of `key`
   */
  template <>
  struct pair_hash<::std::uint32_t, ::std::uint32_t> {
    using result_type = ::std::size_t;
    using argument_type = ::std::pair<::std::uint32_t, ::std::uint32_t>;
    ::std::size_t operator()(const ::std::pair<::std::uint32_t, ::std::uint32_t>& key) const {
      static const ::std::hash<::std::uint64_t> hasher = ::std::hash<::std::uint64_t>();
      return hasher((static_cast<::std::uint64_t>(key.first) << static_cast<::std::uint64_t>(32)) | static_cast<::std::uint64_t>(key.second));
    }
  };

  /**
   * hash of `std::pair<std::int32_t, std::int32_t>`
   * License: CC0
   *
   * Usage:
   * ```
   * using i32 = std::int32_t;
   * std::unordered_map<std::pair<i32, i32>, int, tools::pair_hash<i32, i32>> map;
   * ```
   *
   * @author anqooqie
   * @param value of `std::pair<std::int32_t, std::int32_t>`
   * @return hash of `key`
   */
  template <>
  struct pair_hash<::std::int32_t, ::std::int32_t> {
    using result_type = ::std::size_t;
    using argument_type = ::std::pair<::std::int32_t, ::std::int32_t>;
    ::std::size_t operator()(const ::std::pair<::std::int32_t, ::std::int32_t>& key) const {
      static const ::tools::pair_hash<::std::uint32_t, ::std::uint32_t> hasher = ::tools::pair_hash<::std::uint32_t, ::std::uint32_t>();
      return hasher(::std::make_pair<::std::uint32_t, ::std::uint32_t>(key.first, key.second));
    }
  };
}

#endif
