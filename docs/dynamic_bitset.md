---
title: std::bitset with dynamic size
documentation_of: //tools/dynamic_bitset.hpp
---

It is a sequence of bits of length $n$ determined at runtime.
Its interface is compatible to that of `std::bitset`.

### License
- CC0

### Author
- anqooqie

## Methods based on std::bitset
```cpp
dynamic_bitset s();
dynamic_bitset s(const dynamic_bitset& t);
dynamic_bitset s(dynamic_bitset&& t);
dynamic_bitset& s.operator=(const dynamic_bitset& t);
dynamic_bitset& s.operator=(dynamic_bitset&& t);

dynamic_bitset s(std::size_t n);
dynamic_bitset s(const std::string& str);

dynamic_bitset& s.operator&=(const dynamic_bitset& t);
dynamic_bitset& s.operator|=(const dynamic_bitset& t);
dynamic_bitset& s.operator^=(const dynamic_bitset& t);
dynamic_bitset& s.operator<<=(std::size_t pos);
dynamic_bitset& s.operator>>=(std::size_t pos);
dynamic_bitset& s.set();
dynamic_bitset& s.set(std::size_t pos);
dynamic_bitset& s.set(std::size_t pos, bool val);
dynamic_bitset& s.reset();
dynamic_bitset& s.reset(std::size_t pos);
dynamic_bitset s.operator~() const;
dynamic_bitset& s.flip();
dynamic_bitset& s.flip(std::size_t pos);

typename dynamic_bitset::reference s.operator[](std::size_t pos);
bool s.operator[](std::size_t pos) const;
std::size_t s.count() const;
std::size_t s.size() const;
bool s.test(std::size_t pos) const;
bool s.all() const;
bool s.any() const;
bool s.none() const;
std::string s.to_string() const;
bool operator==(const dynamic_bitset& s, const dynamic_bitset& t);
bool operator!=(const dynamic_bitset& s, const dynamic_bitset& t);
dynamic_bitset s.operator<<(std::size_t pos) const;
dynamic_bitset s.operator>>(std::size_t pos) const;

dynamic_bitset operator&(const dynamic_bitset& s, const dynamic_bitset& t);
dynamic_bitset operator|(const dynamic_bitset& s, const dynamic_bitset& t);
dynamic_bitset operator^(const dynamic_bitset& s, const dynamic_bitset& t);
std::istream& operator>>(std::istream& is, dynamic_bitset& s);
std::ostream& operator<<(std::ostream& os, const dynamic_bitset& s);

struct reference {
  reference& operator=(bool x);
  reference& operator=(const reference& other);
  bool operator~() const;
  operator bool() const;
  reference& flip();
};
```

They are methods based on `std::bitset`.

### Constraints
- Same as ones of `std::bitset`.

### Time Complexity
- Same as ones of `std::bitset`.

## resize
```cpp
void s.resize(std::size_t m);
```

It resizes `s` to contain $m$ bits.
If the current size $n$ is greater than $m$, `s` is reduced to its first $m$ bits.
If the current size $n$ is less than $m$, additional $0$s are appended to `s`.

### Constraints
- None

### Time Complexity
- $O(n)$

## shrink_to_fit
```cpp
void s.shrink_to_fit();
```

It requests the removal of unused memory allocated for `s`.
It is a non-binding request.
It depends on the implementation whether the request is fulfilled.

### Constraints
- None

### Time Complexity
- $O(n)$

## Find_first
```cpp
std::size_t s.Find_first();
```

It returns the least $i$ such that $0 \leq i < n$ and `s.test(i)` hold.
If such the integer does not exist, it returns $n$.

### Constraints
- None

### Time Complexity
- $O(i)$ where $i$ is the return value of `s.Find_first()`

## Find_next
```cpp
std::size_t s.Find_next(std::size_t i);
```

It returns the least $j$ such that $i < j < n$ and `s.test(j)` hold.
If such the integer does not exist, it returns $n$.

### Constraints
- $i < n$

### Time Complexity
- $O(j - i)$ where $j$ is the return value of `s.Find_next(i)`
