#ifndef TOOLS_UTIL_HPP
#define TOOLS_UTIL_HPP

// To see the details of my library, visit my GitHub Pages.
// https://anqooqie.github.io/proconlib/

#ifdef LOCAL
  #ifndef _GLIBCXX_DEBUG
    #define _GLIBCXX_DEBUG
  #endif
#else
  #ifndef NDEBUG
    #define NDEBUG
  #endif
#endif

#include <bits/stdc++.h>
#include "tools/resize.hpp"
#include "tools/fill.hpp"
#include "tools/extend_input.hpp"
#include "tools/extend_output.hpp"
#include "tools/extend_hash.hpp"

using ll = long long;
using ull = unsigned long long;
using i32 = ::std::int32_t;
using u32 = ::std::uint32_t;
using i64 = ::std::int64_t;
using u64 = ::std::uint64_t;

#define ALL(x) ::std::begin(x), ::std::end(x)
#define REP(i, n) for (long long i = 0, i##_len = static_cast<long long>(n); i < i##_len; ++i)

#endif
