#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

vector<vector<int>> mp;
// vector<vector<bool>> visited;
int pulau,r,c, MAXLUAS, temp;
map<int,int> out;
void bfs(int i, int j){
    if(mp[i][j]==1){
        mp[i][j]=pulau;
        if(i!=0) bfs(i-1,j);
        if(j!=0) bfs(i,j-1);
        if(i!=r-1) bfs(i+1,j);
        if(j!=c-1) bfs(i, j+1);
    }
}

int main(){
    cin >> r >> c;
    MAXLUAS = 0;
    pulau = 1;
    mp.assign(r, vector<int>(c));
    // visited.assign(r, vector<bool>(c, false));
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin >> mp[i][j];

    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++){
            if(mp[i][j]==1){
                pulau++;
                temp = mp[i][j];
                bfs(i,j);
            }
        }               
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(mp[i][j]!=0) out[mp[i][j]]++;
        }
    }
    
    for(auto x:out)
        MAXLUAS = max(MAXLUAS, x.second); 
    
    cout << "Banyak Pulau: " << pulau-1 << endl;
    cout << "Luas Terbesar: " << MAXLUAS << endl;                   
    return 0;
}