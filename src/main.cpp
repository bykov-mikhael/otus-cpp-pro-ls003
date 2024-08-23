#include <iostream>
#include <map>
#include <utility>

#include "allocator.hpp"
#include "custom_list.hpp"

int main() {
  std::map<int, int> m1;
  for (int i = 0; i < 10; ++i) m1[i] = factorial(i);

  std::map<int, int, std::less<int>, Alloc<10, std::pair<const int, int>>> m2;
  for (int i = 0; i < 10; ++i) m2[i] = factorial(i);

  for (const auto& [key, value] : m2) {
    std::cout << key << " " << value << std::endl;
  }

  List<int> l1;
  for (int i = 0; i < 10; ++i) {
    l1.push_back(factorial(i));
  }

  List<int, Alloc<10, Link<int>>> l2;
  for (int i = 0; i < 10; ++i) {
    l2.push_back(factorial(i));
  }

  for (auto it = l2.begin(); it != l2.end(); ++it) {
    std::cout << *it << std::endl;
  }

  return 0;
}
