#include <algorithm>
#include <deque>
#include <format>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
template <class C>
void print(const C& container) {
  for (unsigned i = 0; i < container.size(); ++i) {
    std::cout << container[i] << " ";
  }
  std::cout << std::endl;
}
struct Generator {
    int curr {};
    int operator()() { return ++curr; }
};

int main(void) {
  std::vector<int> myvec(10);
  std::generate(myvec.begin(), myvec.end(), rand);
  std::list<int> mylist(10);
  int            i {};
  std::generate(mylist.begin(), mylist.end(), [&i] { return i++; });
  std::deque<int> deck(10);
  std::generate(deck.begin(), deck.end(), Generator());
  deck.erase(deck.cbegin(), deck.cend());
  std::priority_queue<int> pq;
  print(deck);
  // std::cout << std::format("{0}\n", deck);
  // std::priority_queue<int, std::vector<int>> pqv(myvec); //Constructor does not accept containers
  std::priority_queue<int>          pq2(pq);
  std::queue<int, std::vector<int>> queeu;
  // std::queue<int, std::vector<int>> queeu2(myvec); //DO not use

  std::queue<int, std::list<int>> queeu2(mylist);

  std::stack<int, std::list<int>> st(mylist);
  mylist.clear();
  std::cout << st.size() << '\n';
  std::cout << queeu2.size() << '\n';
  std::cout << mylist.size();

  // myvec.at(11) = 1;
  queeu.push(10);
  queeu.push(10);
  queeu.push(10);
  queeu.push(10);

  std::priority_queue<int, std::vector<int>, std::less<int>> q4(std::less<int>(), myvec);
  q4.push(1);
  auto it = mylist.cbegin();
  std::advance(it, 1);
  // queeu2.pop();
  return 0;
}