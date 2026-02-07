---
title: Rational number
documentation_of: //tools/rational.hpp
---

It is a rational number.

For explanatory purposes, for any $x \in \mathbb{Q}$, we define $x_n \in \mathbb{Z}$ and $x_d \in \mathbb{Z}_{> 0}$ such that the relation $x = \frac{x_n}{x_d}$ holds.
When automatic reduction is enabled, $\gcd(x_n, x_d) = 1$ is also simultaneously satisfied.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) rational<Z = tools::bigint, AutoReduce = true> x;
(2) rational<Z = tools::bigint, AutoReduce = true> x(Z n);
(3) rational<Z = tools::bigint, AutoReduce = true> x(const tools::bigdecimal& y);
(4) rational<Z = tools::bigint, AutoReduce = true> x(Z n, Z d);
```

- (1)
    - It creates a rational nubmer which is $\frac{0}{1}$.
- (2)
    - It creates a rational number which is $\frac{n}{1}$.
- (3)
    - It creates a rational number which is numerically equal to $y$.
- (4)
    - It creates a rational number which is $\frac{n}{d}$.

### Constraints
- `tools::signed_integral<Z>` holds or `Z` is `tools::bigint`.
- (4)
    - $d \neq 0$

### Time Complexity
- (1)
    - $O(1)$
- (2)
    - $O(\log \|n\|)$
- (3)
    - $O(\log \|y_u\|)$ where $y_u$ is the unscaled value of $y$
- (4)
    - `AutoReduce` is `true`: $O((\log \|nd\|)^2 \log (\log \|nd\|))$
    - `AutoReduce` is `false`: $O(\log \|nd\|)$

## abs_inplace
```cpp
rational<Z, AutoReduce>& x.abs_inplace();
```

It updates $x$ to $\|x\|$, and returns the updated $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## denominator
```cpp
const Z& x.denominator();
```

It returns $x_d$.
Note that $x_d$ is always positive.

### Constraints
- None

### Time Complexity
- $O(1)$

## negate
```cpp
rational<Z, AutoReduce>& x.negate();
```

It updates $x$ to $-x$, and returns the updated $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## numerator
```cpp
const Z& x.numerator();
```

It returns $x_n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## reduce
```cpp
rational<Z, AutoReduce>& x.reduce();
```

It reduces $x$.

### Constraints
- `AutoReduce` is `false`.

### Time Complexity
- $O((\log \|x_n x_d\|)^2 \log (\log \|x_n x_d\|))$

## operator&lt;=&gt;
```cpp
std::conditional_t<AutoReduce, std::strong_ordering, std::weak_ordering> operator<=>(const rational<Z, AutoReduce>& x, const rational<Z, AutoReduce>& y);
```

Let `T` be `std::conditional_t<AutoReduce, std::strong_ordering, std::weak_ordering>`.
If $x < y$, then it returns `T::less`.
If $x = y$, then it returns `T::eqivalent`.
If $x > y$, then it returns `T::greater`.

### Constraints
- None

### Time Complexity
- $O(\log \|x_n y_d\| \log (\log \|x_n y_d\|) + \log \|y_n x_d\| \log (\log \|y_n x_d\|))$

## Comparison operators
```cpp
(1) bool operator==(const rational<Z, AutoReduce>& x, const rational<Z, AutoReduce>& y);
(2) bool operator!=(const rational<Z, AutoReduce>& x, const rational<Z, AutoReduce>& y);
(3) bool operator<(const rational<Z, AutoReduce>& x, const rational<Z, AutoReduce>& y);
(4) bool operator>(const rational<Z, AutoReduce>& x, const rational<Z, AutoReduce>& y);
(5) bool operator<=(const rational<Z, AutoReduce>& x, const rational<Z, AutoReduce>& y);
(6) bool operator>=(const rational<Z, AutoReduce>& x, const rational<Z, AutoReduce>& y);
```

It compares $x$ and $y$, and returns the result.

### Constraints
- None

### Time Complexity
- (1), (2)
    - `AutoReduce` is `true`: $O(\log \|x_n x_d y_n y_d\|)$
    - `AutoReduce` is `false`: $O(\log \|x_n y_d\| \log (\log \|x_n y_d\|) + \log \|y_n x_d\| \log (\log \|y_n x_d\|))$
- (3), (4), (5), (6)
    - $O(\log \|x_n y_d\| \log (\log \|x_n y_d\|) + \log \|y_n x_d\| \log (\log \|y_n x_d\|))$

## Unary operators
```cpp
(1) rational<Z, AutoReduce> x.operator+();
(2) rational<Z, AutoReduce> x.operator-();
```

- (1)
    - It returns $x$.
- (2)
    - It returns $-x$.

### Constraints
- None

### Time Complexity
- $O(\log \|x_n\| + \log \|x_d\|)$

## Addition operators
```cpp
(1) rational<Z, AutoReduce>& x.operator+=(const rational<Z, AutoReduce>& y);
(2) rational<Z, AutoReduce> operator+(const rational<Z, AutoReduce>& x, const rational<Z, AutoReduce>& y);
```

- (1)
    - It updates $x$ to $x + y$, and returns the updated $x$.
- (2)
    - It returns $x + y$.

### Constraints
- $\| x_d y_d \| < 10^{2^{27}} = 10^{134217728}$
- $\| x_n y_d \| < 10^{2^{27} + 4} = 10^{134217732}$
- $\| y_n x_d \| < 10^{2^{27} + 4} = 10^{134217732}$

### Time Complexity
- `AutoReduce` is `true`: $O((\log \|x_d y_d\| + \log(\|x_n y_d\| + \|y_n x_d\|))^2 \log(\log \|x_d y_d\| + \log(\|x_n y_d\| + \|y_n x_d\|)))$
- `AutoReduce` is `false`: $O(\log \|x_n y_d\| \log(\log \|x_n y_d\|) + \log \|y_n x_d\| \log(\log \|y_n x_d\|) + \log \|x_d y_d\| \log(\log \|x_d y_d\|))$

## Subtraction operators
```cpp
(1) rational<Z, AutoReduce>& x.operator-=(const rational<Z, AutoReduce>& y);
(2) rational<Z, AutoReduce> operator-(const rational<Z, AutoReduce>& x, const rational<Z, AutoReduce>& y);
```

- (1)
    - It updates $x$ to $x - y$, and returns the updated $x$.
- (2)
    - It returns $x - y$.

### Constraints
- $\| x_d y_d \| < 10^{2^{27}} = 10^{134217728}$
- $\| x_n y_d \| < 10^{2^{27} + 4} = 10^{134217732}$
- $\| y_n x_d \| < 10^{2^{27} + 4} = 10^{134217732}$

### Time Complexity
- `AutoReduce` is `true`: $O((\log \|x_d y_d\| + \log(\|x_n y_d\| + \|y_n x_d\|))^2 \log(\log \|x_d y_d\| + \log(\|x_n y_d\| + \|y_n x_d\|)))$
- `AutoReduce` is `false`: $O(\log \|x_n y_d\| \log(\log \|x_n y_d\|) + \log \|y_n x_d\| \log(\log \|y_n x_d\|) + \log \|x_d y_d\| \log(\log \|x_d y_d\|))$

## Multiplication operators
```cpp
(1) rational<Z, AutoReduce>& x.operator*=(const rational<Z, AutoReduce>& y);
(2) rational<Z, AutoReduce> operator*(const rational<Z, AutoReduce>& x, const rational<Z, AutoReduce>& y);
```

- (1)
    - It updates $x$ to $xy$, and returns the updated $x$.
- (2)
    - It returns $xy$.

### Constraints
- $\| x_d y_d \| < 10^{2^{27}} = 10^{134217728}$
- $\| x_n y_n \| < 10^{2^{27} + 4} = 10^{134217732}$

### Time Complexity
- `AutoReduce` is `true`: $O((\log \|x_d y_d\| + \log \|x_n y_n\|)^2 \log(\log \|x_d y_d\| + \log \|x_n y_n\|))$
- `AutoReduce` is `false`: $O(\log \|x_n y_n\| \log(\log \|x_n y_n\|) + \log \|x_d y_d\| \log(\log \|x_d y_d\|))$

## Division operators
```cpp
(1) rational<Z, AutoReduce>& x.operator/=(const rational<Z, AutoReduce>& y);
(2) rational<Z, AutoReduce> operator/(const rational<Z, AutoReduce>& x, const rational<Z, AutoReduce>& y);
```

- (1)
    - It updates $x$ to $\frac{x}{y}$, and returns the updated $x$.
- (2)
    - It returns $\frac{x}{y}$.

### Constraints
- $\| x_d y_n \| < 10^{2^{27}} = 10^{134217728}$
- $\| x_n y_d \| < 10^{2^{27} + 4} = 10^{134217732}$

### Time Complexity
- `AutoReduce` is `true`: $O((\log \|x_d y_n\| + \log \|x_n y_d\|)^2 \log(\log \|x_d y_n\| + \log \|x_n y_d\|))$
- `AutoReduce` is `false`: $O(\log \|x_n y_d\| \log(\log \|x_n y_d\|) + \log \|x_d y_n\| \log(\log \|x_d y_n\|))$

## operator T
```cpp
T explicit x.operator T();
```

It casts $x$ to the type `T`.

### Constraints
- `tools::integral<T>` holds or `T` is `double`.
- `std::numeric_limits<T>::lowest()` $\leq x \leq$ `std::numeric_limits<T>::max()`

### Time Complexity
- `AutoReduce` is `true`: $O((\log \|x_d y_n\| + \log \|x_n y_d\|)^2 \log(\log \|x_d y_n\| + \log \|x_n y_d\|))$
- `AutoReduce` is `false`: $O(\log \|x_n y_d\| \log(\log \|x_n y_d\|) + \log \|x_d y_n\| \log(\log \|x_d y_n\|))$

## operator&gt;&gt;
```cpp
std::istream& operator>>(std::istream& is, rational<Z, AutoReduce>& x);
```

It parses the input as a signed number and creates a rational number which is numerically equal to it.

### Constraints
- The input is expressed as `[+-]?[0-9]+(\.[0-9]+)?` in regular expressions

### Time Complexity
- `AutoReduce` is `true`: $O(n^2 \log n)$ where $n$ is the length of the input
- `AutoReduce` is `false`: $O(n)$ where $n$ is the length of the input

## operator&lt;&lt;
```cpp
std::ostream& operator<<(std::ostream& os, const rational<Z, AutoReduce>& x);
```

It prints $x$ to `os`.

### Constraints
- None

### Time Complexity
- $O(\log \|x_n x_d\|)$

## tools::abs
```cpp
rational<Z, AutoReduce> tools::abs(rational<Z, AutoReduce> x);
```

It returns $\|x\|$.

### Constraints
- None

### Time Complexity
- $O(\log \|x_n x_d\|)$

## tools::signum
```cpp
int tools::signum(rational<Z, AutoReduce> x);
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
