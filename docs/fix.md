---
title: Fixed point combinator
documentation_of: //tools/fix.hpp
---

```cpp
template <typename G>
(see below) fix(G g);
```

It returns a fixed point of its argument function.
When `f(args...)` is invocable and `g(f, args...)` is invocable, `tools::fix(g)(args...)` returns `f(args...)`.

### Usage
```cpp
tools::fix([&](auto&& fib, const int n) -> int {
  return n >= 2 ? fib(n - 2) + fib(n - 1) : n;
})(10);
```

## Constraints
- `g(f, args...)` is invocable.
- `f(args...)` is invocable.

### Time Complexity
- It depends on `g`.

### References
- [C++のラムダで再帰する - koturnの日記](https://koturn.hatenablog.com/entry/2018/06/10/060000)

### License
- According to the source, "ブログ上のコードはコピペ自由です．"

### Author
- koturn
