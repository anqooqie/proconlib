#ifndef TOOLS_PARSE_FIXED_POINT_NUMBER
#define TOOLS_PARSE_FIXED_POINT_NUMBER

#include <cstdint>
#include <string>
#include <algorithm>

namespace tools {

  /**
   * parse a string as a fixed point number
   * License: CC0
   * @author anqooqie
   * @param s the string to be parsed
   * @param scale the count of decimal digits in the fractional part
   * @return $s * 10^{\mathrm{scale}}$
   */
  inline ::std::int_fast64_t parse_fixed_point_number(::std::string s, const int scale) {
    const auto pos = s.find('.');
    if (pos != ::std::string::npos) {
      const int real_scale = s.size() - (pos + 1);
      if (real_scale <= scale) {
        s += ::std::string(scale - real_scale, '0');
      } else {
        s.resize(pos + 1 + scale);
      }
    } else {
      s.push_back('.');
      s += ::std::string(scale, '0');
    }
    s.erase(::std::remove(s.begin(), s.end(), '.'), s.end());
    return ::std::stoll(s);
  }
}

#endif
