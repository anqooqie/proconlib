// competitive-verifier: STANDALONE

#include <iostream>
#include <string>
#include <utility>
#include "tools/assert_that.hpp"
#include "tools/getter_result.hpp"

enum class origin_type {
  default_constructor,
  copy_constructor,
  move_constructor,
  copy_assign,
  move_assign,
};

class inner_type {
  origin_type m_origin;

public:
  constexpr inner_type() : m_origin(origin_type::default_constructor) {
  }
  constexpr inner_type(const inner_type&) : m_origin(origin_type::copy_constructor) {
  }
  constexpr inner_type(inner_type&&) noexcept : m_origin(origin_type::move_constructor) {
  }
  constexpr inner_type& operator=(const inner_type&) {
    this->m_origin = origin_type::copy_assign;
    return *this;
  }
  constexpr inner_type& operator=(inner_type&&) noexcept {
    this->m_origin = origin_type::move_assign;
    return *this;
  }

  constexpr origin_type origin() const {
    return this->m_origin;
  }
};

class outer_type {
  inner_type m_inner;

public:
  constexpr outer_type() = default;

  constexpr auto inner(this auto&& self) -> tools::getter_result_t<decltype(self), inner_type> {
    return std::forward_like<decltype(self)>(self.m_inner);
  }
};

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  outer_type case1{};
  static_assert(std::same_as<decltype(case1.inner()), const inner_type&>);
  assert_that(case1.inner().origin() == origin_type::default_constructor);

  constexpr outer_type case2{};
  static_assert(std::same_as<decltype(case2.inner()), const inner_type&>);
  static_assert(case2.inner().origin() == origin_type::default_constructor);

  static_assert(std::same_as<decltype(outer_type{}.inner()), inner_type>);
  static_assert(outer_type{}.inner().origin() == origin_type::move_constructor);

  static_assert(std::same_as<decltype(static_cast<const outer_type>(outer_type{}).inner()), inner_type>);
  static_assert(static_cast<const outer_type>(outer_type{}).inner().origin() == origin_type::copy_constructor); 

  return 0;
}
