#include <bits/stdc++.h>
using namespace std;

map<string,int> mp;

int main(){
    int n;
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        mp[str]++;
    }
    for(auto i:mp){
        cout << i.first << ": " << i.second << endl;
    }
}