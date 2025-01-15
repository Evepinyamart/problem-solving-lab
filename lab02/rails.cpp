#include <bits/stdc++.h>
using namespace std;
int seq[1010];
stack<int> st;
int main()
{
  int n, cou;
  while (1)
  {
    cin >> n;
    if (!n)
      break;
    while (1)
    {
      cin >> seq[0];
      if (!seq[0])
        break;
      for (int i = 1; i < n; i++)
      {
        cin >> seq[i];
      }
      cou = 1;
      for (int i = 0; i < n; i++)
      {
        if (st.empty())
        {
          st.push(cou++);
        }
        while (!st.empty() && st.top() != seq[i] && cou <= n)
        {
          st.push(cou++);
        }
        if (st.top() == seq[i])
          st.pop();
        else
          break;
      }
      if (st.empty())
        cout << "Yes"
             << "\n";
      else
        cout << "No"
             << "\n";
      while (!st.empty())
      {
        st.pop();
      }
    }
    cout << "\n";
  }
  return 0;
}