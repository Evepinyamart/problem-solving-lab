#include <iostream>
#include <map>
#include <array>
using namespace std;
map<int,int> likeNum;
array<int> toMost;           
int maxIndex = 0;


int main()
{
  int n,order,s,p;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> order >> s;
        if (order==0){
            likeNum[s]--;
        } else if (order==1){
            likeNum[s]++;
        }
        
        cout << maxIndex  << "\n";
    }
  return 0;
}


//สลับทุกรอบที่มีการอัพเดตข้อมูล เก็บ