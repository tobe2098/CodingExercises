

#include <iostream>
#include <vector>

int main(void) {
  std::vector<int> v(10);

  auto it = v.begin() + 6;
  *it     = 8;
  it--;
  v.erase(it);
  std::cout << *it;
  std::cout << v.end() - v.begin();
  return 0;
}