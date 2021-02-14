#ifndef TOOLS_GROUP_HPP
#define TOOLS_GROUP_HPP

#include <cstddef>
#include <vector>
#include <cassert>
#include <numeric>

namespace tools {
  namespace group {
    template <typename Type>
    struct plus {
      using T = Type;
      static T op(const T lhs, const T rhs) {
        return lhs + rhs;
      }
      static T e() {
        return static_cast<T>(0);
      }
      static T inv(const T v) {
        return -v;
      }
    };

    template <typename Type>
    struct bit_xor {
      using T = Type;
      static T op(const T lhs, const T rhs) {
        return lhs ^ rhs;
      }
      static T e() {
        return static_cast<T>(0);
      }
      static T inv(const T v) {
        return v;
      }
    };

    template <typename Type, int Id = -1>
    class permutation {
    private:
      inline static ::std::size_t N;

    public:
      using T = ::std::vector<Type>;
      static void set_N(const ::std::size_t N) {
        permutation<Type, Id>::N = N;
      }
      static T op(const T& lhs, const T& rhs) {
        assert(lhs.size() == N);
        assert(rhs.size() == N);
        T new_v;
        new_v.reserve(N);
        for (::std::size_t i = 0; i < N; ++i) {
          new_v.push_back(rhs[lhs[i]]);
        }
        return new_v;
      }
      static T e() {
        T new_v(N);
        ::std::iota(new_v.begin(), new_v.end(), 0);
        return new_v;
      }
      static T inv(const T& v) {
        assert(v.size() == N);
        T new_v(N);
        for (::std::size_t i = 0; i < N; ++i) {
          new_v[v[i]] = i;
        }
        return new_v;
      }
    };
  }
}

#endif
