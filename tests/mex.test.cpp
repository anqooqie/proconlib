#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2880"

#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include "tools/mex.hpp"
#include "tools/less_by.hpp"

using i64 = std::int_fast64_t;

struct query {
  i64 query_type;
  i64 id;
  i64 day;
  i64 from;
  i64 to;
  query(i64 query_type, i64 id, i64 day, i64 from, i64 to) :
    query_type(query_type),
    id(id),
    day(day),
    from(from),
    to(to) {
  }
};

int main() {
  i64 N, M, Q;
  std::cin >> N >> M >> Q;

  std::vector<query> queries;
  for (i64 i = 0; i < M; ++i) {
    i64 D, A, B;
    std::cin >> D >> A >> B;
    queries.emplace_back(1, i, D, A, B);
  }
  for (i64 i = 0; i < Q; ++i) {
    i64 E, S, T;
    std::cin >> E >> S >> T;
    queries.emplace_back(0, i, E, S, T);
  }

  std::sort(queries.begin(), queries.end(), tools::less_by([](const query& q) {
    return std::make_pair(q.day, q.query_type);
  }));

  tools::mex<i64> mex;
  std::vector<bool> answers(Q);
  for (const query& query : queries) {
    if (query.query_type == 0) {
      answers[query.id] = mex.query(query.from * 2) >= query.to * 2;
    } else {
      mex.insert(query.from * 2, query.to * 2);
    }
  }

  for (const bool answer : answers) {
    std::cout << (answer ? "Yes" : "No") << '\n';
  }

  return 0;
}
