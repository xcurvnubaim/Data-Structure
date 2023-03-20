#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    int sum=0;
    bool p;
    unsigned long long y;
    cin >> x;
    list<unsigned long long> arr;
    while(x--){
        cin >> y;
        p=1;
        for(auto i=arr.begin(); i!=arr.end(); i++){
            if(*i == y){
                arr.erase(i);
                p=0;
                break;
            }
        }
        if(p)
            arr.push_back(y);
    }
    cout << arr.size() << "\n";
    return 0;
}