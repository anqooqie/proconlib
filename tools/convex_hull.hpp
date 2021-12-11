#ifndef TOOLS_CONVEX_HULL_HPP
#define TOOLS_CONVEX_HULL_HPP

#include <type_traits>
#include <vector>
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
  void convex_hull(const InputIterator begin, const InputIterator end, OutputIterator result) {
    using T = ::std::decay_t<decltype(begin->x)>;

    ::std::vector<::tools::vector2<T>> v(begin, end);
    ::std::vector<T> a(v.size());
    ::std::iota(a.begin(), a.end(), 0);
    ::std::sort(a.begin(), a.end(), ::tools::less_by([&](const T& i) {
      return ::std::make_pair(v[i].x, -v[i].y);
    }));

    T vl = 0;
    for (T vr = 0, al = 0, ar = 0; al < T(a.size()); vl = vr, al = ar) {
      for (; ar < T(a.size()) && v[a[al]].x == v[a[ar]].x; ::std::swap(a[vr], a[ar]), ++vr, ++ar);
      if (v[a[vl]].y == v[a[vr - 1]].y) {
        vr -= vr - vl - 1;
      } else {
        ::std::swap(a[vl + 1], a[vr - 1]);
        vr -= vr - vl - 2;
      }
    }
    a.erase(::std::next(a.begin(), vl), a.end());

    ::std::stack<T> stack;
    if (a.size() >= 3) {

      stack.push(0);
      stack.push(1);
      for (T p3 = stack.top() + 1; p3 < T(a.size()); ++p3) {
        while (stack.size() >= 2) {
          const T p2 = stack.top();
          stack.pop();
          const T p1 = stack.top();
          if (::tools::ccw(v[a[p1]], v[a[p2]], v[a[p3]]) == -1) {
            stack.push(p2);
            break;
          }
        }
        stack.push(p3);
      }

      const T threshold = stack.size() + 1;
      for (T p3 = stack.top() - 1; p3 >= 0; --p3) {
        while (T(stack.size()) >= threshold) {
          const T p2 = stack.top();
          stack.pop();
          const T p1 = stack.top();
          if (::tools::ccw(v[a[p1]], v[a[p2]], v[a[p3]]) == -1) {
            stack.push(p2);
            break;
          }
        }
        stack.push(p3);
      }
      stack.pop();

    } else {
      for (T i = 0; i < T(a.size()); ++i) {
        stack.push(i);
      }
    }

    ::std::vector<T> convex_hull;
    while (!stack.empty()) {
      convex_hull.push_back(a[stack.top()]);
      stack.pop();
    }
    ::std::reverse(convex_hull.begin(), convex_hull.end());

    for (const T& c : convex_hull) {
      *result = c;
      ++result;
    }
  }
}

#endif
