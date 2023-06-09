#include <bits/stdc++.h>
using namespace std;

map<string,string> IPname;
struct email_struct {
    map<string, vector<string>> msg;
};

int main(){
    int n,q;
    string str1, str2, str3; 
    cin >> n >> q;
    map<string, email_struct> email;
    for(int i=0; i<n; i++){
        cin >> str1 >> str2;
        IPname[str1] = str2;
    }

    while(q--){
        cin >> str1 >> str2 ;
        getline(cin,str3);
        if(IPname.find(str1) != IPname.end() &&
            IPname.find(str2) != IPname.end())
            email[str2].msg[str1].push_back(str3);
    }

    for(auto i:IPname){
        if(!email[i.first].msg.empty()){
            cout << "===========\n";
            cout << "Mail: " << i.second << endl;
            for(auto a:email[i.first].msg){
                cout << "From: " << IPname[a.first] << endl;
                for(auto y:a.second){
                    cout << ">>" << y << endl;
                }
            }
        }
    }
    return 0;
}