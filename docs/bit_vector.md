---
title: Bit vector
documentation_of: //tools/bit_vector.hpp
---

It is a bit vector.

### License
- CC0 1.0 Universal

### Author
- Nyaan

## Constructor
```cpp
bit_vector bv(int n);
```

It creates a bit vector of length $n$ filled with $0$.

### Constraints
- $n \geq 0$

### Time Complexity
- $O(n)$

## init
```cpp
void bv.init(int n);
```

It makes `bv` a bit vector of length $n$ filled with $0$.

### Constraints
- $n \geq 0$

### Time Complexity
- $O(n)$

## size
```cpp
std::uint32_t bv.size();
```

It returns $n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## get
```cpp
std::uint32_t bv.get(std::uint32_t i);
```

It returns the $i$-th bit of the bit vector. (i.e., $0$ or $1$)

### Constraints
- $0 \leq i < n$

### Time Complexity
- $O(1)$

## set
```cpp
void bv.set(std::uint32_t i);
```

It updates the $i$-th bit of the bit vector to $1$.

### Constraints
- $0 \leq i < n$

### Time Complexity
- $O(1)$

## build
```cpp
void bv.build();
```

It builts the internal auxiliary data structure for the `rank` operation.

### Constraints
- None

### Time Complexity
- $O(n)$

## zeros
```cpp
std::uint32_t bv.zeros();
```

It returns the number of zero bits in the bit vector.

### Constraints
- `bv.build()` has been called ever.
- `bv.init()` has not been called after the last call of `bv.build()`.
- `bv.set()` has not been called after the last call of `bv.build()`.

### Time Complexity
- $O(1)$

## rank0
```cpp
std::uint32_t bv.rank0(std::uint32_t r);
```

It returns $\|\\{i \in \mathbb{N} \mid 0 \leq i < r \land \mathrm{bv.get}(i) = 0\\}\|$.

### Constraints
- $0 \leq r \leq n$
- `bv.build()` has been called ever.
- `bv.init()` has not been called after the last call of `bv.build()`.
- `bv.set()` has not been called after the last call of `bv.build()`.

### Time Complexity
- $O(1)$

## rank1
```cpp
std::uint32_t bv.rank1(std::uint32_t r);
```

It returns $\|\\{i \in \mathbb{N} \mid 0 \leq i < r \land \mathrm{bv.get}(i) = 1\\}\|$.

### Constraints
- $0 \leq r \leq n$
- `bv.build()` has been called ever.
- `bv.init()` has not been called after the last call of `bv.build()`.
- `bv.set()` has not been called after the last call of `bv.build()`.

### Time Complexity
- $O(1)$
