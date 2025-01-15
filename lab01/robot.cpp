#include <bits/stdc++.h>
using namespace std;
char path[101];

int main(void)
{
  int x = 0, y = 0;
  string st;
  cin >> st;
  strcpy(path, st.c_str()); 

  for (int j = 0; j < st.length(); j++)
  {
    char order = path[j];
    if (order == 'N')
    {
      y++;
    }
    else if (order == 'S')
    {
      y--;
    }
    else if (order == 'E')
    {
      x++;
    }
    else if (order == 'W')
    {
      x--;
    }
    else if (order == 'Z')
    {
      x = 0;
      y = 0;
    }
  }
    cout << x << ' ';
    cout << y;
  return 0;
}