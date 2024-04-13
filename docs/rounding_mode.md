---
title: Rounding mode
documentation_of: //tools/rounding_mode.hpp
---

```cpp
enum class rounding_mode {
  ceiling,
  down,
  floor,
  half_down,
  half_even,
  half_up,
  up
};
```

It is a rounding mode for `tools::bigdecimal`.

- `ceiling`
    - It is a rounding mode to round towards positive infinity.
- `down`
    - It is a rounding mode to round towards zero.
- `floor`
    - It is a rounding mode to round towards negative infinity.
- `half_down`
    - It is a rounding mode to round towards the nearest neighbor unless both neighbors are equidistant, in which case round towards zero.
- `half_even`
    - It is a rounding mode to round towards the nearest neighbor unless both neighbors are equidistant, in which case round towards the even neighbor.
- `half_up`
    - It is a rounding mode to round towards the nearest neighbor unless both neighbors are equidistant, in which case round away from zero.
- `up`
    - It is a rounding mode to round away from zero.

### Constraints
- None

### Time Complexity
- Not available

### License
- CC0

### Author
- anqooqie
