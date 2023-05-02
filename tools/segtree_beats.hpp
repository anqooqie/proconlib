#ifndef TOOLS_SEGTREE_BEATS_HPP
#define TOOLS_SEGTREE_BEATS_HPP

#include "atcoder/lazysegtree.hpp"

// Source: https://github.com/hitonanode/cplib-cpp/blob/94a544f88242fec39b4dd434ed379c23aa4dd99b/segmenttree/acl_beats.hpp
// License: MIT
// Author: hitonanode

// MIT License
// 
// Copyright (c) 2019 Ryotaro Sato
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

namespace tools {
  template <class S, auto op, auto e, class F, auto mapping, auto composition, auto id>
  class segtree_beats : public ::atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> {
    using Base = ::atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;
    using Base::lazy_segtree;
    void all_apply(int k, F f) override {
      Base::d[k] = mapping(f, Base::d[k]);
      if (k < Base::size) {
        Base::lz[k] = composition(f, Base::lz[k]);
        if (Base::d[k].fail) Base::push(k), Base::update(k);
      }
    }
  };
}

#endif
