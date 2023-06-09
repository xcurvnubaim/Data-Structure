#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);
#define endl '\n'
#define pii pair<int,int>
using namespace std;

int main(){
    fastio
    int v,e,q;
    cin >> v;
    int adjMat[v][v];
    for(int i=0; i<v; i++)
        for(int j=0; j<v; j++)
            adjMat[i][j] = 1e9;
    int x,y,z;
    // for(int i=1; i<=v; i++)
    //     adjMat[i][i] = 0;
    while(true){
        cin >> x >> y;
        if(x == -1 && y==-1) break;
        adjMat[x][y] = 1;
        // adjMat[y][x] = 1;
    }

    // floyd-marshall
    for(int k=0; k<v; k++){
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                adjMat[i][j] = min(adjMat[i][j],
                adjMat[i][k] + adjMat[k][j]);
            }
        }
    }

    // int start, target;
    // start = 1;
    // cin >> target;
    // q--;
    // long long res = 0;
    // while(q--){
    //     start = target;
    //     cin >> target;
    //     res+= adjMat[start][target];
    // }
    // cout << res;
    // for(int i=0; i<v; i++)
    // {
    //     for(int j=0; j<v; j++){
    //         cout << adjMat[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for(int i=0; i<v; i++){
        if(adjMat[i][i] != 1e9) 
            cout << adjMat[i][i] << endl;
        else cout << "gak bisa pulang mamah" << endl;
    }
    return 0;
}