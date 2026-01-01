#ifndef TOOLS_RANGE_COUNT_DISTINCT_HPP
#define TOOLS_RANGE_COUNT_DISTINCT_HPP

#include <cassert>
#include <concepts>
#include <iterator>
#include <limits>
#include <ranges>
#include <utility>
#include <vector>
#include "tools/compressed.hpp"
#include "tools/mex.hpp"
#include "tools/wavelet_matrix.hpp"

namespace tools {
  class range_count_distinct {
    int m_size;
    tools::wavelet_matrix<int> m_wm;

  public:
    range_count_distinct() = default;
    template <std::ranges::input_range R>
    requires std::totally_ordered<std::ranges::range_value_t<R>>
    range_count_distinct(R&& r) {
      const auto seq = tools::compressed<int>(std::forward<R>(r));
      this->m_size = seq.size();

      const int NONE = -1;
      std::vector<int> prev(tools::mex(seq), NONE);
      for (int i = 0; i < std::ssize(seq); ++i) {
        if (prev[seq[i]] != NONE) {
          this->m_wm.add_point(prev[seq[i]], i);
        }
        prev[seq[i]] = i;
      }

      this->m_wm.build();
    }

    int size() const {
      return this->m_size;
    }

    int query(const int l, const int r) const {
      assert(0 <= l && l <= r && r <= this->size());

      return (r - l) - this->m_wm.range_freq(l, std::numeric_limits<int>::max(), r);
    }
  };
}

#endif
