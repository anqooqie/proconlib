#ifndef TOOLS_REROOTING_DP_HPP
#define TOOLS_REROOTING_DP_HPP

#include <algorithm>
#include <cassert>
#include <concepts>
#include <functional>
#include <iterator>
#include <limits>
#include <ranges>
#include <stack>
#include <tuple>
#include <type_traits>
#include <vector>
#include "tools/commutative_monoid.hpp"

namespace tools {
  template <typename R, tools::commutative_monoid M, std::regular_invocable<R, int> F_VE, std::regular_invocable<typename M::T, int> F_EV>
  requires std::convertible_to<std::invoke_result_t<F_VE, R, int>, typename M::T>
        && std::convertible_to<std::invoke_result_t<F_EV, typename M::T, int>, R>
  class rerooting_dp {
    std::vector<int> m_edges;
    std::vector<std::vector<int>> m_graph;
    F_VE m_f_ve;
    F_EV m_f_ev;

    class vertex {
      const tools::rerooting_dp<R, M, F_VE, F_EV> *m_self;

    public:
      int id;
      int neighbor_id_of_parent;
      std::vector<int> neighbor_ids_of_children;
      typename M::T parent_dp;
      std::vector<typename M::T> children_dp;
      std::vector<typename M::T> children_dp_cumsum1;
      std::vector<typename M::T> children_dp_cumsum2;

      vertex() = default;
      explicit vertex(const tools::rerooting_dp<R, M, F_VE, F_EV> * const self, const int id) :
        m_self(self), id(id), parent_dp(M::e()) {
      }

      int parent_edge_id() const {
        return this->m_self->m_graph[this->id][this->neighbor_id_of_parent];
      }
      int parent_vertex_id() const {
        return this->m_self->m_edges[this->parent_edge_id()] ^ this->id;
      }
      int child_size() const {
        return this->neighbor_ids_of_children.size();
      }
      int child_edge_id(const int child_number) const {
        return this->m_self->m_graph[this->id][this->neighbor_ids_of_children[child_number]];
      }
      int child_vertex_id(const int child_number) const {
        return this->m_self->m_edges[this->child_edge_id(child_number)] ^ this->id;
      }
      R dp_as_root() const {
        return std::invoke(this->m_self->m_f_ev, M::op(this->parent_dp, this->children_dp_cumsum1.back()), this->id);
      }
      R dp_excluding_parent() const {
        return std::invoke(this->m_self->m_f_ev, this->children_dp_cumsum1.back(), this->id);
      }
      R dp_excluding_child(const int excluded_child_number) const {
        return std::invoke(this->m_self->m_f_ev, M::op(this->parent_dp, M::op(this->children_dp_cumsum1[excluded_child_number], this->children_dp_cumsum2[excluded_child_number + 1])), this->id);
      }
    };

  public:
    rerooting_dp() = default;
    rerooting_dp(const int n, const F_VE& f_ve, const F_EV& f_ev) : m_graph(n), m_f_ve(f_ve), m_f_ev(f_ev) {
      assert(n >= 1);
    }

    int size() const {
      return this->m_graph.size();
    }

    int add_edge(const int u, const int v) {
      assert(0 <= u && u < this->size());
      assert(0 <= v && v < this->size());
      this->m_graph[u].push_back(this->m_edges.size());
      this->m_graph[v].push_back(this->m_edges.size());
      this->m_edges.push_back(u ^ v);
      return this->m_edges.size() - 1;
    }

    std::vector<R> query() const {
      assert(std::ssize(this->m_edges) + 1 == this->size());

      const int PRE_VERTEX = 1;
      const int POST_EDGE = 2;
      const int POST_VERTEX = 3;
      const int INVALID = -1;

      std::vector<vertex> vertices;
      for (int i = 0; i < this->size(); ++i) {
        vertices.emplace_back(this, i);
      }

      std::stack<std::tuple<int, int, int>> stack;
      std::vector<bool> will_visit(this->size(), false);
      stack.emplace(PRE_VERTEX, 0, INVALID);
      will_visit[0] = true;
      while (!stack.empty()) {
        const auto type = std::get<0>(stack.top());
        if (type == PRE_VERTEX) {

          const auto vertex_id = std::get<1>(stack.top());
          stack.pop();

          vertex& v = vertices[vertex_id];
          stack.emplace(POST_VERTEX, vertex_id, INVALID);
          for (int neighbor_id = 0; neighbor_id < std::ssize(this->m_graph[vertex_id]); ++neighbor_id) {
            const int child_vertex_id = this->m_edges[this->m_graph[vertex_id][neighbor_id]] ^ vertex_id;
            if (will_visit[child_vertex_id]) {
              v.neighbor_id_of_parent = neighbor_id;
            } else {
              v.neighbor_ids_of_children.push_back(neighbor_id);
              stack.emplace(POST_EDGE, vertex_id, v.child_size() - 1);
              stack.emplace(PRE_VERTEX, child_vertex_id, INVALID);
              will_visit[child_vertex_id] = true;
            }
          }
          v.children_dp.resize(v.child_size());

        } else if (type == POST_EDGE) {

          const auto vertex_id = std::get<1>(stack.top());
          const auto child_number = std::get<2>(stack.top());
          stack.pop();

          vertex& v = vertices[vertex_id];
          const vertex& c = vertices[v.child_vertex_id(child_number)];
          v.children_dp[child_number] = std::invoke(this->m_f_ve, c.dp_excluding_parent(), v.child_edge_id(child_number));

        } else { // POST_VERTEX

          const auto vertex_id = std::get<1>(stack.top());
          stack.pop();

          vertex& v = vertices[vertex_id];

          v.children_dp_cumsum1.reserve(v.child_size() + 1);
          v.children_dp_cumsum1.push_back(M::e());
          for (int child_number = 0; child_number < v.child_size(); ++child_number) {
            v.children_dp_cumsum1.push_back(M::op(v.children_dp_cumsum1.back(), v.children_dp[child_number]));
          }

          v.children_dp_cumsum2.reserve(v.child_size() + 1);
          v.children_dp_cumsum2.push_back(M::e());
          for (int child_number = v.child_size(); child_number --> 0;) {
            v.children_dp_cumsum2.push_back(M::op(v.children_dp[child_number], v.children_dp_cumsum2.back()));
          }
          std::ranges::reverse(v.children_dp_cumsum2);

        }
      }

      stack.emplace(PRE_VERTEX, 0, INVALID);
      while (!stack.empty()) {
        const auto vertex_id = std::get<1>(stack.top());
        stack.pop();

        const vertex& v = vertices[vertex_id];
        for (int child_number = 0; child_number < v.child_size(); ++child_number) {
          vertex& c = vertices[v.child_vertex_id(child_number)];
          c.parent_dp = std::invoke(this->m_f_ve, v.dp_excluding_child(child_number), c.parent_edge_id());
          stack.emplace(PRE_VERTEX, c.id, INVALID);
        }
      }

      return vertices | std::views::transform(&vertex::dp_as_root) | std::ranges::to<std::vector>();
    }
  };
}

#endif
