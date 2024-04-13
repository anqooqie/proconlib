---
title: Combine hash values
documentation_of: //tools/hash_combine.hpp
---

```cpp
void hash_combine(std::size_t& seed, T key);
```

It is a utility function for combining hash values.

### Example

```cpp
std::size_t hash_value(const std::pair<int, int>& pair) {
  static const std::size_t seed = tools::now();
  std::size_t res = seed;
  tools::hash_combine(res, pair.first);
  tools::hash_combine(res, pair.second);
  return res;
}
```

### References
- [c++ - How to create a good hash_combine with 64 bit output (inspired by boost::hash_combine) - Stack Overflow](https://stackoverflow.com/questions/8513911/how-to-create-a-good-hash-combine-with-64-bit-output-inspired-by-boosthash-co/8980550#8980550)

### License
- MIT

### Author
- Google Inc.
