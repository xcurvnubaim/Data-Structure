#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);
#define endl '\n'
using namespace std;

int v,e;
struct ee{
    int u,v,d;
};

vector<ee> edges;

void BellmanFord()
{
    long long dis[v];
    for (int i = 0; i < v; i++)
        dis[i] = LLONG_MAX;
 
    // initialize distance of source as 0
    dis[0] = 0;
 
    // Relax all edges |V| - 1 times. A simple
    // shortest path from src to any other
    // vertex can have at-most |V| - 1 edges
    for (int i = 0; i < v - 1; i++) {
        for (int j = 0; j < edges.size(); j++) {
            if (dis[edges[j].u] != LLONG_MAX && 
            dis[edges[j].u] + edges[j].d < dis[edges[j].v])
                dis[edges[j].v] =
                  dis[edges[j].u] + edges[j].d;
        }
    }
 
    // check for negative-weight cycles.
    // The above step guarantees shortest
    // distances if graph doesn't contain
    // negative weight cycle.  If we get a
    // shorter path, then there is a cycle.
    for (int i = 0; i < edges.size(); i++) {
        int x = edges[i].u;
        int y = edges[i].v;
        int weight = edges[i].d;
        if (dis[x] != LLONG_MAX &&
            dis[x] + weight < dis[y]){
                cout << "Pak Dengklek tidak mau pulang\n";
                return;
            }
    }
    if(dis[v-1]!=LLONG_MAX)
        cout << dis[v-1] << endl;
    else
        cout << "Tidak ada jalan" << endl;
}
 
// Driver program to test above functions
int main()
{
    fastio
    int t;
    cin >> t;
    while(t--){
        edges.clear();
        cin >> v >> e;
        for(int i=0; i<e; i++){
            int u,v,d;
            cin >> u >> v >> d;
            edges.push_back({u,v,d});
            // edges.push_back({v,u,d});
        }
        BellmanFord();
    }
    return 0;
}
