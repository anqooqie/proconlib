#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"
#ifdef __clang__
  #define IGNORE
#endif

#include "tools/util.hpp"
#include "atcoder/modint.hpp"
#include "tools/assert_that.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  {
    mint v;
    std::istringstream iss("123");
    iss >> v;
    assert_that(v == mint(123));
  }
  {
    std::vector<mint> v;
    std::istringstream iss("123 456 789 111 222 333");
    std::copy_n(std::istream_iterator<mint>(iss), 3, std::back_inserter(v));
    assert_that(v.size() == 3);
    assert_that(v[0] == mint(123));
    assert_that(v[1] == mint(456));
    assert_that(v[2] == mint(789));
  }
  {
    std::ostringstream oss;
    oss << mint(123);
    assert_that(oss.str() == "123");
  }
  {
    std::vector<int> v(3);
    std::istringstream iss("123 456 789 111 222 333");
    iss >> v;
    assert_that(v.size() == 3);
    assert_that(v[0] == 123);
    assert_that(v[1] == 456);
    assert_that(v[2] == 789);
  }
  {
    std::array<int, 3> v;
    std::istringstream iss("123 456 789 111 222 333");
    iss >> v;
    assert_that(v[0] == 123);
    assert_that(v[1] == 456);
    assert_that(v[2] == 789);
  }
  {
    std::vector<int> v = {123, 456, 789};
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "[123, 456, 789]");
  }
  {
    std::array<int, 3> v = {123, 456, 789};
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "[123, 456, 789]");
  }
  {
    std::unordered_set<int> v = {123, 456, 789};
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "[123, 456, 789]" || oss.str() == "[123, 789, 456]" || oss.str() == "[456, 123, 789]" || oss.str() == "[456, 789, 123]" || oss.str() == "[789, 123, 456]" || oss.str() == "[789, 456, 123]");
  }
  {
    std::unordered_map<int, int> v = {{{1, 123}, {2, 456}, {3, 789}}};
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "[[1, 123], [2, 456], [3, 789]]" || oss.str() == "[[1, 123], [3, 789], [2, 456]]" || oss.str() == "[[2, 456], [1, 123], [3, 789]]" || oss.str() == "[[2, 456], [3, 789], [1, 123]]" || oss.str() == "[[3, 789], [1, 123], [2, 456]]" || oss.str() == "[[3, 789], [2, 456], [1, 123]]");
  }
  {
    std::stack<int> v;
    v.push(123);
    v.push(456);
    v.push(789);
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "[123, 456, 789]");
    assert_that(v.size() == 3);
    assert_that(v.top() == 789);
  }
  {
    std::queue<int> v;
    v.push(123);
    v.push(456);
    v.push(789);
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "[123, 456, 789]");
    assert_that(v.size() == 3);
    assert_that(v.front() == 123);
  }
  {
    std::pair<int, int> v;
    std::istringstream iss("123 456 111 222");
    iss >> v;
    assert_that(v.first == 123);
    assert_that(v.second == 456);
  }
  {
    std::pair<int, int> v(123, 456);
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "[123, 456]");
  }
  {
    std::tuple<int, int, int> v;
    std::istringstream iss("123 456 789 111 222 333");
    iss >> v;
    assert_that(std::get<0>(v) == 123);
    assert_that(std::get<1>(v) == 456);
    assert_that(std::get<2>(v) == 789);
  }
  {
    std::tuple<int, int, int> v(123, 456, 789);
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "[123, 456, 789]");
  }

  {
    std::vector<std::size_t> v;
    const std::hash<std::pair<int, int>> hasher;
    for (int i = 0; i < 3000; ++i) {
      for (int j = 0; j < 3000; ++j) {
        const auto pair = std::make_pair(i, j);
        v.push_back(hasher(pair));
        assert_that(hasher(pair) == v.back());
      }
    }

    const auto old_size = v.size();
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    assert_that(v.size() == old_size);
  }

  {
    std::vector<std::size_t> v;
    const std::hash<std::tuple<int, int>> hasher;
    for (int i = 0; i < 3000; ++i) {
      for (int j = 0; j < 3000; ++j) {
        const auto tuple = std::make_tuple(i, j);
        v.push_back(hasher(tuple));
        assert_that(hasher(tuple) == v.back());
      }
    }

    const auto old_size = v.size();
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    assert_that(v.size() == old_size);
  }

  std::cout << "Hello World" << '\n';
  return 0;
}
