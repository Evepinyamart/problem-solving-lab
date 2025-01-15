#include <bits/stdc++.h>
using namespace std;
// vector<tuple<long long,long long, long long>> maxp;
long long maxp[500005][4]; // กับเวลารอ
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
  maxp[0][2] = 0;
  maxp[0][3] = menu[0].l;
  /*
  maxp[1][1] = menu[1].m;
  maxp[1][2] = menu[1].m;
  maxp[2][2] = menu[2].m;
*/
  // int s, m, l, j;
  long long pick = 0;
  for (int i = 1; i < n; i++)
  {
    maxp[i][0] = max(maxp[i - 1][0], maxp[i - 1][1]) + menu[i].s;
    maxp[i][1] = max(maxp[i - 1][2], maxp[i - 1][1] + menu[i].m);
    maxp[i][2] = maxp[i - 1][3];
    maxp[i][3] = maxp[i - 1][1] + menu[i].l;
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (maxp[n - 1][i] > ans)
      ans = maxp[n - 1][i];
  }
  cout << ans;
  // cout << get<0>(menu[0]);
  return 0;
}
