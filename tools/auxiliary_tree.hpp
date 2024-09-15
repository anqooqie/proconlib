#ifndef TOOLS_AUXILIARY_TREE_HPP
#define TOOLS_AUXILIARY_TREE_HPP

#include <cstddef>
#include <vector>
#include <utility>
#include <algorithm>
#include <stack>
#include <limits>
#include <iterator>
#include <type_traits>
#include "tools/lca.hpp"
#include "tools/less_by.hpp"
#include "tools/less_by_first.hpp"

namespace tools {
  class auxiliary_tree {
    ::tools::lca m_lca;

  public:
    auxiliary_tree() = default;
    explicit auxiliary_tree(const ::std::size_t n) : m_lca(n) {
    }

    ::std::size_t size() const {
      return this->m_lca.size();
    }

    void add_edge(const ::std::size_t u, const ::std::size_t v) {
      this->m_lca.add_edge(u, v);
    }

    void build(const ::std::size_t r) {
      this->m_lca.build(r);
    }

    ::std::size_t depth(const ::std::size_t v) const {
      return this->m_lca.depth(v);
    }

    ::std::size_t lca(const ::std::size_t u, const ::std::size_t v) const {
      return this->m_lca.query(u, v);
    }

    class query_result {
      ::std::vector<::std::pair<::std::size_t, ::std::size_t>> m_parent;
      ::std::vector<::std::vector<::std::size_t>> m_children;
      ::std::size_t m_root;

      template <typename InputIterator>
      query_result(const ::tools::auxiliary_tree& tree, const InputIterator begin, const InputIterator end) {
        ::std::vector<::std::size_t> X(begin, end);
        assert(!X.empty());
        ::std::sort(X.begin(), X.end(), ::tools::less_by([&](const auto v) { return tree.m_lca.internal_in(v); }));

        ::std::stack<::std::size_t> stack;
        auto it = X.begin();
        stack.push(*(it++));
        for (; it != X.end(); ++it) {
          const auto w = tree.lca(stack.top(), *it);
          while (!stack.empty() && tree.depth(w) < tree.depth(stack.top())) {
            const auto u = stack.top();
            stack.pop();
            this->m_parent.emplace_back(u, w);
            if (!stack.empty() && tree.depth(w) < tree.depth(stack.top())) {
              this->m_parent.back().second = stack.top();
            }
          }
          if (stack.empty() || stack.top() != w) {
            stack.push(w);
          }
          stack.push(*it);
        }
        while (!stack.empty()) {
          const auto u = stack.top();
          stack.pop();
          if (stack.empty()) {
            this->m_parent.emplace_back(u, ::std::numeric_limits<::std::size_t>::max());
            this->m_root = u;
          } else {
            this->m_parent.emplace_back(u, stack.top());
          }
        }

        ::std::sort(this->m_parent.begin(), this->m_parent.end(), ::tools::less_by_first{});

        this->m_children.resize(this->m_parent.size());
        for (const auto& [v, p] : this->m_parent) {
          if (v != this->m_root) {
            const auto it = ::std::lower_bound(this->m_parent.begin(), this->m_parent.end(), ::std::make_pair(p, ::std::numeric_limits<::std::size_t>::max()), ::tools::less_by_first{});
            assert(it != this->m_parent.end());
            assert(it->first == p);
            this->m_children[::std::distance(this->m_parent.begin(), it)].push_back(v);
          }
        }
      }

    public:
      class vertices_iterable {
        query_result const *m_qr;

      public:
        class iterator {
          query_result const *m_qr;
          ::std::size_t m_i;

        public:
          using difference_type = ::std::ptrdiff_t;
          using value_type = ::std::size_t;
          using reference = const ::std::size_t&;
          using pointer = const ::std::size_t*;
          using iterator_category = ::std::input_iterator_tag;

          iterator() = default;
          iterator(query_result const * const qr, const ::std::size_t i) : m_qr(qr), m_i(i) {
          }

          reference operator*() const {
            return this->m_qr->m_parent[this->m_i].first;
          }
          iterator& operator++() {
            ++this->m_i;
            return *this;
          }
          iterator operator++(int) {
            const auto self = *this;
            ++*this;
            return self;
          }
          friend bool operator==(const iterator& lhs, const iterator& rhs) {
            assert(lhs.m_qr == rhs.m_qr);
            return lhs.m_i == rhs.m_i;
          }
          friend bool operator!=(const iterator& lhs, const iterator& rhs) {
            return !(lhs == rhs);
          }
        };

        vertices_iterable() = default;
        vertices_iterable(query_result const * const qr) : m_qr(qr) {
        }

        iterator begin() const {
          return iterator(this->m_qr, 0);
        };
        iterator end() const {
          return iterator(this->m_qr, this->m_qr->m_parent.size());
        }
      };

      query_result() = default;

      ::std::size_t size() const {
        return this->m_parent.size();
      }

      vertices_iterable vertices() const {
        return vertices_iterable(this);
      }

      ::std::size_t root() const {
        return this->m_root;
      }

      ::std::size_t parent(const ::std::size_t v) const {
        const auto it = ::std::lower_bound(this->m_parent.begin(), this->m_parent.end(), ::std::make_pair(v, ::std::numeric_limits<::std::size_t>::max()), ::tools::less_by_first{});
        assert(it != this->m_parent.end());
        assert(it->first == v);
        return it->second;
      }

      const ::std::vector<::std::size_t>& children(const ::std::size_t v) const {
        const auto it = ::std::lower_bound(this->m_parent.begin(), this->m_parent.end(), ::std::make_pair(v, ::std::numeric_limits<::std::size_t>::max()), ::tools::less_by_first{});
        assert(it != this->m_parent.end());
        assert(it->first == v);
        return this->m_children[::std::distance(this->m_parent.begin(), it)];
      }

      friend ::tools::auxiliary_tree;
    };

    template <typename InputIterator>
    query_result query(const InputIterator begin, const InputIterator end) const {
      return query_result(*this, begin, end);
    }

    template <typename Z, ::std::enable_if_t<::std::is_integral_v<Z>, ::std::nullptr_t> = nullptr>
    query_result query(const ::std::vector<Z>& X) const {
      return this->query(X.begin(), X.end());
    }
  };
}

#endif
