#include <bits/stdc++.h>
using namespace std;
vector<int> pointTo[105];
map<int, int> indeg;
queue<int> ans;   //
stack<int> iZero; //
map<int, int> mark;

void topoDfs()
{
  int u;
  while (!iZero.empty())
  {
    u = iZero.top();
    iZero.pop();
    if (mark[u] == 1)
      continue;
    mark[u] = 1;
    ans.push(u);
    for (auto v : pointTo[u])
    {
      indeg[v]--;
      if (indeg[v] == 0)
      {
        iZero.push(v);
      }
    }
  }
}

int main(void)
{
  int n, m, i, j;
  while (1)
  {
    cin >> n >> m;
    if (n == 0 && m == 0)
      break;
    for (int k = 1; k <= m; k++)
    {
      cin >> i >> j;
      pointTo[i].push_back(j);
      indeg[j]++;
    }

    for (int k = 1; k <= n; k++)
    {
      if (indeg[k] == 0)
      {
        iZero.push(k);
      }
    }
    // topological dfs

    topoDfs();
    while (!ans.empty())
    {
      cout << ans.front() << " ";
      ans.pop();
    }
    cout << "\n";
    for (int k = 1; k <= n; k++)
    {
      pointTo[k].clear();
      indeg[k] = 0;
      mark[k] = 0;
    }
  }

  return 0;
}
