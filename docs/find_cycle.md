---
title: Floyd's cycle-finding algorithm
documentation_of: //tools/find_cycle.hpp
---

```cpp
template <typename T, typename F>
std::pair<std::int_fast64_t, std::int_fast64_t> find_cycle(T seed, F f);
```

It returns the length of head and the length of cycle.

## Parameters
- `seed`
    - the initial state
- `f`
    - the function which generates the next state

## License
- CC0

## Author
- anqooqie
