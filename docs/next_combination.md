---
title: Next combination as n-choose-r
documentation_of: //tools/next_combination.hpp
---

```cpp
template <typename Iterator>
bool next_combination(Iterator first, Iterator k, Iterator last);
```

It generates the next combination as n-choose-r.
It returns `true` if the next combination exists, `false` otherwise.

## Usage
```cpp
// 9-choose-3
int k = 3;
do {
  std::cout << std::string(s.begin(), std::next(s.begin(), k)) << std::endl;
} while (tools::next_combination(s.begin(), std::next(s.begin(), k), s.end()));
```

### Constraints
- `first` $\leq$ `k` $\leq$ `last`

### Time Complexity
- Not analyzed yet

### References
- [Stack Overflow](https://stackoverflow.com/questions/5095407/all-combinations-of-k-elements-out-of-n/5097100#5097100)

### License
- CC BY-SA 3.0

### Author
- Thomas Draper
