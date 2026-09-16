#ifndef TOOLS_PALINDROMES_HPP
#define TOOLS_PALINDROMES_HPP

#include <array>
#include <cassert>
#include <compare>
#include <cstddef>
#include <iterator>
#include <limits>
#include <ranges>
#include <type_traits>
#include "tools/int128_t.hpp"
#include "tools/non_bool_integral.hpp"

namespace tools {
  namespace detail::palindromes {
    // The standard library only accepts a signed integral type or an
    // integer-class type, which is implementation-defined, as a difference
    // type. It must not be derived from T itself, since T may be a
    // program-defined type which never qualifies.
    template <tools::non_bool_integral T>
    using difference_type = std::conditional_t<(sizeof(T) <= 8), std::ptrdiff_t, tools::int128_t>;

    template <tools::non_bool_integral T>
    inline constexpr int max_digits = std::numeric_limits<T>::digits10 + 1;

    template <tools::non_bool_integral T>
    inline constexpr std::array<T, max_digits<T>> pow10 = []() {
      std::array<T, max_digits<T>> res{};
      res[0] = 1;
      for (int i = 1; i < max_digits<T>; ++i) {
        res[i] = res[i - 1] * 10;
      }
      return res;
    }();

    // ranks<T>[d] is the number of palindromes with less than d digits.
    template <tools::non_bool_integral T>
    inline constexpr std::array<difference_type<T>, max_digits<T> + 1> ranks = []() {
      using D = difference_type<T>;
      std::array<D, max_digits<T> + 1> res{};
      // p is 10^(ceil(d / 2) - 1), the number of halves with a fixed leading digit.
      D p = 1;
      for (int d = 1; d < max_digits<T>; ++d) {
        res[d + 1] = res[d] + (d == 1 ? D(10) : D(9) * p);
        if (d % 2 == 0) p *= 10;
      }
      return res;
    }();

    template <tools::non_bool_integral T>
    constexpr int digits(const T x) {
      int d = 1;
      while (d < max_digits<T> && pow10<T>[d] <= x) ++d;
      return d;
    }

    // It returns the number of palindromes less than x.
    template <tools::non_bool_integral T>
    constexpr difference_type<T> rank(const T x) {
      if (x == 0) return 0;

      const int d = digits(x);
      const int k = (d + 1) / 2;
      const T h = x / pow10<T>[d - k];
      auto res = ranks<T>[d] + difference_type<T>(h - (d == 1 ? T(0) : pow10<T>[k - 1]));

      // The palindrome built from h shares its leading k digits with x, so
      // comparing the remaining d - k digits decides whether it is less than x.
      // They are compared as they are instead of building the palindrome,
      // which may overflow T when x is close to the maximum value of T.
      T mirrored = 0;
      for (T t = d % 2 == 1 ? h / 10 : h; t > 0; t /= 10) {
        mirrored = mirrored * 10 + t % 10;
      }
      if (mirrored < x % pow10<T>[d - k]) ++res;

      return res;
    }

    // It returns the (i + 1)-th smallest palindrome.
    template <tools::non_bool_integral T>
    constexpr T value(const difference_type<T> i) {
      int d = 1;
      while (d < max_digits<T> && ranks<T>[d + 1] <= i) ++d;
      const int k = (d + 1) / 2;
      const T h = (d == 1 ? T(0) : pow10<T>[k - 1]) + T(i - ranks<T>[d]);

      T res = h;
      for (T t = d % 2 == 1 ? h / 10 : h; t > 0; t /= 10) {
        res = res * 10 + t % 10;
      }
      return res;
    }
  }

  template <tools::non_bool_integral T>
  class palindrome_view : public std::ranges::view_interface<tools::palindrome_view<T>> {
    tools::detail::palindromes::difference_type<T> m_begin{};
    tools::detail::palindromes::difference_type<T> m_end{};

  public:
    class iterator {
      tools::detail::palindromes::difference_type<T> m_i{};

    public:
      using value_type = T;
      using reference = T;
      using pointer = void;
      using difference_type = tools::detail::palindromes::difference_type<T>;
      using iterator_category = std::input_iterator_tag;
      using iterator_concept = std::random_access_iterator_tag;

      iterator() = default;
      constexpr explicit iterator(const difference_type i) : m_i(i) {
      }

      constexpr reference operator*() const {
        return tools::detail::palindromes::value<T>(this->m_i);
      }
      constexpr reference operator[](const difference_type n) const {
        return tools::detail::palindromes::value<T>(this->m_i + n);
      }

      constexpr iterator& operator++() {
        ++this->m_i;
        return *this;
      }
      constexpr iterator operator++(int) {
        const auto self = *this;
        ++*this;
        return self;
      }
      constexpr iterator& operator--() {
        --this->m_i;
        return *this;
      }
      constexpr iterator operator--(int) {
        const auto self = *this;
        --*this;
        return self;
      }
      constexpr iterator& operator+=(const difference_type n) {
        this->m_i += n;
        return *this;
      }
      constexpr iterator& operator-=(const difference_type n) {
        this->m_i -= n;
        return *this;
      }

      friend constexpr iterator operator+(iterator it, const difference_type n) {
        return it += n;
      }
      friend constexpr iterator operator+(const difference_type n, iterator it) {
        return it += n;
      }
      friend constexpr iterator operator-(iterator it, const difference_type n) {
        return it -= n;
      }
      friend constexpr difference_type operator-(const iterator lhs, const iterator rhs) {
        return lhs.m_i - rhs.m_i;
      }

      friend constexpr bool operator==(const iterator lhs, const iterator rhs) {
        return lhs.m_i == rhs.m_i;
      }
      friend constexpr std::strong_ordering operator<=>(const iterator lhs, const iterator rhs) {
        return lhs.m_i < rhs.m_i ? std::strong_ordering::less
          : rhs.m_i < lhs.m_i ? std::strong_ordering::greater
          : std::strong_ordering::equal;
      }
    };

    palindrome_view() = default;
    constexpr palindrome_view(const T a, const T b) :
      m_begin(tools::detail::palindromes::rank(a)),
      m_end(tools::detail::palindromes::rank(b)) {
      assert(0 <= a && a <= b);
    }

    constexpr iterator begin() const {
      return iterator(this->m_begin);
    }
    constexpr iterator end() const {
      return iterator(this->m_end);
    }

    // It hides std::ranges::view_interface::size, whose return type is
    // unspecified in practice. A signed type is chosen for the same reason as
    // int is preferred to std::size_t elsewhere in this library, and the width
    // follows the difference type since the count overflows both int and
    // std::size_t for a wide enough T.
    constexpr tools::detail::palindromes::difference_type<T> size() const {
      return this->m_end - this->m_begin;
    }
  };

  template <tools::non_bool_integral M, tools::non_bool_integral N>
  constexpr tools::palindrome_view<std::common_type_t<M, N>> palindromes(const M a, const N b) {
    if constexpr (std::numeric_limits<M>::is_signed) {
      assert(a >= 0);
    }
    if constexpr (std::numeric_limits<N>::is_signed) {
      assert(b >= 0);
    }
    using T = std::common_type_t<M, N>;
    return tools::palindrome_view<T>(T(a), T(b));
  }
}

namespace std::ranges {
  template <typename T>
  inline constexpr bool enable_borrowed_range<tools::palindrome_view<T>> = true;
}

#endif
