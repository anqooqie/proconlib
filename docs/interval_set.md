---
title: Set of closed integer intervals
documentation_of: //tools/interval_set.hpp
---

It is a set of closed integer intervals.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) interval_set<T, false> set;
(2) interval_set<T, true> set;
```

It creates an empty set of closed integer intervals.
The type parameter `<T>` represents the type of integers.

It internally manages `std::map<T, T> m` whose key is the lower bound of an interval and value is the upper bound of an interval.

- (1)
    - Adjacent intervals will not be merged. For example, $\\{[1, 3], [6, 6]\\} \cup \\{[4, 5]\\} = \\{[1, 3], [4, 5], [6, 6]\\}$.
- (2)
    - Adjacent intervals will be merged. For example, $\\{[1, 3], [6, 6]\\} \cup \\{[4, 5]\\} = \\{[1, 6]\\}$.

### Constraints
- None

### Time Complexity
- $O(1)$

## begin
```cpp
std::map<T, T>::const_iterator set.begin();
```

It returns an iterator pointing to the least closed integer interval.
In other words, it returns `m.begin()`.

### Constraints
- None

### Time Complexity
- $O(1)$

## end
```cpp
std::map<T, T>::const_iterator set.end();
```

It returns an iterator pointing to the interval which would follow the greatest closed integer interval.
In other words, it returns `m.end()`.

### Constraints
- None

### Time Complexity
- $O(1)$

## empty
```cpp
bool set.empty();
```

It returns whether the set is empty or not.

### Constraints
- None

### Time Complexity
- $O(1)$

## size
```cpp
std::map<T, T>::size_type set.size();
```

It returns the number of closed integer intervals.
In other words, it returns `m.size()`.

### Constraints
- None

### Time Complexity
- $O(1)$

## find
```cpp
std::map<T, T>::const_iterator set.find(T x);
```

It returns an iterator pointing to the interval which contains $x$.
If such the interval does not exist, it returns `set.end()`.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where $n$ is the number of intervals.

## contains
```cpp
bool set.contains(T x);
```

It returns whether the set contains $x$ or not.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where $n$ is the number of intervals.

## lower_bound
```cpp
std::map<T, T>::const_iterator set.lower_bound(T x);
```

It returns an iterator pointing to the least interval whose upper bound is greater than or equal to $x$.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where $n$ is the number of intervals.

## upper_bound
```cpp
std::map<T, T>::const_iterator set.upper_bound(T x);
```

It returns an iterator pointing to the least interval whose lower bound is greater than $x$.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where $n$ is the number of intervals.

## insert
```cpp
void set.insert(T l, T r);
```

It inserts a interval $\\{l, r\\}$ to the set.
Duplicated intervals will be merged one interval.
For example, $\\{[1, 3], [6, 6]\\} \cup \\{[2, 4]\\} = \\{[1, 4], [6, 6]\\}$.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where $n$ is the number of intervals.

## erase
```cpp
void set.erase(T l, T r);
```

It removes a interval $\\{l, r\\}$ from the set.
For example, $\\{[1, 4], [6, 6]\\} - \\{[2, 3]\\} = \\{[1, 1], [4, 4], [6, 6]\\}$.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where $n$ is the number of intervals.
