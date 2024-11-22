#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <iostream>
#include <cstdint>
#include "tools/assert_that.hpp"
#include "tools/reverse.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(tools::reverse(false, 0) == false);
  assert_that(tools::reverse(false, 1) == false);
  assert_that(tools::reverse(true, 1) == true);

  assert_that(tools::reverse(INT8_C(0b00000000), 0) == INT8_C(0b00000000));
  assert_that(tools::reverse(INT8_C(0b00000000), 1) == INT8_C(0b00000000));
  assert_that(tools::reverse(INT8_C(0b00000001), 1) == INT8_C(0b00000001));
  assert_that(tools::reverse(INT8_C(0b00000000), 2) == INT8_C(0b00000000));
  assert_that(tools::reverse(INT8_C(0b00000001), 2) == INT8_C(0b00000010));
  assert_that(tools::reverse(INT8_C(0b00000010), 2) == INT8_C(0b00000001));
  assert_that(tools::reverse(INT8_C(0b00000011), 2) == INT8_C(0b00000011));
  assert_that(tools::reverse(INT8_C(0b00000000), 5) == INT8_C(0b00000000));
  assert_that(tools::reverse(INT8_C(0b00001100), 5) == INT8_C(0b00000110));
  assert_that(tools::reverse(INT8_C(0b00011111), 5) == INT8_C(0b00011111));
  assert_that(tools::reverse(INT8_C(0b00000000), 6) == INT8_C(0b00000000));
  assert_that(tools::reverse(INT8_C(0b00101100), 6) == INT8_C(0b00001101));
  assert_that(tools::reverse(INT8_C(0b00111111), 6) == INT8_C(0b00111111));
  assert_that(tools::reverse(INT8_C(0b00000000), 7) == INT8_C(0b00000000));
  assert_that(tools::reverse(INT8_C(0b00101100), 7) == INT8_C(0b00011010));
  assert_that(tools::reverse(INT8_C(0b01111111), 7) == INT8_C(0b01111111));

  assert_that(tools::reverse(UINT8_C(0b00000000), 0) == UINT8_C(0b00000000));
  assert_that(tools::reverse(UINT8_C(0b00000000), 1) == UINT8_C(0b00000000));
  assert_that(tools::reverse(UINT8_C(0b00000001), 1) == UINT8_C(0b00000001));
  assert_that(tools::reverse(UINT8_C(0b00000000), 2) == UINT8_C(0b00000000));
  assert_that(tools::reverse(UINT8_C(0b00000001), 2) == UINT8_C(0b00000010));
  assert_that(tools::reverse(UINT8_C(0b00000010), 2) == UINT8_C(0b00000001));
  assert_that(tools::reverse(UINT8_C(0b00000011), 2) == UINT8_C(0b00000011));
  assert_that(tools::reverse(UINT8_C(0b00000000), 5) == UINT8_C(0b00000000));
  assert_that(tools::reverse(UINT8_C(0b00001100), 5) == UINT8_C(0b00000110));
  assert_that(tools::reverse(UINT8_C(0b00011111), 5) == UINT8_C(0b00011111));
  assert_that(tools::reverse(UINT8_C(0b00000000), 7) == UINT8_C(0b00000000));
  assert_that(tools::reverse(UINT8_C(0b00101100), 7) == UINT8_C(0b00011010));
  assert_that(tools::reverse(UINT8_C(0b01111111), 7) == UINT8_C(0b01111111));
  assert_that(tools::reverse(UINT8_C(0b00000000), 8) == UINT8_C(0b00000000));
  assert_that(tools::reverse(UINT8_C(0b10101100), 8) == UINT8_C(0b00110101));
  assert_that(tools::reverse(UINT8_C(0b11111111), 8) == UINT8_C(0b11111111));

  assert_that(tools::reverse(INT16_C(0b0000000000000000), 0) == INT16_C(0b0000000000000000));
  assert_that(tools::reverse(INT16_C(0b0000000000000000), 1) == INT16_C(0b0000000000000000));
  assert_that(tools::reverse(INT16_C(0b0000000000000001), 1) == INT16_C(0b0000000000000001));
  assert_that(tools::reverse(INT16_C(0b0000000000000000), 2) == INT16_C(0b0000000000000000));
  assert_that(tools::reverse(INT16_C(0b0000000000000001), 2) == INT16_C(0b0000000000000010));
  assert_that(tools::reverse(INT16_C(0b0000000000000010), 2) == INT16_C(0b0000000000000001));
  assert_that(tools::reverse(INT16_C(0b0000000000000011), 2) == INT16_C(0b0000000000000011));
  assert_that(tools::reverse(INT16_C(0b0000000000000000), 9) == INT16_C(0b0000000000000000));
  assert_that(tools::reverse(INT16_C(0b0000000010101100), 9) == INT16_C(0b0000000001101010));
  assert_that(tools::reverse(INT16_C(0b0000000111111111), 9) == INT16_C(0b0000000111111111));
  assert_that(tools::reverse(INT16_C(0b0000000000000000), 14) == INT16_C(0b0000000000000000));
  assert_that(tools::reverse(INT16_C(0b0010100010101100), 14) == INT16_C(0b0000110101000101));
  assert_that(tools::reverse(INT16_C(0b0011111111111111), 14) == INT16_C(0b0011111111111111));
  assert_that(tools::reverse(INT16_C(0b0000000000000000), 15) == INT16_C(0b0000000000000000));
  assert_that(tools::reverse(INT16_C(0b0010100010101100), 15) == INT16_C(0b0001101010001010));
  assert_that(tools::reverse(INT16_C(0b0111111111111111), 15) == INT16_C(0b0111111111111111));

  assert_that(tools::reverse(UINT16_C(0b0000000000000000), 0) == UINT16_C(0b0000000000000000));
  assert_that(tools::reverse(UINT16_C(0b0000000000000000), 1) == UINT16_C(0b0000000000000000));
  assert_that(tools::reverse(UINT16_C(0b0000000000000001), 1) == UINT16_C(0b0000000000000001));
  assert_that(tools::reverse(UINT16_C(0b0000000000000000), 2) == UINT16_C(0b0000000000000000));
  assert_that(tools::reverse(UINT16_C(0b0000000000000001), 2) == UINT16_C(0b0000000000000010));
  assert_that(tools::reverse(UINT16_C(0b0000000000000010), 2) == UINT16_C(0b0000000000000001));
  assert_that(tools::reverse(UINT16_C(0b0000000000000011), 2) == UINT16_C(0b0000000000000011));
  assert_that(tools::reverse(UINT16_C(0b0000000000000000), 9) == UINT16_C(0b0000000000000000));
  assert_that(tools::reverse(UINT16_C(0b0000000010101100), 9) == UINT16_C(0b0000000001101010));
  assert_that(tools::reverse(UINT16_C(0b0000000111111111), 9) == UINT16_C(0b0000000111111111));
  assert_that(tools::reverse(UINT16_C(0b0000000000000000), 15) == UINT16_C(0b0000000000000000));
  assert_that(tools::reverse(UINT16_C(0b0010100010101100), 15) == UINT16_C(0b0001101010001010));
  assert_that(tools::reverse(UINT16_C(0b0111111111111111), 15) == UINT16_C(0b0111111111111111));
  assert_that(tools::reverse(UINT16_C(0b0000000000000000), 16) == UINT16_C(0b0000000000000000));
  assert_that(tools::reverse(UINT16_C(0b0010100010101100), 16) == UINT16_C(0b0011010100010100));
  assert_that(tools::reverse(UINT16_C(0b1111111111111111), 16) == UINT16_C(0b1111111111111111));

  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000000), 0) == INT32_C(0b00000000000000000000000000000000));
  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000000), 1) == INT32_C(0b00000000000000000000000000000000));
  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000001), 1) == INT32_C(0b00000000000000000000000000000001));
  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000000), 2) == INT32_C(0b00000000000000000000000000000000));
  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000001), 2) == INT32_C(0b00000000000000000000000000000010));
  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000010), 2) == INT32_C(0b00000000000000000000000000000001));
  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000011), 2) == INT32_C(0b00000000000000000000000000000011));
  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000000), 17) == INT32_C(0b00000000000000000000000000000000));
  assert_that(tools::reverse(INT32_C(0b00000000000000000010100010101100), 17) == INT32_C(0b00000000000000000110101000101000));
  assert_that(tools::reverse(INT32_C(0b00000000000000011111111111111111), 17) == INT32_C(0b00000000000000011111111111111111));
  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000000), 30) == INT32_C(0b00000000000000000000000000000000));
  assert_that(tools::reverse(INT32_C(0b00100000100010100010100010101100), 30) == INT32_C(0b00001101010001010001010001000001));
  assert_that(tools::reverse(INT32_C(0b00111111111111111111111111111111), 30) == INT32_C(0b00111111111111111111111111111111));
  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000000), 31) == INT32_C(0b00000000000000000000000000000000));
  assert_that(tools::reverse(INT32_C(0b00100000100010100010100010101100), 31) == INT32_C(0b00011010100010100010100010000010));
  assert_that(tools::reverse(INT32_C(0b01111111111111111111111111111111), 31) == INT32_C(0b01111111111111111111111111111111));

  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000000), 0) == UINT32_C(0b00000000000000000000000000000000));
  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000000), 1) == UINT32_C(0b00000000000000000000000000000000));
  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000001), 1) == UINT32_C(0b00000000000000000000000000000001));
  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000000), 2) == UINT32_C(0b00000000000000000000000000000000));
  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000001), 2) == UINT32_C(0b00000000000000000000000000000010));
  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000010), 2) == UINT32_C(0b00000000000000000000000000000001));
  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000011), 2) == UINT32_C(0b00000000000000000000000000000011));
  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000000), 17) == UINT32_C(0b00000000000000000000000000000000));
  assert_that(tools::reverse(UINT32_C(0b00000000000000000010100010101100), 17) == UINT32_C(0b00000000000000000110101000101000));
  assert_that(tools::reverse(UINT32_C(0b00000000000000011111111111111111), 17) == UINT32_C(0b00000000000000011111111111111111));
  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000000), 31) == UINT32_C(0b00000000000000000000000000000000));
  assert_that(tools::reverse(UINT32_C(0b00100000100010100010100010101100), 31) == UINT32_C(0b00011010100010100010100010000010));
  assert_that(tools::reverse(UINT32_C(0b01111111111111111111111111111111), 31) == UINT32_C(0b01111111111111111111111111111111));
  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000000), 32) == UINT32_C(0b00000000000000000000000000000000));
  assert_that(tools::reverse(UINT32_C(0b10100000100010100010100010101100), 32) == UINT32_C(0b00110101000101000101000100000101));
  assert_that(tools::reverse(UINT32_C(0b11111111111111111111111111111111), 32) == UINT32_C(0b11111111111111111111111111111111));

  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000), 0) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));
  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000), 1) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));
  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000001), 1) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));
  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000), 2) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));
  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000001), 2) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));
  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000010), 2) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));
  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000011), 2) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000011));
  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000), 33) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));
  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000010100000100010100010100010101100), 33) == INT64_C(0b0000000000000000000000000000000001101010001010001010001000001010));
  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000111111111111111111111111111111111), 33) == INT64_C(0b0000000000000000000000000000000111111111111111111111111111111111));
  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000), 62) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));
  assert_that(tools::reverse(INT64_C(0b0010100000100000100010100010000010100000100010100010100010101100), 62) == INT64_C(0b0000110101000101000101000100000101000001000101000100000100000101));
  assert_that(tools::reverse(INT64_C(0b0011111111111111111111111111111111111111111111111111111111111111), 62) == INT64_C(0b0011111111111111111111111111111111111111111111111111111111111111));
  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000), 63) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));
  assert_that(tools::reverse(INT64_C(0b0010100000100000100010100010000010100000100010100010100010101100), 63) == INT64_C(0b0001101010001010001010001000001010000010001010001000001000001010));
  assert_that(tools::reverse(INT64_C(0b0111111111111111111111111111111111111111111111111111111111111111), 63) == INT64_C(0b0111111111111111111111111111111111111111111111111111111111111111));

  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000), 0) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));
  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000), 1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));
  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001), 1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));
  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000), 2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));
  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001), 2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));
  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010), 2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));
  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000011), 2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000011));
  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000), 33) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));
  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000010100000100010100010100010101100), 33) == UINT64_C(0b0000000000000000000000000000000001101010001010001010001000001010));
  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000111111111111111111111111111111111), 33) == UINT64_C(0b0000000000000000000000000000000111111111111111111111111111111111));
  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000), 63) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));
  assert_that(tools::reverse(UINT64_C(0b0010100000100000100010100010000010100000100010100010100010101100), 63) == UINT64_C(0b0001101010001010001010001000001010000010001010001000001000001010));
  assert_that(tools::reverse(UINT64_C(0b0111111111111111111111111111111111111111111111111111111111111111), 63) == UINT64_C(0b0111111111111111111111111111111111111111111111111111111111111111));
  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000), 64) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));
  assert_that(tools::reverse(UINT64_C(0b0010100000100000100010100010000010100000100010100010100010101100), 64) == UINT64_C(0b0011010100010100010100010000010100000100010100010000010000010100));
  assert_that(tools::reverse(UINT64_C(0b1111111111111111111111111111111111111111111111111111111111111111), 64) == UINT64_C(0b1111111111111111111111111111111111111111111111111111111111111111));

  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000000LL, 0) == 0b0000000000000000000000000000000000000000000000000000000000000000LL);
  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000000LL, 1) == 0b0000000000000000000000000000000000000000000000000000000000000000LL);
  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000001LL, 1) == 0b0000000000000000000000000000000000000000000000000000000000000001LL);
  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000000LL, 2) == 0b0000000000000000000000000000000000000000000000000000000000000000LL);
  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000001LL, 2) == 0b0000000000000000000000000000000000000000000000000000000000000010LL);
  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000010LL, 2) == 0b0000000000000000000000000000000000000000000000000000000000000001LL);
  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000011LL, 2) == 0b0000000000000000000000000000000000000000000000000000000000000011LL);
  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000000LL, 33) == 0b0000000000000000000000000000000000000000000000000000000000000000LL);
  assert_that(tools::reverse(0b0000000000000000000000000000000010100000100010100010100010101100LL, 33) == 0b0000000000000000000000000000000001101010001010001010001000001010LL);
  assert_that(tools::reverse(0b0000000000000000000000000000000111111111111111111111111111111111LL, 33) == 0b0000000000000000000000000000000111111111111111111111111111111111LL);
  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000000LL, 62) == 0b0000000000000000000000000000000000000000000000000000000000000000LL);
  assert_that(tools::reverse(0b0010100000100000100010100010000010100000100010100010100010101100LL, 62) == 0b0000110101000101000101000100000101000001000101000100000100000101LL);
  assert_that(tools::reverse(0b0011111111111111111111111111111111111111111111111111111111111111LL, 62) == 0b0011111111111111111111111111111111111111111111111111111111111111LL);
  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000000LL, 63) == 0b0000000000000000000000000000000000000000000000000000000000000000LL);
  assert_that(tools::reverse(0b0010100000100000100010100010000010100000100010100010100010101100LL, 63) == 0b0001101010001010001010001000001010000010001010001000001000001010LL);
  assert_that(tools::reverse(0b0111111111111111111111111111111111111111111111111111111111111111LL, 63) == 0b0111111111111111111111111111111111111111111111111111111111111111LL);

  std::cout << "Hello World" << '\n';
  return 0;
}
