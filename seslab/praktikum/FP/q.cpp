#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int v, e, start, target;

vector<int> dist;
struct ed{
    int e, d;
};

vector<vector<ed>> edges;

void dijkstra(){
    vector<bool> visited(v, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while(!pq.empty()){
        auto temp = pq.top();
        pq.pop();

        visited[temp.second] = true;

        for(auto vertex:edges[temp.second]){
            int nextVertex = vertex.e;
            int weight = vertex.d;

            if(!visited[nextVertex]){
                if(temp.first + weight < dist[nextVertex]) {
                    dist[nextVertex] = temp.first + weight;
                    pq.push(make_pair(dist[nextVertex], nextVertex));
                }
            }
        }
    }
}

int main(){
    cin >> v;
    vector<pair<int,string>> warung;
    pair<int,string> res;
    warung.push_back({INT_MAX,""});
    for(int i=0; i<v; i++){
        string x; int y;
        cin >> x >> y;
        warung.push_back(make_pair(y,x));
    } 
    cin >> e;
    dist.assign(v+1, INT_MAX);
    edges.assign(v+1, {});
    int x,y,z;
    while(e--){
        cin >> x >> y >> z;
        edges[x].push_back({y,z});
        edges[y].push_back({x,z});
    }
    start = 0;
    
    dijkstra();
    int cod;
    cin >> cod;
    res.first = INT_MAX;
    res.second = "";
    for(int i=1; i<=v; i++){
        if(dist[i]<=cod && res.first>warung[i].first){
            res = warung[i];
        }
    }
    cout << "hari ini makan di " << res.second;
    return 0;
}