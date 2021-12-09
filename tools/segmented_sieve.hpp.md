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
    path: tools/detail/ceil_and_floor.hpp
    title: tools/detail/ceil_and_floor.hpp
  - icon: ':warning:'
    path: tools/floor_sqrt.hpp
    title: $\left\lfloor \sqrt{x} \right\rfloor$
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/segmented_sieve.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <cassert>\n#include <algorithm>\n#include <limits>\n#include <numeric>\n#include\
    \ <cstddef>\n#include <iterator>\n#include <utility>\n#line 1 \"tools/floor_sqrt.hpp\"\
    \n\n\n\n#line 5 \"tools/floor_sqrt.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ T>\n  T floor_sqrt(T n) {\n    assert(n >= 0);\n\n    T ok = 0;\n    T ng;\n\
    \    for (ng = 1; ng * ng <= n; ng *= 2);\n\n    while (ng - ok > 1) {\n     \
    \ const T mid = (ok + ng) / 2;\n      if (mid * mid <= n) {\n        ok = mid;\n\
    \      } else {\n        ng = mid;\n      }\n    }\n\n    return ok;\n  }\n}\n\
    \n\n#line 1 \"tools/chmin.hpp\"\n\n\n\n#line 5 \"tools/chmin.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  bool chmin(M& lhs, const N&\
    \ rhs) {\n    const bool updated = lhs > rhs;\n    if (updated) lhs = rhs;\n \
    \   return updated;\n  }\n}\n\n\n#line 1 \"tools/ceil.hpp\"\n\n\n\n#line 1 \"\
    tools/detail/ceil_and_floor.hpp\"\n\n\n\n#include <type_traits>\n\nnamespace tools\
    \ {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> floor(const M& lhs, const N& rhs);\n\n  template <typename M, typename N>\n\
    \  constexpr ::std::common_type_t<M, N> ceil(const M& lhs, const N& rhs);\n  \n\
    \  template <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> floor(const\
    \ M& lhs, const N& rhs) {\n    return\n      lhs >= 0 && rhs >= 0 ?\n        lhs\
    \ / rhs :\n      lhs < 0 && rhs >= 0 ?\n        -::tools::ceil(-lhs, rhs) :\n\
    \      lhs >= 0 && rhs < 0 ?\n        -::tools::ceil(lhs, -rhs) :\n        ::tools::floor(-lhs,\
    \ -rhs);\n  }\n  \n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> ceil(const M& lhs, const N& rhs) {\n    return\n      lhs >= 0 && rhs >=\
    \ 0 ?\n        (lhs - 1 + rhs) / rhs :\n      lhs < 0 && rhs >= 0 ?\n        -::tools::floor(-lhs,\
    \ rhs) :\n      lhs >= 0 && rhs < 0 ?\n        -::tools::floor(lhs, -rhs) :\n\
    \        ::tools::ceil(-lhs, -rhs);\n  }\n}\n\n\n#line 5 \"tools/ceil.hpp\"\n\n\
    \n#line 15 \"tools/segmented_sieve.hpp\"\n\nnamespace tools {\n  template <typename\
    \ T>\n  class segmented_sieve {\n  private:\n    ::std::vector<T> m_lpf;\n   \
    \ ::std::vector<::std::vector<T>> m_pf;\n    ::std::vector<T> m_aux;\n    T m_l;\n\
    \n  public:\n    segmented_sieve() = default;\n    segmented_sieve(const ::tools::segmented_sieve<T>&)\
    \ = default;\n    segmented_sieve(::tools::segmented_sieve<T>&&) = default;\n\
    \    ~segmented_sieve() = default;\n    ::tools::segmented_sieve<T>& operator=(const\
    \ ::tools::segmented_sieve<T>&) = default;\n    ::tools::segmented_sieve<T>& operator=(::tools::segmented_sieve<T>&&)\
    \ = default;\n\n    segmented_sieve(const T& k, const T& l, const T& r) {\n  \
    \    assert(l <= r);\n\n      const T lpf_max = ::std::max(::tools::floor_sqrt(r),\
    \ k);\n      this->m_lpf.resize(lpf_max + 1);\n      ::std::fill(this->m_lpf.begin(),\
    \ this->m_lpf.end(), ::std::numeric_limits<T>::max());\n      this->m_pf.resize(r\
    \ - l + 1);\n      this->m_aux.resize(r - l + 1);\n      ::std::iota(this->m_aux.begin(),\
    \ this->m_aux.end(), l);\n      this->m_l = l;\n\n      for (T p = 2; p <= lpf_max;\
    \ ++p) {\n        if (::tools::chmin(this->m_lpf[p], p)) {\n          for (T np\
    \ = p * p; np <= lpf_max; np += p) {\n            ::tools::chmin(this->m_lpf[np],\
    \ p);\n          }\n          for (T p_q = p, np_q; (np_q = ::tools::ceil(l, p_q)\
    \ * p_q) <= r; p_q *= p) {\n            for (; np_q <= r; np_q += p_q) {\n   \
    \           if (lpf_max < this->m_aux[np_q - l]) {\n                this->m_pf[np_q\
    \ - l].push_back(p);\n                this->m_aux[np_q - l] /= p;\n          \
    \    }\n            }\n          }\n        }\n      }\n\n      for (T i = l;\
    \ i <= r; ++i) {\n        if (lpf_max < this->m_aux[i - l]) {\n          this->m_pf[i\
    \ - l].push_back(this->m_aux[i - l]);\n          this->m_aux[i - l] = 1;\n   \
    \     }\n      }\n    }\n\n    T lpf_max() const {\n      return this->m_lpf.size()\
    \ - 1;\n    }\n    T l() const {\n      return this->m_l;\n    }\n    T r() const\
    \ {\n      return this->m_l + this->m_pf.size() - 1;\n    }\n\n    class prime_factor_iterable\
    \ {\n    private:\n      const ::tools::segmented_sieve<T> *m_parent;\n      T\
    \ m_n;\n\n    public:\n      class iterator {\n      private:\n        const prime_factor_iterable\
    \ *m_parent;\n        bool m_large;\n        T m_i;\n\n        T n() const {\n\
    \          return this->m_parent->m_n;\n        }\n\n      public:\n        using\
    \ difference_type = ::std::ptrdiff_t;\n        using value_type = T;\n       \
    \ using reference = T&;\n        using pointer = T*;\n        using iterator_category\
    \ = ::std::input_iterator_tag;\n\n        iterator() = default;\n        iterator(const\
    \ iterator&) = default;\n        iterator(iterator&&) = default;\n        ~iterator()\
    \ = default;\n        iterator& operator=(const iterator&) = default;\n      \
    \  iterator& operator=(iterator&&) = default;\n\n        iterator(prime_factor_iterable\
    \ const * const parent, const bool large, const T& i) :\n          m_parent(parent),\
    \ m_large(large), m_i(i) {\n        }\n\n        T operator*() const {\n     \
    \     if (this->m_large) {\n            return this->m_parent->m_parent->m_pf[this->n()\
    \ - this->m_parent->m_parent->l()][this->m_i];\n          } else {\n         \
    \   return this->m_parent->m_parent->m_lpf[this->m_i];\n          }\n        }\n\
    \n        iterator& operator++() {\n          if (this->m_large) {\n         \
    \   ++this->m_i;\n            if (this->m_i == T(this->m_parent->m_parent->m_pf[this->n()\
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
    \        T m_i;\n        ::std::pair<T, T> m_value;\n\n        void next() {\n\
    \          const ::std::vector<T>& lpf = this->m_parent->m_parent->m_lpf;\n  \
    \        if (this->m_large) {\n            const ::std::vector<T>& pf = this->m_parent->m_parent->m_pf[this->m_parent->m_n\
    \ - this->m_parent->m_parent->l()];\n            this->m_value.first = pf[this->m_i];\n\
    \            this->m_value.second = 0;\n            for (; this->m_i < pf.size()\
    \ && pf[this->m_i] == this->m_value.first; ++this->m_i) {\n              ++this->m_value.second;\n\
    \            }\n            if (this->m_i == pf.size()) {\n              this->m_large\
    \ = false;\n              this->m_i = this->m_parent->m_parent->m_aux[this->m_parent->m_n\
    \ - this->m_parent->m_parent->l()];\n            }\n          } else {\n     \
    \       if (this->m_i == 1) {\n              this->m_value.first = ::std::numeric_limits<T>::max();\n\
    \              this->m_value.second = 0;\n              return;\n            }\
    \ else {\n              this->m_value.first = lpf[this->m_i];\n              this->m_value.second\
    \ = 0;\n            }\n          }\n          for (; lpf[this->m_i] == this->m_value.first;\
    \ this->m_i /= lpf[this->m_i]) {\n            ++this->m_value.second;\n      \
    \    }\n        }\n\n      public:\n        using difference_type = ::std::ptrdiff_t;\n\
    \        using value_type = ::std::pair<T, T>;\n        using reference = ::std::pair<T,\
    \ T>&;\n        using pointer = ::std::pair<T, T>*;\n        using iterator_category\
    \ = ::std::input_iterator_tag;\n\n        iterator() = default;\n        iterator(const\
    \ iterator&) = default;\n        iterator(iterator&&) = default;\n        ~iterator()\
    \ = default;\n        iterator& operator=(const iterator&) = default;\n      \
    \  iterator& operator=(iterator&&) = default;\n\n        iterator(distinct_prime_factor_iterable\
    \ const * const parent, const bool large, const T& i) :\n          m_parent(parent),\
    \ m_large(large), m_i(i) {\n          this->next();\n        }\n\n        ::std::pair<T,\
    \ T> operator*() const {\n          return this->m_value;\n        }\n\n     \
    \   iterator& operator++() {\n          this->next();\n          return *this;\n\
    \        }\n\n        iterator operator++(int) {\n          const iterator self\
    \ = *this;\n          ++*this;\n          return self;\n        }\n\n        friend\
    \ bool operator==(const iterator& lhs, const iterator& rhs) {\n          return\
    \ lhs.m_parent->m_n == rhs.m_parent->m_n && lhs.m_value.first == rhs.m_value.first;\n\
    \        }\n\n        friend bool operator!=(const iterator& lhs, const iterator&\
    \ rhs) {\n          return !(lhs == rhs);\n        }\n      };\n\n      distinct_prime_factor_iterable(::tools::segmented_sieve<T>\
    \ const * const parent, const T& n) :\n        m_parent(parent), m_n(n) {\n  \
    \    }\n\n      iterator begin() const {\n        if (this->m_n <= this->m_parent->lpf_max())\
    \ {\n          return iterator(this, false, this->m_n);\n        } else {\n  \
    \        return iterator(this, true, 0);\n        }\n      }\n\n      iterator\
    \ end() const {\n        return iterator(this, false, 1);\n      }\n    };\n\n\
    \    prime_factor_iterable prime_factor_range(const T& n) const {\n      assert((1\
    \ <= n && n <= this->lpf_max()) || (this->l() <= n && n <= this->r()));\n    \
    \  return prime_factor_iterable(this, n);\n    }\n\n    distinct_prime_factor_iterable\
    \ distinct_prime_factor_range(const T& n) const {\n      assert((1 <= n && n <=\
    \ this->lpf_max()) || (this->l() <= n && n <= this->r()));\n      return distinct_prime_factor_iterable(this,\
    \ n);\n    }\n  };\n}\n\n\n"
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
    \     }\n      }\n    }\n\n    T lpf_max() const {\n      return this->m_lpf.size()\
    \ - 1;\n    }\n    T l() const {\n      return this->m_l;\n    }\n    T r() const\
    \ {\n      return this->m_l + this->m_pf.size() - 1;\n    }\n\n    class prime_factor_iterable\
    \ {\n    private:\n      const ::tools::segmented_sieve<T> *m_parent;\n      T\
    \ m_n;\n\n    public:\n      class iterator {\n      private:\n        const prime_factor_iterable\
    \ *m_parent;\n        bool m_large;\n        T m_i;\n\n        T n() const {\n\
    \          return this->m_parent->m_n;\n        }\n\n      public:\n        using\
    \ difference_type = ::std::ptrdiff_t;\n        using value_type = T;\n       \
    \ using reference = T&;\n        using pointer = T*;\n        using iterator_category\
    \ = ::std::input_iterator_tag;\n\n        iterator() = default;\n        iterator(const\
    \ iterator&) = default;\n        iterator(iterator&&) = default;\n        ~iterator()\
    \ = default;\n        iterator& operator=(const iterator&) = default;\n      \
    \  iterator& operator=(iterator&&) = default;\n\n        iterator(prime_factor_iterable\
    \ const * const parent, const bool large, const T& i) :\n          m_parent(parent),\
    \ m_large(large), m_i(i) {\n        }\n\n        T operator*() const {\n     \
    \     if (this->m_large) {\n            return this->m_parent->m_parent->m_pf[this->n()\
    \ - this->m_parent->m_parent->l()][this->m_i];\n          } else {\n         \
    \   return this->m_parent->m_parent->m_lpf[this->m_i];\n          }\n        }\n\
    \n        iterator& operator++() {\n          if (this->m_large) {\n         \
    \   ++this->m_i;\n            if (this->m_i == T(this->m_parent->m_parent->m_pf[this->n()\
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
    \        T m_i;\n        ::std::pair<T, T> m_value;\n\n        void next() {\n\
    \          const ::std::vector<T>& lpf = this->m_parent->m_parent->m_lpf;\n  \
    \        if (this->m_large) {\n            const ::std::vector<T>& pf = this->m_parent->m_parent->m_pf[this->m_parent->m_n\
    \ - this->m_parent->m_parent->l()];\n            this->m_value.first = pf[this->m_i];\n\
    \            this->m_value.second = 0;\n            for (; this->m_i < pf.size()\
    \ && pf[this->m_i] == this->m_value.first; ++this->m_i) {\n              ++this->m_value.second;\n\
    \            }\n            if (this->m_i == pf.size()) {\n              this->m_large\
    \ = false;\n              this->m_i = this->m_parent->m_parent->m_aux[this->m_parent->m_n\
    \ - this->m_parent->m_parent->l()];\n            }\n          } else {\n     \
    \       if (this->m_i == 1) {\n              this->m_value.first = ::std::numeric_limits<T>::max();\n\
    \              this->m_value.second = 0;\n              return;\n            }\
    \ else {\n              this->m_value.first = lpf[this->m_i];\n              this->m_value.second\
    \ = 0;\n            }\n          }\n          for (; lpf[this->m_i] == this->m_value.first;\
    \ this->m_i /= lpf[this->m_i]) {\n            ++this->m_value.second;\n      \
    \    }\n        }\n\n      public:\n        using difference_type = ::std::ptrdiff_t;\n\
    \        using value_type = ::std::pair<T, T>;\n        using reference = ::std::pair<T,\
    \ T>&;\n        using pointer = ::std::pair<T, T>*;\n        using iterator_category\
    \ = ::std::input_iterator_tag;\n\n        iterator() = default;\n        iterator(const\
    \ iterator&) = default;\n        iterator(iterator&&) = default;\n        ~iterator()\
    \ = default;\n        iterator& operator=(const iterator&) = default;\n      \
    \  iterator& operator=(iterator&&) = default;\n\n        iterator(distinct_prime_factor_iterable\
    \ const * const parent, const bool large, const T& i) :\n          m_parent(parent),\
    \ m_large(large), m_i(i) {\n          this->next();\n        }\n\n        ::std::pair<T,\
    \ T> operator*() const {\n          return this->m_value;\n        }\n\n     \
    \   iterator& operator++() {\n          this->next();\n          return *this;\n\
    \        }\n\n        iterator operator++(int) {\n          const iterator self\
    \ = *this;\n          ++*this;\n          return self;\n        }\n\n        friend\
    \ bool operator==(const iterator& lhs, const iterator& rhs) {\n          return\
    \ lhs.m_parent->m_n == rhs.m_parent->m_n && lhs.m_value.first == rhs.m_value.first;\n\
    \        }\n\n        friend bool operator!=(const iterator& lhs, const iterator&\
    \ rhs) {\n          return !(lhs == rhs);\n        }\n      };\n\n      distinct_prime_factor_iterable(::tools::segmented_sieve<T>\
    \ const * const parent, const T& n) :\n        m_parent(parent), m_n(n) {\n  \
    \    }\n\n      iterator begin() const {\n        if (this->m_n <= this->m_parent->lpf_max())\
    \ {\n          return iterator(this, false, this->m_n);\n        } else {\n  \
    \        return iterator(this, true, 0);\n        }\n      }\n\n      iterator\
    \ end() const {\n        return iterator(this, false, 1);\n      }\n    };\n\n\
    \    prime_factor_iterable prime_factor_range(const T& n) const {\n      assert((1\
    \ <= n && n <= this->lpf_max()) || (this->l() <= n && n <= this->r()));\n    \
    \  return prime_factor_iterable(this, n);\n    }\n\n    distinct_prime_factor_iterable\
    \ distinct_prime_factor_range(const T& n) const {\n      assert((1 <= n && n <=\
    \ this->lpf_max()) || (this->l() <= n && n <= this->r()));\n      return distinct_prime_factor_iterable(this,\
    \ n);\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/floor_sqrt.hpp
  - tools/chmin.hpp
  - tools/ceil.hpp
  - tools/detail/ceil_and_floor.hpp
  isVerificationFile: false
  path: tools/segmented_sieve.hpp
  requiredBy: []
  timestamp: '2021-12-10 01:42:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/segmented_sieve.hpp
layout: document
redirect_from:
- /library/tools/segmented_sieve.hpp
- /library/tools/segmented_sieve.hpp.html
title: tools/segmented_sieve.hpp
---
