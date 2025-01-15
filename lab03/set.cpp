#include <iostream>
#include <set>
#include <vector>
using namespace std;
set<int> x;
vector<int> y;

int main()
{
  int n, m, a;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    x.insert(x.lower_bound(a), a); // sorted from min to max
  }

    y.resize(m);
  for (int i = 0; i < m; i++)
  {
    cin >> y[i];
    auto it = x.lower_bound(y[i]);
    auto less = x.begin();
    if (it != x.begin()) less=prev(it);
    if (abs(*it - y[i]) >= abs(y[i] - *less))
    {
        cout << *less << endl;
    }
      else {
          cout << *it << endl;
      }
  }
  return 0;
}