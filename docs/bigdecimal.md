---
title: Arbitrary precision floating-point number
documentation_of: //tools/bigdecimal.hpp
---

It is an arbitrary precision floating-point number.
It consists of two integers, the unscaled value and the scale.
In other words, an arbitrary precision number $x$ is managed as the form $u_x \times 10^{-s_x}$ where $u_x$ is the unscaled value of $x$ and $s_x$ is the scale of $x$.

For explanatory purposes, let $u_\circ$ denote the unscaled value of $\circ$ and $s_\circ$ denote the scale of $\circ$ in this page.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) bigdecimal x;
(2) bigdecimal x(long long n);
(3) bigdecimal x(const tools::bigint& n);
(4) bigdecimal x(const std::string& s);
```

- (1)
    - It creates an arbitrary precision floating-point number whose unscaled value is $0$ and scale is $0$.
- (2), (3)
    - It creates an arbitrary precision floating-point number whose unscaled value is $n$ and scale is $0$.
- (4)
    - It parses $s$ as a signed number and creates an arbitrary precision floating-point number whose value is parsed $s$.

### Constraints
- (4)
    - $s$ is expressed as `[+-]?[0-9]+(\.[0-9]+)?` in regular expressions

### Time Complexity
- (1)
    - $O(1)$
- (2)
    - $O(1)$
- (3)
    - $O(\log \|n\|)$
- (4)
    - $O(\|s\|)$

## unscaled_value
```cpp
const tools::bigint& x.unscaled_value();
```

It returns $u_x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## precision
```cpp
std::size_t x.precision();
```

It returns $\left\lceil \log_{10} \|u_x\| \right\rceil$.

### Constraints
- None

### Time Complexity
- $O(1)$

## scale
```cpp
std::ptrdiff_t x.scale();
```

It returns $s_x$.

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
bigdecimal& x.negate();
```

It updates $u_x$ to $-u_x$, and returns the updated $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## multiply_by_pow10
```cpp
bigdecimal& x.multiply_by_pow10(std::ptrdiff_t n);
```

It updates $s_x$ to $s_x - n$, and returns the updated $x$.
In other words, it updates $x$ to $10^n x$ while keeping the precision of $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## divide_by_pow10
```cpp
bigdecimal& x.divide_by_pow10(std::ptrdiff_t n);
```

It updates $s_x$ to $s_x + n$, and returns the updated $x$.
In other words, it updates $x$ to $10^{-n} x$ while keeping the precision of $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## set_scale
```cpp
bigdecimal& x.set_scale(std::ptrdiff_t s);
```

It updates $u_x$ to $10^{s - s_x} u_x$ rounded towards zero and $s_x$ to $s$, and returns the updated $x$.
In other words, it updates the scale of $x$ to the specified value while keeping the numerical value of $x$.

### Constraints
- None

### Time Complexity
- $O(\log \|u_x\| + \max(0, s - s_x))$

## compare_3way
```cpp
int bigdecimal::compare_3way(const bigdecimal& x, const bigdecimal& y);
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
- $O(\log \|u_x\| + \log \|u_y\|)$

## Comparison operators
```cpp
bool operator==(const bigdecimal& x, const bigdecimal& y);
bool operator!=(const bigdecimal& x, const bigdecimal& y);
bool operator<(const bigdecimal& x, const bigdecimal& y);
bool operator>(const bigdecimal& x, const bigdecimal& y);
bool operator<=(const bigdecimal& x, const bigdecimal& y);
bool operator>=(const bigdecimal& x, const bigdecimal& y);
```

It compares $x$ and $y$, and returns the result.

### Constraints
- None

### Time Complexity
- $O(\log \|u_x\| + \log \|u_y\|)$

## Unary operators
```cpp
(1) bigdecimal x.operator+();
(2) bigdecimal x.operator-();
```

- (1)
    - It returns $x$.
- (2)
    - It returns $-x$.

### Constraints
- None

### Time Complexity
- $O(\log \|u_x\|)$

## Addition operators
```cpp
(1) bigdecimal& x.operator+=(const bigdecimal& y);
(2) bigdecimal operator+(const bigdecimal& x, const bigdecimal& y);
```

- (1)
    - It updates $x$ to $x + y$ and $s_x$ to $\max(s_x, s_y)$, and returns the updated $x$.
- (2)
    - It returns $x + y$ whose scale is $\max(s_x, s_y)$.

### Constraints
- None

### Time Complexity
- $O(\log \|u_x\| + \log \|u_y\| + \|s_x - s_y\|)$

## Subtraction operators
```cpp
(1) bigdecimal& x.operator-=(const bigdecimal& y);
(2) bigdecimal operator-(const bigdecimal& x, const bigdecimal& y);
```

- (1)
    - It updates $x$ to $x - y$ and $s_x$ to $\max(s_x, s_y)$, and returns the updated $x$.
- (2)
    - It returns $x - y$ whose scale is $\max(s_x, s_y)$.

### Constraints
- None

### Time Complexity
- $O(\log \|u_x\| + \log \|u_y\| + \|s_x - s_y\|)$

## Multiplication operators
```cpp
(1) bigdecimal& x.operator*=(const bigdecimal& y);
(2) bigdecimal operator*(const bigdecimal& x, const bigdecimal& y);
```

- (1)
    - It updates $u_x$ to $u_x u_y$ and $s_x$ to $s_x + s_y$, and returns the updated $x$.
- (2)
    - It returns the arbitrary precision floating-point number whose unscaled value is $u_x u_y$ and scale is $s_x + s_y$.

### Constraints
- $\left\lceil \log_{10000} \|u_x\| \right\rceil + \left\lceil \log_{10000} \|u_y\| \right\rceil - 1 \leq 2^{25}$

### Time Complexity
- $O((\log \|u_x\| + \log \|u_y\|) \log (\log \|u_x\| + \log \|u_y\|))$

## Division operators
```cpp
(1) bigdecimal& x.operator/=(const bigdecimal& y);
(2) bigdecimal operator/(const bigdecimal& x, const bigdecimal& y);
```

- (1)
    - It updates $u_x$ to $\frac{u_x}{u_y}$ rounded by banker's rounding and $s_x$ to $s_x - s_y$, and returns the updated $x$.
- (2)
    - It returns the arbitrary precision floating-point number whose unscaled value is $\frac{u_x}{u_y}$ rounded by banker's rounding and scale is $s_x - s_y$.

### Constraints
- $y \neq 0$
- $3 \left\lceil \log_{10000} \|u_y\| \right\rceil + 2 \leq 2^{25}$
- $\left\lceil \log_{10000} \|u_x\| \right\rceil + \left\lceil \log_{10000} \|u_y\| \right\rceil \leq 2^{25}$

### Time Complexity
- $O((\log \|u_x\| + \log \|u_y\|) \log (\log \|u_x\| + \log \|u_y\|))$

## divide
```cpp
(1) bigdecimal& x.divide(const bigdecimal& y, const std::ptrdiff_t s, const tools::rounding_mode rounding_mode);
(2) bigdecimal& x.divide(const bigdecimal& y, const std::ptrdiff_t s);
```

- (1)
    - It updates $u_x$ to $10^{s - (s_x - s_y)}\frac{u_x}{u_y}$ rounded by the specified rounding mode and $s_x$ to $s$, and returns the updated $x$.
- (2)
    - It updates $u_x$ to $10^{s - (s_x - s_y)}\frac{u_x}{u_y}$ rounded by banker's rounding mode and $s_x$ to $s$, and returns the updated $x$.

### Constraints
- $y \neq 0$
- $3 \left\lceil \log_{10000} \|u_y\| \right\rceil + 2 \leq 2^{25}$
- $\left\lceil \log_{10000} \|10^{s - (s_x - s_y)} u_x\| \right\rceil + \left\lceil \log_{10000} \|u_y\| \right\rceil \leq 2^{25}$

### Time Complexity
- $O((\log \|10^{s - (s_x - s_y)} u_x\| + \log \|u_y\|) \log (\log \|10^{s - (s_x - s_y)} u_x\| + \log \|u_y\|))$

## operator T
```cpp
T explicit operator T(bigdecimal& x);
```

It casts $x$ to the type `T`.

### Constraints
- `T` is a built-in integral type or `double`.
- `std::numeric_limits<T>::min()` $\leq x \leq$ `std::numeric_limits<T>::max()`

### Time Complexity
- $O(\log \|u_x\|)$

## operator&gt;&gt;
```cpp
std::istream& operator>>(std::istream& is, bigdecimal& x);
```

It parses the input as a signed number and creates an arbitrary precision floating-point number whose value is it.

### Constraints
- The input is expressed as `[+-]?[0-9]+(\.[0-9]+)?` in regular expressions

### Time Complexity
- $O(n)$ where $n$ is the length of the input

## operator&lt;&lt;
```cpp
std::ostream& operator<<(std::ostream& os, const bigdecimal& x);
```

It prints $x$ to `os`.

### Constraints
- None

### Time Complexity
- $O(\max(\log(\|u_x\|), \|s_x\|))$

## tools::abs
```cpp
bigdecimal tools::abs(bigdecimal x);
```

It returns $\|x\|$.

### Constraints
- None

### Time Complexity
- $O(\log \|u_x\|)$
