---
title: 0-1 knapsack problem
documentation_of: //tools/zero_one_knapsack.hpp
---

It solves the 0-1 knapsack problem.

## License
- CC0

## Author
- anqooqie

## Constructor
```cpp
zero_one_knapsack<T> solver(T W);
```

It creates a solver for the 0-1 knapsack problem where $W$ is the capacity of the knapsack.

### Constraints
- $W \geq 0$

### Time Complexity
- $O(1)$

## size
```cpp
std::size_t solver.size();
```

It returns the number of items.

### Constraints
- None

### Time Complexity
- $O(1)$

## capacity
```cpp
T solver.capacity();
```

It returns $W$.

### Constraints
- None

### Time Complexity
- $O(1)$

## add_item
```cpp
std::size_t solver.add_item(T v, T w);
```

It adds an item with value $v$ and weight $w$.
It returns an integer $k$ such that this is the $k$-th item that is added.

### Constraints
- $v \geq 0$
- $w \geq 0$

### Time Complexity
- $O(1)$ amortized

## get_item
```cpp
std::pair<T, T> solver.get_item(std::size_t k);
```

It returns the value and the weight of the $k$-th item.

### Constraints
- $0 \leq k < N$ where $N$ is the number of items

### Time Complexity
- $O(1)$

## items
```cpp
const std::vector<std::pair<T, T>>& solver.items();
```

It returns all the items registered in the solver.
The items are ordered in the same order as added by `add_item`.

### Constraints
- None

### Time Complexity
- $O(1)$

## query
```cpp
std::pair<T, std::vector<::std::size_t>> solver.query();
```

It finds a subset of items such that:

- The total value of the items is as large as possible.
- The items have combined weight at most $W$.

It returns the maximum total value of items and the indices of the items.

### Constraints
- None

### Time Complexity
- $O(\min(NW, N \sum_{i = 0}^{N - 1} v_i, 2^\frac{N}{2}))$ where $v_i$ is the value of the $i$-th item.
