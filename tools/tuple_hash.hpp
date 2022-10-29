#ifndef TOOLS_TUPLE_HASH_HPP
#define TOOLS_TUPLE_HASH_HPP

#include <cstddef>
#include <tuple>
#include <chrono>
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
  template <typename... Ts>
  class tuple_hash {
  public:
    using result_type = ::std::size_t;
    using argument_type = ::std::tuple<Ts...>;

  private:
    static constexpr result_type k_mul = 0x9ddfea08eb382d69ULL;

  public:
    template <int I = int(sizeof...(Ts)) - 1>
      result_type operator()(const argument_type& key) const {
      if constexpr (I == -1) {
        static const result_type seed = ::std::chrono::duration_cast<::std::chrono::nanoseconds>(::std::chrono::high_resolution_clock::now().time_since_epoch()).count();
        return seed;
      } else {
        static const ::std::hash<::std::tuple_element_t<I, argument_type>> hasher;
        result_type seed = this->operator()<I - 1>(key);
        result_type a = (hasher(::std::get<I>(key)) ^ seed) * k_mul;
        a ^= (a >> 47);
        result_type b = (seed ^ a) * k_mul;
        b ^= (b >> 47);
        seed = b * k_mul;
        return seed;
      }
    }
  };
}

#endif
