---
title: Concept for a mutable type
documentation_of: //tools/mutable_type.hpp
---

```cpp
template <typename T>
concept mutable_type = !std::is_const_v<std::remove_reference_t<T>>;
```

The concept is used to constrain template parameters to non-const types, ensuring that the referenced type can be modified.

### Example

|`T`|`tools::mutable_type<T>`|
|---|---|
|`int`|`true`|
|`int&`|`true`|
|`int&&`|`true`|
|`const int`|`false`|
|`const int&`|`false`|
|`const int&&`|`false`|

### Constraints
- None

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
