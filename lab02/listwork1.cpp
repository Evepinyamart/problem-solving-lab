#include <iostream>
#include <list>
using namespace std;

list<int> l;

int main(){
  int m,x,k;
  string cmd;

  cin >> m;
  for (int i=0; i<m; i++){
    cin >> cmd;
    if (cmd[0] == 'I'){
      cin >> x;
      l.push_front(x);
    } else {
      cin >> k;
      list<int>::iterator ii = l.begin();
      for (int j=0; j<k; j++){
        if (ii==l.end()){
          break;
        } if (j==k-1){
          l.erase(ii);
        }
        ii++;
      }
    }
  }

  for (list<int>::iterator i = l.begin(); i!= l.end(); i++){
    cout << *i << '\n';
  }
  return 0;
}
