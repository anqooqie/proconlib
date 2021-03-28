---
title: Hash of std::pair
documentation_of: //tools/pair_hash.hpp
---

```cpp
(1) template <class T1, class T2> struct pair_hash;
(2) template <> struct pair_hash<std::int32_t, std::int32_t>;
(3) template <> struct pair_hash<std::uint32_t, std::uint32_t>;
(4) template <> struct pair_hash<std::int64_t, std::int64_t>;
(5) template <> struct pair_hash<std::uint64_t, std::uint64_t>;
```

It returns hash of `std::pair`.

## References
- (1)
    - [Boost, Version 1.71.0](https://github.com/boostorg/container_hash/blob/boost-1.71.0/include/boost/container_hash/hash.hpp)

## License
- (1)
    - [Boost Software License, Version 1.0](http://www.boost.org/LICENSE_1_0.txt)
- (2)
    - CC0
- (3)
    - CC0
- (4)
    - CC0
- (5)
    - CC0

## Author
- (1)
    - Daniel James
- (2)
    - anqooqie
- (3)
    - anqooqie
- (4)
    - anqooqie
- (5)
    - anqooqie
