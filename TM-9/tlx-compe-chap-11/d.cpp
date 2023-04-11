#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);
#define endl '\n'
#define minimum using
#define sepaneng namespace
#define tree std;

minimum sepaneng tree

int n;
struct ufds{
    vector<int> parent,rank;

    void makeset(int n){
        parent.assign(n,0);
        rank.assign(n,0);
        for(int i=1; i<n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        while(parent[x]!=x)
            x = parent[x];
        return x;
    }

    void Union(int x, int y){
        int a = find(x);
        int b = find(y);
        if(a!=b){
            if(rank[a] > rank[b]) {
                parent[b] = a;
            } else {
                parent[a] = b;
                if(rank[a] == rank[b]) rank[b]++;
            }
        }
    }
};

int main(){
    fastio
    ufds set;
    cin >> n;
    set.makeset(n);
    int adjMat[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> adjMat[i][j];
    
    int minCost = 0, edgeCount = 0;
    while(edgeCount < n-1){
        int MIN = INT_MAX, a, b;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(set.find(i)!=set.find(j) &&
                    adjMat[i][j] < MIN){
                        MIN = adjMat[i][j];
                        a = i;
                        b = j;
                    }
            }
        }
        set.Union(a,b);
        edgeCount++;
        minCost += MIN;
    }
    cout << minCost;
    return 0;
}