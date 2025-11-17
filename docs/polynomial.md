---
title: Polynomial
documentation_of: //tools/polynomial.hpp
---

可換環$R$を係数とする多項式環$R[x]$です。

$R$の台集合を$T$としたとき、このクラスは`std::vector<T>`と同様のインタフェースを備えており、$i$番目の要素が$i$次の係数を表しているものとして設計されています。

高次の係数$0$を明示的に持つかどうかによって、ある一つの多項式が複数の表現を持ちます。
たとえば、`polynomial<int>{3, 2}`、`polynomial<int>{3, 2, 0}`、`polynomial<int>{3, 2, 0, 0}`…はいずれも多項式$3 + 2x$を表します。

`std::vector<T>`に存在しない`polynomial<R>`固有のメンバ関数は、`polynomial<R>`を変更したり新規に生成したりする際、末尾の連続する$0$を取り除いて正規化します。

### Note
このページでは、$R[x]$の元$f$の$i$次の係数を$f_i$と表記します。

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) polynomial<T> f();
(2) polynomial<T> f(std::size_t n);
(3) polynomial<T> f(std::size_t n, T c);
(4) template <class InputIterator> polynomial<T> f(InputIterator begin, InputIterator end);
(5) polynomial<T> f(std::initializer_list<T> il);
(6) polynomial<R> f();
(7) polynomial<R> f(std::size_t n);
(8) polynomial<R> f(std::size_t n, typename R::add::T c);
(9) template <class InputIterator> polynomial<R> f(InputIterator begin, InputIterator end);
(10) polynomial<R> f(std::initializer_list<typename R::add::T> il);
```

`std::vector<T>`のコンストラクタとほぼ同様です。

- (1)$\sim$(5)
    - `<T>`を使って可換環$R = (T, +, \cdot)$を定義し、$R$を係数環とする多項式環$R[x]$を作ります。
    - 加法群$(T, +, 0)$は$($ `T` $, $ `+` $, $ `T(0)` $)$によって定義します。
    - 乗法単位的半群$(T, \cdot, 1)$は$($ `T` $, $ `*` $, $ `T(1)` $)$によって定義します。
    - `<T>`の型によっては、$R$は乗法逆元を持ちしたがって体でもあると自動で判定されます。
- (6)$\sim$(10)
    - `<R>`を使って可換環$R = (T, +, \cdot)$を定義し、$R$を係数環とする多項式環$R[x]$を作ります。
    - 加法群$(T, +, 0)$は$($ `typename R::AG::T` $, $ `R::AG::op` $, $ `R::AG::e()` $)$によって定義します。
    - 乗法単位的半群$(T, \cdot, 1)$は$($ `typename R::MM::T` $, $ `R::MM::op` $, $ `R::MM::e()` $)$によって定義します。
    - これはオプションですが、乗法単位的半群に逆元の定義を明示的に与えることで$R$を体とすることができます。その場合$x$の乗法逆元$x^{-1}$は`R::MM::inv(x)`で定義します。
- (1), (6)
    - $0$を作ります。係数は明示的に持ちません。
- (2), (7)
    - $0$を作ります。$n$次未満の係数を明示的に持ちます。
- (3), (8)
    - $\sum_{i = 0}^{n - 1} c x^i$を作ります。$n$次未満の係数を明示的に持ちます。
- (4), (9)
    - $n$を`end` $-$ `begin`として、$i$次の係数が`begin[i]`である多項式を作ります。$n$次未満の係数を明示的に持ちます。
- (5), (10)
    - $n$を`il.size()`として、$i$次の係数が`il.begin()[i]`である多項式を作ります。$n$次未満の係数を明示的に持ちます。

### Constraints
- (1)$\sim$(5)
    - `tools::commutative_ring<tools::rings::plus_multiplies<T>>` holds.
- (6)$\sim$(10)
    - `tools::commutative_ring<R>` holds.
- (4), (9)
    - `begin` $\leq$ `end`

### Time Complexity
- (1), (6)
    - $O(1)$
- (2)$\sim$(5), (7)$\sim$(10)
    - $O(n)$

## Comparison operators
```cpp
bool operator==(polynomial<R> f, polynomial<R> g);
bool operator!=(polynomial<R> f, polynomial<R> g);
```

$f$と$g$が多項式として等しいかどうかを返します。
たとえば`polynomial<int>{3, 2} == polynomial<int>{3, 2, 0}`は`true`です。

### Constraints
- None

### Time Complexity
- $O(n + m)$ where $n$ is `f.size()` and $m$ is `g.size()`

## `std::vector<T>`と同様のメンバ関数
その他、`std::vector<T>`と同様のメンバ関数を持ちます。

### Constraints
- Same as ones of `std::vector<T>`.

### Time Complexity
- Same as ones of `std::vector<T>`.

## pbegin
```cpp
polynomial<R>::coefficient_iterator f.pbegin();
```

$f_0$を指す読み取り専用ランダムアクセスイテレータ`coefficient_iterator`を返します。
`coefficient_iterator`が`const_iterator`と異なる点は、`vector`として明示的に保持していない範囲の高次の係数も指せることです。
`vector`の範囲外の位置を指す`coefficient_iterator`をデリファレンスすると$0$が返ります。

### Constraints
- None

### Time Complexity
- $O(1)$

## deg
```cpp
int f.deg();
```

$\mathrm{deg}(f)$を返します。
ただし$\mathrm{deg}(0) = -1$とします。

### Constraints
- None

### Time Complexity
- $O(n - \mathrm{deg}(f))$ where $n$ is `f.size()`

## regularize
```cpp
polynomial<R>& f.regularize()
```

`f`末尾の連続する$0$を取り除き、取り除いた後の`f`自身を返します。

### Constraints
- None

### Time Complexity
- $O(n - \mathrm{deg}(f))$ where $n$ is `f.size()`

## Unary plus operator
```cpp
polynomial<R> f.operator+();
```

$\mathrm{deg}(f)$次以下の係数を明示的に持つ多項式$f$を返します。

### Constraints
- None

### Time Complexity
- $O(n)$ where $n$ is `f.size()`

## Unary minus operator
```cpp
polynomial<R> f.operator-();
```

$\mathrm{deg}(f)$次以下の係数を明示的に持つ多項式$-f$を返します。

### Constraints
- None

### Time Complexity
- $O(n)$ where $n$ is `f.size()`

## Increment operators
```cpp
(1) polynomial<R>& f.operator++();
(2) polynomial<R> f.operator++(int);
```

- (1)
    - $f$の定数項を$1$加算し、$\mathrm{deg}(\text{加算後の}f)$次以下の係数を明示的に持つ加算後の$f$を返します。
- (2)
    - $f$の定数項を$1$加算し、$(\text{加算前の}$`f.size()`$)$次未満の係数を明示的に持つ加算前の$f$を返します。

### Constraints
- None

### Time Complexity
- (1)
    - $O(n - \mathrm{deg}(f))$ where $n$ is `f.size()`
- (2)
    - $O(n)$ where $n$ is `f.size()`

## Decrement operators
```cpp
(1) polynomial<R>& f.operator--();
(2) polynomial<R> f.operator--(int);
```

- (1)
    - $f$の定数項を$1$減算し、$\mathrm{deg}(\text{減算後の}f)$次以下の係数を明示的に持つ減算後の$f$を返します。
- (2)
    - $f$の定数項を$1$減算し、$(\text{減算前の}$`f.size()`$)$次未満の係数を明示的に持つ減算前の$f$を返します。

### Constraints
- None

### Time Complexity
- (1)
    - $O(n - \mathrm{deg}(f))$ where $n$ is `f.size()`
- (2)
    - $O(n)$ where $n$ is `f.size()`

## Addition operators
```cpp
(1) polynomial<R> operator+(polynomial<R> f, polynomial<R> g);
(2) polynomial<R>& f.operator+=(polynomial<R> g);
```

$\mathrm{deg}(f + g)$次以下の係数を明示的に持つ多項式$f + g$を返します。

### Constraints
- None

### Time Complexity
- $O(n + m)$ where $n$ is `f.size()` and $m$ is `g.size()`

## Subtraction operators
```cpp
(1) polynomial<R> operator-(polynomial<R> f, polynomial<R> g);
(2) polynomial<R>& f.operator-=(polynomial<R> g);
```

$\mathrm{deg}(f - g)$次以下の係数を明示的に持つ多項式$f - g$を返します。

### Constraints
- None

### Time Complexity
- $O(n + m)$ where $n$ is `f.size()` and $m$ is `g.size()`

## Scalar multiplication operators
```cpp
(1) polynomial<R> operator*(polynomial<R> f, T c);
(2) polynomial<R> operator*(T c, polynomial<R> f);
(3) polynomial<R>& f.operator*=(T c);
```

$\mathrm{deg}(cf)$次以下の係数を明示的に持つ多項式$cf$を返します。

### Constraints
- None

### Time Complexity
- $O(n)$ where $n$ is `f.size()`

## Scalar division operators
```cpp
(1) polynomial<R> operator/(polynomial<R> f, T c);
(2) polynomial<R>& f.operator/=(T c);
```

$\mathrm{deg}(c^{-1} f)$次以下の係数を明示的に持つ多項式$c^{-1} f$を返します。

### Constraints
- $R$ is a trivial ring or a field.
- If $R$ is not a trivial ring, $c \neq 0$

### Time Complexity
- $O(n)$ where $n$ is `f.size()`

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

### Constraints
- None

### Time Complexity
- $O(\max(n, n + d))$ where $n$ is `f.size()`

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

### Constraints
- None

### Time Complexity
- $O(\max(n, n - d))$ where $n$ is `f.size()`

## Multiplication by polynomial
```cpp
(1) polynomial<R> operator*(polynomial<R> f, polynomial<R> g);
(2) polynomial<R>& f.operator*=(polynomial<R> g);
```

$\mathrm{deg}(fg)$次以下の係数を明示的に持つ多項式$fg$を返します。

### Constraints
- None

### Time Complexity
- ($T$ is `atcoder::static_modint`, `atcoder::dynamic_modint`, `float`, `double`, `long double`, `std::complex<float>`, `std::complex<double>`, `std::complex<long double>` or an integral type): $O(n + m + (\mathrm{deg}(f) + \mathrm{deg}(g)) \log (\mathrm{deg}(f) + \mathrm{deg}(g)))$ where $n$ is `f.size()` and $m$ is `g.size()`
- (otherwise): $O(n + m + \mathrm{deg}(f)\mathrm{deg}(g))$ where $n$ is `f.size()` and $m$ is `g.size()`

## Division by polynomial
```cpp
(1) polynomial<R> operator/(polynomial<R> f, polynomial<R> g);
(2) polynomial<R>& f.operator/=(polynomial<R> g);
```

以下の条件を満たす多項式を$q$として、$\mathrm{deg}(q)$次以下の係数を明示的に持つ多項式$q$を返します。

$$\begin{align*}
\mathrm{deg}(q) &= \max(-1, n - m)\\
\exists r. f(x) &= g(x) q(x) + r(x)
\end{align*}$$

### Constraints
- At least one of the following conditions hold.
    - $R$ is a trivial ring.
    - $R$ is a field and $g \neq 0$.
    - $R$ is $\mathbb{Z}/M\mathbb{Z}$, $g \neq 0$ and $\gcd(g_{\mathrm{deg}(g)}, M) = 1$.

### Time Complexity
- ($R$ is $\mathbb{Z}/M\mathbb{Z}$): $O(n + m + (\mathrm{deg}(f) - \mathrm{deg}(g)) \log (\mathrm{deg}(f) - \mathrm{deg}(g)))$ where $n$ is `f.size()` and $m$ is `g.size()`
- (otherwise): $O(n + m + \mathrm{deg}(f)^2)$ where $n$ is `f.size()` and $m$ is `g.size()`

## Modulus operators
```cpp
(1) polynomial<R> operator%(polynomial<R> f, polynomial<R> g);
(2) polynomial<R>& f.operator%=(polynomial<R> g);
```

`f / g`で得られる多項式を$q$とし、また$r = f - gq$として、$\mathrm{deg}(r)$次以下の係数を明示的に持つ多項式$r$を返します。

### Constraints
- At least one of the following conditions hold.
    - $R$ is a trivial ring.
    - $R$ is a field and $g \neq 0$.
    - $R$ is $\mathbb{Z}/M\mathbb{Z}$, $g \neq 0$ and $\gcd(g_{\mathrm{deg}(g)}, M) = 1$.

### Time Complexity
- ($R$ is $\mathbb{Z}/M\mathbb{Z}$): $O(n + m + \mathrm{deg}(f) \log \mathrm{deg}(f))$ where $n$ is `f.size()` and $m$ is `g.size()`
- (otherwise): $O(n + m + \mathrm{deg}(f)^2)$ where $n$ is `f.size()` and $m$ is `g.size()`

## derivative
```cpp
(1) polynomial<R> f.derivative();
(2) polynomial<R>& f.derivative_inplace();
```

$\mathrm{deg}(f')$次以下の係数を明示的に持つ多項式$f'$を返します。

### Constraints
- None

### Time Complexity
- $O(n)$ where $n$ is `f.size()`

## operator()
```cpp
(1) T f(T a);
(2) polynomial<R> f(polynomial<R> g);
```

- (1)
    - $f(a)$を返します。
- (2)
    - $\mathrm{deg}(f(g(x)))$次以下の係数を明示的に持つ多項式$f(g(x))$を返します。

### Constraints
- None

### Time Complexity
- (1)
    - $O(n)$ where $n$ is `f.size()`
- (2)
    - ($R$ is $\mathbb{Z}/p\mathbb{Z}$, $n < p$ and $\mathrm{deg}(g) \leq 2$): $O(n + \mathrm{deg}(f) \log \mathrm{deg}(f))$ where $n$ is `f.size()`
    - (the above condition does not hold and $T$ is `atcoder::static_modint`, `atcoder::dynamic_modint`, `float`, `double`, `long double`, `std::complex<float>`, `std::complex<double>`, `std::complex<long double>` or an integral type): $O(n + m + \mathrm{deg}(f)^2 \mathrm{deg}(g) (\log \mathrm{deg}(f) + \log \mathrm{deg}(g)))$ where $n$ is `f.size()` and $m$ is `g.size()`
    - (otherwise): $O(n + m + \mathrm{deg}(f)^2 \mathrm{deg}(g)^2)$ where $n$ is `f.size()` and $m$ is `g.size()`

## multipoint_evaluation
```cpp
template <typename InputIterator>
std::vector<T> f.multipoint_evaluation(InputIterator begin, InputIterator end);
```

$p_0, p_1, \ldots$に対して$f(p_0), f(p_1), \ldots$を求めて返します。

### Constraints
- None

### Time Complexity
- ($R$ is $\mathbb{Z}/M\mathbb{Z}$): $O\left( n + \mathrm{deg}(f) \log\left(\mathrm{deg}(f)\right) + m (\log m)^2 \right)$ where $n$ = `f.size()` and $m$ = `end` $-$ `begin`
- (otherwise): $O\left( n + \mathrm{deg}(f) \cdot m \right)$ where $n$ = `f.size()` and $m$ = `end` $-$ `begin`
