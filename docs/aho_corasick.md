---
title: Aho-Corasick automaton
documentation_of: //tools/aho_corasick.hpp
---

It builds the trie of given strings $S_0, S_1, \ldots, S_{N - 1}$ and decorates each node with auxiliary information (failure links, output links, transition table, and a few aggregate counts). The class itself does not assume any particular application; it is a general-purpose data structure on top of which various string-processing tasks (such as multi-pattern substring search) can be implemented.

The notation used throughout this page follows the formulation in [Library Checker: Aho-Corasick](https://judge.yosupo.jp/problem/aho_corasick):

- Let $P_{i, j}$ be the prefix of $S_i$ of length $j$ ($0 \leq j \leq \|S_i\|$).
- Let $P = \\{P_{i, j} \mid 0 \leq i < N, 0 \leq j \leq \|S_i\|\\}$ and $n = \|P\|$.
- The **trie** of $(S_0, \ldots, S_{N - 1})$ has $n$ nodes, one per element of $P$. Each node $v$ corresponds to a string $\mathrm{str}(v) \in P$, and $\mathrm{str}(0)$ is the empty string (the root).
- $\sigma$ is the alphabet size (the template parameter `AlphabetSize`).

### License
- CC0

### Author
- anqooqie

## Member type: node

`aho_corasick<Encode, AlphabetSize>::node` describes a single trie node. After `build()` is called, all fields hold the values described below.

```cpp
struct node {
  int parent;
  std::array<int, AlphabetSize> children;
  int failure_link;
  std::array<int, AlphabetSize> next;
  std::vector<int> pattern_indices;
  int output_link;
  int pattern_count_sum;
};
```

### parent
The trie parent of $v$, that is, the node corresponding to $\mathrm{str}(v)$ with its last character removed. For the root, `parent` is $-1$.

### children
`children[i]` is the trie child of $v$ obtained by appending the character whose `Encode` value is $i$ to $\mathrm{str}(v)$. If no such child exists in the trie, `children[i]` is $-1$.

This describes the trie shape only; for transitions used while consuming an arbitrary text, see `next`.

### failure_link
The node corresponding to the longest proper suffix of $\mathrm{str}(v)$ that belongs to $P$. For the root, `failure_link` is $-1$.

### next
Let $w$ be $\mathrm{str}(v)$ followed by the character whose `Encode` value is $i$. Then `next[i]` is the node corresponding to the longest suffix of $w$ that belongs to $P$. `next[i]` is always a valid node index; it is never $-1$.

### pattern_indices
The list of indices $k$ such that $S_k = \mathrm{str}(v)$. Empty if no $S_k$ ends at $v$. If the same string is registered multiple times via `add_pattern`, every registration appears as a separate entry.

### output_link
The node corresponding to the longest proper suffix of $\mathrm{str}(v)$ that equals some $S_k$, or $-1$ if no proper suffix of $\mathrm{str}(v)$ matches any $S_k$. Even non-root nodes may have `output_link == -1` (e.g. when the failure-link chain from $v$ never visits a node with non-empty `pattern_indices`).

### pattern_count_sum
The number of patterns that are suffixes (proper or not) of $\mathrm{str}(v)$, equivalently $\sum_{k = 0}^{N - 1} [S_k \text{ is a suffix of } \mathrm{str}(v)]$. Duplicate registrations of the same string are counted with multiplicity.

## Constructor
```cpp
template <auto Encode = [](char c) { return c - 'a'; }, int AlphabetSize = 26>
requires std::is_invocable_r_v<int, decltype(Encode), char> && (AlphabetSize > 0)
aho_corasick<Encode, AlphabetSize> ac();
```

It creates an empty automaton.

The template parameters are:
- `Encode`: a callable that maps a `char` to an `int` in $[0, $`AlphabetSize`$)$. Defaults to `[](char c) { return c - 'a'; }`.
- `AlphabetSize`: the alphabet size $\sigma$. Defaults to $26$.

### Constraints
- None

### Time Complexity
- $O(1)$

## encode
```cpp
int ac.encode(char c);
```

It returns `Encode(c)`.

### Constraints
- $0 \leq$ `Encode(c)` $<$ `AlphabetSize`

### Time Complexity
- $O(1)$ (assuming `Encode` is $O(1)$)

## alphabet_size
```cpp
int ac.alphabet_size();
```

It returns `AlphabetSize`.

### Constraints
- None

### Time Complexity
- $O(1)$

## add_pattern
```cpp
int ac.add_pattern(std::string_view pattern);
```

It registers `pattern` as $S_i$, where $i$ is the index returned. Indices are assigned sequentially starting from $0$.

### Constraints
- `build()` has not been called.
- $0 \leq$ `Encode(pattern[j])` $<$ `AlphabetSize` for every $0 \leq j < \|S_i\|$ where $\|S_i\|$ is the length of `pattern`.

### Time Complexity
- $O(\|S_i\|)$ where $\|S_i\|$ is the length of `pattern`.

## get_pattern
```cpp
const std::string& ac.get_pattern(int k);
```

It returns $S_k$.

### Constraints
- $0 \leq k < N$

### Time Complexity
- $O(1)$

## patterns
```cpp
const std::vector<std::string>& ac.patterns();
```

It returns the list $(S_0, S_1, \ldots, S_{N - 1})$.

### Constraints
- None

### Time Complexity
- $O(1)$

## build
```cpp
void ac.build();
```

It builds the trie of $(S_0, S_1, \ldots, S_{N - 1})$ and populates every field of every `node`.

After `build()`, no further patterns may be added.

### Constraints
- `build()` has not been called.

### Time Complexity
- $O\left(\sigma \left(1 + \sum_{i = 0}^{N - 1} \|S_i\|\right)\right)$

## get_node
```cpp
const node& ac.get_node(int v);
```

It returns the node $v$.

### Constraints
- `build()` has been called.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## nodes
```cpp
const std::vector<node>& ac.nodes();
```

It returns all nodes, indexed by $0, 1, \ldots, n - 1$.

### Constraints
- `build()` has been called.

### Time Complexity
- $O(1)$

## pattern_to_node
```cpp
int ac.pattern_to_node(int k);
```

It returns the node $v$ such that $\mathrm{str}(v) = S_k$.

### Constraints
- `build()` has been called.
- $0 \leq k < N$

### Time Complexity
- $O(1)$

## bfs_ordered
```cpp
const std::vector<int>& ac.bfs_ordered();
```

It returns all nodes in breadth-first order over the trie, starting from the root.

This is useful when one needs to process nodes in a direction along the trie (e.g. aggregating values from leaves toward the root by reversing this list).

### Constraints
- `build()` has been called.

### Time Complexity
- $O(1)$

## Note on matching

This class deliberately does not provide a built-in matching function such as `search(text)` or `count_occurrences(text)`. The intended usage is to drive the automaton manually with `next` and to aggregate per-application data on top of the structure. A typical inner loop is:

```cpp
int v = 0;
for (const char c : text) {
  v = ac.get_node(v).next[ac.encode(c)];
  // aggregate using ac.get_node(v).pattern_indices, pattern_count_sum, output_link, etc.
}
```

For complete examples, see the test files under `tests/aho_corasick/`.
