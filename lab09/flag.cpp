#include <bits/stdc++.h>
using namespace std;
vector<int> h;

int main(int argc, char const *argv[])
{
  int n, x, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    h.push_back(x);
  }
  for (int i = 0; i < n - 1; i++)
  {
    for (int k = i + 1; k < n; k++)
    {
      for (int b = i + 1; b < k; b++)
      {
        if (h[b] < h[i] && h[b] < h[k])
        {
          ans++;
        }
      }
    }
  }
  if (!ans)
    cout << -1;
  else
    cout << ans;

  return 0;
}
