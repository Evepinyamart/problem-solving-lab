#include <bits/stdc++.h>
using namespace std;
int peng[35];

int main(void)
{
  int n, ans = 0;
  cin >> n;
  for (int i = 2; i < n + 3; i++)
  {
    cin >> peng[i];
  }

  for (int i = n+2; i > 2; i--)
  {
    for (int j = i-1; j >= 2; j--)
    {
      if (peng[i] > peng[j])
      {
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}