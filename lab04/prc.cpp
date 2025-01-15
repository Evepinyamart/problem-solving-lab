#include<bits/stdc++.h>
using namespace std;
int team[1005];
vector<int> adj[1005];
pair<int, int> edge[3005];
queue<int> bfs;
int n, m;

int bipartite(int i) {
  int v;
  for (int j = 1; j <= n; j++) {
    if (team[j] != 0)
      continue;
    team[j] = 1;
    bfs.push(j);

    while (!bfs.empty()) {
      v = bfs.front();
      bfs.pop();
      for (auto u : adj[v]) {
        if (v == edge[i].first && u == edge[i].second) continue;
        if (v == edge[i].second && u == edge[i].first) continue;
        if (team[v] == team[u]) {
          return 0;
        }
        if (team[u])
          continue;
        // first time visit node u
        team[u] = 3 - team[v];
        bfs.push(u);
      }
    }
  }
  return 1;
}

int main(void) {
  int a, b;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    edge[i] = {a,b};
  }
  for (int i = 0; i < m; i++) {
    if (bipartite(i)) {
      cout << edge[i].first << " " << edge[i].second;
      break;
    }
    while (!bfs.empty()) {
          bfs.pop();
    }
    memset(team,0,sizeof team);
  }
  return 0;
}