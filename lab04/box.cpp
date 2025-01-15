#include <bits/stdc++.h>
using namespace std;
char m[35][35];
int mark[35][35];
int path[35][35];
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};
int n, q;

void boxpath(int i, int j)
{
  int ni, nj;
  mark[i][j] = 1;
  if (i == n - 2)
  {
    cout << "yes";
    exit(0);
  }
  for (int k = 0; k < 4; k++)
  {
    ni = i + di[k];
    nj = j + dj[k];

    if (ni < 0 || ni >= n - 1 || nj < 0 || nj >= q - 1)
    {
      continue;
    }
    if (mark[ni][nj])
    {
      continue;
    }
    if (m[ni][nj] == '.' && m[ni + 1][nj] == '.' && m[ni][nj + 1] == '.' && m[ni + 1][nj + 1] == '.')
    {
      path[ni][nj] = path[ni + 1][nj] = path[ni][nj + 1] = path[ni + 1][ni + 1] = 1;
      boxpath(ni, nj);
    }
    mark[ni][nj] = 1;
  }
}

int main(int argc, char const *argv[])
{
  int starti, startj, endi, endj;
  cin >> n >> q;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < q; j++)
    {
      cin >> m[i][j];
    }
  }

  for (int i = 0; i < q; i++)
  {
    if (m[0][i] == '.' && m[0][i + 1] == '.' && m[1][i] == '.' && m[1][i + 1] == '.')
      boxpath(0, i);
  }
  /*
  cout << "output\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < q; j++)
    {
      if (path[i][j])
      {
        cout << 'x';
      }
      else
        cout << m[i][j];
    }
    cout << "\n";
  }
  */
  cout << "no";

  return 0;
}