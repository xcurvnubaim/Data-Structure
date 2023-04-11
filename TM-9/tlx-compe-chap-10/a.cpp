#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

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
    int n, q;
    cin >> n >> q;
    set.makeset(n+1);
    while(q--){
        int c, x, y;
        cin >> c >> x >> y;
        if(c==1){
            set.Union(x,y);
        } else {
            if(set.find(x) == set.find(y))
                cout << "Y\n";
            else
                cout << "T\n";
        }
    }
    return 0;
}