---
title: Typical monoids
documentation_of: //tools/monoid.hpp
---

```cpp
namespace monoid {

  template <typename Type, Type E = std::numeric_limits<Type>::min()>
  struct max {
    using T = Type;
    static T op(T x, T y);
    static T e();
  };

  template <typename Type, Type E = std::numeric_limits<Type>::max()>
  struct min {
    using T = Type;
    static T op(T x, T y);
    static T e();
  };

  template <typename Type>
  struct multiplies {
    using T = Type;
    static T op(T x, T y);
    static T e();
  };

  template <typename Type>
  struct gcd {
    using T = Type;
    static T op(T x, T y);
    static T e();
  };

  template <typename Type, Type E>
  struct update {
    using T = Type;
    static T op(T x, T y);
    static T e();
  };
};
```

They are typical monoids.

## License
- CC0

## Author
- anqooqie
