#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool dp[141];
    int t;
    memset(dp,0,sizeof(dp));
    for(int i=0; i<=14; i++){
        for(int j=0; j<=10; j++){
            if(11*i+15*j<141){
                dp[11*i+15*j]=1;
            } else 
                break;
        }
    }
    cin >> t;
    while(t--){
        unsigned long long x;
        cin >> x;
        if(x >= 140){
            cout << "YES" << endl;
        } else {
            if(dp[x]) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}