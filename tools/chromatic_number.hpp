#ifndef TOOLS_CHROMATIC_NUMBER_HPP
#define TOOLS_CHROMATIC_NUMBER_HPP

#include <vector>
#include <cstdint>
#include <cstddef>
#include <cassert>
#include "atcoder/modint.hpp"
#include "tools/ntz.hpp"
#include "tools/popcount.hpp"

// Source: https://drken1215.hatenablog.com/entry/2019/01/16/030000
// License: unknown
// Author: drken

namespace tools {
  class chromatic_number {
  private:
    ::std::vector<::std::uint_fast64_t> neighbor;

  public:
    chromatic_number() = default;
    chromatic_number(const ::tools::chromatic_number&) = default;
    chromatic_number(::tools::chromatic_number&&) = default;
    ~chromatic_number() = default;
    ::tools::chromatic_number& operator=(const ::tools::chromatic_number&) = default;
    ::tools::chromatic_number& operator=(::tools::chromatic_number&&) = default;

    explicit chromatic_number(const ::std::size_t n) : neighbor(n) {
      for (::std::size_t i = 0; i < n; ++i) {
        this->neighbor[i] = (::std::uint_fast64_t(1) << ::std::uint_fast64_t(i));
      }
    }

    ::std::size_t node_count() const {
      return this->neighbor.size();
    }

    void add_edge(const ::std::size_t s, const ::std::size_t t) {
      assert(s < this->node_count());
      assert(t < this->node_count());
      this->neighbor[s] |= (::std::uint_fast64_t(1) << ::std::uint_fast64_t(t));
      this->neighbor[t] |= (::std::uint_fast64_t(1) << ::std::uint_fast64_t(s));
    }

    ::std::int_fast64_t query() const {
      const auto pow2 = [](const ::std::uint_fast64_t x) {
        return ::std::uint_fast64_t(1) << x;
      };
      const auto& set = pow2;

      // I[S] := #. of indepndent subsets of S
      ::std::vector<::atcoder::modint1000000007> I(pow2(this->node_count()));
      I[0] = ::atcoder::modint1000000007(1);
      for (::std::uint_fast64_t S = 1; S < pow2(this->node_count()); ++S) {
        const ::std::uint_fast64_t v = ::tools::ntz(S);
        I[S] = I[S & ~set(v)] + I[S & ~this->neighbor[v]];
      }

      ::std::int_fast64_t ng = 0;
      ::std::int_fast64_t ok = this->node_count();
      while (ok - ng > 1) {
        ::std::int_fast64_t k = (ok + ng) / 2;

        // g[S] := #. of "k independent sets" which cover S just
        // f[S] := #. of "k independent sets" which consist of subsets of S
        // then
        //   f[S] = sum_{T in S} g(T)
        //   g[S] = sum_{T in S} (-1)^(|S|-|T|)f[T]
        ::atcoder::modint1000000007 g(0);
        for (::std::uint_fast64_t S = 0; S < pow2(this->node_count()); ++S) {
          if ((::std::uint_fast64_t(this->node_count()) - ::tools::popcount(S)) & 1) {
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
