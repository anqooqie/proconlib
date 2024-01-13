#ifndef TOOLS_POLYNOMIAL_HPP
#define TOOLS_POLYNOMIAL_HPP

#include <type_traits>
#include <utility>
#include <complex>
#include <vector>
#include <cstddef>
#include <initializer_list>
#include <algorithm>
#include <cassert>
#include <iterator>
#include "atcoder/modint.hpp"
#include "tools/is_prime.hpp"
#include "tools/group.hpp"
#include "tools/monoid.hpp"
#include "tools/fps.hpp"
#include "tools/has_mod.hpp"
#include "tools/fact_mod_cache.hpp"
#include "tools/pow_mod_cache.hpp"

namespace tools {
  namespace detail {
    namespace polynomial {
      template <typename T, typename = ::std::void_t<>>
      struct can_divide : ::std::false_type {};

      template <typename T>
      struct can_divide<T, ::std::void_t<decltype(::std::declval<T>() / ::std::declval<T>())>> : ::std::true_type {};

      template <typename T>
      inline constexpr bool can_divide_v = can_divide<T>::value;

      template <typename T, typename = ::std::void_t<>>
      struct is_prime_modint : ::std::false_type {};

      template <typename T>
      struct is_prime_modint<T, ::std::enable_if_t<::atcoder::internal::is_static_modint<T>::value && ::tools::is_prime(T::mod()), void>> : ::std::true_type {};

      template <typename T>
      inline constexpr bool is_prime_modint_v = is_prime_modint<T>::value;
    }
  }

  template <typename T1, typename T2 = void>
  class polynomial {
  private:
    using AG = ::std::conditional_t<::std::is_same_v<T2, void>, ::tools::group::plus<T1>, T1>;
    using MM = ::std::conditional_t<
      ::std::is_same_v<T2, void>,
        ::std::conditional_t<
          ::std::is_same_v<T1, ::std::complex<float>> ||
          ::std::is_same_v<T1, ::std::complex<double>> ||
          ::std::is_same_v<T1, ::std::complex<long double>> ||
          ::std::is_floating_point_v<T1> ||
          ::tools::detail::polynomial::is_prime_modint_v<T1> ||
          ::atcoder::internal::is_dynamic_modint<T1>::value,
            ::tools::group::multiplies<T1>,
            ::std::conditional_t<
              ::std::is_integral_v<T1> ||
              ::atcoder::internal::is_static_modint<T1>::value,
                ::tools::monoid::multiplies<T1>,
                ::std::conditional_t<
                  ::tools::detail::polynomial::can_divide_v<T1>,
                    ::tools::group::multiplies<T1>,
                    ::tools::monoid::multiplies<T1>
                >
            >
        >,
        T2
    >;

    static_assert(::std::is_same_v<typename AG::T, typename MM::T>);
    using R = typename AG::T;
    using P = ::tools::polynomial<T1, T2>;
    ::std::vector<R> m_vector;

  public:
    using reference = R&;
    using const_reference = const R&;
    using iterator = typename ::std::vector<R>::iterator;
    using const_iterator = typename ::std::vector<R>::const_iterator;
    using size_type = ::std::size_t;
    using difference_type = ::std::ptrdiff_t;
    using value_type = R;
    using allocator_type = typename ::std::vector<R>::allocator_type;
    using pointer = R*;
    using const_pointer = const R*;
    using reverse_iterator = typename ::std::vector<R>::reverse_iterator;
    using const_reverse_iterator = typename ::std::vector<R>::const_reverse_iterator;

    polynomial() = default;
    polynomial(const P&) = default;
    polynomial(P&&) = default;
    ~polynomial() = default;
    P& operator=(const P&) = default;
    P& operator=(P&&) = default;

    explicit polynomial(const size_type n) : m_vector(n) {}
    polynomial(const size_type n, const_reference value) : m_vector(n, value) {}
    template <class InputIter> polynomial(const InputIter first, const InputIter last) : m_vector(first, last) {}
    polynomial(const ::std::initializer_list<R> il) : m_vector(il) {}

    iterator begin() noexcept { return this->m_vector.begin(); }
    const_iterator begin() const noexcept { return this->m_vector.begin(); }
    iterator end() noexcept { return this->m_vector.end(); }
    const_iterator end() const noexcept { return this->m_vector.end(); }
    const_iterator cbegin() const noexcept { return this->m_vector.cbegin(); }
    const_iterator cend() const noexcept { return this->m_vector.cend(); }
    reverse_iterator rbegin() noexcept { return this->m_vector.rbegin(); }
    const_reverse_iterator rbegin() const noexcept { return this->m_vector.rbegin(); }
    const_reverse_iterator crbegin() const noexcept { return this->m_vector.crbegin(); }
    reverse_iterator rend() noexcept { return this->m_vector.rend(); }
    const_reverse_iterator rend() const noexcept { return this->m_vector.rend(); }
    const_reverse_iterator crend() const noexcept { return this->m_vector.crend(); }

    size_type size() const noexcept { return this->m_vector.size(); }
    size_type max_size() const noexcept { return this->m_vector.max_size(); }
    void resize(const size_type sz) { this->m_vector.resize(sz); }
    void resize(const size_type sz, const R& c) { this->m_vector.resize(sz, c); }
    size_type capacity() const noexcept { return this->m_vector.capacity(); }
    bool empty() const noexcept { return this->m_vector.empty(); }
    void reserve(const size_type n) { this->m_vector.reserve(n); }
    void shrink_to_fit() { this->m_vector.shrink_to_fit(); }

    reference operator[](const size_type n) { return this->m_vector[n]; }
    const_reference operator[](const size_type n) const { return this->m_vector[n]; }
    reference at(const size_type n) { return this->m_vector.at(n); }
    const_reference at(const size_type n) const { return this->m_vector.at(n); }
    pointer data() noexcept { return this->m_vector.data(); }
    const_pointer data() const noexcept { return this->m_vector.data(); }
    reference front() { return this->m_vector.front(); }
    const_reference front() const { return this->m_vector.front(); }
    reference back() { return this->m_vector.back(); }
    const_reference back() const { return this->m_vector.back(); }

    template <class InputIterator> void assign(const InputIterator first, const InputIterator last) { this->m_vector.assign(first, last); }
    void assign(const size_type n, const R& u) { this->m_vector.assign(n, u); }
    void assign(const ::std::initializer_list<R> il) { this->m_vector.assign(il); }
    void push_back(const R& x) { this->m_vector.push_back(x); }
    void push_back(R&& x) { this->m_vector.push_back(::std::forward<R>(x)); }
    template <class... Args> reference emplace_back(Args&&... args) { return this->m_vector.emplace_back(::std::forward<Args>(args)...); }
    void pop_back() { this->m_vector.pop_back(); }
    iterator insert(const const_iterator position, const R& x) { return this->m_vector.insert(position, x); }
    iterator insert(const const_iterator position, R&& x) { return this->m_vector.insert(position, ::std::forward<R>(x)); }
    iterator insert(const const_iterator position, const size_type n, const R& x) { return this->m_vector.insert(position, n, x); }
    template <class InputIterator> iterator insert(const const_iterator position, const InputIterator first, const InputIterator last) { return this->m_vector.insert(position, first, last); }
    iterator insert(const const_iterator position, const ::std::initializer_list<R> il) { return this->m_vector.insert(position, il); }
    template <class... Args> iterator emplace(const const_iterator position, Args&&... args) { return this->m_vector.emplace(position, ::std::forward<Args>(args)...); }
    iterator erase(const const_iterator position) { return this->m_vector.erase(position); }
    iterator erase(const const_iterator first, const const_iterator last) { return this->m_vector.erase(first, last); }
    void swap(P& x) noexcept { this->m_vector.swap(x.m_vector); }
    void clear() { this->m_vector.clear(); }

    allocator_type get_allocator() const noexcept { return this->m_vector.get_allocator(); }

    friend bool operator==(const P& x, const P& y) {
      const auto n = ::std::min(x.size(), y.size());
      static const auto is_zero = [](const R& e) { return e == AG::e(); };
      return ::std::equal(x.begin(), x.begin() + n, y.begin(), y.begin() + n) && ::std::all_of(x.begin() + n, x.end(), is_zero) && ::std::all_of(y.begin() + n, y.end(), is_zero);
    }
    friend bool operator!=(const P& x, const P& y) { return !(x == y); }

    friend void swap(P& x, P& y) noexcept { x.m_vector.swap(y.m_vector); }

    class coefficient_iterator {
    private:
      const ::std::vector<R> *m_vector;
      ::std::size_t m_offset;

    public:
      using difference_type = ::std::ptrdiff_t;
      using value_type = R;
      using reference = const R&;
      using pointer = const R*;
      using iterator_category = ::std::random_access_iterator_tag;

      coefficient_iterator() = default;
      coefficient_iterator(const coefficient_iterator& other) = default;
      ~coefficient_iterator() = default;
      coefficient_iterator& operator=(const coefficient_iterator& other) = default;

      coefficient_iterator(const ::std::vector<R> * const vector, const ::std::size_t offset) :
        m_vector(vector),
        m_offset(offset) {
      }

      const R& operator*() const {
        static const R e = AG::e();
        return this->m_offset < this->m_vector->size() ? (*this->m_vector)[this->m_offset] : e;
      }

      coefficient_iterator& operator++() {
        ++this->m_offset;
        return *this;
      }
      coefficient_iterator operator++(int) {
        const auto self = *this;
        ++*this;
        return self;
      }
      coefficient_iterator& operator--() {
        --this->m_offset;
        return *this;
      }
      coefficient_iterator operator--(int) {
        const auto self = *this;
        --*this;
        return self;
      }
      coefficient_iterator& operator+=(const ::std::ptrdiff_t n) {
        this->m_offset += n;
        return *this;
      }
      coefficient_iterator& operator-=(const ::std::ptrdiff_t n) {
        this->m_offset -= n;
        return *this;
      }
      friend coefficient_iterator operator+(const coefficient_iterator& self, const ::std::ptrdiff_t n) {
        return coefficient_iterator(self.m_vector, self.m_offset + n);
      }
      friend ::std::ptrdiff_t operator-(const coefficient_iterator& lhs, const coefficient_iterator& rhs) {
        assert(lhs.m_vector == rhs.m_vector);
        return lhs.m_offset - rhs.m_offset;
      }
      const R& operator[](const ::std::ptrdiff_t n) const {
        return *(*this + n);
      }

      friend bool operator==(const coefficient_iterator& lhs, const coefficient_iterator& rhs) {
        assert(lhs.m_vector == rhs.m_vector);
        return lhs.m_offset == rhs.m_offset;
      }
      friend bool operator!=(const coefficient_iterator& lhs, const coefficient_iterator& rhs) {
        assert(lhs.m_vector == rhs.m_vector);
        return lhs.m_offset != rhs.m_offset;
      }
      friend bool operator<(const coefficient_iterator& lhs, const coefficient_iterator& rhs) {
        assert(lhs.m_vector == rhs.m_vector);
        return lhs.m_offset < rhs.m_offset;
      }
      friend bool operator<=(const coefficient_iterator& lhs, const coefficient_iterator& rhs) {
        assert(lhs.m_vector == rhs.m_vector);
        return lhs.m_offset <= rhs.m_offset;
      }
      friend bool operator>(const coefficient_iterator& lhs, const coefficient_iterator& rhs) {
        assert(lhs.m_vector == rhs.m_vector);
        return lhs.m_offset > rhs.m_offset;
      }
      friend bool operator>=(const coefficient_iterator& lhs, const coefficient_iterator& rhs) {
        assert(lhs.m_vector == rhs.m_vector);
        return lhs.m_offset >= rhs.m_offset;
      }
    };
    coefficient_iterator pbegin() const {
      return coefficient_iterator(&this->m_vector, 0);
    }

    int deg() const {
      for (size_type i = this->size(); i --> 0;) {
        if ((*this)[i] != AG::e()) return i;
      }
      return -1;
    }
    P& regularize() {
      this->resize(this->deg() + 1);
      return *this;
    }

    P operator+() const {
      return P(this->begin(), ::std::next(this->begin(), this->deg() + 1));
    }
    P operator-() const {
      P res;
      for (auto it = this->begin(), end = ::std::next(this->begin(), this->deg() + 1); it != end; ++it) {
        res.push_back(AG::inv(*it));
      }
      return res;
    }
    P& operator++() {
      if (this->empty()) {
        this->push_back(MM::e());
      } else {
        (*this)[0] = AG::op((*this)[0], MM::e());
      }
      return this->regularize();
    }
    P operator++(int) {
      const auto self = *this;
      ++*this;
      return self;
    }
    P& operator--() {
      if (this->empty()) {
        this->push_back(AG::inv(MM::e()));
      } else {
        (*this)[0] = AG::op((*this)[0], AG::inv(MM::e()));
      }
      return this->regularize();
    }
    P operator--(int) {
      const auto self = *this;
      --*this;
      return self;
    }
    P& operator*=(const R& g) {
      this->regularize();
      for (auto& e : *this) {
        e = MM::op(e, g);
      }
      return this->regularize();
    }
    P& operator/=(const R& g) {
      assert(AG::e() == MM::e() || g != AG::e());
      return *this *= MM::inv(g);
    }
    P& operator+=(const P& g) {
      const int n = this->deg() + 1;
      const int m = g.deg() + 1;
      this->resize(::std::max(n, m), AG::e());
      for (int i = 0; i < m; ++i) {
        (*this)[i] = AG::op((*this)[i], g[i]);
      }
      return this->regularize();
    }
    P& operator-=(const P& g) {
      const int n = this->deg() + 1;
      const int m = g.deg() + 1;
      this->resize(::std::max(n, m), AG::e());
      for (int i = 0; i < m; ++i) {
        (*this)[i] = AG::op((*this)[i], AG::inv(g[i]));
      }
      return this->regularize();
    }
    P& operator<<=(const int d) {
      if (d < 0) *this >>= -d;

      this->regularize();
      if (!this->empty()) {
        this->insert(this->begin(), d, AG::e());
      }
      return *this;
    }
    P& operator>>=(const int d) {
      if (d < 0) *this <<= -d;

      this->regularize();
      const int n = this->size();
      this->erase(this->begin(), this->begin() + ::std::min(n, d));
      return *this;
    }

    P& operator*=(const P& g) {
      const int n = this->deg() + 1;
      const int m = g.deg() + 1;

      P res;
      ::tools::convolution<AG, MM>(this->cbegin(), this->cbegin() + n, g.cbegin(), g.cbegin() + m, ::std::back_inserter(res));
      res.regularize();
      return *this = ::std::move(res);
    }

  private:
    P& divide_inplace_naive(const P& g) {
      const int n = this->size();
      const int m = g.size();

      assert(0 < m && m <= n);
      assert(AG::e() != MM::e());
      assert(this->back() != AG::e());
      assert(g.back() != AG::e());

      const auto ic = MM::inv(g.back());
      P q(n - m + 1);
      for (int i = n - m; i >= 0; --i) {
        q[i] = MM::op((*this)[m - 1 + i], ic);
        for (int j = 0; j < m; ++j) {
          (*this)[j + i] = AG::op((*this)[j + i], AG::inv(MM::op(g[j], q[i])));
        }
      }
      return *this = ::std::move(q);
    }
    P& divide_inplace_faster(const P& g) {
      const int n = this->size();
      const int m = g.size();

      static_assert(::tools::has_mod_v<R>);
      static_assert(::std::is_same_v<AG, ::tools::group::plus<R>>);
      static_assert(::std::is_same_v<MM, ::tools::group::multiplies<R>>);
      assert(::tools::is_prime(R::mod()));
      assert(0 < m && m <= n);
      assert(AG::e() != MM::e());
      assert(this->back() != AG::e());
      assert(g.back() != AG::e());

      ::tools::fps<R> q(this->rbegin(), this->rend());
      q.divide_inplace(::tools::fps<R>(g.rbegin(), g.rend()), n - m + 1);
      this->assign(q.rbegin(), q.rend());
      return *this;
    }

  public:
    P& operator/=(P g) {
      if (AG::e() == MM::e()) {
        this->clear();
        return *this;
      }

      this->regularize();
      g.regularize();

      const int n = this->size();
      const int m = g.size();

      assert(m > 0);
      if (n < m) {
        this->clear();
        return *this;
      }

      if constexpr (::tools::has_mod_v<R> && ::std::is_same_v<AG, ::tools::group::plus<R>> && ::std::is_same_v<MM, ::tools::group::multiplies<R>>) {
        assert(::tools::is_prime(R::mod()));
        return this->divide_inplace_faster(g);
      } else {
        return this->divide_inplace_naive(g);
      }
    }
    P& operator%=(const P& g) {
      auto q = (*this) / g;
      q *= g;
      q *= AG::inv(MM::e());
      *this += q;
      return this->regularize();
    }

  private:
    P& taylor_shift(const R& c) {
      static_assert(::tools::has_mod_v<R>);
      static_assert(::std::is_same_v<AG, ::tools::group::plus<R>>);
      static_assert(::std::is_same_v<MM, ::tools::group::multiplies<R>>);
      assert(::tools::is_prime(R::mod()));

      this->regularize();
      const int n = this->size();
      assert(n < R::mod());

      ::tools::fact_mod_cache<R> cache;
      ::tools::pow_mod_cache<R> pow_c(c);

      P a;
      a.reserve(n);
      for (int i = 0; i < n; ++i) {
        a.push_back((*this)[i] * cache.fact(i));
      }

      P b;
      b.reserve(n);
      for (int i = 0; i < n; ++i) {
        b.push_back(pow_c[n - 1 - i] * cache.fact_inv(n - 1 - i));
      }

      a *= b;

      this->clear();
      this->reserve(n);
      for (int i = 0; i < ::std::min(n, int(a.size()) - (n - 1)); ++i) {
        this->push_back(a[n - 1 + i] * cache.fact_inv(i));
      }
      return *this;
    }
    P& composition_ax_d(const R& a, const int d) {
      assert(d >= 0);

      this->regularize();
      if (this->empty()) return *this;

      if (a == AG::e()) {
        this->resize(1);
        return *this;
      }

      if (d == 0) {
        const auto f_a = (*this)(a);
        if (f_a == AG::e()) {
          this->clear();
        } else {
          this->resize(1);
          (*this)[0] = f_a;
        }
        return *this;
      }

      if (d == 1) {
        if (a == MM::e()) return *this;

        auto a_i = MM::e();
        for (auto it = this->begin(); it != this->end(); ++it) {
          *it = MM::op(*it, a_i);
          a_i = MM::op(a_i, a);
        }
        return this->regularize();
      }

      P res;
      res.reserve((this->size() - 1) * d + 1);
      auto a_i = MM::e();
      res.push_back(this->front());
      for (auto it = ::std::next(this->begin()); it != this->end(); ++it) {
        for (int i = 1; i < d; ++i) {
          res.push_back(AG::e());
        }
        res.push_back(MM::op(*it, a_i));
        a_i = MM::op(a_i, a);
      }
      res.regularize();
      return *this = ::std::move(res);
    }

  public:
    R operator()(const R& a) const {
      auto x = MM::e();
      auto res = AG::e();
      for (auto it = this->begin(), end = ::std::next(this->begin(), this->deg() + 1); it != end; ++it) {
        res = AG::op(res, MM::op(*it, x));
        x = MM::op(x, a);
      }
      return res;
    }
    P operator()(const P& g) const {
      const int n = this->deg() + 1;
      if (n == 0) return P{};
      const int m = g.deg() + 1;
      if (m == 0) return P{(*this)[0]};
      if (::std::all_of(g.begin(), ::std::next(g.begin(), m - 1), [](const auto& g_i) { return g_i == AG::e(); })) {
        return P(this->begin(), this->begin() + n).composition_ax_d(g.back(), m - 1);
      }

      const auto naive = [&]() {
        assert(n > 0);
        auto g_i = P{MM::e()};
        auto res = g_i;
        for (int i = 1; i < n; ++i) {
          g_i *= g;
          res += g_i;
        }
        return res;
      };

      if constexpr (::tools::has_mod_v<R> && ::std::is_same_v<AG, ::tools::group::plus<R>> && ::std::is_same_v<MM, ::tools::group::multiplies<R>>) {
        if (::tools::is_prime(R::mod()) && n < R::mod()) {
          if (m == 2) {
            return P(this->begin(), this->begin() + n).taylor_shift(g[0]).composition_ax_d(g[1], 1);
          } else if (m == 3) {
            return P(this->begin(), this->begin() + n).taylor_shift(g[0] - g[1] * g[1] / (R(4) * g[2])).composition_ax_d(g[2], 2).taylor_shift(g[1] / (R(2) * g[2]));
          }
        }
        return naive();
      } else {
        return naive();
      }
    }

    friend P operator*(const P& f, const R& c) { return P(f) *= c; }
    friend P operator*(const R& c, const P& f) { return P(f) *= c; }
    friend P operator/(const P& f, const R& c) { return P(f) /= c; }
    friend P operator+(const P& f, const P& g) { return P(f) += g; }
    friend P operator-(const P& f, const P& g) { return P(f) -= g; }
    friend P operator*(const P& f, const P& g) { return P(f) *= g; }
    friend P operator/(const P& f, const P& g) { return P(f) /= g; }
    friend P operator%(const P& f, const P& g) { return P(f) %= g; }
    friend P operator<<(const P& f, const int d) { return P(f) <<= d; }
    friend P operator>>(const P& f, const int d) { return P(f) >>= d; }
  };
}

#endif
