#include <bits/stdc++.h>
using namespace std;
list<char> ans, toMove;
char inp[100100];

int main()
{
  int f = 0;
  while (scanf(" %s", inp) != EOF)
  {
    int length = strlen(inp);
    for (int i = 0; i < length; i++)
    {
      if (!f && inp[i] == '[')
        f = 1;
      else if (f && (inp[i] == ']' || inp[i] == '['))
      {
        ans.splice(ans.begin(), toMove);
        toMove.clear();
        if (inp[i] == ']')
          f = 0;
      }
      else if (f)
      {
        toMove.push_back(inp[i]);
      }
      else if (!f && inp[i] != ']')
      {
        ans.push_back(inp[i]);
      }
    }
    if (!toMove.empty())
      ans.splice(ans.begin(), toMove);
    for (auto x : ans)
    {
      if (isprint(x))
        cout << x;
    }
    cout << "\n";
    ans.clear();
  }

  return 0;
}