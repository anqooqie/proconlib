---
title: Sliding window aggregation
documentation_of: //tools/swag.hpp
---

It is a data structure which supports the following operations.

- Create an empty sequence of elements on a given monoid in $O(1)$.
- Add an element to the sequence as the first element in $O(1)$.
- Add an element to the sequence as the last element in $O(1)$.
- Remove the first element from the sequence in $O(1)$ amortized.
- Remove the last element from the sequence in $O(1)$ amortized.
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
- `tools::monoid<M>` holds.

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

## push_front
```cpp
void swag.push_front(typename M::T x);
```

It adds an element $x$ to the sequence as the first element.

### Constraints
- None

### Time Complexity
- $O(1)$

## emplace_front
```cpp
template <typename... Args>
void swag.emplace_front(Args&&... args);
```

It adds an element `typename M::T(args...)` to the sequence as the first element.

### Constraints
- None

### Time Complexity
- $O(1)$

## push_back
```cpp
void swag.push_back(typename M::T x);
```

It adds an element $x$ to the sequence as the last element.

### Constraints
- None

### Time Complexity
- $O(1)$

## emplace_back
```cpp
template <typename... Args>
void swag.emplace_back(Args&&... args);
```

It adds an element `typename M::T(args...)` to the sequence as the last element.

### Constraints
- None

### Time Complexity
- $O(1)$

## pop_front
```cpp
void swag.pop_front();
```

It removes the first element from the sequence.

### Constraints
- The sequence is not empty.

### Time Complexity
- $O(1)$ amortized

## pop_back
```cpp
void swag.pop_back();
```

It removes the last element from the sequence.

### Constraints
- The sequence is not empty.

### Time Complexity
- $O(1)$ amortized

## prod
```cpp
typename M::T swag.prod();
```

It returns the production on the monoid of all elements in the sequence.

### Constraints
- None

### Time Complexity
- $O(1)$
