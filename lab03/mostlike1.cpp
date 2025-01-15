#include <iostream>
#include <map>
using namespace std;
map<int,int> likeNum;
int maxIndex=0;

int main()
{
  int n,s;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> s;
        likeNum[s]++;
        if (likeNum[s]>=likeNum[maxIndex]) maxIndex=s;
        cout << maxIndex  << "\n";
    }
  return 0;
}