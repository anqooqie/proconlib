---
title: Sliding window aggregation
documentation_of: //tools/swag.hpp
---

It is a data structure which supports the following operations.

- Create an empty sequence of elements on a given monoid in $O(1)$.
- Add an element to the sequence as the last element in $O(1)$.
- Remove the first element from the sequence in amortized $O(1)$.
- Calculate the production on the monoid of all elements in the sequence, in $O(1)$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <typename M>
swag<M> swag();
```

It creates an empty sequence of elements on a given monoid $M$.

### Constraints
- For all $a$ in `typename M::T`, $b$ in `typename M::T` and $c$ in `typename M::T`, `M::op(M::op(a, b), c)` $=$ `M::op(a, M::op(b, c))`.
- For all $a$ in `typename M::T`, `M::op(M::e(), a)` $=$ `M::op(a, M::e())` $=$ `M::e()`.

### Time Complexity
- $O(1)$

## empty
```cpp
bool swag.empty();
```

It returns whether the sequence is empty or not.

### Constraints
- None

### Time Complexity
- $O(1)$

## push
```cpp
void swag.push(typename M::T x);
```

It adds an element $x$ to the sequence as the last element.

### Constraints
- None

### Time Complexity
- $O(1)$

## emplace
```cpp
template <typename... Args>
void swag.emplace(Args&&... args);
```

It adds an element `typename M::T(args...)` to the sequence as the last element.

### Constraints
- None

### Time Complexity
- $O(1)$

## pop
```cpp
void swag.pop();
```

It removes the first element from the sequence.

### Constraints
- The sequence is not empty.

### Time Complexity
- amortized $O(1)$

## prod
```cpp
typename M::T swag.prod();
```

It returns the production on the monoid of all elements in the sequence.

### Constraints
- None

### Time Complexity
- $O(1)$
