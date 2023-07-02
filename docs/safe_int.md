---
title: $\mathbb{Z} \cup \{\infty, -\infty, \mathrm{NaN}\}$ and $\mathbb{Z}_{\geq 0} \cup \{\infty, \mathrm{NaN}\}$
documentation_of: //tools/safe_int.hpp
---

Given a signed integral type `<T>`, it adds the three special elements $\infty$, $-\infty$ and $\mathrm{NaN}$ to `<T>`.
Given an unsigned integral type `<T>`, it adds the two special elements $\infty$ and $\mathrm{NaN}$ to `<T>`.
If an arithmetic operation on finite integers causes overflow, the arithmetic operation will return $\mathrm{NaN}$.

### References
- [INT32-C. 符号付き整数演算がオーバーフローを引き起こさないことを保証する](https://www.jpcert.or.jp/sc-rules/c-int32-c.html)

### License
- CC0

### Author
- anqooqie

## infinity
```cpp
tools::safe_int<T> tools::safe_int<T>::infinity();
```

It returns $\infty$.

### Constraints
- None

### Time Complexity
- $O(1)$

## nan
```cpp
tools::safe_int<T> tools::safe_int<T>::nan();
```

It returns $\mathrm{NaN}$.

### Constraints
- None

### Time Complexity
- $O(1)$

## Constructor
```cpp
(1) tools::safe_int<T> x();
(2) tools::safe_int<T> x(T n);
```

- (1)
    - It creates $0$.
- (2)
    - It creates the finite integer value which represents $n$.

### Constraints
- `<T>` is a built-in integral type.

### Time Complexity
- $O(1)$

## is_finite
```cpp
bool x.is_finite();
```

It returns `true` if $x \in \mathbb{Z}$.
Otherwise, it returns `false`.

### Constraints
- None

### Time Complexity
- $O(1)$

## is_nan
```cpp
bool x.is_nan();
```

It returns `true` if $x = \mathrm{NaN}$.
Otherwise, it returns `false`.

### Constraints
- None

### Time Complexity
- $O(1)$

## val
```cpp
T x.val();
```

It returns $x$ as `<T>`.

### Constraints
- $x \in \mathbb{Z}$

### Time Complexity
- $O(1)$

## +x
```cpp
tools::safe_int<T> +x;
```

It returns $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## -x
```cpp
tools::safe_int<T> -x;
```

If `<T>` is a signed integral type, it returns 

$$\begin{align*}
\left\{\begin{array}{ll}
-x & \text{(if $x \in \mathbb{Z}$ and $-x$ does not cause an overflow)}\\
\mathrm{NaN} & \text{(if $x \in \mathbb{Z}$ and $-x$ causes an overflow)}\\
-\infty & \text{(if $x = \infty$)}\\
\infty & \text{(if $x = -\infty$)}\\
\mathrm{NaN} & \text{(if $x = \mathrm{NaN}$)}
\end{array}\right.&
\end{align*}$$

If `<T>` is an unsigned integral type, it returns 

$$\begin{align*}
\left\{\begin{array}{ll}
0 & \text{(if $x = 0$)}\\
\mathrm{NaN} & \text{(if $x > 0$)}\\
\mathrm{NaN} & \text{(if $x = \infty$)}\\
\mathrm{NaN} & \text{(if $x = \mathrm{NaN}$)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(1)$

## x + y
```cpp
tools::safe_int<T> x + y;
```

If `<T>` is a signed integral type, the return value is as follows.

|$x \backslash y$|$-\infty$|$\mathbb{Z}$|$\infty$|$\mathrm{NaN}$|
|$-\infty$|$-\infty$|$-\infty$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathbb{Z}$|$-\infty$|(see below)|$\infty$|$\mathrm{NaN}$|
|$\infty$|$\mathrm{NaN}$|$\infty$|$\infty$|$\mathrm{NaN}$|
|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|

If `<T>` is an unsigned integral type, the return value is as follows.

|$x \backslash y$|$\mathbb{Z}_{\geq 0}$|$\infty$|$\mathrm{NaN}$|
|$\mathbb{Z}_{\geq 0}$|(see below)|$\infty$|$\mathrm{NaN}$|
|$\infty$|$\infty$|$\infty$|$\mathrm{NaN}$|
|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|

If $x \in \mathbb{Z}$ and $y \in \mathbb{Z}$, it returns 

$$\begin{align*}
\left\{\begin{array}{ll}
x + y & \text{(if $x + y$ does not cause an overflow)}\\
\mathrm{NaN} & \text{(if $x + y$ causes an overflow)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(1)$

## x - y
```cpp
tools::safe_int<T> x - y;
```

If `<T>` is a signed integral type, the return value is as follows.

|$x \backslash y$|$-\infty$|$\mathbb{Z}$|$\infty$|$\mathrm{NaN}$|
|$-\infty$|$\mathrm{NaN}$|$-\infty$|$-\infty$|$\mathrm{NaN}$|
|$\mathbb{Z}$|$\infty$|(see below)|$-\infty$|$\mathrm{NaN}$|
|$\infty$|$\infty$|$\infty$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|

If `<T>` is an unsigned integral type, the return value is as follows.

|$x \backslash y$|$\mathbb{Z}_{\geq 0}$|$\infty$|$\mathrm{NaN}$|
|$\mathbb{Z}_{\geq 0}$|(see below)|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\infty$|$\infty$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|

If $x \in \mathbb{Z}$ and $y \in \mathbb{Z}$, it returns 

$$\begin{align*}
\left\{\begin{array}{ll}
x - y & \text{(if $x - y$ does not cause an overflow)}\\
\mathrm{NaN} & \text{(if $x - y$ causes an overflow)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(1)$

## x * y
```cpp
tools::safe_int<T> x * y;
```

If `<T>` is a signed integral type, the return value is as follows.

|$x \backslash y$|$-\infty$|$\mathbb{Z}_{<0}$|$0$|$\mathbb{Z}_{>0}$|$\infty$|$\mathrm{NaN}$|
|$-\infty$|$\infty$|$\infty$|$\mathrm{NaN}$|$-\infty$|$-\infty$|$\mathrm{NaN}$|
|$\mathbb{Z}_{<0}$|$\infty$|(see below)|$0$|(see below)|$-\infty$|$\mathrm{NaN}$|
|$0$|$\mathrm{NaN}$|$0$|$0$|$0$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathbb{Z}_{>0}$|$-\infty$|(see below)|$0$|(see below)|$\infty$|$\mathrm{NaN}$|
|$\infty$|$-\infty$|$-\infty$|$\mathrm{NaN}$|$\infty$|$\infty$|$\mathrm{NaN}$|
|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|

If `<T>` is an unsigned integral type, the return value is as follows.

|$x \backslash y$|$0$|$\mathbb{Z}_{>0}$|$\infty$|$\mathrm{NaN}$|
|$0$|$0$|$0$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathbb{Z}_{>0}$|$0$|(see below)|$\infty$|$\mathrm{NaN}$|
|$\infty$|$\mathrm{NaN}$|$\infty$|$\infty$|$\mathrm{NaN}$|
|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|

If $x \in \mathbb{Z}$ and $y \in \mathbb{Z}$, it returns 

$$\begin{align*}
\left\{\begin{array}{ll}
xy & \text{(if $xy$ does not cause an overflow)}\\
\mathrm{NaN} & \text{(if $xy$ causes an overflow)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(1)$

## x / y
```cpp
tools::safe_int<T> x / y;
```

If `<T>` is a signed integral type, the return value is as follows.

|$x \backslash y$|$-\infty$|$\mathbb{Z}_{<0}$|$0$|$\mathbb{Z}_{>0}$|$\infty$|$\mathrm{NaN}$|
|$-\infty$|$\mathrm{NaN}$|$\infty$|$\mathrm{NaN}$|$-\infty$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathbb{Z}_{<0}$|$0$|(see below)|$\mathrm{NaN}$|(see below)|$0$|$\mathrm{NaN}$|
|$0$|$0$|$0$|$\mathrm{NaN}$|$0$|$0$|$\mathrm{NaN}$|
|$\mathbb{Z}_{>0}$|$0$|(see below)|$\mathrm{NaN}$|(see below)|$0$|$\mathrm{NaN}$|
|$\infty$|$\mathrm{NaN}$|$-\infty$|$\mathrm{NaN}$|$\infty$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|

If `<T>` is an unsigned integral type, the return value is as follows.

|$x \backslash y$|$0$|$\mathbb{Z}_{>0}$|$\infty$|$\mathrm{NaN}$|
|$0$|$\mathrm{NaN}$|$0$|$0$|$\mathrm{NaN}$|
|$\mathbb{Z}_{>0}$|$\mathrm{NaN}$|(see below)|$0$|$\mathrm{NaN}$|
|$\infty$|$\mathrm{NaN}$|$\infty$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|

If $x \in \mathbb{Z}$ and $y \in \mathbb{Z} \setminus \\{0\\}$, the return value is as follows.

- If $x = $ `std::numeric_limits<T>::min()` and $y = -1$, it returns $\mathrm{NaN}$.
- Otherwise, it returns the rounded $\frac{x}{y}$ towards zero.

### Constraints
- None

### Time Complexity
- $O(1)$

## x % y
```cpp
tools::safe_int<T> x % y;
```

If `<T>` is a signed integral type, the return value is as follows.

|$x \backslash y$|$-\infty$|$\mathbb{Z}_{<0}$|$0$|$\mathbb{Z}_{>0}$|$\infty$|$\mathrm{NaN}$|
|$-\infty$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathbb{Z}_{<0}$|$\mathrm{NaN}$|(see below)|$\mathrm{NaN}$|(see below)|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$0$|$\mathrm{NaN}$|$0$|$\mathrm{NaN}$|$0$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathbb{Z}_{>0}$|$\mathrm{NaN}$|(see below)|$\mathrm{NaN}$|(see below)|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\infty$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|

If `<T>` is an unsigned integral type, the return value is as follows.

|$x \backslash y$|$0$|$\mathbb{Z}_{>0}$|$\infty$|$\mathrm{NaN}$|
|$0$|$\mathrm{NaN}$|$0$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathbb{Z}_{>0}$|$\mathrm{NaN}$|(see below)|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\infty$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|

If $x \in \mathbb{Z}$ and $y \in \mathbb{Z} \setminus \\{0\\}$, the return value is as follows.

- If $x = $ `std::numeric_limits<T>::min()` and $y = -1$, it returns $\mathrm{NaN}$.
- Otherwise, it returns $x - qy$ where $q$ is the rounded $\frac{x}{y}$ towards zero.

### Constraints
- None

### Time Complexity
- $O(1)$

## x += y
```cpp
tools::safe_int<T>& x += y;
```

It runs `x = x + y;` and returns $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## x -= y
```cpp
tools::safe_int<T>& x -= y;
```

It runs `x = x - y;` and returns $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## x *= y
```cpp
tools::safe_int<T>& x *= y;
```

It runs `x = x * y;` and returns $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## x /= y
```cpp
tools::safe_int<T>& x /= y;
```

It runs `x = x / y;` and returns $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## x %= y
```cpp
tools::safe_int<T>& x %= y;
```

It runs `x = x % y;` and returns $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## ++x
```cpp
tools::safe_int<T>& ++x;
```

It runs `x = x + 1;` and returns $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## x++
```cpp
tools::safe_int<T> x++;
```

It runs `x = x + 1;` and returns the previous $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## &#45;&#45;x
```cpp
tools::safe_int<T>& --x;
```

It runs `x = x - 1;` and returns $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## x&#45;&#45;
```cpp
tools::safe_int<T> x--;
```

It runs `x = x - 1;` and returns the previous $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## x == y
```cpp
bool x == y;
```

The return value is as follows.

|$x \backslash y$|$-\infty$|$\mathbb{Z}$|$\infty$|$\mathrm{NaN}$|
|$-\infty$|true|false|false|false|
|$\mathbb{Z}$|false|$x == y$|false|false|
|$\infty$|false|false|true|false|
|$\mathrm{NaN}$|false|false|false|false|

### Constraints
- None

### Time Complexity
- $O(1)$

## x != y
```cpp
bool x != y;
```

It returns `!(x == y)`.

### Constraints
- None

### Time Complexity
- $O(1)$

## x < y
```cpp
bool x < y;
```

The return value is as follows.

|$x \backslash y$|$-\infty$|$\mathbb{Z}$|$\infty$|$\mathrm{NaN}$|
|$-\infty$|false|true|true|false|
|$\mathbb{Z}$|false|$x < y$|true|false|
|$\infty$|false|false|false|false|
|$\mathrm{NaN}$|false|false|false|false|

### Constraints
- None

### Time Complexity
- $O(1)$

## x > y
```cpp
bool x > y;
```

The return value is as follows.

|$x \backslash y$|$-\infty$|$\mathbb{Z}$|$\infty$|$\mathrm{NaN}$|
|$-\infty$|false|false|false|false|
|$\mathbb{Z}$|true|$x > y$|false|false|
|$\infty$|true|true|false|false|
|$\mathrm{NaN}$|false|false|false|false|

### Constraints
- None

### Time Complexity
- $O(1)$

## x <= y
```cpp
bool x <= y;
```

It returns `(x < y) || (x == y)`.

### Constraints
- None

### Time Complexity
- $O(1)$

## x >= y
```cpp
bool x >= y;
```

It returns `(x > y) || (x == y)`.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator&gt;&gt;
```cpp
std::istream& operator>>(std::istream& is, safe_int<T>& x);
```

It reads a finite integer from standard input and updates $x$ to it.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator&lt;&lt;
```cpp
std::ostream& operator<<(std::ostream& os, safe_int<T> x);
```

It prints the following value to `os`.

|$x$|output value|
|$-\infty$|`-inf`|
|$\mathbb{Z}$|$x$|
|$\infty$|`inf`|
|$\mathrm{NaN}$|`nan`|

### Constraints
- None

### Time Complexity
- $O(1)$
