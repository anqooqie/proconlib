---
title: Lazy evaluation read-only std::vector
documentation_of: //tools/virtual_vector.hpp
---

It is almost same as `const std::vector{f(0), f(1), ..., f(n - 1)}`, but evaluate values when needed.
Hence, the time taken to construct it can be $o(n)$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <typename F>
virtual_vector<F> v(std::size_t n, F f);
```

### Constraints
- $n \geq 0$
- $f$ takes `std::size_t` and returns `const T&` where `T` is any type.

### Time Complexity
- Same as the time taken to copy `f`

## Methods based on const std::vector&lt;T&gt;
```cpp
virtual_vector<F>::const_iterator v.begin();
virtual_vector<F>::const_iterator v.end();
virtual_vector<F>::const_iterator v.cbegin();
virtual_vector<F>::const_iterator v.cend();
virtual_vector<F>::const_reverse_iterator v.rbegin();
virtual_vector<F>::const_reverse_iterator v.rend();
virtual_vector<F>::const_reverse_iterator v.crbegin();
virtual_vector<F>::const_reverse_iterator v.crend();

std::size_t v.size();
bool v.empty();

const T& v.operator[](std::size_t i);
const T& v.at(std::size_t i);
const T& v.front();
const T& v.back();

bool operator==(virtual_vector<F> v, virtual_vector<G> u);
bool operator!=(virtual_vector<F> v, virtual_vector<G> u);
bool operator<(virtual_vector<F> v, virtual_vector<G> u);
bool operator<=(virtual_vector<F> v, virtual_vector<G> u);
bool operator>(virtual_vector<F> v, virtual_vector<G> u);
bool operator>=(virtual_vector<F> v, virtual_vector<G> u);
```

They are methods based on `const std::vector<T>`.

### Constraints
- Same as ones of `const std::vector<T>`

### Time Complexity
- Same as ones of `const std::vector<T>`
