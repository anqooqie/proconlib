#ifndef FENWICK_HPP
#define FENWICK_HPP

#include <vector>
#include <type_traits>
#include <iterator>
#include <cassert>

/*
usage:

std::vector<std::int_fast64_t> a = {1, 2, 3, 4, 5};
tools::fenwick<std::int_fast64_t> b(a.begin(), a.end());
b.sum(1, 3) // => 5 (sum of [1, 3) of b)
*/

namespace tools {
  template <typename T>
  class fenwick {
  private:
    std::vector<T> values;

  public:
    template <
      typename InputIter,
      typename std::enable_if<
        std::is_same<T, typename std::iterator_traits<InputIter>::value_type>::value &&
        std::is_base_of<std::input_iterator_tag, typename std::iterator_traits<InputIter>::iterator_category>::value,
        std::nullptr_t
      >::type = nullptr
    >
    fenwick(const InputIter begin, const InputIter end) :
      values(begin, end) {
      for (std::size_t i = 1; i < this->values.size(); ++i) {
        if (i + (i & -i) - 1 < this->values.size()) {
          this->values[i + (i & -i) - 1] += this->values[i - 1];
        }
      }
    }

    std::size_t size() const {
      return this->values.size();
    }

    void add(std::size_t i, const T value) {
      assert(i < this->values.size());
      for (i += 1; i <= this->values.size(); i += i & -i) {
        this->values[i - 1] += value;
      }
    }

    T sum(const std::size_t begin, const std::size_t end) const {
      if (begin == 0) {
        assert(end <= this->values.size());
        T result = 0;
        for (std::size_t i = end; i > 0; i -= i & -i) {
          result += this->values[i - 1];
        }
        return result;
      } else {
        return begin < end ? this->sum(0, end) - this->sum(0, begin) : 0;
      }
    }

    T operator[](const std::size_t i) const {
      return this->sum(i, i + 1);
    }
  };
}

#endif
