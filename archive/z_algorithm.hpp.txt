#ifndef Z_ALGORITHM_HPP
#define Z_ALGORITHM_HPP

#include <vector>
#include <cstddef>
#include <iterator>

/*
usage:

std::string S = "momomosumomomosu";
std::vector<std::size_t> Z = tools::z_algorithm(S.begin(), S.end());
std::cout << Z[0] << ' ' << Z[1] << ' ' << Z[2] << ' ' << Z[3] << std::endl; //=> 16 0 4 0
*/

// Source: 【図解】線形時間の文字列アルゴリズム「Z algorithm」をイラストとアニメーションでかみ砕く - Qiita ( https://qiita.com/Pro_ktmr/items/16904c9570aa0953bf05 )
// Author: Pro_ktmr ( https://qiita.com/Pro_ktmr )
// License: Unknown
namespace tools {
  template <typename InputIter>
  ::std::vector<::std::size_t> z_algorithm(const InputIter& begin, const InputIter& end) {
    ::std::vector<typename ::std::iterator_traits<InputIter>::value_type> S(begin, end);
    ::std::vector<::std::size_t> Z(S.size());

    // Z[0] は自明
    Z[0] = S.size();

    ::std::size_t i = 1;
    ::std::size_t prefix = 0;
    while (i < S.size()) {

      // ナイーブに、 prefix をできるだけ伸ばす
      for (; i + prefix < S.size() && S[prefix] == S[i + prefix]; ++prefix);

      // Z[i] は確定
      Z[i] = prefix;

      // prefix が 0 ならもう得られる情報は無い
      // ナイーブに次の探索へ
      if (prefix == 0) {
        ++i;
        continue;
      }

      // Z[i + 1] ～ Z[i + prefix - 1] について、既存の情報の使い回しができないか考える
      ::std::size_t extra_offset = 1;
      for (; extra_offset < prefix && extra_offset + Z[extra_offset] < prefix; ++extra_offset) {

        // これは完全に使い回せる
        Z[i + extra_offset] = Z[extra_offset];
      }

      // extra_offset + Z[extra_offset] < prefix を満たさない Z[i + extra_offset] は一部だけ使い回せる
      // i を i + extra_offset へ進めて次の探索へ
      i += extra_offset;

      // 一部使い回し分
      prefix -= extra_offset;
    }

    return Z;
  }
}

#endif
