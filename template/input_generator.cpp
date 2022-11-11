#include "tools/util.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());

  // [Guide]
  // 
  // How to get a random integer in [1, 10000]:
  // std::uniform_int_distribution<ll> dist(1, 10000);
  // std::cout << dist(engine) << '\n';
  // 
  // How to sample random 3 integers from a vector:
  // std::vector<ll> population({1, 2, 3, 4, 5});
  // std::vector<ll> sample;
  // std::sample(population.begin(), population.end(), std::back_inserter(sample), 3, engine);

  return 0;
}
