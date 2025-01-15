#include <bits/stdc++.h>
using namespace std;
int lp[100005];
int maxSum[100005];

int main(void)
{
  int n, jump;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> lp[i];
  }
  maxSum[0] = 0;
  maxSum[1] = 0;
  maxSum[2] = lp[2];
  for (int i = 3; i < n; i++)
  {
    int an = lp[i];
    maxSum[i] = max(maxSum[i - 3] + an, maxSum[i - 1]);
  }
  cout << maxSum[n - 1];
  return 0;
}
