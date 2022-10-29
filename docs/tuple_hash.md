---
title: Hash of std::tuple
documentation_of: //tools/tuple_hash.hpp
---

```cpp
template <typename... Ts>
struct tuple_hash {
  using result_type = std::size_t;
  using argument_type = std::tuple<Ts...>;
  result_type operator()(argument_type key);
};
```

It returns hash of `std::tuple<Ts...>`.

## References
- [c++ - How to create a good hash_combine with 64 bit output (inspired by boost::hash_combine) - Stack Overflow](https://stackoverflow.com/questions/8513911/how-to-create-a-good-hash-combine-with-64-bit-output-inspired-by-boosthash-co/8980550#8980550)

## License
- MIT

## Author
- Google Inc.
