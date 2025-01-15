#include <iostream>
#include <list>
using namespace std;

list<int> station[100001];

int main()
{
  int m;
  char cmd;
  int trainNum;
  int currStation, nextStation;
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> cmd;
    if (cmd == 'N')
    {
      cin >> trainNum >> currStation;
      station[currStation].push_back(trainNum);
    }
    else if (cmd == 'M')
    {
      cin >> currStation >> nextStation;
      station[nextStation].splice(station[nextStation].begin(), station[currStation]);
    }
  }

  for (int j = 0; j < 100001; j++)
  {
    for (list<int>::iterator i = station[j].begin(); i != station[j].end(); i++)
    {
      cout << *i << '\n';
    }
  }
  return 0;
}