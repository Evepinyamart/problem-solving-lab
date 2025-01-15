#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  vector<int> fibo(n + 5);
  // ต้องมีพื้นที่ให้เก็บ n+1ที่ เพราะเริ่มที่0!!

  fibo[0] = 0;
  fibo[1] = 1;

  for (int i = 2; i <= n; i++)
  {
    fibo[i] = fibo[i - 2] + fibo[i - 1];
    fibo[i] %= 199933;
  }

  cout << fibo[n];
  return 0;
}