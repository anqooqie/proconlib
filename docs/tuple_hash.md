---
title: Hash of std::tuple
documentation_of: //tools/tuple_hash.hpp
---

```cpp
template <typename... Ts>
struct tuple_hash {
  std::size_t operator()(std::tuple<Ts...> key);
};
```

It is a class for calculating the hash value of `std::tuple<T1, T2, ..., Tn>`.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
tools::tuple_hash<T1, T2, ..., Tn> hash();
```

It creates an instance.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator()
```cpp
std::size_t hash.operator()(std::tuple<T1, T2, ..., Tn> key);
```

It returns the hash value of `key`.

### Constraints
- None

### Time Complexity
- $O(n)$
