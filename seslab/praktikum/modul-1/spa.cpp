#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    while(1){
        cin >> str;
        if(str=="stop") break;
        stack<string> path;
        string temp;
        int a;
        a=0;
        str += '/';
        for(int i=1; i<str.size(); i++){
            if(str[i]=='/'){
                temp = str.substr(a,i-a);
                a=i;
                if(temp=="/.." || temp==".."){
                  if(path.empty()) continue;
                  path.pop();  
                } 
                else if(temp=="/." || temp=="/" || temp==".") continue;
                else path.push(temp);
            }
        }
        string output;
        output = "";
        while(!path.empty()){
            if(path.top()=="/"){
                path.pop();
                continue;
            }
            output = path.top() + output;
            path.pop();
        }
        if(output[0]!='/') output = '/' + output;
        cout << output << endl;
    }

    return 0;
}