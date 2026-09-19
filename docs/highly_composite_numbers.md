---
title: List all highly composite numbers
documentation_of: //tools/highly_composite_numbers.hpp
---

```cpp
template <tools::non_bool_integral T>
std::vector<std::pair<T, T>> highly_composite_numbers(T n);
```

It returns all the highly composite numbers not greater than $n$, in ascending order, each paired with its number of positive divisors.
That is, it returns the pairs $(m, d(m))$ for all the positive integers $m \leq n$ such that $d(k) < d(m)$ for all $1 \leq k < m$, where $d(m)$ is the number of positive divisors of $m$.

It enumerates all the positive integers not greater than $n$ of the form $2^{e_1} 3^{e_2} 5^{e_3} \cdots$ with $e_1 \geq e_2 \geq e_3 \geq \cdots$, since every highly composite number is of that form.
Let $N$ be the number of such integers and $H$ be the number of highly composite numbers not greater than $n$.
The time complexity is technically $O(N \log H)$, which is written below in terms of $n$ by $\log N \sim \frac{2\pi}{\sqrt{3}} \sqrt{\frac{\log n}{\log \log n}}$ as $n \to \infty$.
As a practical guide, the values of $N$, $H$ and $N \log_2 H$ for typical values of $n$ are shown below.

|$n$|$N$|$H$|$N \log_2 H$|
|---|---|---|---|
|$10^3$|$39$|$15$|$152$|
|$10^6$|$289$|$38$|$1517$|
|$10^9$|$1274$|$66$|$7701$|
|$10^{12}$|$4357$|$95$|$28625$|
|$10^{15}$|$12651$|$125$|$88124$|
|$10^{18}$|$32749$|$156$|$238590$|
|$2^{31} - 1$|$1476$|$69$|$9016$|
|$2^{63} - 1$|$43607$|$167$|$321981$|
|$2^{64} - 1$|$47616$|$170$|$352806$|
|$2^{127} - 1$|$4085319$|$400$|$35312910$|
|$2^{128} - 1$|$4333170$|$404$|$37517502$|

### Constraints
- $n \geq 1$

### Time Complexity
- $\exp\left(\left(\frac{2\pi}{\sqrt{3}} + o(1)\right) \sqrt{\frac{\log n}{\log \log n}}\right)$

### License
- CC0

### Author
- anqooqie
