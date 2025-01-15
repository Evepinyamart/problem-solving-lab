#include <iostream>
#include <vector>
using namespace std;
set<int> price;

int main()
{
  int nBook, nRound,money,nBuy,a;
  cin >> nBook >> nRound;
  price.resize(nBook);
  cin >> price[0];
  for (int j = 0; j < nBook-1; j++)
  {
    cin >> a;
    price[j+1] = a + price[j];
  }
  for (int i = 0; i < nRound; i++)
  {
    money = nBuy = 0;
    
    cin >> money;
    nBuy = lower_bound(price.begin(), price.end(), money);
    cout << nBuy << "\n";
  }
return 0;
}

