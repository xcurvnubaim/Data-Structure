#include <bits/stdc++.h>
using namespace std;

class comparator{
    public:
    bool operator()(int a,int b){
        return(a>b);
    }
};

int main(){
    int x,y;
    cin >> x >> y;
    priority_queue<int, vector<int>, comparator> arr;
    x +=y;
    int p;
    while(x--){
        cin >> p;
        arr.push(p);
    }
    while(!arr.empty()){
        cout << arr.top() << " ";
        arr.pop();
    }
    return 0;
}