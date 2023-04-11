#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

struct ufds{
    vector<int> parent,rank;

    void makeset(int n){
        parent.assign(n+1,0);
        rank.assign(n+1,0);
        for(int i=1; i<=n; i++){
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
    vector<pair<int,int>> edges;
    vector<bool> connected;
    vector<int> khusus, setSize;
    vector<long long> prefix_sum;
    ufds sets;
    int t;
    cin >> t;
    while(t--){
        int n,e,q,r;
        int a,b;
        cin >> n >> e >> q >> r;
        sets.makeset(n);
        edges.assign(e,{0,0});
        khusus.assign(q,0);
        setSize.assign(n+1,0);
        prefix_sum.assign(n+1,0);
        connected.assign(e,1);
        for(int i=0; i<e; i++){
            cin >> edges[i].first >> edges[i].second;
        }
        for(int i=0; i<q; i++){
            cin >> khusus[i];
        }
        for(int i=0; i<r; i++){
            cin >> a;
            connected[a-1] = 0;
        }
        for(int i=0; i<e; i++){
            if(connected[i]){
                sets.Union(edges[i].first, edges[i].second);
            }
        }
        
        //calculate set size
        for(int i=0; i<q; i++){
            int temp= sets.find(khusus[i]);
            setSize[temp]++;
        }

        //prefix sum
        for(int i=1; i<n; i++){
            prefix_sum[i] = prefix_sum[i-1] + setSize[i];
        }

        //calculate disconected
        long long excl_set, sum=0;
        for(int i=1; i<n; i++){
            excl_set = q-prefix_sum[i];
            sum += setSize[i]*excl_set;
        }
        cout << sum << endl;
    }
    return 0;
}