#ifndef TOOLS_CONVOLUTION_HPP
#define TOOLS_CONVOLUTION_HPP

#include <cassert>
#include <vector>
#include <type_traits>
#include <cstddef>
#include <complex>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <utility>
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
      // return maximum 2^k s.t. x = 1 (mod 2^k)
      constexpr unsigned int pow2_k(const unsigned int x) {
        assert(x != 1);
        return (x - 1) & -(x - 1);
      }

      template <typename AG, typename MM>
      ::std::vector<typename AG::T> naive(const ::std::vector<typename AG::T>& a, const ::std::vector<typename AG::T>& b) {
        static_assert(::std::is_same_v<typename AG::T, typename MM::T>);
        assert(!a.empty() && !b.empty());

        using T = typename AG::T;

        ::std::vector<T> c(a.size() + b.size() - 1, AG::e());
        for (::std::size_t i = 0; i < a.size(); ++i) {
          for (::std::size_t j = 0; j < b.size(); ++j) {
            c[i + j] = AG::op(c[i + j], MM::op(a[i], b[j]));
          }
        }

        return c;
      }

      template <typename C>
      ::std::vector<C> fft(::std::vector<C> a, ::std::vector<C> b) {
        static_assert(::std::is_same_v<C, ::std::complex<float>> || ::std::is_same_v<C, ::std::complex<double>> || ::std::is_same_v<C, ::std::complex<long double>>);
        assert(!a.empty() && !b.empty());

        using R = typename C::value_type;

        const auto original_n = a.size() + b.size() - 1;
        const auto n = ::tools::pow2(::tools::ceil_log2(original_n));
        a.resize(n);
        b.resize(n);

        ::std::vector<C> pow_root;
        pow_root.reserve(n);
        pow_root.emplace_back(1, 0);
        if (n > 1) pow_root.push_back(::std::polar<R>(1, R(2) * ::std::acos(R(-1)) / n));
        for (::std::size_t p = 2; p < n; p *= 2) {
          pow_root.push_back(pow_root[p / 2] * pow_root[p / 2]);
          for (::std::size_t i = p + 1; i < p * 2; ++i) {
            pow_root.push_back(pow_root[p] * pow_root[i - p]);
          }
        }

        const auto butterfly = [&](::std::vector<C>& f) {
          ::std::vector<C> prev(n);
          for (::std::size_t p = n / 2; p >= 1; p /= 2) {
            prev.swap(f);
            for (::std::size_t qp = 0; qp < n; qp += p) {
              for (::std::size_t r = 0; r < p; ++r) {
                f[qp + r] = prev[qp * 2 % n + r] + pow_root[qp] * prev[qp * 2 % n + p + r];
              }
            }
          }
        };

        butterfly(a);
        butterfly(b);

        ::std::vector<C> c;
        c.reserve(n);
        for (::std::size_t i = 0; i < n; ++i) {
          c.push_back(a[i] * b[i]);
        }

        ::std::reverse(::std::next(pow_root.begin()), pow_root.end());
        butterfly(c);
        for (auto& c_i : c) c_i /= n;

        c.resize(original_n);
        return c;
      }

      template <typename R>
      ::std::vector<R> fft_real(const ::std::vector<R>& a, const ::std::vector<R>& b) {
        static_assert(::std::is_floating_point_v<R>);
        assert(!a.empty() && !b.empty());

        ::std::vector<::std::complex<R>> a_complex;
        a_complex.reserve(a.size());
        for (const auto& a_i : a) a_complex.emplace_back(a_i, 0);

        ::std::vector<::std::complex<R>> b_complex;
        b_complex.reserve(b.size());
        for (const auto& b_i : b) b_complex.emplace_back(b_i, 0);

        const auto c_complex = ::tools::detail::convolution::fft(a_complex, b_complex);

        ::std::vector<R> c;
        c.reserve(c_complex.size());
        for (const auto& c_i : c_complex) c.push_back(c_i.real());

        return c;
      }

      template <typename M>
      ::std::vector<M> ntt(const ::std::vector<M>& a, const ::std::vector<M>& b) {
        static_assert(::atcoder::internal::is_static_modint<M>::value);
        static_assert(2 <= M::mod() && M::mod() <= 2000000000);
        static_assert(::tools::is_prime(M::mod()));
        assert(a.size() + b.size() <= ::tools::detail::convolution::pow2_k(M::mod()) + 1);

        return ::atcoder::convolution(a, b);
      }

      template <typename M>
      ::std::vector<M> ntt_and_garner(const ::std::vector<M>& a, const ::std::vector<M>& b) {
        using M1 = ::atcoder::static_modint<1107296257>; // 33 * 2^25 + 1
        using M2 = ::atcoder::static_modint<1711276033>; // 51 * 2^25 + 1
        using M3 = ::atcoder::static_modint<1811939329>; // 27 * 2^26 + 1

        static_assert(::atcoder::internal::is_static_modint<M>::value || ::atcoder::internal::is_dynamic_modint<M>::value);
        assert(a.size() + b.size() <= ::std::min({::tools::detail::convolution::pow2_k(M1::mod()), ::tools::detail::convolution::pow2_k(M2::mod()), ::tools::detail::convolution::pow2_k(M3::mod())}) + 1);

        // No need for the following assertion because the condition always holds.
        // assert(std::min(a.size(), b.size()) * tools::square(M::mod() - 1) < M1::mod() * M2::mod() * M3::mod());

        ::std::vector<M1> a1;
        ::std::vector<M2> a2;
        ::std::vector<M3> a3;
        a1.reserve(a.size());
        a2.reserve(a.size());
        a3.reserve(a.size());
        for (const auto& a_i : a) {
          a1.emplace_back(a_i.val());
          a2.emplace_back(a_i.val());
          a3.emplace_back(a_i.val());
        }

        ::std::vector<M1> b1;
        ::std::vector<M2> b2;
        ::std::vector<M3> b3;
        b1.reserve(b.size());
        b2.reserve(b.size());
        b3.reserve(b.size());
        for (const auto& b_i : b) {
          b1.emplace_back(b_i.val());
          b2.emplace_back(b_i.val());
          b3.emplace_back(b_i.val());
        }

        const auto c1 = ::atcoder::convolution(a1, b1);
        const auto c2 = ::atcoder::convolution(a2, b2);
        const auto c3 = ::atcoder::convolution(a3, b3);

        assert(c1.size() == c2.size() && c2.size() == c3.size());
        ::std::vector<M> c;
        c.reserve(c1.size());

        for (::std::size_t i = 0; i < c1.size(); ++i) {
          c.push_back(M::raw(::tools::garner3(c1[i], c2[i], c3[i], M::mod())));
        }
        return c;
      }

      template <typename Z>
      ::std::vector<Z> ntt_and_garner_for_ll(const ::std::vector<Z>& a, const ::std::vector<Z>& b) {
        static_assert(::std::is_integral_v<Z>);
        assert(a.size() + b.size() <= ::tools::pow2(24) + 1);

        if constexpr (::std::is_same_v<Z, long long>) {
          return ::atcoder::convolution_ll(a, b);
        } else {
          const auto c = ::atcoder::convolution_ll(::std::vector<long long>(a.begin(), a.end()), ::std::vector<long long>(b.begin(), b.end()));
          return ::std::vector<Z>(c.begin(), c.end());
        }
      }
    }
  }

  template <typename AG, typename MM, typename InputIterator, typename OutputIterator>
  void convolution(const InputIterator a_begin, const InputIterator a_end, const InputIterator b_begin, const InputIterator b_end, OutputIterator result) {
    using T = ::std::decay_t<decltype(*::std::declval<InputIterator>())>;

    if (a_begin == a_end || b_begin == b_end) return;

    ::std::vector<T> a(a_begin, a_end);
    ::std::vector<T> b(b_begin, b_end);

    auto c = [&]() {
      if constexpr (::std::is_same_v<AG, ::tools::group::plus<T>> && (::std::is_same_v<MM, ::tools::monoid::multiplies<T>> || ::std::is_same_v<MM, ::tools::group::multiplies<T>>)) {
        if constexpr (::std::is_same_v<T, ::std::complex<float>> || ::std::is_same_v<T, ::std::complex<double>> || ::std::is_same_v<T, ::std::complex<long double>>) {
          return ::tools::detail::convolution::fft(a, b);
        } else if constexpr (::std::is_floating_point_v<T>) {
          return ::tools::detail::convolution::fft_real(a, b);
        } else if constexpr (::std::is_integral_v<T>) {
          return ::tools::detail::convolution::ntt_and_garner_for_ll(a, b);
        } else if constexpr (::atcoder::internal::is_static_modint<T>::value || ::atcoder::internal::is_dynamic_modint<T>::value) {
          if constexpr (::atcoder::internal::is_static_modint<T>::value && T::mod() <= 2000000000 && ::tools::is_prime(T::mod())) {
            if (a.size() + b.size() <= ::tools::detail::convolution::pow2_k(T::mod()) + 1) {
              return ::tools::detail::convolution::ntt(a, b);
            } else {
              return ::tools::detail::convolution::ntt_and_garner(a, b);
            }
          } else {
            return ::tools::detail::convolution::ntt_and_garner(a, b);
          }
        } else {
          return ::tools::detail::convolution::naive<AG, MM>(a, b);
        }
      } else {
        return ::tools::detail::convolution::naive<AG, MM>(a, b);
      }
    }();
    ::std::move(c.begin(), c.end(), result);
  }

  template <typename InputIterator, typename OutputIterator>
  void convolution(const InputIterator a_begin, const InputIterator a_end, const InputIterator b_begin, const InputIterator b_end, OutputIterator result) {
    using T = ::std::decay_t<decltype(*::std::declval<InputIterator>())>;
    ::tools::convolution<::tools::group::plus<T>, ::tools::monoid::multiplies<T>>(a_begin, a_end, b_begin, b_end, result);
  }
}

#endif
