#ifndef TOOLS_DP_WITH_REROOTING_HPP
#define TOOLS_DP_WITH_REROOTING_HPP

#include <cstddef>
#include <vector>
#include <limits>
#include <stack>
#include <tuple>
#include <algorithm>

namespace tools {
  template <typename V, typename E, typename R, typename M, typename M::T (*f_ve)(R, E), R (*f_ev)(typename M::T, V)>
  class dp_with_rerooting {
  private:
    class adjacency {
    public:
      ::std::size_t to;
      E attribute;

      adjacency() = default;
      adjacency(const adjacency&) = default;
      adjacency(adjacency&&) = default;
      ~adjacency() = default;
      adjacency& operator=(const adjacency&) = default;
      adjacency& operator=(adjacency&&) = default;

      adjacency(const ::std::size_t to, const E& attribute) :
        to(to), attribute(attribute) {
      }
    };

    ::std::vector<V> vertex_attributes;
    ::std::vector<::std::vector<adjacency>> adjacency_list;

    class vertex {
    private:
      const ::tools::dp_with_rerooting<V, E, R, M, f_ve, f_ev> *self;

    public:
      ::std::size_t id;
      ::std::size_t parent_adjacency_id;
      ::std::vector<::std::size_t> child_adjacency_ids;
      typename M::T parent_dp;
      ::std::vector<typename M::T> children_dp;
      ::std::vector<typename M::T> children_dp_cumsum1;
      ::std::vector<typename M::T> children_dp_cumsum2;

      vertex() = default;
      vertex(const vertex&) = default;
      vertex(vertex&&) = default;
      ~vertex() = default;
      vertex& operator=(const vertex&) = default;
      vertex& operator=(vertex&&) = default;

      explicit vertex(const ::tools::dp_with_rerooting<V, E, R, M, f_ve, f_ev> * const self, const ::std::size_t id) :
        self(self), id(id), parent_dp(M::e()) {
      }

      V attribute() const {
        return self->vertex_attributes[this->id];
      }
      ::std::size_t parent_vertex_id() const {
        return self->adjacency_list[this->id][this->parent_adjacency_id].to;
      }
      E parent_edge_attribute() const {
        return self->adjacency_list[this->id][this->parent_adjacency_id].attribute;
      }
      ::std::size_t child_size() const {
        return this->child_adjacency_ids.size();
      }
      ::std::size_t child_vertex_id(const ::std::size_t child_edge_id) const {
        return self->adjacency_list[this->id][this->child_adjacency_ids[child_edge_id]].to;
      }
      E child_edge_attribute(const ::std::size_t child_edge_id) const {
        return self->adjacency_list[this->id][this->child_adjacency_ids[child_edge_id]].attribute;
      }
      R dp_as_root() const {
        return f_ev(M::op(this->parent_dp, this->children_dp_cumsum1.back()), this->attribute());
      }
      R dp_excluding_parent() const {
        return f_ev(this->children_dp_cumsum1.back(), this->attribute());
      }
      R dp_excluding_child(const ::std::size_t excluded_child_edge_id) const {
        return f_ev(M::op(this->parent_dp, M::op(this->children_dp_cumsum1[excluded_child_edge_id], this->children_dp_cumsum2[excluded_child_edge_id + 1])), this->attribute());
      }
    };

  public:
    dp_with_rerooting() = default;
    dp_with_rerooting(const ::tools::dp_with_rerooting<V, E, R, M, f_ve, f_ev>&) = default;
    dp_with_rerooting(::tools::dp_with_rerooting<V, E, R, M, f_ve, f_ev>&&) = default;
    ~dp_with_rerooting() = default;
    ::tools::dp_with_rerooting<V, E, R, M, f_ve, f_ev>& operator=(const ::tools::dp_with_rerooting<V, E, R, M, f_ve, f_ev>&) = default;
    ::tools::dp_with_rerooting<V, E, R, M, f_ve, f_ev>& operator=(::tools::dp_with_rerooting<V, E, R, M, f_ve, f_ev>&&) = default;

    void add_vertex(const V& vertex_attribute) {
      this->vertex_attributes.push_back(vertex_attribute);
      this->adjacency_list.emplace_back();
    }

    void add_edge(const ::std::size_t a, const ::std::size_t b, const E& edge_attribute) {
      this->adjacency_list[a].emplace_back(b, edge_attribute);
      this->adjacency_list[b].emplace_back(a, edge_attribute);
    }

    ::std::size_t size() const {
      return this->vertex_attributes.size();
    }

    ::std::vector<R> query() const {
      const int PRE_VERTEX = 1;
      const int POST_EDGE = 2;
      const int POST_VERTEX = 3;
      const ::std::size_t INVALID = ::std::numeric_limits<::std::size_t>::max();

      ::std::vector<vertex> vertices;
      for (::std::size_t i = 0; i < this->size(); ++i) {
        vertices.emplace_back(this, i);
      }

      ::std::stack<::std::tuple<int, ::std::size_t, ::std::size_t>> stack;
      ::std::vector<bool> will_visit(this->size(), false);
      stack.emplace(PRE_VERTEX, 0, INVALID);
      will_visit[0] = true;
      while (!stack.empty()) {
        const int type = ::std::get<0>(stack.top());
        if (type == PRE_VERTEX) {

          const ::std::size_t vertex_id = ::std::get<1>(stack.top());
          stack.pop();

          vertex& v = vertices[vertex_id];
          stack.emplace(POST_VERTEX, vertex_id, INVALID);
          for (::std::size_t adjacency_id = 0; adjacency_id < this->adjacency_list[vertex_id].size(); ++adjacency_id) {
            const ::std::size_t child_id = this->adjacency_list[vertex_id][adjacency_id].to;
            if (will_visit[child_id]) {
              v.parent_adjacency_id = adjacency_id;
            } else {
              v.child_adjacency_ids.push_back(adjacency_id);
              stack.emplace(POST_EDGE, vertex_id, v.child_size() - 1);
              stack.emplace(PRE_VERTEX, child_id, INVALID);
              will_visit[child_id] = true;
            }
          }
          v.children_dp.resize(v.child_size());

        } else if (type == POST_EDGE) {

          const ::std::size_t vertex_id = ::std::get<1>(stack.top());
          const ::std::size_t edge_id = ::std::get<2>(stack.top());
          stack.pop();

          vertex& v = vertices[vertex_id];
          const vertex& c = vertices[v.child_vertex_id(edge_id)];
          v.children_dp[edge_id] = f_ve(c.dp_excluding_parent(), v.child_edge_attribute(edge_id));

        } else { // POST_VERTEX

          const ::std::size_t vertex_id = ::std::get<1>(stack.top());
          stack.pop();

          vertex& v = vertices[vertex_id];

          v.children_dp_cumsum1.reserve(v.child_size() + 1);
          v.children_dp_cumsum1.push_back(M::e());
          for (::std::size_t edge_id = 0; edge_id < v.child_size(); ++edge_id) {
            v.children_dp_cumsum1.push_back(M::op(v.children_dp_cumsum1.back(), v.children_dp[edge_id]));
          }

          v.children_dp_cumsum2.reserve(v.child_size() + 1);
          v.children_dp_cumsum2.push_back(M::e());
          for (::std::size_t edge_id = v.child_size(); edge_id --> 0;) {
            v.children_dp_cumsum2.push_back(M::op(v.children_dp[edge_id], v.children_dp_cumsum2.back()));
          }
          ::std::reverse(v.children_dp_cumsum2.begin(), v.children_dp_cumsum2.end());

        }
      }

      stack.emplace(PRE_VERTEX, 0, INVALID);
      while (!stack.empty()) {
        const ::std::size_t vertex_id = ::std::get<1>(stack.top());
        stack.pop();

        const vertex& v = vertices[vertex_id];
        for (::std::size_t edge_id = 0; edge_id < v.child_size(); ++edge_id) {
          vertex& c = vertices[v.child_vertex_id(edge_id)];
          c.parent_dp = f_ve(v.dp_excluding_child(edge_id), c.parent_edge_attribute());
          stack.emplace(PRE_VERTEX, c.id, INVALID);
        }
      }

      ::std::vector<R> result;
      result.reserve(this->size());
      for (const vertex& v : vertices) {
        result.push_back(v.dp_as_root());
      }
      return result;
    }
  };
}

#endif
