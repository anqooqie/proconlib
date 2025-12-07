#ifndef TOOLS_AVAILABLE_FOR_MULTIPLE_RANGE_ADAPTORS_HPP
#define TOOLS_AVAILABLE_FOR_MULTIPLE_RANGE_ADAPTORS_HPP

#include <concepts>
#include <ranges>
#include <type_traits>
#include "tools/specialization_of.hpp"

namespace tools {
  template <typename T>
  concept available_for_multiple_range_adaptors = std::ranges::forward_range<T>
    && std::ranges::viewable_range<T>
    && std::copyable<std::views::all_t<T>>;
}

#endif
