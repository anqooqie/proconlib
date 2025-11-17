---
title: Concept for a type that can be passed for range adaptors multi times
documentation_of: //tools/available_for_multiple_range_adaptors.hpp
---

```cpp
template <typename T>
concept available_for_multiple_range_adaptors = std::ranges::forward_range<T>
  && std::ranges::viewable_range<T>
  && std::copyable<std::views::all_t<T>>;
```

It is a concept that represents a type that can be passed for range adaptors multi times.

### Constraints
- None

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
