#ifndef TOOLS_DIGIT_PRODUCT_FREQUENCY_HPP
#define TOOLS_DIGIT_PRODUCT_FREQUENCY_HPP

#include <array>
#include <algorithm>
#include <iterator>
#include <map>
#include <numeric>
#include <tuple>
#include <vector>
#include "tools/less_by_first.hpp"
#include "tools/non_bool_integral.hpp"
#include "tools/resize.hpp"

namespace tools {
  template <tools::non_bool_integral T>
  std::map<T, T> digit_product_frequency(const T n) {
    if (n <= 0) return std::map<T, T>{};

    std::vector<int> n_digits;
    for (auto tmp = n; tmp > 0; tmp /= 10) {
      n_digits.push_back(tmp % 10);
    }

    using tuple = std::tuple<int, int, int, int>;
    constexpr std::array<tuple, 10> diff = {
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

    static const auto safe_ref = [](std::vector<std::vector<std::vector<std::vector<T>>>>& vector, const int e2, const int e3, const int e5, const int e7) -> T& {
      vector.resize(std::max<int>(vector.size(), e2 + 1));
      vector[e2].resize(std::max<int>(vector[e2].size(), e3 + 1));
      vector[e2][e3].resize(std::max<int>(vector[e2][e3].size(), e5 + 1));
      vector[e2][e3][e5].resize(std::max<int>(vector[e2][e3][e5].size(), e7 + 1));
      return vector[e2][e3][e5][e7];
    };

    std::vector<std::array<std::vector<std::vector<std::vector<std::vector<T>>>>, 2>> dp(n_digits.size() + 1);
    tools::resize(dp[0], 2, 1, 1, 1, 1);
    dp[0][true][0][0][0][0] = 1;
    dp[0][false][0][0][0][0] = 1;
    for (int i = 0; i < std::ssize(n_digits); ++i) {
      for (int e2 = 0; e2 < std::ssize(dp[i][true]); ++e2) {
        for (int e3 = 0; e3 < std::ssize(dp[i][true][e2]); ++e3) {
          for (int e5 = 0; e5 < std::ssize(dp[i][true][e2][e3]); ++e5) {
            for (int e7 = 0; e7 < std::ssize(dp[i][true][e2][e3][e5]); ++e7) {
              if (dp[i][true][e2][e3][e5][e7] > 0 && n_digits[i] > 0) {
                const auto& [d2, d3, d5, d7] = diff[n_digits[i]];
                safe_ref(dp[i + 1][true], e2 + d2, e3 + d3, e5 + d5, e7 + d7) += dp[i][true][e2][e3][e5][e7];
              }
            }
          }
        }
      }
      for (int e2 = 0; e2 < std::ssize(dp[i][false]); ++e2) {
        for (int e3 = 0; e3 < std::ssize(dp[i][false][e2]); ++e3) {
          for (int e5 = 0; e5 < std::ssize(dp[i][false][e2][e3]); ++e5) {
            for (int e7 = 0; e7 < std::ssize(dp[i][false][e2][e3][e5]); ++e7) {
              if (dp[i][false][e2][e3][e5][e7] > 0) {
                for (int d = 1; d < n_digits[i]; ++d) {
                  const auto& [d2, d3, d5, d7] = diff[d];
                  safe_ref(dp[i + 1][true], e2 + d2, e3 + d3, e5 + d5, e7 + d7) += dp[i][false][e2][e3][e5][e7];
                }
                for (int d = 1; d <= 9; ++d) {
                  const auto& [d2, d3, d5, d7] = diff[d];
                  safe_ref(dp[i + 1][false], e2 + d2, e3 + d3, e5 + d5, e7 + d7) += dp[i][false][e2][e3][e5][e7];
                }
              }
            }
          }
        }
      }
    }

    std::vector<std::vector<std::vector<std::vector<T>>>> answer;
    for (int i = std::ssize(n_digits); i >= 1; --i) {
      for (int e2 = 0; e2 < std::ssize(dp[i][i == std::ssize(n_digits)]); ++e2) {
        for (int e3 = 0; e3 < std::ssize(dp[i][i == std::ssize(n_digits)][e2]); ++e3) {
          for (int e5 = 0; e5 < std::ssize(dp[i][i == std::ssize(n_digits)][e2][e3]); ++e5) {
            for (int e7 = 0; e7 < std::ssize(dp[i][i == std::ssize(n_digits)][e2][e3][e5]); ++e7) {
              if (dp[i][i == std::ssize(n_digits)][e2][e3][e5][e7] > 0) {
                safe_ref(answer, e2, e3, e5, e7) += dp[i][i == std::ssize(n_digits)][e2][e3][e5][e7];
              }
            }
          }
        }
      }
    }

    std::vector<std::pair<T, T>> freq;
    {
      int e2, e3, e5, e7;
      T p2, p3, p5, p7;
      for (e2 = 0, p2 = 1; e2 < std::ssize(answer); ++e2, p2 *= 2) {
        for (e3 = 0, p3 = 1; e3 < std::ssize(answer[e2]); ++e3, p3 *= 3) {
          for (e5 = 0, p5 = 1; e5 < std::ssize(answer[e2][e3]); ++e5, p5 *= 5) {
            for (e7 = 0, p7 = 1; e7 < std::ssize(answer[e2][e3][e5]); ++e7, p7 *= 7) {
              if (answer[e2][e3][e5][e7] > 0) {
                freq.emplace_back(p2 * p3 * p5 * p7, answer[e2][e3][e5][e7]);
              }
            }
          }
        }
      }
    }

    if (const auto sum_of_positives = std::accumulate(freq.begin(), freq.end(), T(0), [](const auto sum, const auto& pair) { return sum + pair.second; }); sum_of_positives < n) {
      freq.emplace_back(0, n - sum_of_positives);
    }

    return std::map<T, T>(freq.begin(), freq.end());
  }
}

#endif
