#ifndef TOOLS_NOP_MAPPING_HPP
#define TOOLS_NOP_MAPPING_HPP

namespace tools {
  template <typename F, typename S>
  S nop_mapping(F, const S& e) {
    return e;
  }
}

#endif
