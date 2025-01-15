#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    priority_queue<tuple<int, int, int>> Sortlike; // #like,update,p
    map<int, int> likeNum;
    int n, p, order;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> order >> p;
        if (order == 0)
        {
            likeNum[p] -= 1;
        }
        if (order == 1)
        {
            likeNum[p] += 1;
        }

        Sortlike.push({likeNum[p], i, p});

        while ((Sortlike.size()) && (get<0>(Sortlike.top()) != likeNum[get<2>(Sortlike.top())]))
        {
            Sortlike.pop();
        }
        cout << get<2>(Sortlike.top()) << "\n";
    }
    likeNum.clear();
    return 0;
}
