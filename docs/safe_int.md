---
title: $\mathbb{Z} \cup \{\infty, -\infty, \mathrm{NaN}\}$
documentation_of: //tools/safe_int.hpp
---

It adds the three elements $\infty, -\infty, \mathrm{NaN}$ to a given signed integral type `<T>`.

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
- `<T>` is a signed integral type.

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

It returns 

$$\begin{align*}
\left\{\begin{array}{ll}
-x & \text{(if $x \in \mathbb{Z}$ and $-x$ does not cause an overflow)}\\
\mathrm{NaN} & \text{(if $x \in \mathbb{Z}$ and $-x$ causes an overflow)}\\
-\infty & \text{(if $x = \infty$)}\\
\infty & \text{(if $x = -\infty$)}\\
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

The return value is as follows.

|$x \backslash y$|$-\infty$|$\mathbb{Z}$|$\infty$|$\mathrm{NaN}$|
|$-\infty$|$-\infty$|$-\infty$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathbb{Z}$|$-\infty$|(see below)|$\infty$|$\mathrm{NaN}$|
|$\infty$|$\mathrm{NaN}$|$\infty$|$\infty$|$\mathrm{NaN}$|
|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|

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

The return value is as follows.

|$x \backslash y$|$-\infty$|$\mathbb{Z}$|$\infty$|$\mathrm{NaN}$|
|$-\infty$|$\mathrm{NaN}$|$-\infty$|$-\infty$|$\mathrm{NaN}$|
|$\mathbb{Z}$|$\infty$|(see below)|$-\infty$|$\mathrm{NaN}$|
|$\infty$|$\infty$|$\infty$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|

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

The return value is as follows.

|$x \backslash y$|$-\infty$|$\mathbb{Z}_{<0}$|$0$|$\mathbb{Z}_{>0}$|$\infty$|$\mathrm{NaN}$|
|$-\infty$|$\infty$|$\infty$|$\mathrm{NaN}$|$-\infty$|$-\infty$|$\mathrm{NaN}$|
|$\mathbb{Z}_{<0}$|$\infty$|(see below)|$0$|(see below)|$-\infty$|$\mathrm{NaN}$|
|$0$|$\mathrm{NaN}$|$0$|$0$|$0$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathbb{Z}_{>0}$|$-\infty$|(see below)|$0$|(see below)|$\infty$|$\mathrm{NaN}$|
|$\infty$|$-\infty$|$-\infty$|$\mathrm{NaN}$|$\infty$|$\infty$|$\mathrm{NaN}$|
|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|

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

The return value is as follows.

|$x \backslash y$|$-\infty$|$\mathbb{Z}_{<0}$|$0$|$\mathbb{Z}_{>0}$|$\infty$|$\mathrm{NaN}$|
|$-\infty$|$\mathrm{NaN}$|$\infty$|$\mathrm{NaN}$|$-\infty$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathbb{Z}_{<0}$|$0$|(see below)|$\mathrm{NaN}$|(see below)|$0$|$\mathrm{NaN}$|
|$0$|$0$|$0$|$\mathrm{NaN}$|$0$|$0$|$\mathrm{NaN}$|
|$\mathbb{Z}_{>0}$|$0$|(see below)|$\mathrm{NaN}$|(see below)|$0$|$\mathrm{NaN}$|
|$\infty$|$\mathrm{NaN}$|$-\infty$|$\mathrm{NaN}$|$\infty$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|

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

The return value is as follows.

|$x \backslash y$|$-\infty$|$\mathbb{Z}_{<0}$|$0$|$\mathbb{Z}_{>0}$|$\infty$|$\mathrm{NaN}$|
|$-\infty$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathbb{Z}_{<0}$|$\mathrm{NaN}$|(see below)|$\mathrm{NaN}$|(see below)|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$0$|$\mathrm{NaN}$|$0$|$\mathrm{NaN}$|$0$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathbb{Z}_{>0}$|$\mathrm{NaN}$|(see below)|$\mathrm{NaN}$|(see below)|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\infty$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|

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
