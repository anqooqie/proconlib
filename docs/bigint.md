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
(1) bigint x;
(2) bigint x(std::int_fast64_t n);
(3) bigint x(const std::string& s);
```

- (1)
    - It creates an arbitrary precision integer whose value is $0$.
- (2)
    - It creates an arbitrary precision integer whose value is $n$.
- (3)
    - It parses $s$ as a signed integer and creates an arbitrary precision integer whose value is parsed $s$.

### Constraints
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

## multiply_by_pow10000
```cpp
bigint& x.multiply_by_pow10000(std::ptrdiff_t e);
```

It updates $x$ to $10000^e x$ rounded towards zero, and returns the updated $x$.

### Constraints
- None

### Time Complexity
- $O(\log \|x\| + \max(0, e))$

## divide_by_pow10000
```cpp
bigint& x.divide_by_pow10000(std::ptrdiff_t e);
```

It updates $x$ to $10000^{-e} x$ rounded towards zero, and returns the updated $x$.

### Constraints
- None

### Time Complexity
- $O(\log \|x\| + \max(0, -e))$

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

It returns $\left\lceil \log_{10000} \|x\| \right\rceil$.

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
\left\lfloor \frac{|x|}{10000^i} \right\rfloor \bmod 10000
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
- $\left\lceil \log_{10000} \|x\| \right\rceil + \left\lceil \log_{10000} \|y\| \right\rceil - 1 \leq 2^{25}$

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
- $y \neq 0$
- $3 \left\lceil \log_{10000} \|y\| \right\rceil + 2 \leq 2^{25}$
- $\left\lceil \log_{10000} \|x\| \right\rceil + \left\lceil \log_{10000} \|y\| \right\rceil \leq 2^{25}$

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
- $y \neq 0$
- $3 \left\lceil \log_{10000} \|y\| \right\rceil + 2 \leq 2^{25}$
- $\left\lceil \log_{10000} \|x\| \right\rceil + \left\lceil \log_{10000} \|y\| \right\rceil \leq 2^{25}$

### Time Complexity
- $O((\log \|x\| + \log \|y\|) \log (\log \|x\| + \log \|y\|))$

## operator>>
```cpp
std::istream& operator>>(std::istream& is, bigint& x);
```

It parses the input as a signed integer and creates an arbitrary precision integer whose value is it.

### Constraints
- The input is expressed as `[+-]?[0-9]+` in regular expressions

### Time Complexity
- $O(n)$ where $n$ is the length of the input

## operator<<
```cpp
std::ostream& operator<<(std::ostream& os, const bigint& x);
```

It prints $x$ to `os`.

### Constraints
- None

### Time Complexity
- $O(\log \|x\|)$
