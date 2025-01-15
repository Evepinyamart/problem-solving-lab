#include <bits/stdc++.h>
using namespace std;
#define MAX_N 200100

vector<int> adj[MAX_N];
vector<int> length[MAX_N];
bool scanned[MAX_N];
int dist[MAX_N];
set<pair<int, int>> dv;

int mst(int s, int n)
{
  int totalVal = 0;
  // initial
  for (int u = 0; u < n; u++)
  {
    dist[u] = INT_MAX;
    scanned[u] = false;
  }

  dist[s] = 0;
  dv.insert({0, s});
  for (int i = 0; i < n; i++)
  {
    // extract min
    int bestu = -1;
    while (!dv.empty())
    {
      auto it = dv.begin();
      if (!scanned[it->second])
      {
        bestu = it->second;
        break;
      }
      dv.erase(it);
    }
    if (bestu == -1)
      break;

    // decrese key
    int deg = adj[bestu].size();
    for (int j = 0; j < deg; j++)
    {
      int v = adj[bestu][j];
      int len = length[bestu][j];
      if (len < dist[v])
      {
        dist[v] = len;
      }
      dv.insert(make_pair(dist[v], v));
    }
    totalVal += dist[bestu];
    scanned[bestu] = true;
  }
  return totalVal;
}

int main(void)
{
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    length[u].push_back(w);
    length[v].push_back(w);
  }
  int ans = mst(0, n);
  cout << ans;
  return 0;
}