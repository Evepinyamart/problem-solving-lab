#include <bits/stdc++.h>
using namespace std;
int path[51], ans[51];

int main(void) {
  int n, t;
  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    cin >> path[i];
  }

  if (t == 1) {
    ans[0] = (n < path[0]) ? 1:0 ;
    for (int i = 0; i < n - 1; i++) {
      ans[i+1] = (path[i] < path[i + 1]) ? 1:0;
    }
  }

  if (t==2){
      int y = path[0];
    for (int i=0;i<n-1;i++) {
        cout << y << " ";
        int d = (path[i+1] > 2*y) ? 2*y:y;
        ans[i+1] = (d == y) ? 1:0;
        y=path[i+1]-d;
  }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}