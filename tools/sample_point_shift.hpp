#ifndef TOOLS_SAMPLE_POINT_SHIFT_HPP
#define TOOLS_SAMPLE_POINT_SHIFT_HPP

#include <type_traits>
#include <iterator>
#include <vector>
#include <cassert>
#include <array>
#include <initializer_list>
#include "tools/is_prime.hpp"
#include "tools/fact_mod_cache.hpp"
#include "tools/convolution.hpp"

namespace tools {

  template <typename RandomAccessIterator>
  ::std::enable_if_t<
    ::std::is_base_of_v<
      ::std::random_access_iterator_tag,
      typename ::std::iterator_traits<RandomAccessIterator>::iterator_category
    >,
    ::std::vector<typename ::std::iterator_traits<RandomAccessIterator>::value_type>
  > sample_point_shift(const RandomAccessIterator begin, const RandomAccessIterator end, const typename ::std::iterator_traits<RandomAccessIterator>::value_type c, const int M) {
    assert(begin < end);
    using T = typename ::std::iterator_traits<RandomAccessIterator>::value_type;
    assert(::tools::is_prime(T::mod()));
    const int N = ::std::distance(begin, end) - 1;
    assert(N < T::mod());
    assert(0 <= M);
    if (M == 0) return ::std::vector<T>{};
    const int m = ::std::min(M, T::mod()) - 1;
    ::tools::fact_mod_cache<T> cache;
    const ::std::array<T, 2> minus_1_pow = {T(1), T(-1)};

    ::std::vector<T> c1;
    {
      ::std::vector<T> a1(N + 1);
      for (int i = 0; i <= N; ++i) {
        a1[i] = begin[i] * cache.fact_inv(i);
      }

      ::std::vector<T> b1(N + 1);
      for (int i = 0; i <= N; ++i) {
        b1[i] = minus_1_pow[i & 1] * cache.fact_inv(i);
      }

      ::tools::convolution(a1.begin(), a1.end(), b1.begin(), b1.end(), ::std::back_inserter(c1));
      c1.resize(N + 1);
    }

    ::std::vector<T> c2;
    {
      ::std::vector<T> a2(N + 1);
      for (int i = 0; i <= N; ++i) {
        a2[i] = c1[N - i] * cache.fact(N - i);
      }

      ::std::vector<T> b2(N + 1);
      b2[0] = T(1);
      T b = c;
      for (int i = 1; i <= N; ++i, --b) {
        b2[i] = b2[i - 1] * b;
      }
      for (int i = 0; i <= N; ++i) {
        b2[i] *= cache.fact_inv(i);
      }

      ::tools::convolution(a2.begin(), a2.end(), b2.begin(), b2.end(), ::std::back_inserter(c2));
      c2.resize(N + 1);
      ::std::reverse(c2.begin(), c2.end());
      for (int i = 0; i <= N; ++i) {
        c2[i] *= cache.fact_inv(i);
      }
    }

    ::std::vector<T> c3;
    {
      const auto& a3 = c2;

      ::std::vector<T> b3(m + 1);
      for (int i = 0; i <= m; ++i) {
        b3[i] = cache.fact_inv(i);
      }

      ::tools::convolution(a3.begin(), a3.end(), b3.begin(), b3.end(), ::std::back_inserter(c3));
      c3.resize(m + 1);
      for (int i = 0; i <= m; ++i) {
        c3[i] *= cache.fact(i);
      }
    }

    for (int i = ::tools::ssize(c3); i < M; ++i) {
      c3[i] = c3[T(i).val()];
    }

    return c3;
  }

  template <typename InputIterator>
  ::std::enable_if_t<
    !::std::is_base_of_v<
      ::std::random_access_iterator_tag,
      typename ::std::iterator_traits<InputIterator>::iterator_category
    >,
    ::std::vector<typename ::std::iterator_traits<InputIterator>::value_type>
  > sample_point_shift(const InputIterator begin, const InputIterator end, const typename ::std::iterator_traits<InputIterator>::value_type c, const int M) {
    using T = typename ::std::iterator_traits<InputIterator>::value_type;
    const ::std::vector<T> samples(begin, end);
    return ::tools::sample_point_shift(samples.begin(), samples.end(), c, M);
  }

  template <typename T>
  ::std::vector<T> sample_point_shift(const ::std::initializer_list<T> il, const T c, const int M) {
    return ::tools::sample_point_shift(il.begin(), il.end(), c, M);
  }
}

#endif
