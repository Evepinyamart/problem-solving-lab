#include <iostream>
#include <map>
using namespace std;
map<int,int> stock;

int main(void)
{
  int n, order, number, pIn, pOut;
  cin >> n;
  for (int i=0; i<n; i++){
    cin >> order >> number;
    if (order == 1){
      cin >> pIn;
      stock[number] += pIn;
    } else if (order == 2){
      cout << stock[number] << "\n";
    } else if (order == 3){
      cin >> pOut;
        if (pOut > stock[number]){
          pOut = stock[number];
        }
        cout << pOut << "\n";
        stock[number]-=pOut;
    }
  }
  return 0;
}