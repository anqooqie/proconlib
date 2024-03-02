---
title: Four dimensional vector
documentation_of: //tools/vector4.hpp
---

It is a four-dimensional vector.

### License
- CC0

### Author
- anqooqie

## Methods based on std::array&lt;T, 4&gt;
```cpp
vector4<T> v(const vector4<T>& u);
vector4<T>& v.operator=(const vector4<T>& u);

(vector4<T>::iterator or vector4<T>::const_iterator) v.begin();
(vector4<T>::iterator or vector4<T>::const_iterator) v.end();
vector4<T>::const_iterator v.cbegin();
vector4<T>::const_iterator v.cend();
(vector4<T>::reverse_iterator or vector4<T>::const_reverse_iterator) v.rbegin();
(vector4<T>::reverse_iterator or vector4<T>::const_reverse_iterator) v.rend();
vector4<T>::const_reverse_iterator v.crbegin();
vector4<T>::const_reverse_iterator v.crend();

std::size_t v.size();
bool v.empty();

(T& or const T&) v.operator[](std::size_t i);
(T& or const T&) v.front();
(T& or const T&) v.back();

bool operator==(vector4<T> v, vector4<T> u);
bool operator!=(vector4<T> v, vector4<T> u);
```

They are methods based on `std::array<T, 4>`.

### Constraints
- Same as ones of `std::array<T, 4>`.

### Time Complexity
- Same as ones of `std::array<T, 4>`.

## Constructor
```cpp
(1) vector4<T> v();
(2) vector4<T> v(T x, T y, T z, T w);
```

- (1)
    - It creates a vector $(0, 0, 0, 0)$.
- (2)
    - It creates a vector $(x, y, z, w)$.

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

## w
```cpp
T v.w;
```

It is identical to `v[3]`.

## Arithmetic operators
```cpp
(1) vector4<T> operator+(vector4<T> v);
(2) vector4<T> operator-(vector4<T> v);
(3) vector4<T>& v.operator+=(vector4<T> u);
(4) vector4<T> operator+(vector4<T> v, vector4<T> u);
(5) vector4<T>& v.operator-=(vector4<T> u);
(6) vector4<T> operator-(vector4<T> v, vector4<T> u);
(7) vector4<T>& v.operator*=(T c);
(8) vector4<T> operator*(T c, vector4<T> v);
(9) vector4<T> operator*(vector4<T> v, T c);
(10) vector4<T>& v.operator/=(T c);
(11) vector4<T> operator/(vector4<T> v, T c);
```

It supports basic arithmetic operations on vectors where $\overrightarrow{u}$ is another vector and $c$ is a scholar value.

### Constraints
- (10), (11)
    - $c \neq 0$

### Time Complexity
- $O(1)$

## inner_product
```cpp
T v.inner_product(vector4<T> u);
```

It returns $\overrightarrow{v} \cdot \overrightarrow{u}$.

### Constraints
- None

### Time Complexity
- $O(1)$

## l1_norm
```cpp
T v.l1_norm();
```

It returns $\left\\|\overrightarrow{v}\right\\|_1 = \|x\| + \|y\| + \|z\| + \|w\|$.

### Constraints
- None

### Time Complexity
- $O(1)$

## squared_l2_norm
```cpp
T v.squared_l2_norm();
```

It returns $\overrightarrow{v} \cdot \overrightarrow{v} = x^2 + y^2 + z^2 + w^2$.

### Constraints
- None

### Time Complexity
- $O(1)$

## l2_norm
```cpp
std::conditional_t<std::is_floating_point_v<T>, T, double> v.l2_norm();
```

It returns $\left\\|\overrightarrow{v}\right\\|_2 = \sqrt{x^2 + y^2 + z^2 + w^2}$.

### Constraints
- None

### Time Complexity
- $O(1)$

## normalized
```cpp
vector4<T> v.normalized();
```

It returns $\frac{\overrightarrow{v}}{\left\\|\overrightarrow{v}\right\\|_2}$.

### Constraints
- `std::is_floating_point_v<T>` is `true`.

### Time Complexity
- $O(1)$

## operator&gt;&gt;
```cpp
std::istream& operator>>(std::istream& is, vector4<T>& self);
```

It returns `is >> self.x >> self.y >> self.z >> self.w`.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator&lt;&lt;
```cpp
std::ostream& operator<<(std::ostream& os, const vector4<T>& self);
```

It returns `os << '(' << self.x << ", " << self.y << ", " << self.z << ", " << self.w << ')'`.

### Constraints
- None

### Time Complexity
- $O(1)$
