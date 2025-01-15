#include <bits/stdc++.h>
using namespace std;
vector<tuple<int, int, int>> menu;
// vector<tuple<long long,long long, long long>> maxp;
// long long maxp[500001][3];
long long maxp[500005][3]

int main(int argc, char const *argv[])
{
  int n, x, y, z;
  cin >> n;
  // maxp.assign(n+1);
  for (int i = 0; i < n; i++)
  {
    cin >> x >> y >> z;
    menu.push_back(make_tuple(x, y, z));
  }
  /* for (int i=0;i<3;i++){
    maxp[0][i] = get<i>(menu[0])
   }
   maxp[1][1] = get<1>(menu[1]);
   maxp[1][2] = get<1>(menu[1]);
   maxp[2][2] = get<1>(menu[2]);  */

  int s, m, l, j;
  for (int i = 3; i < n + 3; i++)
  {
    j = i - 3;
    s = get<0>(menu[j]);
    m = get<1>(menu[j]);
    l = get<2>(menu[j]);
    maxp[i] = max(maxp[i-1][0],)
    // cout << maxp[i] << "\n";
  }

  cout << maxp[n + 2];
  // cout << get<0>(menu[0]);
  return 0;
}