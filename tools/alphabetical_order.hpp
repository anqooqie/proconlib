#ifndef TOOLS_ALPHABETICAL_ORDER_HPP
#define TOOLS_ALPHABETICAL_ORDER_HPP

#include <array>
#include <limits>

namespace tools {

  int alphabetical_order(const char c) {
    static const ::std::array<char, ::std::numeric_limits<char>::max()> map = []() {
      ::std::array<char, ::std::numeric_limits<char>::max()> m;
      m['A'] = 0;
      m['B'] = 1;
      m['C'] = 2;
      m['D'] = 3;
      m['E'] = 4;
      m['F'] = 5;
      m['G'] = 6;
      m['H'] = 7;
      m['I'] = 8;
      m['J'] = 9;
      m['K'] = 10;
      m['L'] = 11;
      m['M'] = 12;
      m['N'] = 13;
      m['O'] = 14;
      m['P'] = 15;
      m['Q'] = 16;
      m['R'] = 17;
      m['S'] = 18;
      m['T'] = 19;
      m['U'] = 20;
      m['V'] = 21;
      m['W'] = 22;
      m['X'] = 23;
      m['Y'] = 24;
      m['Z'] = 25;
      m['a'] = 0;
      m['b'] = 1;
      m['c'] = 2;
      m['d'] = 3;
      m['e'] = 4;
      m['f'] = 5;
      m['g'] = 6;
      m['h'] = 7;
      m['i'] = 8;
      m['j'] = 9;
      m['k'] = 10;
      m['l'] = 11;
      m['m'] = 12;
      m['n'] = 13;
      m['o'] = 14;
      m['p'] = 15;
      m['q'] = 16;
      m['r'] = 17;
      m['s'] = 18;
      m['t'] = 19;
      m['u'] = 20;
      m['v'] = 21;
      m['w'] = 22;
      m['x'] = 23;
      m['y'] = 24;
      m['z'] = 25;
      return m;
    }();
    return map[c];
  }
}

#endif
