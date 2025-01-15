#include <bits/stdc++.h>
using namespace std;
string strname;
char name[101];
char text[100001];
int nit = 0;
int ans = 0;

int main(int argc, char const *argv[])
{
  // name input
  cin >> name;
  cin >> text;
  for (int i = 0; i < strlen(text); i++)
  {
    if (nit == strlen(name))
    {
      nit = 0;
      ans++;
    }
    if (text[i] == name[nit])
      nit++;
  }
  cout << ans;
  return 0;
}
