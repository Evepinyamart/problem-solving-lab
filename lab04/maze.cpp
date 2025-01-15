#include <bits/stdc++.h>
using namespace std;
char m[25][25];
int mark[25][25];
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};
int ans;

void bfsFound(int i, int j, int x, int y, int n, int key)
{
  int ni, nj;
  mark[i][j] = 1;
  for (int k = 0; k < 4; k++)
  {
    ni = i + di[k];
    nj = j + dj[k];

    if (mark[ni][nj])
    {
      continue;
    }
    if (ni < 1 || ni > n || nj < 1 || nj > n)
    {
      continue;
    }
    if (m[ni][nj] == '.')
    {
      bfsFound(ni, nj, x, y, n, key);
    }
    if (m[ni][nj] == 'O' && key)
    {
      bfsFound(ni, nj, x, y, n, 0);
    }
  }
}

int main(int argc, char const *argv[])
{
  int n, q, starti, startj, endi, endj;
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> m[i][j];
    }
  }

  for (int i = 1; i <= q; i++)
  {
    ans = 0;
    cin >> starti >> startj >> endi >> endj;
    bfsFound(starti, startj, endi, endj, n, 1);
    if (mark[endi][endj])
    {
      cout << "yes" << endl;
    }
    else
    {
      cout << "no" << endl;
    }
    memset(mark, 0, sizeof mark);
  }

  return 0;
}
