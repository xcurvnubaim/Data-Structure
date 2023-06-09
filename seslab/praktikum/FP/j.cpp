#include <bits/stdc++.h>
#define MOD 1000000009
// #define FA 30
#define ull unsigned long long
using namespace std;

/* Iterative Function to calculate (x^y)%p in O(log y) */
int power(ull x, ull y)
{
    int res = 1;     // Initialize result
 
    x = x % MOD; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % MOD;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % MOD;
    }
    return res;
}

ull solve(ull x){
    ull k, res;
    if(x & 1){
        k = x*((x-1)/2);
    } else {
        k = (x/2)*(x-1);
    }
    return power(2,k);
    // k%=(MOD-1);
    // if(k<FA) return (1<<k);
    // else {
    //     res = (1<< (k%FA));
    //     // cout << k << " " << res << endl;
    //     ull temp = 73741815;
    //     for(int i=0; i< k/30; i++){
    //         res = res * temp % MOD;
    //     }
    //     return res;
    // }
}

int main(){
    ull m,n;
    cin >> m;
    while(m--){
        cin >> n;
        cout << "Zodiak found: "<< solve(n) << " signs"<< endl;
    }
    return 0;
}