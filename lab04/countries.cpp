#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
int myMap[35][35];
set<int> neightbor[1000];
// set<pair<int, int>> country_area[35];
bool visited[1000];
int dist[1000];
set<pair<int, int>> dv;

void dijkstra(int s, int d, int n)
{
  // initial
  for (int u = 0; u <= n; u++)
  {
    dist[u] = INF;
  }

  dist[s] = 0;
  dv.insert({0, s});
  while (!dv.empty())
  {
    auto it = dv.begin();
    int bestu = it->second;
    dv.erase(it);

    if (visited[bestu])
      continue;
    visited[bestu] = true;

    // int deg = neightbor[bestu].size();
    for (auto v : neightbor[bestu])
    {
      if (dist[bestu] + 1 < dist[v])
      {
        dv.erase({dist[v], v}); // Remove the existing pair from dv
        dist[v] = dist[bestu] + 1;
        dv.insert({dist[v], v}); // Insert the updated pair into dv
      }
    }
  }
}

int main()
{
  int r, c, start_x, start_y, des_x, des_y, n_country = 1;
  cin >> r >> c >> start_x >> start_y >> des_x >> des_y;
  start_x--;
  start_y--;
  des_x--;
  des_y--;

  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> myMap[i][j];
    }
  }

  int country1, country2;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c - 1; j++)
    {
      country1 = myMap[i][j];
      country2 = myMap[i][j + 1];
      if (country1 != country2)
      {
        neightbor[country1].insert(country2);
        neightbor[country2].insert(country1);
        n_country++;
      }
      // country_area[country1].insert({i, j});
    }
    // country_area[myMap[i][c - 1]].insert({i, c - 1});
  }

  int togo = myMap[des_x][des_y];
  dijkstra(myMap[start_x][start_y], togo, n_country);

  cout << dist[togo] << endl;

  return 0;
}
