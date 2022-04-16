---
title: Persistent stack
documentation_of: //tools/persistent_stack.hpp
---

It is a persistent stack.

### License
- CC0

### Author
- anqooqie

## Constructor of buffer
```cpp
persistent_stack<T>::buffer buffer();
```

It creates an empty buffer for `tools::persistent_stack<T>`.

### Constraints
- None

### Time Complexity
- $O(1)$

## Constructor
```cpp
persistent_stack<T> stack(persistent_stack<T>::buffer& buffer);
```

It creates an empty stack whose data stores on `buffer`.

### Constraints
- None

### Time Complexity
- $O(1)$

## empty
```cpp
bool stack.empty();
```

It returns whether the stack is empty or not.

### Constraints
- `buffer` is in its lifetime.

### Time Complexity
- $O(1)$

## size
```cpp
std::size_t stack.size();
```

It returns the current number of elements of the stack.

### Constraints
- `buffer` is in its lifetime.

### Time Complexity
- $O(1)$

## top
```cpp
T stack.top();
```

It returns the newest element in the stack.

### Constraints
- `buffer` is in its lifetime.
- `stack` is not empty.

### Time Complexity
- $O(1)$

## push
```cpp
persistent_stack<T> stack.push(T x);
```

It clones `stack`, adds `x` to the new stack and returns the new stack.

### Constraints
- `buffer` is in its lifetime.

### Time Complexity
- $O(1)$ amortized

## pop
```cpp
persistent_stack<T> stack.pop();
```

It clones `stack`, removes the newest element from the new stack and returns the new stack.

### Constraints
- `buffer` is in its lifetime.
- `stack` is not empty.

### Time Complexity
- $O(1)$

## emplace
```cpp
template <typename... Args>
persistent_stack<T> emplace(Args&&... args);
```

It clones `stack`, adds `T(args...)` to the new stack and returns the new stack.

### Constraints
- `buffer` is in its lifetime.

### Time Complexity
- $O(1)$ amortized
