#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("hippo.in", "r", stdin);
  freopen("hippo.out", "w", stdout);

  int T;
  cin >> T;

  for (int t = 1; t <= T; ++t)
  {
    int n, h, ta, td, ans = 0;
    cin >> n >> h >> ta >> td;

    vector<int> height(n);
    int visit[100100];
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < n; ++i)
    {
      cin >> height[i];
    }

    sort(height.begin(), height.begin() + n);
    int k = n - 1;
    for (int i = 0; i < n; i++)
    {
      if (visit[i] == 1)
        continue;
      while (k > i && (height[i] + height[k] >= h) || visit[k] == 1)
      {
        k--;
      }
      if (k > i && height[i] + height[k] < h && !visit[k] && ta * 2 > td)
      {
        ans += td;
        visit[i] = visit[k] = 1;
      }
      else
      {
        ans += ta;
        visit[i] = 1;
      }
    }

    cout << "Case " << t << ": " << ans << endl;
  }

  fclose(stdin);
  fclose(stdout);
  return 0;
}
