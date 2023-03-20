#include <bits/stdc++.h>
using namespace std;

typedef struct{
    vector<int> child, ancestors;
    int new_id, level;
}Node;

vector<int> level[100002];
int newID = 1;
void dfs(Node *node, int loc, int lv){
    node[loc].new_id = newID;
    node[loc].level = lv;
    level[lv].push_back(newID);
    newID++;
    for(auto i=node[loc].child.begin(); i!=node[loc].child.end(); i++)
        dfs(node, *i, lv+1);
}

int lca(Node *node,int v, int p){
    int j;
        for(int i=0;;i++){
            if(p & (1<<i)){
                if(node[v].ancestors.size()>i){
                    v = node[v].ancestors[i];
                } else
                    return -1;  
            } else if( p < (1<<i))
                break;
        }
    return v ? v : -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    Node node[n+2];
    for(int i=1; i<=n; i++){
        int y;
        cin >> y;
        node[y].child.push_back(i);
        node[i].ancestors.push_back(y);
    }

    for(int i=1; i<=n; i++){
        for(int j=0;j<node[i].ancestors.size();j++){
            if(node[node[i].ancestors[j]].ancestors.size() > j){
                int xy = node[node[i].ancestors[j]].ancestors[j];
                if(xy)
                    node[i].ancestors.push_back(xy);
            } else
                break;
        }
    }

    for(auto i=0; i<node[0].child.size(); i++)
        dfs(node, node[0].child[i],0);
    int m,v,p;
    cin >> m;
    while(m--){
        cin >> v >> p;
        int ancestor = lca(node,v,p);
        if(ancestor==-1){
            cout << "0 ";
        } else {
            vector<int> &anc_lev = level[node[ancestor].level];
            vector<int> &v_lev = level[node[v].level];
            auto left = lower_bound(v_lev.begin(),
                v_lev.end(),node[ancestor].new_id);
            int right_id = INT_MAX; 
            auto temp = lower_bound(anc_lev.begin(),
                anc_lev.end(),node[ancestor].new_id);
            if(temp != anc_lev.end()){
                temp++;
                if(temp!=anc_lev.end()) right_id = *temp;
            }
            auto right = lower_bound(v_lev.begin(),v_lev.end(),right_id);
            int c = right - left - 1;
            cout << c << " ";
        }
    }
    return 0;
}