---
title: Shortest path tree
documentation_of: //tools/shortest_path_tree.hpp
---

It represents the answer to the single source shortest path problem.
Let $T$ be the set of vertices whose shortest distance from vertex $s$ is finite, then it is known that the graph constructed using only the edges included in the shortest path from vertex $s$ to vertex $t \in T$ is a rooted tree with root $s$.
It is the data structure that combines the rooted tree (called the shortest path tree) and the vertices not included in $T$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
shortest_path_tree<Cost, F> graph(std::ranges::range d, std::rangs::range p, F f);
```

Given $(d_0, d_1, \ldots, d_{n - 1})$, the shortest distance from a single source to vertex $v$ $(0 \leq v < n)$, and $(p_0, p_1, \ldots, p_{n - 1})$, the edge number from the parent of vertex $v$ to vertex $v$ in the shortest path tree $(0 \leq v < n)$, it creates a data structure representing the answer to the single source shortest path problem.
If vertex $v$ is the root of the shortest path tree or is not in the shortest path tree, $p_v$ must be $-1$.

$f$ is a function to find the parent of vertex $v$ in the shortest path tree.
For all $v$ such that vertex $v$ is a vertex in the shortest path tree but not the root, $f(p_v, v)$ must return the parent of $v$.

The type parameter `<Cost>` represents the type of the shortest distance.

### Constraints
- $\|d\| = \|p\|$ (hereinafter referred to as $n$)
- $\forall p_v \in p. p_v \geq -1$
- $\forall p_v \in p. (p_v \geq 0 \Rightarrow 0 \leq f(p_v, v) < n)$
- For all $v$ such that $0 \leq v < n$, `while (p[v] >= 0) v = f(p[v], v);` halts.

### Time Complexity
- $O(n)$

## size
```cpp
int graph.size();
```

It returns $n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## dist
```cpp
(1) std::vector<Cost> graph.dist();
(2) Cost graph.dist(int v);
```

- (1)
    - It returns $d$.
- (2)
    - It returns $d_v$.

### Constraints
- (1)
    - None
- (2)
    - $0 \leq v < n$

### Time Complexity
- $O(1)$

## from_vertex
```cpp
int graph.from_vertex(int v);
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
f(p_v, v) & \text{(if $p_v \geq 0$)}\\
-1 & \text{(if $p_v = -1$)}
\end{array}\right.&
\end{align*}$$

### Constraints
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## from_edge_id
```cpp
int graph.from_edge_id(int v);
```

It returns $p_v$.

### Constraints
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## vertex_path
```cpp
std::vector<int> graph.vertex_path(int v);
```

If $d_v$ is finite, it returns the vertices in the shortest path from the single source to vertex $v$, in the order of their appearance in the path.
If $d_v$ is not finite, it returns an empty vector.

### Constraints
- $0 \leq v < n$

### Time Complexity
- $O(n)$

## edge_id_path
```cpp
std::vector<int> graph.edge_id_path(int v);
```

If $d_v$ is finite, it returns the edge numbers in the shortest path from the single source to vertex $v$, in the order of their appearance in the path.
If $d_v$ is not finite, it returns an empty vector.

### Constraints
- $0 \leq v < n$

### Time Complexity
- $O(n)$
