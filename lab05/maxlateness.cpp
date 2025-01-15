#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int>> deadline; //<deadline,time>

int main()
{
  int n, latecost, maxcost = 0, ct = 0;
  pair<int, int> t;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> t.first >> t.second;
    t.first = -1 * (t.first + 10);
    deadline.push(t);
  }

  for (int i = 0; i < n; i++)
  {
    latecost = 0;
    ct += deadline.top().second;
    if (ct > (deadline.top().first * -1))
    {
      latecost = (ct + deadline.top().first) * 1000;
      if (latecost > maxcost)
      {
        maxcost = latecost;
      }
    }
    deadline.pop();
  }
  cout << maxcost;
  return 0;
}