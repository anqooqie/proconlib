// competitive-verifier: STANDALONE
// Source: https://atcoder.jp/contests/abc292/tasks/abc292_f

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numbers>
#include "tools/assert_close.hpp"
#include "tools/golden_section_search.hpp"

double solve(const double A, const double B) {
  return tools::golden_section_search(0.0, std::numbers::pi / 6, [&](const auto theta) {
    return std::min(B / std::cos(theta), A / std::sin(std::numbers::pi / 3 + theta));
  }, true).second;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  tools::assert_close(1.03527618041008295791, solve(1, 1), 1e-9);
  tools::assert_close(1.15470053837925168416, solve(1, 2), 1e-9);
  tools::assert_close(1.15470053837925168416, solve(3, 1), 1e-9);
  tools::assert_close(1.15470053837925168416, solve(1, 4), 1e-9);
  tools::assert_close(1.15470053837925168416, solve(1000, 1), 1e-9);
  tools::assert_close(1.15470053837925168416, solve(1, 999), 1e-9);
  tools::assert_close(1.15470053837925168416, solve(1, 998), 1e-9);
  tools::assert_close(1.15470053837925168416, solve(1, 997), 1e-9);
  tools::assert_close(2.07055236082016591581, solve(2, 2), 1e-9);
  tools::assert_close(2.30940107675850336832, solve(3, 2), 1e-9);
  tools::assert_close(2.30940107675850336832, solve(2, 4), 1e-9);
  tools::assert_close(2.30940107675850336832, solve(2, 1000), 1e-9);
  tools::assert_close(2.30940107675850336832, solve(999, 2), 1e-9);
  tools::assert_close(2.30940107675850336832, solve(998, 2), 1e-9);
  tools::assert_close(2.30940107675850336832, solve(2, 997), 1e-9);
  tools::assert_close(3.10582854123024887372, solve(3, 3), 1e-9);
  tools::assert_close(3.46410161513775483044, solve(4, 3), 1e-9);
  tools::assert_close(3.46410161513775483044, solve(1000, 3), 1e-9);
  tools::assert_close(3.46410161513775483044, solve(999, 3), 1e-9);
  tools::assert_close(3.46410161513775483044, solve(3, 998), 1e-9);
  tools::assert_close(3.46410161513775483044, solve(3, 997), 1e-9);
  tools::assert_close(4.14110472164033183162, solve(4, 4), 1e-9);
  tools::assert_close(4.61880215351700673665, solve(1000, 4), 1e-9);
  tools::assert_close(4.61880215351700673665, solve(4, 999), 1e-9);
  tools::assert_close(4.61880215351700673665, solve(4, 998), 1e-9);
  tools::assert_close(4.61880215351700673665, solve(997, 4), 1e-9);
  tools::assert_close(1035.27618041008304317074, solve(1000, 1000), 1e-9);
  tools::assert_close(1034.76034566210842058354, solve(999, 1000), 1e-9);
  tools::assert_close(1034.24812118999830090615, solve(998, 1000), 1e-9);
  tools::assert_close(1033.73951236049651924986, solve(997, 1000), 1e-9);
  tools::assert_close(1034.24090422967287850042, solve(999, 999), 1e-9);
  tools::assert_close(1033.72507128774645934755, solve(999, 998), 1e-9);
  tools::assert_close(1033.21285224096095589630, solve(999, 997), 1e-9);
  tools::assert_close(1033.20562804926271383010, solve(998, 998), 1e-9);
  tools::assert_close(1032.68979691700587864034, solve(998, 997), 1e-9);
  tools::assert_close(1032.17035186885277653346, solve(997, 997), 1e-9);
  tools::assert_close(367.52304404557946782006, solve(355, 355), 1e-9);
  tools::assert_close(70.39878026788564113758, solve(68, 68), 1e-9);
  tools::assert_close(446.20403375674578683174, solve(431, 431), 1e-9);
  tools::assert_close(600.46018463784810137440, solve(580, 580), 1e-9);
  tools::assert_close(783.70406857043280979269, solve(757, 757), 1e-9);
  tools::assert_close(251.72471736667685604516, solve(934, 218), 1e-9);
  tools::assert_close(378.74177658839454352346, solve(676, 328), 1e-9);
  tools::assert_close(255.18881898181459177977, solve(221, 355), 1e-9);
  tools::assert_close(92.37604307034013118027, solve(922, 80), 1e-9);
  tools::assert_close(550.55793644667596709041, solve(511, 545), 1e-9);
  tools::assert_close(77.36493607140985773185, solve(467, 67), 1e-9);
  tools::assert_close(707.33881326480741336127, solve(691, 674), 1e-9);
  tools::assert_close(581.96907134314278664533, solve(835, 504), 1e-9);
  tools::assert_close(39.25981830489455148836, solve(965, 34), 1e-9);
  tools::assert_close(255.18881898181459177977, solve(221, 980), 1e-9);
  tools::assert_close(578.50496972800499406731, solve(501, 895), 1e-9);
  tools::assert_close(175.51448183364624355818, solve(325, 152), 1e-9);
  tools::assert_close(348.71956259053399662662, solve(302, 731), 1e-9);
  tools::assert_close(176.66918237202548880305, solve(896, 153), 1e-9);
  tools::assert_close(25.40341184434353394295, solve(489, 22), 1e-9);
  tools::assert_close(460.72551481332141065650, solve(607, 399), 1e-9);
  tools::assert_close(469.45665540790525938064, solve(432, 466), 1e-9);
  tools::assert_close(579.65967026638429615559, solve(968, 502), 1e-9);
  tools::assert_close(384.51527928029076974781, solve(475, 333), 1e-9);
  tools::assert_close(96.99484522385714058146, solve(84, 792), 1e-9);
  tools::assert_close(6.92820323027550966088, solve(6, 7), 1e-9);
  tools::assert_close(96.99484522385714058146, solve(84, 97), 1e-9);
  tools::assert_close(15.00001233653745025265, solve(13, 15), 1e-9);
  tools::assert_close(209.00000000456401494375, solve(181, 209), 1e-9);
  tools::assert_close(209.00000000456401494375, solve(209, 181), 1e-9);
  tools::assert_close(932.99803501043527376169, solve(808, 933), 1e-9);
  tools::assert_close(932.99803501043527376169, solve(933, 808), 1e-9);

  return 0;
}
