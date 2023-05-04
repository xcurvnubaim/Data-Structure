#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);
#define endl '\n'
#define pip pair<int, pair<int,int>>
using namespace std;

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
        int root = x;
        while(parent[root]!=root)
            root = parent[root];

        while(parent[x] != root){
            int temp = parent[x];
            parent[x] = root;
            x = temp;
        }
        return root;
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
    
    //kruskal
    priority_queue<pip, vector<pip>, greater<pip>> edges;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            edges.push({adjMat[i][j], {i,j}});
        }
    }
    int minCost = 0, edgeCount = 0;
    while(edgeCount < n-1){
        pip temp = edges.top(); 
        edges.pop();
        int a = temp.second.first, b = temp.second.second;
        if(set.find(a) != set.find(b)){
            set.Union(a,b);
            edgeCount++;
            minCost += temp.first;
        }
    }
    cout << minCost;
    return 0;
}