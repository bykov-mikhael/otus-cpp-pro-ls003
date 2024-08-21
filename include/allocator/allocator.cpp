#include "allocator.hpp"

/*
 * Рекурсивная функция вычисления факториала
 */
int factorial(int iVal) {
  if (iVal == 0) {
    return 1;
  } else {
    return iVal * factorial(iVal - 1);
  }
}