---
title: Assertion macro
documentation_of: //tools/assert_that.hpp
---

```cpp
#define assert_that(cond) do {\
  if (!(cond)) {\
    std::cerr << __FILE__ << ':' << __LINE__ << ": " << __func__ << ": Assertion `" << #cond << "' failed." << '\n';\
    std::exit(EXIT_FAILURE);\
  }\
} while (false)
```

It asserts that `cond` holds.
If `cond` is `false`, it outputs the debug information to `std::cerr` and terminates the program with exit status `EXIT_FAILURE`.

The macro is always enabled regardless of `NDEBUG` unlike `assert`.

## Constraints
- None

## Time Complexity
- Same as `cond`

## License
- CC0

## Author
- anqooqie
