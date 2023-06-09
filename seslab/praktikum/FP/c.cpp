#include <bits/stdc++.h>
using namespace std;

map<int,int> element;

int main(){
    int t,n,x;
    pair<int,int> temp = make_pair(-1, -1);
    cin >> t;
    while(t--){
        element.clear();
        int count=0;
        temp = make_pair(-1,-1);
        cin >> n;
        while(n--){
            cin >> x;
            count++;
            element[x]++;
        }
        for(auto i:element){
            if(i.second > temp.second) temp = i;
        }
        if(element.size()==1){
            cout << count << endl;
        } else if(element.size()==2){
            cout << 2*temp.second - count << endl;
        } else {
            if(temp.second*2 <= count){
                cout << (count & 1) << endl;
            } else {
                cout << 2*temp.second - count << endl;
            }
        }
    }
    return 0;
}