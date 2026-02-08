// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/shortest_path

#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/chmin.hpp"
#include "tools/greater_by_second.hpp"
#include "tools/persistent_stack.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, M, s, t;
  std::cin >> N >> M >> s >> t;
  std::vector<std::vector<std::pair<ll, ll>>> graph(N);
  for (ll i = 0; i < M; ++i) {
    ll a, b, c;
    std::cin >> a >> b >> c;
    graph[a].emplace_back(b, c);
  }

  std::vector<ll> dist(N, std::numeric_limits<ll>::max());
  dist[s] = 0;

  std::vector<tools::persistent_stack<ll>> path(N);
  path[s] = path[s].push(s);

  std::priority_queue<std::pair<ll, ll>, std::vector<std::pair<ll, ll>>, tools::greater_by_second> pq;
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

  if (dist[t] == std::numeric_limits<ll>::max()) {
    std::cout << -1 << '\n';
    return 0;
  }

  std::cout << dist[t] << ' ' << path[t].size() - 1 << '\n';
  std::vector<ll> answers;
  for (auto stack = path[t]; !stack.empty(); stack = stack.pop()) {
    answers.push_back(stack.top());
  }
  std::ranges::reverse(answers);
  for (ll i = 0; i + 1 < std::ssize(answers); ++i) {
    std::cout << answers[i] << ' ' << answers[i + 1] << '\n';
  }

  std::vector<tools::persistent_stack<ll>>{}.swap(path);
  assert_that(tools::persistent_stack<ll>::fully_released());

  return 0;
}
