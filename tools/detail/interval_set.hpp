#ifndef TOOLS_DETAIL_INTERVAL_SET_HPP
#define TOOLS_DETAIL_INTERVAL_SET_HPP

#include <map>
#include <iterator>
#include <optional>
#include <utility>
#include <iostream>
#include <string>

namespace tools {
  namespace detail {
    template <typename T, bool Mergeable>
    class interval_set {
    private:
      // closed intervals
      std::map<T, T> m_intervals;
  
    public:
      interval_set() = default;
      interval_set(const tools::detail::interval_set<T, Mergeable>&) = default;
      interval_set(tools::detail::interval_set<T, Mergeable>&&) = default;
      ~interval_set() = default;
      tools::detail::interval_set<T, Mergeable>& operator=(const tools::detail::interval_set<T, Mergeable>&) = default;
      tools::detail::interval_set<T, Mergeable>& operator=(tools::detail::interval_set<T, Mergeable>&&) = default;
  
      auto begin() const {
        return this->m_intervals.begin();
      }
  
      auto end() const {
        return this->m_intervals.end();
      }
  
      bool empty() const {
        return this->m_intervals.empty();
      }
  
      auto size() const {
        return this->m_intervals.size();
      }
  
      auto find(const T& x) const {
        const auto next = this->m_intervals.upper_bound(x);
        if (next == this->m_intervals.begin()) return this->m_intervals.end();
        const auto prev = std::prev(next);
        if (prev->second < x) return this->m_intervals.end();
        return prev;
      }
  
      bool contains(const T& x) const {
        return this->find(x) != this->m_intervals.end();
      }
  
      auto lower_bound(const T& x) const {
        const auto next = this->m_intervals.lower_bound(x);
        if (next == this->m_intervals.begin()) return next;
        const auto prev = std::prev(next);
        if (prev->second < x) return next;
        return prev;
      }
  
      auto upper_bound(const T& x) const {
        return this->m_intervals.upper_bound(x);
      }
  
      void insert(const T& l, const T& r) {
        if (!(l <= r)) {
          return;
        }
  
        const auto l_it = this->find(l - (Mergeable ? 1 : 0));
        const T min = l_it != this->m_intervals.end() ? l_it->first : l;
        const auto r_it = this->find(r + (Mergeable ? 1 : 0));
        const T max = r_it != this->m_intervals.end() ? r_it->second : r;
  
        this->m_intervals.erase(this->lower_bound(l - (Mergeable ? 1 : 0)), this->upper_bound(r + (Mergeable ? 1 : 0)));
        this->m_intervals.emplace(min, max);
      }
  
      void erase(const T& l, const T& r) {
        if (!(l <= r + (Mergeable ? 0 : 1))) {
          return;
        }
  
        const auto l_it = this->find(l);
        const auto l_new_interval = l_it != this->m_intervals.end() && l_it->first <= l - (Mergeable ? 1 : 0)
          ? std::make_optional(std::make_pair(l_it->first, l - (Mergeable ? 1 : 0)))
          : std::nullopt;
        const auto r_it = this->find(r);
        const auto r_new_interval = r_it != this->m_intervals.end() && r + (Mergeable ? 1 : 0) <= r_it->second
          ? std::make_optional(std::make_pair(r + (Mergeable ? 1 : 0), r_it->second))
          : std::nullopt;
  
        this->m_intervals.erase(this->lower_bound(l), this->upper_bound(r));
  
        if (l_new_interval) {
          this->m_intervals.emplace(l_new_interval->first, l_new_interval->second);
        }
        if (r_new_interval) {
          this->m_intervals.emplace(r_new_interval->first, r_new_interval->second);
        }
      }
  
      friend std::ostream& operator<<(std::ostream& os, const tools::detail::interval_set<T, Mergeable>& self) {
        os << '{';
        std::string delimiter = "";
        for (const auto& [l, r] : self) {
          os << delimiter << '[' << l << ", " << r << ']';
          delimiter = ", ";
        }
        os << '}';
        return os;
      }
    };
  }
}

#endif
