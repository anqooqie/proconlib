#ifndef TOOLS_FPS_HPP
#define TOOLS_FPS_HPP

#include <vector>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <utility>
#include "atcoder/convolution.hpp"
#include "tools/convolution.hpp"
#include "tools/pow2.hpp"
#include "tools/ceil_log2.hpp"
#include "tools/ssize.hpp"

// Source: https://opt-cp.com/fps-implementation/
// License: CC0
// Author: opt

namespace tools {
  template <typename M>
  class fps : public ::std::vector<M> {
  private:
    using F = ::tools::fps<M>;

  public:
    using ::std::vector<M>::vector;
    using ::std::vector<M>::operator=;

    F operator-() const {
      F res(*this);
      for (auto& e : res) {
        e = -e;
      }
      return res;
    }
    F& operator*=(const M& g) {
      for (auto& e : *this) {
        e *= g;
      }
      return *this;
    }
    F& operator/=(const M& g) {
      assert(g != M(0));
      *this *= g.inv();
      return *this;
    }
    F& operator+=(const F& g) {
      const int n = (*this).size();
      const int m = g.size();
      for (int i = 0; i < ::std::min(n, m); ++i) {
        (*this)[i] += g[i];
      }
      return *this;
    }
    F& operator-=(const F& g) {
      const int n = (*this).size();
      const int m = g.size();
      for (int i = 0; i < ::std::min(n, m); ++i) {
        (*this)[i] -= g[i];
      }
      return *this;
    }
    F& operator<<=(const int d) {
      const int n = (*this).size();
      (*this).insert((*this).begin(), d, 0);
      (*this).resize(n);
      return *this;
    }
    F& operator>>=(const int d) {
      const int n = (*this).size();
      (*this).erase((*this).begin(), (*this).begin() + ::std::min(n, d));
      (*this).resize(n);
      return *this;
    }
    F& operator*=(const F& g) {
      const int n = (*this).size();
      F res;
      ::tools::convolution((*this).cbegin(), (*this).cend(), g.cbegin(), g.cend(), ::std::back_inserter(res));
      res.resize(n);
      *this = ::std::move(res);
      return *this;
    }

    F inv(int d = -1) const {
      const int n = (*this).size();
      assert(n != 0 && (*this)[0] != M(0));
      if (d == -1) d = n;
      assert(d > 0);
      F res{(*this)[0].inv()};

      // return maximum 2^k s.t. x = 1 (mod 2^k)
      static const auto pow2_k = [](const unsigned int x) -> int {
        return (x - 1) & -(x - 1);
      };

      // If M is an NTT-friendly prime, we use a faster algorithm.
      if (::tools::is_prime(M::mod()) && ::tools::pow2(::tools::ceil_log2(d)) <= pow2_k(M::mod()) + 1) {
        while (::tools::ssize(res) < d) {
          const int m = res.size();
          F f((*this).begin(), (*this).begin() + ::std::min(n, 2 * m));
          F r(res);
          f.resize(2 * m);
          ::atcoder::internal::butterfly(f);
          r.resize(2 * m);
          ::atcoder::internal::butterfly(r);
          for (int i = 0; i < 2 * m; ++i) {
            f[i] *= r[i];
          }
          ::atcoder::internal::butterfly_inv(f);
          f.erase(f.begin(), f.begin() + m);
          f.resize(2 * m);
          ::atcoder::internal::butterfly(f);
          for (int i = 0; i < 2 * m; ++i) {
            f[i] *= r[i];
          }
          ::atcoder::internal::butterfly_inv(f);
          M iz = M(2 * m).inv();
          iz *= -iz;
          for (int i = 0; i < m; ++i) {
            f[i] *= iz;
          }
          res.insert(res.end(), f.begin(), f.begin() + m);
        }
        return {res.begin(), res.begin() + d};
      }

      while (::tools::ssize(res) < d) {
        const int m = res.size();
        F f((*this).begin(), (*this).begin() + ::std::min(n, 2 * m));
        f *= -1;
        F r(res);
        r.resize(2 * m);
        r *= r;
        r *= f;
        r += res;
        r += res;
        res = ::std::move(r);
      }
      return {res.begin(), res.begin() + d};
    }

    F& operator/=(const F& g) {
      const int n = (*this).size();
      const auto g_inv = g.inv(n);
      F res;
      ::tools::convolution((*this).cbegin(), (*this).cend(), g_inv.cbegin(), g_inv.cend(), ::std::back_inserter(res));
      res.resize(n);
      *this = ::std::move(res);
      return *this;
    }

    // sparse
    F& operator*=(::std::vector<::std::pair<int, M>> g) {
      const int n = (*this).size();
      auto [d, c] = g.front();
      if (d == 0) {
        g.erase(g.begin());
      } else {
        c = 0;
      }
      for (int i = n - 1; i >= 0; --i) {
        (*this)[i] *= c;
        for (auto& [j, b] : g) {
          if (j > i) break;
          (*this)[i] += (*this)[i - j] * b;
        }
      }
      return *this;
    }
    F& operator/=(::std::vector<::std::pair<int, M>> g) {
      const int n = (*this).size();
      auto [d, c] = g.front();
      assert(d == 0 && c != M(0));
      const M ic = c.inv();
      g.erase(g.begin());
      for (int i = 0; i < n; ++i) {
        for (auto& [j, b] : g) {
          if (j > i) break;
          (*this)[i] -= (*this)[i - j] * b;
        }
        (*this)[i] *= ic;
      }
      return *this;
    }

    // multiply and divide (1 + cz^d)
    void multiply(const int d, const M c) { 
      const int n = (*this).size();
      if (c == M(1)) {
        for (int i = n - d - 1; i >= 0; --i) {
          (*this)[i + d] += (*this)[i];
        }
      } else if (c == M(-1)) {
        for (int i = n - d - 1; i >= 0; --i) {
          (*this)[i + d] -= (*this)[i];
        }
      } else {
        for (int i = n - d - 1; i >= 0; --i) {
          (*this)[i + d] += (*this)[i] * c;
        }
      }
    }
    void divide(const int d, const M c) {
      const int n = (*this).size();
      if (c == M(1)) {
        for (int i = n - d - 1; i >= 0; --i) {
          (*this)[i + d] -= (*this)[i];
        }
      } else if (c == M(-1)) {
        for (int i = n - d - 1; i >= 0; --i) {
          (*this)[i + d] += (*this)[i];
        }
      } else {
        for (int i = n - d - 1; i >= 0; --i) {
          (*this)[i + d] -= (*this)[i] * c;
        }
      }
    }

    M eval(const M& a) const {
      M x(1);
      M res(0);
      for (auto e : *this) {
        res += e * x;
        x *= a;
      }
      return res;
    }

    F operator*(const M& g) const { return F(*this) *= g; }
    F operator/(const M& g) const { return F(*this) /= g; }
    F operator+(const F& g) const { return F(*this) += g; }
    F operator-(const F& g) const { return F(*this) -= g; }
    F operator<<(const int d) const { return F(*this) <<= d; }
    F operator>>(const int d) const { return F(*this) >>= d; }
    F operator*(const F& g) const { return F(*this) *= g; }
    F operator/(const F& g) const { return F(*this) /= g; }
    F operator*(::std::vector<::std::pair<int, M>> g) const { return F(*this) *= g; }
    F operator/(::std::vector<::std::pair<int, M>> g) const { return F(*this) /= g; }
  };
}

#endif
