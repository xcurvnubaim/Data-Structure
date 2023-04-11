#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);
#define endl '\n'
using namespace std;

int v, e;
vector<int> dist;
struct ed{
    int e, d;
};

vector<vector<ed>> edges;
int sp(int start, int target){
    priority_queue<int, vector<int>, greater<int>> q;
    dist.clear();
    dist.assign(v+1, INT_MAX);
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