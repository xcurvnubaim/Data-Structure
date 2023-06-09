#include <bits/stdc++.h>
using namespace std;


int main(){
    map<string, int> user;
    string cmd,nama;
    int n,t,x;
    cin >> n >> t;
    vector<bool> tersedia(n+1, true);
    vector<string> pc(n+1, "");
    while(t--){
        cin >> cmd;
        if(cmd=="DATANG"){
            cin >> nama >> x;
            if(tersedia[x]==false){
                if(user.size()==n){
                    cout << "Penuh\n";
                } else {
                    for(int i=1; i<=n; i++){
                        if(tersedia[i]){
                            pc[i] = nama;
                            user[nama] = i;
                            tersedia[i] = false;
                            break;
                        }
                    }
                }
            } else {
                pc[x] = nama;
                user[nama] = x;
                tersedia[x] = false;
            }
        } else if(cmd == "SELESAI"){
            cin >> x;
            user.erase(pc[x]);
            tersedia[x] = true;
        } else if(cmd == "STATUS"){
            cin >> x;
            if(tersedia[x] == true)
                cout << "Kosong" << endl;
            else
                cout << "Digunakan " << pc[x] << endl;
        } else if(cmd == "CARI"){
            cin >> nama;
            if(user.find(nama)==user.end()) cout << "Tidak ada\n";
            else
                cout << "Komputer " << user[nama] << endl;            
        } else {
            cout << user.size() << endl;
        }
    }
    return 0;
}