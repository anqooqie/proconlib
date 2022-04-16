#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include <cstdint>
#include <iostream>
#include <vector>
#include <utility>
#include <limits>
#include <queue>
#include <algorithm>
#include "tools/persistent_stack.hpp"
#include "tools/greater_by_second.hpp"
#include "tools/chmin.hpp"
#include "tools/ssize.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N, M, s, t;
  std::cin >> N >> M >> s >> t;
  std::vector<std::vector<std::pair<i64, i64>>> graph(N);
  for (i64 i = 0; i < M; ++i) {
    i64 a, b, c;
    std::cin >> a >> b >> c;
    graph[a].emplace_back(b, c);
  }

  std::vector<i64> dist(N, std::numeric_limits<i64>::max());
  dist[s] = 0;

  tools::persistent_stack<i64>::buffer buffer;
  std::vector<tools::persistent_stack<i64>> path(N, tools::persistent_stack<i64>(buffer));
  path[s] = path[s].push(s);

  std::priority_queue<std::pair<i64, i64>, std::vector<std::pair<i64, i64>>, tools::greater_by_second> pq;
  pq.emplace(s, 0);
  while (!pq.empty()) {
    const auto [here, d] = pq.top();
    pq.pop();
    if (dist[here] < d) continue;
    for (const auto& [next, w] : graph[here]) {
      if (tools::chmin(dist[next], dist[here] + w)) {
        path[next] = path[here].push(next);
        pq.emplace(next, dist[next]);
      }
    }
  }

  if (dist[t] == std::numeric_limits<i64>::max()) {
    std::cout << -1 << '\n';
    return 0;
  }

  std::cout << dist[t] << ' ' << path[t].size() - 1 << '\n';
  std::vector<i64> answers;
  for (auto stack = path[t]; !stack.empty(); stack = stack.pop()) {
    answers.push_back(stack.top());
  }
  std::reverse(answers.begin(), answers.end());
  for (i64 i = 0; i + 1 < tools::ssize(answers); ++i) {
    std::cout << answers[i] << ' ' << answers[i + 1] << '\n';
  }

  return 0;
}
