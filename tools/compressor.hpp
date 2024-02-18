#ifndef TOOLS_COMPRESSOR_HPP
#define TOOLS_COMPRESSOR_HPP

#include <vector>
#include <algorithm>
#include <cassert>
#include "tools/lower_bound.hpp"

namespace tools {
  template <typename T>
  class compressor {
  private:
    ::std::vector<T> m_sorted;

  public:
    compressor() = default;
    compressor(const ::tools::compressor<T>&) = default;
    compressor(::tools::compressor<T>&&) = default;
    ~compressor() = default;
    ::tools::compressor<T>& operator=(const ::tools::compressor<T>&) = default;
    ::tools::compressor<T>& operator=(::tools::compressor<T>&&) = default;

    template <typename InputIterator>
    compressor(InputIterator begin, InputIterator end) : m_sorted(begin, end) {
      ::std::sort(this->m_sorted.begin(), this->m_sorted.end());
      this->m_sorted.erase(::std::unique(this->m_sorted.begin(), this->m_sorted.end()), this->m_sorted.end());
    }
    explicit compressor(const ::std::vector<T>& v) : compressor(v.begin(), v.end()) {
    }

    T size() const {
      return this->m_sorted.size();
    }
    T compress(const T& x) const {
      const T i = ::tools::lower_bound(this->m_sorted.begin(), this->m_sorted.end(), x);
      assert(i < this->size());
      assert(this->m_sorted[i] == x);
      return i;
    }
    T decompress(const T& i) const {
      assert(0 <= i && i < this->size());
      return this->m_sorted[i];
    }

    auto begin() {
      return this->m_sorted.cbegin();
    }
    auto begin() const {
      return this->m_sorted.cbegin();
    }
    auto end() {
      return this->m_sorted.cend();
    }
    auto end() const {
      return this->m_sorted.cend();
    }
  };
}

#endif
