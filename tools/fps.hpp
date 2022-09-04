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
      const int n = this->size();
      const int m = g.size();
      for (int i = 0; i < ::std::min(n, m); ++i) {
        (*this)[i] += g[i];
      }
      return *this;
    }
    F& operator-=(const F& g) {
      const int n = this->size();
      const int m = g.size();
      for (int i = 0; i < ::std::min(n, m); ++i) {
        (*this)[i] -= g[i];
      }
      return *this;
    }
    F& operator<<=(const int d) {
      const int n = this->size();
      this->insert(this->begin(), d, 0);
      this->resize(n);
      return *this;
    }
    F& operator>>=(const int d) {
      const int n = this->size();
      this->erase(this->begin(), this->begin() + ::std::min(n, d));
      this->resize(n);
      return *this;
    }
    F& multiply_inplace(const F& g, int d = -1) {
      const int n = this->size();
      if (d == -1) d = n;
      assert(d >= 0);
      F res;
      ::tools::convolution(this->cbegin(), this->cend(), g.cbegin(), g.cend(), ::std::back_inserter(res));
      res.resize(d);
      *this = ::std::move(res);
      return *this;
    }
    F multiply(const F& g, const int d = -1) const { return F(*this).multiply_inplace(g, d); }

    F inv(int d = -1) const {
      const int n = this->size();
      assert(n != 0 && (*this)[0] != M(0));
      if (d == -1) d = n;
      assert(d > 0);

      // return maximum 2^k s.t. x = 1 (mod 2^k)
      static const auto pow2_k = [](const unsigned int x) -> int {
        return (x - 1) & -(x - 1);
      };

      // If M is an NTT-friendly prime, we use a faster algorithm.
      if (::tools::is_prime(M::mod()) && ::tools::pow2(::tools::ceil_log2(d)) <= pow2_k(M::mod()) + 1) {
        F res{(*this)[0].inv()};
        for (int m = 1; m < d; m *= 2) {
          F f(this->begin(), this->begin() + ::std::min(n, 2 * m));
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
        res.resize(d);
        return res;
      }

      F res{(*this)[0].inv()};
      for (int m = 1; m < d; m *= 2) {
        F f(this->begin(), this->begin() + ::std::min(n, 2 * m));
        f *= -1;
        F r(res);
        r.multiply_inplace(r, 2 * m);
        r.multiply_inplace(f);
        r += res;
        r += res;
        res = ::std::move(r);
      }
      res.resize(d);
      return res;
    }

    F& divide_inplace(const F& g, int d = -1) {
      const int n = this->size();
      if (d == -1) d = n;
      assert(d >= 0);
      const auto g_inv = g.inv(n);
      F res;
      ::tools::convolution(this->cbegin(), this->cend(), g_inv.cbegin(), g_inv.cend(), ::std::back_inserter(res));
      res.resize(d);
      return *this;
    }
    F divide(const F& g, const int d = -1) const { return F(*this).divide_inplace(g, d); }

    // sparse
    F& multiply_inplace(::std::vector<::std::pair<int, M>> g) {
      const int n = this->size();
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
    F multiply(const ::std::vector<::std::pair<int, M>>& g) const { return F(*this).multiply_inplace(g); }

    F& divide_inplace(::std::vector<::std::pair<int, M>> g) {
      const int n = this->size();
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
    F divide(const ::std::vector<::std::pair<int, M>>& g) const { return F(*this).divide_inplace(g); }

    // multiply and divide (1 + cz^d)
    void multiply_inplace(const int d, const M c) {
      const int n = this->size();
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
    void divide_inplace(const int d, const M c) {
      const int n = this->size();
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

    F& integral_inplace() {
      const int n = this->size();
      assert(n > 0);
      if (n == 1) return *this = F{0};
      this->insert(this->begin(), 0);
      this->pop_back();
      ::std::vector<M> inv(n);
      inv[1] = M(1);
      int p = M::mod();
      for (int i = 2; i < n; ++i) {
        inv[i] = -inv[p % i] * (p / i);
      }
      for (int i = 2; i < n; ++i) {
        (*this)[i] *= inv[i];
      }
      return *this;
    }
    F integral() const { return F(*this).integral_inplace(); }

    F& derivative_inplace() {
      const int n = this->size();
      assert(n > 0);
      for (int i = 2; i < n; ++i) {
        (*this)[i] *= i;
      }
      this->erase(this->begin());
      this->push_back(0);
      return *this;
    }
    F derivative() const { return F(*this).derivative_inplace(); }

    F& log_inplace(int d = -1) {
      const int n = this->size();
      assert(n > 0 && (*this)[0] == 1);
      if (d == -1) d = n;
      assert(d >= 0);
      if (d < n) this->resize(d);
      const F f_inv = this->inv();
      this->derivative_inplace();
      this->multiply_inplace(f_inv);
      this->integral_inplace();
      return *this;
    }
    F log(const int d = -1) const { return F(*this).log_inplace(d); }

    F& exp_inplace(int d = -1) {
      const int n = this->size();
      assert(n > 0 && (*this)[0] == 0);
      if (d == -1) d = n;
      assert(d >= 0);

      // return maximum 2^k s.t. x = 1 (mod 2^k)
      static const auto pow2_k = [](const unsigned int x) -> int {
        return (x - 1) & -(x - 1);
      };

      // If M is an NTT-friendly prime, we use a faster algorithm.
      if (::tools::is_prime(M::mod()) && ::tools::pow2(::tools::ceil_log2(d)) <= pow2_k(M::mod()) + 1) {
        F g{1}, g_fft{1, 1};
        (*this)[0] = 1;
        this->resize(d);
        F h_drv(this->derivative());
        for (int m = 2; m < d; m *= 2) {
          // prepare
          F f_fft(this->begin(), this->begin() + m);
          f_fft.resize(2 * m);
          ::atcoder::internal::butterfly(f_fft);

          // Step 2.a'
          {
            F g_(m);
            for (int i = 0; i < m; ++i) {
              g_[i] = f_fft[i] * g_fft[i];
            }
            ::atcoder::internal::butterfly_inv(g_);
            g_.erase(g_.begin(), g_.begin() + m / 2);
            g_.resize(m);
            ::atcoder::internal::butterfly(g_);
            for (int i = 0; i < m; ++i) {
              g_[i] *= g_fft[i];
            }
            ::atcoder::internal::butterfly_inv(g_);
            g_.resize(m / 2);
            g_ /= M(-m) * m;
            g.insert(g.end(), g_.begin(), g_.begin() + m / 2);
          }

          // Step 2.b'--d'
          F t(this->begin(), this->begin() + m);
          t.derivative_inplace();
          {
            // Step 2.b'
            F r{h_drv.begin(), h_drv.begin() + m - 1};
            // Step 2.c'
            r.resize(m);
            ::atcoder::internal::butterfly(r);
            for (int i = 0; i < m; ++i) {
              r[i] *= f_fft[i];
            }
            ::atcoder::internal::butterfly_inv(r);
            r /= -m;
            // Step 2.d'
            t += r;
            t.insert(t.begin(), t.back());
            t.pop_back();
          }

          // Step 2.e'
          if (2 * m < d) {
            t.resize(2 * m);
            ::atcoder::internal::butterfly(t);
            g_fft = g;
            g_fft.resize(2*m);
            ::atcoder::internal::butterfly(g_fft);
            for (int i = 0; i < 2 * m; ++i) {
              t[i] *= g_fft[i];
            }
            ::atcoder::internal::butterfly_inv(t);
            t.resize(m);
            t /= 2 * m;
          } else { // この場合分けをしても数パーセントしか速くならない
            F g1(g.begin() + m / 2, g.end());
            F s1(t.begin() + m / 2, t.end());
            t.resize(m/2);
            g1.resize(m);
            ::atcoder::internal::butterfly(g1);
            t.resize(m);
            ::atcoder::internal::butterfly(t);
            s1.resize(m);
            ::atcoder::internal::butterfly(s1);
            for (int i = 0; i < m; ++i) {
              s1[i] = g_fft[i] * s1[i] + g1[i] * t[i];
            }
            for (int i = 0; i < m; ++i) {
              t[i] *= g_fft[i];
            }
            ::atcoder::internal::butterfly_inv(t);
            ::atcoder::internal::butterfly_inv(s1);
            for (int i = 0; i < m / 2; ++i) {
              t[i + m / 2] += s1[i];
            }
            t /= m;
          }

          // Step 2.f'
          F v(this->begin() + m, this->begin() + ::std::min<int>(d, 2 * m));
          v.resize(m);
          t.insert(t.begin(), m - 1, 0);
          t.push_back(0);
          t.integral_inplace();
          for (int i = 0; i < m; ++i) {
            v[i] -= t[m + i];
          }

          // Step 2.g'
          v.resize(2 * m);
          ::atcoder::internal::butterfly(v);
          for (int i = 0; i < 2 * m; ++i) {
            v[i] *= f_fft[i];
          }
          ::atcoder::internal::butterfly_inv(v);
          v.resize(m);
          v /= 2 * m;

          // Step 2.h'
          for (int i = 0; i < ::std::min(d - m, m); ++i) {
            (*this)[m + i] = v[i];
          }
        }
        return *this;
      }

      F g{1};
      for (int m = 1; m < d; m *= 2) {
        F r(g);
        r.resize(2 * m);
        r.log_inplace();
        r *= -1;
        r += F(this->begin(), this->begin() + ::std::min(n, 2 * m));
        ++r[0];
        r.multiply_inplace(g);
        g = ::std::move(r);
      }
      g.resize(d);
      *this = ::std::move(g);
      return *this;
    }
    F exp(const int d = -1) const { return F(*this).exp_inplace(d); }

    F& pow_inplace(const long long k, int d = -1) {
      const int n = this->size();
      if (d == -1) d = n;
      assert(d >= 0 && k >= 0);
      if (d == 0) {
        return *this = F(0);
      }
      if (k == 0) {
        *this = F(d);
        (*this)[0] = M(1);
        return *this;
      }
      int l = 0;
      while (l < n && (*this)[l] == M(0)) ++l;
      if (l == n || l > (d - 1) / k) {
        return *this = F(d);
      }
      M c{(*this)[l]};
      this->erase(this->begin(), this->begin() + l);
      *this /= c;
      this->log_inplace(d - l * k);
      *this *= k;
      this->exp_inplace();
      *this *= c.pow(k);
      this->insert(this->begin(), l * k, 0);
      return *this;
    }
    F pow(const long long k, const int d = -1) const { return F(*this).pow_inplace(k, d); }

    F operator*(const M& g) const { return F(*this) *= g; }
    F operator/(const M& g) const { return F(*this) /= g; }
    F operator+(const F& g) const { return F(*this) += g; }
    F operator-(const F& g) const { return F(*this) -= g; }
    F operator<<(const int d) const { return F(*this) <<= d; }
    F operator>>(const int d) const { return F(*this) >>= d; }
  };
}

#endif
