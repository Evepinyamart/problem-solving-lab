#include <bits/stdc++.h>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
int max_ans = 0;
vector<int> boatCap; //<cap,free?>
vector<int> booking;

int main(void)
{
  int n, m, p;

  cin >> n >> m;
  booking.reserve(m + 1);
  for (int i = 0; i < n; i++)
  {
    cin >> p;
    boatCap.push_back(p);
  }
  sort(boatCap.begin(), boatCap.begin() + n);
  for (int i = 0; i < m; i++)
  {
    cin >> booking[i];
  }

  for (int i = 0; i < m; i++)
  {
    if (booking[i] > boatCap.back())
    {
      break;
    }
    // lower_bound
    auto j = lower_bound(boatCap.begin(), boatCap.end(), booking[i]);
    max_ans++;
    boatCap.erase(j);
  }

  cout << max_ans << "\n";
  return 0;
}
