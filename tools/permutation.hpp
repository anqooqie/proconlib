#ifndef TOOLS_PERMUTATION_HPP
#define TOOLS_PERMUTATION_HPP

#include <vector>
#include <cstddef>
#include <numeric>
#include <cassert>
#include <utility>
#include <iostream>
#include <string>

namespace tools {
  template <typename T>
  class permutation {
  private:
    ::std::vector<T> m_vector;

  public:
    permutation() = default;
    permutation(const ::tools::permutation<T>&) = default;
    permutation(::tools::permutation<T>&&) = default;
    ~permutation() = default;
    ::tools::permutation<T>& operator=(const ::tools::permutation<T>&) = default;
    ::tools::permutation<T>& operator=(::tools::permutation<T>&&) = default;

    permutation(::std::size_t dim) : m_vector(dim) {
      ::std::iota(this->m_vector.begin(), this->m_vector.end(), 0);
    }

    T operator[](const ::std::size_t i) const {
      assert(i < this->size());
      return this->m_vector[i];
    }
    typename ::std::vector<T>::const_iterator begin() const {
      return this->m_vector.begin();
    }
    typename ::std::vector<T>::const_iterator end() const {
      return this->m_vector.end();
    }

    ::std::size_t size() const {
      return this->m_vector.size();
    }

    void swap(const ::std::size_t i, const ::std::size_t j) {
      assert(i < this->size());
      assert(j < this->size());
      ::std::swap(this->m_vector[i], this->m_vector[j]);
    }

    ::tools::permutation<T> inv() const {
      ::tools::permutation<T> result(this->size());
      for (::std::size_t i = 0; i < this->size(); ++i) {
        result.m_vector[this->m_vector[i]] = i;
      }
      return result;
    }

    friend ::tools::permutation<T> operator*(const ::tools::permutation<T>& lhs, const ::tools::permutation<T>& rhs) {
      assert(lhs.size() == rhs.size());
      ::tools::permutation<T> result(lhs.size());
      for (::std::size_t i = 0; i < lhs.size(); ++i) {
        result.m_vector[i] = rhs.m_vector[lhs.m_vector[i]];
      }
      return result;
    }
    friend bool operator==(const ::tools::permutation<T>& lhs, const ::tools::permutation<T>& rhs) {
      return lhs.m_vector == rhs.m_vector;
    }
    friend bool operator!=(const ::tools::permutation<T>& lhs, const ::tools::permutation<T>& rhs) {
      return !(lhs == rhs);
    }

    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::permutation<T>& self) {
      os << '(';
      ::std::string delimiter = "";
      for (const T& value : self.m_vector) {
        os << delimiter << value;
        delimiter = ", ";
      }
      return os << ')';
    }
    friend ::std::istream& operator>>(::std::istream& is, ::tools::permutation<T>& self) {
      for (T& value : self.m_vector) {
        is >> value;
      }
      return is;
    }
  };
}

#endif
