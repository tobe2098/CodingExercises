#ifndef _VARIADIC_EXAMPLES_HEADER_
#define _VARIADIC_EXAMPLES_HEADER_

#include <cstdarg>
#include <iostream>
#include <utility>
// C-style variadic

void printSum(int count, ...) {
  va_list args;
  va_start(args, count);

  int sum = 0;
  for (int i = 0; i < count; ++i) {
    sum += va_arg(args, int);
  }

  va_end(args);
  std::cout << "Sum: " << sum << '\n';
}

enum ArgType { INT, DOUBLE, STRING };

void printArgs(int count, ...) {
  va_list args;
  va_start(args, count);

  for (int i = 0; i < count; ++i) {
    ArgType type = static_cast<ArgType>(va_arg(args, int));  // Read type marker

    switch (type) {
      case INT:
        std::cout << va_arg(args, int) << " ";
        break;
      case DOUBLE:
        std::cout << va_arg(args, double) << " ";
        break;
      case STRING:
        std::cout << va_arg(args, const char*) << " ";
        break;
    }
  }

  va_end(args);
  std::cout << '\n';
}
// Sub
void sum(std::initializer_list<int> nums) {
  int total = 0;
  for (int num : nums) {
    total += num;
  }
  std::cout << "Sum: " << total << '\n';
}

// SFINAE

template <typename T, typename... Args>
typename std::enable_if<std::is_integral<T>::value>::type printInts(T first, Args... rest) {
  std::cout << first << ' ';
  printInts(rest...);
}

void printInts() {
  std::cout << '\n';
}

// Perfect forwarding of args
template <typename... Args>
void forwardAll(Args&&... args) {
  ((std::cout << std::forward<Args>(args) << ' '), ...) << '\n';
}

template <typename... Args>
void forwardAll2(Args&&... args) {
  (void)std::initializer_list<int> { (std::cout << std::forward<Args>(args) << ' ', 0)... };
  std::cout << '\n';
}
// Variadic templates
template <typename... Args>
void printAll(Args... args) {
  (std::cout << ... << args) << '\n';  // Fold expression (C++17)
}

void printAll2() {
  std::cout << '\n';
}  // Base case
template <typename T, typename... Args>
void printAll2(T first, Args... rest) {
  std::cout << first << ' ';
  printAll(rest...);
}
#endif