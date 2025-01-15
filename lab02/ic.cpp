#include <iostream>
#include <list>
using namespace std;
list<int> l;

int main()
{
  int m, x;
  string cmd;
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> cmd;
    if (cmd == "ri")
    {
      cin >> x;
      l.push_back(x);
    }
    else if (cmd == "li")
    {
      cin >> x;
      l.push_front(x);
    }
    else if (cmd == "rr")
    {
      l.push_front(l.back());
      l.pop_back();
    }
    else if (cmd == "lr")
    {
      l.push_back(l.front());
      l.pop_front();
    }
  }
  for (auto i = l.begin(); i!=l.end(); i++){
    cout << *i << '\n';
  }
  return 0;
}