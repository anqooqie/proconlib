#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <cstdlib>
#include <iostream>
#include "tools/assert_that.hpp"
#include "tools/alphabetical_order.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(tools::alphabetical_order('A') == 0);
  assert_that(tools::alphabetical_order('B') == 1);
  assert_that(tools::alphabetical_order('C') == 2);
  assert_that(tools::alphabetical_order('D') == 3);
  assert_that(tools::alphabetical_order('E') == 4);
  assert_that(tools::alphabetical_order('F') == 5);
  assert_that(tools::alphabetical_order('G') == 6);
  assert_that(tools::alphabetical_order('H') == 7);
  assert_that(tools::alphabetical_order('I') == 8);
  assert_that(tools::alphabetical_order('J') == 9);
  assert_that(tools::alphabetical_order('K') == 10);
  assert_that(tools::alphabetical_order('L') == 11);
  assert_that(tools::alphabetical_order('M') == 12);
  assert_that(tools::alphabetical_order('N') == 13);
  assert_that(tools::alphabetical_order('O') == 14);
  assert_that(tools::alphabetical_order('P') == 15);
  assert_that(tools::alphabetical_order('Q') == 16);
  assert_that(tools::alphabetical_order('R') == 17);
  assert_that(tools::alphabetical_order('S') == 18);
  assert_that(tools::alphabetical_order('T') == 19);
  assert_that(tools::alphabetical_order('U') == 20);
  assert_that(tools::alphabetical_order('V') == 21);
  assert_that(tools::alphabetical_order('W') == 22);
  assert_that(tools::alphabetical_order('X') == 23);
  assert_that(tools::alphabetical_order('Y') == 24);
  assert_that(tools::alphabetical_order('Z') == 25);

  assert_that(tools::alphabetical_order('a') == 0);
  assert_that(tools::alphabetical_order('b') == 1);
  assert_that(tools::alphabetical_order('c') == 2);
  assert_that(tools::alphabetical_order('d') == 3);
  assert_that(tools::alphabetical_order('e') == 4);
  assert_that(tools::alphabetical_order('f') == 5);
  assert_that(tools::alphabetical_order('g') == 6);
  assert_that(tools::alphabetical_order('h') == 7);
  assert_that(tools::alphabetical_order('i') == 8);
  assert_that(tools::alphabetical_order('j') == 9);
  assert_that(tools::alphabetical_order('k') == 10);
  assert_that(tools::alphabetical_order('l') == 11);
  assert_that(tools::alphabetical_order('m') == 12);
  assert_that(tools::alphabetical_order('n') == 13);
  assert_that(tools::alphabetical_order('o') == 14);
  assert_that(tools::alphabetical_order('p') == 15);
  assert_that(tools::alphabetical_order('q') == 16);
  assert_that(tools::alphabetical_order('r') == 17);
  assert_that(tools::alphabetical_order('s') == 18);
  assert_that(tools::alphabetical_order('t') == 19);
  assert_that(tools::alphabetical_order('u') == 20);
  assert_that(tools::alphabetical_order('v') == 21);
  assert_that(tools::alphabetical_order('w') == 22);
  assert_that(tools::alphabetical_order('x') == 23);
  assert_that(tools::alphabetical_order('y') == 24);
  assert_that(tools::alphabetical_order('z') == 25);

  std::cout << "Hello World" << '\n';
  return 0;
}
