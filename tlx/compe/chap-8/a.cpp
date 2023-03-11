#include <bits/stdc++.h>
using namespace std;

int main(){
    deque <int> mydeq;
    int t;
    cin >> t;
    while(t--){
        string s;
        int x;
        cin >> s;
        if(s=="push_back") {
            cin >> x;
            mydeq.push_back(x);
        } else if(s=="push_front"){
            cin >> x;
            mydeq.push_front(x);
        } else if(s=="pop_back"){
            mydeq.pop_back();
        } else {
            mydeq.pop_front();
        }
    }
    for(auto i = mydeq.begin(); i!=mydeq.end(); i++)
        cout << *i << "\n";
    return 0;
}