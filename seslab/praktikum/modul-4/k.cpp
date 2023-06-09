#include <bits/stdc++.h>
using namespace std;

int r,c;
vector<vector<int>> mp;
vector<vector<bool>> visited;

int MAXLUAS;

int bfs(int i, int j, int Luas){
    if(mp[i][j]!=-1 && visited[i][j]==false){
        mp[i][j] += Luas;
        visited[i][j] = true;
        if(i!=0)
            mp[i][j] = bfs(i-1, j, mp[i][j]);
        if(j!=0)
            mp[i][j] = bfs(i, j-1, mp[i][j]);
        if(i!=r-1)
            mp[i][j] = bfs(i+1, j, mp[i][j]);
        if(j!=c-1)
            mp[i][j] = bfs(i, j+1, mp[i][j]);
        Luas = mp[i][j];
        MAXLUAS = max(MAXLUAS, Luas);
    }
    return Luas;
}

int main(){
    cin >> r >> c;
    MAXLUAS = -1;
    mp.assign(r,vector<int>(c,0));
    visited.assign(r, vector<bool>(c, false));
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++){
            char ch; int x;
            cin >> ch >> x;
            if(ch=='J'){
                mp[i][j] = -1;
            } else {
                mp[i][j] = x;
            }
        }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << mp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            // cout << mp[i][j] << " ";
            if(mp[i][j]!=-1) bfs(i,j,0);
        }
        // cout << endl;
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << mp[i][j] << " ";
        }
        cout << endl;
    }
    cout << MAXLUAS;
    return 0;
}