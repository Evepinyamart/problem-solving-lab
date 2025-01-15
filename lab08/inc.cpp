#include <bits/stdc++.h>
using namespace std;
int inp[1005];
int l[1005];
stack<int> ans;

int main(void)
{
  int n, maxx = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> inp[i];
  }

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (inp[i] > inp[j])
      {
        l[i] = max(l[i], l[j] + 1);
      }
    }
    maxx = max(maxx, l[i]);
  }

  for (int i = n - 1; i >= 0; i--)
  {
    if (l[i] == maxx)
    {
      ans.push(inp[i]);
      maxx--;
    }
  }

  cout << ans.size() << "\n";
  while (!ans.empty())
  {
    cout << ans.top() << " ";
    ans.pop();
  }
  return 0;
}
