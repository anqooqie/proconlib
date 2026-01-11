---
title: Enumerate all integer partitions
documentation_of: //tools/next_integer_partition.hpp
---

## (1)
```cpp
template <tools::integral Z>
bool next_integer_partition(std::vector<Z>& a);
```

It generates the next integer partition of $n = \sum_{i = 0}^{\|a\| - 1} a_i$.
It returns `true` if the next integer partition exists, `false` otherwise.

### Example
```cpp
std::vector<int> a{4};
assert(tools::next_integer_partition(a));
assert(a == std::vector<int>{3, 1});
assert(tools::next_integer_partition(a));
assert(a == std::vector<int>{2, 2});
assert(tools::next_integer_partition(a));
assert(a == std::vector<int>{2, 1, 1});
assert(tools::next_integer_partition(a));
assert(a == std::vector<int>{1, 1, 1, 1});
assert(!tools::next_integer_partition(a));
assert(a == std::vector<int>{4});
```

### Usage
```cpp
std::vector<int> a{4};
do {
  // ...
} while (tools::next_integer_partition(a));
```

### Constraints
- $\|a\| \geq 1$
- For any $i$ and $j$ such that $0 \leq i < j < \|a\|$, $a_i \geq a_j$.
- $a_{\|a\| - 1} \geq 1$

### Time Complexity
- If you just call `next_integer_partition`, it takes only $O(n)$ time.
- If you enumerate all the integer partitions of $n$, it takes $O(n \cdot p(n))$ time where $p(n)$ is the number of integer partitions of $n$.

FYI, $p(n)$ for some representative $n$s are listed below.

|$n$|$p(n)$|
|---|---|
|$10$|$42$|
|$20$|$627$|
|$30$|$5,604$|
|$40$|$37,338$|
|$50$|$204,226$|
|$60$|$966,467$|
|$70$|$4,087,968$|
|$80$|$15,796,476$|
|$90$|$56,634,173$|
|$100$|$190,569,292$|

### License
- CC0

### Author
- anqooqie

## (2)
```cpp
template <tools::integral Z1, tools::integral Z2>
bool next_integer_partition(std::vector<std::pair<Z1, Z2>>& a);
```

It is almost equivalent to (1), but the integer partition $a$ is given as the run-length encoded list.
In other words, the integer partition $(x_0, \cdots \text{($n_0$ times)} \cdots, x_0, x_1, \cdots \text{($n_1$ times)} \cdots, x_1, \ldots, x_{\|a\| - 1}, \cdots \text{($n_{\|a\| - 1}$ times)} \cdots, x_{\|a\| - 1})$ is given as $((x_0, n_0), (x_1, n_1), \ldots, (x_{\|a\| - 1}, n_{\|a\| - 1}))$.

### Example
```cpp
std::vector<std::pair<int, int>> a{ {4, 1} };
assert(tools::next_integer_partition(a));
assert(a == std::vector<std::pair<int, int>>{ {3, 1}, {1, 1} });
assert(tools::next_integer_partition(a));
assert(a == std::vector<std::pair<int, int>>{ {2, 2} });
assert(tools::next_integer_partition(a));
assert(a == std::vector<std::pair<int, int>>{ {2, 1}, {1, 2} });
assert(tools::next_integer_partition(a));
assert(a == std::vector<std::pair<int, int>>{ {1, 4} });
assert(!tools::next_integer_partition(a));
assert(a == std::vector<std::pair<int, int>>{ {4, 1} });
```

### Usage
```cpp
std::vector<std::pair<int, int>> a{ {4, 1} };
do {
  // ...
} while (tools::next_integer_partition(a));
```

### Constraints
- $\|a\| \geq 1$
- For any $i$ and $j$ such that $0 \leq i < j < \|a\|$, $x_i > x_j$.
- $x_{\|a\| - 1} \geq 1$
- For any $i$ such that $0 \leq i < \|a\|$, $n_i \geq 1$.

### Time Complexity
- If you just call `next_integer_partition`, it takes only $O(1)$ amortized time.
- If you enumerate all the integer partitions of $n$, it takes $O(p(n))$ time where $p(n)$ is the number of integer partitions of $n$.

### License
- CC0

### Author
- anqooqie
