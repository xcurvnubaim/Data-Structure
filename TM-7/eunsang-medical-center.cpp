#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct pasien {
    string nama;
    int parah, umur, idx;
};

bool comparator(pasien a, pasien b){
    if(a.parah > b.parah) return true;
    if(a.parah == b.parah && a.umur > b.umur) return true;
    if(a.parah == b.parah && a.umur == b.umur && a.idx > b.idx)
        return true;
    return false;
}

int main(){
    int a,b,c,n;
    cin >> a >> b >> c >> n;
    list<pasien> a_doc, b_doc, c_doc, z_doc;
    int a_cp, b_cp, c_cp, tot; 
    a_cp = a*2;
    b_cp = b*3;
    c_cp = c*4;
    tot = a_cp + b_cp + c_cp;
    for(int i=0; i<n; i++){
        pasien x;
        x.idx=i;
        cin >> x.nama >> x.parah >> x.umur;
        if(       x.parah < 5  && tot > 0){
            c_doc.push_back(x);
        } else if(x.parah <= 7 && x.parah >=5 && b_doc.size() < b_cp) {
            b_doc.push_back(x);
        } else if(x.parah <= 10 && x.parah >=8 && a_doc.size() < a_cp) {
            a_doc.push_back(x);
        } else {
            z_doc.push_back(x);
            tot++;
        }
        tot--;
    }

    a_doc.sort(comparator);
    cout << "Treated by Senior Doctor: " << a_doc.size() << endl;
    for(auto i=a_doc.begin(); i!=a_doc.end(); i++)
        cout << i->nama << " " << i->parah << " " << i->umur << endl;

    b_doc.sort(comparator);
    cout << endl << "Treated by Resident: " << b_doc.size() << endl;
    for(auto i=b_doc.begin(); i!=b_doc.end(); i++)
        cout << i->nama << " " << i->parah << " " << i->umur << endl;
    c_doc.sort(comparator);
    cout << endl << "Treated by Intern: " << c_doc.size() << endl;
    for(auto i=c_doc.begin(); i!=c_doc.end(); i++)
        cout << i->nama << " " << i->parah << " " << i->umur << endl;
    z_doc.sort(comparator);
    cout << endl << "Sent to Another Hospital: " << z_doc.size() << endl;
    for(auto i=z_doc.begin(); i!=z_doc.end(); i++)
        cout << i->nama << " " << i->parah << " " << i->umur << endl;
    return 0;
}