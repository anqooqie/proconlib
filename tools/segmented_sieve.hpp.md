---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/chmin.hpp
    title: chmin function
  - icon: ':heavy_check_mark:'
    path: tools/floor_sqrt.hpp
    title: $\left\lfloor \sqrt{x} \right\rfloor$
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/segmented_sieve.test.cpp
    title: tests/segmented_sieve.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/segmented_sieve.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <cassert>\n#include <algorithm>\n#include <limits>\n#include <numeric>\n#include\
    \ <cstddef>\n#include <iterator>\n#include <utility>\n#line 1 \"tools/floor_sqrt.hpp\"\
    \n\n\n\n#line 5 \"tools/floor_sqrt.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ T>\n  T floor_sqrt(const T n) {\n    assert(n >= 0);\n\n    T ok = 0;\n    T\
    \ ng;\n    for (ng = 1; ng <= n / ng; ng *= 2);\n\n    while (ng - ok > 1) {\n\
    \      const T mid = ok + (ng - ok) / 2;\n      if (mid <= n / mid) {\n      \
    \  ok = mid;\n      } else {\n        ng = mid;\n      }\n    }\n\n    return\
    \ ok;\n  }\n}\n\n\n#line 1 \"tools/chmin.hpp\"\n\n\n\n#line 5 \"tools/chmin.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M, typename N>\n  bool chmin(M&\
    \ lhs, const N& rhs) {\n    const bool updated = lhs > rhs;\n    if (updated)\
    \ lhs = rhs;\n    return updated;\n  }\n}\n\n\n#line 1 \"tools/ceil.hpp\"\n\n\n\
    \n#include <type_traits>\n#line 6 \"tools/ceil.hpp\"\n\nnamespace tools {\n\n\
    \  template <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> ceil(const\
    \ M lhs, const N rhs) {\n    using T = ::std::common_type_t<M, N>;\n    assert(rhs\
    \ != N(0));\n    return lhs / rhs + T(((lhs > M(0) && rhs > N(0)) || (lhs < M(0)\
    \ && rhs < N(0))) && lhs % rhs);\n  }\n}\n\n\n#line 15 \"tools/segmented_sieve.hpp\"\
    \n\nnamespace tools {\n  template <typename T>\n  class segmented_sieve {\n  private:\n\
    \    ::std::vector<T> m_lpf;\n    ::std::vector<::std::vector<T>> m_pf;\n    ::std::vector<T>\
    \ m_aux;\n    T m_l;\n\n  public:\n    segmented_sieve() = default;\n    segmented_sieve(const\
    \ ::tools::segmented_sieve<T>&) = default;\n    segmented_sieve(::tools::segmented_sieve<T>&&)\
    \ = default;\n    ~segmented_sieve() = default;\n    ::tools::segmented_sieve<T>&\
    \ operator=(const ::tools::segmented_sieve<T>&) = default;\n    ::tools::segmented_sieve<T>&\
    \ operator=(::tools::segmented_sieve<T>&&) = default;\n\n    segmented_sieve(const\
    \ T& k, const T& l, const T& r) {\n      assert(l <= r);\n\n      const T lpf_max\
    \ = ::std::max(::tools::floor_sqrt(r), k);\n      this->m_lpf.resize(lpf_max +\
    \ 1);\n      ::std::fill(this->m_lpf.begin(), this->m_lpf.end(), ::std::numeric_limits<T>::max());\n\
    \      this->m_pf.resize(r - l + 1);\n      this->m_aux.resize(r - l + 1);\n \
    \     ::std::iota(this->m_aux.begin(), this->m_aux.end(), l);\n      this->m_l\
    \ = l;\n\n      for (T p = 2; p <= lpf_max; ++p) {\n        if (::tools::chmin(this->m_lpf[p],\
    \ p)) {\n          for (T np = p * p; np <= lpf_max; np += p) {\n            ::tools::chmin(this->m_lpf[np],\
    \ p);\n          }\n          for (T p_q = p, np_q; (np_q = ::tools::ceil(l, p_q)\
    \ * p_q) <= r; p_q *= p) {\n            for (; np_q <= r; np_q += p_q) {\n   \
    \           if (lpf_max < this->m_aux[np_q - l]) {\n                this->m_pf[np_q\
    \ - l].push_back(p);\n                this->m_aux[np_q - l] /= p;\n          \
    \    }\n            }\n          }\n        }\n      }\n\n      for (T i = l;\
    \ i <= r; ++i) {\n        if (lpf_max < this->m_aux[i - l]) {\n          this->m_pf[i\
    \ - l].push_back(this->m_aux[i - l]);\n          this->m_aux[i - l] = 1;\n   \
    \     }\n      }\n    }\n\n    segmented_sieve(const T& l, const T& r) :\n   \
    \   segmented_sieve(0, l, r) {\n    }\n\n    T lpf_max() const {\n      return\
    \ this->m_lpf.size() - 1;\n    }\n    T l() const {\n      return this->m_l;\n\
    \    }\n    T r() const {\n      return this->m_l + this->m_pf.size() - 1;\n \
    \   }\n\n    class prime_factor_iterable {\n    private:\n      const ::tools::segmented_sieve<T>\
    \ *m_parent;\n      T m_n;\n\n    public:\n      class iterator {\n      private:\n\
    \        const prime_factor_iterable *m_parent;\n        bool m_large;\n     \
    \   T m_i;\n\n        T n() const {\n          return this->m_parent->m_n;\n \
    \       }\n\n      public:\n        using difference_type = ::std::ptrdiff_t;\n\
    \        using value_type = T;\n        using reference = T&;\n        using pointer\
    \ = T*;\n        using iterator_category = ::std::input_iterator_tag;\n\n    \
    \    iterator() = default;\n        iterator(const iterator&) = default;\n   \
    \     iterator(iterator&&) = default;\n        ~iterator() = default;\n      \
    \  iterator& operator=(const iterator&) = default;\n        iterator& operator=(iterator&&)\
    \ = default;\n\n        iterator(prime_factor_iterable const * const parent, const\
    \ bool large, const T& i) :\n          m_parent(parent), m_large(large), m_i(i)\
    \ {\n        }\n\n        T operator*() const {\n          if (this->m_large)\
    \ {\n            return this->m_parent->m_parent->m_pf[this->n() - this->m_parent->m_parent->l()][this->m_i];\n\
    \          } else {\n            return this->m_parent->m_parent->m_lpf[this->m_i];\n\
    \          }\n        }\n\n        iterator& operator++() {\n          if (this->m_large)\
    \ {\n            ++this->m_i;\n            if (this->m_i == T(this->m_parent->m_parent->m_pf[this->n()\
    \ - this->m_parent->m_parent->l()].size())) {\n              this->m_large = false;\n\
    \              this->m_i = this->m_parent->m_parent->m_aux[this->n() - this->m_parent->m_parent->l()];\n\
    \            }\n          } else {\n            this->m_i /= this->m_parent->m_parent->m_lpf[this->m_i];\n\
    \          }\n          return *this;\n        }\n\n        iterator operator++(int)\
    \ {\n          const iterator self = *this;\n          ++*this;\n          return\
    \ self;\n        }\n\n        friend bool operator==(const iterator& lhs, const\
    \ iterator& rhs) {\n          return lhs.m_large == rhs.m_large && (!lhs.m_large\
    \ || lhs.n() == rhs.n()) && lhs.m_i == rhs.m_i;\n        }\n\n        friend bool\
    \ operator!=(const iterator& lhs, const iterator& rhs) {\n          return !(lhs\
    \ == rhs);\n        }\n      };\n\n      prime_factor_iterable(::tools::segmented_sieve<T>\
    \ const * const parent, const T& n) :\n        m_parent(parent), m_n(n) {\n  \
    \    }\n\n      iterator begin() const {\n        if (this->m_n <= this->m_parent->lpf_max())\
    \ {\n          return iterator(this, false, this->m_n);\n        } else {\n  \
    \        return iterator(this, true, 0);\n        }\n      }\n\n      iterator\
    \ end() const {\n        return iterator(this, false, 1);\n      }\n    };\n\n\
    \    class distinct_prime_factor_iterable {\n    private:\n      const ::tools::segmented_sieve<T>\
    \ *m_parent;\n      T m_n;\n\n    public:\n      class iterator {\n      private:\n\
    \        const distinct_prime_factor_iterable *m_parent;\n        bool m_large;\n\
    \        T m_i;\n        ::std::pair<T, T> m_value;\n\n        T n() const {\n\
    \          return this->m_parent->m_n;\n        }\n\n        void next() {\n \
    \         const ::std::vector<T>& lpf = this->m_parent->m_parent->m_lpf;\n   \
    \       if (this->m_large) {\n            const ::std::vector<T>& pf = this->m_parent->m_parent->m_pf[this->m_parent->m_n\
    \ - this->m_parent->m_parent->l()];\n            this->m_value.first = pf[this->m_i];\n\
    \            this->m_value.second = 0;\n            for (; this->m_i < T(pf.size())\
    \ && pf[this->m_i] == this->m_value.first; ++this->m_i) {\n              ++this->m_value.second;\n\
    \            }\n            if (this->m_i == T(pf.size())) {\n              this->m_large\
    \ = false;\n              this->m_i = this->m_parent->m_parent->m_aux[this->m_parent->m_n\
    \ - this->m_parent->m_parent->l()];\n              for (; lpf[this->m_i] == this->m_value.first;\
    \ this->m_i /= lpf[this->m_i]) {\n                ++this->m_value.second;\n  \
    \            }\n            }\n          } else {\n            if (this->m_i ==\
    \ 1) {\n              this->m_value.first = ::std::numeric_limits<T>::max();\n\
    \              this->m_value.second = 0;\n            } else {\n             \
    \ this->m_value.first = lpf[this->m_i];\n              this->m_value.second =\
    \ 0;\n              for (; lpf[this->m_i] == this->m_value.first; this->m_i /=\
    \ lpf[this->m_i]) {\n                ++this->m_value.second;\n              }\n\
    \            }\n          }\n        }\n\n      public:\n        using difference_type\
    \ = ::std::ptrdiff_t;\n        using value_type = ::std::pair<T, T>;\n       \
    \ using reference = ::std::pair<T, T>&;\n        using pointer = ::std::pair<T,\
    \ T>*;\n        using iterator_category = ::std::input_iterator_tag;\n\n     \
    \   iterator() = default;\n        iterator(const iterator&) = default;\n    \
    \    iterator(iterator&&) = default;\n        ~iterator() = default;\n       \
    \ iterator& operator=(const iterator&) = default;\n        iterator& operator=(iterator&&)\
    \ = default;\n\n        iterator(distinct_prime_factor_iterable const * const\
    \ parent, const bool large, const T& i) :\n          m_parent(parent), m_large(large),\
    \ m_i(i) {\n          this->next();\n        }\n\n        ::std::pair<T, T> operator*()\
    \ const {\n          return this->m_value;\n        }\n\n        iterator& operator++()\
    \ {\n          this->next();\n          return *this;\n        }\n\n        iterator\
    \ operator++(int) {\n          const iterator self = *this;\n          ++*this;\n\
    \          return self;\n        }\n\n        friend bool operator==(const iterator&\
    \ lhs, const iterator& rhs) {\n          return lhs.n() == rhs.n() && lhs.m_value.first\
    \ == rhs.m_value.first;\n        }\n\n        friend bool operator!=(const iterator&\
    \ lhs, const iterator& rhs) {\n          return !(lhs == rhs);\n        }\n  \
    \    };\n\n      distinct_prime_factor_iterable(::tools::segmented_sieve<T> const\
    \ * const parent, const T& n) :\n        m_parent(parent), m_n(n) {\n      }\n\
    \n      iterator begin() const {\n        if (this->m_n <= this->m_parent->lpf_max())\
    \ {\n          return iterator(this, false, this->m_n);\n        } else {\n  \
    \        return iterator(this, true, 0);\n        }\n      }\n\n      iterator\
    \ end() const {\n        return iterator(this, false, 1);\n      }\n    };\n\n\
    \    class prime_iterable {\n    private:\n      const ::tools::segmented_sieve<T>\
    \ *m_parent;\n      T m_lb;\n      T m_ub;\n\n    public:\n      class iterator\
    \ {\n      private:\n        const prime_iterable *m_parent;\n        T m_i;\n\
    \n        void next() {\n          ++this->m_i;\n          for (; this->m_i <=\
    \ this->m_parent->m_ub && (\n            (this->m_i <= this->m_parent->m_parent->lpf_max()\
    \ && this->m_parent->m_parent->m_lpf[this->m_i] != this->m_i)\n            ||\
    \ (this->m_parent->m_parent->lpf_max() < this->m_i && this->m_parent->m_parent->m_pf[this->m_i\
    \ - this->m_parent->m_parent->l()][0] != this->m_i)\n          ); ++this->m_i);\n\
    \        }\n\n      public:\n        using difference_type = ::std::ptrdiff_t;\n\
    \        using value_type = T;\n        using reference = T&;\n        using pointer\
    \ = T*;\n        using iterator_category = ::std::input_iterator_tag;\n\n    \
    \    iterator() = default;\n        iterator(const iterator&) = default;\n   \
    \     iterator(iterator&&) = default;\n        ~iterator() = default;\n      \
    \  iterator& operator=(const iterator&) = default;\n        iterator& operator=(iterator&&)\
    \ = default;\n\n        iterator(prime_iterable const * const parent, const T&\
    \ i) :\n          m_parent(parent), m_i(i) {\n          this->next();\n      \
    \  }\n\n        T operator*() const {\n          return this->m_i;\n        }\n\
    \n        iterator& operator++() {\n          this->next();\n          return\
    \ *this;\n        }\n\n        iterator operator++(int) {\n          const iterator\
    \ self = *this;\n          ++*this;\n          return self;\n        }\n\n   \
    \     friend bool operator==(const iterator& lhs, const iterator& rhs) {\n   \
    \       return lhs.m_i == rhs.m_i;\n        }\n\n        friend bool operator!=(const\
    \ iterator& lhs, const iterator& rhs) {\n          return !(lhs == rhs);\n   \
    \     }\n      };\n\n      prime_iterable(::tools::segmented_sieve<T> const *\
    \ const parent, const T& lb, const T& ub) :\n        m_parent(parent), m_lb(lb),\
    \ m_ub(ub) {\n      }\n\n      iterator begin() const {\n        return iterator(this,\
    \ this->m_lb - 1);\n      }\n\n      iterator end() const {\n        return iterator(this,\
    \ this->m_ub);\n      }\n    };\n\n    prime_factor_iterable prime_factor_range(const\
    \ T& n) const {\n      assert((1 <= n && n <= this->lpf_max()) || (this->l() <=\
    \ n && n <= this->r()));\n      return prime_factor_iterable(this, n);\n    }\n\
    \n    distinct_prime_factor_iterable distinct_prime_factor_range(const T& n) const\
    \ {\n      assert((1 <= n && n <= this->lpf_max()) || (this->l() <= n && n <=\
    \ this->r()));\n      return distinct_prime_factor_iterable(this, n);\n    }\n\
    \n    prime_iterable prime_range(const T& lb, const T& ub) const {\n      assert(lb\
    \ <= ub);\n      const bool is_in_small_sieve = 1 <= lb && ub <= this->lpf_max();\n\
    \      const bool is_in_large_sieve = this->l() <= lb && ub <= this->r();\n  \
    \    assert(is_in_small_sieve || is_in_large_sieve);\n      return prime_iterable(this,\
    \ lb, ub);\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_SEGMENTED_SIEVE_HPP\n#define TOOLS_SEGMENTED_SIEVE_HPP\n\n\
    #include <vector>\n#include <cassert>\n#include <algorithm>\n#include <limits>\n\
    #include <numeric>\n#include <cstddef>\n#include <iterator>\n#include <utility>\n\
    #include \"tools/floor_sqrt.hpp\"\n#include \"tools/chmin.hpp\"\n#include \"tools/ceil.hpp\"\
    \n\nnamespace tools {\n  template <typename T>\n  class segmented_sieve {\n  private:\n\
    \    ::std::vector<T> m_lpf;\n    ::std::vector<::std::vector<T>> m_pf;\n    ::std::vector<T>\
    \ m_aux;\n    T m_l;\n\n  public:\n    segmented_sieve() = default;\n    segmented_sieve(const\
    \ ::tools::segmented_sieve<T>&) = default;\n    segmented_sieve(::tools::segmented_sieve<T>&&)\
    \ = default;\n    ~segmented_sieve() = default;\n    ::tools::segmented_sieve<T>&\
    \ operator=(const ::tools::segmented_sieve<T>&) = default;\n    ::tools::segmented_sieve<T>&\
    \ operator=(::tools::segmented_sieve<T>&&) = default;\n\n    segmented_sieve(const\
    \ T& k, const T& l, const T& r) {\n      assert(l <= r);\n\n      const T lpf_max\
    \ = ::std::max(::tools::floor_sqrt(r), k);\n      this->m_lpf.resize(lpf_max +\
    \ 1);\n      ::std::fill(this->m_lpf.begin(), this->m_lpf.end(), ::std::numeric_limits<T>::max());\n\
    \      this->m_pf.resize(r - l + 1);\n      this->m_aux.resize(r - l + 1);\n \
    \     ::std::iota(this->m_aux.begin(), this->m_aux.end(), l);\n      this->m_l\
    \ = l;\n\n      for (T p = 2; p <= lpf_max; ++p) {\n        if (::tools::chmin(this->m_lpf[p],\
    \ p)) {\n          for (T np = p * p; np <= lpf_max; np += p) {\n            ::tools::chmin(this->m_lpf[np],\
    \ p);\n          }\n          for (T p_q = p, np_q; (np_q = ::tools::ceil(l, p_q)\
    \ * p_q) <= r; p_q *= p) {\n            for (; np_q <= r; np_q += p_q) {\n   \
    \           if (lpf_max < this->m_aux[np_q - l]) {\n                this->m_pf[np_q\
    \ - l].push_back(p);\n                this->m_aux[np_q - l] /= p;\n          \
    \    }\n            }\n          }\n        }\n      }\n\n      for (T i = l;\
    \ i <= r; ++i) {\n        if (lpf_max < this->m_aux[i - l]) {\n          this->m_pf[i\
    \ - l].push_back(this->m_aux[i - l]);\n          this->m_aux[i - l] = 1;\n   \
    \     }\n      }\n    }\n\n    segmented_sieve(const T& l, const T& r) :\n   \
    \   segmented_sieve(0, l, r) {\n    }\n\n    T lpf_max() const {\n      return\
    \ this->m_lpf.size() - 1;\n    }\n    T l() const {\n      return this->m_l;\n\
    \    }\n    T r() const {\n      return this->m_l + this->m_pf.size() - 1;\n \
    \   }\n\n    class prime_factor_iterable {\n    private:\n      const ::tools::segmented_sieve<T>\
    \ *m_parent;\n      T m_n;\n\n    public:\n      class iterator {\n      private:\n\
    \        const prime_factor_iterable *m_parent;\n        bool m_large;\n     \
    \   T m_i;\n\n        T n() const {\n          return this->m_parent->m_n;\n \
    \       }\n\n      public:\n        using difference_type = ::std::ptrdiff_t;\n\
    \        using value_type = T;\n        using reference = T&;\n        using pointer\
    \ = T*;\n        using iterator_category = ::std::input_iterator_tag;\n\n    \
    \    iterator() = default;\n        iterator(const iterator&) = default;\n   \
    \     iterator(iterator&&) = default;\n        ~iterator() = default;\n      \
    \  iterator& operator=(const iterator&) = default;\n        iterator& operator=(iterator&&)\
    \ = default;\n\n        iterator(prime_factor_iterable const * const parent, const\
    \ bool large, const T& i) :\n          m_parent(parent), m_large(large), m_i(i)\
    \ {\n        }\n\n        T operator*() const {\n          if (this->m_large)\
    \ {\n            return this->m_parent->m_parent->m_pf[this->n() - this->m_parent->m_parent->l()][this->m_i];\n\
    \          } else {\n            return this->m_parent->m_parent->m_lpf[this->m_i];\n\
    \          }\n        }\n\n        iterator& operator++() {\n          if (this->m_large)\
    \ {\n            ++this->m_i;\n            if (this->m_i == T(this->m_parent->m_parent->m_pf[this->n()\
    \ - this->m_parent->m_parent->l()].size())) {\n              this->m_large = false;\n\
    \              this->m_i = this->m_parent->m_parent->m_aux[this->n() - this->m_parent->m_parent->l()];\n\
    \            }\n          } else {\n            this->m_i /= this->m_parent->m_parent->m_lpf[this->m_i];\n\
    \          }\n          return *this;\n        }\n\n        iterator operator++(int)\
    \ {\n          const iterator self = *this;\n          ++*this;\n          return\
    \ self;\n        }\n\n        friend bool operator==(const iterator& lhs, const\
    \ iterator& rhs) {\n          return lhs.m_large == rhs.m_large && (!lhs.m_large\
    \ || lhs.n() == rhs.n()) && lhs.m_i == rhs.m_i;\n        }\n\n        friend bool\
    \ operator!=(const iterator& lhs, const iterator& rhs) {\n          return !(lhs\
    \ == rhs);\n        }\n      };\n\n      prime_factor_iterable(::tools::segmented_sieve<T>\
    \ const * const parent, const T& n) :\n        m_parent(parent), m_n(n) {\n  \
    \    }\n\n      iterator begin() const {\n        if (this->m_n <= this->m_parent->lpf_max())\
    \ {\n          return iterator(this, false, this->m_n);\n        } else {\n  \
    \        return iterator(this, true, 0);\n        }\n      }\n\n      iterator\
    \ end() const {\n        return iterator(this, false, 1);\n      }\n    };\n\n\
    \    class distinct_prime_factor_iterable {\n    private:\n      const ::tools::segmented_sieve<T>\
    \ *m_parent;\n      T m_n;\n\n    public:\n      class iterator {\n      private:\n\
    \        const distinct_prime_factor_iterable *m_parent;\n        bool m_large;\n\
    \        T m_i;\n        ::std::pair<T, T> m_value;\n\n        T n() const {\n\
    \          return this->m_parent->m_n;\n        }\n\n        void next() {\n \
    \         const ::std::vector<T>& lpf = this->m_parent->m_parent->m_lpf;\n   \
    \       if (this->m_large) {\n            const ::std::vector<T>& pf = this->m_parent->m_parent->m_pf[this->m_parent->m_n\
    \ - this->m_parent->m_parent->l()];\n            this->m_value.first = pf[this->m_i];\n\
    \            this->m_value.second = 0;\n            for (; this->m_i < T(pf.size())\
    \ && pf[this->m_i] == this->m_value.first; ++this->m_i) {\n              ++this->m_value.second;\n\
    \            }\n            if (this->m_i == T(pf.size())) {\n              this->m_large\
    \ = false;\n              this->m_i = this->m_parent->m_parent->m_aux[this->m_parent->m_n\
    \ - this->m_parent->m_parent->l()];\n              for (; lpf[this->m_i] == this->m_value.first;\
    \ this->m_i /= lpf[this->m_i]) {\n                ++this->m_value.second;\n  \
    \            }\n            }\n          } else {\n            if (this->m_i ==\
    \ 1) {\n              this->m_value.first = ::std::numeric_limits<T>::max();\n\
    \              this->m_value.second = 0;\n            } else {\n             \
    \ this->m_value.first = lpf[this->m_i];\n              this->m_value.second =\
    \ 0;\n              for (; lpf[this->m_i] == this->m_value.first; this->m_i /=\
    \ lpf[this->m_i]) {\n                ++this->m_value.second;\n              }\n\
    \            }\n          }\n        }\n\n      public:\n        using difference_type\
    \ = ::std::ptrdiff_t;\n        using value_type = ::std::pair<T, T>;\n       \
    \ using reference = ::std::pair<T, T>&;\n        using pointer = ::std::pair<T,\
    \ T>*;\n        using iterator_category = ::std::input_iterator_tag;\n\n     \
    \   iterator() = default;\n        iterator(const iterator&) = default;\n    \
    \    iterator(iterator&&) = default;\n        ~iterator() = default;\n       \
    \ iterator& operator=(const iterator&) = default;\n        iterator& operator=(iterator&&)\
    \ = default;\n\n        iterator(distinct_prime_factor_iterable const * const\
    \ parent, const bool large, const T& i) :\n          m_parent(parent), m_large(large),\
    \ m_i(i) {\n          this->next();\n        }\n\n        ::std::pair<T, T> operator*()\
    \ const {\n          return this->m_value;\n        }\n\n        iterator& operator++()\
    \ {\n          this->next();\n          return *this;\n        }\n\n        iterator\
    \ operator++(int) {\n          const iterator self = *this;\n          ++*this;\n\
    \          return self;\n        }\n\n        friend bool operator==(const iterator&\
    \ lhs, const iterator& rhs) {\n          return lhs.n() == rhs.n() && lhs.m_value.first\
    \ == rhs.m_value.first;\n        }\n\n        friend bool operator!=(const iterator&\
    \ lhs, const iterator& rhs) {\n          return !(lhs == rhs);\n        }\n  \
    \    };\n\n      distinct_prime_factor_iterable(::tools::segmented_sieve<T> const\
    \ * const parent, const T& n) :\n        m_parent(parent), m_n(n) {\n      }\n\
    \n      iterator begin() const {\n        if (this->m_n <= this->m_parent->lpf_max())\
    \ {\n          return iterator(this, false, this->m_n);\n        } else {\n  \
    \        return iterator(this, true, 0);\n        }\n      }\n\n      iterator\
    \ end() const {\n        return iterator(this, false, 1);\n      }\n    };\n\n\
    \    class prime_iterable {\n    private:\n      const ::tools::segmented_sieve<T>\
    \ *m_parent;\n      T m_lb;\n      T m_ub;\n\n    public:\n      class iterator\
    \ {\n      private:\n        const prime_iterable *m_parent;\n        T m_i;\n\
    \n        void next() {\n          ++this->m_i;\n          for (; this->m_i <=\
    \ this->m_parent->m_ub && (\n            (this->m_i <= this->m_parent->m_parent->lpf_max()\
    \ && this->m_parent->m_parent->m_lpf[this->m_i] != this->m_i)\n            ||\
    \ (this->m_parent->m_parent->lpf_max() < this->m_i && this->m_parent->m_parent->m_pf[this->m_i\
    \ - this->m_parent->m_parent->l()][0] != this->m_i)\n          ); ++this->m_i);\n\
    \        }\n\n      public:\n        using difference_type = ::std::ptrdiff_t;\n\
    \        using value_type = T;\n        using reference = T&;\n        using pointer\
    \ = T*;\n        using iterator_category = ::std::input_iterator_tag;\n\n    \
    \    iterator() = default;\n        iterator(const iterator&) = default;\n   \
    \     iterator(iterator&&) = default;\n        ~iterator() = default;\n      \
    \  iterator& operator=(const iterator&) = default;\n        iterator& operator=(iterator&&)\
    \ = default;\n\n        iterator(prime_iterable const * const parent, const T&\
    \ i) :\n          m_parent(parent), m_i(i) {\n          this->next();\n      \
    \  }\n\n        T operator*() const {\n          return this->m_i;\n        }\n\
    \n        iterator& operator++() {\n          this->next();\n          return\
    \ *this;\n        }\n\n        iterator operator++(int) {\n          const iterator\
    \ self = *this;\n          ++*this;\n          return self;\n        }\n\n   \
    \     friend bool operator==(const iterator& lhs, const iterator& rhs) {\n   \
    \       return lhs.m_i == rhs.m_i;\n        }\n\n        friend bool operator!=(const\
    \ iterator& lhs, const iterator& rhs) {\n          return !(lhs == rhs);\n   \
    \     }\n      };\n\n      prime_iterable(::tools::segmented_sieve<T> const *\
    \ const parent, const T& lb, const T& ub) :\n        m_parent(parent), m_lb(lb),\
    \ m_ub(ub) {\n      }\n\n      iterator begin() const {\n        return iterator(this,\
    \ this->m_lb - 1);\n      }\n\n      iterator end() const {\n        return iterator(this,\
    \ this->m_ub);\n      }\n    };\n\n    prime_factor_iterable prime_factor_range(const\
    \ T& n) const {\n      assert((1 <= n && n <= this->lpf_max()) || (this->l() <=\
    \ n && n <= this->r()));\n      return prime_factor_iterable(this, n);\n    }\n\
    \n    distinct_prime_factor_iterable distinct_prime_factor_range(const T& n) const\
    \ {\n      assert((1 <= n && n <= this->lpf_max()) || (this->l() <= n && n <=\
    \ this->r()));\n      return distinct_prime_factor_iterable(this, n);\n    }\n\
    \n    prime_iterable prime_range(const T& lb, const T& ub) const {\n      assert(lb\
    \ <= ub);\n      const bool is_in_small_sieve = 1 <= lb && ub <= this->lpf_max();\n\
    \      const bool is_in_large_sieve = this->l() <= lb && ub <= this->r();\n  \
    \    assert(is_in_small_sieve || is_in_large_sieve);\n      return prime_iterable(this,\
    \ lb, ub);\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/floor_sqrt.hpp
  - tools/chmin.hpp
  - tools/ceil.hpp
  isVerificationFile: false
  path: tools/segmented_sieve.hpp
  requiredBy: []
  timestamp: '2023-08-20 17:29:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/segmented_sieve.test.cpp
documentation_of: tools/segmented_sieve.hpp
layout: document
title: Segmented sieve
---

It can list all primes $p$ such that $L \leq p \leq R$.
Also, it can list all prime factors of $n$ such that $L \leq n \leq R$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) segmented_sieve<T> sieve(T K, T L, T R);
(2) segmented_sieve<T> sieve(T L, T R);
```

- (1)
    - It constructs two sieves, $1 \leq p \leq \max\left(\left\lfloor\sqrt{R}\right\rfloor, K\right)$ and $L \leq p \leq R$. They can list all primes $p$ in them, and list all prime factors of $n$ in them.
- (2)
    - It is the same as `sieve(0, L, R)`.

### Constraints
- $1 \leq L \leq R$
- $K \leq R$

### Time Complexity
- $O\left(\left(\max\left(\left\lfloor\sqrt{R}\right\rfloor, K\right) + R - L\right) \log\log\left(\max\left(\left\lfloor\sqrt{R}\right\rfloor, K\right)\right)\right)$

## lpf_max
```cpp
T sieve.lpf_max();
```

It returns $\max\left(\left\lfloor\sqrt{R}\right\rfloor, K\right)$.

### Constraints
- None

### Time Complexity
- $O(1)$

## l
```cpp
T sieve.l();
```

It returns $L$.

### Constraints
- None

### Time Complexity
- $O(1)$

## r
```cpp
T sieve.r();
```

It returns $R$.

### Constraints
- None

### Time Complexity
- $O(1)$

## prime_range
```cpp
struct {
  segmented_sieve<T>::prime_iterable::iterator begin();
  segmented_sieve<T>::prime_iterable::iterator end();
} sieve.prime_range(T l, T r);
```

It returns all primes $p$ such that $l \leq p \leq r$ in ascending order.

### Constraints
- $1 \leq l \leq r \leq \max\left(\left\lfloor\sqrt{R}\right\rfloor, K\right)$ or $L \leq l \leq r \leq R$

### Time Complexity
- $O(1)$

## prime_factor_range
```cpp
struct {
  segmented_sieve<T>::prime_factor_iterable::iterator begin();
  segmented_sieve<T>::prime_factor_iterable::iterator end();
} sieve.prime_factor_range(T n);
```

It returns all prime factors of $n$ in ascending order.

### Constraints
- $1 \leq n \leq \max\left(\left\lfloor\sqrt{R}\right\rfloor, K\right)$ or $L \leq n \leq R$

### Time Complexity
- $O(1)$

## distinct_prime_factor_range
```cpp
struct {
  segmented_sieve<T>::distinct_prime_factor_iterable::iterator begin();
  segmented_sieve<T>::distinct_prime_factor_iterable::iterator end();
} sieve.distinct_prime_factor_range(T n);
```

It returns all distinct prime factors of $n$ and the numbers of occurrences of them, in ascending order of primes.
For example, `sieve.distinct_prime_factor_range(360)` returns $((2, 3), (3, 2), (5, 1))$ since $360 = 2^3 \times 3^2 \times 5^1$.

### Constraints
- $1 \leq n \leq \max\left(\left\lfloor\sqrt{R}\right\rfloor, K\right)$ or $L \leq n \leq R$

### Time Complexity
- $O(1)$
