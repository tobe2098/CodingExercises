
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
void myprint(std::pair<int, int> i) {
  std::cout << i.first << " ,";
}

int main() {
  int                mynumbers[] = { 3, 9, 0, 2, 1, 4, 5 };
  std::map<int, int> m;
  for (int i = 0; i < 7; i++) {
    m[i] = mynumbers[i];
  }
  std::for_each(m.begin(), m.end(), myprint);
  std::cout << m.size();

  std::set<int> s(mynumbers, mynumbers + 7);
  std::cout << std::equal(s.begin(), s.end(), s.begin()) << std::endl;
}