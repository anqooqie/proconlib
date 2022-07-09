---
title: Random tree generator
documentation_of: //tools/random_tree.hpp
---

It will generate random trees.

### References
- [あんたさんはTwitterを使っています: 「@DEGwer3456 https://t.co/iKbySxrK2D できました」 / Twitter](https://twitter.com/anta_prg/status/869633557362163712)

### License
- unknown

### Author
- anta

## Constructor
```cpp
random_tree<T> dist(std::size_t n);
```

It creates a generator to generate random trees with $n$ vertices.
The type parameter `<T>` will be used as the type of vertex numbers.

### Constraints
- $n \geq 1$

### Time Complexity
- $O(1)$

## size
```cpp
std::size_t dist.size();
```

It returns $n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator()
```cpp
template <typename R>
std::vector<std::pair<T, T>> dist.operator()(R& engine);
```

It returns edges of a randomly generated tree with $n$ vertices.

### Constraints
- `engine` is a pseudorandom number generator.

### Time Complexity
- $O(n)$
