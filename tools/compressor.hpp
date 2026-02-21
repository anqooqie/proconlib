#ifndef TOOLS_COMPRESSOR_HPP
#define TOOLS_COMPRESSOR_HPP

#include <algorithm>
#include <cassert>
#include <concepts>
#include <ranges>
#include <utility>
#include <vector>
#include "tools/lower_bound.hpp"

namespace tools {
  template <typename T>
  requires std::sortable<typename std::vector<T>::iterator>
        && std::equality_comparable<T>
  class compressor {
    std::vector<T> m_sorted;

  public:
    compressor() = default;
    template <std::ranges::input_range R>
    requires std::constructible_from<T, std::ranges::range_reference_t<R>>
    explicit compressor(R&& range) : m_sorted(std::forward<R>(range) | std::ranges::to<std::vector<T>>()) {
      std::ranges::sort(this->m_sorted);
      this->m_sorted.erase(std::unique(this->m_sorted.begin(), this->m_sorted.end()), this->m_sorted.end());
    }

    int size() const {
      return this->m_sorted.size();
    }
    int compress(const T& x) const {
      const int i = tools::lower_bound(this->m_sorted, x);
      assert(i < this->size());
      assert(this->m_sorted[i] == x);
      return i;
    }
    T decompress(const int i) const {
      assert(0 <= i && i < this->size());
      return this->m_sorted[i];
    }
    bool contains(const T& x) const {
      const auto it = std::ranges::lower_bound(this->m_sorted, x);
      return it != this->m_sorted.end() && *it == x;
    }

    typename std::vector<T>::const_iterator begin() const {
      return this->m_sorted.begin();
    }
    typename std::vector<T>::const_iterator end() const {
      return this->m_sorted.end();
    }
  };

  template <std::ranges::input_range R>
  requires std::sortable<typename std::vector<std::ranges::range_value_t<R>>::iterator>
        && std::equality_comparable<std::ranges::range_value_t<R>>
        && std::constructible_from<std::ranges::range_value_t<R>, std::ranges::range_reference_t<R>>
  compressor(R&&) -> compressor<std::ranges::range_value_t<R>>;
}

#endif
