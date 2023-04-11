#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);
#define endl '\n'
using namespace std;

int v, e, start, target;
vector<int> dist;
struct ed{
    int e, d;
};

vector<vector<ed>> edges;
void sp(){
    priority_queue<int, vector<int>, greater<int>> q;
    dist[start] = 0;
    q.push(start);
    while(!q.empty()){
        int v = q.top(); q.pop();
        for(auto i:edges[v]){
            int temp = dist[v] + i.d;
            if(dist[i.e] > temp){
                q.push(i.e);
                dist[i.e] = temp;
            }
        }
    }
}

int main(){
    cin >> v >> e >> start >> target;
    dist.assign(v+1, INT_MAX);
    edges.assign(v+1, {});
    int x,y,z;
    while(e--){
        cin >> x >> y >> z;
        edges[x].push_back({y,z});
        edges[y].push_back({x,z});
    }

    sp();
    cout << dist[target];
    return 0;
}