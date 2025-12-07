#ifndef TOOLS_CONVOLUTION_HPP
#define TOOLS_CONVOLUTION_HPP

#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <concepts>
#include <cstddef>
#include <iterator>
#include <ranges>
#include <type_traits>
#include <utility>
#include <vector>
#include "atcoder/convolution.hpp"
#include "atcoder/modint.hpp"
#include "tools/available_for_multiple_range_adaptors.hpp"
#include "tools/ceil_log2.hpp"
#include "tools/complex.hpp"
#include "tools/garner3.hpp"
#include "tools/groups.hpp"
#include "tools/is_prime.hpp"
#include "tools/modint.hpp"
#include "tools/monoids.hpp"
#include "tools/pow2.hpp"
#include "tools/ring.hpp"
#include "tools/rings.hpp"

namespace tools {
  namespace detail {
    namespace convolution {
      template <tools::ring R, std::ranges::forward_range R1, std::ranges::forward_range R2>
      requires std::same_as<std::ranges::range_value_t<R1>, std::ranges::range_value_t<R2>>
            && std::assignable_from<typename R::add::T&, std::ranges::range_value_t<R1>>
      auto naive(R1&& a, R2&& b) {
        assert(!std::ranges::empty(a));
        assert(!std::ranges::empty(b));

        using Add = typename R::add;
        using Mul = typename R::mul;
        using T = typename Add::T;

        const auto n = std::ranges::distance(a);
        const auto m = std::ranges::distance(b);

        std::vector<T> c(n + m - 1, Add::e());
        if (n < m) {
          auto it1 = c.begin();
          for (const auto& b_j : b) {
            auto it2 = it1;
            for (const auto& a_i : a) {
              *it2 = Add::op(*it2, Mul::op(a_i, b_j));
              ++it2;
            }
            ++it1;
          }
        } else {
          auto it1 = c.begin();
          for (const auto& a_i : a) {
            auto it2 = it1;
            for (const auto& b_j : b) {
              *it2 = Add::op(*it2, Mul::op(a_i, b_j));
              ++it2;
            }
            ++it1;
          }
        }

        return c;
      }

      template <std::ranges::input_range R1, std::ranges::input_range R2>
      requires std::same_as<std::ranges::range_value_t<R1>, std::ranges::range_value_t<R2>>
            && (std::floating_point<std::ranges::range_value_t<R1>> || tools::complex<std::ranges::range_value_t<R1>>)
      auto fft(R1&& pa, R2&& pb) {
        using T = std::ranges::range_value_t<R1>;
        using C = std::conditional_t<std::floating_point<T>, std::complex<T>, T>;
        using R = typename C::value_type;

        assert(!std::ranges::empty(pa));
        assert(!std::ranges::empty(pb));

        std::vector<C> a, b;
        if constexpr (std::same_as<T, R>) {
          for (auto&& a_i : pa) {
            a.emplace_back(std::forward<decltype(a_i)>(a_i), 0);
          }
          for (auto&& b_i : pb) {
            b.emplace_back(std::forward<decltype(b_i)>(b_i), 0);
          }
        } else {
          a = std::forward<R1>(pa) | std::ranges::to<std::vector<C>>();
          b = std::forward<R2>(pb) | std::ranges::to<std::vector<C>>();
        }
        const auto n = a.size() + b.size() - 1;
        const auto z = tools::pow2(tools::ceil_log2(n));
        a.resize(z);
        b.resize(z);

        std::vector<C> pow_root;
        pow_root.reserve(z);
        pow_root.emplace_back(1, 0);
        if (z > 1) pow_root.push_back(std::polar<R>(1, R(2) * std::acos(R(-1)) / z));
        for (std::size_t p = 2; p < z; p *= 2) {
          pow_root.push_back(pow_root[p / 2] * pow_root[p / 2]);
          for (std::size_t i = p + 1; i < p * 2; ++i) {
            pow_root.push_back(pow_root[p] * pow_root[i - p]);
          }
        }

        const auto butterfly = [&](std::vector<C>& f) {
          std::vector<C> prev(z);
          for (std::size_t p = z / 2; p >= 1; p /= 2) {
            prev.swap(f);
            for (std::size_t qp = 0; qp < z; qp += p) {
              for (std::size_t r = 0; r < p; ++r) {
                f[qp + r] = prev[qp * 2 % z + r] + pow_root[qp] * prev[qp * 2 % z + p + r];
              }
            }
          }
        };

        butterfly(a);
        butterfly(b);

        for (std::size_t i = 0; i < z; ++i) {
          a[i] *= b[i];
        }

        std::reverse(std::next(pow_root.begin()), pow_root.end());
        butterfly(a);

        if constexpr (std::same_as<T, R>) {
          std::vector<T> c;
          c.reserve(n);
          for (std::size_t i = 0; i < n; ++i) {
            c.push_back(a[i].real() / z);
          }
          return c;
        } else {
          a.resize(n);
          for (auto& a_i : a) {
            a_i /= z;
          }
          return a;
        }
      }

      template <std::ranges::input_range R1, std::ranges::input_range R2>
      requires (std::same_as<std::ranges::range_value_t<R1>, std::ranges::range_value_t<R2>>
            && atcoder::internal::is_static_modint<std::ranges::range_value_t<R1>>::value
            && std::ranges::range_value_t<R1>::mod() <= 2000000000
            && tools::is_prime(std::ranges::range_value_t<R1>::mod()))
      auto ntt(R1&& pa, R2&& pb) {
        using M = std::ranges::range_value_t<R1>;
        
        assert(!std::ranges::empty(pa));
        assert(!std::ranges::empty(pb));

        auto a = std::forward<R1>(pa) | std::ranges::to<std::vector<M>>();
        auto b = std::forward<R2>(pb) | std::ranges::to<std::vector<M>>();
        const auto n = a.size();
        const auto m = b.size();
        const auto z = tools::pow2(tools::ceil_log2(n + m - 1));
        assert((M::mod() - 1) % z == 0);

        if (n == m && 4 * n == z + 4) {

          const auto afbf = a.front() * b.front();
          const auto abbb = a.back() * b.back();

          a.resize(z / 2);
          atcoder::internal::butterfly(a);

          b.resize(z / 2);
          atcoder::internal::butterfly(b);

          for (std::size_t i = 0; i < z / 2; ++i) {
            a[i] *= b[i];
          }

          atcoder::internal::butterfly_inv(a);
          const auto iz = M(z / 2).inv();

          a.resize(n + m - 1);
          a.front() = afbf;
          for (auto it = std::next(a.begin()), end = std::prev(a.end()); it != end; ++it) {
            *it *= iz;
          }
          a.back() = abbb;

        } else {

          a.resize(z);
          atcoder::internal::butterfly(a);

          b.resize(z);
          atcoder::internal::butterfly(b);

          for (std::size_t i = 0; i < z; ++i) {
            a[i] *= b[i];
          }

          atcoder::internal::butterfly_inv(a);
          const auto iz = M(z).inv();

          a.resize(n + m - 1);
          for (auto& a_i : a) {
            a_i *= iz;
          }

        }

        return a;
      }

      template <std::ranges::input_range R1, std::ranges::input_range R2>
      requires std::same_as<std::ranges::range_value_t<R1>, std::ranges::range_value_t<R2>>
            && tools::modint<std::ranges::range_value_t<R1>>
      auto ntt_and_garner(R1&& a, R2&& b) {
        using M = std::ranges::range_value_t<R1>;

        if constexpr (tools::available_for_multiple_range_adaptors<R1> && tools::available_for_multiple_range_adaptors<R2>) {
          using M1 = atcoder::static_modint<1107296257>; // 33 * 2^25 + 1
          using M2 = atcoder::static_modint<1711276033>; // 51 * 2^25 + 1
          using M3 = atcoder::static_modint<1811939329>; // 27 * 2^26 + 1

          assert(!std::ranges::empty(a));
          assert(!std::ranges::empty(b));

          const auto n = std::ranges::distance(a);
          const auto m = std::ranges::distance(b);
          const auto z = tools::pow2(tools::ceil_log2(n + m - 1));

          assert((M1::mod() - 1) % z == 0);
          assert((M2::mod() - 1) % z == 0);
          assert((M3::mod() - 1) % z == 0);

          // No need for the following assertion because the condition always holds.
          // assert(std::min(n, m) * tools::square(M::mod() - 1) < M1::mod() * M2::mod() * M3::mod());

          return std::views::zip_transform(
            [](const auto c1_i, const auto c2_i, const auto c3_i) {
              return M::raw(tools::garner3(c1_i, c2_i, c3_i, M::mod()));
            },
            tools::detail::convolution::ntt(
              a | std::views::transform([](const auto a_i) { return M1(a_i.val()); }),
              b | std::views::transform([](const auto b_i) { return M1(b_i.val()); })
            ),
            tools::detail::convolution::ntt(
              a | std::views::transform([](const auto a_i) { return M2(a_i.val()); }),
              b | std::views::transform([](const auto b_i) { return M2(b_i.val()); })
            ),
            tools::detail::convolution::ntt(
              a | std::views::transform([](const auto a_i) { return M3(a_i.val()); }),
              b | std::views::transform([](const auto b_i) { return M3(b_i.val()); })
            )
          ) | std::ranges::to<std::vector<M>>();
        } else {
          const auto va = std::forward<R1>(a) | std::ranges::to<std::vector<M>>();
          const auto vb = std::forward<R2>(b) | std::ranges::to<std::vector<M>>();
          return tools::detail::convolution::ntt_and_garner(va, vb);
        }
      }

      template <std::ranges::input_range R1, std::ranges::input_range R2>
      requires std::same_as<std::ranges::range_value_t<R1>, std::ranges::range_value_t<R2>>
            && std::integral<std::ranges::range_value_t<R1>>
      auto ntt_and_garner_for_ll(R1&& a, R2&& b) {
        using Z = std::ranges::range_value_t<R1>;
        using ll = long long;

        return atcoder::convolution_ll(
          std::forward<R1>(a) | std::ranges::to<std::vector<ll>>(),
          std::forward<R2>(b) | std::ranges::to<std::vector<ll>>()
        ) | std::ranges::to<std::vector<Z>>();
      }
    }
  }

  template <tools::ring R, std::ranges::input_range R1, std::ranges::input_range R2>
  requires std::same_as<std::ranges::range_value_t<R1>, std::ranges::range_value_t<R2>>
        && std::assignable_from<typename R::add::T&, std::ranges::range_value_t<R1>>
  auto convolution(R1&& a, R2&& b) {
    if constexpr (std::ranges::forward_range<R1> && std::ranges::forward_range<R2>) {
      using Add = typename R::add;
      using Mul = typename R::mul;
      using T = typename Add::T;

      if (std::ranges::empty(a) || std::ranges::empty(b)) {
        return std::vector<T>{};
      }

      const auto n = std::ranges::distance(a);
      const auto m = std::ranges::distance(b);

      if (std::min(n, m) <= 60) {
        return tools::detail::convolution::naive<R>(std::forward<R1>(a), std::forward<R2>(b));
      }

      if constexpr (std::same_as<Add, tools::groups::plus<T>> && (std::same_as<Mul, tools::monoids::multiplies<T>> || std::same_as<Mul, tools::groups::multiplies<T>>)) {
        if constexpr (std::floating_point<T> || tools::complex<T>) {
          return tools::detail::convolution::fft(std::forward<R1>(a), std::forward<R2>(b));
        } else if constexpr (std::integral<T>) {
          return tools::detail::convolution::ntt_and_garner_for_ll(std::forward<R1>(a), std::forward<R2>(b));
        } else if constexpr (tools::modint<T>) {
          if constexpr (atcoder::internal::is_static_modint<T>::value && T::mod() <= 2000000000 && tools::is_prime(T::mod())) {
            if ((T::mod() - 1) % tools::pow2(tools::ceil_log2(n + m - 1)) == 0) {
              return tools::detail::convolution::ntt(std::forward<R1>(a), std::forward<R2>(b));
            } else {
              return tools::detail::convolution::ntt_and_garner(std::forward<R1>(a), std::forward<R2>(b));
            }
          } else {
            return tools::detail::convolution::ntt_and_garner(std::forward<R1>(a), std::forward<R2>(b));
          }
        } else {
          return tools::detail::convolution::naive<R>(std::forward<R1>(a), std::forward<R2>(b));
        }
      } else {
        return tools::detail::convolution::naive<R>(std::forward<R1>(a), std::forward<R2>(b));
      }
    } else {
      return tools::convolution(
        std::forward<R1>(a) | std::ranges::to<std::vector<std::ranges::range_value_t<R1>>>(),
        std::forward<R2>(b) | std::ranges::to<std::vector<std::ranges::range_value_t<R2>>>()
      );
    }
  }

  template <std::ranges::input_range R1, std::ranges::input_range R2>
  requires std::same_as<std::ranges::range_value_t<R1>, std::ranges::range_value_t<R2>>
  auto convolution(R1&& a, R2&& b) {
    return tools::convolution<tools::rings::plus_multiplies<std::ranges::range_value_t<R1>>>(std::forward<R1>(a), std::forward<R2>(b));
  }
}

#endif
