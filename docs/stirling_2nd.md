---
title: Stirling numbers of the second kind
documentation_of: //tools/stirling_2nd.hpp
---

It calculates the Stirling numbers of the second kind $S(n, k) = \frac{1}{k!} \sum_{i = 0}^k (-1)^{k - i} {}_k \mathrm{C}_i i^n$.

### List of $S(n, k)$

|$n \backslash k$|$0$|$1$|       $2$|            $3$|             $4$|              $5$|              $6$|              $7$|              $8$|             $9$|            $10$|           $11$|       $12$|     $13$| $14$|$15$|
|             $0$|$1$|$0$|       $0$|            $0$|             $0$|              $0$|              $0$|              $0$|              $0$|             $0$|             $0$|            $0$|        $0$|      $0$|  $0$| $0$|
|             $1$|$0$|$1$|       $0$|            $0$|             $0$|              $0$|              $0$|              $0$|              $0$|             $0$|             $0$|            $0$|        $0$|      $0$|  $0$| $0$|
|             $2$|$0$|$1$|       $1$|            $0$|             $0$|              $0$|              $0$|              $0$|              $0$|             $0$|             $0$|            $0$|        $0$|      $0$|  $0$| $0$|
|             $3$|$0$|$1$|       $3$|            $1$|             $0$|              $0$|              $0$|              $0$|              $0$|             $0$|             $0$|            $0$|        $0$|      $0$|  $0$| $0$|
|             $4$|$0$|$1$|       $7$|            $6$|             $1$|              $0$|              $0$|              $0$|              $0$|             $0$|             $0$|            $0$|        $0$|      $0$|  $0$| $0$|
|             $5$|$0$|$1$|      $15$|           $25$|            $10$|              $1$|              $0$|              $0$|              $0$|             $0$|             $0$|            $0$|        $0$|      $0$|  $0$| $0$|
|             $6$|$0$|$1$|      $31$|           $90$|            $65$|             $15$|              $1$|              $0$|              $0$|             $0$|             $0$|            $0$|        $0$|      $0$|  $0$| $0$|
|             $7$|$0$|$1$|      $63$|          $301$|           $350$|            $140$|             $21$|              $1$|              $0$|             $0$|             $0$|            $0$|        $0$|      $0$|  $0$| $0$|
|             $8$|$0$|$1$|     $127$|          $966$|       $1{,}701$|        $1{,}050$|            $266$|             $28$|              $1$|             $0$|             $0$|            $0$|        $0$|      $0$|  $0$| $0$|
|             $9$|$0$|$1$|     $255$|      $3{,}025$|       $7{,}770$|        $6{,}951$|        $2{,}646$|            $462$|             $36$|             $1$|             $0$|            $0$|        $0$|      $0$|  $0$| $0$|
|            $10$|$0$|$1$|     $511$|      $9{,}330$|      $34{,}105$|       $42{,}525$|       $22{,}827$|        $5{,}880$|            $750$|            $45$|             $1$|            $0$|        $0$|      $0$|  $0$| $0$|
|            $11$|$0$|$1$| $1{,}023$|     $28{,}501$|     $145{,}750$|      $246{,}730$|      $179{,}487$|       $63{,}987$|       $11{,}880$|       $1{,}155$|            $55$|            $1$|        $0$|      $0$|  $0$| $0$|
|            $12$|$0$|$1$| $2{,}047$|     $86{,}526$|     $611{,}501$|  $1{,}379{,}400$|  $1{,}323{,}652$|      $627{,}396$|      $159{,}027$|      $22{,}275$|       $1{,}705$|           $66$|        $1$|      $0$|  $0$| $0$|
|            $13$|$0$|$1$| $4{,}095$|    $261{,}625$| $2{,}532{,}530$|  $7{,}508{,}501$|  $9{,}321{,}312$|  $5{,}715{,}424$|  $1{,}899{,}612$|     $359{,}502$|      $39{,}325$|      $2{,}431$|       $78$|      $1$|  $0$| $0$|
|            $14$|$0$|$1$| $8{,}191$|    $788{,}970$|$10{,}391{,}745$| $40{,}075{,}035$| $63{,}436{,}373$| $49{,}329{,}280$| $20{,}912{,}320$| $5{,}135{,}130$|     $752{,}752$|     $66{,}066$|  $3{,}367$|     $91$|  $1$| $0$|
|            $15$|$0$|$1$|$16{,}383$|$2{,}375{,}101$|$42{,}355{,}950$|$210{,}766{,}920$|$420{,}693{,}273$|$408{,}741{,}333$|$216{,}627{,}840$|$67{,}128{,}490$|$12{,}662{,}650$|$1{,}479{,}478$|$106{,}470$|$4{,}550$|$105$| $1$|

## stirling_2nd::fixed_n
```cpp
template <typename M>
tools::fps<M> stirling_2nd::fixed_n(int N, int K);
```

It returns $S(N, k) \pmod{P}$ for all $k$ such that $0 \leq k \leq K$, where $P$ is `M::mod()`.

### Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $P$ is a prime.
- $0 \leq \min(N, K) < P$

### Time Complexity
- $O(\min(N, K) \log(\min(N, K)) + K)$

### Algorithm
The following equation holds.

$$\begin{align*}
S(n, k) &= \frac{1}{k!} \sum_{i = 0}^k (-1)^{k - i} {}_k \mathrm{C}_i i^n\\
&= \frac{1}{k!} \sum_{i = 0}^k (-1)^{k - i} \frac{k!}{i! (k - i)!} i^n\\
&= \sum_{i = 0}^k (-1)^{k - i} \frac{1}{i! (k - i)!} i^n\\
&= \sum_{i = 0}^k \frac{i^n}{i!} \frac{(-1)^{k - i}}{(k - i)!}\\
a_i &:= \frac{i^n}{i!} & (0 \leq i \leq k)\\
b_i &:= \frac{(-1)^i}{i!} & (0 \leq i \leq k)\\
S(n, k) &= \sum_{i = 0}^k a_i b_{k - i}
\end{align*}$$

Therefore, $S(n, k)$ can be calculated by convolution.

### License
- CC0

### Author
- anqooqie

## stirling_2nd::fixed_k
```cpp
template <typename M>
tools::fps<M> stirling_2nd::fixed_k(int N, int K);
```

It returns $S(n, K) \pmod{P}$ for all $n$ such that $0 \leq n \leq N$, where $P$ is `M::mod()`.

### Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $P$ is a prime.
- $0 \leq K < P$
- $0 \leq N < P + K - 1$

### Time Complexity
- $O((N - K) \log (N - K) + N)$

### Algorithm
$S(n, k) = n! [x^n] \frac{(e^x - 1)^k}{k!}$ holds.
Therefore, $S(n, k)$ can be calculated by FPS.

### License
- CC0

### Author
- anqooqie

## stirling_2nd::diagonal
```cpp
template <typename M>
tools::fps<M> stirling_2nd::diagonal(int N);
```

It returns $S(n, n) \pmod{M}$ for all $n$ such that $0 \leq n \leq N$, where $M$ is `M::mod()`.
Note that $S(n, n) = 1$.

### Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $N \geq 0$

### Time Complexity
- $O(N)$

### License
- CC0

### Author
- anqooqie

## stirling_2nd::all
```cpp
template <typename M>
std::vector<std::vector<M>> stirling_2nd::all(int N, int K);
```

It returns $S(n, k) \pmod{M}$ for all $n$ such that $0 \leq n \leq N$ and all $k$ such that $0 \leq k \leq K$, where $M$ is `M::mod()`.

### Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $N \geq 0$
- $K \geq 0$

### Time Complexity
- $O(NK)$

### License
- CC0

### Author
- anqooqie
