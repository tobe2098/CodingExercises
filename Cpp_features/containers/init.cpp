#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
int main(void) {
  std::vector<int>         myvec(10);
  std::list<int>           mylist(10);
  std::priority_queue<int> pq;
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
  // queeu2.pop();
  return 0;
}