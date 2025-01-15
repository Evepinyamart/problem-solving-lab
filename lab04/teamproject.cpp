#include<bits/stdc++.h>
using namespace std;
int mark[100100];
pair<int,int> p[200100];
vector<int> g[100100];
queue<int> bfs;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0);
    int n,m,k,i;
    cin >> n >> m >> k;
    for(i=0;i<m;i++){
        cin >> p[i].first >> p[i].second;
        mark[p[i].first]++; mark[p[i].second]++;
    }
    for(i=0;i<m;i++){
        if(mark[p[i].first] >= k || mark[p[i].second] >= k) continue;
        g[p[i].first].push_back(p[i].second);
        g[p[i].second].push_back(p[i].first);
    }
    memset(mark,0,sizeof mark);
    for(i=1;i<=n;i++){
        if(mark[i]) continue;
        mark[i] = 1;
        bfs.push(i);
        while(!bfs.empty()){
            int u = bfs.front();
            bfs.pop();
            for(auto x:g[u]){
                if(mark[x] == 0){
                    mark[x] = 3-mark[u];
                    bfs.push(x);
                }
                else if(mark[x] == mark[u]){
                    cout << "no\n";
                    return 0;
                }
            }
        }
    }
    cout << "yes\n";
    return 0;
}