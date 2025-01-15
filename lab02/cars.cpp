#include <iostream>
#include <stack>
using namespace std;
stack<int> carEff;

int main(void)
{
  int n, p, v, ans = 0;
  cin >> n;
  for (int i=0;i<n;i++)
  {
    cin >> p >> v;
    while (1)
    {
      if (carEff.size()>0 && carEff.top()<v){
        carEff.pop();
        ans++;
      }
      else {
        carEff.push(v);
        break;
      }
    } 
  }
    cout << ans;
  return 0;
}
