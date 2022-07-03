---
title: Solver of minimum-cost flow problem
documentation_of: //tools/mcf_graph.hpp
---

It solves Minimum-cost flow problem.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
mcf_graph<Cap, Cost> graph(int n);
```

It creates a directed graph with $n$ vertices and $0$ edges.
`Cap` and `Cost` are the type of the capacity and the cost, respectively.

### Constraints
- $0 \leq n \leq 10^8$
- `Cap` and `Cost` are `int` or `long long`.

### Time Complexity
- $O(n)$

## add_edge
```cpp
int graph.add_edge(int from, int to, Cap cap, Cost cost);
```

It adds an edge oriented from `from` to `to` with capacity `cap` and cost `cost`.
It returns an integer $k$ such that this is the $k$-th edge that is added.

### Constraints
- $0 \leq \mathrm{from, to} < n$
- $0 \leq \mathrm{cap}$

### Time Complexity
- $O(1)$ amortized

## flow
```cpp
(1) std::pair<Cap, Cost> graph.flow(int s, int t);
(2) std::pair<Cap, Cost> graph.flow(int s, int t, Cap flow_limit);
```

- It augments the flow from $s$ to $t$ as much as possible. It returns the amount of the flow and the cost.
- (1) It augments the $s-t$ flow as much as possible.
- (2) It augments the $s-t$ flow as much as possible, until reaching the amount of `flow_limit`.

### Constraints
- same as `slope`.

### Time Complexity
- same as `slope`.

## slope
```cpp
(1) std::vector<std::pair<Cap, Cost>> graph.slope(int s, int t);
(2) std::vector<std::pair<Cap, Cost>> graph.slope(int s, int t, Cap flow_limit);
```

Let $g$ be a function such that $g(x)$ is the cost of the minimum cost $s-t$ flow when the amount of the flow is exactly $x$.
$g$ is known to be piecewise linear.
It returns $g$ as the list of the changepoints, that satisfies the followings.

- The first element of the list is $(0, g(0))$.
- No three changepoints are on the same line.
- (1) The last element of the list is $(x, g(x))$, where $x$ is the maximum amount of the $s-t$ flow.
- (2) The last element of the list is $(y, g(y))$, where $y = \min(x, \mathrm{flow\\_limit})$.

### Constraints
Let $x$ be the maximum absolute value of cost among all edges.

- $s \neq t$
- The total amount of the flow is in `Cap`.
- The total cost of the flow is in `Cost`.
- (Cost : `int`): $0 \leq nx \leq 2 \times 10^9 + 1000$
- (Cost : `long long`): $0 \leq nx \leq 8 \times 10^{18} + 1000$
- (2) If you call `flow` or `slope` multiple times, `flow_limit` is greater than or equal to `flow_limit` in the last call of `flow` or `slope`.

### Time Complexity
- (No edges with negative cost or DAG): $O(F (n + m) \log n)$, where $F$ is the amount of the flow and $m$ is the number of added edges.
- (Otherwise): $O(Nnm + nm + F (n + m) \log n)$, where $N$ is the number of negative cycles, $F$ is the amount of the flow and $m$ is the number of added edges.

## edges
```cpp
struct edge<Cap, Cost> {
  int from, to;
  Cap cap, flow;
  Cost cost;
};

(1) mcf_graph<Cap, Cost>::edge graph.get_edge(int i);
(2) std::vector<mcf_graph<Cap, Cost>::edge> graph.edges();
```

- It returns the current internal state of the edges.
- The edges are ordered in the same order as added by `add_edge`.

### Constraints
- $0 \leq i < m$

### Time Complexity
- (1): $(O(1))$
- (2): $(O(m))$, where $m$ is the number of added edges.
