#ifndef TOOLS_LCA_HPP
#define TOOLS_LCA_HPP

#include <cstdint>
#include <vector>
#include <cstddef>
#include <cassert>
#include <numeric>
#include <limits>
#include <stack>
#include <utility>
#include <algorithm>
#include <tuple>
#include "tools/ceil.hpp"
#include "tools/less_by.hpp"
#include "tools/ceil_log2.hpp"
#include "tools/floor_log2.hpp"
#include "tools/pow2.hpp"

namespace tools {
  class lca {
    using u32 = ::std::uint32_t;
    ::std::vector<::std::vector<u32>> m_graph;
    ::std::vector<u32> m_depth;
    ::std::vector<u32> m_tour;
    ::std::vector<u32> m_in;
    u32 m_block_size;
    ::std::vector<::std::vector<u32>> m_sparse_table;
    ::std::vector<::std::vector<::std::vector<u32>>> m_lookup_table;
    ::std::vector<u32> m_patterns;

    bool built() const {
      return !this->m_depth.empty();
    }

    u32 nblocks() const {
      return ::tools::ceil(this->m_tour.size(), this->m_block_size);
    }

    auto less_by_depth() const {
      return ::tools::less_by([&](const auto v) { return this->m_depth[v]; });
    }

  public:
    lca() = default;
    explicit lca(const ::std::size_t n) : m_graph(n) {
      assert(n >= 1);
    }

    ::std::size_t size() const {
      return this->m_graph.size();
    }

    void add_edge(const ::std::size_t u, const ::std::size_t v) {
      assert(!this->built());
      assert(u < this->size());
      assert(v < this->size());
      assert(u != v);
      this->m_graph[u].push_back(v);
      this->m_graph[v].push_back(u);
    }

    void build(const ::std::size_t r) {
      assert(!this->built());
      assert(::std::accumulate(this->m_graph.begin(), this->m_graph.end(), static_cast<::std::size_t>(0), [](const auto sum, const auto& neighbors) { return sum + neighbors.size(); }) == 2 * (this->size() - 1));

      this->m_depth.assign(this->size(), ::std::numeric_limits<u32>::max());
      this->m_tour.resize(2 * this->size() - 1);
      this->m_in.resize(this->size());

      u32 t = 0;
      ::std::stack<::std::pair<u32, u32>> stack;
      stack.emplace(r, 0);
      while (!stack.empty()) {
        const auto [here, depth] = stack.top();
        stack.pop();
        this->m_tour[t] = here;
        if (this->m_depth[here] == ::std::numeric_limits<u32>::max()) {
          this->m_depth[here] = depth;
          this->m_in[here] = t;
          for (const auto next : this->m_graph[here]) {
            if (this->m_depth[next] == ::std::numeric_limits<u32>::max()) {
              stack.emplace(here, depth);
              stack.emplace(next, depth + 1);
            }
          }
        }
        ++t;
      }

      if (this->size() > 1) {
        this->m_tour.pop_back();
      }

      this->m_block_size = ::std::max<u32>(1, ::tools::ceil(::tools::ceil_log2(this->m_tour.size()), 2));
      this->m_sparse_table.resize(::tools::floor_log2(this->nblocks()) + 1);
      this->m_sparse_table[0].resize(this->nblocks());
      for (u32 b = 0; (b + 1) * this->m_block_size <= this->m_tour.size(); ++b) {
        const auto l = b * this->m_block_size;
        const auto r = ::std::min<u32>(l + this->m_block_size, this->m_tour.size());
        this->m_sparse_table[0][b] = *::std::min_element(this->m_tour.begin() + l, this->m_tour.begin() + r, this->less_by_depth());
      }
      for (u32 h = 1; h < this->m_sparse_table.size(); ++h) {
        this->m_sparse_table[h].resize(this->nblocks() + UINT32_C(1) - (UINT32_C(1) << h));
        for (u32 b = 0; b < this->m_sparse_table[h].size(); ++b) {
          this->m_sparse_table[h][b] = ::std::min(this->m_sparse_table[h - 1][b], this->m_sparse_table[h - 1][b + (UINT32_C(1) << (h - 1))], this->less_by_depth());
        }
      }

      this->m_lookup_table.resize(::tools::pow2(this->m_block_size - 1));
      for (u32 p = 0; p < this->m_lookup_table.size(); ++p) {
        this->m_lookup_table[p].resize(this->m_block_size + 1);
        for (u32 l = 0; l <= this->m_block_size; ++l) {
          this->m_lookup_table[p][l].resize(this->m_block_size + 1);
        }

        ::std::vector<u32> partial_sum(this->m_block_size);
        partial_sum[0] = this->m_block_size;
        for (u32 i = 1; i < this->m_block_size; ++i) {
          partial_sum[i] = partial_sum[i - 1] - UINT32_C(1) + (((p >> (i - 1)) & UINT32_C(1)) << 1);
        }

        for (u32 l = 0; l < this->m_block_size; ++l) {
          this->m_lookup_table[p][l][l + 1] = l;
          for (u32 r = l + 2; r <= this->m_block_size; ++r) {
            this->m_lookup_table[p][l][r] = ::std::min(this->m_lookup_table[p][l][r - 1], r - 1, ::tools::less_by([&](const auto i) { return partial_sum[i]; }));
          }
        }
      }

      this->m_patterns.resize(this->nblocks());
      for (u32 b = 0; b * this->m_block_size < this->m_tour.size(); ++b) {
        const auto l = b * this->m_block_size;
        const auto r = ::std::min<u32>(l + this->m_block_size, this->m_tour.size());
        this->m_patterns[b] = 0;
        for (u32 i = l; i + 1 < r; ++i) {
          this->m_patterns[b] |= static_cast<u32>(this->m_depth[this->m_tour[i]] < this->m_depth[this->m_tour[i + 1]]) << (i - l);
        }
      }
    }

    ::std::size_t depth(const ::std::size_t v) const {
      assert(this->built());
      assert(v < this->size());
      return this->m_depth[v];
    }

    ::std::size_t query(::std::size_t u, ::std::size_t v) const {
      assert(this->built());
      assert(u < this->size());
      assert(v < this->size());

      ::std::tie(u, v) = ::std::minmax({u, v}, ::tools::less_by([&](const auto w) { return this->m_in[w]; }));

      const auto l = this->m_in[u];
      const auto r = this->m_in[v] + UINT32_C(1);
      const auto bl = ::tools::ceil(l, this->m_block_size);
      const auto br = r / this->m_block_size;
      u32 lca;
      if (br < bl) {
        lca = this->m_tour[br * this->m_block_size + this->m_lookup_table[this->m_patterns[br]][l % this->m_block_size][r % this->m_block_size]];
      } else {
        lca = u;
        if (bl < br) {
          const auto h = ::tools::floor_log2(br - bl);
          lca = ::std::min(this->m_sparse_table[h][bl], this->m_sparse_table[h][br - (UINT32_C(1) << h)], this->less_by_depth());
        }
        if (l < bl * this->m_block_size) {
          lca = ::std::min(lca, this->m_tour[(bl - UINT32_C(1)) * this->m_block_size + this->m_lookup_table[this->m_patterns[bl - 1]][l % this->m_block_size][this->m_block_size]], this->less_by_depth());
        }
        if (br * this->m_block_size < r) {
          lca = ::std::min(lca, this->m_tour[br * this->m_block_size + this->m_lookup_table[this->m_patterns[br]][0][r % this->m_block_size]], this->less_by_depth());
        }
      }

      return lca;
    }
  };
}

#endif
