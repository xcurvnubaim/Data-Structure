#include <bits/stdc++.h>
using namespace std;

int main(){
    map<string, int> user;
    map<int, string> pc;
    set<int> tersedia;
    string cmd,nama;
    int n,t,x;
    cin >> n >> t;
    for(int i=1; i<=n; i++)
        tersedia.insert(i);
    while(t--){
        cin >> cmd; 
        if(cmd=="DATANG"){
            cin >> nama >> x;
            if(tersedia.find(x)==tersedia.end()){
                if(user.size()==n){
                    cout << "Penuh\n";
                } else {
                    auto minimum = tersedia.begin();
                    pc[*minimum] = nama;
                    user[nama] = *minimum;
                    tersedia.erase(minimum);
                }
            } else {
                pc[x] = nama;
                user[nama] = x;
                tersedia.erase(tersedia.find(x));
            }
        } else if(cmd == "SELESAI"){
            cin >> x;
            user.erase(pc[x]);
            tersedia.insert(x);
        } else if(cmd == "STATUS"){
            cin >> x;
            if(tersedia.find(x) != tersedia.end())
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