---
title: DP with rerooting
documentation_of: //tools/dp_with_rerooting.hpp
---

It is an abstract algorithm for DP on a tree with rerooting.

## Example
It calculates the diameter of a given tree.

```cpp
struct monoid {
  using T = int;
  static T op(const T x, const T y) {
    return std::max(x, y);
  }
  static T e() {
    return 0;
  }
};

int f_ve(const int w, const int vertex) {
  return w + vertex;
}
int f_ev(std::monostate, const int edge) {
  return edge;
}

int main() {
  int n;
  std::cin >> n;

  tools::dp_with_rerooting<std::monostate, int, int, monoid, f_ve, f_ev> dp;
  for (int i = 0; i < n; ++i) {
    dp.add_vertex(std::monostate());
  }
  for (int i = 0; i < n - 1; ++i) {
    int s, t, w;
    std::cin >> s >> t >> w;
    dp.add_edge(s, t, w);
  }

  const std::vector<int> result = dp.query();
  std::cout << *std::max_element(result.begin(), result.end()) << '\n';
  return 0;
}
```

## License
- CC0

## Author
- anqooqie
