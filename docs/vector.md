---
title: Vector
documentation_of: //tools/vector.hpp
---

It is a $n$-dimensional vector.

### License
- CC0

### Author
- anqooqie

## Methods based on std::vector&lt;T&gt;
```cpp
vector<T> v();
vector<T> v(const vector<T>& u);
vector<T> v(vector<T>&& u);
vector<T>& v.operator=(const vector<T>& u);
vector<T>& v.operator=(vector<T>&& u);

vector<T> v(std::size_t n);
vector<T> v(std::size_t n, T value);
template <typename InputIter>
vector<T> v(InputIter first, InputIter last);
vector<T> v(std::initializer_list<T> il);

(vector<T>::iterator or vector<T>::const_iterator) v.begin();
(vector<T>::iterator or vector<T>::const_iterator) v.end();
vector<T>::const_iterator v.cbegin();
vector<T>::const_iterator v.cend();
(vector<T>::reverse_iterator or vector<T>::const_reverse_iterator) v.rbegin();
(vector<T>::reverse_iterator or vector<T>::const_reverse_iterator) v.rend();
vector<T>::const_reverse_iterator v.crbegin();
vector<T>::const_reverse_iterator v.crend();

std::size_t v.size();
bool v.empty();

(T& or const T&) v.operator[](std::size_t i);
(T& or const T&) v.front();
(T& or const T&) v.back();

bool operator==(vector<T> v, vector<T> u);
bool operator!=(vector<T> v, vector<T> u);
```

They are methods based on `std::vector<T>`.

### Constraints
- Same as ones of `std::vector<T>`.

### Time Complexity
- Same as ones of `std::vector<T>`.

## Arithmetic operators
```cpp
(1) vector<T> operator+(vector<T> v);
(2) vector<T> operator-(vector<T> v);
(3) vector<T>& v.operator+=(vector<T> u);
(4) vector<T> operator+(vector<T> v, vector<T> u);
(5) vector<T>& v.operator-=(vector<T> u);
(6) vector<T> operator-(vector<T> v, vector<T> u);
(7) vector<T>& v.operator*=(T c);
(8) vector<T> operator*(T c, vector<T> v);
(9) vector<T> operator*(vector<T> v, T c);
(10) vector<T>& v.operator/=(T c);
(11) vector<T> operator/(vector<T> v, T c);
```

It supports basic arithmetic operations on vectors where $\overrightarrow{u}$ is another $n$-dimensional vector and $c$ is a scholar value.

### Constraints
- (3), (4), (5), (6)
    - The dimension of $\overrightarrow{u}$ is equal to the dimension of $\overrightarrow{v}$.
- (10), (11)
    - $c \neq 0$

### Time Complexity
- $O(n)$

## inner_product
```cpp
T v.inner_product(vector<T> u);
```

It returns $\overrightarrow{v} \cdot \overrightarrow{u}$.

### Constraints
- The dimension of $\overrightarrow{u}$ is equal to the dimension of $\overrightarrow{v}$.

### Time Complexity
- $O(n)$

## l1_norm
```cpp
T v.l1_norm();
```

It returns $\left\\|\overrightarrow{v}\right\\|_1$.

### Constraints
- None

### Time Complexity
- $O(n)$

## squared_l2_norm
```cpp
T v.squared_l2_norm();
```

It returns $\left\\|\overrightarrow{v}\right\\|_2^2 = \overrightarrow{v} \cdot \overrightarrow{v}$.

### Constraints
- None

### Time Complexity
- $O(n)$

## l2_norm
```cpp
std::is_conditional_t<std::is_floating_point_v<T>, T, double> v.l2_norm();
```

It returns $\left\\|\overrightarrow{v}\right\\|_2$.

### Constraints
- None

### Time Complexity
- $O(n)$

## normalized
```cpp
vector<T> v.normalized();
```

It returns $\frac{\overrightarrow{v}}{\left\\|\overrightarrow{v}\right\\|_2}$.

### Constraints
- `std::is_floating_point_v<T>` is `true`.

### Time Complexity
- $O(n)$

## operator&gt;&gt;
```cpp
std::istream& operator>>(std::istream& is, vector<T>& self);
```

It is equivalent to the following code.

```cpp
for (auto& v : self) is >> v;
return is;
```

### Constraints
- None

### Time Complexity
- $O(n)$

## operator&lt;&lt;
```cpp
std::ostream& operator<<(std::ostream& os, const vector<T>& self);
```

It is equivalent to the following code.

```cpp
os << '(';
for (std::size_t i = 0; i < self.size(); ++i) {
  if (i > 0) os << ", ";
  os << self[i];
}
os << ')';
return os;
```

### Constraints
- None

### Time Complexity
- $O(n)$
