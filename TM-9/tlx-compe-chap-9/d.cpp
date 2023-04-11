#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);
#define endl '\n'
using namespace std;

vector<int> edges[502];

int bfs(int start, int roma){
    queue<int> q;
    int dist[502];
    memset(dist, -1, sizeof(dist));
    q.push(start);
    dist[start] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0; i<edges[now].size(); i++){
            int x = edges[now][i];
            if(dist[x]==-1){
                q.push(x);
                dist[x] = dist[now] + 1;
            }
        }
    }
    return dist[roma];
}

int main(){
    fastio
    int n, l, t, awal, roma;
    cin >> n >> l >> t >> awal >> roma;
    int a, b, temp;
    for(int i=0; i<l; i++){
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int ans = 2e9;
    for(int i=0; i<t; i++){
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
        int temp = bfs(awal, roma);
        if(temp>=0)
            ans = min(ans, temp);
        edges[a].pop_back();
        edges[b].pop_back();
    }
    cout << ans;
    return 0;
}