#include <bits/stdc++.h>
using namespace std;

class ufds{
    vector<int> parent, rank;

    void makeset(int n){
        parent.assign(n,0);
        rank.assign(n,0);
        for(int i=1; i<n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        int root = x;
        while(parent[root] != root)
            root = parent[root];
        
        int temp;
        while(x != root){
            temp = parent[x];
            parent[x] = root;
            x = temp;
        }
        return root;
    }

    void Union(int x, int y){
        int a = find(x);
        int b = find(y);
        if(a!=b){
            if(rank[a] > rank[b])
                parent[b] = a;
            else{
                parent[a] = b;
                if(rank[a]==rank[b]) rank[b]++;
            }
        }
    }
};