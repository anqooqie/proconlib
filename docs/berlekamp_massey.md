---
title: Berlekamp-Massey algorithm
documentation_of: //tools/berlekamp_massey.hpp
---

```cpp
template <typename K>
tools::polynomial<K> berlekamp_massey(tools::polynomial<K> a);
```

Given a generating function of a sequence $(a_0, a_1, \ldots, a_{N - 1})$ where $a_i$ is on a field, it returns a generating function of a sequence $(1, c_1, c_2, \ldots, c_d)$ of the minimum length $d \geq 0$ such that $a_i + \sum_{j=1}^d c_j a_{i - j} \equiv 0$ for $d \leq i < N$.

Berlekamp-Massey algorithm can be used in the following situation.
We have the first $2d$ terms of an infinite sequence.
The sequence is known to be generated from a linear recurrence equation of at most degree $d$.
If we give the first $2d$ terms to Berlekamp-Massey algorithm, we can identify the coefficients of the linear recurrence equation.

### Example
Assume that we have the first $4$ terms $(0, 1, 1, 2)$ of an infinite sequence $(a_0, a_1, \ldots)$.
The sequence is known to be generated from a linear recurrence equation of at most degree $2$.
We can find that the sequence is generated from $a_{n+2} - a_{n+1} - a_n \equiv 0$ by Berlekamp-Massey algorithm.
The infinite sequence is the Fibonacci sequence.

Here is the example code to get $a_n$ for $0 \leq n < 2^{64}$ by Berlekamp-Massey + Bostan-Mori.

```cpp
#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/polynomial.hpp"
#include "tools/berlekamp_massey.hpp"
#include "tools/bostan_mori.hpp"

using mint = atcoder::modint998244353;

int main() {
  unsigned long long n;
  std::cin >> n;

  int most_degree = 2;
  tools::polynomial<mint> a{mint(0), mint(1)};
  for (int i = a.size(); i < 2 * most_degree; ++i) {
    a[i] = a[i - 1] + a[i - 2];
  }

  const auto c = tools::berlekamp_massey(a);

  a.resize(c.size() - 1);
  a *= c;
  a.resize(c.size() - 1);

  std::cout << tools::bostan_mori(a, c, n).val() << '\n';
  return 0;
}
```

### Constraints
- `<K>` is a field.

### Time Complexity
- $O(N^2)$

### References
- [数列の漸化式の特定と第N項の計算    [いかたこのたこつぼ]](https://ikatakos.com/pot/programming_algorithm/number_theory/barlekamp_massey)

### License
- CC0

### Author
- anqooqie
