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