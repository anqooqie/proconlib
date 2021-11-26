---
title: Matrix
documentation_of: //tools/matrix.hpp
---

It is a $n \times m$-dimensional matrix.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) matrix<T> A(std::size_t n, std::size_t m);
(2) matrix<T> A(std::size_t n, std::size_t m, T x);
```

- (1)
    - It creates a $n \times m$-dimensional matrix.
- (2)
    - It creates a $n \times m$-dimensional matrix, of which all the elements $x$.

The type parameter `<T>` represents the type of the elements.

### Constraints
- None

### Time Complexity
- $O(nm)$

## operator[]
```cpp
T& A[i][j];
```

It is the $(i, j)$-th element of the matrix.

### Constraints
- $0 \leq i < n$
- $0 \leq j < m$

### Time Complexity
- $O(1)$

## rows
```cpp
std::size_t A.rows();
```

It returns the number of the rows of the matrix.

### Constraints
- None

### Time Complexity
- $O(1)$

## cols
```cpp
std::size_t A.cols();
```

It returns the number of the columns of the matrix.

### Constraints
- None

### Time Complexity
- $O(1)$

## gauss_jordan
```cpp
std::int_fast64_t A.gauss_jordan();
```

It transforms the matrix to the reduced row echelon form, and returns the rank of the matrix.

### Constraints
- None

### Time Complexity
- $O(n m^2)$

## solve
```cpp
matrix<T> A.solve(vector<T> b);
```

It solves $A\overrightarrow{x} = \overrightarrow{b}$.
If the answers exist, the answers can be denoted as follows where $B$ is another $m \times (m - \mathrm{rank}(A) + 1)$-dimensional matrix and $c_i$ are free variables.

$$\begin{align*}
\overrightarrow{x} &= B\left(\begin{array}{c}
c_1\\
c_2\\
\vdots\\
c_{m - \mathrm{rank}(A)}\\
1
\end{array}\right)
\end{align*}$$

If the answers exist, it returns $B$.
Otherwise, it returns a $m \times 0$-dimensional matrix.

### Constraints
- None

### Time Complexity
- $O(n m^2)$

## Arithmetic operations
```cpp
(1) matrix<T> +A;
(2) matrix<T> -A;
(3) matrix<T> A + B;
(4) matrix<T> A - B;
(5) matrix<T> A * c;
(6) matrix<T> c * A;
(7) matrix<T> A / c;
(8) matrix<T>& A += B;
(9) matrix<T>& A -= B;
(10) matrix<T>& A *= c;
(11) matrix<T>& A /= c;
(12) bool A == B;
(13) bool A != B;
```

It supports basic arithmetic operations on matrices where $B$ is another $n \times m$-dimensional matrix and $c$ is a scholar value.

### Constraints
- (3), (4), (8), (9), (12), (13)
    - The dimension of $B$ is equal to the dimension of $A$.
- (7), (11)
    - $c \neq 0$

### Time Complexity
- $O(nm)$

## e
```cpp
matrix<T> matrix<T>::e(::std::size_t n);
```

It returns $n \times n$-dimensional identity matrix.

### Constraints
- None

### Time Complexity
- $O(n^2)$
