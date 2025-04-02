#ifndef _PRINT_HEADER_
#define _PRINT_HEADER_
#include <cstdarg>
#include <iostream>
void printFormatted(const char* format, ...) {
  va_list args;
  va_start(args, format);

  while (*format) {
    if (*format == '%') {
      switch (*++format) {
        case 'd':
          std::cout << va_arg(args, int) << " ";
          break;
        case 'f':
          std::cout << va_arg(args, double) << " ";
          break;
        case 's':
          std::cout << va_arg(args, const char*) << " ";
          break;
        default:
          std::cerr << "Unknown format specifier\n";
          break;
      }
    } else {
      std::cout << *format;
    }
    format++;
  }

  va_end(args);
  std::cout << '\n';
}
#endif