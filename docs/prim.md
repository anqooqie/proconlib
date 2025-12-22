---
title: Prim's algorithm
documentation_of: //tools/prim.hpp
---

It constructs minimum spanning trees for each connected components of a given undirected graph which is not necessarily simple based on Prim's algorithm.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
prim<T> graph(int n);
```

It creates an undirected graph with $n$ vertices and $0$ edges.
The type parameter `<T>` represents the type of the cost.

### Constraints
- $n \geq 0$

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

## add_edge
```cpp
int graph.add_edge(int u, int v, T w);
```

It adds an undirected edge between $u$ and $v$ with cost `w`.
It returns an integer $k$ such that this is the $k$-th ($0$ indexed) edge that is added.

### Constraints
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(1)$ amortized

## get_edge
```cpp
struct edge {
  int from;
  int to;
  T cost;
};
const edge& graph.get_edge(int k);
```

It returns the $k$-th ($0$ indexed) edge.

### Constraints
- $0 \leq k < \|E\|$ where $\|E\|$ is the number of edges

### Time Complexity
- $O(1)$

## edges
```cpp
const std::vector<edge>& graph.edges();
```

It returns all the edges in the graph.
The edges are ordered in the same order as added by `add_edge`.

### Constraints
- None

### Time Complexity
- $O(1)$

## query
```cpp
struct minimum_spanning_tree {
  T cost();
  std::vector<int> edge_ids();
};
struct minimum_spanning_forest {
  minimum_spanning_tree get_mst(int k);
  std::vector<minimum_spanning_tree> msts();
  int mst_id(int v);
};

(1) std::vector<T> graph.query();
(2) std::vector<T> graph.query<false>();
(3) minimum_spanning_forest graph.query<true>();
```

- (1), (2)
    - It is identical to `graph.query<true>().msts() | std::views::transform([](const auto& mst) { return mst.cost(); }) | std::ranges::to<std::vector>()`.
- (3)
    - It returns the information about the minimum spanning trees for each connected components of the graph.
    - The order of the connected components is undefined.

### Constraints
- None

### Time Complexity
- $O((n + \|E\|) \log n)$ where $\|E\|$ is the number of edges

## minimum_spanning_forest::get_mst
```cpp
minimum_spanning_tree msf.get_mst(int k);
```

It returns the minimum spanning tree for the $k$-th connected component of the graph.

### Constraints
- $0 \leq k < $ `msf.msts().size()`

### Time Complexity
- $O(1)$

## minimum_spanning_forest::msts
```cpp
std::vector<minimum_spanning_tree> msf.msts();
```

It returns the minimum spanning trees for each connected components of the graph.
It is guaranteed that `msf.msts()[k]` is the same as `msf.get_mst(k)`.

### Constraints
- None

### Time Complexity
- $O(1)$

## minimum_spanning_forest::mst_id
```cpp
int msf.mst_id(int v);
```

It returns $k$ such that the $k$-th connected component contains vertex $v$.

### Constraints
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## minimum_spanning_tree::cost
```cpp
T mst.cost();
```

It returns the total cost of the minimum spanning tree.

### Constraints
- None

### Time Complexity
- $O(1)$

## minimum_spanning_tree::cost
```cpp
std::vector<int> mst.edge_ids();
```

It returns the indices of each edge in the minimum spanning tree.

### Constraints
- None

### Time Complexity
- $O(1)$
