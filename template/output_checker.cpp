#include "tools/util.hpp"

int main(const int argc, char *argv[]) {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  const std::string input = argc > 1 ? argv[1] : "";
  const std::string your_output = argc > 2 ? argv[2] : "";
  const std::string expected_output = argc > 3 ? argv[3] : "";

  {
    std::ifstream ifs(input);
  }
  {
    std::ifstream ifs(your_output);
  }
  {
    std::ifstream ifs(expected_output);
  }

  return 0;
}
