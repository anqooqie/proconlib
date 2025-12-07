#ifndef TOOLS_CHROMATIC_NUMBER_HPP
#define TOOLS_CHROMATIC_NUMBER_HPP

#include <vector>
#include <cstddef>
#include <cassert>
#include "atcoder/modint.hpp"
#include "tools/countr_zero.hpp"
#include "tools/popcount.hpp"

// Source: https://drken1215.hatenablog.com/entry/2019/01/16/030000
// License: unknown
// Author: drken

namespace tools {
  class chromatic_number {
  private:
    std::vector<unsigned long long> neighbor;

  public:
    chromatic_number() = default;
    chromatic_number(const tools::chromatic_number&) = default;
    chromatic_number(tools::chromatic_number&&) = default;
    ~chromatic_number() = default;
    tools::chromatic_number& operator=(const tools::chromatic_number&) = default;
    tools::chromatic_number& operator=(tools::chromatic_number&&) = default;

    explicit chromatic_number(const std::size_t n) : neighbor(n) {
      for (std::size_t i = 0; i < n; ++i) {
        this->neighbor[i] = (1ULL << i);
      }
    }

    std::size_t node_count() const {
      return this->neighbor.size();
    }

    void add_edge(const std::size_t s, const std::size_t t) {
      assert(s < this->node_count());
      assert(t < this->node_count());
      this->neighbor[s] |= (1ULL << t);
      this->neighbor[t] |= (1ULL << s);
    }

    long long query() const {
      const auto pow2 = [](const unsigned long long x) {
        return 1ULL << x;
      };
      const auto& set = pow2;

      // I[S] := #. of indepndent subsets of S
      std::vector<atcoder::modint1000000007> I(pow2(this->node_count()));
      I[0] = atcoder::modint1000000007(1);
      for (unsigned long long S = 1; S < pow2(this->node_count()); ++S) {
        const unsigned long long v = tools::countr_zero(S);
        I[S] = I[S & ~set(v)] + I[S & ~this->neighbor[v]];
      }

      long long ng = 0;
      long long ok = this->node_count();
      while (ok - ng > 1) {
        long long k = (ok + ng) / 2;

        // g[S] := #. of "k independent sets" which cover S just
        // f[S] := #. of "k independent sets" which consist of subsets of S
        // then
        //   f[S] = sum_{T in S} g(T)
        //   g[S] = sum_{T in S} (-1)^(|S|-|T|)f[T]
        atcoder::modint1000000007 g(0);
        for (unsigned long long S = 0; S < pow2(this->node_count()); ++S) {
          if ((static_cast<unsigned long long>(this->node_count()) - tools::popcount(S)) & 1) {
            g -= I[S].pow(k);
          } else {
            g += I[S].pow(k);
          }
        }

        if (g.val() != 0) {
          ok = k;
        } else {
          ng = k;
        }
      }

      return ok;
    }
  };
}

#endif
