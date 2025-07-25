---
title: Mo's algorithm
documentation_of: //tools/mo.hpp
---

Assume the following situation.

- Given $f \colon \mathbb{N}^2 \to S$, $g \colon S \to T$ and $Q$ queries $(l_0, r_0), (l_1, r_1), \ldots, (l_{Q - 1}, r_{Q - 1})$ such that $0 \leq l_q \leq M$ and $0 \leq r_q \leq N$ for any $0 \leq q < Q$, you need to answer $g(f(l_0, r_0)), g(f(l_1, r_1)), \ldots, g(f(l_{Q - 1}, r_{Q - 1}))$.
- Given $f(l, r)$, it is possible to get $f(l - 1, r)$ in $\alpha$ time. 
- Given $f(l, r)$, it is possible to get $f(l + 1, r)$ in $\alpha$ time. 
- Given $f(l, r)$, it is possible to get $f(l, r - 1)$ in $\alpha$ time. 
- Given $f(l, r)$, it is possible to get $f(l, r + 1)$ in $\alpha$ time. 
- Given $s$, it is possible to get $g(s)$ in $\beta$ time.

In this situation, Mo's algorithm can answer $Q$ queries in $O(\alpha \sqrt{MNQ} + \beta Q + Q \log Q)$ time.

### References
- [定数倍が最適な Mo's Algorithm - noshi91のメモ](https://noshi91.hatenablog.com/entry/2023/04/13/224811)

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) mo<false> mo(int M, int N, int Q);
(2) mo<true> mo(int N, int Q);
(3) mo mo(int N, int Q);
```

It creates a storage for queries.

- (2)
    - By adding the constraints $M = N$ and $l_q \leq r_q$ for any $0 \leq q < Q$, it makes Mo's algorithm $\sqrt{2}$ times faster.
- (3)
    - It is equivalent to (2).

### Constraints
- None

### Time Complexity
- $O(Q)$

## add_query
```cpp
void mo.add_query(int l, int r);
```

It adds a query $(l, r)$ to the storage.

### Constraints
- The number of times that `mo.add_query` has been called so far is less than $Q$.
- $0 \leq l \leq M$
- $0 \leq r \leq N$
- If `mo` is constructed by the constructor (2) or (3), $l \leq r$

### Time Complexity
- $O(1)$

## run
```cpp
(1)
template <typename DL, typename IL, typename DR, typename IR, typename F>
requires (std::invocable<DL, int> && std::invocable<IL, int> && std::invocable<DR, int> && std::invocable<IR, int> && std::invocable<F, int>)
void mo.run(DL decrement_l, IL increment_l, DR decrement_r, IR increment_r, F run_query);

(2)
template <typename D, typename A, typename F>
requires (std::invocable<D, int> && std::invocable<A, int> && std::invocable<F, int>)
void mo.run(D del, A add, F run_query);
```

It executes Mo's algorithm.

- (1)
    - You need to compute $f(0, 0)$ in advance.
    - When `decrement_l` is called with parameter $l$, you should have $f(l + 1, r)$, so you need to compute $f(l, r)$ using $f(l + 1, r)$.
    - When `increment_l` is called with parameter $l$, you should have $f(l - 1, r)$, so you need to compute $f(l, r)$ using $f(l - 1, r)$.
    - When `decrement_r` is called with parameter $r$, you should have $f(l, r + 1)$, so you need to compute $f(l, r)$ using $f(l, r + 1)$.
    - When `increment_r` is called with parameter $r$, you should have $f(l, r - 1)$, so you need to compute $f(l, r)$ using $f(l, r - 1)$.
    - When `run_query` is called with parameter $q$, you should have $f(l_q, r_q)$, so you need to compute $g(f(l_q, r_q))$ and answer the $q$-th query.
- (2)
    - It is equivalent to `mo.run(add, del, del, add, run_query)`.

### Constraints
- (2)
    - `mo` is constructed by the constructor (2) or (3).

### Time Complexity
- $O(\alpha \sqrt{MNQ} + \beta Q + Q \log Q)$ where $\alpha$ is the time to run `decrement_l`, `increment_l`, `decrement_r` and `increment_r`, and $\beta$ is the time to run `run_query`.
