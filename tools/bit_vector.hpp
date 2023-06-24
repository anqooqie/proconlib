#ifndef TOOLS_BIT_VECTOR_HPP
#define TOOLS_BIT_VECTOR_HPP

#include <cstdint>
#include <vector>
#include <immintrin.h>

// Source: https://nyaannyaan.github.io/library/data-structure-2d/wavelet-matrix.hpp.html
// License: CC0 1.0 Universal
// Author: Nyaan

namespace tools {
  class bit_vector {
  private:
    using u32 = ::std::uint32_t;
    using i64 = ::std::int64_t;
    using u64 = ::std::uint64_t;

    static constexpr u32 w = 64;
    ::std::vector<u64> m_block;
    ::std::vector<u32> m_count;
    u32 m_size, m_zeros;

  public:
    bit_vector() {}
    explicit bit_vector(int _n) { init(_n); }
    __attribute__((optimize("O3", "unroll-loops"))) void init(int _n) {
      m_size = m_zeros = _n;
      m_block.resize(m_size / w + 1, 0);
      m_count.resize(m_block.size(), 0);
    }

    u32 size() const { return m_size; }
    inline u32 get(u32 i) const { return u32(m_block[i / w] >> (i % w)) & 1u; }
    inline void set(u32 i) { m_block[i / w] |= 1LL << (i % w); }

    __attribute__((target("popcnt"))) void build() {
      for (u32 i = 1; i < m_block.size(); ++i)
        m_count[i] = m_count[i - 1] + _mm_popcnt_u64(m_block[i - 1]);
      m_zeros = rank0(m_size);
    }

    u32 zeros() const { return m_zeros; }
    inline u32 rank0(u32 i) const { return i - rank1(i); }
    __attribute__((target("bmi2,popcnt"))) inline u32 rank1(u32 i) const {
      return m_count[i / w] + _mm_popcnt_u64(_bzhi_u64(m_block[i / w], i % w));
    }
  };
}

#endif
