---
title: Mo's algorithm
documentation_of: //tools/mo.hpp
---

Assume the following situation.

- $Q$ queries are given.
- The $i$-th query asks you about some kind of value for the range $[l_i, r_i)$. $(0 \leq l_i \leq r_i \leq N)$
- Some kind of state is uniquely determined from a range $[l, r)$.
- If you know the state uniquely determined from $[l - 1, r)$, you can calculate the state uniquely determined from $[l, r)$ in $\alpha$ time.
- If you know the state uniquely determined from $[l + 1, r)$, you can calculate the state uniquely determined from $[l, r)$ in $\alpha$ time.
- If you know the state uniquely determined from $[l, r - 1)$, you can calculate the state uniquely determined from $[l, r)$ in $\alpha$ time.
- If you know the state uniquely determined from $[l, r + 1)$, you can calculate the state uniquely determined from $[l, r)$ in $\alpha$ time.
- If you know the state uniquely determined from $[l_i, r_i)$, you can answer the $i$-th query in $\beta$ time.

In this situation, Mo's algorithm can answer $Q$ queries in $O(\alpha N \sqrt{Q} + \beta Q)$ time.

### References
- [Mo's algorithm とその上位互換の話 - あなたは嘘つきですかと聞かれたら「YES」と答えるブログ](https://snuke.hatenablog.com/entry/2016/07/01/000000)
- [Mo’s algorithm \| Nyaan’s Library](https://nyaannyaan.github.io/library/misc/mo.hpp.html)

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
mo mo(std::size_t N, std::size_t Q);
```

It creates a storage for queries.

### Constraints
- None

### Time Complexity
- $O\left(\log \frac{N}{\sqrt{Q}} + \sqrt{Q}\right)$

## add_query
```cpp
void mo.add_query(std::size_t l, std::size_t r);
```

It adds a query for $[l, r)$ to the storage.

### Constraints
- $0 \leq l \leq r \leq N$

### Time Complexity
- $O(1)$ amortized

## run
```cpp
template <typename AL, typename AR, typename DL, typename DR, typename F>
void mo.run(AL add_left, AR add_right, DL delete_left, DR delete_right, F run_query);
```

It runs Mo's algorithm.
When `run_query(i)` is invoked, you can answer the $i$-th query by using the state uniquely determined from $[l_i, r_i)$.

### Constraints
- `add_left(std::size_t)` is invocable.
- `add_right(std::size_t)` is invocable.
- `delete_left(std::size_t)` is invocable.
- `delete_right(std::size_t)` is invocable.
- `run_query(std::size_t)` is invocable.
- When `add_left(i)` is invoked, you have to update the state from one uniquely determined from $[l, r)$ to one uniquely determined from $[l - 1, r)$. (You may utilize the contract that $i = l - 1$ holds.)
- When `add_right(i)` is invoked, you have to update the state from one uniquely determined from $[l, r)$ to one uniquely determined from $[l, r + 1)$. (You may utilize the contract that $i = r$ holds.)
- When `delete_left(i)` is invoked, you have to update the state from one uniquely determined from $[l, r)$ to one uniquely determined from $[l + 1, r)$. (You may utilize the contract that $i = l$ holds.)
- When `delete_right(i)` is invoked, you have to update the state from one uniquely determined from $[l, r)$ to one uniquely determined from $[l, r - 1)$. (You may utilize the contract that $i = r - 1$ holds.)

### Time Complexity
- $O(\alpha N \sqrt{Q} + \beta Q)$ where $\alpha$ is the time to run `add_left`, `add_right`, `delete_left` and `delete_right`, and $\beta$ is the time to run `run_query`.
