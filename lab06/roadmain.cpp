#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100010
#define INF 1e9

vector<int> adj[MAX_N];
vector<int> length[MAX_N];
bool scanned[MAX_N];
int dist[MAX_N];
set<pair<int, int>> dv;

/*
  MST
 **อันที่ถนนที่ไม่พัง ใช้cost=0เลย คือยังไงก็ต้องเลือก
*/
int mst(int s, int n)
{
  int totalVal = 0;
  // initial
  for (int u = 0; u < n; u++)
  {
    dist[u] = INF;
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
  int n, m, a, b, c, d;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> a >> b >> c >> d;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
    if (d == 1)
      c = 0;
    length[a].push_back(c);
    length[b].push_back(c);
  }

  cout << mst(0, n);
  // cout << dist[n - 1];
  return 0;
}
