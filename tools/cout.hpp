#ifndef TOOLS_COUT_HPP
#define TOOLS_COUT_HPP

// Source: https://nyaannyaan.github.io/library/misc/fastio.hpp.html
// License: CC0 1.0 Universal
// Author: Nyaan

#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <type_traits>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <utility>

namespace tools {
  namespace detail {
    namespace ostream {
      static constexpr int SZ = 1 << 17;
      char outbuf[SZ];
      int out_right = 0;

      struct Pre {
        char num[40000];
        constexpr Pre() : num() {
          for (int i = 0; i < 10000; i++) {
            int n = i;
            for (int j = 3; j >= 0; j--) {
              num[i * 4 + j] = n % 10 + '0';
              n /= 10;
            }
          }
        }
      } constexpr pre;

      void flush() {
        ::std::fwrite(outbuf, 1, out_right, stdout);
        out_right = 0;
      }

      void wt(const char c) {
        if (out_right > SZ - 32) flush();
        outbuf[out_right++] = c;
      }

      void wt(const bool b) {
        if (out_right > SZ - 32) flush();
        outbuf[out_right++] = b ? '1' : '0';
      }

      void wt(const ::std::string& s) {
        for (int l = 0, w; l < int(s.size()); l += w) {
          w = ::std::min(int(s.size()) - l, SZ - out_right);
          ::std::memcpy(outbuf + out_right, s.data() + l, w);
          out_right += w;
          if (out_right == SZ) flush();
        }
      }

      void wt(const char * const s) {
        wt(::std::string(s));
      }

      template <typename T>
      void wt(T x) {
        if (out_right > SZ - 32) flush();
        if (!x) {
          outbuf[out_right++] = '0';
          return;
        }
        if constexpr (::std::is_signed_v<T>) {
          if (x < 0) {
            outbuf[out_right++] = '-';
            x = -x;
          }
        }
        int i = 12;
        char buf[16];
        while (x >= 10000) {
          ::std::memcpy(buf + i, pre.num + (x % 10000) * 4, 4);
          x /= 10000;
          i -= 4;
        }
        if (x < 100) {
          if (x < 10) {
            outbuf[out_right] = '0' + x;
            ++out_right;
          } else {
            ::std::uint32_t q = (::std::uint32_t(x) * 205) >> 11;
            ::std::uint32_t r = ::std::uint32_t(x) - q * 10;
            outbuf[out_right] = '0' + q;
            outbuf[out_right + 1] = '0' + r;
            out_right += 2;
          }
        } else {
          if (x < 1000) {
            ::std::memcpy(outbuf + out_right, pre.num + (x << 2) + 1, 3);
            out_right += 3;
          } else {
            ::std::memcpy(outbuf + out_right, pre.num + (x << 2), 4);
            out_right += 4;
          }
        }
        ::std::memcpy(outbuf + out_right, buf + i + 4, 12 - i);
        out_right += 12 - i;
      }

      static struct Dummy {
        Dummy() { ::std::atexit(flush); }
      } dummy;
    }
  }

  struct ostream {
    template <typename... Args>
    ::tools::ostream& operator<<(Args&&... args) {
      ::tools::detail::ostream::wt(::std::forward<Args>(args)...);
      return *this;
    }
  };

  ::tools::ostream cout;
}

#endif
