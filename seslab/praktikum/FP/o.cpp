#include <bits/stdc++.h>
using namespace std;
int matrix[101][101];
int n,m,x,y;

void df(int x, int y, int v){
    if(x != -1 && x != n &&
       y != -1 && y != n && 
       v < matrix[x][y]){
        matrix[x][y] = v;
        v++;
        df(x+1,y,v);
        df(x-1,y,v);
        df(x,y+1,v);
        df(x,y-1,v);
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            matrix[i][j] = 5;


    while(m--){
        cin >> x >> y;
        x--; y--;
        df(y,x,1);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << (matrix[i][j]==5 ? 0 : matrix[i][j]) << " ";
        cout << endl;
    }
    return 0;
}