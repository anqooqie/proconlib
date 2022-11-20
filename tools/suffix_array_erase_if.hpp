#ifndef TOOLS_SUFFIX_ARRAY_ERASE_IF_HPP
#define TOOLS_SUFFIX_ARRAY_ERASE_IF_HPP

#include <utility>
#include <cstddef>
#include <cassert>
#include <algorithm>

namespace tools {
  template <typename RandomAccessIterator, typename Predicate>
  ::std::pair<RandomAccessIterator, RandomAccessIterator> suffix_array_erase_if(
      const RandomAccessIterator sa,
      const RandomAccessIterator sa_end,
      const RandomAccessIterator lcpa,
      const RandomAccessIterator lcpa_end,
      const Predicate pred
  ) {
    const ::std::size_t N = sa_end - sa;
    assert(N >= 1);
    assert(static_cast<::std::size_t>(lcpa_end - lcpa) + 1 == N);

    ::std::size_t sa_vl = 0, lcpa_vl = 0;
    for (::std::size_t sa_vr = 0, sa_al = 0, sa_ar = 0, lcpa_vr = 0; sa_al < N; sa_vl = sa_vr, sa_al = sa_ar, lcpa_vl = lcpa_vr) {
      const bool removes = pred(sa[sa_al]);

      for (; sa_ar < N && removes == pred(sa[sa_ar]); ++sa_vr, ++sa_ar);
      if (sa_vl < sa_al) ::std::move(sa + sa_al, sa + sa_ar, sa + sa_vl);

      const auto lcpa_al = sa_al == 0 ? 0 : sa_al - removes;
      const auto lcpa_ar = ::std::min(sa_ar - !removes, N - 1);
      lcpa_vr = lcpa_vl + (lcpa_ar - lcpa_al);
      if (lcpa_vl < lcpa_al) ::std::move(lcpa + lcpa_al, lcpa + lcpa_ar, lcpa + lcpa_vl);

      if (removes) {
        sa_vr = sa_vl;
        if (0 < sa_al && sa_ar < N) {
          lcpa[lcpa_vl] = *::std::min_element(lcpa + lcpa_vl, lcpa + lcpa_vr);
          lcpa_vr = lcpa_vl + 1;
        } else {
          lcpa_vr = lcpa_vl;
        }
      }
    }

    return ::std::make_pair(sa + sa_vl, lcpa + lcpa_vl);
  }
}

#endif
