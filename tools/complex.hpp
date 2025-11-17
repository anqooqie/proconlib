#ifndef TOOLS_COMPLEX_HPP
#define TOOLS_COMPLEX_HPP

#include <complex>
#include "tools/specialization_of.hpp"

namespace tools {
  template <typename T>
  concept complex = ::tools::specialization_of<T, ::std::complex>;
}

#endif
