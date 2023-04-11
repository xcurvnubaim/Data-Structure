#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);
#define endl '\n'
using namespace std;

priority_queue<int> pq;
int main(){
    int n,x;
    cin >> n;
    while(n--){
        cin >> x;
        switch (x)
        {
        case 1:
            cin >> x;
            pq.push(x);
            break;
        case 2:
            cout << pq.top() << endl;
            break;
        case 3:
            pq.pop();
            break;
        }
    }
    return 0;
}