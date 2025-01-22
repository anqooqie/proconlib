// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include <iostream>
#include "tools/assert_that.hpp"
#include "tools/bigdecimal.hpp"

/*
cat <<'_EOT_' | ruby -r bigdecimal -w
10.times do
  ->(x, y){puts "  assert_that(tools::bigdecimal(\"#{x.to_s("F")}\") + tools::bigdecimal(\"#{y.to_s("F")}\") == tools::bigdecimal(\"#{(x + y).to_s("F")}\"));"}\
    [*2.times.map{BigDecimal(5.times.map{rand(10)}.join) * BigDecimal(10).power(rand(11) - 8) * (rand(2) * 2 - 1)}]
end
10.times do
  ->(x, y){puts "  assert_that(tools::bigdecimal(\"#{x.to_s("F")}\") - tools::bigdecimal(\"#{y.to_s("F")}\") == tools::bigdecimal(\"#{(x - y).to_s("F")}\"));"}\
    [*2.times.map{BigDecimal(5.times.map{rand(10)}.join) * BigDecimal(10).power(rand(11) - 8) * (rand(2) * 2 - 1)}]
end
10.times do
  ->(x, y){puts "  assert_that(tools::bigdecimal(\"#{x.to_s("F")}\") * tools::bigdecimal(\"#{y.to_s("F")}\") == tools::bigdecimal(\"#{(x * y).to_s("F")}\"));"}\
    [*2.times.map{BigDecimal(5.times.map{rand(10)}.join) * BigDecimal(10).power(rand(11) - 8) * (rand(2) * 2 - 1)}]
end
10.times do
  ->(x, y){puts "  assert_that(tools::bigdecimal(\"#{x.to_s("F")}\").divide_and_copy(tools::bigdecimal(\"#{y.to_s("F")}\"), 15) == tools::bigdecimal(\"#{x.div(y, 100).round(15, BigDecimal::ROUND_HALF_EVEN).to_s("F")}\"));"}\
    [*2.times.map{BigDecimal(5.times.map{rand(10)}.join) * BigDecimal(10).power(rand(11) - 8) * (rand(2) * 2 - 1)}]
end
10.times do
  ->(x){puts "  assert_that(static_cast<double>(tools::bigdecimal(\"#{x.to_s("F")}\")) == #{x.to_f});"}\
    [BigDecimal(20.times.map{rand(10)}.join) * BigDecimal(10).power(rand(41) - 31) * (rand(2) * 2 - 1)]
end
_EOT_
 */

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(tools::bigdecimal("0.0097772") + tools::bigdecimal("-72.855") == tools::bigdecimal("-72.8452228"));
  assert_that(tools::bigdecimal("84.333") + tools::bigdecimal("-6383900.0") == tools::bigdecimal("-6383815.667"));
  assert_that(tools::bigdecimal("0.0048") + tools::bigdecimal("72881.0") == tools::bigdecimal("72881.0048"));
  assert_that(tools::bigdecimal("0.58784") + tools::bigdecimal("847.5") == tools::bigdecimal("848.08784"));
  assert_that(tools::bigdecimal("0.00049683") + tools::bigdecimal("5388900.0") == tools::bigdecimal("5388900.00049683"));
  assert_that(tools::bigdecimal("81437.0") + tools::bigdecimal("-0.0059072") == tools::bigdecimal("81436.9940928"));
  assert_that(tools::bigdecimal("-0.54255") + tools::bigdecimal("-279.81") == tools::bigdecimal("-280.35255"));
  assert_that(tools::bigdecimal("-72.343") + tools::bigdecimal("-0.093009") == tools::bigdecimal("-72.436009"));
  assert_that(tools::bigdecimal("-0.018432") + tools::bigdecimal("-3.9252") == tools::bigdecimal("-3.943632"));
  assert_that(tools::bigdecimal("0.028044") + tools::bigdecimal("0.41577") == tools::bigdecimal("0.443814"));
  assert_that(tools::bigdecimal("470430.0") - tools::bigdecimal("-366100.0") == tools::bigdecimal("836530.0"));
  assert_that(tools::bigdecimal("287.53") - tools::bigdecimal("65.997") == tools::bigdecimal("221.533"));
  assert_that(tools::bigdecimal("388.02") - tools::bigdecimal("1.4246") == tools::bigdecimal("386.5954"));
  assert_that(tools::bigdecimal("1241100.0") - tools::bigdecimal("90.434") == tools::bigdecimal("1241009.566"));
  assert_that(tools::bigdecimal("0.0099714") - tools::bigdecimal("-5.2323") == tools::bigdecimal("5.2422714"));
  assert_that(tools::bigdecimal("-50.355") - tools::bigdecimal("-0.00039784") == tools::bigdecimal("-50.35460216"));
  assert_that(tools::bigdecimal("-39.5") - tools::bigdecimal("-78.445") == tools::bigdecimal("38.945"));
  assert_that(tools::bigdecimal("0.0013112") - tools::bigdecimal("0.00066117") == tools::bigdecimal("0.00065003"));
  assert_that(tools::bigdecimal("-687860.0") - tools::bigdecimal("0.00010768") == tools::bigdecimal("-687860.00010768"));
  assert_that(tools::bigdecimal("-0.0009437") - tools::bigdecimal("-44384.0") == tools::bigdecimal("44383.9990563"));
  assert_that(tools::bigdecimal("0.00084213") * tools::bigdecimal("40277.0") == tools::bigdecimal("33.91847001"));
  assert_that(tools::bigdecimal("-60.942") * tools::bigdecimal("-0.98643") == tools::bigdecimal("60.11501706"));
  assert_that(tools::bigdecimal("27651.0") * tools::bigdecimal("600560.0") == tools::bigdecimal("16606084560.0"));
  assert_that(tools::bigdecimal("-0.00035273") * tools::bigdecimal("7698.7") == tools::bigdecimal("-2.715562451"));
  assert_that(tools::bigdecimal("652280.0") * tools::bigdecimal("5694.6") == tools::bigdecimal("3714473688.0"));
  assert_that(tools::bigdecimal("-236010.0") * tools::bigdecimal("-0.00049626") == tools::bigdecimal("117.1223226"));
  assert_that(tools::bigdecimal("0.0087251") * tools::bigdecimal("72099.0") == tools::bigdecimal("629.0709849"));
  assert_that(tools::bigdecimal("-79237.0") * tools::bigdecimal("779530.0") == tools::bigdecimal("-61767618610.0"));
  assert_that(tools::bigdecimal("0.70356") * tools::bigdecimal("0.0058389") == tools::bigdecimal("0.004108016484"));
  assert_that(tools::bigdecimal("-47.693") * tools::bigdecimal("-0.0020069") == tools::bigdecimal("0.0957150817"));
  assert_that(tools::bigdecimal("0.14094").divide_and_copy(tools::bigdecimal("-0.00081366"), 15) == tools::bigdecimal("-173.217314357348278"));
  assert_that(tools::bigdecimal("-0.020643").divide_and_copy(tools::bigdecimal("-0.55371"), 15) == tools::bigdecimal("0.037281248306875"));
  assert_that(tools::bigdecimal("868220.0").divide_and_copy(tools::bigdecimal("0.066584"), 15) == tools::bigdecimal("13039468.941487444431095"));
  assert_that(tools::bigdecimal("-771070.0").divide_and_copy(tools::bigdecimal("-0.004221"), 15) == tools::bigdecimal("182674721.629945510542525"));
  assert_that(tools::bigdecimal("0.00007411").divide_and_copy(tools::bigdecimal("720550.0"), 15) == tools::bigdecimal("0.000000000102852"));
  assert_that(tools::bigdecimal("46198.0").divide_and_copy(tools::bigdecimal("-48179.0"), 15) == tools::bigdecimal("-0.958882500674568"));
  assert_that(tools::bigdecimal("0.00094178").divide_and_copy(tools::bigdecimal("378.3"), 15) == tools::bigdecimal("0.000002489505683"));
  assert_that(tools::bigdecimal("7393100.0").divide_and_copy(tools::bigdecimal("9.9838"), 15) == tools::bigdecimal("740509.62559346140748"));
  assert_that(tools::bigdecimal("-0.00070613").divide_and_copy(tools::bigdecimal("-4489.9"), 15) == tools::bigdecimal("0.000000157270763"));
  assert_that(tools::bigdecimal("-0.16924").divide_and_copy(tools::bigdecimal("0.12616"), 15) == tools::bigdecimal("-1.34147114774889"));
  assert_that(static_cast<double>(tools::bigdecimal("0.00060849208430964892484")) == 0.000608492084309649);
  assert_that(static_cast<double>(tools::bigdecimal("-8367632.5457855285954")) == -8367632.545785529);
  assert_that(static_cast<double>(tools::bigdecimal("0.000000082904080060350542742")) == 8.290408006035054e-08);
  assert_that(static_cast<double>(tools::bigdecimal("-80536959647574109887000.0")) == -8.053695964757411e+22);
  assert_that(static_cast<double>(tools::bigdecimal("-38686373079212.849471")) == -38686373079212.85);
  assert_that(static_cast<double>(tools::bigdecimal("0.000000078537519721927027447")) == 7.853751972192703e-08);
  assert_that(static_cast<double>(tools::bigdecimal("4.4916641691544645264")) == 4.491664169154465);
  assert_that(static_cast<double>(tools::bigdecimal("-8729845389355269753400000000.0")) == -8.72984538935527e+27);
  assert_that(static_cast<double>(tools::bigdecimal("-7947717608030811285600.0")) == -7.947717608030811e+21);
  assert_that(static_cast<double>(tools::bigdecimal("-921.24546068561416098")) == -921.2454606856141);

  std::cout << "Hello World" << '\n';
  return 0;
}
