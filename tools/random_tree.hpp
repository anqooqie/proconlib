#ifndef TOOLS_RANDOM_TREE_HPP
#define TOOLS_RANDOM_TREE_HPP

#include <cstddef>
#include <cassert>
#include <vector>
#include <utility>
#include <numeric>
#include <random>

// Source: https://twitter.com/anta_prg/status/869633557362163712
// License: unknown
// Author: anta

namespace tools {

  template <typename T>
  class random_tree {
  private:
    ::std::size_t m_size;

  public:
    random_tree() = default;
    random_tree(const ::tools::random_tree<T>&) = default;
    random_tree(::tools::random_tree<T>&&) = default;
    ~random_tree() = default;
    ::tools::random_tree<T>& operator=(const ::tools::random_tree<T>&) = default;
    ::tools::random_tree<T>& operator=(::tools::random_tree<T>&&) = default;

    explicit random_tree(const ::std::size_t n) : m_size(n) {
      assert(n >= 1);
    }

    ::std::size_t size() const {
      return this->m_size;
    }

    template <typename R>
    ::std::vector<::std::pair<T, T>> operator()(R& engine) const {
      ::std::vector<::std::pair<T, T>> edges;

      ::std::vector<T> perm(this->size());
      ::std::iota(perm.begin(), perm.end(), 0);
      for (::std::size_t i = 0; i + 1 < this->size(); ++i) {
        const auto x = ::std::uniform_int_distribution<::std::size_t>(0, this->size() - i - 2)(engine);
        const auto y = ::std::uniform_int_distribution<::std::size_t>(0, this->size() - 1)(engine);
        ::std::swap(perm[i + 1], perm[i + 1 + x]);
        if (y < i + 1) ::std::swap(perm[i], perm[y]);
        edges.emplace_back(perm[i], perm[i + 1]);
      }

      return edges;
    }
  };
}

#endif
