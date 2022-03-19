---
title: Heap managing median
documentation_of: //tools/median_heap.hpp
---

It is a heap managing median.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
median_heap<T, Compare = std::less<T>> heap(Compare less = Compare());
```

It creates an empty heap.

### Constraints
- None

### Time Complexity
- $O(1)$

## empty
```cpp
bool heap.empty();
```

It returns whether the heap is empty or not.

### Constraints
- None

### Time Complexity
- $O(1)$

## size
```cpp
std::size_t heap.size();
```

It returns the number of elements in the heap.

### Constraints
- None

### Time Complexity
- $O(1)$

## lesser
```cpp
T heap.lesser();
```

It returns the $\left\lfloor\frac{N + 1}{2}\right\rfloor$-th smallest element in the heap where $N$ is the number of elements in the heap.

### Constraints
- The heap is not empty.

### Time Complexity
- $O(1)$

## greater
```cpp
T heap.greater();
```

It returns the $\left(\left\lfloor\frac{N}{2}\right\rfloor + 1\right)$-th smallest element in the heap where $N$ is the number of elements in the heap.

### Constraints
- The heap is not empty.

### Time Complexity
- $O(1)$

## push
```cpp
void heap.push(T x);
```

It adds $x$ to the heap.

### Constraints
- None

### Time Complexity
- $O(\log N)$ where $N$ is the number of elements in the heap

## emplace
```cpp
template <typename... Args>
void heap.emplace(Args&&... args);
```

It adds `T(args...)` to the heap.

### Constraints
- None

### Time Complexity
- $O(\log N)$ where $N$ is the number of elements in the heap

## swap
```cpp
void heap.swap(median_heap<T, Compare>& other);
```

It swaps `heap` and `other`.

### Constraints
- None

### Time Complexity
- $O(1)$
