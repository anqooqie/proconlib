#ifndef TOOLS_COMPRESSOR_HPP
#define TOOLS_COMPRESSOR_HPP

#include <algorithm>
#include <cassert>
#include <ranges>
#include <vector>
#include "tools/lower_bound.hpp"

namespace tools {
  template <typename T>
  class compressor {
    ::std::vector<T> m_sorted;

  public:
    compressor() = default;
    template <typename InputIterator>
    compressor(const InputIterator begin, const InputIterator end) : m_sorted(begin, end) {
      ::std::ranges::sort(this->m_sorted);
      this->m_sorted.erase(::std::unique(this->m_sorted.begin(), this->m_sorted.end()), this->m_sorted.end());
    }
    template <::std::ranges::range R>
    explicit compressor(R&& range) : compressor(::std::ranges::begin(range), ::std::ranges::end(range)) {
    }

    T size() const {
      return this->m_sorted.size();
    }
    T compress(const T& x) const {
      const T i = ::tools::lower_bound(this->m_sorted, x);
      assert(i < this->size());
      assert(this->m_sorted[i] == x);
      return i;
    }
    T decompress(const T& i) const {
      assert(0 <= i && i < this->size());
      return this->m_sorted[i];
    }
    bool contains(const T& x) const {
      const auto it = ::std::ranges::lower_bound(this->m_sorted, x);
      return it != this->m_sorted.end() && *it == x;
    }

    typename ::std::vector<T>::const_iterator begin() const {
      return this->m_sorted.begin();
    }
    typename ::std::vector<T>::const_iterator end() const {
      return this->m_sorted.end();
    }
  };
}

#endif
