#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n+1];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int max_num=-1,idx, current=0;
    long long res=0;
    if(n < k){
        k=n;
    }
    while(current <= n-k){
        max_num=-1;
        for(int i=current; i<current + k; i++){
            if(max_num < arr[i]){
                max_num = arr[i];
                idx=i;
            }
        }
        arr[current] = max_num;
        res+= max_num;
        for(int i=current+1; i<=idx && i<=n-k; i++){
            arr[i] = max(arr[i-1],arr[i+k-1]);
            res += arr[i];
        }
        current = idx+1;
    }
    cout << res;
    return 0;
}