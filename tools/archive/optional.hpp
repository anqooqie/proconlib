#ifndef OPTIONAL_HPP
#define OPTIONAL_HPP

#include <stdexcept>

namespace tools {
  template <typename T>
  class optional {
  private:
    bool m_has_value;
    T m_value;

  public:
    optional() :
      m_has_value(false),
      m_value() {
    }

    optional(const T& other) :
      m_has_value(true),
      m_value(other) {
    }

    optional<T>& operator=(const T& other) {
      this->m_has_value = true;
      this->m_value = other;
    }

    ~optional() {
      this->m_value.~T();
    }

    T& operator*() {
      return this->value();
    }
    const T& operator*() const {
      return this->value();
    }

    explicit operator bool() const {
      return this->has_value();
    }

    void reset() {
      this->m_has_value = false;
    }

    bool has_value() const {
      return this->m_has_value;
    }

    T& value() {
      if (!this->m_has_value) throw std::range_error("Optional has no valid value.");
      return this->m_value;
    }
    const T& value() const {
      if (!this->m_has_value) throw std::range_error("Optional has no valid value.");
      return this->m_value;
    }

    T value_or(const T& default_value) const {
      return this->m_has_value ? this->m_value : default_value;
    }
  };
}

#endif
