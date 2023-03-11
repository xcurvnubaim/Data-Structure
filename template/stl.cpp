#include <bits/stdc++.h>
using namespace std;


template <typename T>
class comparator{
    public:
        bool operator()(T a, T b){
            return(a>b);
        }
};

int main(){
    priority_queue<string, vector<string>, comparator<string>> mypqueue;
    mypqueue.push("halo");
    mypqueue.push("dunia");
    mypqueue.push("u");
    while(!mypqueue.empty()){
        cout << mypqueue.top() << " ";
        mypqueue.pop();
    }
    
    return 0;
}