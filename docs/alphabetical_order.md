---
title: Alphabetical order of a given character
documentation_of: //tools/alphabetical_order.hpp
license: CC0
---

```cpp
int alphabetical_order(char c);
```

It returns 

$$\begin{align*}
\left\{\begin{array}{ll}
0 & \text{(if $c$ is 'A' or 'a')}\\
1 & \text{(if $c$ is 'B' or 'b')}\\
\vdots &\\
25 & \text{(if $c$ is 'Z' or 'z')}
\end{array}\right.&
\end{align*}$$

## Constraints
- `c` is any one of `[A-Za-z]`.

## Time Complexity
- $O(1)$

## License
- CC0

## Author
- anqooqie
