#ifndef TOOLS_MANACHER_HPP
#define TOOLS_MANACHER_HPP

#include <cassert>
#include <iterator>
#include <ranges>
#include <type_traits>
#include <utility>
#include <vector>
#include "tools/integral.hpp"
#include "tools/mex.hpp"

namespace tools {
  class manacher {
    std::vector<int> m_radiuses;

  public:
    manacher() = default;
    template <std::ranges::input_range R>
    requires tools::integral<std::ranges::range_value_t<R>>
    manacher(R&& r) {
      auto S = std::forward<R>(r) | std::ranges::to<std::vector>();
      const int N = S.size();
      S.resize(2 * N + 1);
      for (int i = N - 1; i >= 0; --i) {
        S[2 * i + 1] = S[i];
      }
      const auto dummy = tools::mex(S);
      for (int i = 0; i <= 2 * N; i += 2) {
        S[i] = dummy;
      }

      this->m_radiuses.resize(S.size());
      {
        int i = 0;
        int j = 0;
        while (i < std::ssize(S)) {
          for (; i >= j && i + j < std::ssize(S) && S[i - j] == S[i + j]; ++j);
          this->m_radiuses[i] = j;
          int k;
          for (k = 1; i >= k && k + this->m_radiuses[i - k] < j; ++k) {
            this->m_radiuses[i + k] = this->m_radiuses[i - k];
          }
          i += k;
          j -= k;
        }
      }
    }

    int size() const {
      return (this->m_radiuses.size() - 1) / 2;
    }

    template <bool Restore = false>
    std::conditional_t<Restore, std::pair<int, int>, int> odd_length(const int i) const {
      assert(0 <= i && i < this->size());
      if constexpr (Restore) {
        return std::make_pair(i - (this->m_radiuses[i * 2 + 1] / 2 - 1), i + this->m_radiuses[i * 2 + 1] / 2);
      } else {
        return this->m_radiuses[i * 2 + 1] - 1;
      }
    }
    template <bool Restore = false>
    std::conditional_t<Restore, std::pair<int, int>, int> even_length(const int i) const {
      assert(0 <= i && i <= this->size());
      if constexpr (Restore) {
        return std::make_pair(i - (this->m_radiuses[i * 2] - 1) / 2, i + (this->m_radiuses[i * 2] - 1) / 2);
      } else {
        return this->m_radiuses[i * 2] - 1;
      }
    }
  };
}

#endif
