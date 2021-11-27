---
title: Binary heap
documentation_of: //tools/binary_heap.hpp
---

It manages the maximum element efficiently.
It also allows you to update the priority of any elements.

### Usage
```cpp
tools::binary_heap<std::string, int> heap;
heap.push(std::make_pair("abc", 5));
const std::pair<std::string, int> pair = heap.top();
heap.push(std::make_pair("abc", 7));
heap.erase("abc");
```

### References
- [優先度変更可能なヒープについて - えびちゃんの日記](https://rsk0315.hatenablog.com/entry/2019/10/29/173703)

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
binary_heap<Key, Priority, std::less<Priority>> heap();
binary_heap<Key, Priority, Compare> heap(Compare compare);
```

It creates a empty max heap which uses `compare` as a comparator.
The type parameter `<Key>` represents the type of keys.
The type parameter `<Priority>` represents the type of the priorities correspanding to each key.
The type parameter `<Compare>` represents the type of the comparator.

### Constraints
- None

### Time Complexity
- $O(1)$

## empty
```cpp
bool heap.empty();
```

It returns `true` if and only if the heap is empty.
Otherwise, it returns `false`.

### Constraints
- None

### Time Complexity
- $O(1)$

## size
```cpp
std::size_t heap.size();
```

It returns the current number of elements of the heap.

### Constraints
- None

### Time Complexity
- $O(1)$

## top
```cpp
std::pair<Key, Priority> heap.top();
```

It returns the maximum element of the heap.

### Constraints
- The heap is not empty.

### Time Complexity
- $O(1)$

## at
```cpp
Priority heap.at(Key k);
```

It returns the priority of `k`.

### Constraints
- `k` exists in the heap.

### Time Complexity
- $O(1)$

## push
```cpp
bool heap.push(std::pair<Key, Priority> x);
```

If `x.first` does not exist in the heap, it inserts `x.first` whose priority is `x.second` into the heap and returns `true`.
If `x.first` exists in the heap, it updates the priority of `x.first` to `x.second` and returns `false`.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where n is the current number of elements of the heap

## emplace
```cpp
bool heap.emplace(Key k, Priority p);
```

It returns `heap.push(std::make_pair(k, p))`.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where n is the current number of elements of the heap

## pop
```cpp
void heap.pop();
```

It removes the maximum element from the heap.

### Constraints
- The heap is not empty.

### Time Complexity
- $O(\log n)$ where n is the current number of elements of the heap

## erase
```cpp
std::size_t heap.erase(Key k);
```

If `k` exists in the heap, it removes `k` from the heap and returns $1$.
If `k` does not exist in the heap, it returns $0$.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where n is the current number of elements of the heap
