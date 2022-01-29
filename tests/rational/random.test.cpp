#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <iostream>
#include "tests/assert_that.hpp"
#include "tools/rational.hpp"
#include "tools/bigint.hpp"

/*
cat <<'_EOT_' | ruby -r rational -w
10.times do
  ->(x, y){puts "  assert_that(static_cast<double>(tools::rational(tools::bigint(\"#{x}\"), tools::bigint(\"#{y}\"))) == #{Rational(x, y).to_f});"}\
    [*2.times.map{(rand(1000000) + 1) * (rand(2) * 2 - 1)}]
end
_EOT_
 */

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(static_cast<double>(tools::rational(tools::bigint("257647"), tools::bigint("-219959"))) == -1.1713410226451293);
  assert_that(static_cast<double>(tools::rational(tools::bigint("160661"), tools::bigint("-559733"))) == -0.2870314953736871);
  assert_that(static_cast<double>(tools::rational(tools::bigint("40254"), tools::bigint("-190752"))) == -0.2110279315551082);
  assert_that(static_cast<double>(tools::rational(tools::bigint("466076"), tools::bigint("318039"))) == 1.4654680715258193);
  assert_that(static_cast<double>(tools::rational(tools::bigint("-328141"), tools::bigint("-719842"))) == 0.4558514229511476);
  assert_that(static_cast<double>(tools::rational(tools::bigint("-397270"), tools::bigint("928386"))) == -0.42791468203958266);
  assert_that(static_cast<double>(tools::rational(tools::bigint("672923"), tools::bigint("-130542"))) == -5.154839055629606);
  assert_that(static_cast<double>(tools::rational(tools::bigint("931516"), tools::bigint("264478"))) == 3.5220925748077345);
  assert_that(static_cast<double>(tools::rational(tools::bigint("-485813"), tools::bigint("828958"))) == -0.5860526106268351);
  assert_that(static_cast<double>(tools::rational(tools::bigint("-450120"), tools::bigint("319853"))) == -1.4072714653293856);

  std::cout << "Hello World" << '\n';
  return 0;
}
