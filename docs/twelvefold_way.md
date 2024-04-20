---
title: Twelvefold way
documentation_of: //tools/twelvefold_way.hpp
---

It calculates the number of ways to put all of the $n$ labeled / unlabeled balls to $k$ labeled / unlabeled boxes when the number of balls per box is at most $1$ / unrestricted / at least $1$.

### Formulas

|balls|boxes|at most $1$|unrestricted|at least $1$|
|labeled|labeled|$\displaystyle (k)_n = n! [x^n] (1 + x)^k$|$\displaystyle k^n = n! [x^n] e^{kx}$|$\displaystyle \sum_{i = 0}^k (-1)^{k - i} \binom{k}{i} i^n = n! [x^n] (e^x - 1)^k$|
|unlabeled|labeled|$\displaystyle \binom{k}{n} = [x^n] (1 + x)^k$|$\displaystyle \binom{n + k - 1}{n} = [x^n] \left(\frac{1}{1 - x}\right)^k$|$\displaystyle \binom{n - 1}{n - k} = [x^n] \left(\frac{x}{1 - x}\right)^k$|
|labeled|unlabeled|$[n \leq k]$|$\displaystyle B(n, k) = \sum_{i = 0}^k \left\\{ {n \atop i} \right\\}$|$\displaystyle \left\\{ {n \atop k} \right\\} = n! [x^n] \frac{(e^x - 1)^k}{k!}$|
|unlabeled|unlabeled|$[n \leq k]$|$P(n, k)$|$P(n - k, k)$|

### License
- CC0

### Author
- anqooqie

## twelvefold_way&lt;true, true&gt;::at_most_1
```cpp
template <typename M>
M twelvefold_way<true, true>::at_most_1(long long n, long long k);
```

It returns the remainder of the number of ways to put all of the $n$ labeled balls to $k$ labeled boxes when the number of balls per box is at most $1$ divided by `M::mod()`.

### Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $n \geq 0$
- $k \geq 0$

### Time Complexity
- ($k < n$):
    - $O(1)$
- ($n \leq k$):
    - ($M$ is a prime):
        - $O\left( \min\left( \min(k, M) + \frac{\log k}{\log M}, \sqrt{M \log M} + \sqrt{\frac{M}{\log M}} \log k \right) \right)$
    - (otherwise):
        - $O\left( M + \frac{\log M}{\log \log M} \log k \right)$

## twelvefold_way&lt;true, true&gt;::unrestricted
```cpp
template <typename M>
M twelvefold_way<true, true>::unrestricted(long long n, long long k);
```

It returns the remainder of the number of ways to put all of the $n$ labeled balls to $k$ labeled boxes when the number of balls per box is unrestricted divided by `M::mod()`.

### Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $n \geq 0$
- $k \geq 0$

### Time Complexity
- $O(\log n)$

## twelvefold_way&lt;true, true&gt;::at_least_1
```cpp
template <typename M>
M twelvefold_way<true, true>::at_least_1(long long n, long long k);
```

It returns the remainder of the number of ways to put all of the $n$ labeled balls to $k$ labeled boxes when the number of balls per box is at least $1$ divided by `M::mod()`.

### Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $n \geq 0$
- $k \geq 0$

### Time Complexity
- ($n < k$):
    - $O(1)$
- ($k \leq n$):
    - ($M$ is a prime):
        - $O\left( k \log n \right)$
    - (otherwise):
        - $O\left( \min\left( nk, M + k \left( \frac{\log M}{\log \log M} \log k + \left( \frac{\log M}{\log \log M} \right)^2 \right) \right) \right)$

## twelvefold_way&lt;false, true&gt;::at_most_1
```cpp
template <typename M>
M twelvefold_way<false, true>::at_most_1(long long n, long long k);
```

It returns the remainder of the number of ways to put all of the $n$ unlabeled balls to $k$ labeled boxes when the number of balls per box is at most $1$ divided by `M::mod()`.

### Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $n \geq 0$
- $k \geq 0$

### Time Complexity
- ($k < n$):
    - $O(1)$
- ($n \leq k$):
    - ($M$ is a prime):
        - $O\left( \min\left( \min(k, M) + \frac{\log k}{\log M}, \sqrt{M \log M} + \sqrt{\frac{M}{\log M}} \log k \right) \right)$
    - (otherwise):
        - $O\left( M + \frac{\log M}{\log \log M} \log k \right)$

## twelvefold_way&lt;false, true&gt;::unrestricted
```cpp
template <typename M>
M twelvefold_way<false, true>::unrestricted(long long n, long long k);
```

It returns the remainder of the number of ways to put all of the $n$ unlabeled balls to $k$ labeled boxes when the number of balls per box is unrestricted divided by `M::mod()`.

### Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $n \geq 0$
- $k \geq 0$

### Time Complexity
- ($M$ is a prime):
    - $O\left( \min\left( \min(n + k, M) + \frac{\log (n + k)}{\log M}, \sqrt{M \log M} + \sqrt{\frac{M}{\log M}} \log (n + k) \right) \right)$
- (otherwise):
    - $O\left( M + \frac{\log M}{\log \log M} \log (n + k) \right)$

## twelvefold_way&lt;false, true&gt;::at_least_1
```cpp
template <typename M>
M twelvefold_way<false, true>::at_least_1(long long n, long long k);
```

It returns the remainder of the number of ways to put all of the $n$ unlabeled balls to $k$ labeled boxes when the number of balls per box is at least $1$ divided by `M::mod()`.

### Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $n \geq 0$
- $k \geq 0$

### Time Complexity
- ($n < k$):
    - $O(1)$
- ($k \leq n$):
    - ($M$ is a prime):
        - $O\left( \min\left( \min(n, M) + \frac{\log n}{\log M}, \sqrt{M \log M} + \sqrt{\frac{M}{\log M}} \log n \right) \right)$
    - (otherwise):
        - $O\left( M + \frac{\log M}{\log \log M} \log n \right)$

## twelvefold_way&lt;true, false&gt;::at_most_1
```cpp
template <typename M>
M twelvefold_way<true, false>::at_most_1(long long n, long long k);
```

It returns the remainder of the number of ways to put all of the $n$ labeled balls to $k$ unlabeled boxes when the number of balls per box is at most $1$ divided by `M::mod()`.

### Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $n \geq 0$
- $k \geq 0$

### Time Complexity
- $O(1)$

## twelvefold_way&lt;true, false&gt;::unrestricted
```cpp
template <typename M>
M twelvefold_way<true, false>::unrestricted(long long n, long long k);
```

It returns the remainder of the number of ways to put all of the $n$ labeled balls to $k$ unlabeled boxes when the number of balls per box is unrestricted divided by `M::mod()`.

### Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $n \geq 0$
- $k \geq 0$

### Time Complexity
- ($M$ is a prime and $\min(n, k) < M$):
    - $O(\min(n, k) \log n)$
- (otherwise):
    - $O(nk)$

## twelvefold_way&lt;true, false&gt;::at_least_1
```cpp
template <typename M>
M twelvefold_way<true, false>::at_least_1(long long n, long long k);
```

It returns the remainder of the number of ways to put all of the $n$ labeled balls to $k$ unlabeled boxes when the number of balls per box is at least $1$ divided by `M::mod()`.

### Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $n \geq 0$
- $k \geq 0$

### Time Complexity
- ($n < k$):
    - $O(1)$
- ($k \leq n$):
    - ($M$ is a prime and $k < M$):
        - $O(k \log n)$
    - (otherwise):
        - $O(nk)$

## twelvefold_way&lt;false, false&gt;::at_most_1
```cpp
template <typename M>
M twelvefold_way<false, false>::at_most_1(long long n, long long k);
```

It returns the remainder of the number of ways to put all of the $n$ unlabeled balls to $k$ unlabeled boxes when the number of balls per box is at most $1$ divided by `M::mod()`.

### Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $n \geq 0$
- $k \geq 0$

### Time Complexity
- $O(1)$

## twelvefold_way&lt;false, false&gt;::unrestricted
```cpp
template <typename M>
M twelvefold_way<false, false>::unrestricted(long long n, long long k);
```

It returns the remainder of the number of ways to put all of the $n$ unlabeled balls to $k$ unlabeled boxes when the number of balls per box is unrestricted divided by `M::mod()`.

### Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $n \geq 0$
- $k \geq 0$

### Time Complexity
- ($n = k$):
    - $O(n \log n)$
- (otherwise):
    - $O(n \min(n, k))$

## twelvefold_way&lt;false, false&gt;::at_least_1
```cpp
template <typename M>
M twelvefold_way<false, false>::at_least_1(long long n, long long k);
```

It returns the remainder of the number of ways to put all of the $n$ unlabeled balls to $k$ unlabeled boxes when the number of balls per box is at least $1$ divided by `M::mod()`.

### Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $n \geq 0$
- $k \geq 0$

### Time Complexity
- ($n < k$):
    - $O(1)$
- ($n = 2k$):
    - $O(k \log k)$
- (otherwise):
    - $O((n - k) \min(n - k, k))$
