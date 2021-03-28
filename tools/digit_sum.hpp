#ifndef TOOLS_DIGIT_SUM_HPP
#define TOOLS_DIGIT_SUM_HPP

namespace tools {

  template <typename T>
  T digit_sum(T n) {
    T sum = 0;
    for (; n > 0; n /= 10) {
      sum += n % 10;
    }
    return sum;
  }
}

#endif
