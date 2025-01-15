#include <bits/stdc++.h>
using namespace std;
// vector<tuple<long long,long long, long long>> maxp;
long long maxp[500005][3]; //กับเวลารอ
// long long maxp[500005];
struct p
{
  int s, m, l;
};
vector<p> menu;

int main(int argc, char const *argv[])
{
  int n, x, y, z;
  cin >> n;
  // maxp.assign(n+1);
  for (int i = 0; i < n; i++)
  {
    p inp;
    cin >> inp.s >> inp.m >> inp.l;
    menu.push_back(inp);
  }
  maxp[0][0] = menu[0].s;
  maxp[0][1] = menu[0].m;
  maxp[0][2] = menu[0].l;
  maxp[1][1] = menu[1].m;
  maxp[1][2] = menu[1].m;
  maxp[2][2] = menu[2].m;

  // int s, m, l, j;
  long long pick = 0;
  for (int i = 3; i < n + 3; i++)
  {
    int j = i - 3;
    // s = get<0>(menu[j]);
    // m = get<1>(menu[j]);
    // l = get<2>(menu[j]);
    for (int k = 0; k < 3; k++)
    {
      if (k == 0)
        pick = menu[j].s;
      if (k == 1)
        pick = menu[j].m;
      if (k == 2)
        pick = menu[j].l;

      maxp[i][k] = max(maxp[i - 1][0] + pick, maxp[i - 2][1] + pick);
      maxp[i][k] = max(maxp[i][k], maxp[i - 3][2] + pick);
      maxp[i][k] = max(maxp[i][k], maxp[i - 1][k]);
    }
    // cout << maxp[i] << "\n";
  }

  cout << maxp[n + 1][0] << " " << maxp[n + 1][1] << " " << maxp[n + 1][2];
  // cout << get<0>(menu[0]);
  return 0;
}
