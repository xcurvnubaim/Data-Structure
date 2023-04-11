#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    fastio
    int r,c;
    cin >> r >> c;
    int map[r+2][c+2];
    memset(map,-1,sizeof(map));
    for(int i=1; i<=r; i++)
        for(int j=1; j<=c; j++)
            cin >> map[i][j];
    int x,y,MIN;
    cin >> x >> y;
    map[x][y]=1;
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        pair<int,int> pos = q.front();
        q.pop();
        if(pos.first==r || pos.second==c || pos.first==1 || pos.second ==1){
            MIN = map[pos.first][pos.second];
            break;
        }
        //ke kanan
        if(map[pos.first][pos.second+1]==0){
            map[pos.first][pos.second+1] += map[pos.first][pos.second] + 1;
            q.push({pos.first, pos.second+1});
        }
        //ke kiri
        if(map[pos.first][pos.second-1]==0){
            map[pos.first][pos.second-1] += map[pos.first][pos.second] + 1;
            q.push({pos.first, pos.second-1});
        }
        //ke bawah
        if(map[pos.first+1][pos.second]==0){
            map[pos.first+1][pos.second] += map[pos.first][pos.second] + 1;
            q.push({pos.first+1, pos.second});
        }
        //ke atas
        if(map[pos.first-1][pos.second]==0){
            map[pos.first-1][pos.second] += map[pos.first][pos.second] + 1;
            q.push({pos.first-1, pos.second});
        }
    }
    
    cout << MIN << endl;
    return 0;
}