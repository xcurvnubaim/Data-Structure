#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);
#define endl '\n'
#define pii pair<int,int>
using namespace std;

int v, e;
vector<int> dist;
struct ed{
    int e, d;
};

vector<vector<ed>> edges;
int sp(int start, int target){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist.clear();
    dist.assign(v+1, INT_MAX);
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
    return dist[target];
}

int main(){
    fastio
    int q;
    cin >> v >> e >> q;
    edges.assign(v+1, {});
    int x,y,z;
    while(e--){
        cin >> x >> y >> z;
        edges[x].push_back({y,z});
        edges[y].push_back({x,z});
    }
    int start, target;
    start = 1;
    cin >> target;
    q--;
    long long res = 0;
    while(q--){
        start = target;
        cin >> target;
        res += sp(start, target);
        // for(auto i:dist)
        //     cout << i << " ";
        // cout << endl;
    }
    cout << res;
    return 0;
}