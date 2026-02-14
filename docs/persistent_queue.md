---
title: Persistent queue
documentation_of: //tools/persistent_queue.hpp
---

It is a persistent queue.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
persistent_queue<T> queue();
```

It creates an empty queue.

### Constraints
- None

### Time Complexity
- $O(1)$

## empty
```cpp
bool queue.empty();
```

It returns whether the queue is empty or not.

### Constraints
- None

### Time Complexity
- $O(1)$

## size
```cpp
std::size_t queue.size();
```

It returns the current number of elements of the queue.

### Constraints
- None

### Time Complexity
- $O(1)$

## front
```cpp
const T& queue.front();
```

It returns the reference to the oldest element in the queue.

### Constraints
- `queue` is not empty.

### Time Complexity
- $O(1)$

## back
```cpp
const T& queue.back();
```

It returns the reference to the newest element in the queue.

### Constraints
- `queue` is not empty.

### Time Complexity
- $O(1)$

## push
```cpp
persistent_queue<T> queue.push(T x);
```

It clones `queue`, adds `x` to the new queue and returns the new queue.

### Constraints
- None

### Time Complexity
- $O(1)$

## pop
```cpp
persistent_queue<T> queue.pop();
```

It clones `queue`, removes the oldest element from the new queue and returns the new queue.

### Constraints
- `queue` is not empty.

### Time Complexity
- $O(1)$

## emplace
```cpp
template <typename... Args>
persistent_queue<T> emplace(Args&&... args);
```

It clones `queue`, adds `T(args...)` to the new queue and returns the new queue.

### Constraints
- None

### Time Complexity
- $O(1)$
