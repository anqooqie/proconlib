#ifndef TOOLS_CARTESIAN_TREE_HPP
#define TOOLS_CARTESIAN_TREE_HPP

#include <cassert>
#include <functional>
#include <iterator>
#include <stack>
#include <ranges>
#include <utility>
#include <vector>
#include "tools/getter_result.hpp"

namespace tools {
  class cartesian_tree {
  public:
    struct vertex {
      int parent;
      int left;
      int right;
      std::pair<int, int> interval;
    };

  private:
    std::vector<vertex> m_vertices;

  public:
    cartesian_tree() = default;
    template <std::ranges::random_access_range R, typename Compare = std::ranges::less>
    requires std::indirect_strict_weak_order<Compare, std::ranges::iterator_t<R>>
    explicit cartesian_tree(R&& a, const Compare comp = {}) : m_vertices(std::ranges::distance(a)) {
      if (this->size() == 0) return;

      static constexpr int NONE = -1;
      const auto begin = std::ranges::begin(a);

      for (int i = 0; i < this->size(); ++i) {
        this->m_vertices[i].parent = i ? i - 1 : NONE;
        this->m_vertices[i].left = NONE;
        this->m_vertices[i].right = NONE;
        auto c = NONE;
        while (this->m_vertices[i].parent != NONE && std::invoke(comp, begin[i], begin[this->m_vertices[i].parent])) {
          if (c != NONE) {
            this->m_vertices[c].parent = this->m_vertices[i].parent;
          }
          c = this->m_vertices[i].parent;

          const auto gp = this->m_vertices[this->m_vertices[i].parent].parent;
          this->m_vertices[this->m_vertices[i].parent].parent = i;
          this->m_vertices[i].parent = gp;
        }
      }

      auto root = NONE;
      for (int i = 0; i < this->size(); ++i) {
        const auto p = this->m_vertices[i].parent;
        if (p == NONE) {
          root = i;
        } else {
          if (p < i) {
            this->m_vertices[p].right = i;
          } else {
            this->m_vertices[p].left = i;
          }
        }
      }

      std::vector<int> strict_left(this->size());
      strict_left[root] = 0;
      this->m_vertices[root].interval = std::make_pair(0, this->size());
      std::stack<int> stack;
      stack.push(root);
      while (!stack.empty()) {
        const auto here = stack.top();
        stack.pop();
        const auto& v = this->m_vertices[here];
        if (v.right != NONE) {
          strict_left[v.right] = here + 1;
          this->m_vertices[v.right].interval = std::make_pair(
            std::invoke(comp, begin[here], begin[v.right]) ? strict_left[v.right] : this->m_vertices[here].interval.first,
            this->m_vertices[here].interval.second
          );
          stack.push(v.right);
        }
        if (v.left != NONE) {
          strict_left[v.left] = strict_left[here];
          this->m_vertices[v.left].interval = std::make_pair(strict_left[v.left], here);
          stack.push(v.left);
        }
      }
    }
    template <std::ranges::input_range R, typename Compare = std::ranges::less>
    requires (std::indirect_strict_weak_order<Compare, typename std::vector<std::ranges::range_value_t<R>>::iterator> && !std::ranges::random_access_range<R>)
    explicit cartesian_tree(R&& a, const Compare comp = {}) : cartesian_tree(std::forward<R>(a) | std::ranges::to<std::vector>(), comp) {
    }

    int size() const {
      return this->m_vertices.size();
    }
    auto get_vertex(this auto&& self, const int i) -> tools::getter_result_t<decltype(self), vertex> {
      assert(0 <= i && i < self.size());
      return std::forward_like<decltype(self)>(self.m_vertices[i]);
    }
    auto vertices(this auto&& self) -> tools::getter_result_t<decltype(self), std::vector<vertex>> {
      return std::forward_like<decltype(self)>(self.m_vertices);
    }
  };
}

#endif
