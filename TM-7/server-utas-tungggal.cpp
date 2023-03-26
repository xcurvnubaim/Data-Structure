#include <bits/stdc++.h>
using namespace std;
typedef struct {
    int idx;
    unsigned long long t,d;
} q;

unsigned long long proses=0;
vector<long long> res;
queue<q> myqueue;
void dequeue(){
    q temp = myqueue.front();
    myqueue.pop();
    proses = max(proses,temp.t) + temp.d;
    res[temp.idx] = proses;
}

int main(){
    unsigned long long n,b,x,y;
    cin >> n >> b;
    res.assign(n,-1);
    for(int i=0; i<n ; i++){
        cin >> x >> y;
        if(proses == 0){
            proses = x+y;
            res[0] = proses;
        } else {
            if(x < proses){
                if(myqueue.size() < b){
                    myqueue.push({i,x,y});
                }
            } else {
                while(x >= proses && !myqueue.empty())
                    dequeue();
                myqueue.push({i,x,y});
            }
        }
    }

    while(!myqueue.empty())
        dequeue();

    for(int i=0; i<n; i++){
        cout << res[i] << " ";
    }
    return 0;
}