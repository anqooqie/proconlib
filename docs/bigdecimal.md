---
title: Arbitrary precision floating-point number
documentation_of: //tools/bigdecimal.hpp
---

It is an arbitrary precision floating-point number.
It consists of two integers, the unscaled value and the scale.
In other words, an arbitrary precision number $x$ is managed as the form $x_u \times 10^{-x_s}$ where $x_u \in \mathbb{Z}$ is the unscaled value of $x$ and $x_s \in \mathbb{Z}$ is the scale of $x$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) bigdecimal x;
(2) bigdecimal x(tools::integral auto n);
(3) bigdecimal x(const tools::bigint& n);
(4) bigdecimal x(std::string s);
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

## abs_inplace
```cpp
bigdecimal& x.abs_inplace();
```

It updates $x$ to $\|x\|$, and returns the updated $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## divide
```cpp
(1) bigdecimal x.divide(const bigdecimal& y, const std::ptrdiff_t s);
(2) bigdecimal x.divide(const bigdecimal& y, const std::ptrdiff_t s, const tools::rounding_mode rounding_mode);
```

- (1)
    - It returns $z$ such that $z_u$ is $10^{s - (x_s - y_s)}\frac{x_u}{y_u}$ rounded by banker's rounding mode and $z_s$ is $s$.
- (2)
    - It returns $z$ such that $z_u$ is $10^{s - (x_s - y_s)}\frac{x_u}{y_u}$ rounded by the specified rounding mode and $z_s$ is $s$.

### Constraints
- $0 < \|y_u\| < 10^{2^{27}} = 10^{134217728}$

### Time Complexity
- $O((\log \|10^{s - (x_s - y_s)} x_u\| + \log \|y_u\|) \log (\log \|10^{s - (x_s - y_s)} x_u\| + \log \|y_u\|))$

## divide_by_pow10
```cpp
bigdecimal x.divide_by_pow10(std::ptrdiff_t n);
```

It returns $y$ such that $y_s$ is $x_s + n$.
In other words, it returns $10^{-n} x$ while keeping the precision of $x$.

### Constraints
- None

### Time Complexity
- $O(\log \|x_u\|)$

## divide_inplace
```cpp
(1) bigdecimal& x.divide_inplace(const bigdecimal& y, const std::ptrdiff_t s);
(2) bigdecimal& x.divide_inplace(const bigdecimal& y, const std::ptrdiff_t s, const tools::rounding_mode rounding_mode);
```

- (1)
    - It updates $x_u$ to $10^{s - (x_s - y_s)}\frac{x_u}{y_u}$ rounded by banker's rounding mode and $x_s$ to $s$, and returns the updated $x$.
- (2)
    - It updates $x_u$ to $10^{s - (x_s - y_s)}\frac{x_u}{y_u}$ rounded by the specified rounding mode and $x_s$ to $s$, and returns the updated $x$.

### Constraints
- $0 < \|y_u\| < 10^{2^{27}} = 10^{134217728}$

### Time Complexity
- $O((\log \|10^{s - (x_s - y_s)} x_u\| + \log \|y_u\|) \log (\log \|10^{s - (x_s - y_s)} x_u\| + \log \|y_u\|))$

## divide_inplace_by_pow10
```cpp
bigdecimal& x.divide_inplace_by_pow10(std::ptrdiff_t n);
```

It updates $x_s$ to $x_s + n$, and returns the updated $x$.
In other words, it updates $x$ to $10^{-n} x$ while keeping the precision of $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## multiply_by_pow10
```cpp
bigdecimal x.multiply_by_pow10(std::ptrdiff_t n);
```

It returns $y$ such that $y_s$ is $x_s - n$.
In other words, it returns $10^n x$ while keeping the precision of $x$.

### Constraints
- None

### Time Complexity
- $O(\log \|x_u\|)$

## multiply_inplace_by_pow10
```cpp
bigdecimal& x.multiply_inplace_by_pow10(std::ptrdiff_t n);
```

It updates $x_s$ to $x_s - n$, and returns the updated $x$.
In other words, it updates $x$ to $10^n x$ while keeping the precision of $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## negate
```cpp
bigdecimal& x.negate();
```

It updates $x_u$ to $-x_u$, and returns the updated $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## precision
```cpp
std::size_t x.precision();
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
\left\lfloor \log_{10} |x_u| \right\rfloor + 1 & \text{(if $x \neq 0$)}\\
0 & \text{(if $x = 0$)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(1)$

## scale
```cpp
std::ptrdiff_t x.scale();
```

It returns $x_s$.

### Constraints
- None

### Time Complexity
- $O(1)$

## set_scale
```cpp
bigdecimal& x.set_scale(std::ptrdiff_t s);
```

It updates $u_x$ to $10^{s - x_s} x_u$ rounded towards zero and $x_s$ to $s$, and returns the updated $x$.
In other words, it updates the scale of $x$ to the specified value while keeping the numerical value of $x$.

### Constraints
- None

### Time Complexity
- $O(\log \|x_u\| + \max(0, s - x_s))$

## unscaled_value
```cpp
const tools::bigint& x.unscaled_value();
```

It returns $x_u$.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator&lt;=&gt;
```cpp
std::weak_ordering operator<=>(const bigdecimal& x, const bigdecimal& y);
```

If $x < y$, then it returns `std::weak_ordering::less`.
If $x = y$, then it returns `std::weak_ordering::equivalent`.
If $x > y$, then it returns `std::weak_ordering::greater`.

### Constraints
- None

### Time Complexity
- $O(\log \|x_u\| + \log \|y_u\|)$

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
- $O(\log \|x_u\| + \log \|y_u\|)$

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
- $O(\log \|x_u\|)$

## Addition operators
```cpp
(1) bigdecimal& x.operator+=(const bigdecimal& y);
(2) bigdecimal operator+(const bigdecimal& x, const bigdecimal& y);
```

- (1)
    - It updates $x$ to $x + y$ and $x_s$ to $\max(x_s, y_s)$, and returns the updated $x$.
- (2)
    - It returns $x + y$ whose scale is $\max(x_s, y_s)$.

### Constraints
- None

### Time Complexity
- $O(\log \|x_u\| + \log \|y_u\| + \|x_s - y_s\|)$

## Subtraction operators
```cpp
(1) bigdecimal& x.operator-=(const bigdecimal& y);
(2) bigdecimal operator-(const bigdecimal& x, const bigdecimal& y);
```

- (1)
    - It updates $x$ to $x - y$ and $x_s$ to $\max(x_s, y_s)$, and returns the updated $x$.
- (2)
    - It returns $x - y$ whose scale is $\max(x_s, y_s)$.

### Constraints
- None

### Time Complexity
- $O(\log \|x_u\| + \log \|y_u\| + \|x_s - y_s\|)$

## Multiplication operators
```cpp
(1) bigdecimal& x.operator*=(const bigdecimal& y);
(2) bigdecimal operator*(const bigdecimal& x, const bigdecimal& y);
```

- (1)
    - It updates $x_u$ to $x_u y_u$ and $x_s$ to $x_s + y_s$, and returns the updated $x$.
- (2)
    - It returns the arbitrary precision floating-point number whose unscaled value is $x_u y_u$ and scale is $x_s + y_s$.

### Constraints
- $\| x_u y_u \| < 10^{2^{27} + 4} = 10^{134217732}$

### Time Complexity
- $O((\log \|x_u\| + \log \|y_u\|) \log (\log \|x_u\| + \log \|y_u\|))$

## Division operators
```cpp
(1) bigdecimal& x.operator/=(const bigdecimal& y);
(2) bigdecimal operator/(const bigdecimal& x, const bigdecimal& y);
```

- (1)
    - It updates $x_u$ to $\frac{x_u}{y_u}$ rounded by banker's rounding and $x_s$ to $x_s - y_s$, and returns the updated $x$.
- (2)
    - It returns the arbitrary precision floating-point number whose unscaled value is $\frac{x_u}{y_u}$ rounded by banker's rounding and scale is $x_s - y_s$.

### Constraints
- $0 < \|y_u\| < 10^{2^{27}} = 10^{134217728}$

### Time Complexity
- $O((\log \|x_u\| + \log \|y_u\|) \log (\log \|x_u\| + \log \|y_u\|))$

## operator T
```cpp
T explicit operator T(const bigdecimal& x);
```

It casts $x$ to the type `T`.

### Constraints
- `T` is a built-in integral type or `double`.
- `std::numeric_limits<T>::min()` $\leq x \leq$ `std::numeric_limits<T>::max()`

### Time Complexity
- $O(\log \|x_u\|)$

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
- $O(\max(\log(\|x_u\|), \|x_s\|))$

## tools::abs
```cpp
bigdecimal tools::abs(bigdecimal x);
```

It returns $\|x\|$.

### Constraints
- None

### Time Complexity
- $O(\log \|x_u\|)$

## tools::signum
```cpp
int tools::signum(bigdecimal x);
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
