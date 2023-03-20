#include <bits/stdc++.h>
using namespace std;

int main(){
    list<string> dir;
    dir.push_back("home");
    dir.push_back("anton");
    string str;
    int q;
    cin >> q;
    while(q--){
        cin >> str;
        if(str=="goto"){
            cin >> str;
            dir.push_back(str);
        } else if(str=="whereami"){
            if(dir.empty()){
                cout << "i am nowhere\n";
                continue;
            }
            for(auto i=dir.begin(); i!=dir.end(); i++){
                if(i!=dir.begin()) cout << "/";
                cout << *i;
            }
            cout << "\n";
        } else {
            if(dir.empty()){
                cout << "cannot go back\n";
            } else
                dir.pop_back();
        }
    }
    return 0;
}