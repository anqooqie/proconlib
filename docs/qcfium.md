---
title: QCFium's method
documentation_of: //tools/qcfium.hpp
---

```cpp
#include "tools/qcfium.hpp"
```

It enables some compile options to speed up.

### Constraints
- With GCC, it must be included after the standard library headers.

### Time Complexity
- Not applicable

### Note
Only GCC honors the pragmas in this file.
Clang can include it without errors, but ignores the pragmas, so it has no effect there.

### References
- [Speeding Up for Naive Algorithm - Codeforces](https://codeforces.com/blog/entry/66279)

### License
- CC0

### Author
- anqooqie
