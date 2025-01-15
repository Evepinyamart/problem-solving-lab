#include <iostream>
#include <map>
using namespace std;
int start[300002];
int after[300002];

int main(void)
{
  int n,front,back,tmp,s;
  cin >> n;
      for (int i=1; i<n; i++){
        cin >> back >> front;
        start[back] = 1;
        tmp = after[front];
        after[front] = back; //index start at 1
        while (after[back] != 0){
          back = after[back];
        }
        after[back] = tmp;
      } 


  //find the 1st node
  for (s=1; s < n; s++)
  {
    if (start[s] == 0){
      break;
    }
  }

     cout << s;
      for (int i=1; i<n; i++){
        s=after[s];
        cout << " " << s;
      }
    
  return 0;
}

