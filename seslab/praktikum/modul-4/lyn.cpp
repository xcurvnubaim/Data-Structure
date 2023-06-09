#include <bits/stdc++.h>
using namespace std;

//x1 x2 x3 0 1 2
//y1 y2 y3 3 4 5
//z1 z2 z3 6 7 8
int translate(){
    char ch;
    int x;
    int temp;
    cin >> ch >> x;
        if(ch=='X') temp= 1 + x;
        else if(ch=='Y') temp = 4 + x;
        else temp = 7 + x;
    return temp-2;
}

struct dsu{
    vector<int> parent;
    
    void makeset(int n){
        for(int i=0; i<n; i++)
            parent.push_back(i);
    }

    int find(int x){
        if(x == parent[x])
            return x;
        else
            return parent[x] = find(parent[x]);
    }

    void Union(int a, int b){
        int x = find(a);
        int y = find(b);
        if(x!=y)
            parent[x] = y;
    }
};

int main(){
    int n;
    cin >> n;
    dsu st;
    st.makeset(9);
    while(n--){
        int n1, n2;
        n1 = translate();
        string buffer;
        cin >> buffer;
        n2 = translate();
        st.Union(n1,n2);
    }
    map<int, int> group;
    for(int i=0; i<9; i++){
        group[st.find(st.parent[i])]++;
    }
    vector<int> prefix_sum;
    prefix_sum.push_back(0);
    for(auto i:group){
        prefix_sum.push_back(i.second + prefix_sum.back());
    }
    int sum = 0;
    for(int i=1; i<prefix_sum.size(); i++){
        sum += (9-prefix_sum[i])*
            (prefix_sum[i]-prefix_sum[i-1]);
    }
    cout << sum;
    return 0;
}