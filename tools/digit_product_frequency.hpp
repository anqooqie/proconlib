#ifndef TOOLS_DIGIT_PRODUCT_FREQUENCY_HPP
#define TOOLS_DIGIT_PRODUCT_FREQUENCY_HPP

#include <map>
#include <vector>
#include <tuple>
#include <cstddef>
#include <array>
#include <algorithm>
#include <numeric>
#include "tools/resize.hpp"
#include "tools/less_by_first.hpp"

namespace tools {

  template <typename T>
  ::std::map<T, T> digit_product_frequency(const T n) {
    if (n <= 0) return ::std::map<T, T>{};

    ::std::vector<::std::size_t> n_digits;
    for (auto tmp = n; tmp > 0; tmp /= 10) {
      n_digits.push_back(tmp % 10);
    }

    using tuple = ::std::tuple<::std::size_t, ::std::size_t, ::std::size_t, ::std::size_t>;
    constexpr ::std::array<tuple, 10> diff = {
      tuple(0, 0, 0, 0),
      tuple(0, 0, 0, 0),
      tuple(1, 0, 0, 0),
      tuple(0, 1, 0, 0),
      tuple(2, 0, 0, 0),
      tuple(0, 0, 1, 0),
      tuple(1, 1, 0, 0),
      tuple(0, 0, 0, 1),
      tuple(3, 0, 0, 0),
      tuple(0, 2, 0, 0),
    };

    static const auto safe_ref = [](::std::vector<::std::vector<::std::vector<::std::vector<T>>>>& vector, const ::std::size_t e2, const ::std::size_t e3, const ::std::size_t e5, const ::std::size_t e7) -> T& {
      vector.resize(::std::max(vector.size(), e2 + 1));
      vector[e2].resize(::std::max(vector[e2].size(), e3 + 1));
      vector[e2][e3].resize(::std::max(vector[e2][e3].size(), e5 + 1));
      vector[e2][e3][e5].resize(::std::max(vector[e2][e3][e5].size(), e7 + 1));
      return vector[e2][e3][e5][e7];
    };

    ::std::vector<::std::array<::std::vector<::std::vector<::std::vector<::std::vector<T>>>>, 2>> dp(n_digits.size() + 1);
    ::tools::resize(dp[0], 2, 1, 1, 1, 1);
    dp[0][true][0][0][0][0] = 1;
    dp[0][false][0][0][0][0] = 1;
    for (::std::size_t i = 0; i < n_digits.size(); ++i) {
      for (::std::size_t e2 = 0; e2 < dp[i][true].size(); ++e2) {
        for (::std::size_t e3 = 0; e3 < dp[i][true][e2].size(); ++e3) {
          for (::std::size_t e5 = 0; e5 < dp[i][true][e2][e3].size(); ++e5) {
            for (::std::size_t e7 = 0; e7 < dp[i][true][e2][e3][e5].size(); ++e7) {
              if (dp[i][true][e2][e3][e5][e7] > 0 && n_digits[i] > 0) {
                const auto& [d2, d3, d5, d7] = diff[n_digits[i]];
                safe_ref(dp[i + 1][true], e2 + d2, e3 + d3, e5 + d5, e7 + d7) += dp[i][true][e2][e3][e5][e7];
              }
            }
          }
        }
      }
      for (::std::size_t e2 = 0; e2 < dp[i][false].size(); ++e2) {
        for (::std::size_t e3 = 0; e3 < dp[i][false][e2].size(); ++e3) {
          for (::std::size_t e5 = 0; e5 < dp[i][false][e2][e3].size(); ++e5) {
            for (::std::size_t e7 = 0; e7 < dp[i][false][e2][e3][e5].size(); ++e7) {
              if (dp[i][false][e2][e3][e5][e7] > 0) {
                for (::std::size_t d = 1; d < n_digits[i]; ++d) {
                  const auto& [d2, d3, d5, d7] = diff[d];
                  safe_ref(dp[i + 1][true], e2 + d2, e3 + d3, e5 + d5, e7 + d7) += dp[i][false][e2][e3][e5][e7];
                }
                for (::std::size_t d = 1; d <= 9; ++d) {
                  const auto& [d2, d3, d5, d7] = diff[d];
                  safe_ref(dp[i + 1][false], e2 + d2, e3 + d3, e5 + d5, e7 + d7) += dp[i][false][e2][e3][e5][e7];
                }
              }
            }
          }
        }
      }
    }

    ::std::vector<::std::vector<::std::vector<::std::vector<T>>>> answer;
    for (::std::size_t i = n_digits.size(); i >= 1; --i) {
      for (::std::size_t e2 = 0; e2 < dp[i][i == n_digits.size()].size(); ++e2) {
        for (::std::size_t e3 = 0; e3 < dp[i][i == n_digits.size()][e2].size(); ++e3) {
          for (::std::size_t e5 = 0; e5 < dp[i][i == n_digits.size()][e2][e3].size(); ++e5) {
            for (::std::size_t e7 = 0; e7 < dp[i][i == n_digits.size()][e2][e3][e5].size(); ++e7) {
              if (dp[i][i == n_digits.size()][e2][e3][e5][e7] > 0) {
                safe_ref(answer, e2, e3, e5, e7) += dp[i][i == n_digits.size()][e2][e3][e5][e7];
              }
            }
          }
        }
      }
    }

    ::std::vector<::std::pair<T, T>> freq;
    {
      ::std::size_t e2, e3, e5, e7;
      T p2, p3, p5, p7;
      for (e2 = 0, p2 = 1; e2 < answer.size(); ++e2, p2 *= 2) {
        for (e3 = 0, p3 = 1; e3 < answer[e2].size(); ++e3, p3 *= 3) {
          for (e5 = 0, p5 = 1; e5 < answer[e2][e3].size(); ++e5, p5 *= 5) {
            for (e7 = 0, p7 = 1; e7 < answer[e2][e3][e5].size(); ++e7, p7 *= 7) {
              if (answer[e2][e3][e5][e7] > 0) {
                freq.emplace_back(p2 * p3 * p5 * p7, answer[e2][e3][e5][e7]);
              }
            }
          }
        }
      }
    }

    if (const auto sum_of_positives = ::std::accumulate(freq.begin(), freq.end(), T(0), [](const auto sum, const auto& pair) { return sum + pair.second; }); sum_of_positives < n) {
      freq.emplace_back(0, n - sum_of_positives);
    }

    ::std::sort(freq.begin(), freq.end(), ::tools::less_by_first{});
    return ::std::map<T, T>(freq.begin(), freq.end());
  }
}

#endif
