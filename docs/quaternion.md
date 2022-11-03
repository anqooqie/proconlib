---
title: Quaternion
documentation_of: //tools/quaternion.hpp
---

It is a quaternion.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) quaternion<T> q();
(2) quaternion<T> q(T x, T y, T z, T w);
```

- (1)
    - It creates a quaternion $0$.
- (2)
    - It creates a quaternion $w + xi + yj + zk$.

### Constraints
- `std::is_floating_point_v<T>` is `true`.

### Time Complexity
- $O(1)$

## x
```cpp
(1) T q.x();
(2) void q.x(T val);
```

- (1)
    - It returns the X component of $q$.
- (2)
    - It updates the X component of $q$ to `val`.

### Constraints
- None

### Time Complexity
- $O(1)$

## y
```cpp
(1) T q.y();
(2) void q.y(T val);
```

- (1)
    - It returns the Y component of $q$.
- (2)
    - It updates the Y component of $q$ to `val`.

### Constraints
- None

### Time Complexity
- $O(1)$

## z
```cpp
(1) T q.z();
(2) void q.z(T val);
```

- (1)
    - It returns the Z component of $q$.
- (2)
    - It updates the Z component of $q$ to `val`.

### Constraints
- None

### Time Complexity
- $O(1)$

## w
```cpp
(1) T q.w();
(2) void q.w(T val);
```

- (1)
    - It returns the W component of $q$.
- (2)
    - It updates the W component of $q$ to `val`.

### Constraints
- None

### Time Complexity
- $O(1)$

## real
```cpp
(1) T q.real();
(2) void q.real(T val);
```

- (1)
    - It returns the W component of $q$.
- (2)
    - It updates the W component of $q$ to `val`.

### Constraints
- None

### Time Complexity
- $O(1)$

## imag
```cpp
(1) tools::vector3<T> q.imag();
(2) void q.imag(tools::vector3<T> val);
```

- (1)
    - It returns the X component, the Y component and the Z component of $q$.
- (2)
    - It updates the X component of $q$ to `val.x`, the Y component of $q$ to `val.y` and the Z component of $q$ to `val.z`.

### Constraints
- None

### Time Complexity
- $O(1)$

## abs
```cpp
T q.abs();
```

It returns $\|q\| = \sqrt{w^2 + x^2 + y^2 + z^2}$.

### Constraints
- None

### Time Complexity
- $O(1)$

## norm
```cpp
T q.norm();
```

It returns $q q^\ast = w^2 + x^2 + y^2 + z^2$.

### Constraints
- None

### Time Complexity
- $O(1)$

## conj
```cpp
quaternion<T> q.conj();
```

It returns $q^\ast = w - xi - yj - zk$.

### Constraints
- None

### Time Complexity
- $O(1)$

## inv
```cpp
quaternion<T> q.inv();
```

It returns $q^{-1} = \frac{q^\ast}{\|q\|^2}$.

### Constraints
- $q \neq 0$

### Time Complexity
- $O(1)$

## angle
```cpp
T q.angle();
```

It returns the angle of the rotation which $q$ represents in radians.
In other words, it returns $2 \cos^{-1}(w)$.

### Constraints
- $\|q\| \approx 1$

### Time Complexity
- $O(1)$

## axis
```cpp
tools::vector3<T> q.axis();
```

It returns the axis of the rotation which $q$ represents.
In other words, it returns the following unit vector where $\mathbb{v} = (x, y, z)$.

$$\begin{align*}
\left\{\begin{array}{ll}
\frac{\mathbb{v}}{|\mathbb{v}|} & \text{(if $|\mathbb{v}| > 0$)}\\
(1, 0, 0) & \text{(if $|\mathbb{v}| = 0$)}
\end{array}\right.&
\end{align*}$$

### Constraints
- $\|q\| \approx 1$

### Time Complexity
- $O(1)$

## Unary plus operator
```cpp
quaternion<T> q.operator+();
```

It returns the copy of $q$.

### Constraints
- None

### Time Complexity
- $O(1)$

## Unary negation operator
```cpp
quaternion<T> q.operator-();
```

It returns $-w - xi - yj - zk$.

### Constraints
- None

### Time Complexity
- $O(1)$

## Addition operators
```cpp
(1) quaternion<T>& q1.operator+=(quaternion<T> q2);
(2) quaternion<T> operator+(quaternion<T> q1, quaternion<T> q2);
```

- (1)
    - It updates $q_1$ to $(w_1 + w_2) + (x_1 + x_2)i + (y_1 + y_2)j + (z_1 + z_2)k$, and returns $q_1$.
- (2)
    - It returns $(w_1 + w_2) + (x_1 + x_2)i + (y_1 + y_2)j + (z_1 + z_2)k$.

### Constraints
- None

### Time Complexity
- $O(1)$

## Subtraction operators
```cpp
(1) quaternion<T>& q1.operator-=(quaternion<T> q2);
(2) quaternion<T> operator-(quaternion<T> q1, quaternion<T> q2);
```

- (1)
    - It updates $q_1$ to $(w_1 - w_2) + (x_1 - x_2)i + (y_1 - y_2)j + (z_1 - z_2)k$, and returns $q_1$.
- (2)
    - It returns $(w_1 - w_2) + (x_1 - x_2)i + (y_1 - y_2)j + (z_1 - z_2)k$.

### Constraints
- None

### Time Complexity
- $O(1)$

## Multiplication operators
```cpp
(1) quaternion<T>& q.operator*=(T c);
(2) quaternion<T> operator*(quaternion<T> q, T c);
(3) quaternion<T> operator*(T c, quaternion<T> q);
(4) quaternion<T>& q1.operator*=(quaternion<T> q2);
(5) quaternion<T> operator*(quaternion<T> q1, quaternion<T> q2);
(6) tools::vector3<T> operator*(quaternion<T> q, tools::vector3<T> p);
```

- (1)
    - It updates $q$ to $cw + cxi + cyj + czk$, and returns $q$.
- (2), (3)
    - It returns $cw + cxi + cyj + czk$.
- (4)
    - It updates $q_1$ to $(w_1 w_2 - \mathbb{v}_1 \cdot \mathbb{v}_2) + (w_1 \mathbb{v}_2 + w_2 \mathbb{v}_1 + \mathbb{v}_1 \times \mathbb{v}_2)$ where $\mathbb{v}_1 = (x_1, y_1, z_1)$ and $\mathbb{v}_2 = (x_2, y_2, z_2)$, and returns $q_1$.
- (5)
    - It returns $(w_1 w_2 - \mathbb{v}_1 \cdot \mathbb{v}_2) + (w_1 \mathbb{v}_2 + w_2 \mathbb{v}_1 + \mathbb{v}_1 \times \mathbb{v}_2)$ where $\mathbb{v}_1 = (x_1, y_1, z_1)$ and $\mathbb{v}_2 = (x_2, y_2, z_2)$.
- (6)
    - It applies the rotation which $q$ represents to $\mathbb{p}$. In other words, it returns the imaginary part of $q (\mathbb{p}_x i + \mathbb{p}_y j + \mathbb{p}_z k) q^\ast$, that is $(\cos \theta) \mathbb{p} + (1 - \cos \theta) (\hat{\mathbb{v}} \cdot \mathbb{p}) \hat{\mathbb{v}} + \sin \theta (\hat{\mathbb{v}} \times \mathbb{p})$ where $\theta$ = `q.angle()` and $\hat{\mathbb{v}}$ = `q.axis()`.

### Constraints
- None

### Time Complexity
- $O(1)$

## Division operators
```cpp
(1) quaternion<T>& q.operator/=(T c);
(2) quaternion<T> operator/(quaternion<T> q, T c);
(3) quaternion<T>& q1.operator/=(quaternion<T> q2);
(4) quaternion<T> operator/(quaternion<T> q1, quaternion<T> q2);
```

- (1)
    - It updates $q$ to $\frac{w}{c} + \frac{x}{c}i + \frac{y}{c}j + \frac{z}{c}k$, and returns $q$.
- (2)
    - It returns $\frac{w}{c} + \frac{x}{c}i + \frac{y}{c}j + \frac{z}{c}k$.
- (3)
    - It updates $q_1$ to $q_1 q_2^{-1}$, and returns $q_1$.
- (4)
    - It returns $q_1 q_2^{-1}$.

### Constraints
- (1), (2)
    - $c \neq 0$
- (3), (4)
    - $q_2 \neq 0$

### Time Complexity
- $O(1)$

## Comparison operators
```cpp
(1) bool operator==(quaternion<T> q1, quaternion<T> q2);
(2) bool operator!=(quaternion<T> q1, quaternion<T> q2);
```

- (1)
    - It returns whether $w_1 = w_2 \land x_1 = x_2 \land y_1 = y_2 \land z_1 = z_2$.
- (2)
    - It returns whether $w_1 \neq w_2 \lor x_1 \neq x_2 \lor y_1 \neq y_2 \lor z_1 \neq z_2$.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator&lt;&lt;
```cpp
std::ostream& operator<<(std::ostream& os, const quaternion<T>& self);
```

It is equivalent to the following code.

```cpp
std::ostringstream s;
s.flags(os.flags());
s.imbue(os.getloc());
s.precision(os.precision());
s << '(' << self.x() << ',' << self.y() << ',' << self.z() << ',' << self.w() << ')';
return os << s.str();
```

### Constraints
- None

### Time Complexity
- $O(1)$

## angle_axis
```cpp
quaternion<T> quaternion<T>::angle_axis(T theta, tools::vector3<T> v);
```

It returns a rotation which rotates $\theta$ radians around $\mathbb{v}$.
In other words, it returns $\cos\left(\frac{\theta}{2}\right) + \sin\left(\frac{\theta}{2}\right) \frac{\mathbb{v}}{\|\mathbb{v}\|}$.

### Constraints
- $\mathbb{v} \neq (0, 0, 0)$

### Time Complexity
- $O(1)$

## from_to_rotation
```cpp
quaternion<T> quaternion<T>::from_to_rotation(tools::vector3<T> u, tools::vector3<T> v);
```

It returns a rotation which rotates from $\mathbb{u}$ to $\mathbb{v}$.

### Constraints
- $\mathbb{u} \neq (0, 0, 0)$
- $\mathbb{v} \neq (0, 0, 0)$

### Time Complexity
- $O(1)$

## look_rotation
```cpp
quaternion<T> quaternion<T>::look_rotation(tools::vector3<T> f, tools::vector3<T> u);
```

It returns a rotation with the specified forward direction $\mathbb{f}$ and upwards direction $\mathbb{u}$.
Z axis will be aligned with $\mathbb{f}$, X axis aligned with $\mathbb{f} \times \mathbb{u}$, and Y axis aligned with cross product between Z and X.

### Constraints
- $\mathbb{u} \neq (0, 0, 0)$
- $\mathbb{v} \neq (0, 0, 0)$

### Time Complexity
- $O(1)$

## slerp
```cpp
quaternion<T> quaternion<T>::slerp(quaternion<T> q0, quaternion<T> q1, T t);
```

It spherically interpolates between quaternions $q_0$ and $q_1$ by ratio $t$.

### Constraints
- $\mathbb{q_0} \neq 0$

### Time Complexity
- $O(1)$

## identity
```cpp
quaternion<T> quaternion<T>::identity();
```

It returns $1$.

### Constraints
- None

### Time Complexity
- $O(1)$

## random
```cpp
template <typename R>
quaternion<T> quaternion<T>::random(R& engine);
```

It returns a random rotation.

### Constraints
- `engine` is a pseudorandom number generator.

### Time Complexity
- $O(1)$

## tools::exp
```cpp
quaternion<T> tools::exp(quaternion<T> q);
```

It returns $e^q = \sum_{n = 0}^\infty \frac{q^n}{n!}$.

### Note
$e^q$ is the following quaternion where $\mathbb{v} = xi + yj + zk$.

$$\begin{align*}
\left\{\begin{array}{ll}
e^w \left(\cos|\mathbb{v}| + \sin|\mathbb{v}| \frac{\mathbb{v}}{|\mathbb{v}|}\right) & \text{(if $|\mathbb{v}| > 0$)}\\
e^w & \text{(if $|\mathbb{v}| = 0$)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(1)$

## tools::log
```cpp
quaternion<T> tools::log(quaternion<T> q);
```

It returns $\mathrm{Log}(q)$.
$\mathrm{Log}(q)$ is defined as follows where $\mathbb{v} = xi + yj + zk$.

$$\begin{align*}
\mathrm{Log}(q) &=
\left\{\begin{array}{ll}
\log |q| + \mathrm{atan2}(|\mathbb{v}|, w) \frac{\mathbb{v}}{|\mathbb{v}|} & \text{(if $|\mathbb{v}| > 0$)}\\
\log |q| + \mathrm{atan2}(|\mathbb{v}|, w) i  & \text{(if $|\mathbb{v}| = 0$ and $w \neq 0$)}
\end{array}\right.&
\end{align*}$$

### Note
$\mathrm{Log}(q)$ is one of the quaternions $q'$ such that $e^{q'} = q$ holds.
All the quaternions $q'$ such that $e^{q'} = q$ holds can be written in the following form for any unit three-dimensional vector $\hat{\mathbb{u}}$ and any integer $k$.

$$\begin{align*}
\left\{\begin{array}{ll}
\log |q| + (\mathrm{atan2}(|\mathbb{v}|, w) + 2k \pi) \frac{\mathbb{v}}{|\mathbb{v}|} & \text{(if $|\mathbb{v}| > 0$)}\\
\log |q| + (\mathrm{atan2}(|\mathbb{v}|, w) + 2k \pi) \hat{\mathbb{u}} & \text{(if $|\mathbb{v}| = 0$ and $w \neq 0$)}
\end{array}\right.&
\end{align*}$$

### Constraints
- $q \neq 0$

### Time Complexity
- $O(1)$

## tools::pow
```cpp
quaternion<T> tools::pow(quaternion<T> q, T t);
```

It returns $q^t$.
$q^t$ is defined as $e^{t \mathrm{Log}(q)}$.

### Constraints
- $q \neq 0$ or $t \neq 0$

### Time Complexity
- $O(1)$
