#include <iostream>
#include <map>
#include <array>
using namespace std;
map<int,int> result;
int p[101];

int main(void)
{
  int n;
  cin >> n;
  for (int i=1; i<n+1; i++){
    cin >> p[i];
    p[i]+=p[i-1];
  }
  
  for (int j=1; j<n; j++){
    for (int k=j; k<n+1; k++){
      result[p[k]-p[j-1]] = 1;
    }
  }

  cout << size(result);

  return 0;
}

