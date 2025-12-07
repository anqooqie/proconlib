#ifndef TOOLS_CARTESIAN_TREE_HPP
#define TOOLS_CARTESIAN_TREE_HPP

#include <functional>
#include <cstddef>
#include <utility>
#include <vector>
#include <limits>
#include <stack>
#include <cassert>

namespace tools {
  template <typename T, typename Compare = std::less<T>>
  class cartesian_tree {
  public:
    struct vertex {
      std::size_t parent;
      std::size_t left;
      std::size_t right;
      std::pair<std::size_t, std::size_t> interval;
    };

  private:
    Compare m_comp;
    std::vector<vertex> m_vertices;

  public:
    cartesian_tree() = default;
    cartesian_tree(const tools::cartesian_tree<T, Compare>&) = default;
    cartesian_tree(tools::cartesian_tree<T, Compare>&&) = default;
    ~cartesian_tree() = default;
    tools::cartesian_tree<T, Compare>& operator=(const tools::cartesian_tree<T, Compare>&) = default;
    tools::cartesian_tree<T, Compare>& operator=(tools::cartesian_tree<T, Compare>&&) = default;

    explicit cartesian_tree(const std::vector<T>& a, const Compare& comp = Compare()) : m_comp(comp), m_vertices(a.size()) {
      const auto NONE = std::numeric_limits<std::size_t>::max();

      for (std::size_t i = 0; i < a.size(); ++i) {
        this->m_vertices[i].parent = i ? i - 1 : NONE;
        this->m_vertices[i].left = NONE;
        this->m_vertices[i].right = NONE;
        auto c = NONE;
        while (this->m_vertices[i].parent != NONE && this->m_comp(a[i], a[this->m_vertices[i].parent])) {
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
      for (std::size_t i = 0; i < a.size(); ++i) {
        const auto p = this->m_vertices[i].parent;
        if (p == NONE) {
          root = i;
        } else {
          if (p < i) {
            this->m_vertices[p].right= i;
          } else {
            this->m_vertices[p].left = i;
          }
        }
      }

      std::vector<std::size_t> strict_left(a.size());
      strict_left[root] = 0;
      this->m_vertices[root].interval = std::make_pair(0, a.size());
      std::stack<std::size_t> stack;
      stack.push(root);
      while (!stack.empty()) {
        const auto here = stack.top();
        stack.pop();
        const auto& v = this->m_vertices[here];
        if (v.right != NONE) {
          strict_left[v.right] = here + 1;
          this->m_vertices[v.right].interval = std::make_pair(
            this->m_comp(a[here], a[v.right]) ? strict_left[v.right] : this->m_vertices[here].interval.first,
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
    template <typename InputIterator>
    cartesian_tree(const InputIterator begin, const InputIterator end, const Compare& comp = Compare()) : cartesian_tree(std::vector<T>(begin, end), comp) {
    }

    std::size_t size() const {
      return this->m_vertices.size();
    }
    const vertex& get_vertex(std::size_t i) const {
      assert(i < this->size());
      return this->m_vertices[i];
    }
    const std::vector<vertex>& vertices() const {
      return this->m_vertices;
    }
  };
}

#endif
