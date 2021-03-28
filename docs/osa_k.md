---
title: osa_k's algorithm
documentation_of: //tools/osa_k.hpp
---

It handles minimum prime factors.

## Usage
```cpp
// builds the table of minimum prime factors up to 10000
tools::osa_k<int> osa_k(10000);

// obtains the number of divisors of 24, that is 8
osa_k.divisor_count(24);

// lists all prime factors of 24, that are 2, 2, 2 and 3
for (const int& prime_factor : osa_k.prime_factor_range(24)) {
  // ...
}

// lists all distinct prime factors of 24, that are std::make_pair(2, 3) and std::make_pair(3, 1)
for (const std::pair<int, int>& distinct_prime_factor : osa_k.distinct_prime_factor_range(24)) {
  // ...
}

// lists all primes up to 10000
for (const int& prime : osa_k.prime_range()) {
  // ...
}

// lists all divisors of 24, that are 1, 2, 3, 4, 6, 8, 12 and 24
for (const int& divisor : osa_k.divisors(24)) {
  // ...
}
```

## License
- CC0

## Author
- anqooqie
