#include <iostream>
#include <vector>
using namespace std;

vector<int> connect[100001];
int group[100001], n;

void markConnected(int node) {
    group[node] = 1;

    for (int neighbor : connect[node]) {
        if (group[neighbor] == 0) {
            markConnected(neighbor);
        }
    }
}

int main() {
    int m, a, b, ans = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        connect[a - 1].push_back(b - 1);
        connect[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < n; i++) {
        if (group[i] == 0) {
            ans++;
            markConnected(i);
        }
    }

    cout << ans;
    return 0;
}