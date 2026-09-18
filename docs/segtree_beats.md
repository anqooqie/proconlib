---
title: Segment tree beats
documentation_of: //tools/segtree_beats.hpp
---

```cpp
template <class S, auto op, auto e, class F, auto mapping, auto composition, auto id>
class segtree_beats : public atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;
```

It is `atcoder::lazy_segtree`, but the set $F$ of mappings does not need to distribute over $\mathrm{op}$, i.e. $f(x \cdot y) = f(x) \cdot f(y)$ does not need to hold for all $f \in F$ and $x, y \in S$.
Instead, `mapping` is allowed to give up.

When `mapping(f, x)` cannot compute $f(x)$ exactly, it returns a value whose `fail` is `true`.
Then this class discards the value, pushes the lazy value of the node, which already contains $f$, down to its two children, and recomputes the value of the node by `op` from the recomputed values of the children.
Since a child covers a shorter interval than its parent, the recursion eventually reaches nodes on which `mapping` succeeds.
`fail` is examined only on inner nodes, never on leaves.

It is a general framework, and the computation it can perform is determined by what you put into $S$ and $F$.
`tools::preset_segtree_beats` is a ready-made instantiation for the most frequent case, namely range chmin, range chmax, range add, range min, range max and range sum, but this class is not limited to it.

Its public interface is entirely inherited from `atcoder::lazy_segtree`.

### Constraints
- `S` has a public member variable `bool fail`.
- `e()` returns a value whose `fail` is `false`.
- `op(x, y)` returns a value whose `fail` is `false` if neither `x.fail` nor `y.fail` is `true`.
- `mapping(f, x)` returns a value whose `fail` is `true` only if it cannot compute $f(x)$ exactly.
- `mapping(f, x)` returns a value whose `fail` is `false` if `x` is the value of a single element.
- $f(x \cdot y) = f(x) \cdot f(y)$ holds for all $f \in F$ and $x, y \in S$ such that `mapping(f, op(x, y))` returns a value whose `fail` is `false`.
- The other constraints of `atcoder::lazy_segtree` hold.

### Time Complexity
- This class guarantees no bound. It depends on how often `mapping` gives up, which you have to prove for each specific $S$, $F$ and `mapping`. When they are designed well, the total number of giving up is typically $O((n + q) \log n)$ or $O\left((n + q) \log^2 n\right)$ for $n$ elements and $q$ operations.

### References
- [atcoder::lazy_segtree に1行書き足すだけの抽象化 Segment Tree Beats - ひとなので](https://rsm9.hatenablog.com/entry/2021/02/01/220408)
- [Segment Tree Beats (based on atcoder::lazy_segtree) \| cplib-cpp](https://hitonanode.github.io/cplib-cpp/segmenttree/acl_beats.hpp.html)
- [Lazy Segtree \| AtCoder Library](https://atcoder.github.io/ac-library/production/document_en/lazysegtree.html)

### License
- MIT

### Author
- hitonanode
