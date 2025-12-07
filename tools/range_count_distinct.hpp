#ifndef TOOLS_RANGE_COUNT_DISTINCT_HPP
#define TOOLS_RANGE_COUNT_DISTINCT_HPP

#include <cassert>
#include <cstddef>
#include <iterator>
#include <limits>
#include <ranges>
#include <vector>
#include "tools/wavelet_matrix.hpp"
#include "tools/compress.hpp"
#include "tools/mex.hpp"

namespace tools {
  class range_count_distinct {
  private:
    std::size_t m_size;
    tools::wavelet_matrix<std::size_t> m_wm;

  public:
    range_count_distinct() = default;
    range_count_distinct(const tools::range_count_distinct&) = default;
    range_count_distinct(tools::range_count_distinct&&) = default;
    ~range_count_distinct() = default;
    tools::range_count_distinct& operator=(const tools::range_count_distinct&) = default;
    tools::range_count_distinct& operator=(tools::range_count_distinct&&) = default;

    template <typename InputIterator>
    range_count_distinct(const InputIterator begin, const InputIterator end) {
      std::vector<std::size_t> seq;
      tools::compress(std::ranges::subrange(begin, end), std::back_inserter(seq));
      this->m_size = seq.size();

      const auto NONE = std::numeric_limits<std::size_t>::max();
      std::vector<std::size_t> prev(tools::mex(seq.begin(), seq.end()), NONE);
      for (std::size_t i = 0; i < seq.size(); ++i) {
        if (prev[seq[i]] != NONE) {
          this->m_wm.add_point(prev[seq[i]], i);
        }
        prev[seq[i]] = i;
      }

      this->m_wm.build();
    }

    std::size_t size() const {
      return this->m_size;
    }

    std::size_t query(std::size_t l, std::size_t r) const {
      assert(l <= r && r <= this->size());

      return (r - l) - this->m_wm.range_freq(l, std::numeric_limits<std::size_t>::max(), r);
    }
  };
}

#endif
