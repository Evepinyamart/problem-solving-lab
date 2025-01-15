#include <iostream>
#include <map>
using namespace std;
map<int, int> team;

int main()
{
  int r, n, m, a, b, ans;
  cin >> r;
  for (int i = 0; i < r; i++)
  {
    ans = 1;
    team.clear();
    cin >> n >> m;
    for (int j = 0; j < m; j++)
    {
      cin >> a >> b;
      // a and b have mention before
      if (team[a] && team[b])
      {
        if ((team[a] % 2) - (team[b] % 2) == 0)
        {
          ans = 0;
          break;
        }
      }
      else
      {
        if (!team[a] && !team[b])
        {
          team[a] = 1;
        }
        if (team[a])
        {
          team[b] = team[a] + 1;
        }
        else if (team[b])
        {
          team[a] = team[b] + 1;
        }
      }
    }
    if (ans)
    {
      cout << "yes" << endl;
    }
    else
    {
      cout << "no" << endl;
    }
  }
  return 0;
}