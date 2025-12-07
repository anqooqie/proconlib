#ifndef TOOLS_HASH_COMBINE_HPP
#define TOOLS_HASH_COMBINE_HPP

#include <cstddef>
#include <functional>

// Source: https://github.com/google/cityhash/blob/f5dc54147fcce12cefd16548c8e760d68ac04226/src/city.h
// License: MIT
// Author: Google Inc.

// Copyright (c) 2011 Google, Inc.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

namespace tools {
  template <typename T>
  void hash_combine(std::size_t& seed, const T& v) {
    static const std::hash<T> hasher;
    static constexpr std::size_t k_mul = 0x9ddfea08eb382d69ULL;
    std::size_t a = (hasher(v) ^ seed) * k_mul;
    a ^= (a >> 47);
    std::size_t b = (seed ^ a) * k_mul;
    b ^= (b >> 47);
    seed = b * k_mul;
  }
}

#endif
