#include <iostream>
using namespace std;

int main(void)
{
  unsigned long n, k, t, round = 1;
  cin >> n >> k >> t;
  
  while (k * round % n != 0)
  {
    if (k * round % n == t-1)
    {
      round++;
      break;
    }
      round++;
  }
  cout << round;
  return 0;
}