---
title: Set of integers as closed integer intervals
documentation_of: //tools/integer_interval_set.hpp
---

It is a set of integers, and provides the following two operations.

- Add the integeres $x$ such that $l \leq x \leq r$ to the set, where $l$ and $r$ are given integers.
- Remove the integers $x$ such that $l \leq x \leq r$ from the set, where $l$ and $r$ are given integers.

It manages the elements as a set of mutually exclusive closed integer intervals.
The set of intervals is implemented as `std::map<T, T> m`, whose key is the lower bound of an interval and value is the upper bound of it.
It provides limited (read-only) access to `m`.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
integer_interval_set<T> set;
```

It creates an empty set of integers.
The type parameter `<T>` represents the type of integers.

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

It returns the number of mutually exclusive closed integer intervals.
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
- $O(\log n)$ where $n$ is the number of mutually exclusive closed integer intervals.

## contains
```cpp
bool set.contains(T x);
```

It returns whether the set contains $x$ or not.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where $n$ is the number of mutually exclusive closed integer intervals.

## lower_bound
```cpp
std::map<T, T>::const_iterator set.lower_bound(T x);
```

It returns an iterator pointing to the least interval whose upper bound is greater than or equal to $x$.
If such the interval does not exist, it returns `set.end()`.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where $n$ is the number of mutually exclusive closed integer intervals.

## upper_bound
```cpp
std::map<T, T>::const_iterator set.upper_bound(T x);
```

It returns an iterator pointing to the least interval whose lower bound is greater than $x$.
If such the interval does not exist, it returns `set.end()`.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where $n$ is the number of mutually exclusive closed integer intervals.

## insert
```cpp
void set.insert(T l, T r);
```

It inserts the integers $x$ such that $l \leq x \leq r$ to the set.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where $n$ is the number of mutually exclusive closed integer intervals.

## erase
```cpp
void set.erase(T l, T r);
```

It removes the integers $x$ such that $l \leq x \leq r$ from the set.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where $n$ is the number of mutually exclusive closed integer intervals.
