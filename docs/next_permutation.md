---
title: Next permutation with the manner of n-choose-r
documentation_of: //tools/next_permutation.hpp
---

```cpp
template <typename Iterator>
bool next_permutation(Iterator first, Iterator k, Iterator last);
```

It generates the next permutation with the manner of n-choose-r.
It returns `true` if the next permutation exists, `false` otherwise.

## Usage
```cpp
// 9-choose-3
int k = 3;
do {
  std::cout << std::string(s.begin(), std::next(s.begin(), k)) << std::endl;
} while (tools::next_permutation(s.begin(), std::next(s.begin(), k), s.end()));
```

## License
- CC0

## Author
- anqooqie
