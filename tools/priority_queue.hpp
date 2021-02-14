#ifndef TOOLS_PRIORITY_QUEUE_HPP
#define TOOLS_PRIORITY_QUEUE_HPP

#include <functional>
#include <utility>
#include <queue>
#include <vector>
#include <unordered_map>

namespace tools {

  /**
   * updatable priority queue
   * License: CC0
   *
   * Usage:
   * ```
   * tools::priority_queue<std::string, int> pq;
   * pq.push(std::make_pair("abc", 5));
   * const std::pair<std::string, int> pair = pq.top();
   * pq.push(std::make_pair("abc", 7));
   * pq.erase("abc");
   * ```
   *
   * @author anqooqie
   * @param <T> type of key
   * @param <Priority> type of priority
   */
  template <class T, class Priority, class Compare = ::std::less<Priority>>
  class priority_queue {
  private:
    class compare_by_priority {
    private:
      Compare compare;

    public:
      compare_by_priority(const Compare& compare) : compare(compare) {
      }

      bool operator()(const ::std::pair<T, Priority>& x, const ::std::pair<T, Priority>& y) const {
        return this->compare(x.second, y.second) || (!this->compare(x.second, y.second) && !this->compare(y.second, x.second) && x.first < y.first);
      }
    };

    ::std::priority_queue<::std::pair<T, Priority>, ::std::vector<::std::pair<T, Priority>>, compare_by_priority> heap;
    ::std::priority_queue<::std::pair<T, Priority>, ::std::vector<::std::pair<T, Priority>>, compare_by_priority> outdated;
    ::std::unordered_map<T, Priority> latest_priority;

  public:
    using container_type = ::std::vector<::std::pair<T, Priority>>;
    using value_type = typename container_type::value_type;
    using reference = typename container_type::reference;
    using const_reference = typename container_type::const_reference;
    using size_type = typename container_type::size_type;

    explicit priority_queue(const Compare& compare = Compare()) : heap(compare), outdated(compare) {
    }
    priority_queue(const priority_queue&) = default;
    priority_queue(priority_queue&&) = default;
    ~priority_queue() = default;
    priority_queue& operator=(const priority_queue&) = default;
    priority_queue& operator=(priority_queue&&) = default;

    bool empty() const {
      return this->latest_priority.empty();
    }

    size_type size() const {
      return this->latest_priority.size();
    }

    Priority at(const T& k) const {
      return this->latest_priority.at(k);
    }

    const_reference top() {
      while (!this->outdated.empty() && this->outdated.top() == this->heap.top()) {
        this->outdated.pop();
        this->heap.pop();
      }
      return this->heap.top();
    }

    void push(const value_type& x) {
      if (auto it = this->latest_priority.find(x.first); it != this->latest_priority.end()) {
        if (it->second == x.second) return;
        this->outdated.push(*it);
        this->heap.push(x);
        it->second = x.second;
      } else {
        this->heap.push(x);
        this->latest_priority.insert(x);
      }
    }

    void pop() {
      while (!this->outdated.empty() && this->outdated.top() == this->heap.top()) {
        this->outdated.pop();
        this->heap.pop();
      }
      this->latest_priority.erase(this->heap.top().first);
      this->heap.pop();
    }

    size_type erase(const T& k) {
      if (auto it = this->latest_priority.find(k); it != this->latest_priority.end()) {
        this->outdated.push(*it);
        this->latest_priority.erase(it);
        return 1;
      } else {
        return 0;
      }
    }
  };
}

#endif
