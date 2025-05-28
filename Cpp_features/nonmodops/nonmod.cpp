

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>
using namespace std;
class myprinter {
    void operator()(int i) { std::cout << i << ", "; }
};
void print(const int &value)  // change argument to const int & value for set
{
  std::cout << value << " ";
}
struct Print {
    void operator()(const int &val) { std::cout << val << ' '; }
};
int main() {
  int            t[] = { 10, 2, 4, 3, 5, 6, 10, 8, 9, 10 };
  std::list<int> l1(t, t + 10);
  std::cout << "Print all elements of the container - using function\n";
  std::for_each(l1.begin(), l1.end(), print);
  std::cout << std::endl << std::endl;

  std::cout << "Print all elements of the container - using function object\n";
  std::for_each(l1.begin(), l1.end(), Print());
  std::cout << std::endl << std::endl;

  //!! Be aware of sets and maps !!
  // change arguments of function print and function object must be const
  std::set<int> s1(t, t + 10);

  std::cout << "Print all elements of the set - using function\n";
  std::for_each(s1.begin(), s1.end(), print);  // Compiler error is here if not const
  std::cout << std::endl << std::endl;

  std::cout << "Print all elements of the set - using function object\n";
  std::for_each(s1.begin(), s1.end(), *(new Print()));
  std::cout << std::endl << std::endl;
  deque<int> d1(t, t + 10);
  cout << "Look for the first even element in the container:\n";
  deque<int>::iterator found = find(d1.begin(), d1.end(), 10);
  if (found != d1.end()) {
    cout << "Value 10 found at position : " << distance(d1.begin(), found) << endl;
    cout << endl;
    cout << "Founding all remaining elements of value 10\n";
    ++found;  // skip element already found if any;
    while ((found = find(found, d1.end(), 10)) != d1.end()) {
      cout << "Next value 10 found at position : " << distance(d1.begin(), found) << endl;
      ++found;
    }
  } else {
    cout << "Value 10 not found\n";
  }
  std::cout << "Value" << std::distance(s1.begin(), s1.begin());
  std::list<int> l5(t, t + 10);
  std::list<int> l4(t, t + 5);
  auto           pair = std::mismatch(l5.begin(), l5.end(), l4.begin());
  std::cout << "Value" << (pair.second == l4.end()) << d1.end() - d1.begin();
  return 0;
}