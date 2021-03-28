---
title: Typical groups
documentation_of: //tools/group.hpp
---

```cpp
namespace group {

  template <typename Type>
  struct plus {
    using T = Type;
    static T op(T x, T y);
    static T e();
    static T inv(T x);
  };

  template <typename Type>
  struct bit_xor {
    using T = Type;
    static T op(T x, T y);
    static T e();
    static T inv(T x);
  };
};
```

They are typical groups.

## License
- CC0

## Author
- anqooqie
