---
title: Polynomial
documentation_of: //tools/polynomial.hpp
---

可換環$R$を係数とする多項式環$R[x]$です。

このクラスは`std::vector<R>`と同様のインタフェースを備えており、$i$番目の要素が$i$次の係数を表しているものとして設計されています。

高次の係数$0$を明示的に持つかどうかによって、ある一つの多項式が複数の表現を持ちます。
たとえば、`polynomial<R>{3, 2}`、`polynomial<R>{3, 2, 0}`、`polynomial<R>{3, 2, 0, 0}`…はいずれも多項式$3 + 2x$を表します。

### Note
このページでは、$R[x]$の元$f$の$i$次の係数を$f_i$と表記します。

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) polynomial<R> f();
(2) polynomial<R> f(std::size_t n);
(3) polynomial<R> f(std::size_t n, R c);
(4) template <class InputIterator> polynomial<R> f(InputIterator begin, InputIterator end);
(5) polynomial<R> f(std::initializer_list<R> il);
(6) polynomial<AG, MM> f();
(7) polynomial<AG, MM> f(std::size_t n);
(8) polynomial<AG, MM> f(std::size_t n, R c);
(9) template <class InputIterator> polynomial<AG, MM> f(InputIterator begin, InputIterator end);
(10) polynomial<AG, MM> f(std::initializer_list<R> il);
```

`std::vector<R>`のコンストラクタとほぼ同様です。

- (1)
    - $0$を作ります。係数は明示的に持ちません。
- (2)
    - $0$を作ります。$n$次未満の係数を明示的に持ちます。
- (3)
    - $\sum_{i = 0}^{n - 1} c x^i$を作ります。$n$次未満の係数を明示的に持ちます。
- (4)
    - $n$を`end` $-$ `begin`として、$i$次の係数が`begin[i]`である多項式を作ります。$n$次未満の係数を明示的に持ちます。
- (5)
    - $n$を`il.size()`として、$i$次の係数が`il.begin()[i]`である多項式を作ります。$n$次未満の係数を明示的に持ちます。
- (6)$\sim$(10)
    - 可換環$(R, +, \cdot)$を`AG`と`MM`を使って定義する以外は、それぞれ(1)$\sim$(5)と同じです。
    - 加法群$(R, +, 0)$は$($ `typename AG::T` $, $ `AG::op` $, $ `AG::e()` $)$によって定義します。
    - 乗法単位的半群$(R, \cdot, 1)$は$($ `typename MM::T` $, $ `MM::op` $, $ `MM::e()` $)$によって定義します。
    - これはオプションですが、乗法単位的半群に逆元の定義を追加して$R$を体とすることができます。その場合$x$の乗法逆元$x^{-1}$は`MM::inv(x)`で定義します。

### Constraints
- (1)$\sim$(5)
    - For all $x$ in $R$, $y$ in $R$ and $z$ in $R$, $(x + y) + z = x + (y + z)$.
    - For all $x$ in $R$, $0 + x = x + 0 = x$.
    - For all $x$ in $R$, $(-x) + x = x + (-x) = 0$.
    - For all $x$ in $R$ and $y$ in $R$, $x + y = y + x$.
    - For all $x$ in $R$, $y$ in $R$ and $z$ in $R$, $(x \cdot y) \cdot z = x \cdot (y \cdot z)$.
    - For all $x$ in $R$, $1 \cdot x = x \cdot 1 = x$.
    - For all $x$ in $R$ and $y$ in $R$, $x \cdot y = y \cdot x$.
    - For all $x$ in $R$, $y$ in $R$ and $z$ in $R$, $x \cdot (y + z) = (x \cdot y) + (x \cdot z)$.
    - For all $x$ in $R$, $y$ in $R$ and $z$ in $R$, $(x + y) \cdot z = (x \cdot z) + (y \cdot z)$.
- (6)$\sim$(10)
    - For all $x$ in $R$, $y$ in $R$ and $z$ in $R$, `AG::op(AG::op(x, y), z)` $=$ `AG::op(x, AG::op(y, z))`.
    - For all $x$ in $R$, `AG::op(AG::e(), x)` $=$ `AG::op(x, AG::e())` $= x$.
    - For all $x$ in $R$, `AG::op(AG::inv(x), x)` $=$ `AG::op(x, AG::inv(x))` $=$ `AG::e()`.
    - For all $x$ in $R$ and $y$ in $R$, `AG::op(x, y)` $=$ `AG::op(y, x)`.
    - For all $x$ in $R$, $y$ in $R$ and $z$ in $R$, `MM::op(MM::op(x, y), z)` $=$ `MM::op(x, MM::op(y, z))`.
    - For all $x$ in $R$, `MM::op(MM::e(), x)` $=$ `MM::op(x, MM::e())` $= x$.
    - If `MM::inv` is defined, for all $x$ in $R$, `MM::op(MM::inv(x), x)` $=$ `MM::op(x, MM::inv(x))` $=$ `MM::e()`.
    - For all $x$ in $R$ and $y$ in $R$, `MM::op(x, y)` $=$ `MM::op(y, x)`.
    - For all $x$ in $R$, $y$ in $R$ and $z$ in $R$, `MM::op(x, AG::op(y, z))` $=$ `AG::op(MM::op(x, y), MM::op(x, z))`.
    - For all $x$ in $R$, $y$ in $R$ and $z$ in $R$, `MM::op(AG::op(x, y), z)` $=$ `AG::op(MM::op(x, z), MM::op(y, z))`.
- (4), (9)
    - `begin` $\leq$ `end`

### Time Complexity
- (1), (6)
    - $O(1)$
- (2), (3), (4), (5), (7), (8), (9), (10)
    - $O(n)$

## Comparison operators
```cpp
bool operator==(polynomial<R> f, polynomial<R> g);
bool operator!=(polynomial<R> f, polynomial<R> g);
```

$f$と$g$が多項式として等しいかどうかを返します。
たとえば`polynomial<R>{3, 2} == polynomial<R>{3, 2, 0}`は`true`です。

### Constraints
- None

### Time Complexity
- $O(n + m)$ where $n$ is `f.size()` and $m$ is `g.size()`

## `std::vector<R>`と同様のメンバ関数
その他、`std::vector<R>`と同様のメンバ関数を持ちます。

### Constraints
- Same as ones of `std::vector<R>`.

### Time Complexity
- Same as ones of `std::vector<R>`.

## deg
```cpp
int f.deg();
```

$\mathrm{deg}(f)$を返します。
ただし$\mathrm{deg}(0) = -1$とします。

### Constraints
- None

### Time Complexity
- $O(n)$ where $n$ is `f.size()`

## Unary plus operator
```cpp
polynomial<R> f.operator+();
```

$n$を`f.size()`として、$n$次未満の係数を明示的に持つ多項式$f$を返します。

### Constraints
- None

### Time Complexity
- $O(n)$

## Unary minus operator
```cpp
polynomial<R> f.operator-();
```

$n$を`f.size()`として、$n$次未満の係数を明示的に持つ多項式$-f$を返します。

### Constraints
- None

### Time Complexity
- $O(n)$

## Addition operators
```cpp
(1) polynomial<R> operator+(polynomial<R> f, polynomial<R> g);
(2) polynomial<R>& f.operator+=(polynomial<R> g);
```

$n$を`f.size()`、$m$を`g.size()`として、$\max(n, m)$次未満の係数を明示的に持つ多項式$f + g$を返します。

### Constraints
- None

### Time Complexity
- $O(n + m)$

## Subtraction operators
```cpp
(1) polynomial<R> operator-(polynomial<R> f, polynomial<R> g);
(2) polynomial<R>& f.operator-=(polynomial<R> g);
```

$n$を`f.size()`、$m$を`g.size()`として、$\max(n, m)$次未満の係数を明示的に持つ多項式$f - g$を返します。

### Constraints
- None

### Time Complexity
- $O(n + m)$

## Scalar multiplication operators
```cpp
(1) polynomial<R> operator*(polynomial<R> f, R c);
(2) polynomial<R> operator*(R c, polynomial<R> f);
(3) polynomial<R>& f.operator*=(R c);
```

$n$を`f.size()`として、$n$次未満の係数を明示的に持つ多項式$cf$を返します。

### Constraints
- None

### Time Complexity
- $O(n)$

## Scalar division operators
```cpp
(1) polynomial<R> operator/(polynomial<R> f, R c);
(2) polynomial<R>& f.operator/=(R c);
```

$n$を`f.size()`として、$n$次未満の係数を明示的に持つ多項式$c^{-1} f$を返します。

### Constraints
- $R$ is a trivial ring or a field.
- If $R$ is not a trivial ring, $c \neq 0$

### Time Complexity
- $O(n)$

## Left shift operators
```cpp
(1) polynomial<R> operator<<(polynomial<R> f, int d);
(2) polynomial<R>& f.operator<<=(int d);
```

$n$を`f.size()`として、$\max(0, n + d)$次未満の係数を明示的に持ち、かつ以下の条件を満たす多項式$g$を返します。

$$\begin{align*}
\text{For any $i$ such that $0 \leq i < \max(0, n + d)$, } g_i &= \left\{\begin{array}{ll}
f_{i - d} & \text{(if $0 \leq i - d < n$)}\\
0 & \text{(otherwise)}
\end{array}\right.
\end{align*}$$

$d \geq 0$ならば、$f x^d$と同じです。

### Constraints
- None

### Time Complexity
- $O(\max(n, n + d))$

## Right shift operators
```cpp
(1) polynomial<R> operator>>(polynomial<R> f, int d);
(2) polynomial<R>& f.operator>>=(int d);
```

$n$を`f.size()`として、$\max(0, n - d)$次未満の係数を明示的に持ち、かつ以下の条件を満たす多項式$g$を返します。

$$\begin{align*}
\text{For any $i$ such that $0 \leq i < \max(0, n - d)$, } g_i &= \left\{\begin{array}{ll}
f_{i + d} & \text{(if $0 \leq i + d < n$)}\\
0 & \text{(otherwise)}
\end{array}\right.
\end{align*}$$

$\forall i. 0 \leq i < d \Rightarrow f_i = 0$ならば、$\frac{f}{x^d}$と同じです。

### Constraints
- None

### Time Complexity
- $O(\max(n, n - d))$

## Multiplication by polynomial
```cpp
(1) polynomial<R> operator*(polynomial<R> f, polynomial<R> g);
(2) polynomial<R>& f.operator*=(polynomial<R> g);
```

$n$を`f.size()`、$m$を`g.size()`として、$\max(0, n + m - 1)$次未満の係数を明示的に持つ多項式$fg$を返します。

### Constraints
- None

### Time Complexity
- ($R$ is `atcoder::static_modint`): $O((n + m) \log (n + m))$
- ($R$ is `atcoder::dynamic_modint`): $O((n + m) \log (n + m))$
- ($R$ is `float`): $O((n + m) \log (n + m))$
- ($R$ is `double`): $O((n + m) \log (n + m))$
- ($R$ is `long double`): $O((n + m) \log (n + m))$
- ($R$ is `std::complex<float>`): $O((n + m) \log (n + m))$
- ($R$ is `std::complex<double>`): $O((n + m) \log (n + m))$
- ($R$ is `std::complex<lond double>`): $O((n + m) \log (n + m))$
- ($R$ is a built-in integer type): $O((n + m) \log (n + m))$
- (otherwise): $O(nm)$

## Division by polynomial
```cpp
(1) polynomial<R> operator/(polynomial<R> f, polynomial<R> g);
(2) polynomial<R>& f.operator/=(polynomial<R> g);
```

$n$を$\mathrm{deg}(f) + 1$、$m$を$\mathrm{deg}(g) + 1$として、$\max(0, n - m + 1)$次未満の係数を明示的に持ち以下の条件を満たす多項式$q$を返します。

$$\begin{align*}
\mathrm{deg}(q) &= \max(-1, n - m)\\
\exists r. f(x) &= g(x) q(x) + r(x)
\end{align*}$$

### Constraints
- $R$ is a trivial ring or a field.
- If $R$ is not a trivial ring, $g \neq 0$

### Time Complexity
- ($R$ is $\mathbb{Z}/p\mathbb{Z}$): $O(n + \max(1, n - m) \log(\max(1, n - m)))$
- (otherwise): $O(nm)$

## Modulus operators
```cpp
(1) polynomial<R> operator%(polynomial<R> f, polynomial<R> g);
(2) polynomial<R>& f.operator%=(polynomial<R> g);
```

$\mathrm{deg}(r) + 1$次未満の係数を明示的に持つ多項式$r = f - gq$を返します。
$q$は`f / g`で得られる多項式です。

### Constraints
- $R$ is a trivial ring or a field.
- If $R$ is not a trivial ring, $g \neq 0$

### Time Complexity
- ($R$ is $\mathbb{Z}/p\mathbb{Z}$): $O(n \log n)$
- (otherwise): $O(nm)$

## operator()
```cpp
(1) R f(R a);
(2) polynomial<R> f(polynomial<R> g);
```

- (1)
    - $f(a)$を返します。
- (2)
    - $f(g(x))$を返します。

### Constraints
- None

### Time Complexity
- (1)
    - $O(n)$
- (2)
    - ($R$ is $\mathbb{Z}/p\mathbb{Z}$, $n < p$ and $g(x) = x + g(0)$): $O(n \log n)$
    - (otherwise): $O(n^2 \log n)$
