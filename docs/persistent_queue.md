---
title: Persistent queue
documentation_of: //tools/persistent_queue.hpp
---

It is a persistent queue.

### License
- CC0

### Author
- anqooqie

## Constructor of buffer
```cpp
persistent_queue<T>::buffer buffer();
```

It creates an empty buffer for `tools::persistent_queue<T>`.

### Constraints
- None

### Time Complexity
- $O(1)$

## Constructor
```cpp
persistent_queue<T> queue(persistent_queue<T>::buffer& buffer);
```

It creates an empty queue whose data stores on `buffer`.

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
- `buffer` is in its lifetime.

### Time Complexity
- $O(1)$

## size
```cpp
std::size_t queue.size();
```

It returns the current number of elements of the queue.

### Constraints
- `buffer` is in its lifetime.

### Time Complexity
- $O(1)$

## front
```cpp
T queue.front();
```

It returns the oldest element in the queue.

### Constraints
- `buffer` is in its lifetime.
- `queue` is not empty.

### Time Complexity
- $O(1)$

## back
```cpp
T queue.back();
```

It returns the newest element in the queue.

### Constraints
- `buffer` is in its lifetime.
- `queue` is not empty.

### Time Complexity
- $O(1)$

## push
```cpp
persistent_queue<T> queue.push(T x);
```

It clones `queue`, adds `x` to the new queue and returns the new queue.

### Constraints
- `buffer` is in its lifetime.

### Time Complexity
- $O(\log N)$ where $N$ is the number of ever `push` or `emplace` calls

## pop
```cpp
persistent_queue<T> queue.pop();
```

It clones `queue`, removes the oldest element from the new queue and returns the new queue.

### Constraints
- `buffer` is in its lifetime.
- `queue` is not empty.

### Time Complexity
- $O(\log n)$ where $n$ is the number of elements of `queue`

## emplace
```cpp
template <typename... Args>
persistent_queue<T> emplace(Args&&... args);
```

It clones `queue`, adds `T(args...)` to the new queue and returns the new queue.

### Constraints
- `buffer` is in its lifetime.

### Time Complexity
- $O(\log N)$ where $N$ is the number of ever `push` or `emplace` calls
