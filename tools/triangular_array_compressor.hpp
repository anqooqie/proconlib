#ifndef TOOLS_TRIANGULAR_ARRAY_COMPRESSOR_HPP
#define TOOLS_TRIANGULAR_ARRAY_COMPRESSOR_HPP

#include <cassert>
#include <functional>
#include <utility>

namespace tools {
  template <typename Compare>
  class triangular_array_compressor;

  template <>
  class triangular_array_compressor<::std::less<int>> {
    int m_size;

  public:
    triangular_array_compressor() = default;
    triangular_array_compressor(const int n) : m_size(n) {
      assert(n >= 0);
    }

    int size() const {
      return m_size;
    }

    int compress(const int i, const int j) const {
      const auto& n = this->m_size;
      assert(0 <= i && i < j && j < n);
      return (i >= (n + 1) / 2 ? (n - 1 - i) * (n - 1) - 1 : i * (n - 2) - 1) + j;
    }

    ::std::pair<int, int> decompress(const int k) const {
      const auto& n = this->m_size;
      assert(0 <= k && k < n * (n - 1) / 2);
      auto i = k / (n - 1);
      auto j = k % (n - 1);
      if (j < n - 1 - i) {
        j += i + 1;
      } else {
        i = n - 1 - i;
        ++j;
      }
      return {i, j};
    }
  };

  template <>
  class triangular_array_compressor<::std::less_equal<int>> {
    int m_size;

  public:
    triangular_array_compressor() = default;
    triangular_array_compressor(const int n) : m_size(n) {
      assert(n >= 0);
    }

    int size() const {
      return m_size;
    }

    int compress(const int i, const int j) const {
      const auto& n = this->m_size;
      assert(0 <= i && i <= j && j < n);
      return (i >= (n + 1) / 2 ? (n - 1 - i) * (n + 1) + 1 : i * n) + j;
    }

    ::std::pair<int, int> decompress(const int k) const {
      const auto& n = this->m_size;
      assert(0 <= k && k < n * (n + 1) / 2);
      auto i = k / (n + 1);
      auto j = k % (n + 1);
      if (j < n - i) {
        j += i;
      } else {
        i = n - 1 - i;
        --j;
      }
      return {i, j};
    }
  };

  template <>
  class triangular_array_compressor<::std::greater<int>> {
    int m_size;

  public:
    triangular_array_compressor() = default;
    triangular_array_compressor(const int n) : m_size(n) {
      assert(n >= 0);
    }

    int size() const {
      return m_size;
    }

    int compress(const int i, const int j) const {
      const auto& n = this->m_size;
      assert(0 <= j && j < i && i < n);
      return (i >= (n + 1) / 2 ? (n - 1 - i) * n : i * (n - 1)) + j;
    }

    ::std::pair<int, int> decompress(const int k) const {
      const auto& n = this->m_size;
      assert(0 <= k && k < n * (n - 1) / 2);
      auto i = k / (n - 1);
      auto j = k % (n - 1);
      if (i <= j) {
        j -= i;
        i = n - 1 - i;
      }
      return {i, j};
    }
  };

  template <>
  class triangular_array_compressor<::std::greater_equal<int>> {
    int m_size;

  public:
    triangular_array_compressor() = default;
    triangular_array_compressor(const int n) : m_size(n) {
      assert(n >= 0);
    }

    int size() const {
      return m_size;
    }

    int compress(const int i, const int j) const {
      const auto& n = this->m_size;
      assert(0 <= j && j <= i && i < n);
      return (i >= (n + 1) / 2 ? (n - 1 - i) * (n + 1) + n - i : i * (n + 1)) + j;
    }

    ::std::pair<int, int> decompress(const int k) const {
      const auto& n = this->m_size;
      assert(0 <= k && k < n * (n + 1) / 2);
      auto i = k / (n + 1);
      auto j = k % (n + 1);
      if (i + 1 <= j) {
        j -= i + 1;
        i = n - 1 - i;
      }
      return {i, j};
    }
  };
}

#endif
