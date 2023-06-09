#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long a,b,c, sum=0,h;
    string str;
    cin >> str >> h;
    cout << (1ull<<(h+1))-1 << " ";
    if(str=="BST"){
        cout << (h+1);
    } else {
        a=1; b=1;
        if(h==0) sum = 1;
        else if(h==1) sum = 2;
        else {
            sum = 2;
            for(int i=2; i<=h; i++){
                c = a + b;
                a = b;
                b = c;
                sum += c;
            }
        }
        cout << sum; 
    }
}

1 1 2 3 5 8
1 2 4 7 12 20