#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main(){
    int n;
    cin >> n;
    queue<int> in;
    ull x;
    while(n--){
        cin >> x;
        in.push(x);
    }
    int q;
    ull w;
    cin >> q >> w;
    stack<ull> bag;
    while(q--){
        string str;
        cin >> str;
        if(str=="add"){
            x = in.front();
            bag.push(x);
            in.pop();
        } else {
            bag.pop();
        }
    }
    int size = bag.size();
    ull sum=0;
    while(!bag.empty()){
        sum+=bag.top();
        bag.pop();
    }
    if(sum==w){
        cout << sum << " " << size;
    }else cout << "-1";
    return 0;
}