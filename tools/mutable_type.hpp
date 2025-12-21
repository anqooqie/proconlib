#ifndef TOOLS_MUTABLE_TYPE_HPP
#define TOOLS_MUTABLE_TYPE_HPP

#include <type_traits>

namespace tools {
  template <typename T>
  concept mutable_type = !std::is_const_v<std::remove_reference_t<T>>;
}

#endif
