---
title: Circular shift to the left
documentation_of: //tools/rotate_left.hpp
---

```cpp
template <typename T>
T rotate_left(T value, std::size_t count);
```

It returns `value` left-shifted by `input`-bit with a manner of the circular shift.

## Usage
```cpp
// 5-bit circular shift to the left
tools::rotate_left(x, 5);
```

## References
- [Stack Overflow](https://stackoverflow.com/questions/776508/best-practices-for-circular-shift-rotate-operations-in-c/776523#776523)

## License
- CC BY-SA 3.0

## Authors
- [John Regehr](https://blog.regehr.org/)
- [Peter Cordes](https://stackoverflow.com/users/224132/peter-cordes)
