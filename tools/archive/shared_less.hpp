#ifndef SHARED_LESS_HPP
#define SHARED_LESS_HPP

#include <memory>

/*
usage:

std::priority_queue<std::shared_ptr<klass>, std::vector<std::shared_ptr<klass>>, tools::shared_less<klass>> queue;
*/

namespace tools {
  template <typename T>
  struct shared_less {
    bool operator()(const std::shared_ptr<T>& lhs, const std::shared_ptr<T>& rhs) const {
      return *lhs < *rhs;
    }
    using first_argument_type = std::shared_ptr<T>;
    using second_argument_type = std::shared_ptr<T>;
    using result_type = bool;
  };
}

#endif
