#include <algorithm>
#include <deque>
#include <iostream>
#include <set>
#include <vector>
void print(int i) {
  std::cout << i << ", ";
}
struct Seq {
    int num;

    Seq(int start): num(start) { }
    int operator()() { return num++; }
};
bool pred(int i) {
  return i % 2 == 0;
}
int main(void) {
  std::vector<int> v1(7);
  std::generate_n(v1.begin(), 7, Seq(1));
  std::remove_if(v1.begin(), v1.end(), pred);
  std::for_each(v1.begin(), v1.end(), print);
  return 0;
}