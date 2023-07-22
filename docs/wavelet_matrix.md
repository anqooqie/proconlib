---
title: Wavelet matrix
documentation_of: //tools/wavelet_matrix.hpp
---

It is a data structure which can process various queries at high speed for $n$ weighted points $(x_0, y_0, w_0), (x_1, y_1, w_1), \ldots, (x_{n - 1}, y_{n - 1}, w_{n - 1})$ on a two-dimensional plane.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
wavelet_matrix<T> wm();
```

It creates an empty two-dimensional plane.

### Constraints
- None

### Time Complexity
- $O(1)$

## size
```cpp
std::size_t wm.size();
```

It returns the number of points on the plane.

### Constraints
- None

### Time Complexity
- $O(1)$

## add_point
```cpp
std::size_t wm.add_point(T x, T y);
```

It adds a point $(x, y)$ to the plane.
It returns an integer $i$ such that this is the $i$-th ($0$ indexed) point that is added.

### Constraints
- `wm.build()` has not been called ever.

### Time Complexity
- $O(1)$ amortized

## get_point
```cpp
std::pair<T, T> wm.get_point(std::size_t i)
```

It returns the $i$-th ($0$ indexed) point.

### Constraints
- $i < n$ where $n$ is `wm.size()`

### Time Complexity
- $O(1)$

## points
```cpp
const std::vector<std::pair<T, T>>& wm.points();
```

It returns all the points on the plane.
The points are ordered in the same order as added by `add_point`.

### Constraints
- None

### Time Complexity
- $O(1)$

## build
```cpp
std::vector<std::vector<std::size_t>> wm.build();
```

It internally creates the data structure called as wavelet matrix.

It also returns the matrix $A_{h, j}$ with $O(\log n)$ rows and $n$ columns.
Each row of $A_h$ is the permutation of $(0, 1, \ldots, n - 1)$.
You can initialize an auxiliary data structure by $A_{h, j}$, for querying weighted points.

### Example
```cpp
// Given n weighted points, answer the sum of w_i such that l <= x_i < r and d <= y_i < u.

tools::wavelet_matrix<int> wm;
for (int i = 0; i < n; ++i) {
  wm.add_point(x[i], y[i]);
}

std::vector<std::vector<ll>> partial_sums;
for (const auto& A_h : wm.build()) {
  std::vector<ll> v;
  for (const auto i : A_h) {
    v.push_back(w[i]);
  }

  partial_sums.emplace_back();
  partial_sums.back().push_back(0);
  std::partial_sum(v.begin(), v.end(), std::back_inserter(partial_sums.back()));
}

ll answer = 0;
for (const auto& [h, jl, jr] : wm.range_prod(l, r, u)) {
  answer += partial_sums[h][jr] - partial_sums[h][jl];
}
for (const auto& [h, jl, jr] : wm.range_prod(l, r, d)) {
  answer -= partial_sums[h][jr] - partial_sums[h][jl];
}
std::cout << answer << '\n';
```

### Constraints
- `wm.build()` has not been called ever.

### Time Complexity
- $O(n \log n)$

## apply
```cpp
std::vector<std::pair<std::size_t, std::size_t>> wm.apply(std::size_t i);
```

It has no side effects, but just returns pairs $(0, j_0), (1, j_1), \ldots, (H - 1, j_{H - 1})$ where $H$ is the number of rows of the returned matrix from `wm.build()`.
You can update the auxiliary data structure by the returned pairs, for querying weighted points.

### Example
```cpp
// Answer Q queries.
// (type 1 query) 1 x y w: Add a point (x, y) at weight w.
// (type 2 query) 2 l r d u: Print the sum of w_i such that l <= x_i < r and d <= y_i < u.

std::queue<int> query_types;
tools::wavelet_matrix<int> wm;
std::vector<int> weights;
std::queue<std::tuple<int, int, int, int>> query2;

int Q;
std::cin >> Q;
for (int q = 0; q < Q; ++q) {
  int t;
  std::cin >> t;
  query_types.push(t);
  if (t == 1) {
    int x, y, w;
    wm.add_point(x, y);
    weights.push_back(w);
  } else {
    int l, r, d, u;
    std::cin >> l >> r >> d >> u;
    query2.emplace(l, r, d, u);
  }
}

auto fws = std::vector(wm.build().size(), atcoder::fenwick_tree<ll>(wm.size()));

int i = 0;
while (!query_types.empty()) {
  const auto t = query_types.front();
  query_types.pop();
  if (t == 1) {
    for (const auto& [h, j] : wm.apply(i)) {
      fws[h].add(j, weights[i]);
    }
    ++i;
  } else {
    const auto [l, r, d, u] = query2.front();
    query2.pop();

    ll answer = 0;
    for (const auto& [h, jl, jr] : wm.range_prod(l, r, u)) {
      answer += fws[h].sum(jl, jr);
    }
    for (const auto& [h, jl, jr] : wm.range_prod(l, r, d)) {
      answer -= fws[h].sum(jl, jr);
    }
    std::cout << answer << '\n';
  }
}
```

### Constraints
- `wm.build()` has been called ever.
- $i < n$

### Time Complexity
- $O(\log n)$

## kth_smallest
```cpp
std::size_t wm.kth_smallest(T l, T r, std::size_t k);
```

It returns $i$ such that $l \leq x_i < r$ and $\|\\{j \mid l \leq x_j < r \land (y_j, j) < (y_i, i)) \\}\| = k$.

### Constraints
- `wm.build()` has been called ever.
- $l \leq r$
- $k < \|\\{i \mid l \leq x_i < r\\}\|$

### Time Complexity
- $O(\log n)$

## kth_largest
```cpp
std::size_t wm.kth_largest(T l, T r, std::size_t k);
```

It returns $i$ such that $l \leq x_i < r$ and $\|\\{j \mid l \leq x_j < r \land (y_i, i) < (y_j, j)) \\}\| = k$.

### Constraints
- `wm.build()` has been called ever.
- $l \leq r$
- $k < \|\\{i \mid l \leq x_i < r\\}\|$

### Time Complexity
- $O(\log n)$

## range_prod
```cpp
std::vector<std::tuple<std::size_t, std::size_t, std::size_t>> wm.range_prod(T l, T r, T u);
```

It has no side effects, but just returns tuples $(0, l_0, r_0), (1, l_1, r_1), \ldots, (H - 1, l_{H - 1}, r_{H - 1})$ where $H$ is the number of rows of the returned matrix from `wm.build()`.
You can answer the query about weighted points using the auxiliary data structure and the returned tuples.

### Example
See the examples of `build` and `apply`.

### Constraints
- `wm.build()` has been called ever.
- $l \leq r$

### Time Complexity
- $O(\log n)$

## range_freq
```cpp
(1) std::size_t wm.range_freq(T l, T r);
(2) std::size_t wm.range_freq(T l, T r, T u);
(3) std::size_t wm.range_freq(T l, T r, T d, T u);
```

- (1)
    - It returns $\|\\{i \mid l \leq x_i < r \\}\|$.
- (2)
    - It returns $\|\\{i \mid l \leq x_i < r \land y_i < u \\}\|$.
- (3)
    - It returns $\|\\{i \mid l \leq x_i < r \land d \leq y_i < u \\}\|$.

### Constraints
- (1), (2)
    - `wm.build()` has been called ever.
    - $l \leq r$
- (3)
    - `wm.build()` has been called ever.
    - $l \leq r$
    - $d \leq u$

### Time Complexity
- $O(\log n)$

## prev_value
```cpp
std::optional<T> wm.prev_value(T l, T r, T u);
```

It returns the maximum $y_i$ such that $l \leq x_i < r$ and $y_i < u$.
If such the $y_i$ does not exist, it returns `std::nullopt`.

### Constraints
- `wm.build()` has been called ever.
- $l \leq r$

### Time Complexity
- $O(\log n)$

## next_value
```cpp
std::optional<T> wm.next_value(T l, T r, T d);
```

It returns the minimum $y_i$ such that $l \leq x_i < r$ and $d \leq y_i$.
If such the $y_i$ does not exist, it returns `std::nullopt`.

### Constraints
- `wm.build()` has been called ever.
- $l \leq r$

### Time Complexity
- $O(\log n)$

## prev_points
```cpp
std::pair<typename std::vector<std::size_t>::const_iterator, typename std::vector<std::size_t>::const_iterator> prev_points(T l, T r, T u)
```

Let us denote the returned iterator pair by `begin` and `end`.
`std::vector<std::size_t>(begin, end)` would be $\\{i \mid l \leq x_i < r \land y_i = y\\}$ sorted in ascending order, where $y$ is `wm.prev_value(l, r, u)`.

### Constraints
- `wm.build()` has been called ever.
- $l \leq r$

### Time Complexity
- $O(\log n)$

## next_points
```cpp
std::pair<typename std::vector<std::size_t>::const_iterator, typename std::vector<std::size_t>::const_iterator> next_points(T l, T r, T d)
```

Let us denote the returned iterator pair by `begin` and `end`.
`std::vector<std::size_t>(begin, end)` would be $\\{i \mid l \leq x_i < r \land y_i = y\\}$ sorted in ascending order, where $y$ is `wm.next_value(l, r, d)`.

### Constraints
- `wm.build()` has been called ever.
- $l \leq r$

### Time Complexity
- $O(\log n)$
