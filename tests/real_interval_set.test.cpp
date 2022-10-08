#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2880"

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include "tools/real_interval_set.hpp"
#include "tools/less_by.hpp"

using ll = long long;

struct query {
  ll query_type;
  ll id;
  ll day;
  ll from;
  ll to;
  query(ll query_type, ll id, ll day, ll from, ll to) :
    query_type(query_type),
    id(id),
    day(day),
    from(from),
    to(to) {
  }
};

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, M, Q;
  std::cin >> N >> M >> Q;

  std::vector<query> queries;
  for (ll i = 0; i < M; ++i) {
    ll D, A, B;
    std::cin >> D >> A >> B;
    queries.emplace_back(1, i, D, A, B);
  }
  for (ll i = 0; i < Q; ++i) {
    ll E, S, T;
    std::cin >> E >> S >> T;
    queries.emplace_back(0, i, E, S, T);
  }

  std::sort(queries.begin(), queries.end(), tools::less_by([](const query& q) {
    return std::make_pair(q.day, q.query_type);
  }));

  tools::real_interval_set<ll> set;
  std::vector<bool> answers(Q);
  for (const query& query : queries) {
    if (query.query_type == 0) {
      const auto it = set.find(query.from);
      const ll reachable = it != set.end() ? it->second : query.from;
      answers[query.id] = query.to <= reachable;
    } else {
      set.insert(query.from, query.to);
    }
  }

  for (const bool answer : answers) {
    std::cout << (answer ? "Yes" : "No") << '\n';
  }

  return 0;
}
