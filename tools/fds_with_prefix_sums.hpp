#ifndef TOOLS_FDS_WITH_PREFIX_SUMS_HPP
#define TOOLS_FDS_WITH_PREFIX_SUMS_HPP

#include <algorithm>
#include <cassert>
#include <concepts>
#include <cstddef>
#include <iterator>
#include <numeric>
#include <ranges>
#include <type_traits>
#include <utility>
#include <vector>
#include "tools/floor_sqrt.hpp"
#include "tools/modint_compatible.hpp"

namespace tools {
  template <::tools::modint_compatible M>
  class fds_with_prefix_sums {
    using F = ::tools::fds_with_prefix_sums<M>;
    long long m_N;
    ::std::vector<M> m_lo;
    ::std::vector<M> m_hi;

    long long sqrt_N() const {
      return this->m_lo.size() - 1;
    }
    long long hi_max() const {
      return this->m_hi.size() - 1;
    }

  public:
    class iterator {
      const F *m_parent;
      ::std::size_t m_i;

    public:
      using reference = const M&;
      using value_type = M;
      using difference_type = ::std::ptrdiff_t;
      using pointer = const M*;
      using iterator_category = ::std::random_access_iterator_tag;

      iterator() = default;
      iterator(const F * const parent, const ::std::size_t i) : m_parent(parent), m_i(i) {
      }

      reference operator*() const {
        if (this->m_i + 1 < this->m_parent->m_lo.size()) {
          return this->m_parent->m_lo[this->m_i + 1];
        } else {
          return this->m_parent->m_hi[this->m_parent->m_lo.size() + this->m_parent->m_hi.size() - this->m_i - 2];
        }
      }
      pointer operator->() const {
        return &(*(*this));
      }

      iterator& operator++() {
        ++this->m_i;
        return *this;
      }
      iterator operator++(int) {
        const auto self = *this;
        ++*this;
        return self;
      }
      iterator& operator--() {
        --this->m_i;
        return *this;
      }
      iterator operator--(int) {
        const auto self = *this;
        --*this;
        return self;
      }
      iterator& operator+=(const difference_type n) {
        this->m_i += n;
        return *this;
      }
      iterator& operator-=(const difference_type n) {
        this->m_i -= n;
        return *this;
      }
      friend iterator operator+(const iterator self, const difference_type n) {
        return iterator(self.m_parent, self.m_i + n);
      }
      friend iterator operator+(const difference_type n, const iterator self) {
        return self + n;
      }
      friend iterator operator-(const iterator self, const difference_type n) {
        return iterator(self.m_parent, self.m_i - n);
      }
      friend difference_type operator-(const iterator lhs, const iterator rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return static_cast<difference_type>(lhs.m_i) - static_cast<difference_type>(rhs.m_i);
      }
      reference operator[](const difference_type n) const {
        return *(*this + n);
      }

      friend bool operator==(const iterator lhs, const iterator rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return lhs.m_i == rhs.m_i;
      }
      friend bool operator!=(const iterator lhs, const iterator rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return lhs.m_i != rhs.m_i;
      }
      friend bool operator<(const iterator lhs, const iterator rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return lhs.m_i < rhs.m_i;
      }
      friend bool operator<=(const iterator lhs, const iterator rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return lhs.m_i <= rhs.m_i;
      }
      friend bool operator>(const iterator lhs, const iterator rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return lhs.m_i > rhs.m_i;
      }
      friend bool operator>=(const iterator lhs, const iterator rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return lhs.m_i >= rhs.m_i;
      }
    };
    using reverse_iterator = ::std::reverse_iterator<iterator>;

    fds_with_prefix_sums() = default;
    explicit fds_with_prefix_sums(const long long N) : fds_with_prefix_sums(N, [](long long) { return M::raw(0); }) {
    }
    template <typename PrefixSumFunction>
    requires ::std::regular_invocable<PrefixSumFunction, long long>
          && ::std::assignable_from<M&, ::std::invoke_result_t<PrefixSumFunction, long long>>
    fds_with_prefix_sums(const long long N, const PrefixSumFunction& sum) : m_N(N) {
      assert(N >= 1);
      const auto sqrt_N = ::tools::floor_sqrt(N);
      this->m_lo.reserve(sqrt_N + 1);
      this->m_lo.push_back(M::raw(0));
      for (long long i = 1; i <= sqrt_N; ++i) {
        this->m_lo.push_back(sum(i));
      }
      const auto hi_max = sqrt_N - (N < sqrt_N * (sqrt_N + 1));
      this->m_hi.reserve(hi_max + 1);
      this->m_hi.push_back(M::raw(0));
      for (long long i = 1; i <= hi_max; ++i) {
        this->m_hi.push_back(sum(N / i));
      }
    }
    template <::std::ranges::input_range R>
    requires ::std::assignable_from<M&, ::std::ranges::range_value_t<R>>
    fds_with_prefix_sums(const long long N, R&& v) : m_N(N) {
      assert(N >= 1);
      const auto sqrt_N = ::tools::floor_sqrt(N);
      this->m_lo.resize(sqrt_N + 1);
      this->m_lo[0] = M::raw(0);
      const auto hi_max = sqrt_N - (N < sqrt_N * (sqrt_N + 1));
      this->m_hi.resize(hi_max + 1);
      this->m_hi[0] = M::raw(0);
      ::std::ranges::copy_n(::std::ranges::copy_n(::std::ranges::begin(v), sqrt_N, ::std::next(this->m_lo.begin())).in, hi_max, this->m_hi.rbegin());
    }

    iterator begin() const {
      return iterator(this, 0);
    }
    iterator end() const {
      return iterator(this, this->sqrt_N() + this->hi_max());
    }
    reverse_iterator rbegin() const {
      return ::std::make_reverse_iterator(this->end());
    }
    reverse_iterator rend() const {
      return ::std::make_reverse_iterator(this->begin());
    }

    F operator+() const {
      return *this;
    }
    F operator-() const {
      F g(this->m_N);
      for (int i = 1; i <= this->sqrt_N(); ++i) {
        g.m_lo[i] = -this->m_lo[i];
      }
      for (int i = 1; i <= this->hi_max(); ++i) {
        g.m_hi[i] = -this->m_hi[i];
      }
      return g;
    }

    F& operator+=(const F& g) {
      assert(this->m_N == g.m_N);
      for (int i = 1; i <= this->sqrt_N(); ++i) {
        this->m_lo[i] += g.m_lo[i];
      }
      for (int i = 1; i <= this->hi_max(); ++i) {
        this->m_hi[i] += g.m_hi[i];
      }
      return *this;
    }
    friend F operator+(const F& f, const F& g) {
      return F(f) += g;
    }

    F& operator-=(const F& g) {
      assert(this->m_N == g.m_N);
      for (int i = 1; i <= this->sqrt_N(); ++i) {
        this->m_lo[i] -= g.m_lo[i];
      }
      for (int i = 1; i <= this->hi_max(); ++i) {
        this->m_hi[i] -= g.m_hi[i];
      }
      return *this;
    }
    friend F operator-(const F& f, const F& g) {
      return F(f) -= g;
    }

    F& operator*=(const M& g) {
      return *this = *this * g;
    }
    friend F operator*(const F& f, const F& g) {
      assert(f.m_N == g.m_N);
      const auto hi_max = f.hi_max();

      F h(f.m_N);
      h.m_hi.resize(hi_max + 3);

      for (int i = 1; i <= h.sqrt_N(); ++i) {
        for (int j = 1; i * j <= h.sqrt_N(); ++j) {
          h.m_lo[i * j] += (f.m_lo[i] - f.m_lo[i - 1]) * (g.m_lo[j] - g.m_lo[j - 1]);
        }
      }
      for (int k = 1; k <= h.sqrt_N(); ++k) {
        h.m_lo[k] += h.m_lo[k - 1];
      }

      const auto apply = [&](const long long z_1, const long long z_2, const M d) {
        h.m_hi[z_1] += d;
        h.m_hi[z_2 + 1] -= d;
      };
      for (long long i = 1; i * (i + 1) * (i + 1) <= h.m_N; ++i) {
        for (long long j = i + 1; i * j * j <= h.m_N; ++j) {
          apply(j, std::min(h.m_N / (i * j), hi_max + 1), (f.m_lo[i] - f.m_lo[i - 1]) * (g.m_lo[j] - g.m_lo[j - 1]));
          apply(j, j, ((i * j <= hi_max ? f.m_hi[i * j] : f.m_lo[h.m_N / (i * j)]) - f.m_lo[j - 1]) * (g.m_lo[i] - g.m_lo[i - 1]));
          apply(i, i, (f.m_lo[j] - f.m_lo[j - 1]) * ((i * j <= hi_max ? g.m_hi[i * j] : g.m_lo[h.m_N / (i * j)]) - g.m_lo[j - 1]));
        }
      }
      for (long long i = 1; i * i * (i + 1) <= h.m_N; ++i) {
        for (long long j = i; i * j * (j + 1) <= h.m_N; ++j) {
          apply(i, i, ((i * j <= hi_max ? f.m_hi[i * j] : f.m_lo[h.m_N / (i * j)]) - f.m_lo[j]) * (g.m_lo[j] - g.m_lo[j - 1]));
          apply(j, j, (f.m_lo[i] - f.m_lo[i - 1]) * ((i * j <= hi_max ? g.m_hi[i * j] : g.m_lo[h.m_N / (i * j)]) - g.m_lo[j]));
          apply(j + 1, std::min(h.m_N / (i * j), hi_max + 1), (f.m_lo[j] - f.m_lo[j - 1]) * (g.m_lo[i] - g.m_lo[i - 1]));
        }
      }
      for (long long i = 1; i * i * i <= h.m_N; ++i) {
        apply(i, i, (f.m_lo[i] - f.m_lo[i - 1]) * (g.m_lo[i] - g.m_lo[i - 1]));
      }
      for (int i = 1; i <= hi_max; ++i) {
        h.m_hi[i] += h.m_hi[i - 1];
      }
      h.m_hi.erase(h.m_hi.end() - 2, h.m_hi.end());

      return h;
    }

    F& operator/=(const F& g) {
      assert(this->m_N == g.m_N);
      assert(::std::gcd(g.m_lo[1].val(), M::mod()) == 1);
      const auto g1_inv = g.m_lo[1].inv();
      const auto hi_max = this->hi_max();

      for (int i = this->sqrt_N(); i >= 1; --i) {
        this->m_lo[i] -= this->m_lo[i - 1];
      }
      for (int i = hi_max; i >= 1; --i) {
        this->m_hi[i] -= this->m_hi[i - 1];
      }
      this->m_hi.resize(hi_max + 3);

      for (int i = 1; i <= this->sqrt_N(); ++i) {
        this->m_lo[i] *= g1_inv;
        for (int j = 2; i * j <= this->sqrt_N(); ++j) {
          this->m_lo[i * j] -= (g.m_lo[j] - g.m_lo[j - 1]) * this->m_lo[i];
        }
      }
      for (int i = 1; i <= this->sqrt_N(); ++i) {
        this->m_lo[i] += this->m_lo[i - 1];
      }

      const auto apply = [&](const long long z_1, const long long z_2, const M d) {
        this->m_hi[z_1] -= d;
        this->m_hi[z_2 + 1] += d;
      };
      for (long long i = 1; i * (i + 1) * (i + 1) <= this->m_N; ++i) {
        for (long long j = i + 1; i * j * j <= this->m_N; ++j) {
          apply(j, ::std::min(this->m_N / (i * j), hi_max + 1), (g.m_lo[i] - g.m_lo[i - 1]) * (this->m_lo[j] - this->m_lo[j - 1]));
          apply(j, j, ((i * j <= hi_max ? g.m_hi[i * j] : g.m_lo[this->m_N / (i * j)]) - g.m_lo[j - 1]) * (this->m_lo[i] - this->m_lo[i - 1]));
        }
      }
      for (long long i = 1; i * i * (i + 1) <= this->m_N; ++i) {
        for (long long j = i; i * j * (j + 1) <= this->m_N; ++j) {
          apply(i, i, ((i * j <= hi_max ? g.m_hi[i * j] : g.m_lo[this->m_N / (i * j)]) - g.m_lo[j]) * (this->m_lo[j] - this->m_lo[j - 1]));
          apply(j + 1, ::std::min(this->m_N / (i * j), hi_max + 1), (g.m_lo[j] - g.m_lo[j - 1]) * (this->m_lo[i] - this->m_lo[i - 1]));
        }
      }
      for (long long i = 1; i * i * i <= this->m_N; ++i) {
        apply(i, i, (g.m_lo[i] - g.m_lo[i - 1]) * (this->m_lo[i] - this->m_lo[i - 1]));
      }
      for (int i = 1; i <= hi_max; ++i) {
        this->m_hi[i] += this->m_hi[i - 1];
      }
      this->m_hi.erase(this->m_hi.end() - 2, this->m_hi.end());

      for (auto b = hi_max; b >= 1; --b) {
        for (auto j = b + 1; j * j <= this->m_N / b; ++j) {
          this->m_hi[b] -= (g.m_lo[j] - g.m_lo[j - 1]) * ((b * j <= hi_max ? this->m_hi[b * j] : this->m_lo[this->m_N / (b * j)]) - this->m_lo[j - 1]);
        }
        for (long long i = 2; i <= b && i * b * (b + 1) <= this->m_N; ++i) {
          this->m_hi[b] -= (g.m_lo[i] - g.m_lo[i - 1]) * ((i * b <= hi_max ? this->m_hi[i * b] : this->m_lo[this->m_N / (i * b)]) - this->m_lo[b]);
        }
        this->m_hi[b] += g.m_lo[1] * this->m_lo[b];
        this->m_hi[b] *= g1_inv;
      }

      return *this;
    }
    friend F operator/(const F& f, const F& g) {
      return F(f) /= g;
    }
  };
}

#endif
