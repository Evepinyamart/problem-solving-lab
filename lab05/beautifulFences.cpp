#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  int n, l;
  vector<pair<int, int>> houseLo;
  cin >> n >> l;
  for (int i = 0; i < n; i++)
  {
    int inp1, inp2;
    cin >> inp1 >> inp2;
    houseLo.push_back({inp1, inp2});
  }
  int ans = 1;
  int currentF = houseLo[0].first + l;
  int passedHouse = 0;
  while (currentF < houseLo.back().second)
  {
    if (houseLo[passedHouse].second <= currentF)
    {
      passedHouse++;
      continue;
    }
    currentF = houseLo[passedHouse].first + l;
    ans++;
  }
  cout << ans;
  return 0;
}
