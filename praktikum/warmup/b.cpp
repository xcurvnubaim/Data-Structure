#include <bits/stdc++.h>
using namespace std;

int  main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    unsigned a=0,b=-1;
    int q;
    cin >> q;
    while(q--){
        int p;
        cin >> p;
        if(p==1){
            string str; int x;
            cin >> str >> x;
            switch(str[0]){
                case 'X' :
                    a ^= x;
                    b ^= x;
                    break;
                case 'O' :
                    a |= x;
                    b |= x;
                    break;
                case 'A' :
                    a &= x;
                    b &= x;
                    break;
            }
        } else {
            for(int i=0; i<n; i++)
                cout << ((~arr[i] & a ) | (arr[i] & b)) << " ";
            cout << "\n";
        }
    }

    return 0;
}