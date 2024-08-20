#define PROBLEM "https://judge.yosupo.jp/problem/division_of_big_integers"

#include <iostream>
#include <string>
#include <sstream>
#include "tools/cin.hpp"
#include "tools/cout.hpp"
#include "tools/bigint.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll T;
  tools::cin >> T;
  for (ll t = 0; t < T; ++t) {
    const auto A = [&]() {
      std::string s;
      tools::cin >> s;
      return tools::bigint(s);
    }();
    const auto B = [&]() {
      std::string s;
      tools::cin >> s;
      return tools::bigint(s);
    }();
    const auto [q, r] = A.divmod(B);
    tools::cout << [&]() {
      std::ostringstream oss;
      oss << q;
      return oss.str();
    }() << ' ' << [&]() {
      std::ostringstream oss;
      oss << r;
      return oss.str();
    }() << '\n';
  }

  return 0;
}
