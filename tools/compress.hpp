#ifndef TOOLS_COMPRESS_HPP
#define TOOLS_COMPRESS_HPP

#include <utility>
#include <map>
#include <iterator>
#include <vector>
#include <algorithm>
#include "tools/lower_bound.hpp"

namespace tools {

  template <typename InputIterator>
  ::std::pair<
    ::std::map<
      typename ::std::iterator_traits<InputIterator>::value_type,
      typename ::std::iterator_traits<InputIterator>::value_type
    >,
    ::std::vector<typename ::std::iterator_traits<InputIterator>::value_type>
  > compress(InputIterator begin, InputIterator end) {
    using T = typename ::std::iterator_traits<InputIterator>::value_type;

    ::std::vector<T> g(begin, end);
    ::std::sort(g.begin(), g.end());
    g.erase(::std::unique(g.begin(), g.end()), g.end());

    ::std::map<T, T> f;
    for (T i = 0; i < T(g.size()); ++i) {
      f.emplace(g[i], i);
    }

    return ::std::make_pair(f, g);
  }

  template <typename InputIterator, typename OutputIterator>
  void compress(InputIterator begin, InputIterator end, OutputIterator result) {
    using T = typename ::std::iterator_traits<InputIterator>::value_type;
    ::std::vector<T> orig(begin, end);
    ::std::vector<T> sorted(orig);
    ::std::sort(sorted.begin(), sorted.end());
    sorted.erase(::std::unique(sorted.begin(), sorted.end()), sorted.end());
    for (auto it = orig.begin(); it != orig.end(); ++it, ++result) {
      *result = ::tools::lower_bound(sorted.begin(), sorted.end(), *it);
    }
  }
}

#endif
