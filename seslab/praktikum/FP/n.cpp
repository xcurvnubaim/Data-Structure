#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<bool> st;
    int n;
    cin >> n;
    while(n--){
        bool act;
        cin >> act;
        if(st.empty()){
            if(act){
                st.push(1);
                st.push(0);
            }else {
                st.push(0);
            }
        } else if(st.size()==1){
            if(st.top()){
                if(act){
                    st.pop();
                } else {
                    st.push(0);
                }
            } else if(act==0) {
                st.pop();
            }
        } else {
            if(st.top()){
                if(act){
                    st.pop();
                } else {
                    st.push(0);
                }
            } else {
                if(act){
                    st.pop();
                    st.push(1);
                    st.push(0);
                    st.push(1);
                    st.push(0);
                } else {
                    st.pop();
                }
            }
        }
    }
    cout << st.size() << endl;
    return 0;
}