---
title: Three dimensional vector
documentation_of: //tools/vector3.hpp
---

It is a three-dimensional vector.

### License
- CC0

### Author
- anqooqie

## Methods based on std::array&lt;T, 3&gt;
```cpp
vector3<T> v(const vector3<T>& u);
vector3<T>& v.operator=(const vector3<T>& u);

(vector3<T>::iterator or vector3<T>::const_iterator) v.begin();
(vector3<T>::iterator or vector3<T>::const_iterator) v.end();
vector3<T>::const_iterator v.cbegin();
vector3<T>::const_iterator v.cend();
(vector3<T>::reverse_iterator or vector3<T>::const_reverse_iterator) v.rbegin();
(vector3<T>::reverse_iterator or vector3<T>::const_reverse_iterator) v.rend();
vector3<T>::const_reverse_iterator v.crbegin();
vector3<T>::const_reverse_iterator v.crend();

std::size_t v.size();
bool v.empty();

(T& or const T&) v.operator[](std::size_t i);
(T& or const T&) v.front();
(T& or const T&) v.back();

void v.swap(vector3<T>& u);

bool operator==(vector3<T> v, vector3<T> u);
bool operator!=(vector3<T> v, vector3<T> u);
```

They are methods based on `std::array<T, 3>`.

### Constraints
- Same as ones of `std::array<T, 3>`.

### Time Complexity
- Same as ones of `std::array<T, 3>`.

## Constructor
```cpp
(1) vector3<T> v();
(2) vector3<T> v(T x, T y, T z);
```

- (1)
    - It creates a vector $(0, 0, 0)$.
- (2)
    - It creates a vector $(x, y, z)$.

### Constraints
- None

### Time Complexity
- $O(1)$

## x
```cpp
T v.x;
```

It is identical to `v[0]`.

## y
```cpp
T v.y;
```

It is identical to `v[1]`.

## z
```cpp
T v.z;
```

It is identical to `v[2]`.

## Arithmetic operators
```cpp
(1) vector3<T> operator+(vector3<T> v);
(2) vector3<T> operator-(vector3<T> v);
(3) vector3<T>& v.operator+=(vector3<T> u);
(4) vector3<T> operator+(vector3<T> v, vector3<T> u);
(5) vector3<T>& v.operator-=(vector3<T> u);
(6) vector3<T> operator-(vector3<T> v, vector3<T> u);
(7) vector3<T>& v.operator*=(T c);
(8) vector3<T> operator*(T c, vector3<T> v);
(9) vector3<T> operator*(vector3<T> v, T c);
(10) vector3<T>& v.operator/=(T c);
(11) vector3<T> operator/(vector3<T> v, T c);
```

It supports basic arithmetic operations on vectors where $\overrightarrow{u}$ is another vector and $c$ is a scholar value.

### Constraints
- (10), (11)
    - $c \neq 0$

### Time Complexity
- $O(1)$

## inner_product
```cpp
T v.inner_product(vector3<T> u);
```

It returns $\overrightarrow{v} \cdot \overrightarrow{u}$.

### Constraints
- None

### Time Complexity
- $O(1)$

## outer_product
```cpp
vector3<T> v.outer_product(vector3<T> u);
```

It returns $\overrightarrow{v} \times \overrightarrow{u}$.

### Constraints
- None

### Time Complexity
- $O(1)$

## l1_norm
```cpp
T v.l1_norm();
```

It returns $\left\\|\overrightarrow{v}\right\\|_1 = \|x\| + \|y\| + \|z\|$.

### Constraints
- None

### Time Complexity
- $O(1)$

## squared_l2_norm
```cpp
T v.squared_l2_norm();
```

It returns $\overrightarrow{v} \cdot \overrightarrow{v} = x^2 + y^2 + z^2$.

### Constraints
- None

### Time Complexity
- $O(1)$

## l2_norm
```cpp
std::conditional_t<std::is_floating_point_v<T>, T, double> v.l2_norm();
```

It returns $\left\\|\overrightarrow{v}\right\\|_2 = \sqrt{x^2 + y^2 + z^2}$.

### Constraints
- None

### Time Complexity
- $O(1)$

## normalized
```cpp
vector3<T> v.normalized();
```

It returns $\frac{\overrightarrow{v}}{\left\\|\overrightarrow{v}\right\\|_2}$.

### Constraints
- `std::is_floating_point_v<T>` is `true`.

### Time Complexity
- $O(1)$

## orthonormal_basis
```cpp
std::array<vector3<T>, 3> v.orthonormal_basis();
```

It returns three vectors $u_1, u_2, u_3$ which satisfy the following conditions.

$$\begin{align*}
\left\{\begin{array}{l}
u_1 = \frac{v}{|v|}\\
|u_2| = 1\\
u_1 \cdot u_2 = 0\\
u_3 = u_1 \times u_2
\end{array}\right.&
\end{align*}$$

### Constraints
- `std::is_floating_point_v<T>` is `true`.

### Time Complexity
- $O(1)$

## operator&gt;&gt;
```cpp
std::istream& operator>>(std::istream& is, vector3<T>& self);
```

It returns `is >> self.x >> self.y >> self.z`.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator&lt;&lt;
```cpp
std::ostream& operator<<(std::ostream& os, const vector3<T>& self);
```

It returns `os << '(' << self.x << ", " << self.y << ", " << self.z << ')'`.

### Constraints
- None

### Time Complexity
- $O(1)$
