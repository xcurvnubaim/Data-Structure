#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pii pair<int,int>

int v;
vector<vector<int>> adjMat;
map<int, int> pd;

struct nx{
    // priority_queue<int> pd;
    multiset<int , greater<int>> pd;
    // priority_queue<int, vector<int>, greater<int>> edgeCost;
    multiset<int> edgeCost;
};

map<int, nx> group;

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
ufds dsu;

int main(){
    int e;
    cin >> v >> e;
    dsu.makeset(v+1);
    adjMat.assign(v+1, vector<int>(v+1,0));
    for(int i=1; i<=v; i++){
        cin >> pd[i];
    }
    while(e--){
        int x,y,z;
        cin >> x >> y >> z;
        adjMat[x][y] = adjMat[y][x] = z;
        dsu.Union(x,y);
    }
    for(int i=1; i<=v; i++){
        group[dsu.find(i)].pd.insert(pd[i]);
    }
    for(int i=1; i<=v; i++){
        for(int j=i+1; j<=v; j++){
            if(adjMat[i][j]){
                group[dsu.find(i)].edgeCost.insert(adjMat[i][j]);
            }
        }
    }
    int q,temp;
    cin >> q;
    while(q--){
        
        char cmd;
        int a,b,c,d;
        cin >> cmd;
        if(cmd == '?'){
            cin >> a;
            if(a==1){
                cin >> b;
                if(group[dsu.find(b)].edgeCost.empty())
                    cout << 0 << endl;
                else
                    cout << *group[dsu.find(b)].edgeCost.begin() << endl;
            } else {
                cin >> b >> c;
                if(dsu.find(b)==dsu.find(c))
                    cout << 0 << endl;
                else {
                    cout << *group[dsu.find(b)].pd.begin() +
                            *group[dsu.find(c)].pd.begin() << endl; 
                }
            }
        } else {
            cin >> a;
            if(a==1){
                cin >> b >> c;
                // if(*group[dsu.find(b)].pd.begin()==pd[b]){
                temp = dsu.find(b);
                group[temp].pd.erase(group[temp].pd.find(pd[b]));
                group[dsu.find(b)].pd.insert(c);
                // }
                pd[b] = c;
            } else {
                cin >> b >> c >> d;
                // if(*group[dsu.find(c)].edgeCost.begin()==adjMat[b][c]){
                temp = dsu.find(b);
                group[temp].edgeCost.erase(group[temp].edgeCost.find(adjMat[b][c]));
                group[dsu.find(c)].edgeCost.insert(d);
                // }
                adjMat[b][c] = adjMat[c][b] = d;
            }
        }
    }
    return 0;
}