#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class A {
    int a;

  public:
    A(int a): a(a) { }
    operator int() { return a; }
    int  getA() const { return a; }
    bool operator<(const A& b) const { return a < b.a; }
};

template <typename T>
void print(const T& start, const T& end) {
  T it = start;
  while (it != end) {
    std::cout << *(it)++ << ' ';
  }
  std::cout << '\n';
}

int main(void) {
  // int mynumbers1[] = { 3, 9, 2, 4, 4 };

  // std::set<int, std::greater<int>> myset(mynumbers1, mynumbers1 + 5);
  // myset.insert(mynumbers1, mynumbers1 + 5);
  // if (myset.count(4) == 2) {
  //   std::cout << "It worked";
  // }
  // print(myset.begin(), myset.end());
  // std::multiset<int, std::greater_equal<int>> mset(myset.begin(), myset.end());
  // print(mset.begin(), mset.end());
  // std::set<A> set(mynumbers1, mynumbers1 + 2);
  // std::cout << set.begin()->getA();
  // std::map<int, int> map;
  // map.insert({ 1, 1 });
  // map.insert({ 1, 2 });
  // std::cout << map[1];
  // std::pair<int, std::string>  p { 1, "aa" };
  // std::set<int, int>::iterator it = myset.begin();
  // while (it != myset.end()) {
  //   std::cout << *it << ' ';
  //   it++;
  // }
  // std::cout << std::endl;
  // int mynumbers2[] = { 3, 9, 0, 2, 1, 4, 5 };

  // std::vector<int> v2(mynumbers2, mynumbers2 + 7);
  // std::set<int>    s1(v2.begin(), v2.end());
  // s1.insert(v2.begin(), v2.end());
  // s1.insert(10);
  // s1.erase(s1.lower_bound(4), s1.upper_bound(6));
  // s1.insert(v2.begin(), v2.end());
  // print(s1.begin(), s1.end());
  // std::cout << s1.size() << std::endl;
  // std::stringstream s;
  // s.str();
  int                      mynumbers2[] = { 3, 9, 0, 2, 1, 4, 5 };
  std::string              words[]      = { "three", "nine", "zero", "two", "one", "four", "five" };
  std::map<A, std::string> m;
  for (int i = 0; i < 7; i++) {
    m.insert(std::pair<A, std::string>(A(mynumbers2[i]), words[i]));
  }
  m.erase(m.lower_bound(3), m.upper_bound(4));
  for (auto it = m.begin(); it != m.end(); it++) {
    std::cout << it->second << ' ';
  }

  return 0;
}