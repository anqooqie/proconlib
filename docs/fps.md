---
title: Formal power series
documentation_of: //tools/fps.hpp
---

最初の$n$項にのみ注目した多項式環$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$です。
多くの場合で形式的冪級数$(\mathbb{Z}/M\mathbb{Z})[[x]]$の最初の$n$項の係数のみが判明しているものと同一視できます。

このクラスは`std::vector<M>`と同様のインタフェースを備えており、$i$番目の要素が$i$次の係数を表しているものとして設計されています。

### Note
このページでは、$\gcd(0, x) = x$、$\gcd(x, 0) = x$、$\gcd(0, 0) = 0$と定義します。

このページでは、$x$の最小素因数を$\mathrm{lpf}(x)$と表記します。
$\mathrm{lpf}(1)$は$\infty$であるとします。

このページでは、$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$f$の$i$次の係数を$f_i$と表記します。

このページでは、$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$f$を$(\mathbb{Z}/M\mathbb{Z})[x]/(x^m)$の元として解釈したものを$f^{(m)}$と表記します。
$f^{(m)}$の定義は以下です。

$$\begin{align*}
\text{For any $i$ such that $0 \leq i < m$, } f^{(m)}_i &= \left\{\begin{array}{ll}
f_i & \text{(if $i < n$)}\\
0 & \text{(if $i \geq n$)}
\end{array}\right.
\end{align*}$$

### References
- [形式的冪級数（FPS）ライブラリの実装例（C++） \| opt の競プロブログ](https://opt-cp.com/fps-implementation/)

### License
- CC0

### Author
- opt

## Constructor
```cpp
(1) fps<M> f();
(2) fps<M> f(std::size_t n);
(3) fps<M> f(std::size_t n, M c);
(4) template <class InputIterator> fps<M> f(InputIterator begin, InputIterator end);
(5) fps<M> f(std::initializer_list<M> il);
```

`std::vector<M>`のコンストラクタと同様です。

- (1)
    - 自明な環$\\{0\\}$の元$0$を作ります。
- (2)
    - $(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$0$を作ります。
- (3)
    - $(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$\sum_{i = 0}^{n - 1} c x^i$を作ります。
- (4)
    - $n$を`end` $-$ `begin`として、$i$次の係数が`begin[i]`である$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元を作ります。
- (5)
    - $n$を`il.size()`として、$i$次の係数が`il.begin()[i]`である$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元を作ります。

### Constraints
- (1), (2), (3), (5)
    - `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- (4)
    - `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
    - `begin` $\leq$ `end`

### Time Complexity
- (1)
    - $O(1)$
- (2), (3), (4), (5)
    - $O(n)$

## `std::vector<M>`と同様のメンバ関数
その他、`std::vector<M>`と同様のメンバ関数を持ちます。

### Constraints
- Same as ones of `std::vector<M>`.

### Time Complexity
- Same as ones of `std::vector<M>`.

## Unary plus operator
```cpp
fps<M> f.operator+();
```

$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$f$を返します。

### Constraints
- None

### Time Complexity
- $O(n)$

## Unary minus operator
```cpp
fps<M> f.operator-();
```

$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$-f$を返します。
$-f$とは以下の条件を満たす$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$g$のことです。

$$\begin{align*}
\text{For any $i$ such that $0 \leq i < n$, } g_i &= -f_i
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(n)$

## Increment operators
```cpp
(1) fps<M>& f.operator++();
(2) fps<M> f.operator++(int);
```

- (1)
    - $n > 0$のとき$f_0$を$1$加算し、加算後の$f$を返します。
- (2)
    - $n > 0$のとき$f_0$を$1$加算し、加算前の$f$を返します。

### Constraints
- None

### Time Complexity
- (1)
    - $O(1)$
- (2)
    - $O(n)$

## Decrement operators
```cpp
(1) fps<M>& f.operator--();
(2) fps<M> f.operator--(int);
```

- (1)
    - $n > 0$のとき$f_0$を$1$減算し、減算後の$f$を返します。
- (2)
    - $n > 0$のとき$f_0$を$1$減算し、減算前の$f$を返します。

### Constraints
- None

### Time Complexity
- (1)
    - $O(1)$
- (2)
    - $O(n)$

## Addition operators
```cpp
(1) fps<M> operator+(fps<M> f, fps<M> g);
(2) fps<M>& f.operator+=(fps<M> g);
```

$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$f + g^{(n)}$を返します。
$f + g^{(n)}$とは、以下の条件を満たす$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$h$のことです。

$$\begin{align*}
\text{For any $i$ such that $0 \leq i < n$, } h_i &= f_i + g^{(n)}_i
\end{align*}$$

### Constraints
- None

### Time Complexity
- (1)
    - $O(n + m)$
- (2)
    - $O(\min(n, m))$

## Subtraction operators
```cpp
(1) fps<M> operator-(fps<M> f, fps<M> g);
(2) fps<M>& f.operator-=(fps<M> g);
```

$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$f - g^{(n)}$を返します。
$f - g^{(n)}$とは、以下の条件を満たす$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$h$のことです。

$$\begin{align*}
\text{For any $i$ such that $0 \leq i < n$, } h_i &= f_i - g^{(n)}_i
\end{align*}$$

### Constraints
- None

### Time Complexity
- (1)
    - $O(n + m)$
- (2)
    - $O(\min(n, m))$

## Scalar multiplication operators
```cpp
(1) fps<M> operator*(fps<M> f, M c);
(2) fps<M> operator*(M c, fps<M> f);
(3) fps<M>& f.operator*=(M c);
```

$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$cf$を返します。
$cf$とは、以下の条件を満たす$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$g$のことです。

$$\begin{align*}
\text{For any $i$ such that $0 \leq i < n$, } g_i &= c f_i
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(n)$

## Scalar division operators
```cpp
(1) fps<M> operator/(fps<M> f, M c);
(2) fps<M>& f.operator/=(M c);
```

$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$c^{-1} f$を返します。
$c^{-1} f$とは、以下の条件を満たす$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$g$のことです。

$$\begin{align*}
\text{For any $i$ such that $0 \leq i < n$, } g_i &= c^{-1} f_i
\end{align*}$$

### Constraints
- $\gcd(c, M) = 1$

### Time Complexity
- $O(n + \log M)$

## Left shift operators
```cpp
(1) fps<M> operator<<(fps<M> f, int d);
(2) fps<M>& f.operator<<=(int d);
```

以下の条件を満たす$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$g$を返します。

$$\begin{align*}
\text{For any $i$ such that $0 \leq i < n$, } g_i &= \left\{\begin{array}{ll}
f_{i - d} & \text{(if $0 \leq i - d < n$)}\\
0 & \text{(otherwise)}
\end{array}\right.
\end{align*}$$

$d \geq 0$ならば、$f x^d$と同じです。

### Constraints
- None

### Time Complexity
- $O(n)$

## Right shift operators
```cpp
(1) fps<M> operator>>(fps<M> f, int d);
(2) fps<M>& f.operator>>=(int d);
```

以下の条件を満たす$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$g$を返します。

$$\begin{align*}
\text{For any $i$ such that $0 \leq i < n$, } g_i &= \left\{\begin{array}{ll}
f_{i + d} & \text{(if $0 \leq i + d < n$)}\\
0 & \text{(otherwise)}
\end{array}\right.
\end{align*}$$

$\forall i. 0 \leq i < d \Rightarrow f_i = 0$ならば、$\frac{f}{x^d}$と同じです。

### Constraints
- None

### Time Complexity
- $O(n)$

## inv
```cpp
(1) fps<M> f.inv(int d);
(2) fps<M> f.inv();
```

- (1)
    - $(\mathbb{Z}/M\mathbb{Z})[x]/(x^d)$の元${f^{(d)}}^{-1}$を返します。${f^{(d)}}^{-1}$とは、$f^{(d)} h = 1$を満たす$(\mathbb{Z}/M\mathbb{Z})[x]/(x^d)$の元$h$のことです。
- (2)
    - `f.inv(f.size())`と同じです。

### Constraints
- (1)
    - $d \geq 0$
    - $d > 0 \Rightarrow \gcd(f^{(d)}_0, M) = 1$
- (2)
    - $n > 0 \Rightarrow \gcd(f_0, M) = 1$

### Time Complexity
- (1)
    - $O(d \log d + \log M)$
- (2)
    - $O(n \log n + \log M)$

## Multiplication by FPS
```cpp
(1) fps<M> f.multiply(fps<M> g, int d);
(2) fps<M> f.multiply(fps<M> g);
(3) fps<M> operator*(fps<M> f, fps<M> g);
(4) fps<M>& multiply_inplace(fps<M> g, int d);
(5) fps<M>& multiply_inplace(fps<M> g);
(6) fps<M>& f.operator*=(fps<M> g);
```

- (1), (4)
    - $(\mathbb{Z}/M\mathbb{Z})[x]/(x^d)$の元$f^{(d)} g^{(d)}$を返します。$f^{(d)} g^{(d)}$とは、以下の条件を満たす$(\mathbb{Z}/M\mathbb{Z})[x]/(x^d)$の元$h$のことです。

$$\begin{align*}
\text{For any $i$ such that $0 \leq i < d$, } h_i &= \sum_{j = 0}^i f^{(d)}_j g^{(d)}_{i - j}
\end{align*}$$

- (2), (3)
    - `f.multiply(g, f.size())`と同じです。
- (5), (6)
    - `f.multiply_inplace(g, f.size())`と同じです。

### Constraints
- (1), (4)
    - $d \geq 0$

### Time Complexity
- (1), (4)
    - $O((\min(n, d) + \min(m, d)) \log(\min(n, d) + \min(m, d)) + d)$ where $m$ is `g.size()`
- (2), (3), (5), (6)
    - $O((n + m) \log(n + m))$ where $m$ is `g.size()`

## Division by FPS
```cpp
(1) fps<M> f.divide(fps<M> g, int d);
(2) fps<M> f.divide(fps<M> g);
(3) fps<M> operator/(fps<M> f, fps<M> g);
(4) fps<M>& divide_inplace(fps<M> g, int d);
(5) fps<M>& divide_inplace(fps<M> g);
(6) fps<M>& f.operator/=(fps<M> g);
```

- (1), (4)
    - $(\mathbb{Z}/M\mathbb{Z})[x]/(x^d)$の元$f^{(d)} {g^{(d)}}^{-1}$を返します。
- (2), (3)
    - `f.divide(g, f.size())`と同じです。
- (5), (6)
    - `f.divide_inplace(g, f.size())`と同じです。

### Constraints
- (1), (4)
    - $d \geq 0$
    - $d > 0 \Rightarrow \gcd(g^{(d)}_0, M) = 1$
- (2), (3), (5), (6)
    - $n > 0 \Rightarrow \gcd(g^{(n)}_0, M) = 1$

### Time Complexity
- (1)
    - $O(n + d \log d + \log M)$
- (2), (3), (5), (6)
    - $O(n \log n + \log M)$
- (4)
    - $O(d \log d + \log M)$

## Multiplication by sparse FPS
```cpp
(1) template <typename InputIterator> fps<M> f.multiply(InputIterator g_begin, InputIterator g_end);
(2) fps<M> f.multiply(std::initializer_list<std::pair<int, M>> g);
(3) template <typename InputIterator> fps<M>& f.multiply_inplace(InputIterator g_begin, InputIterator g_end);
(4) fps<M>& f.multiply_inplace(std::initializer_list<std::pair<int, M>> g);
```

疎な係数列の形で$g$を受け取ります。
$g$は第一要素が次数、第二要素が係数を表すペアのリストの形で表されます。
$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$f g^{(n)}$を返します。

### Constraints
- (1), (3)
    - `g_begin` $\leq$ `g_end`
    - `*g_begin` is convertible to `std::pair<int, M>`.
    - `std::all_of(g_begin, g_end, [](std::pair<int, M> g_i) { return g_i.first >= 0; })`
    - `std::is_sorted(g_begin, g_end, [](std::pair<int, M> g_i, std::pair<int, M> g_j) { return g_i.first < g_j.first; })`
    - `std::unique(g_begin, g_end, [](std::pair<int, M> g_i, std::pair<int, M> g_j) { return g_i.first < g_j.first; }) == g_end`
- (2), (4)
    - `std::all_of(g.begin(), g.end(), [](std::pair<int, M> g_i) { return g_i.first >= 0; })`
    - `std::is_sorted(g.begin(), g.end(), [](std::pair<int, M> g_i, std::pair<int, M> g_j) { return g_i.first < g_j.first; })`
    - `std::unique(g.begin(), g.end(), [](std::pair<int, M> g_i, std::pair<int, M> g_j) { return g_i.first < g_j.first; }) == g_end`

### Time Complexity
- $O(nk)$ where $k$ is `g.size()`

## Division by sparse FPS
```cpp
(1) template <typename InputIterator> fps<M> f.divide(InputIterator g_begin, InputIterator g_end);
(2) fps<M> f.divide(std::initializer_list<std::pair<int, M>> g);
(3) template <typename InputIterator> fps<M>& f.divide(InputIterator g_begin, InputIterator g_end);
(4) fps<M>& f.divide_inplace(std::initializer_list<std::pair<int, M>> g);
```

疎な係数列の形で$g$を受け取ります。
$g$は第一要素が次数、第二要素が係数を表すペアのリストの形で表されます。
$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$f {g^{(n)}}^{-1}$を返します。

### Constraints
- (1), (3)
    - `g_begin` $\leq$ `g_end`
    - `*g_begin` is convertible to `std::pair<int, M>`.
    - `std::all_of(g_begin, g_end, [](std::pair<int, M> g_i) { return g_i.first >= 0; })`
    - `std::is_sorted(g_begin, g_end, [](std::pair<int, M> g_i, std::pair<int, M> g_j) { return g_i.first < g_j.first; })`
    - `std::unique(g_begin, g_end, [](std::pair<int, M> g_i, std::pair<int, M> g_j) { return g_i.first < g_j.first; }) == g_end`
    - $n > 0 \Rightarrow \gcd(g^{(n)}_0, M) = 1$
- (2), (4)
    - `std::all_of(g_begin, g_end, [](std::pair<int, M> g_i) { return g_i.first >= 0; })`
    - `std::is_sorted(g_begin, g_end, [](std::pair<int, M> g_i, std::pair<int, M> g_j) { return g_i.first < g_j.first; })`
    - `std::unique(g_begin, g_end, [](std::pair<int, M> g_i, std::pair<int, M> g_j) { return g_i.first < g_j.first; }) == g_end`
    - $n > 0 \Rightarrow \gcd(g^{(n)}_0, M) = 1$

### Time Complexity
- $O(nk + \log M)$ where $k$ is `g.size()`

## Multiplication by $1 + c x^d$
```cpp
(1) fps<M> f.multiply(int d, M c);
(2) fps<M>& f.multiply_inplace(int d, M c);
```

$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$f \cdot (1 + c x^d)$を返します。

### Constraints
- $d > 0$

### Time Complexity
- (1)
    - $O(n)$
- (2)
    - $O(\max(0, n - d))$

## Division by $1 + c x^d$
```cpp
(1) fps<M> f.divide(int d, M c);
(2) fps<M>& f.divide_inplace(int d, M c);
```

$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$\frac{f}{1 + c x^d}$を返します。

### Constraints
- $d > 0$

### Time Complexity
- (1)
    - $O(n)$
- (2)
    - $O(\max(0, n - d))$

## integral
```cpp
(1) fps<M> f.integral();
(2) fps<M>& f.integral_inplace();
```

$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$\int f \mathrm{d}x$を返します。
$\int f \mathrm{d}x$とは、以下の条件を満たす$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$g$のことです。

$$\begin{align*}
g_0 &= 0\\
\text{For any $i$ such that $1 \leq i < n$, } g_i &= \frac{f_{i - 1}}{i}
\end{align*}$$

### Constraints
- $n \leq \mathrm{lpf}(M)$

### Time Complexity
- $O(n)$

## derivative
```cpp
(1) fps<M> f.derivative();
(2) fps<M>& f.derivative_inplace();
```

$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$f'$を返します。
$f'$とは、以下の条件を満たす$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$g$のことです。

$$\begin{align*}
\text{For any $i$ such that $0 \leq i < n - 1$, } g_i &= (i + 1) f_{i + 1}\\
g_{n - 1} &= 0
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(n)$

## log
```cpp
(1) fps<M> f.log(int d);
(2) fps<M> f.log();
(3) fps<M>& f.log_inplace(int d);
(4) fps<M>& f.log_inplace();
```

- (1), (3)
    - $(\mathbb{Z}/M\mathbb{Z})[x]/(x^d)$の元$\log\left(f^{(d)}\right)$を返します。$\log\left(f^{(d)}\right)$とは、$-\sum_{i = 1}^{d - 1} \frac{\left(1 - f^{(d)}\right)^i}{i}$のことです。
- (2)
    - `f.log(f.size())`と同じです。
- (4)
    - `f.log_inplace(f.size())`と同じです。

### Constraints
- (1), (3)
    - $0 \leq d \leq \mathrm{lpf}(M)$
    - $d > 0 \Rightarrow f_0^{(d)} = 1$
- (2), (4)
    - $n \leq \mathrm{lpf}(M)$
    - $n > 0 \Rightarrow f_0 = 1$

### Time Complexity
- (1)
    - $O(n + d \log d + \log M)$
- (2), (4)
    - $O(n \log n + \log M)$
- (3)
    - $O(d \log d + \log M)$

## exp
```cpp
(1) fps<M> f.exp(int d);
(2) fps<M> f.exp();
(3) fps<M>& f.exp_inplace(int d);
(4) fps<M>& f.exp_inplace();
```

- (1), (3)
    - $(\mathbb{Z}/M\mathbb{Z})[x]/(x^d)$の元$\exp\left(f^{(d)}\right)$を返します。$\exp\left(f^{(d)}\right)$とは、$\sum_{i = 0}^{d - 1} \frac{\left(f^{(d)}\right)^i}{i!}$のことです。
- (2)
    - `f.exp(f.size())`と同じです。
- (4)
    - `f.exp_inplace(f.size())`と同じです。

### Constraints
- (1), (3)
    - $0 \leq d \leq \mathrm{lpf}(M)$
    - $d > 0 \Rightarrow f_0^{(d)} = 0$
- (2), (4)
    - $n \leq \mathrm{lpf}(M)$
    - $n > 0 \Rightarrow f_0 = 0$

### Time Complexity
- (1)
    - $O(n + d \log d + \log M)$
- (2), (4)
    - $O(n \log n + \log M)$
- (3)
    - $O(d \log d + \log M)$

## pow
```cpp
(1) fps<M> f.pow(long long k, int d);
(2) fps<M> f.pow(long long k);
(3) fps<M>& f.pow_inplace(long long k, int d);
(4) fps<M>& f.pow_inplace(long long k);
```

- (1), (3)
    - $(\mathbb{Z}/M\mathbb{Z})[x]/(x^d)$の元$\left(f^{(d)}\right)^k$を返します。
- (2)
    - `f.pow(k, f.size())`と同じです。
- (4)
    - `f.pow_inplace(k, f.size())`と同じです。

### Constraints
- (1), (3)
    - $k \geq 0$
    - $d \geq 0$
- (2), (4)
    - $k \geq 0$

### Time Complexity
- (1), (3)
    - ($M$ is a prime and $d \leq M$): $O(n + d \log d + \log k + \log M)$
    - (otherwise): $O(n + d \log d \log k + \log M)$
- (2), (4)
    - ($M$ is a prime and $n \leq M$): $O(n \log n + \log k + \log M)$
    - (otherwise): $O(n \log n \log k + \log M)$

## operator()
```cpp
fps<M> f(fps<M> g);
```

$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$f(g^{(n)}(x))$を返します。

### Constraints
- $n > 0 \Rightarrow g_0^{(n)} = 0$

### Time Complexity
- $O(n^2 \log n)$

## compositional_inverse
```cpp
fps<M> f.compositional_inverse();
```

$f(g(x)) \equiv g(f(x)) \equiv x \pmod{x^n}$なる$(\mathbb{Z}/M\mathbb{Z})[x]/(x^n)$の元$g$を返します。

### Constraints
- $n \geq 2$
- $f_0 = 0$
- $\gcd(f_1, M) = 1$

### Time Complexity
- $O(n^2 \log n)$
