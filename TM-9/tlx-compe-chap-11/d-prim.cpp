#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);
#define endl '\n'
#define pii pair<int,int>
using namespace std;

int v;
vector<vector<int>> adjMat;

int primMST(){
    bool mstSet[v];
    int minMST = 0, count=0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    memset(mstSet, false, sizeof(mstSet));

    pq.push({0,0});

    while(!pq.empty() && count < v){
        pii x = pq.top(); pq.pop();
        if(!mstSet[x.second]){
            mstSet[x.second] = true;
            minMST += x.first;
            count++;
            for(int i=0; i<v; i++){
                if(!mstSet[i])
                    pq.push({adjMat[x.second][i],i});
            }
        }
    }

    return minMST;
}


int main(){
    fastio
    cin >> v;
    adjMat.assign(v, vector<int>(v,0));
    for(int i=0; i<v; i++)
        for(int j=0; j<v; j++)
            cin >> adjMat[i][j];
    
    int minCost = primMST();
    cout << minCost;
    return 0;
}