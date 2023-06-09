#include <bits/stdc++.h>
using namespace std;



int main(){
    int v, e, pos;
    cin >> v >> e >> pos;
    vector<vector<int>> edge(v+1);
    while(e--){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    queue<int> q;
    int dist[v+1];
    for(int i=1; i<=v; i++) dist[i] = INT_MAX;
    dist[pos] = 0;
    q.push(pos);
    while(!q.empty()){
        int z = q.front(); q.pop();
        for(int i:edge[z]){
            int temp = dist[z] + 1;
            if(dist[i] > temp){
                dist[i] = temp;
                q.push(i);
            }
        }
    }
    map<int, int> rad;
    set<int> lb;
    for(int i=1; i<=v; i++){
        rad[dist[i]]++;
        lb.insert(dist[i]);
    }
    auto tr = lb.end();
    tr--;
    for(int i=1; i<=*tr; i++){
        rad[i] += rad[i-1];
    }
    int day;
    cin >> day;
    while(day--){
        int r;
        cin >> r;
        if(r <= *tr){
            cout << rad[r] << endl;
        } else {
            auto itr = rad.end();
            itr--;
            cout << itr->second << endl;

        }
    }
    return 0;
}