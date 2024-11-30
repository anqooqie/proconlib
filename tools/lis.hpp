#ifndef TOOLS_LIS_HPP
#define TOOLS_LIS_HPP

#include <type_traits>
#include <iterator>
#include <cstddef>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>
#include "atcoder/segtree.hpp"
#include "tools/permutation.hpp"
#include "tools/monoid.hpp"
#include "tools/cmp_equal.hpp"

namespace tools {
  namespace lis {
    template <bool Strict, bool Restore, typename RandomAccessIterator, typename Compare, ::std::enable_if_t<::std::is_base_of_v<::std::random_access_iterator_tag, typename ::std::iterator_traits<RandomAccessIterator>::iterator_category>, ::std::nullptr_t> = nullptr>
    ::std::conditional_t<Restore, ::std::vector<int>, int> segtree(const RandomAccessIterator begin, const RandomAccessIterator end, const Compare& comp) {
      const int N = end - begin;

      const auto p = ::tools::permutation<int>([&]() {
        ::std::vector<int> v(N);
        if constexpr (Strict) {
          ::std::iota(v.rbegin(), v.rend(), 0);
        } else {
          ::std::iota(v.begin(), v.end(), 0);
        }
        ::std::stable_sort(v.begin(), v.end(), [&](const auto x, const auto y) {
          return comp(begin[x], begin[y]);
        });
        return v;
      }()).inv_inplace();

      ::atcoder::segtree<int, ::tools::monoid::max<int, 0>::op, ::tools::monoid::max<int, 0>::e> segtree(N);
      for (int i = 0; i < N; ++i) {
        segtree.set(p[i], segtree.prod(0, p[i]) + 1);
      }

      if constexpr (Restore) {
        ::std::vector<int> answer(segtree.all_prod());
        for (int i = N - 1; i >= 0; --i) {
          if (const auto k = segtree.get(p[i]); k == segtree.all_prod() || p[i] < p[answer[k]]) {
            answer[k - 1] = i;
          }
        }
        return answer;
      } else {
        return segtree.all_prod();
      }
    }
    template <bool Strict, bool Restore, typename InputIterator, typename Compare, ::std::enable_if_t<!::std::is_base_of_v<::std::random_access_iterator_tag, typename ::std::iterator_traits<InputIterator>::iterator_category>, ::std::nullptr_t> = nullptr>
    ::std::conditional_t<Restore, ::std::vector<int>, int> segtree(const InputIterator begin, const InputIterator end, const Compare& comp) {
      ::std::vector<typename ::std::iterator_traits<InputIterator>::value_type> v(begin, end);
      return ::tools::lis::segtree<Strict, Restore>(v.begin(), v.end());
    }
    template <bool Strict, bool Restore, typename InputIterator>
    ::std::conditional_t<Restore, ::std::vector<int>, int> segtree(const InputIterator begin, const InputIterator end) {
      return ::tools::lis::segtree<Strict, Restore>(begin, end, ::std::less<typename ::std::iterator_traits<InputIterator>::value_type>{});
    }
    template <bool Strict, typename InputIterator, typename Compare>
    int segtree(const InputIterator begin, const InputIterator end, const Compare& comp) {
      return ::tools::lis::segtree<Strict, false>(begin, end, comp);
    }
    template <bool Strict, typename InputIterator>
    int segtree(const InputIterator begin, const InputIterator end) {
      return ::tools::lis::segtree<Strict, false>(begin, end, ::std::less<typename ::std::iterator_traits<InputIterator>::value_type>{});
    }

    template <bool Strict, bool Restore, typename RandomAccessIterator, typename Compare, ::std::enable_if_t<::std::is_base_of_v<::std::random_access_iterator_tag, typename ::std::iterator_traits<RandomAccessIterator>::iterator_category>, ::std::nullptr_t> = nullptr>
    ::std::conditional_t<Restore, ::std::vector<int>, int> bisect(const RandomAccessIterator begin, const RandomAccessIterator end, const Compare& comp) {
      const int N = end - begin;

      ::std::vector<int> bisect;
      ::std::vector<int> lengths(Restore ? N : 0);
      for (int i = 0; i < N; ++i) {
        const auto it = Strict
          ? ::std::lower_bound(bisect.begin(), bisect.end(), i, [&](const auto x, const auto y) { return comp(begin[x], begin[y]); })
          : ::std::upper_bound(bisect.begin(), bisect.end(), i, [&](const auto x, const auto y) { return comp(begin[x], begin[y]); });
        if constexpr (Restore) {
          lengths[i] = ::std::distance(bisect.begin(), it) + 1;
        }
        if (it != bisect.end()) {
          *it = i;
        } else {
          bisect.push_back(i);
        }
      }

      if constexpr (Restore) {
        ::std::vector<int> answer(bisect.size());
        for (int i = N - 1; i >= 0; --i) {
          if (const auto k = lengths[i]; ::tools::cmp_equal(k, bisect.size()) || (Strict ? comp(begin[i], begin[answer[k]]) : !comp(begin[answer[k]], begin[i]))) {
            answer[k - 1] = i;
          }
        }
        return answer;
      } else {
        return bisect.size();
      }
    }
    template <bool Strict, bool Restore, typename InputIterator, typename Compare, ::std::enable_if_t<!::std::is_base_of_v<::std::random_access_iterator_tag, typename ::std::iterator_traits<InputIterator>::iterator_category>, ::std::nullptr_t> = nullptr>
    ::std::conditional_t<Restore, ::std::vector<int>, int> bisect(const InputIterator begin, const InputIterator end, const Compare& comp) {
      ::std::vector<typename ::std::iterator_traits<InputIterator>::value_type> v(begin, end);
      return ::tools::lis::bisect<Strict, Restore>(v.begin(), v.end());
    }
    template <bool Strict, bool Restore, typename InputIterator>
    ::std::conditional_t<Restore, ::std::vector<int>, int> bisect(const InputIterator begin, const InputIterator end) {
      return ::tools::lis::bisect<Strict, Restore>(begin, end, ::std::less<typename ::std::iterator_traits<InputIterator>::value_type>{});
    }
    template <bool Strict, typename InputIterator, typename Compare>
    int bisect(const InputIterator begin, const InputIterator end, const Compare& comp) {
      return ::tools::lis::bisect<Strict, false>(begin, end, comp);
    }
    template <bool Strict, typename InputIterator>
    int bisect(const InputIterator begin, const InputIterator end) {
      return ::tools::lis::bisect<Strict, false>(begin, end, ::std::less<typename ::std::iterator_traits<InputIterator>::value_type>{});
    }
  }
}

#endif
