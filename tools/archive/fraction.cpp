#include <string>
#include <cmath>
#include "fraction.hpp"

namespace std {
  ::std::string to_string(const ::tools::fraction& f) {
    return '(' + ::std::to_string(f.numerator()) + '/' + ::std::to_string(f.denominator()) + ')';
  }

  ::tools::fraction abs(const ::tools::fraction& f) {
    return f.numerator() < 0 ? -f : f;
  }

  double sqrt(const ::tools::fraction& f) {
    return ::std::sqrt(static_cast<double>(f));
  }

  ::std::ostream& operator<<(::std::ostream& os, const ::tools::fraction& self) {
    return os << ::std::to_string(self);
  }
}
