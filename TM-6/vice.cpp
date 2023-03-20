#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    int digit = max(a,b);
    stack<int> x,y;
    list<int> z;
    int temp;
    for(int i=0; i<a; i++){
        cin >> temp;
        x.push(temp);
    }
    for(int i=0; i<b; i++){
        cin >> temp;
        y.push(temp);
    }
    int sisa=0;
    for(int i=0; i<digit; i++){
        temp=sisa;
        if(!x.empty()){
            temp += x.top();
            x.pop();
        }
        if(!y.empty()){
            temp += y.top();
            y.pop();
        }
        sisa = temp/10;
        if(temp>=10){
            temp%=10;
        }
        z.push_front(temp);
    }
    if(sisa)
        z.push_front(sisa);
    for(auto i=z.begin(); i!=z.end(); i++){
        cout << *i;
    }
    cout << "\n";
}