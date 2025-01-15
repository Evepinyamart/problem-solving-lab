#include <bits/stdc++.h>
using namespace std;
int team[100010];

int findroot(int i)
{
  if (i == team[i])
    return i;
  return findroot(team[i]);
}

int main(void)
{
  int n, q, m1, m2;
  char ins;
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
  {
    team[i] = i;
  }
  for (int i = 1; i <= q; i++)
  {
    cin >> ins >> m1 >> m2;
    if (ins == 'c')
    {
      team[findroot(m1)] = findroot(m2); // เอาm1มาชี้ไปหาm2 (m2กลายเป็นroot)
    }
    else if (ins == 'q')
    {
      if (findroot(m1) == findroot(m2))
      {
        cout << "yes\n";
      }
      else
      {
        cout << "no\n";
      }
    }
  }
  return 0;
}