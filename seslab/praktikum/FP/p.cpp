#include <bits/stdc++.h>
using namespace std;

char maps[102][102];
bool visited[102][102];
int r,c;

void bfs(int x, int y){
    if(!visited[x][y] && maps[x][y]!='X' &&
        x!=-1 && y!=-1 && x!=r && y!=c){
        visited[x][y] = true;
        bfs(x-1,y);    
        bfs(x+1,y);
        bfs(x,y-1);
        bfs(x,y+1);    
    }
}

int main(){
    cin >> r >> c;
    memset(visited, 0, sizeof visited);
    for(int i=0; i<r; i++){
        string str;
        cin >> str;
        for(int j=0; j<c; j++){
            maps[i][j] = str[j];
        }
    }
    for(int i=0; i<r; i++){
        bfs(i,0);
        bfs(i,c-1);
    }
    for(int i=0; i<c; i++){
        bfs(0,i);
        bfs(r-1,i);
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(maps[i][j]=='^') bfs(i,j);   
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(maps[i][j]=='O'){
                cout << (visited[i][j] ? 'O' : 'X'); 
            } else {
                cout << maps[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}