---
title: Median solver
documentation_of: //tools/median_solver.hpp
---

It calculates the median of an array.
It also allows you to dynamically add values to the array.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
median_solver<T> median();
```

It creates an empty array.

### Constraints
- None

### Time Complexity
- $O(1)$

## push
```cpp
void median.push(T x);
```

It adds $x$ to the array.

### Constraints
- None

### Time Complexity
- $O(\log N)$ where $N$ is the number of elements in the array

## size
```cpp
std::size_t median.size();
```

It returns the number of elements in the array.

### Constraints
- None

### Time Complexity
- $O(1)$

## empty
```cpp
bool median.empty();
```

It returns whether the array is empty or not.

### Constraints
- None

### Time Complexity
- $O(1)$

## lesser
```cpp
T median.lesser();
```

It returns the $\left\lfloor\frac{N + 1}{2}\right\rfloor$-th smallest element in the array.

### Constraints
- The array is not empty.

### Time Complexity
- $O(1)$

## greater
```cpp
T median.greater();
```

It returns the $\left(\left\lfloor\frac{N}{2}\right\rfloor + 1\right)$-th smallest element in the array.

### Constraints
- The array is not empty.

### Time Complexity
- $O(1)$
