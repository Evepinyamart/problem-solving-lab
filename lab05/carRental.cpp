#include <bits/stdc++.h>
using namespace std;
vector<int> rental[105];
int package[1005];

int main(int argc, char const *argv[])
{
  int k, n;
  cin >> k >> n;
  for (int i = 0; i < k; i++)
  {
    int c, p, w;
    cin >> c >> p >> w;
    rental[i].push_back(c);
    rental[i].push_back(p);
    rental[i].push_back(w);
  }
  for (int j = 0; j < n; j++)
  {
    cin >> package[j];
  }

  int lowest_cost = INT_MAX;
  for (int i = 0; i < k; i++)
  {
    int n_car = 1;
    int package_weight = 0;
    bool not_pass = false;
    int rental_weight = rental[i][2];
    for (int j = 0; j < n; j++)
    {
      int pg = package[j];
      if (pg > rental_weight)
      {
        not_pass = true;
        continue;
      }
      if (package_weight + pg > rental_weight)
      {
        package_weight = pg;
        n_car++;
      }
      else
      {
        package_weight += pg;
      }
    }
    if (not_pass)
      continue;
    int cost = n_car * rental[i][1] + rental[i][0];
    lowest_cost = min(lowest_cost, cost);
  }
  cout << lowest_cost;

  return 0;
}
