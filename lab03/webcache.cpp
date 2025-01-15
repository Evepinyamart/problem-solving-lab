#include <iostream>
#include <map>
#include <queue>
using namespace std;
queue<int> cache;
map<int,int> status;

int main(void)
{
  int n,m,c,miss=0;
  cin >> n >> m;
  for (int i=0;i<m;i++){
    cin >> c;
    if (status[c] == 0){
      cache.push(c);
      status[c]=1;
      miss++;
      if (cache.size() > n){
        status[cache.front()] = 0;
        cache.pop();
      }
    } 
  }
    cout << miss << endl;
  return 0;
}