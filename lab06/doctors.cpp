#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100010
#define INF 1e9

vector<int> adj[MAX_N];
vector<int> length[MAX_N];
bool scanned[MAX_N];
int dist[MAX_N];
set<pair<int, int>> dv;
vector<int> n_people;

void dijkstra(int s, int n)
{
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
      if (dist[bestu] + len < dist[v])
      {
        dist[v] = dist[bestu] + len;
      }
      dv.insert(make_pair(dist[v], v));
    }

    scanned[bestu] = true;
  }
}

int main(void)
{
  int totalMinCost = 0;
  int n, m, l;
  cin >> n >> m >> l;
  n_people.reserve(n);
  for (int i = 0; i < n; i++)
  {
    cin >> n_people[i];
  }
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
  dijkstra(0, n);
  for (int i = 1; i < n; i++)
  {
    totalMinCost += min(l, n_people[i]) * dist[i];
  }
  cout << totalMinCost;
  return 0;
}