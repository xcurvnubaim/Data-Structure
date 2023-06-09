#include <bits/stdc++.h>
using namespace std;

unordered_multiset<int> st;

int main(){
    int n,x;
    cin >> n;
    while(n--){
        cin >> x;
        st.insert(x);
    }

    return 0;
}