#pragma once

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>

constexpr std::size_t max_size{10};

int factorial(int iVal);

template <class T, std::size_t S>
struct std_11_simple_allocator {
  using value_type = T;
  std::size_t m_size = S;

  void *m_memory = nullptr;
  std::size_t m_cnt = 0;

  std_11_simple_allocator() noexcept {}

  template <class U, std::size_t N>
  std_11_simple_allocator(const std_11_simple_allocator<U, N> &) noexcept {}

  ~std_11_simple_allocator() {
    if (m_memory != nullptr) {
      m_cnt = 0;
      free(m_memory);
      m_memory = nullptr;
    }
  }

  template <class U>
  struct rebind {
    using other = std_11_simple_allocator<U, S>;
  };

  T *allocate(std::size_t n) {
    if (m_memory == nullptr) {
      m_memory = malloc(max_size * sizeof(T));

      if (m_memory == nullptr) {
        throw std::bad_alloc();
      }

      std::cout << "init ok " << (void *)m_memory << std::endl;
    } else if (n > max_size) {
      std::cout << "fault" << std::endl;

      throw std::bad_alloc();
    }

    if (m_cnt + n <= max_size) {
      auto chunk = reinterpret_cast<T *>(m_memory) + m_cnt;
      m_cnt += n;
      std::cout << "all: " << (void *)chunk << std::endl;
      return chunk;
    } else {
      std::cout << "all ERROR CNT" << std::endl;
      throw std::bad_alloc();
    }
  }

  void deallocate([[maybe_unused]] T *p, [[maybe_unused]] std::size_t n) {
    // ::operator delete(p);
  }
};

template <class T, std::size_t U, class TA, std::size_t UA>
constexpr bool operator==(
    [[maybe_unused]] const std_11_simple_allocator<T, U> &a1,
    [[maybe_unused]] const std_11_simple_allocator<TA, UA> &a2) noexcept {
  return true;
}

template <class T, std::size_t U, class TA, std::size_t UA>
constexpr bool operator!=(
    [[maybe_unused]] const std_11_simple_allocator<T, U> &a1,
    [[maybe_unused]] const std_11_simple_allocator<TA, UA> &a2) noexcept {
  return false;
}