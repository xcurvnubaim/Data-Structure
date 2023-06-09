#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);
#define endl '\n'
#define pii pair<int,int>
using namespace std;

int v, e, start, target;
vector<int> dist;
struct ed{
    int e, d;
};

vector<vector<ed>> edges;
void sp(){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({0,start});
    while(!pq.empty()){
        pii v = pq.top(); pq.pop();
        for(auto i:edges[v.second]){
            int temp = dist[v.second] + i.d;
            if(dist[i.e] > temp){
                dist[i.e] = temp;
                pq.push({dist[i.e],i.e});
            }
        }
    }
}
            
int main(){
    cin >> v >> e;
    dist.assign(v+1, INT_MAX);
    edges.assign(v+1, {});
    int x,y,z;
    while(e--){
        cin >> x >> y;
        edges[x].push_back({y,1});
        edges[y].push_back({x,1});
    }
    cin >> start >> target;
    sp();
    cout << dist[target];
    return 0;
}