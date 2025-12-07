#ifndef TOOLS_CIN_HPP
#define TOOLS_CIN_HPP

#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <type_traits>
#include <iostream>
#include <utility>

// Source: https://nyaannyaan.github.io/library/misc/fastio.hpp.html
// License: CC0 1.0 Universal
// Author: Nyaan

namespace tools {
  namespace detail {
    namespace istream {
      static constexpr int SZ = 1 << 17;
      char inbuf[SZ];
      int in_left = 0;
      int in_right = 0;

      void load() {
        const int len = in_right - in_left;
        std::memmove(inbuf, inbuf + in_left, len);
        in_right = len + std::fread(inbuf + len, 1, SZ - len, stdin);
        in_left = 0;
      }

      void skip_space() {
        if (in_left + 32 > in_right) load();
        while (inbuf[in_left] <= ' ') in_left++;
      }

      void rd(char& c) {
        if (in_left + 32 > in_right) load();
        c = inbuf[in_left++];
      }

      void rd(std::string& s) {
        for (; (in_left < in_right || (load(), in_left < in_right)) && (inbuf[in_left] == ' ' || inbuf[in_left] == '\n'); ++in_left);
        s.clear();
        if (in_left == in_right) return;
        int real_size = 0;
        do {
          int to;
          for (to = in_left; to < in_right && inbuf[to] != ' ' && inbuf[to] != '\n'; ++to);
          const int new_real_size = real_size + (to - in_left);
          if (int(s.size()) < new_real_size) {
            s.resize(std::max(new_real_size, int(s.size()) * 2));
          }
          std::memcpy(s.data() + real_size, inbuf + in_left, to - in_left);
          in_left = to;
          real_size = new_real_size;
        } while (in_left == in_right && (load(), in_left < in_right));
        s.resize(real_size);
      }

      template <typename T>
      void rd(T& x) {
        if (in_left + 32 > in_right) load();
        char c;
        do {
          c = inbuf[in_left++];
        } while (c < '-');
        [[maybe_unused]] bool minus = false;
        if constexpr (std::is_signed_v<T>) {
          if (c == '-') {
            minus = true;
            c = inbuf[in_left++];
          }
        }
        x = 0;
        while (c >= '0') {
          x = x * 10 + (c & 15);
          c = inbuf[in_left++];
        }
        if constexpr (std::is_signed_v<T>) {
          if (minus) x = -x;
        }
      }
    }
  }

  struct istream {
    template <typename... Args>
    tools::istream& operator>>(Args&&... args) {
      tools::detail::istream::rd(std::forward<Args>(args)...);
      return *this;
    }
  };

  tools::istream cin;
}

#endif
