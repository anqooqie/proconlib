#ifndef TOOLS_CONVOLUTION_HPP
#define TOOLS_CONVOLUTION_HPP

#include <type_traits>
#include <complex>
#include <cassert>
#include <vector>
#include <iterator>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <cmath>
#include <iterator>
#include "atcoder/modint.hpp"
#include "atcoder/convolution.hpp"
#include "tools/pow2.hpp"
#include "tools/ceil_log2.hpp"
#include "tools/is_prime.hpp"
#include "tools/garner3.hpp"
#include "tools/group.hpp"
#include "tools/monoid.hpp"

namespace tools {
  namespace detail {
    namespace convolution {
      template <typename T, typename = void>
      struct make_complex {
        using type = T;
      };

      template <typename T>
      struct make_complex<T, ::std::enable_if_t<::std::is_floating_point_v<T>, void>> {
        using type = ::std::complex<T>;
      };

      template <typename T>
      using make_complex_t = typename ::tools::detail::convolution::make_complex<T>::type;

      template <typename AG, typename MM, typename InputIterator1, typename InputIterator2, typename OutputIterator>
      void naive(const InputIterator1 a_begin, const InputIterator1 a_end, const InputIterator2 b_begin, const InputIterator2 b_end, OutputIterator result) {
        static_assert(::std::is_same_v<typename AG::T, typename MM::T>);
        assert(a_begin != a_end);
        assert(b_begin != b_end);

        using T = typename AG::T;

        const auto n = ::std::distance(a_begin, a_end);
        const auto m = ::std::distance(b_begin, b_end);

        ::std::vector<T> c(n + m - 1, AG::e());
        if (n < m) {
          auto c_begin = c.begin();
          for (auto b_it = b_begin; b_it != b_end; ++b_it, ++c_begin) {
            auto c_it = c_begin;
            for (auto a_it = a_begin; a_it != a_end; ++a_it, ++c_it) {
              *c_it = AG::op(*c_it, MM::op(*a_it, *b_it));
            }
          }
        } else {
          auto c_begin = c.begin();
          for (auto a_it = a_begin; a_it != a_end; ++a_it, ++c_begin) {
            auto c_it = c_begin;
            for (auto b_it = b_begin; b_it != b_end; ++b_it, ++c_it) {
              *c_it = AG::op(*c_it, MM::op(*a_it, *b_it));
            }
          }
        }

        ::std::move(c.begin(), c.end(), result);
      }

      template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
      void fft(const InputIterator1 a_begin, const InputIterator1 a_end, const InputIterator2 b_begin, const InputIterator2 b_end, OutputIterator result) {
        using T = ::std::decay_t<decltype(*::std::declval<InputIterator1>())>;
        static_assert(::std::is_same_v<T, ::std::decay_t<decltype(*::std::declval<InputIterator2>())>>);
        using C = ::tools::detail::convolution::make_complex_t<T>;
        static_assert(::std::is_same_v<C, ::std::complex<float>> || ::std::is_same_v<C, ::std::complex<double>> || ::std::is_same_v<C, ::std::complex<long double>>);
        using R = typename C::value_type;

        assert(a_begin != a_end);
        assert(b_begin != b_end);

        ::std::vector<C> a, b;
        if constexpr (::std::is_same_v<T, R>) {
          for (auto it = a_begin; it != a_end; ++it) {
            a.emplace_back(*it, 0);
          }
          for (auto it = b_begin; it != b_end; ++it) {
            b.emplace_back(*it, 0);
          }
        } else if constexpr (::std::is_same_v<T, C>) {
          a.assign(a_begin, a_end);
          b.assign(b_begin, b_end);
        }
        const auto n = a.size() + b.size() - 1;
        const auto z = ::tools::pow2(::tools::ceil_log2(n));
        a.resize(z);
        b.resize(z);

        ::std::vector<C> pow_root;
        pow_root.reserve(z);
        pow_root.emplace_back(1, 0);
        if (z > 1) pow_root.push_back(::std::polar<R>(1, R(2) * ::std::acos(R(-1)) / z));
        for (::std::size_t p = 2; p < z; p *= 2) {
          pow_root.push_back(pow_root[p / 2] * pow_root[p / 2]);
          for (::std::size_t i = p + 1; i < p * 2; ++i) {
            pow_root.push_back(pow_root[p] * pow_root[i - p]);
          }
        }

        const auto butterfly = [&](::std::vector<C>& f) {
          ::std::vector<C> prev(z);
          for (::std::size_t p = z / 2; p >= 1; p /= 2) {
            prev.swap(f);
            for (::std::size_t qp = 0; qp < z; qp += p) {
              for (::std::size_t r = 0; r < p; ++r) {
                f[qp + r] = prev[qp * 2 % z + r] + pow_root[qp] * prev[qp * 2 % z + p + r];
              }
            }
          }
        };

        butterfly(a);
        butterfly(b);

        for (::std::size_t i = 0; i < z; ++i) {
          a[i] *= b[i];
        }

        ::std::reverse(::std::next(pow_root.begin()), pow_root.end());
        butterfly(a);

        for (::std::size_t i = 0; i < n; ++i) {
          if constexpr (::std::is_same_v<T, R>) {
            *result = a[i].real() / z;
          } else {
            *result = a[i] / z;
          }
          ++result;
        }
      }

      template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
      void ntt(const InputIterator1 a_begin, const InputIterator1 a_end, const InputIterator2 b_begin, const InputIterator2 b_end, OutputIterator result) {
        using M = ::std::decay_t<decltype(*::std::declval<InputIterator1>())>;
        static_assert(::std::is_same_v<M, ::std::decay_t<decltype(*::std::declval<InputIterator2>())>>);

        static_assert(::atcoder::internal::is_static_modint<M>::value);
        static_assert(2 <= M::mod() && M::mod() <= 2000000000);
        static_assert(::tools::is_prime(M::mod()));
        assert(a_begin != a_end);
        assert(b_begin != b_end);

        ::std::vector<M> a(a_begin, a_end);
        ::std::vector<M> b(b_begin, b_end);
        const auto n = a.size();
        const auto m = b.size();
        const auto z = ::tools::pow2(::tools::ceil_log2(n + m - 1));
        assert((M::mod() - 1) % z == 0);

        if (n == m && 4 * n == z + 4) {

          const auto afbf = a.front() * b.front();
          const auto abbb = a.back() * b.back();

          a.resize(z / 2);
          ::atcoder::internal::butterfly(a);

          b.resize(z / 2);
          ::atcoder::internal::butterfly(b);

          for (::std::size_t i = 0; i < z / 2; ++i) {
            a[i] *= b[i];
          }

          ::atcoder::internal::butterfly_inv(a);
          const auto iz = M(z / 2).inv();

          *result = afbf;
          ++result;
          for (::std::size_t i = 1; i < n + m - 2; ++i) {
            *result = a[i] * iz;
            ++result;
          }
          *result = abbb;
          ++result;

        } else {

          a.resize(z);
          ::atcoder::internal::butterfly(a);

          b.resize(z);
          ::atcoder::internal::butterfly(b);

          for (::std::size_t i = 0; i < z; ++i) {
            a[i] *= b[i];
          }

          ::atcoder::internal::butterfly_inv(a);
          const auto iz = M(z).inv();

          for (::std::size_t i = 0; i < n + m - 1; ++i) {
            *result = a[i] * iz;
            ++result;
          }

        }
      }

      template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
      void ntt_and_garner(const InputIterator1 a_begin, const InputIterator1 a_end, const InputIterator2 b_begin, const InputIterator2 b_end, OutputIterator result) {
        using M = ::std::decay_t<decltype(*::std::declval<InputIterator1>())>;
        static_assert(::std::is_same_v<M, ::std::decay_t<decltype(*::std::declval<InputIterator2>())>>);
        using M1 = ::atcoder::static_modint<1107296257>; // 33 * 2^25 + 1
        using M2 = ::atcoder::static_modint<1711276033>; // 51 * 2^25 + 1
        using M3 = ::atcoder::static_modint<1811939329>; // 27 * 2^26 + 1

        static_assert(::atcoder::internal::is_static_modint<M>::value || ::atcoder::internal::is_dynamic_modint<M>::value);
        assert(a_begin != a_end);
        assert(b_begin != b_end);

        const auto n = ::std::distance(a_begin, a_end);
        const auto m = ::std::distance(b_begin, b_end);
        const auto z = ::tools::pow2(::tools::ceil_log2(n + m - 1));

        assert((M1::mod() - 1) % z == 0);
        assert((M2::mod() - 1) % z == 0);
        assert((M3::mod() - 1) % z == 0);

        // No need for the following assertion because the condition always holds.
        // assert(std::min(a.size(), b.size()) * tools::square(M::mod() - 1) < M1::mod() * M2::mod() * M3::mod());

        ::std::vector<M1> c1;
        c1.reserve(n + m - 1);
        {
          ::std::vector<M1> a1;
          a1.reserve(n);
          for (auto it = a_begin; it != a_end; ++it) {
            a1.emplace_back(it->val());
          }

          ::std::vector<M1> b1;
          b1.reserve(m);
          for (auto it = b_begin; it != b_end; ++it) {
            b1.emplace_back(it->val());
          }

          ::tools::detail::convolution::ntt(a1.begin(), a1.end(), b1.begin(), b1.end(), ::std::back_inserter(c1));
        }

        ::std::vector<M2> c2;
        c2.reserve(n + m - 1);
        {
          ::std::vector<M2> a2;
          a2.reserve(n);
          for (auto it = a_begin; it != a_end; ++it) {
            a2.emplace_back(it->val());
          }

          ::std::vector<M2> b2;
          b2.reserve(m);
          for (auto it = b_begin; it != b_end; ++it) {
            b2.emplace_back(it->val());
          }

          ::tools::detail::convolution::ntt(a2.begin(), a2.end(), b2.begin(), b2.end(), ::std::back_inserter(c2));
        }

        ::std::vector<M3> c3;
        c3.reserve(n + m - 1);
        {
          ::std::vector<M3> a3;
          a3.reserve(n);
          for (auto it = a_begin; it != a_end; ++it) {
            a3.emplace_back(it->val());
          }

          ::std::vector<M3> b3;
          b3.reserve(m);
          for (auto it = b_begin; it != b_end; ++it) {
            b3.emplace_back(it->val());
          }

          ::tools::detail::convolution::ntt(a3.begin(), a3.end(), b3.begin(), b3.end(), ::std::back_inserter(c3));
        }

        for (::std::size_t i = 0; i < c1.size(); ++i) {
          *result = M::raw(::tools::garner3(c1[i], c2[i], c3[i], M::mod()));
          ++result;
        }
      }

      template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
      void ntt_and_garner_for_ll(const InputIterator1 a_begin, const InputIterator1 a_end, const InputIterator2 b_begin, const InputIterator2 b_end, OutputIterator result) {
        using Z = ::std::decay_t<decltype(*::std::declval<InputIterator1>())>;
        static_assert(::std::is_same_v<Z, ::std::decay_t<decltype(*::std::declval<InputIterator2>())>>);
        using ll = long long;

        static_assert(::std::is_integral_v<Z>);
        assert(a_begin != a_end);
        assert(b_begin != b_end);

        const auto n = ::std::distance(a_begin, a_end);
        const auto m = ::std::distance(b_begin, b_end);
        assert(n + m - 1 <= ::tools::pow2(24));

        ::std::vector<ll> a, b;
        a.reserve(n);
        b.reserve(m);
        ::std::copy(a_begin, a_end, ::std::back_inserter(a));
        ::std::copy(b_begin, b_end, ::std::back_inserter(b));

        for (const auto c_i : ::atcoder::convolution_ll(a, b)) {
          *result = c_i;
          ++result;
        }
      }
    }
  }

  template <typename AG, typename MM, typename InputIterator1, typename InputIterator2, typename OutputIterator>
  void convolution(const InputIterator1 a_begin, const InputIterator1 a_end, const InputIterator2 b_begin, const InputIterator2 b_end, OutputIterator result) {
    using T = ::std::decay_t<decltype(*::std::declval<InputIterator1>())>;
    static_assert(::std::is_same_v<T, ::std::decay_t<decltype(*::std::declval<InputIterator2>())>>);

    if (a_begin == a_end || b_begin == b_end) return;

    const auto n = ::std::distance(a_begin, a_end);
    const auto m = ::std::distance(b_begin, b_end);
    if (::std::min(n, m) <= 60) {
      ::tools::detail::convolution::naive<AG, MM>(a_begin, a_end, b_begin, b_end, result);
      return;
    }

    if constexpr (::std::is_same_v<AG, ::tools::group::plus<T>> && (::std::is_same_v<MM, ::tools::monoid::multiplies<T>> || ::std::is_same_v<MM, ::tools::group::multiplies<T>>)) {
      if constexpr (::std::is_floating_point_v<T> || ::std::is_same_v<T, ::std::complex<float>> || ::std::is_same_v<T, ::std::complex<double>> || ::std::is_same_v<T, ::std::complex<long double>>) {
        ::tools::detail::convolution::fft(a_begin, a_end, b_begin, b_end, result);
      } else if constexpr (::std::is_integral_v<T>) {
        ::tools::detail::convolution::ntt_and_garner_for_ll(a_begin, a_end, b_begin, b_end, result);
      } else if constexpr (::atcoder::internal::is_static_modint<T>::value || ::atcoder::internal::is_dynamic_modint<T>::value) {
        if constexpr (::atcoder::internal::is_static_modint<T>::value && T::mod() <= 2000000000 && ::tools::is_prime(T::mod())) {
          if ((T::mod() - 1) % ::tools::pow2(::tools::ceil_log2(n + m - 1)) == 0) {
            ::tools::detail::convolution::ntt(a_begin, a_end, b_begin, b_end, result);
          } else {
            ::tools::detail::convolution::ntt_and_garner(a_begin, a_end, b_begin, b_end, result);
          }
        } else {
          ::tools::detail::convolution::ntt_and_garner(a_begin, a_end, b_begin, b_end, result);
        }
      } else {
        ::tools::detail::convolution::naive<AG, MM>(a_begin, a_end, b_begin, b_end, result);
      }
    } else {
      ::tools::detail::convolution::naive<AG, MM>(a_begin, a_end, b_begin, b_end, result);
    }
  }

  template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
  void convolution(const InputIterator1 a_begin, const InputIterator1 a_end, const InputIterator2 b_begin, const InputIterator2 b_end, const OutputIterator result) {
    using T = ::std::decay_t<decltype(*::std::declval<InputIterator1>())>;
    static_assert(::std::is_same_v<T, ::std::decay_t<decltype(*::std::declval<InputIterator2>())>>);
    ::tools::convolution<::tools::group::plus<T>, ::tools::monoid::multiplies<T>>(a_begin, a_end, b_begin, b_end, result);
  }
}

#endif
