// competitive-verifier: STANDALONE

#include <iostream>
#include "tools/assert_that.hpp"
#include "tools/is_bipartite.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  // empty graph (0 vertices)
  {
    tools::is_bipartite g(0);
    assert_that(g.size() == 0);
    assert_that(g.edges().empty());
    assert_that(g.query());
  }

  // single vertex, no edges
  {
    tools::is_bipartite g(1);
    assert_that(g.size() == 1);
    assert_that(g.query());
  }

  // single edge (trivially bipartite)
  {
    tools::is_bipartite g(2);
    const int eid = g.add_edge(0, 1);
    assert_that(eid == 0);
    assert_that(g.size() == 2);
    assert_that(g.edges().size() == 1);
    assert_that(g.query());

    const auto& e = g.get_edge(0);
    assert_that(e.from == 0);
    assert_that(e.to == 1);
  }

  // self-loop (not bipartite)
  {
    tools::is_bipartite g(1);
    g.add_edge(0, 0);
    assert_that(!g.query());
  }

  // triangle (odd cycle, not bipartite)
  {
    tools::is_bipartite g(3);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    assert_that(!g.query());
  }

  // square (even cycle, bipartite)
  {
    tools::is_bipartite g(4);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 0);
    assert_that(g.query());
  }

  // path graph (always bipartite)
  {
    tools::is_bipartite g(5);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    assert_that(g.query());
  }

  // complete bipartite K_{3,3}
  {
    tools::is_bipartite g(6);
    for (int i = 0; i < 3; ++i) {
      for (int j = 3; j < 6; ++j) {
        g.add_edge(i, j);
      }
    }
    assert_that(g.query());
    assert_that(g.edges().size() == 9);
  }

  // K4 (complete graph on 4 vertices, contains odd cycle)
  {
    tools::is_bipartite g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 3);
    assert_that(!g.query());
  }

  // disconnected graph: bipartite + bipartite = bipartite
  {
    tools::is_bipartite g(6);
    // component 1: edge 0-1
    g.add_edge(0, 1);
    // component 2: square 2-3-4-5
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    g.add_edge(4, 5);
    g.add_edge(5, 2);
    assert_that(g.query());
  }

  // disconnected graph: bipartite + non-bipartite = non-bipartite
  {
    tools::is_bipartite g(5);
    // component 1: edge 0-1 (bipartite)
    g.add_edge(0, 1);
    // component 2: triangle 2-3-4 (not bipartite)
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    g.add_edge(4, 2);
    assert_that(!g.query());
  }

  // isolated vertices (all disconnected, bipartite)
  {
    tools::is_bipartite g(10);
    assert_that(g.query());
  }

  // multi-edges (even number of parallel edges, still bipartite)
  {
    tools::is_bipartite g(2);
    g.add_edge(0, 1);
    g.add_edge(0, 1);
    assert_that(g.query());
  }

  // add_edge returns correct indices, get_edge normalizes (from <= to)
  {
    tools::is_bipartite g(5);
    assert_that(g.add_edge(3, 1) == 0);
    assert_that(g.add_edge(4, 0) == 1);
    assert_that(g.add_edge(2, 2) == 2);

    // edges are normalized so from <= to
    const auto& e0 = g.get_edge(0);
    assert_that(e0.from == 1);
    assert_that(e0.to == 3);

    const auto& e1 = g.get_edge(1);
    assert_that(e1.from == 0);
    assert_that(e1.to == 4);

    const auto& e2 = g.get_edge(2);
    assert_that(e2.from == 2);
    assert_that(e2.to == 2);
  }

  // edges() returns all edges in insertion order
  {
    tools::is_bipartite g(4);
    g.add_edge(0, 1);
    g.add_edge(2, 3);
    g.add_edge(1, 2);
    const auto& es = g.edges();
    assert_that(es.size() == 3);
    assert_that(es[0].from == 0 && es[0].to == 1);
    assert_that(es[1].from == 2 && es[1].to == 3);
    assert_that(es[2].from == 1 && es[2].to == 2);
  }

  // pentagon (5-cycle, odd, not bipartite)
  {
    tools::is_bipartite g(5);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    g.add_edge(4, 0);
    assert_that(!g.query());
  }

  // hexagon (6-cycle, even, bipartite)
  {
    tools::is_bipartite g(6);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    g.add_edge(4, 5);
    g.add_edge(5, 0);
    assert_that(g.query());
  }

  // tree (always bipartite)
  {
    tools::is_bipartite g(7);
    // 0 -- 1 -- 3 -- 6
    // |    |
    // 2    4
    // |
    // 5
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 5);
    g.add_edge(3, 6);
    assert_that(g.query());
  }

  // tree + one back edge creating odd cycle
  {
    tools::is_bipartite g(7);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 5);
    g.add_edge(3, 6);
    // back edge 0-3: creates cycle 0-1-3-0 (length 3, odd)
    g.add_edge(0, 3);
    assert_that(!g.query());
  }

  return 0;
}
