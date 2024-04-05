#ifndef TOOLS_POLYNOMIAL_PRODUCT_HPP
#define TOOLS_POLYNOMIAL_PRODUCT_HPP

#include <type_traits>
#include <iterator>
#include <vector>
#include <queue>
#include <utility>
#include <cstddef>
#include <initializer_list>
#include "tools/greater_by.hpp"

namespace tools {
  template <typename RandomAccessIterator>
  ::std::enable_if_t<
    ::std::is_base_of_v<
      ::std::random_access_iterator_tag,
      typename ::std::iterator_traits<RandomAccessIterator>::iterator_category
    >,
    typename ::std::iterator_traits<RandomAccessIterator>::value_type
  > polynomial_product(const RandomAccessIterator begin, const RandomAccessIterator end) {
    using P = typename ::std::iterator_traits<RandomAccessIterator>::value_type;

    if (begin == end) return ++P{};

    ::std::vector<P> cache;
    const auto get_polynomial = [&](const bool is_cache, const ::std::size_t i) -> const P& { return is_cache ? cache[i] : begin[i]; };
    const auto greater_by_size = ::tools::greater_by([&](const auto& pair) { return get_polynomial(pair.first, pair.second).size(); });
    ::std::priority_queue<::std::pair<bool, ::std::size_t>, ::std::vector<::std::pair<bool, ::std::size_t>>, decltype(greater_by_size)> pq(greater_by_size);
    for (auto it = begin; it != end; ++it) {
      pq.emplace(false, ::std::distance(begin, it));
    }

    while (pq.size() > 1) {
      const auto [p, i] = pq.top();
      pq.pop();
      const auto [q, j] = pq.top();
      pq.pop();
      cache.push_back(get_polynomial(p, i) * get_polynomial(q, j));
      pq.emplace(true, cache.size() - 1);
    }

    return get_polynomial(pq.top().first, pq.top().second);
  }

  template <typename InputIterator>
  ::std::enable_if_t<
    !::std::is_base_of_v<
      ::std::random_access_iterator_tag,
      typename ::std::iterator_traits<InputIterator>::iterator_category
    >,
    typename ::std::iterator_traits<InputIterator>::value_type
  > polynomial_product(const InputIterator begin, const InputIterator end) {
    using P = typename ::std::iterator_traits<InputIterator>::value_type;
    const ::std::vector<P> polynomials(begin, end);
    return polynomial_product(polynomials.begin(), polynomials.end());
  }

  template <typename P>
  P polynomial_product(const ::std::initializer_list<P> il) {
    return polynomial_product(il.begin(), il.end());
  }
}

#endif
