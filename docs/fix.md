---
title: Fixed point combinator
documentation_of: //tools/fix.hpp
---

It returns a fixed point of its argument function.

## Usage
```cpp
tools::fix([&](auto&& fib, const int n) -> int {
  return n >= 2 ? fib(n - 2) + fib(n - 1) : n;
})(10);
```

## References
- [C++のラムダで再帰する - koturnの日記](https://koturn.hatenablog.com/entry/2018/06/10/060000)

## License
- According to the source, "ブログ上のコードはコピペ自由です．"

## Author
- koturn
