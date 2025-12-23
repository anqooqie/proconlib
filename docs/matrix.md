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
(1) matrix<T, n, m> A();
(2) matrix<T, n, m> A(std::initializer_list<std::initializer_list<T>> il);
(3) matrix<T> A(int n, int m);
(4) matrix<T> A(int n, int m, T x);
(5) matrix<T> A(std::initializer_list<std::initializer_list<T>> il);
```

- (1), (3)
    - It creates a $n \times m$-dimensional matrix.
- (2)
    - It creates a $n \times m$-dimensional matrix where $A_{r, c}$ is `il.begin()[r].begin()[c]`.
- (4)
    - It creates a $n \times m$-dimensional matrix filled with $x$.
- (5)
    - It creates a $n \times m$-dimensional matrix where $n$ is `il.size()`, $m$ is `il.empty() ? 0 : il.begin()->size()` and $A_{r, c}$ is `il.begin()[r].begin()[c]`.

The type parameter `<T>` represents the type of the elements.
Alternatively, you can explicitly specify the algebraic structure (at least a semiring) of the coefficient ring as `<T>`.

### Constraints
- (2)
    - `il.size()` is equal to $n$.
    - For all $0 \leq r < n$, `il.begin()[r].size()` is equal to $m$.
- (3), (4)
    - $n \geq 0$
    - $m \geq 0$
- (5)
    - For all $0 \leq r < $`il.size()`, `il.begin()[r].size()` is equal to `il.begin()->size()`.

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
int A.rows();
```

It returns $n$, the number of rows of the matrix.

### Constraints
- None

### Time Complexity
- $O(1)$

## cols
```cpp
int A.cols();
```

It returns $m$, the number of columns of the matrix.

### Constraints
- None

### Time Complexity
- $O(1)$

## gauss_jordan
```cpp
int A.gauss_jordan();
```

It transforms $A$ to the reduced row echelon form, and returns the rank of $A$.

### Constraints
- The coefficient ring is a field.

### Time Complexity
- $O(n m^2)$

## rank
```cpp
int A.rank();
```

It returns the rank of $A$.

### Constraints
- The coefficient ring is a field.

### Time Complexity
- $O(nm \min(n, m))$

## solve
```cpp
(1) matrix<T> A.solve(vector<T, n> b);
(2) matrix<T> A.solve(vector<T> b);
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
- The coefficient ring is a field.
- (1)
    - `A` is `matrix<T, n, m>`.
    - $m \geq 1$
- (2)
    - `A` is `matrix<T>`.
    - $n = \mathrm{dim}(b)$
    - $m \geq 1$

### Time Complexity
- $O(n m^2)$

## determinant
```cpp
T A.determinant();
```

It returns $\|A\|$.

### Constraints
- The coefficient ring is a field.
- $n = m$

### Time Complexity
- $O(n^3)$

## Unary plus operator
```cpp
(1) matrix<T, n, m> operator+(matrix<T, n, m> A);
(2) matrix<T> operator+(matrix<T> A);
```

It returns the copy of $A$.

### Constraints
- None

### Time Complexity
- $O(nm)$

## Unary negation operator
```cpp
(1) matrix<T, n, m> operator-(matrix<T, n, m> A);
(2) matrix<T> operator-(matrix<T> A);
```

It returns $-A$.

### Constraints
- The coefficient ring is a ring.

### Time Complexity
- $O(nm)$

## Addition operators
```cpp
(1) matrix<T, n, m> operator+(matrix<T, n, m> A, matrix<T, n, m> B);
(2) matrix<T, n, m>& operator+=(matrix<T, n, m>& A, matrix<T, n, m> B);
(3) matrix<T> operator+(matrix<T> A, matrix<T> B);
(4) matrix<T>& operator+=(matrix<T>& A, matrix<T> B);
```

- (1), (3)
    - It returns $A + B$.
- (2), (4)
    - It updates $A$ to $A + B$, and returns the new $A$.

### Constraints
- (3), (4)
    - The number of rows of $A$ is equal to the number of rows of $B$.
    - The number of columns of $A$ is equal to the number of columns of $B$.

### Time Complexity
- $O(nm)$

## Subtraction operators
```cpp
(1) matrix<T, n, m> operator-(matrix<T, n, m> A, matrix<T, n, m> B);
(2) matrix<T, n, m>& operator-=(matrix<T, n, m>& A, matrix<T, n, m> B);
(3) matrix<T> operator-(matrix<T> A, matrix<T> B);
(4) matrix<T>& operator-=(matrix<T>& A, matrix<T> B);
```

- (1), (3)
    - It returns $A - B$.
- (2), (4)
    - It updates $A$ to $A - B$, and returns the new $A$.

### Constraints
- The coefficient ring is a ring.
- (3), (4)
    - The number of rows of $A$ is equal to the number of rows of $B$.
    - The number of columns of $A$ is equal to the number of columns of $B$.

### Time Complexity
- $O(nm)$

## Multiplication operators for a matrix
```cpp
(1) matrix<T, n, k> operator*(matrix<T, n, m> A, matrix<T, m, k> B);
(2) matrix<T, n, m>& operator*=(matrix<T, n, m>& A, matrix<T, m, m> B);
(3) matrix<T> operator*(matrix<T> A, matrix<T> B);
(4) matrix<T>& operator*=(matrix<T>& A, matrix<T> B);
```

- (1), (3)
    - It returns $AB$.
- (2), (4)
    - It updates $A$ to $AB$, and returns the new $A$.

### Constraints
- (3)
    - The number of columns of $A$ is equal to the number of rows of $B$.
- (4)
    - The number of columns of $A$ is equal to the number of rows of $B$.
    - The number of rows of $B$ is equal to the number of columns of $B$.

### Time Complexity
- (1), (3)
    - $O(nmk)$
- (2), (4)
    - $O(nm^2)$

## Multiplication operators for a vector
```cpp
(1) vector<T, n> operator*(matrix<T, n, m> A, vector<T, m> v);
(2) vector<T> operator*(matrix<T> A, vector<T> v);
```

It returns $Av$.

### Constraints
- (2)
    - The number of columns of $A$ is equal to $\mathrm{dim}(v)$.

### Time Complexity
- $O(nm)$

## Multiplication operators for a scholar value
```cpp
(1) matrix<T, n, m> operator*(matrix<T, n, m> A, T c);
(2) matrix<T, n, m>& operator*=(matrix<T, n, m>& A, T c);
(3) matrix<T> operator*(matrix<T> A, T c);
(4) matrix<T>& operator*=(matrix<T>& A, T c);
```

- (1), (3)
    - It returns $cA$.
- (2), (4)
    - It updates $A$ to $cA$, and returns the new $A$.

### Constraints
- None

### Time Complexity
- $O(nm)$

## Division operators for a matrix
```cpp
(1) matrix<T, n, m> operator/(matrix<T, n, m> A, matrix<T, m, m> B);
(2) matrix<T, n, m>& operator/=(matrix<T, n, m>& A, matrix<T, m, m> B);
(3) matrix<T> operator/(matrix<T> A, matrix<T> B);
(4) matrix<T>& operator/=(matrix<T>& A, matrix<T> B);
```

- (1), (3)
    - It returns $AB^{-1}$.
- (2), (4)
    - It updates $A$ to $AB^{-1}$, and returns the new $A$.

### Constraints
- The coefficient ring is a field.
- (1), (2)
    - $B^{-1}$ exists.
- (3), (4)
    - The number of columns of $A$ is equal to the number of rows of $B$.
    - $B^{-1}$ exists.

### Time Complexity
- $O((n + m) m^2)$

## Division operators for a scholar value
```cpp
(1) matrix<T, n, m> operator/(matrix<T, n, m> A, T c);
(2) matrix<T, n, m>& operator/=(matrix<T, n, m>& A, T c);
(3) matrix<T> operator/(matrix<T> A, T c);
(4) matrix<T>& operator/=(matrix<T>& A, T c);
```

- (1), (3)
    - It returns $c^{-1} A$.
- (2), (4)
    - It updates $A$ to $c^{-1} A$, and returns the new $A$.

### Constraints
- The coefficient ring is a field.
- $c \neq 0$

### Time Complexity
- $O(nm)$

## Comparison operations
```cpp
(1) bool operator==(matrix<T, n, m> A, matrix<T, n, m> B);
(2) bool operator!=(matrix<T, n, m> A, matrix<T, n, m> B);
(3) bool operator==(matrix<T> A, matrix<T> B);
(4) bool operator!=(matrix<T> A, matrix<T> B);
```

- (1), (3)
    - It returns whether $A = B$.
- (2), (4)
    - It returns whether $A \neq B$.

### Constraints
- None

### Time Complexity
- $O(nm)$

## operator&gt;&gt;
```cpp
(1) std::istream& operator>>(std::istream& is, matrix<T, n, m>& self);
(2) std::istream& operator>>(std::istream& is, matrix<T>& self);
```

It is equivalent to the following code.

```cpp
for (int r = 0; r < self.rows(); ++r) {
  for (int c = 0; c < self.cols(); ++c) {
    is >> self[r][c];
  }
}
return is;
```

### Constraints
- None

### Time Complexity
- $O(nm)$

## operator&lt;&lt;
```cpp
(1) std::ostream& operator<<(std::ostream& os, matrix<T, n, m> self);
(2) std::ostream& operator<<(std::ostream& os, matrix<T> self);
```

It is equivalent to the following code.

```cpp
for (int r = 0; r < self.rows(); ++r) {
  os << '[';
  for (int c = 0; c < self.cols(); ++c) {
    if (c > 0) os << ", ";
    os << self[r][c];
  }
  os << ']' << '\n';
}
return os;
```

### Constraints
- None

### Time Complexity
- $O(nm)$

## e
```cpp
(1) matrix<T, n, n> matrix<T, n, n>::e();
(2) matrix<T> matrix<T>::e(int n);
```

It returns $n \times n$-dimensional identity matrix.

### Constraints
- (2)
    - $n \geq 0$

### Time Complexity
- $O(n^2)$

## inv
```cpp
(1) std::optional<matrix<T, n, n>> A.inv();
(2) std::optional<matrix<T>> A.inv();
```

If $A^{-1}$ exists, it returns $A^{-1}$.
Otherwise, it returns `std::nullopt`.

### Constraints
- The coefficient ring is a field.
- (1)
    - $A$ is `matrix<T, n, n>`.
- (2)
    - $A$ is `matrix<T>`.
    - $n = m$

### Time Complexity
- $O(n^3)$

## transposed
```cpp
(1) matrix<T, m, n> A.transposed();
(2) matrix<T> A.transposed();
```

It returns $A^\top$.

### Constraints
- (1)
    - $A$ is `matrix<T, n, m>`.
- (2)
    - $A$ is `matrix<T>`.

### Time Complexity
- $O(nm)$
