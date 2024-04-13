---
title: Fast output
documentation_of: //tools/cout.hpp
---

It provides very restricted but fast output functions.

### Constraints
- You cannot include this header file from more than one compilation unit.

### License
- CC0 1.0 Universal

### Author
- Nyaan

## tools::cout
```cpp
tools::ostream cout;
```

It is an interface to the output functions.

## tools::ostream::operator&lt;&lt;
```cpp
(1) tools::ostream& cout.operator<<(char c);
(2) tools::ostream& cout.operator<<(bool b);
(3) tools::ostream& cout.operator<<(std::string s);
(4) tools::ostream& cout.operator<<(const char *s);
(5) template <typename T> tools::ostream& cout.operator<<(T& x);
```

- (1)
    - It writes `c` to standard output and returns `cout`.
- (2)
    - If `b` is `true`, it writes `1` to standard output and returns `cout`.
    - If `b` is `false`, it writes `0` to standard output and returns `cout`.
- (3)
    - It writes `s` to standard output and returns `cout`.
- (4)
    - It is identical to `cout << std::string(s)`.
- (5)
    - It writes `x` to standard output and returns `cout`.

### Constraints
- (1), (2), (3), (4)
    - You cannot write standard output by any other ways except for `tools::cout` in the program.
- (5)
    - You cannot write standard output by any other ways except for `tools::cout` in the program.
    - `<T>` is a built-in integral type.

### Time Complexity
- (1), (2), (5)
    - $O(1)$
- (3), (4)
    - $O(\|s\|)$
