---
title: Two dimensional vector
documentation_of: //tools/vector2.hpp
---

It is a two-dimensional vector.

### License
- CC0

### Author
- anqooqie

## Methods based on std::array&lt;T, 2&gt;
```cpp
vector2<T> v(const vector2<T>& u);
vector2<T>& v.operator=(const vector2<T>& u);

(vector2<T>::iterator or vector2<T>::const_iterator) v.begin();
(vector2<T>::iterator or vector2<T>::const_iterator) v.end();
vector2<T>::const_iterator v.cbegin();
vector2<T>::const_iterator v.cend();
(vector2<T>::reverse_iterator or vector2<T>::const_reverse_iterator) v.rbegin();
(vector2<T>::reverse_iterator or vector2<T>::const_reverse_iterator) v.rend();
vector2<T>::const_reverse_iterator v.crbegin();
vector2<T>::const_reverse_iterator v.crend();

std::size_t v.size();
bool v.empty();

(T& or const T&) v.operator[](std::size_t i);
(T& or const T&) v.front();
(T& or const T&) v.back();

bool operator==(vector2<T> v, vector2<T> u);
bool operator!=(vector2<T> v, vector2<T> u);
```

They are methods based on `std::array<T, 2>`.

### Constraints
- Same as ones of `std::array<T, 2>`.

### Time Complexity
- Same as ones of `std::array<T, 2>`.

## Constructor
```cpp
(1) vector2<T> v();
(2) vector2<T> v(T x, T y);
```

- (1)
    - It creates a vector $(0, 0)$.
- (2)
    - It creates a vector $(x, y)$.

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

## Arithmetic operators
```cpp
(1) vector2<T> operator+(vector2<T> v);
(2) vector2<T> operator-(vector2<T> v);
(3) vector2<T>& v.operator+=(vector2<T> u);
(4) vector2<T> operator+(vector2<T> v, vector2<T> u);
(5) vector2<T>& v.operator-=(vector2<T> u);
(6) vector2<T> operator-(vector2<T> v, vector2<T> u);
(7) vector2<T>& v.operator*=(T c);
(8) vector2<T> operator*(T c, vector2<T> v);
(9) vector2<T> operator*(vector2<T> v, T c);
(10) vector2<T>& v.operator/=(T c);
(11) vector2<T> operator/(vector2<T> v, T c);
```

It supports basic arithmetic operations on vectors where $\overrightarrow{u}$ is another vector and $c$ is a scholar value.

### Constraints
- (10), (11)
    - $c \neq 0$

### Time Complexity
- $O(1)$

## inner_product
```cpp
T v.inner_product(vector2<T> u);
```

It returns $\overrightarrow{v} \cdot \overrightarrow{u}$.

### Constraints
- None

### Time Complexity
- $O(1)$

## outer_product
```cpp
T v.outer_product(vector2<T> u);
```

It returns `v.x * u.y - v.y * u.x`.

### Constraints
- None

### Time Complexity
- $O(1)$

## l1_norm
```cpp
T v.l1_norm();
```

It returns $\left\\|\overrightarrow{v}\right\\|_1 = \|x\| + \|y\|$.

### Constraints
- None

### Time Complexity
- $O(1)$

## squared_l2_norm
```cpp
T v.squared_l2_norm();
```

It returns $\overrightarrow{v} \cdot \overrightarrow{v} = x^2 + y^2$.

### Constraints
- None

### Time Complexity
- $O(1)$

## l2_norm
```cpp
std::conditional_t<std::is_floating_point_v<T>, T, double> v.l2_norm();
```

It returns $\left\\|\overrightarrow{v}\right\\|_2 = \sqrt{x^2 + y^2}$.

### Constraints
- None

### Time Complexity
- $O(1)$

## normalized
```cpp
vector2<T> v.normalized();
```

It returns $\frac{\overrightarrow{v}}{\left\\|\overrightarrow{v}\right\\|_2}$.

### Constraints
- `std::is_floating_point_v<T>` is `true`.

### Time Complexity
- $O(1)$

## turned90
```cpp
vector2<T> v.turned90();
```

It returns $(-y, x)$.

### Constraints
- None

### Time Complexity
- $O(1)$

## turned270
```cpp
vector2<T> v.turned270();
```

It returns $(y, -x)$.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator&gt;&gt;
```cpp
std::istream& operator>>(std::istream& is, vector2<T>& self);
```

It returns `is >> self.x >> self.y`.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator&lt;&lt;
```cpp
std::ostream& operator<<(std::ostream& os, const vector2<T>& self);
```

It returns `os << '(' << self.x << ", " << self.y << ')'`.

### Constraints
- None

### Time Complexity
- $O(1)$

## four_directions
```cpp
const std::array<vector2<T>, 4>& vector2<T>::four_directions();
```

It returns vectors $\left(\cos\left(\frac{i}{2}\pi\right), \sin\left(\frac{i}{2}\pi\right)\right)$ for $0 \leq i < 4$.

### Constraints
- None

### Time Complexity
- $O(1)$

## eight_directions
```cpp
const std::array<vector2<T>, 8>& vector2<T>::eight_directions();
```

It returns vectors $\left(\mathrm{RI}\left(\cos\left(\frac{i}{4}\pi\right)\right), \mathrm{RI}\left(\sin\left(\frac{i}{4}\pi\right)\right)\right)$ for $0 \leq i < 8$ where $\mathrm{RI}(x)$ rounds $x$ towards infinity.

### Constraints
- None

### Time Complexity
- $O(1)$
