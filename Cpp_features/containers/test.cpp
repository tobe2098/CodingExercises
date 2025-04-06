#include <deque>
#include <iostream>
#include <list>
#include <vector>
class A {
  public:
    int a;
    A(int a): a(a) { }
    // A(const A& a) { }
};

std::ostream& operator<<(std::ostream& o, const A& a) {
  o << a.a;
  return o;
}
template <typename T>
std::ostream& print(T const& start, T const& end) {  // Must be lvalue or const ref or mvoe I guess
  for (T i = start; i != end; i++) {
    std::cout << *i << " ";
  }
  return std::cout;
}
void fill(int table[], unsigned size, std::vector<A*>& v) {
  for (unsigned i = 0; i < size; ++i) {
    v.push_back(new A(table[i]));
  }
}

int main(void) {
  std::vector<int> v1(10);
  for (int i = 1; i <= 10; i++) {
    v1[i - 1] = i;
  }
  std::vector<int> v2;
  for (auto it = v1.begin(); it != v1.end(); it++) {
    v2.push_back(v1[v1.end() - it - 1]);
  }
  print(v2.rbegin(), v2.rend()) << std::endl;
  int            tab[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  std::list<int> l1(tab, tab + 10);
  // std::list<int>::const_iterator it = l1.begin()+3;  // No random access in lists
  print(l1.begin(), l1.end());
  // l1.erase(it, std::advance(it, 1));
  l1.clear();
  // int             tab[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  std::vector<A*> v3;
  fill(tab, 10, v3);

  std::vector<A*>::iterator it3 = v3.begin();
  std::cout << **it3 << std::endl;
  std::list<A> l3;
  for (it3 = v3.begin(); it3 != v3.end(); ++it3) {
    l3.push_front(**it3);
  }
  std::cout << **v3.begin() << std::endl;
  std::cout << *v3.begin() << std::endl;
  std::cout << **(it3 - 1) << std::endl;
  print(l3.begin(), l3.end()) << std::endl;  // LINE I

  std::list<A>  l5(tab, tab + 10);
  std::deque<A> d1;
  print(d1.rbegin(), d1.rend());
  // std::list<A>::iterator it;
  // for (it = l5.begin(); it != l5.end(); it++) {
  //   d1.insert(d1.begin(), it[0]);
  //   d1.insert(d1.begin(), it);
  // }
  return 0;
}