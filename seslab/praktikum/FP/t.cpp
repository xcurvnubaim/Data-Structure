#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);
#define endl '\n'
#define pii pair<int,int>
using namespace std;

int v, e, start, target;
vector<int> dist;
// struct ed{
//     int e, d;
// };

vector<vector<int>> edges;
vector<int> prev_node;
// void sp(){
//     priority_queue<pii, vector<pii>, greater<pii>> pq;
//     dist[start] = 0;
//     pq.push(make_pair(0,start));
//     while(!pq.empty()){
//         pii v = pq.top(); pq.pop();
//         for(auto i:edges[v.second]){
//             int temp = dist[v.second] + i.d;
//             if(dist[i.e] > temp){
//                 dist[i.e] = temp;
//                 pq.push(make_pair(dist[i.e],i.e));
//                 prev_node[i.e] = v.second;
//             }
//         }
//     }
// }
// void dijkstra(){
//     vector<bool> visited(v+1, false);
//     priority_queue<pii, vector<pii>, greater<pii>> pq;
    
//     pq.push(make_pair(0, start));
//     dist[start] = 0;

//     while(!pq.empty()){
//         auto temp = pq.top();
//         pq.pop();

//         visited[temp.second] = true;

//         for(auto vertex:edges[temp.second]){
//             int nextVertex = vertex.e;
//             int weight = vertex.d;

//             if(!visited[nextVertex]){
//                 if(temp.first + weight < dist[nextVertex]) {
//                     dist[nextVertex] = temp.first + weight;
//                     prev_node[nextVertex] = temp.second;
//                     pq.push(make_pair(dist[nextVertex], nextVertex));
//                 }
//             }
//         }
//     }
// }

void bfs(){
    vector<bool> visited(v+1,false);
    queue<int> q;
    q.push(1);
    dist[1] = 1;
    visited[1] = true;
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(auto i:edges[x]){
            if(!visited[i]){
                dist[i] = dist[x] + 1;
                prev_node[i] = x;
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){
    cin >> v >> e;
    dist.assign(v+1, INT_MAX);
    prev_node.assign(v+1, -1);
    edges.assign(v+1, {});
    int x,y,z;
    while(e--){
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    start = 1; target = v;
    // sp();
    bfs();
    if(dist[target]!=INT_MAX){
        cout << dist[target] << endl;
        // int path = v;
        stack<int> path;
        path.push(v);
        while(path.top()!=1){
            path.push(prev_node[path.top()]);
        }
        while(!path.empty()){
            cout << path.top() << " ";
            path.pop();
        }
    } else {
        cout << "RIP LAPET 2023\n";
    }
    return 0;
}