---
title: Fast input
documentation_of: //tools/cin.hpp
---

It provides very restricted but fast input functions.

### Constraints
- You cannot include this header file from more than one compilation unit.

### License
- CC0 1.0 Universal

### Author
- Nyaan

## tools::cin
```cpp
tools::istream cin;
```

It is an interface to the input functions.

### Constraints
- None

### Time Complexity
- Not applicable

## tools::istream::operator&gt;&gt;
```cpp
(1) tools::istream& cin.operator>>(char& c);
(2) tools::istream& cin.operator>>(std::string& s);
(3) template <typename T> tools::istream& cin.operator>>(T& x);
```

- (1)
    - It reads one character from standard input, sets the value to `c` and returns `cin`.
- (2)
    - We can express the entire string not yet read from standard input in the form of the regular expression `([ \n]*)([^ \n]*).*`. It reads the first and second groups from standard input, sets the second group to `s` and returns `cin`.
- (3)
    - If we can express the entire string not yet read from standard input in the form of the regular expression `([ \n]*)(-?[0-9]+).*`, it reads the first and second groups from standard input, sets the integer parsed from the second group to `x` and returns `cin`.

### Constraints
- (1)
    - You cannot read standard input by any other ways except for `tools::cin` in the program.
    - There are at least one character not yet read from standard input.
- (2)
    - You cannot read standard input by any other ways except for `tools::cin` in the program.
- (3)
    - You cannot read standard input by any other ways except for `tools::cin` in the program.
    - `<T>` is a built-in integral type.
    - If `<T>` is signed:
        - The entire string not yet read from standard input matches the regular expression `^[ \n]*-?[0-9]+`.
        - `-std::numeric_limits<T>::max()` $\leq v \leq$ `std::numeric_limits<T>::max()` where $v$ is the value that will be read.
    - If `<T>` is unsigned:
        - The entire string not yet read from standard input matches the regular expression `^[ \n]*[0-9]+`.
        - $0 \leq v \leq$ `std::numeric_limits<T>::max()` where $v$ is the value that will be read.

### Time Complexity
- (1), (3)
    - $O(1)$
- (2)
    - $O(\|v\|)$ where $v$ is the value that will be read
