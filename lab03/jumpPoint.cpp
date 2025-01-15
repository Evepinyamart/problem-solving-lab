#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  int n, r;
  pair<int, int> trees[1010];
  vector<int> reachable[1010];
  queue<int> q;
  int dist[1010];
  cin >> n >> r;
  trees[0] = {0, 0};
  for (int i = 1; i <= n; i++)
  {
    cin >> trees[i].first >> trees[i].second;
  }
  trees[n + 1] = {100, 100};

  for (int i = 0; i < n + 2; i++)
  {
    for (int j = i + 1; j < n + 2; j++)
    {
      if (r * r >= (trees[i].first - trees[j].first) * (trees[i].first - trees[j].first) + (trees[i].second - trees[j].second) * (trees[i].second - trees[j].second))
      {
        reachable[i].push_back(j);
        reachable[j].push_back(i);
      }
    }
  }

  dist[0] = 0;
  dist[n + 1] = -1;
  q.push(0);
  while (!q.empty())
  {
    int currentNode = q.front();
    q.pop();
    for (auto next : reachable[currentNode])
    {
      if (dist[next] && dist[next] != -1)
        continue; // avoid loop (running into the tree that already passed)
      dist[next] = dist[currentNode] + 1;
      q.push(next);
    }
  }
  cout << dist[n + 1];
  return 0;
}

/*
5 50
50 0
100 0
100 50
50 30
70 50
*/