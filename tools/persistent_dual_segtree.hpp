#ifndef TOOLS_PERSISTENT_DUAL_SEGTREE_HPP
#define TOOLS_PERSISTENT_DUAL_SEGTREE_HPP

#include <cstddef>
#include <limits>
#include <vector>
#include <cassert>
#include <algorithm>
#include "tools/fix.hpp"
#include "tools/pow2.hpp"
#include "tools/ceil_log2.hpp"

namespace tools {

  template <typename M>
  class persistent_dual_segtree {
  private:
    using T = typename M::T;

    struct node {
      T lazy;
      ::std::size_t left;
      ::std::size_t right;
    };

  public:
    class buffer {
    private:
      ::std::vector<::tools::persistent_dual_segtree<M>::node> m_nodes;

    public:
      buffer() = default;
      buffer(const ::tools::persistent_dual_segtree<M>::buffer&) = default;
      buffer(::tools::persistent_dual_segtree<M>::buffer&&) = default;
      ~buffer() = default;
      ::tools::persistent_dual_segtree<M>::buffer& operator=(const ::tools::persistent_dual_segtree<M>::buffer&) = default;
      ::tools::persistent_dual_segtree<M>::buffer& operator=(::tools::persistent_dual_segtree<M>::buffer&&) = default;

      friend ::tools::persistent_dual_segtree<M>;
    };

  private:
    static const ::std::size_t EMPTY = ::std::numeric_limits<::std::size_t>::max();
    ::tools::persistent_dual_segtree<M>::buffer *m_buffer;
    ::std::size_t m_size;
    ::std::size_t m_root;

    persistent_dual_segtree(::tools::persistent_dual_segtree<M>::buffer * const buffer, const ::std::size_t size, const ::std::size_t root) : m_buffer(buffer), m_size(size), m_root(root) {
    }

  public:
    persistent_dual_segtree() = default;
    persistent_dual_segtree(const ::tools::persistent_dual_segtree<M>&) = default;
    persistent_dual_segtree(::tools::persistent_dual_segtree<M>&&) = default;
    ~persistent_dual_segtree() = default;
    ::tools::persistent_dual_segtree<M>& operator=(const ::tools::persistent_dual_segtree<M>&) = default;
    ::tools::persistent_dual_segtree<M>& operator=(::tools::persistent_dual_segtree<M>&&) = default;

    persistent_dual_segtree(::tools::persistent_dual_segtree<M>::buffer& buffer, const ::std::size_t n) : m_buffer(&buffer), m_size(n), m_root(EMPTY) {
      if (n == 0) return;

      this->m_root = ::tools::fix([&](auto&& dfs, const ::std::size_t l, const ::std::size_t r) -> ::std::size_t {
        ::tools::persistent_dual_segtree<M>::node node;
        node.lazy = M::e();
        if (r - l == 1) {
          node.left = EMPTY;
          node.right = EMPTY;
        } else {
          const auto mid = l + ::tools::pow2(::tools::ceil_log2(r - l) - 1);
          node.left = dfs(l, mid);
          node.right = dfs(mid, r);
        }

        buffer.m_nodes.push_back(node);
        return buffer.m_nodes.size() - 1;
      })(0, n);
    }

    ::std::size_t size() const {
      return this->m_size;
    }

    ::tools::persistent_dual_segtree<M> apply(const ::std::size_t l, const ::std::size_t r, const T& x) {
      assert(l <= r && r <= this->m_size);
      if (l == r) return *this;
      if (x == M::e()) return *this;

      return ::tools::persistent_dual_segtree<M>(this->m_buffer, this->m_size, ::tools::fix(
        [&](auto&& dfs, const ::std::size_t old_node_id, const ::std::size_t ll, const ::std::size_t rr, const T& xx) -> ::std::size_t {
          ::tools::persistent_dual_segtree<M>::node new_node;
          const auto new_lazy = M::op(xx, this->m_buffer->m_nodes[old_node_id].lazy);
          if (::std::min(rr, r) <= ::std::max(ll, l)) {
            new_node.lazy = new_lazy;
            new_node.left = this->m_buffer->m_nodes[old_node_id].left;
            new_node.right = this->m_buffer->m_nodes[old_node_id].right;
          } else if (l <= ll && rr <= r) {
            new_node.lazy = M::op(x, new_lazy);
            new_node.left = this->m_buffer->m_nodes[old_node_id].left;
            new_node.right = this->m_buffer->m_nodes[old_node_id].right;
          } else {
            const auto mid = ll + ::tools::pow2(::tools::ceil_log2(rr - ll) - 1);
            new_node.lazy = M::e();
            new_node.left = dfs(this->m_buffer->m_nodes[old_node_id].left, ll, mid, new_lazy);
            new_node.right = dfs(this->m_buffer->m_nodes[old_node_id].right, mid, rr, new_lazy);
          }

          this->m_buffer->m_nodes.push_back(new_node);
          return this->m_buffer->m_nodes.size() - 1;
        }
      )(this->m_root, 0, this->m_size, M::e()));
    }

    T get(const ::std::size_t i) const {
      assert(i < this->m_size);

      return ::tools::fix([&](auto&& dfs, const ::std::size_t node_id, const ::std::size_t l, const ::std::size_t r, const T& x) -> T {
        const auto& node = this->m_buffer->m_nodes[node_id];
        const auto new_lazy = M::op(x, node.lazy);
        if (r - l == 1) return new_lazy;

        const auto mid = l + ::tools::pow2(::tools::ceil_log2(r - l) - 1);
        if (i < mid) {
          return dfs(node.left, l, mid, new_lazy);
        } else {
          return dfs(node.right, mid, r, new_lazy);
        }
      })(this->m_root, 0, this->m_size, M::e());
    }
  };
}

#endif
