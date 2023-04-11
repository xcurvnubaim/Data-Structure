#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);
#define endl '\n'
using namespace std;
map<string, int> dist;
string num, sorted;
int n,k;

void bfs(){
    queue<string> q;
    q.push(num);
    dist[num] = 0;
    while(!q.empty()){
        string front = q.front();
        q.pop();
        if(front == sorted) return;
        for(int i=0; i<=n-k; i++){
            string temp = front;
            reverse(temp.begin()+i, temp.begin()+i+k);
            if(dist.find(temp) == dist.end()){
                dist[temp] = dist[front] + 1;
                q.push(temp);
            }
        }
    }
    dist[sorted] = -1;
}

int main(){
    fastio
    cin >> n;
    num.assign(n,'0');
    for(int i=0; i<n; i++) cin >> num[i];
    cin >> k;
    sorted = num;
    sort(sorted.begin(), sorted.end());
    bfs();
    cout << dist[sorted] << endl;
    return 0;
}