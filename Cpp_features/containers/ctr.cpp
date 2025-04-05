#include <iostream>
#include <vector>

using namespace std;
class A {
    int number;
    int number2;

  public:
    explicit A(int _number): number(_number), number2(0) { cout << "Normal constructor\n"; }
    A() { cout << "Default constructor\n"; }

    A(const A& source) {
      number  = source.number;
      number2 = source.number2;
      cout << "Copy constructor\n";
    }

    A& operator=(const A& source) {
      number  = source.number;
      number2 = source.number2;
      cout << "Assignment operator\n";
      return *this;
    }
};
int main() {
  vector<A> v1;        //(1)
  v1.push_back(A(1));  //(1)
  cout << "First ready!\n";
  // copy constructor
  vector<A> v2(v1);  //(2)
  cout << "Second ready!\n";
  // assignment operator - empty target
  vector<A> v3;  //(3)
  v3 = v2;       //(3)
  cout << "Third ready!\n";
  // assignment - not empty target
  vector<A> v4(2);  //(4)
  v4 = v2;          //(4)
  return 0;
}