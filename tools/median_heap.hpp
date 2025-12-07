#ifndef TOOLS_MEDIAN_HEAP_HPP
#define TOOLS_MEDIAN_HEAP_HPP

#include <functional>
#include <queue>
#include <vector>
#include <cstddef>
#include <cassert>

namespace tools {

  template <typename T, typename Compare = std::less<T>>
  class median_heap {
  private:
    class RevCompare {
    private:
      Compare m_less;
    public:
      explicit RevCompare(const Compare& less) : m_less(less) {
      }
      bool operator()(const T& x, const T& y) const {
        return this->m_less(y, x);
      }
    };

    Compare m_less;
    std::priority_queue<T, std::vector<T>, Compare> m_pq1;
    std::priority_queue<T, std::vector<T>, RevCompare> m_pq2;

  public:
    explicit median_heap(const Compare& less) : m_less(less), m_pq1(less), m_pq2(RevCompare(less)) {
    }
    median_heap() : median_heap(Compare()) {
    }
    median_heap(const tools::median_heap<T, Compare>&) = default;
    median_heap(tools::median_heap<T, Compare>&&) = default;
    ~median_heap() = default;
    tools::median_heap<T, Compare>& operator=(const tools::median_heap<T, Compare>&) = default;
    tools::median_heap<T, Compare>& operator=(tools::median_heap<T, Compare>&&) = default;

    bool empty() const {
      return this->m_pq1.empty() && this->m_pq2.empty();
    }

    std::size_t size() const {
      return this->m_pq1.size() + this->m_pq2.size();
    }

    T lesser() const {
      assert(!this->empty());
      return this->m_pq1.top();
    }

    T greater() const {
      assert(!this->empty());
      return this->m_pq1.size() == this->m_pq2.size() ? this->m_pq2.top() : this->m_pq1.top();
    }

    void push(const T& v) {
      if (this->m_pq1.size() == this->m_pq2.size()) {
        if (!this->m_pq2.empty() && this->m_less(this->m_pq2.top(), v)) {
          this->m_pq1.push(this->m_pq2.top());
          this->m_pq2.pop();
          this->m_pq2.push(v);
        } else {
          this->m_pq1.push(v);
        }
      } else {
        if (this->m_less(v, this->m_pq1.top())) {
          this->m_pq2.push(this->m_pq1.top());
          this->m_pq1.pop();
          this->m_pq1.push(v);
        } else {
          this->m_pq2.push(v);
        }
      }
    }

    template <typename... Args>
    void emplace(Args&&... args) {
      this->push(T(std::forward<Args>(args)...));
    }

    void swap(tools::median_heap<T, Compare>& other) {
      std::swap(this->m_less, other.m_less);
      this->m_pq1.swap(other.m_pq1);
      this->m_pq2.swap(other.m_pq2);
    }
  };
}

#endif
