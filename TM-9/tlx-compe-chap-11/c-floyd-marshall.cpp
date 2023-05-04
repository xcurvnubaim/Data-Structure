#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);
#define endl '\n'
#define pii pair<int,int>
using namespace std;

int main(){
    fastio
    int v,e,q;
    cin >> v >> e >> q;
    int adjMat[v+1][v+1];
    for(int i=1; i<=v; i++)
        for(int j=1; j<=v; j++)
            adjMat[i][j] = 1e9;
    int x,y,z;
    for(int i=1; i<=v; i++)
        adjMat[i][i] = 0;
    while(e--){
        cin >> x >> y >> z;
        adjMat[x][y] = min(adjMat[x][y],z);
        adjMat[y][x] = min(adjMat[y][x],z);
    }

    //floyd-marshall
    for(int k=1; k<=v; k++){
        for(int i=1; i<=v; i++){
            for(int j=1; j<=v; j++){
                adjMat[i][j] = min(adjMat[i][j],
                adjMat[i][k] + adjMat[k][j]);
            }
        }
    }

    int start, target;
    start = 1;
    cin >> target;
    q--;
    long long res = 0;
    while(q--){
        start = target;
        cin >> target;
        res+= adjMat[start][target];
    }
    cout << res;
    return 0;
}