---
title: Rational number
documentation_of: //tools/rational.hpp
---

It is a rational number.

For explanatory purposes, let $n_\circ$ denote the numerator of $\circ$ and $d_\circ$ denote the denominator of $\circ$ in this page.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) rational x;
(2) rational x(long long n);
(3) rational x(const tools::bigint& n);
(4) rational x(const tools::bigdecimal& n);
(5) rational x(long long n, long long d);
(6) rational x(const tools::bigint& n, const tools::bigint& d);
```

- (1)
    - It creates a rational nubmer which is $\frac{0}{1}$.
- (2), (3)
    - It creates a rational number which is $\frac{n}{1}$.
- (4)
    - It creates a rational number which is numerically equal to $n$.
- (5), (6)
    - It creates a rational number which is $\frac{n}{d}$.

### Constraints
- (5), (6)
    - $d \neq 0$

### Time Complexity
- (1)
    - $O(1)$
- (2)
    - $O(1)$
- (3)
    - $O(\log \|n\|)$
- (4)
    - $O(\log \|u_n\|)$ where $u_n$ is the unscaled value of $n$
- (5), (6)
    - $O((\log \|n\| + \log \|d\|)^2 \log (\log \|n\| + \log \|d\|))$

## numerator
```cpp
const tools::bigint& x.numerator();
```

It returns the numerator of $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## denominator
```cpp
const tools::bigint& x.denominator();
```

It returns the denominator of $x$.
The denominator of $x$ is always positive.

### Constraints
- None

### Time Complexity
- $O(1)$

## signum
```cpp
int x.signum();
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
-1 & \text{(if $x < 0$)}\\
0 & \text{(if $x = 0$)}\\
1 & \text{(if $x > 0$)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(1)$

## negate
```cpp
rational& x.negate();
```

It updates $x$ to $-x$, and returns the updated $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## abs
```cpp
rational x.abs();
```

It returns $\|x\|$.

### Constraints
- None

### Time Complexity
- $O(\log \|n_x\| + \log \|d_x\|)$

## compare_3way
```cpp
int rational::compare_3way(const rational& x, const rational& y);
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
-1 & \text{(if $x < y$)}\\
0 & \text{(if $x = y$)}\\
1 & \text{(if $x > y$)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O((\log \|n_x\| + \log \|d_y\|) \log (\log \|n_x\| + \log \|d_y\|) + (\log \|n_y\| + \log \|d_x\|) \log (\log \|n_y\| + \log \|d_x\|))$

## Comparison operators
```cpp
(1) bool operator==(const rational& x, const rational& y);
(2) bool operator!=(const rational& x, const rational& y);
(3) bool operator<(const rational& x, const rational& y);
(4) bool operator>(const rational& x, const rational& y);
(5) bool operator<=(const rational& x, const rational& y);
(6) bool operator>=(const rational& x, const rational& y);
```

It compares $x$ and $y$, and returns the result.

### Constraints
- None

### Time Complexity
- (1), (2)
    - $O(\log \|n_x\| + \log \|d_x\| + \log \|n_y\| + \log \|d_y\|)$
- (3), (4), (5), (6)
    - $O((\log \|n_x\| + \log \|d_y\|) \log (\log \|n_x\| + \log \|d_y\|) + (\log \|n_y\| + \log \|d_x\|) \log (\log \|n_y\| + \log \|d_x\|))$

## Unary operators
```cpp
(1) rational x.operator+();
(2) rational x.operator-();
```

- (1)
    - It returns $x$.
- (2)
    - It returns $-x$.

### Constraints
- None

### Time Complexity
- $O(\log \|n_x\| + \log \|d_x\|)$

## Addition operators
```cpp
(1) rational& x.operator+=(const rational& y);
(2) rational operator+(const rational& x, const rational& y);
```

- (1)
    - It updates $x$ to $x + y$, and returns the updated $x$.
- (2)
    - It returns $x + y$.

### Constraints
- $\left\lceil \log_{10000} \|n_x\| \right\rceil + \left\lceil \log_{10000} \|d_y\| \right\rceil - 1 \leq 2^{25}$
- $\left\lceil \log_{10000} \|n_y\| \right\rceil + \left\lceil \log_{10000} \|d_x\| \right\rceil - 1 \leq 2^{25}$
- $3 \left\lceil \log_{10000} \|d_x d_y\| \right\rceil + 2 \leq 2^{25}$
- $\left\lceil \log_{10000} \|n_x d_y + n_y d_x\| \right\rceil + \left\lceil \log_{10000} \|d_x d_y\| \right\rceil \leq 2^{25}$

### Time Complexity
- $O((\log \|d_x d_y\| + \log(\|n_x d_y\| + \|n_y d_x\|))^2 \log(\log \|d_x d_y\| + \log(\|n_x d_y\| + \|n_y d_x\|)))$

## Subtraction operators
```cpp
(1) rational& x.operator-=(const rational& y);
(2) rational operator-(const rational& x, const rational& y);
```

- (1)
    - It updates $x$ to $x - y$, and returns the updated $x$.
- (2)
    - It returns $x - y$.

### Constraints
- $\left\lceil \log_{10000} \|n_x\| \right\rceil + \left\lceil \log_{10000} \|d_y\| \right\rceil - 1 \leq 2^{25}$
- $\left\lceil \log_{10000} \|n_y\| \right\rceil + \left\lceil \log_{10000} \|d_x\| \right\rceil - 1 \leq 2^{25}$
- $3 \left\lceil \log_{10000} \|d_x d_y\| \right\rceil + 2 \leq 2^{25}$
- $\left\lceil \log_{10000} \|n_x d_y - n_y d_x\| \right\rceil + \left\lceil \log_{10000} \|d_x d_y\| \right\rceil \leq 2^{25}$

### Time Complexity
- $O((\log \|d_x d_y\| + \log(\|n_x d_y\| + \|n_y d_x\|))^2 \log(\log \|d_x d_y\| + \log(\|n_x d_y\| + \|n_y d_x\|)))$

## Multiplication operators
```cpp
(1) rational& x.operator*=(const rational& y);
(2) rational operator*(const rational& x, const rational& y);
```

- (1)
    - It updates $x$ to $xy$, and returns the updated $x$.
- (2)
    - It returns $xy$.

### Constraints
- $3 \left\lceil \log_{10000} \|d_x d_y\| \right\rceil + 2 \leq 2^{25}$
- $\left\lceil \log_{10000} \|n_x n_y\| \right\rceil + \left\lceil \log_{10000} \|d_x d_y\| \right\rceil \leq 2^{25}$

### Time Complexity
- $O((\log \|d_x d_y\| + \log \|n_x n_y\|)^2 \log(\log \|d_x d_y\| + \log \|n_x n_y\|))$

## Division operators
```cpp
(1) rational& x.operator/=(const rational& y);
(2) rational operator/(const rational& x, const rational& y);
```

- (1)
    - It updates $x$ to $\frac{x}{y}$, and returns the updated $x$.
- (2)
    - It returns $\frac{x}{y}$.

### Constraints
- $3 \left\lceil \log_{10000} \|d_x n_y\| \right\rceil + 2 \leq 2^{25}$
- $\left\lceil \log_{10000} \|n_x d_y\| \right\rceil + \left\lceil \log_{10000} \|d_x n_y\| \right\rceil \leq 2^{25}$

### Time Complexity
- $O((\log \|d_x n_y\| + \log \|n_x d_y\|)^2 \log(\log \|d_x n_y\| + \log \|n_x d_y\|))$

## operator T
```cpp
T explicit operator T(rational& x);
```

It casts $x$ to the type `T`.

### Constraints
- `T` is a built-in integral type or `double`.
- `std::numeric_limits<T>::min()` $\leq x \leq$ `std::numeric_limits<T>::max()`

### Time Complexity
- $O((\log \|d_x n_y\| + \log \|n_x d_y\|)^2 \log(\log \|d_x n_y\| + \log \|n_x d_y\|))$

## operator>>
```cpp
std::istream& operator>>(std::istream& is, rational& x);
```

It parses the input as a signed number and creates a rational number which is numerically equal to it.

### Constraints
- The input is expressed as `[+-]?[0-9]+(\.[0-9]+)?` in regular expressions

### Time Complexity
- $O(n^2 \log n)$ where $n$ is the length of the input

## operator<<
```cpp
std::ostream& operator<<(std::ostream& os, const rational& x);
```

It prints $x$ to `os`.

### Constraints
- None

### Time Complexity
- $O(\log \|n_x\| + \log \|d_x\|)$
