#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  while (1)
  {
    int n, d, r, sumDiff = 0;
    vector<int> mRoute;
    vector<int> nRoute;
    cin >> n >> d >> r;
    if (!n)
    {
      exit(0);
    }
    for (int i = 0; i < n; i++)
    {
      int mr;
      cin >> mr;
      mRoute.push_back(mr);
    }
    sort(mRoute.begin(), mRoute.begin() + n, greater<int>());
    for (int i = 0; i < n; i++)
    {
      int nr;
      cin >> nr;
      nRoute.push_back(nr);
    }
    sort(nRoute.begin(), nRoute.begin() + n);
    for (int i = 0; i < n; i++)
    {
      int diff = nRoute.back() + mRoute.back() - d;
      if (diff > 0)
        sumDiff += diff;
      nRoute.pop_back();
      mRoute.pop_back();
    }
    cout << sumDiff * r << "\n";
  }

  return 1;
}