#ifndef TOOLS_CONVEX_HULL_HPP
#define TOOLS_CONVEX_HULL_HPP

#include <type_traits>
#include <vector>
#include <cstddef>
#include <numeric>
#include <algorithm>
#include <utility>
#include <iterator>
#include <stack>
#include "tools/vector2.hpp"
#include "tools/less_by.hpp"
#include "tools/ccw.hpp"

namespace tools {
  template <typename InputIterator, typename OutputIterator>
  void convex_hull(const InputIterator begin, const InputIterator end, bool minimum, OutputIterator result) {
    using T = ::std::decay_t<decltype(begin->x)>;

    const ::std::vector<::tools::vector2<T>> v(begin, end);
    ::std::vector<::std::size_t> a(v.size());
    ::std::iota(a.begin(), a.end(), 0);
    ::std::sort(a.begin(), a.end(), ::tools::less_by([&](const T& i) {
      return ::std::make_pair(v[i].x, v[i].y);
    }));
    ::std::vector<::std::vector<::std::size_t>> duplicates;

    if (minimum) {
      ::std::size_t vl = 0;
      for (::std::size_t vr = 0, al = 0, ar = 0; al < a.size(); vl = vr, al = ar) {
        for (; ar < a.size() && v[a[al]].x == v[a[ar]].x; ++vr, ++ar);
        for (::std::size_t i = 0; i < ar - al; ++i) ::std::swap(a[vl + i], a[al + i]);
        if (v[a[vl]].y == v[a[vr - 1]].y) {
          vr -= vr - vl - 1;
          duplicates.emplace_back();
          duplicates.back().push_back(a[vl]);
        } else {
          ::std::swap(a[vl + 1], a[vr - 1]);
          vr -= vr - vl - 2;
          duplicates.emplace_back();
          duplicates.back().push_back(a[vl]);
          duplicates.emplace_back();
          duplicates.back().push_back(a[vl + 1]);
        }
      }
      a.erase(::std::next(a.begin(), vl), a.end());
    } else {
      ::std::size_t vl = 0;
      for (::std::size_t vr = 0, al = 0, ar = 0; al < a.size(); vl = vr, al = ar) {
        for (; ar < a.size() && v[a[al]] == v[a[ar]]; ++vr, ++ar);
        for (::std::size_t i = 0; i < ar - al; ++i) ::std::swap(a[vl + i], a[al + i]);
        duplicates.emplace_back();
        for (::std::size_t i = vl; i < vr; ++i) {
          duplicates.back().push_back(a[i]);
        }
        vr -= vr - vl - 1;
      }
      a.erase(::std::next(a.begin(), vl), a.end());
    }

    ::std::vector<::std::size_t> convex_hull;
    if (a.size() >= 3) {

      convex_hull.push_back(0);
      convex_hull.push_back(1);
      for (::std::size_t p3 = 2; p3 < a.size(); ++p3) {
        while (convex_hull.size() >= 2) {
          const int ccw = ::tools::ccw(v[a[convex_hull.rbegin()[1]]], v[a[convex_hull.back()]], v[a[p3]]);
          if (ccw == 1 || (!minimum && ccw == -2)) {
            break;
          }
          convex_hull.pop_back();
        }
        convex_hull.push_back(p3);
      }

      const ::std::size_t threshold = convex_hull.size() + 1;
      for (::std::size_t p3 = convex_hull.back(); p3 --> 0;) {
        while (convex_hull.size() >= threshold) {
          const int ccw = ::tools::ccw(v[a[convex_hull.rbegin()[1]]], v[a[convex_hull.back()]], v[a[p3]]);
          if (ccw == 1 || (!minimum && ccw == -2)) {
            break;
          }
          convex_hull.pop_back();
        }
        convex_hull.push_back(p3);
      }
      convex_hull.pop_back();

    } else {
      for (::std::size_t i = 0; i < a.size(); ++i) {
        convex_hull.push_back(i);
      }
    }

    for (const ::std::size_t& c : convex_hull) {
      for (const ::std::size_t& i : duplicates[c]) {
        if constexpr (::std::is_assignable_v<OutputIterator, ::std::size_t>) {
          *result = i;
        } else {
          *result = v[i];
        }
        ++result;
      }
    }
  }
}

#endif
