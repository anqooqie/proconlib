// competitive-verifier: STANDALONE

#include <iostream>
#include <sstream>
#include <string>
#include "tools/assert_that.hpp"
#include "tools/dynamic_bitset.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  // default constructor / empty / size
  {
    tools::dynamic_bitset s;
    assert_that(s.size() == 0);
    assert_that(s.empty());
    assert_that(s.count() == 0);
    assert_that(!s.any());
    assert_that(s.none());
    assert_that(s.all());
    assert_that(s.to_string() == "");
  }

  // size constructor
  {
    tools::dynamic_bitset s(10);
    assert_that(s.size() == 10);
    assert_that(!s.empty());
    assert_that(s.count() == 0);
    assert_that(!s.any());
    assert_that(s.none());
    assert_that(!s.all());
    assert_that(s.to_string() == "0000000000");
  }

  // string constructor — leftmost char is the most significant bit
  {
    tools::dynamic_bitset s("10110");
    assert_that(s.size() == 5);
    assert_that(s.count() == 3);
    assert_that(!s.test(0));
    assert_that(s.test(1));
    assert_that(s.test(2));
    assert_that(!s.test(3));
    assert_that(s.test(4));
    assert_that(s.to_string() == "10110");
  }

  // test / set / reset / flip on a single position
  {
    tools::dynamic_bitset s(8);
    s.set(3);
    assert_that(s.test(3));
    assert_that(s.count() == 1);
    s.set(5, true);
    assert_that(s.test(5));
    s.set(3, false);
    assert_that(!s.test(3));
    s.reset(5);
    assert_that(!s.test(5));
    s.flip(2);
    assert_that(s.test(2));
    s.flip(2);
    assert_that(!s.test(2));
  }

  // set() / reset() / flip() / operator~ on whole bitset, crossing W=64 boundary
  {
    tools::dynamic_bitset s(130);
    s.set();
    assert_that(s.count() == 130);
    assert_that(s.all());
    assert_that(s.any());
    assert_that(!s.none());
    s.reset();
    assert_that(s.count() == 0);
    assert_that(!s.all());
    assert_that(!s.any());
    assert_that(s.none());
    s.flip();
    assert_that(s.count() == 130);
    assert_that(s.all());
    const auto t = ~s;
    assert_that(t.count() == 0);
    assert_that(t.none());
  }

  // operator[] read / write via reference
  {
    tools::dynamic_bitset s(70);
    s[0] = true;
    s[63] = true;
    s[64] = true;
    s[69] = true;
    assert_that(s[0]);
    assert_that(s[63]);
    assert_that(s[64]);
    assert_that(s[69]);
    assert_that(!s[1]);
    assert_that(s.count() == 4);
    s[0] = false;
    assert_that(!s[0]);
    s[1].flip();
    assert_that(s[1]);
    assert_that(~s[2]);
    assert_that(!~s[1]);
    s[5] = s[1];
    assert_that(s[5]);
  }

  // operator&= / |= / ^=
  {
    tools::dynamic_bitset a("11001100");
    tools::dynamic_bitset b("10101010");
    auto c = a;
    c &= b;
    assert_that(c.to_string() == "10001000");
    c = a;
    c |= b;
    assert_that(c.to_string() == "11101110");
    c = a;
    c ^= b;
    assert_that(c.to_string() == "01100110");
    assert_that((a & b).to_string() == "10001000");
    assert_that((a | b).to_string() == "11101110");
    assert_that((a ^ b).to_string() == "01100110");
  }

  // operator<<= / >>= within a single block
  {
    tools::dynamic_bitset s("00010110");
    s <<= 2;
    assert_that(s.to_string() == "01011000");
    s >>= 3;
    assert_that(s.to_string() == "00001011");
  }

  // operator<<= / >>= crossing block boundary (W=64), with both block and intra-block shift
  {
    tools::dynamic_bitset s(130);
    s.set(0);
    s.set(1);
    s.set(63);
    s.set(64);
    s.set(129);
    auto t = s << 1;
    assert_that(!t.test(0));
    assert_that(t.test(1));
    assert_that(t.test(2));
    assert_that(!t.test(63));
    assert_that(t.test(64));
    assert_that(t.test(65));
    assert_that(!t.test(129));
    assert_that(t.count() == 4);

    t = s << 65;
    assert_that(t.count() == 4);
    assert_that(t.test(65));
    assert_that(t.test(66));
    assert_that(t.test(128));
    assert_that(t.test(129));

    t = s << 130;
    assert_that(t.count() == 0);

    t = s >> 1;
    assert_that(t.test(0));
    assert_that(!t.test(1));
    assert_that(t.test(62));
    assert_that(t.test(63));
    assert_that(!t.test(64));
    assert_that(t.test(128));
    assert_that(t.count() == 4);

    t = s >> 64;
    assert_that(t.count() == 2);
    assert_that(t.test(0));
    assert_that(t.test(65));

    t = s >> 200;
    assert_that(t.count() == 0);
  }

  // operator<< / >> top-bits truncation
  {
    tools::dynamic_bitset s("1111");
    assert_that((s << 2).to_string() == "1100");
    assert_that((s << 4).to_string() == "0000");
    assert_that((s >> 2).to_string() == "0011");
    assert_that((s >> 4).to_string() == "0000");
  }

  // equality
  {
    tools::dynamic_bitset a("1010");
    tools::dynamic_bitset b("1010");
    tools::dynamic_bitset c("1011");
    tools::dynamic_bitset d("01010");
    assert_that(a == b);
    assert_that(a != c);
    assert_that(a != d);
  }

  // const operator[] / test
  {
    const tools::dynamic_bitset s("101");
    assert_that(s[0]);
    assert_that(!s[1]);
    assert_that(s[2]);
    assert_that(s.test(0));
  }

  // streams
  {
    std::istringstream iss("11010");
    tools::dynamic_bitset s;
    iss >> s;
    assert_that(s.to_string() == "11010");
    std::ostringstream oss;
    oss << s;
    assert_that(oss.str() == "11010");
  }

  // resize: grow appends 0s, shrink keeps the prefix (least significant bits)
  {
    tools::dynamic_bitset s("11011");
    s.resize(8);
    assert_that(s.size() == 8);
    assert_that(s.to_string() == "00011011");
    s.resize(3);
    assert_that(s.size() == 3);
    assert_that(s.to_string() == "011");
  }

  // resize crossing W=64 boundary, then shrink within boundary clears stale bits
  {
    tools::dynamic_bitset s(70);
    s.set();
    assert_that(s.count() == 70);
    s.resize(60);
    assert_that(s.size() == 60);
    assert_that(s.count() == 60);
    s.resize(70);
    assert_that(s.size() == 70);
    assert_that(s.count() == 60);
    for (std::size_t i = 0; i < 60; ++i) assert_that(s.test(i));
    for (std::size_t i = 60; i < 70; ++i) assert_that(!s.test(i));
  }

  // shrink_to_fit (non-binding; just verify it does not corrupt state)
  {
    tools::dynamic_bitset s("1011");
    s.shrink_to_fit();
    assert_that(s.size() == 4);
    assert_that(s.to_string() == "1011");
  }

  // count(l, r): empty range, full range, range within a single block, range across blocks
  {
    tools::dynamic_bitset s(130);
    s.set(0);
    s.set(1);
    s.set(5);
    s.set(63);
    s.set(64);
    s.set(65);
    s.set(127);
    s.set(129);
    assert_that(s.count() == 8);
    assert_that(s.count(0, 130) == 8);
    assert_that(s.count(0, 0) == 0);
    assert_that(s.count(5, 5) == 0);
    assert_that(s.count(0, 6) == 3);
    assert_that(s.count(0, 5) == 2);
    assert_that(s.count(2, 64) == 2);
    assert_that(s.count(63, 66) == 3);
    assert_that(s.count(64, 130) == 4);
    assert_that(s.count(128, 130) == 1);
    assert_that(s.count(63, 64) == 1);
    assert_that(s.count(64, 65) == 1);
    assert_that(s.count(65, 127) == 1);
    assert_that(s.count(66, 127) == 0);
  }

  // count(l, r) on all-set bitset, crossing block boundary
  {
    tools::dynamic_bitset s(200);
    s.set();
    for (std::size_t l = 0; l <= 200; ++l) {
      for (std::size_t r = l; r <= 200; ++r) {
        assert_that(s.count(l, r) == r - l);
      }
    }
  }

  // count(l, l) at l == size when size is a multiple of W (regression: must not OOB)
  {
    tools::dynamic_bitset s(64);
    assert_that(s.count(64, 64) == 0);
    s.set();
    assert_that(s.count(64, 64) == 0);
  }
  {
    tools::dynamic_bitset s(128);
    assert_that(s.count(128, 128) == 0);
  }
  {
    tools::dynamic_bitset s;
    assert_that(s.count(0, 0) == 0);
  }

  // Find_first / Find_next
  {
    tools::dynamic_bitset s(200);
    assert_that(s.Find_first() == 200);
    s.set(7);
    s.set(63);
    s.set(64);
    s.set(127);
    s.set(199);
    assert_that(s.Find_first() == 7);
    assert_that(s.Find_next(7) == 63);
    assert_that(s.Find_next(62) == 63);
    assert_that(s.Find_next(63) == 64);
    assert_that(s.Find_next(64) == 127);
    assert_that(s.Find_next(127) == 199);
    assert_that(s.Find_next(199) == 200);
    assert_that(s.Find_next(198) == 199);
  }

  // Find_first when first bit is set
  {
    tools::dynamic_bitset s(10);
    s.set(0);
    assert_that(s.Find_first() == 0);
    assert_that(s.Find_next(0) == 10);
  }

  return 0;
}
