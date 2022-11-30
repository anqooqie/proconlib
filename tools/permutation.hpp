#ifndef TOOLS_PERMUTATION_HPP
#define TOOLS_PERMUTATION_HPP

#include <vector>
#include <cassert>
#include <cstddef>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <utility>
#include <iostream>
#include <string>

namespace tools {
  template <typename T>
  class permutation {
  private:
    ::std::vector<T> m_perm;
    ::std::vector<T> m_inv;

    void verify_consistency() const {
#ifndef NDEBUG
      ::std::vector<bool> unique(this->m_perm.size(), true);
      for (const T x : this->m_perm) {
        assert(0 <= x && x < T(this->m_perm.size()));
        assert(unique[x]);
        unique[x] = false;
      }
#endif
    }

    void make_inv() {
      this->m_inv.resize(this->m_perm.size());
      for (::std::size_t i = 0; i < this->m_perm.size(); ++i) {
        this->m_inv[this->m_perm[i]] = i;
      }
    }

  public:
    permutation() = default;
    permutation(const ::tools::permutation<T>&) = default;
    permutation(::tools::permutation<T>&&) = default;
    ~permutation() = default;
    ::tools::permutation<T>& operator=(const ::tools::permutation<T>&) = default;
    ::tools::permutation<T>& operator=(::tools::permutation<T>&&) = default;

    explicit permutation(::std::size_t n) : m_perm(n), m_inv(n) {
      ::std::iota(this->m_perm.begin(), this->m_perm.end(), 0);
      ::std::iota(this->m_inv.begin(), this->m_inv.end(), 0);
    }
    template <typename Iterator>
    permutation(Iterator begin, Iterator end) : m_perm(begin, end) {
      this->verify_consistency();
      this->make_inv();
    }

    ::std::size_t size() const {
      return this->m_perm.size();
    }
    T operator[](const ::std::size_t i) const {
      assert(i < this->size());
      return this->m_perm[i];
    }
    typename ::std::vector<T>::const_iterator begin() const {
      return this->m_perm.begin();
    }
    typename ::std::vector<T>::const_iterator end() const {
      return this->m_perm.end();
    }

    ::tools::permutation<T>& swap_from_left(const T x, const T y) {
      assert(0 <= x && x < T(this->size()));
      assert(0 <= y && y < T(this->size()));
      this->m_inv[this->m_perm[y]] = x;
      this->m_inv[this->m_perm[x]] = y;
      ::std::swap(this->m_perm[x], this->m_perm[y]);
      return *this;
    }
    ::tools::permutation<T>& swap_from_right(const T x, const T y) {
      assert(0 <= x && x < T(this->size()));
      assert(0 <= y && y < T(this->size()));
      this->m_perm[this->m_inv[y]] = x;
      this->m_perm[this->m_inv[x]] = y;
      ::std::swap(this->m_inv[x], this->m_inv[y]);
      return *this;
    }

    T id() const {
      if (this->size() == 0) return 0;

      ::std::vector<T> left(this->size());
      ::std::iota(left.begin(), left.end(), 0);

      ::std::vector<T> fact(this->size());
      fact[0] = 1;
      for (::std::size_t i = 1; i < this->size(); ++i) {
        fact[i] = fact[i - 1] * i;
      }

      T id = 0;
      for (::std::size_t i = 0; i < this->size(); ++i) {
        auto it = ::std::lower_bound(left.begin(), left.end(), this->m_perm[i]);
        id += ::std::distance(left.begin(), it) * fact[this->m_perm.size() - 1 - i];
        left.erase(it);
      }

      return id;
    }

    static ::tools::permutation<T> from(const ::std::size_t n, T id) {
      if (n == 0) return ::tools::permutation<T>(0);

      ::std::vector<T> left(n);
      ::std::iota(left.begin(), left.end(), 0);

      ::std::vector<T> fact(n);
      fact[0] = 1;
      for (::std::size_t i = 1; i < n; ++i) {
        fact[i] = fact[i - 1] * i;
      }

      ::std::vector<T> p;
      for (::std::size_t i = 0; i < n; ++i) {
        auto it = ::std::next(left.begin(), id / fact[n - i - 1]);
        p.push_back(*it);
        left.erase(it);
        id %= fact[n - i - 1];
      }

      return ::tools::permutation<T>(p.begin(), p.end());
    }

    ::tools::permutation<T> inv() const {
      return ::tools::permutation<T>(this->m_inv.begin(), this->m_inv.end());
    }
    ::tools::permutation<T>& inv_inplace() {
      this->m_perm.swap(this->m_inv);
      return *this;
    }

    ::tools::permutation<T>& operator*=(const ::tools::permutation<T>& other) {
      assert(this->size() == other.size());
      for (::std::size_t i = 0; i < this->size(); ++i) {
        this->m_inv[i] = other.m_perm[this->m_perm[i]];
      }
      this->m_perm.swap(this->m_inv);
      this->make_inv();
      return *this;
    }
    friend ::tools::permutation<T> operator*(const ::tools::permutation<T>& lhs, const ::tools::permutation<T>& rhs) {
      return ::tools::permutation<T>(lhs) *= rhs;
    }

    friend bool operator==(const ::tools::permutation<T>& lhs, const ::tools::permutation<T>& rhs) {
      return lhs.m_perm == rhs.m_perm;
    }
    friend bool operator!=(const ::tools::permutation<T>& lhs, const ::tools::permutation<T>& rhs) {
      return lhs.m_perm != rhs.m_perm;
    }

    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::permutation<T>& self) {
      os << '(';
      ::std::string delimiter = "";
      for (const T value : self.m_perm) {
        os << delimiter << value;
        delimiter = ", ";
      }
      return os << ')';
    }
    friend ::std::istream& operator>>(::std::istream& is, ::tools::permutation<T>& self) {
      for (T& value : self.m_perm) {
        is >> value;
      }
      self.verify_consistency();
      self.make_inv();
      return is;
    }
  };
}

#endif
