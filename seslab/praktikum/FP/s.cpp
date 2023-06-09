#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    vector<string> arr;
    string str;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> str;
        arr.push_back(str);
    }
    int res=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(stoi(arr[i]+arr[j])%k==0)
                res++;
            if(stoi(arr[j]+arr[i])%k==0)
                res++;
        }
    }
    cout << res;
    return 0;
}