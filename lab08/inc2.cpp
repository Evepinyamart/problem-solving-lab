#include <bits/stdc++.h>
using namespace std;
int inp[100005];

int LIS(int n)
{
  vector<int> ans;
  ans.push_back(inp[1]); // l[0]=0
  for (int i = 2; i <= n; i++)
  {
    if (inp[i] > ans.back())
    {
      // ต่อ sequence นี้ได้เลย
      ans.push_back(inp[i]);
    }
    else
    {
      // continue the sequence of this number by finding the latest element that not less than this number
      int latestSeq = lower_bound(ans.begin(), ans.end(), inp[i]) - ans.begin();
      ans[latestSeq] = inp[i];
    }
  }
  return ans.size();
}

int main(void)
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> inp[i];
  }
  cout << LIS(n);
  return 0;
}