#include <bits/stdc++.h>
using namespace std;

#define nodes pair<string,int>

class Compare{
    public:
        bool operator()(nodes x, nodes y){
            return (x.second <= y.second ||
            (x.second <= y.second &&  x.first>y.first));
        }
};

int main(){
    priority_queue<nodes,vector<nodes>,Compare> mypqueue;
    queue<pair<string,int>> myqueue;    
    int ruang,q,tersedia;
    string nama,namapenyakit;
    string penyakit[4] = {"flu","maag","diare","pusingkebanyakantugas"};
    int jumlah_penyakit[4] = {};
    cin >> ruang;
    // tersedia = ruang;
    while (cin >> q)
    {
        if(q==1){
            cin >> nama >> namapenyakit;
            cout << "pasien atas nama " << nama << " terdaftar dalam database" << '\n';
            if(myqueue.size()<ruang){
                // tersedia--;
                for(int i=0;i<4;i++)
                    if(namapenyakit == penyakit[i])
                        myqueue.push(make_pair(nama,i));
                cout << "pasien atas nama " << nama << " langsung masuk" << '\n';
            } else {
                for(int i=0;i<4;i++)
                    if(namapenyakit == penyakit[i])
                        mypqueue.push(make_pair(nama,i));
                cout << "pasien atas nama " << nama << " mengantri" << '\n';
            }
        } else {
            if(myqueue.size()>0){
                int op = myqueue.front().second;
                cout << "pasien atas nama " << myqueue.front().first << " sudah selesai konsultasi " <<
                penyakit[op] << '\n';
                jumlah_penyakit[op]++;
                myqueue.pop();
            }
            // if(tersedia<=ruang) tersedia++;
            if(mypqueue.size()>0){
                pair<string,int> temp;
                temp = mypqueue.top();
                mypqueue.pop();
                myqueue.push(temp);
                cout << "pasien atas nama " << temp.first <<" masuk dari antrian" << '\n';
            }
        }
    }
    // if(jumlah_penyakit[0]>0) cout << ""
    return 0;
}