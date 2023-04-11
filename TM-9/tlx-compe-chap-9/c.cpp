#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);
#define endl '\n'
using namespace std;
map<string, string> edges;
map<string, bool> kunjungi;

int main(){
    int n,m;
    cin >> n >> m;
    while(m--){
        string p, c;
        cin >> p >> c;
        edges[c] = p;
    }
    string a, b;
    cin >> a >> b;
    string x,y,temp;
    vector<string> out;
    x=a; y=b;
    while(edges[b]!=""){
        out.push_back(b);
        b = edges[b];
        if(b==a) break;
    }
    if(b!=a){
        out.clear();
        a=y;
        b=x;
        while(edges[b]!=""){
            out.push_back(b);
            b = edges[b];
            if(b==a) break;
        }
    }
    out.push_back(b);
    if(out.size() && b==a){
        for(int i=out.size()-1; i>=0; i--){
            cout << out[i] << endl;
        }
    } else {
        cout << "TIDAK MUNGKIN\n";
    }
    return 0;
}