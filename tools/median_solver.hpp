#ifndef TOOLS_MEDIAN_SOLVER_HPP
#define TOOLS_MEDIAN_SOLVER_HPP

#include <queue>
#include <vector>
#include <functional>
#include <cstddef>
#include <cassert>

namespace tools {

  /**
   * calculates the median of an array.
   * This also allows you to dynamically add values to the array.
   * License: CC0
   *
   * Usage:
   * ```
   * tools::median_solver<int> median;
   * median.push(5);
   * median.push(3);
   * median.push(7);
   * median.push(6);
   * median.query(); // => 5
   * ```
   *
   * @author anqooqie
   * @param <T> type of a value of the array
   */
  template <typename T>
  class median_solver {
  private:
    ::std::priority_queue<T, ::std::vector<T>, ::std::less<T>> pq1;
    ::std::priority_queue<T, ::std::vector<T>, ::std::greater<T>> pq2;

  public:
    median_solver() = default;
    median_solver(const median_solver&) = default;
    median_solver(median_solver&&) = default;
    ~median_solver() = default;
    median_solver& operator=(const median_solver&) = default;
    median_solver& operator=(median_solver&&) = default;

    void push(const T& v) {
      if ((this->pq1.size() + this->pq2.size()) % 2 == 0) {
        if (!this->pq2.empty() && v > this->pq2.top()) {
          this->pq1.push(this->pq2.top());
          this->pq2.pop();
          this->pq2.push(v);
        } else {
          this->pq1.push(v);
        }
      } else {
        if (v < this->pq1.top()) {
          this->pq2.push(this->pq1.top());
          this->pq1.pop();
          this->pq1.push(v);
        } else {
          this->pq2.push(v);
        }
      }
    }

    ::std::size_t size() const {
      return this->pq1.size() + this->pq2.size();
    }

    bool empty() const {
      return this->pq1.empty() && this->pq2.empty();
    }

    T query() const {
      assert(!this->empty());
      return this->pq1.top();
    }
  };
}

#endif
