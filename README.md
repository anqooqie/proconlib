# My Library for Competitive Programming

[![Actions Status](https://github.com/anqooqie/proconlib/actions/workflows/verify.yml/badge.svg)](https://github.com/anqooqie/proconlib/actions)
[![anqooqie](https://img.shields.io/endpoint?url=https%3A%2F%2Fatcoder-badges.now.sh%2Fapi%2Fatcoder%2Fjson%2Fanqooqie)](https://atcoder.jp/users/anqooqie)

## What is This
It is my library for competitive programming.
It requires gcc and C++23.

## Documentation
See my [![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://anqooqie.github.io/proconlib).

## License
Since different files have different licenses, please refer to the corresponding page in GitHub Pages.

## How to Use
Download the library at first.
```sh
git clone https://github.com/anqooqie/proconlib.git /path/to/the/library
cd /path/to/the/library
git submodule update --init --recursive
```

To use the library, include the header files of the library in your code.
```sh
vim example.cpp
```
```cpp
#include <iostream>
#include "tools/totient.hpp"

int main() {
  std::cout << "phi(6) = " << tools::totient(6) << '\n';
  return 0;
}
```

Since most online judges do not support submitting multiple files, you have to expand `#include` statements in most cases.
You can use any tools but I recommend [oj-bundle](https://github.com/online-judge-tools/verification-helper).
```sh
oj-bundle -I /path/to/the/library example.cpp >expanded_example.cpp
```

To update the library to the latest version, run the following commands.
```sh
cd /path/to/the/library
git pull origin main
git submodule update --recursive
```
