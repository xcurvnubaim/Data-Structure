#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,e,q,r;
    cin >> n >> e >> q >> r;
    vector<pair<int,int>> edges;
    vector<bool> terhubung;
    for(int i=0; i<e; i++){
        int x,y;
        cin >> x >> y;
        edges.push_back({x,y});
        terhubung.push_back(1);
    }
    vector<int> node_khusus;
    int temp;
    for(int i=0; i<q; i++){
        cin >> temp;
        node_khusus.push_back(temp);
    }

    for(int i=0; i<r; i++){
        cin >> temp;
        terhubung[temp-1] = 0;
    }

    int adjMat[n+2][n+2] = {};

    for(int i=0; i<e; i++){
        // if(!terhubung[i]){
            adjMat[edges[i].first][edges[i].second] = 1;
            for(int j=0; j<n; j++){
                if(adjMat[edges[i].second][j]){
                    adjMat[j][edges[i].first] = 1;
                }
            }
            adjMat[edges[i].second][edges[i].first] = 1;
        // }
    }

    for(int i=0; )

    return 0;
}