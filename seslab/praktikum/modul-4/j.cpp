#include <bits/stdc++.h>
using namespace std;

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

    int setCount(){
        set<int> par;
        for(int i=0; i<parent.size(); i++){
            par.insert(find(i));
        }
        return par.size();
    }
};

int main(){
    ufds dsu;
    int v, e;
    cin >> v >> e;
    dsu.makeset(v);
    while(e--){
        int a,b;
        cin >> a >> b;
        a--; b--;
        dsu.Union(a,b);
    }
    cout << dsu.setCount()-1 << endl;
    return 0;
}