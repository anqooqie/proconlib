---
title: Parse fixed point number
documentation_of: //tools/parse_fixed_point_number.hpp
---

```cpp
std::int_fast64_t parse_fixed_point_number(std::string s, int scale);
```
It parses a string as a fixed point number.
It returns $s * 10^{\mathrm{scale}}$.

## License
- CC0

## Author
- anqooqie
