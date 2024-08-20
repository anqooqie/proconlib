---
title: Arbitrary precision integer
documentation_of: //tools/bigint.hpp
---

It is an arbitrary precision integer.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) bigint x();
(2) template <typename Z> bigint x(Z n);
(3) bigint x(const std::string& s);
```

- (1)
    - It creates an arbitrary precision integer whose value is $0$.
- (2)
    - It creates an arbitrary precision integer whose value is $n$.
- (3)
    - It parses $s$ as a signed integer and creates an arbitrary precision integer whose value is parsed $s$.

### Constraints
- (2)
    - `std::is_integral_v<Z>` holds, `<Z>` is `tools::int128_t` or `<Z>` is `tools::uint128_t`.
- (3)
    - $s$ is expressed as `[+-]?[0-9]+` in regular expressions

### Time Complexity
- (1)
    - $O(1)$
- (2)
    - $O(1)$
- (3)
    - $O(\|s\|)$

## negate
```cpp
bigint& x.negate();
```

It updates $x$ to $-x$, and returns the updated $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## multiply_by_pow10
```cpp
bigint& x.multiply_by_pow10(std::ptrdiff_t n);
```

It updates $x$ to $10^n x$ rounded towards zero, and returns the updated $x$.

### Constraints
- None

### Time Complexity
- $O(\log \|x\| + \max(0, n))$

## divide_by_pow10
```cpp
bigint& x.divide_by_pow10(std::ptrdiff_t n);
```

It updates $x$ to $10^{-n} x$ rounded towards zero, and returns the updated $x$.

### Constraints
- None

### Time Complexity
- $O(\log \|x\| + \max(0, -n))$

## compare_3way
```cpp
int bigint::compare_3way(const bigint& x, const bigint& y);
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
- $O(\log \|x\| + \log \|y\|)$

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

## size
```cpp
std::size_t x.size();
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
\left\lfloor \log_{10} |x| \right\rfloor + 1 & \text{(if $x \neq 0$)}\\
0 & \text{(if $x = 0$)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(1)$

## operator[]
```cpp
std::int_fast32_t x.operator[](std::size_t i);
```

It returns

$$\begin{align*}
\left\lfloor \frac{|x|}{10^i} \right\rfloor \bmod 10
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(1)$

## Comparison operators
```cpp
bool operator==(const bigint& x, const bigint& y);
bool operator!=(const bigint& x, const bigint& y);
bool operator<(const bigint& x, const bigint& y);
bool operator>(const bigint& x, const bigint& y);
bool operator<=(const bigint& x, const bigint& y);
bool operator>=(const bigint& x, const bigint& y);
```

It compares $x$ and $y$, and returns the result.

### Constraints
- None

### Time Complexity
- $O(\log \|x\| + \log \|y\|)$

## Unary operators
```cpp
(1) bigint x.operator+();
(2) bigint x.operator-();
```

- (1)
    - It returns $x$.
- (2)
    - It returns $-x$.

### Constraints
- None

### Time Complexity
- $O(\log \|x\|)$

## Addition operators
```cpp
(1) bigint& x.operator+=(const bigint& y);
(2) bigint operator+(const bigint& x, const bigint& y);
```

- (1)
    - It updates $x$ to $x + y$, and returns the updated $x$.
- (2)
    - It returns $x + y$.

### Constraints
- None

### Time Complexity
- $O(\log \|x\| + \log \|y\|)$

## Subtraction operators
```cpp
(1) bigint& x.operator-=(const bigint& y);
(2) bigint operator-(const bigint& x, const bigint& y);
```

- (1)
    - It updates $x$ to $x - y$, and returns the updated $x$.
- (2)
    - It returns $x - y$.

### Constraints
- None

### Time Complexity
- $O(\log \|x\| + \log \|y\|)$

## Multiplication operators
```cpp
(1) bigint& x.operator*=(const bigint& y);
(2) bigint operator*(const bigint& x, const bigint& y);
```

- (1)
    - It updates $x$ to $xy$, and returns the updated $x$.
- (2)
    - It returns $xy$.

### Constraints
- $\|xy\| < 10^{2^{27} + 4} = 10^{134217732}$

### Time Complexity
- $O((\log \|x\| + \log \|y\|) \log (\log \|x\| + \log \|y\|))$

## Division operators
```cpp
(1) bigint& x.operator/=(const bigint& y);
(2) bigint operator/(const bigint& x, const bigint& y);
```

- (1)
    - It updates $x$ to $\frac{x}{y}$ rounded towards zero, and returns the updated $x$.
- (2)
    - It returns $\frac{x}{y}$ rounded towards zero.

### Constraints
- $0 < \|y\| < 10^{2^{27}} = 10^{134217728}$

### Time Complexity
- $O((\log \|x\| + \log \|y\|) \log (\log \|x\| + \log \|y\|))$

## Modulo operators
```cpp
(1) bigint& x.operator%=(const bigint& y);
(2) bigint operator%(const bigint& x, const bigint& y);
```

- (1)
    - It updates $x$ to $x - qy$ where $q$ is $\frac{x}{y}$ rounded towards zero, and returns the updated $x$.
- (2)
    - It returns $x - qy$ where $q$ is $\frac{x}{y}$ rounded towards zero.

### Constraints
- $0 < \|y\| < 10^{2^{27}} = 10^{134217728}$

### Time Complexity
- $O((\log \|x\| + \log \|y\|) \log (\log \|x\| + \log \|y\|))$

## divmod
```cpp
std::pair<bigint, bigint> x.divmod(const bigint& y);
```

It returns `x / y` and `x % y`.

### Constraints
- $0 < \|y\| < 10^{2^{27}} = 10^{134217728}$

### Time Complexity
- $O((\log \|x\| + \log \|y\|) \log (\log \|x\| + \log \|y\|))$

## operator T
```cpp
T explicit operator T(bigint& x);
```

It casts $x$ to the type `T`.

### Constraints
- `T` is a built-in integral type, `double`, `tools::int128_t` or `tools::uint128_t`.
- the minimum value of `<T>` $\leq x \leq$ the maximum value of `<T>`

### Time Complexity
- $O(\log \|x\|)$

## operator&gt;&gt;
```cpp
std::istream& operator>>(std::istream& is, bigint& x);
```

It parses the input as a signed integer and creates an arbitrary precision integer whose value is it.

### Constraints
- The input is expressed as `[+-]?[0-9]+` in regular expressions

### Time Complexity
- $O(n)$ where $n$ is the length of the input

## operator&lt;&lt;
```cpp
std::ostream& operator<<(std::ostream& os, const bigint& x);
```

It prints $x$ to `os`.

### Constraints
- None

### Time Complexity
- $O(\log \|x\|)$

## tools::abs
```cpp
bigint tools::abs(bigint x);
```

It returns $\|x\|$.

### Constraints
- None

### Time Complexity
- $O(\log \|x\|)$

## tools::gcd
```cpp
bigint tools::gcd(bigint x, bigint y);
```

It returns $\gcd(x, y)$.

### Constraints
- $\min\left(\|x\|, \|y\|\right) < 10^{2^{27}} = 10^{134217728}$

### Time Complexity
- $O((\log \|x\| + \log \|y\|)^2 \log (\log \|x\| + \log \|y\|))$
