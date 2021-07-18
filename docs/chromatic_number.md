---
title: Chromatic number
documentation_of: //tools/chromatic_number.hpp
---

It calculates the chromatic number of a given graph which is not necessarily simple.

### References
- [AOJ 2136 Webby Subway (JAG 夏合宿 2008 day2-F) - けんちょんの競プロ精進記録](https://drken1215.hatenablog.com/entry/2019/01/16/030000)

### License
- unknown

### Author
- drken

## Constructor
```cpp
chromatic_number graph(::std::size_t n);
```

It creates a graph with $n$ vertices and $0$ edges.

### Constraints
- $1 \leq n \leq 63$

### Time Complexity
- $O(n)$

## add_edge
```cpp
void graph.add_edge(::std::size_t s, ::std::size_t t);
```

It adds a edge from $s$ to $t$.

### Constraints
- $0 \leq s < n$
- $0 \leq t < n$

### Time Complexity
- $O(1)$

## query
```cpp
::std::int_fast64_t graph.query();
```

It returns the chromatic number of the graph.

### Constraints
- None

### Time Complexity
- $O(2^n n)$
