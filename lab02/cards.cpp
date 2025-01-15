#include <iostream>
#include <list>
using namespace std;
list<int> remaining;

int main(){
  int x=1;
  while (x!=0){
    cin >> x;
      if (x == 0){
          break;
      }
      
      for (int i=0; i<x; i++){
          remaining.push_back(i+1);
      }
      cout << "\nDiscarded cards:";
      while (remaining.size() != 1){
          cout << " " << remaining.front();
          if (remaining.size()!=2) cout<<",";
          remaining.pop_front();
          remaining.push_back(remaining.front());
          remaining.pop_front();
      }
      cout << "\nRemaining card: " << remaining.front();
      remaining.clear();
  }
    
  return 0;
}
