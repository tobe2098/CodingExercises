#include "print.hpp"
#include "variadic.hpp"
//

int main(void) {
  //
  printAll(1, 2, "Hello");
  printAll2(1, 2, "hello\n");
  printAll2();
  printAll();
  //
  forwardAll(1, 2, "hello\n");
  forwardAll2(1, 2, "hello\n");
  //
  sum({ 1, 2, 3 });
  //
  printSum(3, 1, 2, 3);
  printArgs(3, INT, 3, DOUBLE, 3.14, STRING, "Hello World");
  //
  printFormatted("This is a number %d, this is not %s", 3.14, "End\n");
  // printf("%s");

  return 0;
}