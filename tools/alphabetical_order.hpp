#ifndef TOOLS_ALPHABETICAL_ORDER
#define TOOLS_ALPHABETICAL_ORDER

#include <unordered_map>

namespace tools {

  /**
   * gets the alphabetical order of the given character
   * License: CC0
   * @aurhor anqooqie
   * @param c input
   * @return 0 if c is 'A' or 'a', 1 if c is 'B' or 'b', ..., and 25 if c is 'Z' or 'z'
   */
  int alphabetical_order(const char c) {
    static const std::unordered_map<char, int> map({
      {'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, {'F', 5}, {'G', 6}, {'H', 7}, {'I', 8}, {'J', 9},
      {'K', 10}, {'L', 11}, {'M', 12}, {'N', 13}, {'O', 14}, {'P', 15}, {'Q', 16}, {'R', 17}, {'S', 18}, {'T', 19},
      {'U', 20}, {'V', 21}, {'W', 22}, {'X', 23}, {'Y', 24}, {'Z', 25}, {'a', 0}, {'b', 1}, {'c', 2}, {'d', 3},
      {'e', 4}, {'f', 5}, {'g', 6}, {'h', 7}, {'i', 8}, {'j', 9}, {'k', 10}, {'l', 11}, {'m', 12}, {'n', 13},
      {'o', 14}, {'p', 15}, {'q', 16}, {'r', 17}, {'s', 18}, {'t', 19}, {'u', 20}, {'v', 21}, {'w', 22}, {'x', 23},
      {'y', 24}, {'z', 25}
    });
    return map.at(c);
  }
}

#endif
