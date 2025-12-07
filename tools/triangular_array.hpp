#ifndef TOOLS_TRIANGULAR_ARRAY_HPP
#define TOOLS_TRIANGULAR_ARRAY_HPP

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
#include "tools/triangular_array_compressor.hpp"

namespace tools {
  template <typename T, typename Compare>
  class triangular_array;

  template <typename T>
  class triangular_array<T, std::less<int>> {
    tools::triangular_array_compressor<std::less<int>> m_comp;
    std::vector<T> m_data;
  
  public:
    triangular_array() = default;
    triangular_array(const int n) : m_comp(n), m_data(n * (n - 1) / 2) {
      assert(n >= 0);
    }
    triangular_array(const int n, const T& value) : m_comp(n), m_data(n * (n - 1) / 2, value) {
      assert(n >= 0);
    }

    int size() const {
      return this->m_comp.size();
    }

    std::vector<T>::iterator operator[](const int i) {
      assert(0 <= i && i + 1 < this->size());
      return std::next(this->m_data.begin(), this->m_comp.compress(i, i + 1) - (i + 1));
    }
    std::vector<T>::const_iterator operator[](const int i) const {
      assert(0 <= i && i + 1 < this->size());
      return std::next(this->m_data.begin(), this->m_comp.compress(i, i + 1) - (i + 1));
    }

    friend std::istream& operator>>(std::istream& is, tools::triangular_array<T, std::less<int>>& self) {
      for (int i = 0; i + 1 < self.size(); ++i) {
        std::copy_n(std::istream_iterator<T>(is), self.size() - 1 - i, std::next(self.m_data.begin(), self.m_comp.compress(i, i + 1)));
      }
      return is;
    }
  };

  template <typename T>
  class triangular_array<T, std::less_equal<int>> {
    tools::triangular_array_compressor<std::less_equal<int>> m_comp;
    std::vector<T> m_data;
  
  public:
    triangular_array() = default;
    triangular_array(const int n) : m_comp(n), m_data(n * (n + 1) / 2) {
      assert(n >= 0);
    }
    triangular_array(const int n, const T& value) : m_comp(n), m_data(n * (n + 1) / 2, value) {
      assert(n >= 0);
    }

    int size() const {
      return this->m_comp.size();
    }

    std::vector<T>::iterator operator[](const int i) {
      assert(0 <= i && i < this->size());
      return std::next(this->m_data.begin(), this->m_comp.compress(i, i) - i);
    }
    std::vector<T>::const_iterator operator[](const int i) const {
      assert(0 <= i && i < this->size());
      return std::next(this->m_data.begin(), this->m_comp.compress(i, i) - i);
    }

    friend std::istream& operator>>(std::istream& is, tools::triangular_array<T, std::less_equal<int>>& self) {
      for (int i = 0; i < self.size(); ++i) {
        std::copy_n(std::istream_iterator<T>(is), self.size() - i, std::next(self.m_data.begin(), self.m_comp.compress(i, i)));
      }
      return is;
    }
  };

  template <typename T>
  class triangular_array<T, std::greater<int>> {
    tools::triangular_array_compressor<std::greater<int>> m_comp;
    std::vector<T> m_data;
  
  public:
    triangular_array() = default;
    triangular_array(const int n) : m_comp(n), m_data(n * (n - 1) / 2) {
      assert(n >= 0);
    }
    triangular_array(const int n, const T& value) : m_comp(n), m_data(n * (n - 1) / 2, value) {
      assert(n >= 0);
    }

    int size() const {
      return this->m_comp.size();
    }

    std::vector<T>::iterator operator[](const int i) {
      assert(1 <= i && i < this->size());
      return std::next(this->m_data.begin(), this->m_comp.compress(i, 0));
    }
    std::vector<T>::const_iterator operator[](const int i) const {
      assert(1 <= i && i < this->size());
      return std::next(this->m_data.begin(), this->m_comp.compress(i, 0));
    }

    friend std::istream& operator>>(std::istream& is, tools::triangular_array<T, std::greater<int>>& self) {
      for (int i = 1; i < self.size(); ++i) {
        std::copy_n(std::istream_iterator<T>(is), i, self[i]);
      }
      return is;
    }
  };

  template <typename T>
  class triangular_array<T, std::greater_equal<int>> {
    tools::triangular_array_compressor<std::greater_equal<int>> m_comp;
    std::vector<T> m_data;
  
  public:
    triangular_array() = default;
    triangular_array(const int n) : m_comp(n), m_data(n * (n + 1) / 2) {
      assert(n >= 0);
    }
    triangular_array(const int n, const T& value) : m_comp(n), m_data(n * (n + 1) / 2, value) {
      assert(n >= 0);
    }

    int size() const {
      return this->m_comp.size();
    }

    std::vector<T>::iterator operator[](const int i) {
      assert(0 <= i && i < this->size());
      return std::next(this->m_data.begin(), this->m_comp.compress(i, 0));
    }
    std::vector<T>::const_iterator operator[](const int i) const {
      assert(0 <= i && i < this->size());
      return std::next(this->m_data.begin(), this->m_comp.compress(i, 0));
    }

    friend std::istream& operator>>(std::istream& is, tools::triangular_array<T, std::greater_equal<int>>& self) {
      for (int i = 0; i < self.size(); ++i) {
        std::copy_n(std::istream_iterator<T>(is), i + 1, self[i]);
      }
      return is;
    }
  };
}

#endif
