#include <iostream>
using namespace std;
long long sec[100001];

int main(void)
{
  long long n, k, finalist,fastest = 3e9;
  cin >> n >> k;
  finalist = n;
  for (int j = 0; j < n; j++)
  {
    cin >> sec[j];
    if (sec[j] <= fastest)
    {
      fastest = sec[j];
    }
  }

  for (int j = 0; j < n; j++)
  {
    if (sec[j] != fastest)
    {
      if (fastest*n > sec[j] * (n-1)){
        continue;
      }
      for (int i = 1; i < k + 1; i++)
      {
        if ((fastest * i <= sec[j] * (i - 1)))
        {
          finalist--;
          break;
        }
      }
    }
  }
  cout << finalist;
  return 0;
}