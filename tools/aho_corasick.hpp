#ifndef TOOLS_AHO_CORASICK_HPP
#define TOOLS_AHO_CORASICK_HPP

#include <algorithm>
#include <array>
#include <cassert>
#include <functional>
#include <iterator>
#include <queue>
#include <ranges>
#include <string>
#include <string_view>
#include <type_traits>
#include <utility>
#include <vector>
#include "tools/getter_result.hpp"

namespace tools {
  template <auto Encode = [](const char c) { return c - 'a'; }, int AlphabetSize = 26>
  requires std::is_invocable_r_v<int, decltype(Encode), char> && (AlphabetSize > 0)
  class aho_corasick {
    static constexpr int NONE = -1;

  public:
    struct node {
      int parent;
      std::array<int, AlphabetSize> children;
      int failure_link;
      std::array<int, AlphabetSize> next;
      std::vector<int> pattern_indices;
      int output_link;
      int pattern_count_sum;
    };

  private:
    std::vector<std::string> m_patterns;
    std::vector<node> m_nodes;
    std::vector<int> m_pattern_to_node;
    std::vector<int> m_bfs_ordered;

    bool built() const {
      return !this->m_nodes.empty();
    }

  public:
    aho_corasick() = default;

    int encode(const char c) const {
      const int i = std::invoke(Encode, c);
      assert(0 <= i && i < AlphabetSize);
      return i;
    }
    int alphabet_size() const {
      return AlphabetSize;
    }

    int add_pattern(const std::string_view pattern) {
      assert(!this->built());
      assert(std::ranges::all_of(
        pattern | std::views::transform([](const char c) { return std::invoke(Encode, c); }),
        [](const int i) { return 0 <= i && i < AlphabetSize; }
      ));
      this->m_patterns.emplace_back(pattern);
      return this->m_patterns.size() - 1;
    }
    auto get_pattern(this auto&& self, const int k) -> tools::getter_result_t<decltype(self), std::string> {
      assert(0 <= k && k < std::ssize(self.m_patterns));
      return std::forward_like<decltype(self)>(self.m_patterns[k]);
    }
    auto patterns(this auto&& self) -> tools::getter_result_t<decltype(self), std::vector<std::string>> {
      return std::forward_like<decltype(self)>(self.m_patterns);
    }

    void build() {
      assert(!this->built());

      this->m_nodes.push_back({NONE, {}, NONE, {}, {}, NONE, 0});
      this->m_nodes.back().children.fill(NONE);
      this->m_pattern_to_node.resize(this->m_patterns.size());
      for (int k = 0; k < std::ssize(this->m_patterns); ++k) {
        int current_node = 0;
        for (const char c : this->m_patterns[k]) {
          const auto i = std::invoke(Encode, c);
          if (this->m_nodes[current_node].children[i] == NONE) {
            this->m_nodes[current_node].children[i] = this->m_nodes.size();
            this->m_nodes.push_back({current_node, {}, NONE, {}, {}, NONE, 0});
            this->m_nodes.back().children.fill(NONE);
          }
          current_node = this->m_nodes[current_node].children[i];
        }
        this->m_nodes[current_node].pattern_indices.push_back(k);
        this->m_pattern_to_node[k] = current_node;
      }

      std::queue<std::pair<int, int>> queue;
      auto& root = this->m_nodes[0];
      for (int i = 0; i < AlphabetSize; ++i) {
        if (root.children[i] != NONE) {
          queue.emplace(i, root.children[i]);
          root.next[i] = root.children[i];
        } else {
          root.next[i] = 0;
        }
      }
      this->m_bfs_ordered.push_back(0);

      while (!queue.empty()) {
        const auto [i, v] = queue.front();
        queue.pop();
        auto& node = this->m_nodes[v];
        node.failure_link = this->m_nodes[node.parent].failure_link != NONE
          ? this->m_nodes[this->m_nodes[node.parent].failure_link].next[i]
          : 0;
        for (int j = 0; j < AlphabetSize; ++j) {
          if (node.children[j] != NONE) {
            queue.emplace(j, node.children[j]);
            node.next[j] = node.children[j];
          } else {
            node.next[j] = this->m_nodes[node.failure_link].next[j];
          }
        }
        node.output_link = this->m_nodes[node.failure_link].pattern_indices.empty()
          ? this->m_nodes[node.failure_link].output_link
          : node.failure_link;
        node.pattern_count_sum = node.pattern_indices.size() + (node.output_link != NONE ? this->m_nodes[node.output_link].pattern_count_sum : 0);
        this->m_bfs_ordered.push_back(v);
      }
    }

    auto get_node(this auto&& self, const int v) -> tools::getter_result_t<decltype(self), node> {
      assert(self.built());
      assert(0 <= v && v < std::ssize(self.m_nodes));
      return std::forward_like<decltype(self)>(self.m_nodes[v]);
    }
    auto nodes(this auto&& self) -> tools::getter_result_t<decltype(self), std::vector<node>> {
      assert(self.built());
      return std::forward_like<decltype(self)>(self.m_nodes);
    }

    int pattern_to_node(const int k) const {
      assert(this->built());
      assert(0 <= k && k < std::ssize(this->m_patterns));
      return this->m_pattern_to_node[k];
    }

    auto bfs_ordered(this auto&& self) -> tools::getter_result_t<decltype(self), std::vector<int>> {
      assert(self.built());
      return std::forward_like<decltype(self)>(self.m_bfs_ordered);
    }
  };
}

#endif
