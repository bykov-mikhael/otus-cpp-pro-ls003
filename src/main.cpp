#include <allocator.hpp>
#include <cstddef>
#include <cstdlib>
#include <custom_list.hpp>
#include <iostream>
#include <map>
#include <utility>

int main() {
  /*
   * - создание экземпляра std::map<int, int> со стандартным аллокатором
   */
  std::map<int, int> mMap001;

  for (size_t stSize = 0; stSize < 10; stSize++) {
    mMap001.insert(std::pair<int, int>(stSize, factorial(stSize)));
  }

  for (auto it001 = mMap001.begin(); it001 != mMap001.end(); it001++) {
    std::cout << it001->first << " - " << it001->second << std::endl;
  }

  /*
   * - создание экземпляра std::map<int, int> с новым аллокатором, ограниченным
   * 10 элементами
   */
  std::map<int, int, std::less<int>,
           std_11_simple_allocator<std::pair<const int, int>, 10>>
      mMap002;

  for (size_t stSize = 0; stSize < 10; stSize++) {
    mMap002.insert(std::pair<int, int>(stSize, factorial(stSize)));
  }

  for (auto it = mMap002.begin(); it != mMap002.end(); it++) {
    std::cout << it->first << " - " << it->second << std::endl;
  }

  /*
   * - создание экземпляра своего контейнера со стандартным аллокатором
   */

  return EXIT_SUCCESS;
}