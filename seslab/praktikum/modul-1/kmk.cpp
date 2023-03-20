#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int idx,kesusahan,keuntungan;
}node;

class comparator{
    public:
        bool operator()(node a, node b){
            if(a.keuntungan < b.keuntungan)
                return true;
            else if(a.keuntungan == b.keuntungan){
                if(a.kesusahan < b.kesusahan) return true;
                else if(a.kesusahan > b.kesusahan) return false;
                else if(a.idx > b.idx) return true;
            }
            return false;
        }
};

int main(){
    int t,idx,keuntungan=0,kesusahan=0;
    string str;
    priority_queue<node, vector<node>, comparator> mypqueue;
    node temp;
    cin >> t;
    idx=0;
    while(t--){
        cin >> str;
        int biaya, bayaran;
        if(str=="pekerjaan"){
            cin >> temp.kesusahan >> biaya >> bayaran;
            temp.keuntungan = bayaran - biaya;
            temp.idx = idx;
            idx++;
            mypqueue.push(temp);
        } else {
            int n;
            cin >> n;
            while(n--){
                if(mypqueue.size()){
                    temp = mypqueue.top();
                    if(temp.keuntungan >= 0){
                        cout << "Mengerjakan pekerjaan " << temp.idx << "\n";
                        keuntungan += temp.keuntungan; 
                        kesusahan += temp.kesusahan;
                    }else{
                        cout << "Skip pekerjaan " << temp.idx << "\n";
                        n++;
                    }
                    mypqueue.pop();
                } else {
                    cout << "Sabar Woy!\n";
                    break;
                }
            }
        }
    }
    cout << "Total Kesusahan: " << kesusahan << "\n";
    cout << "Total Keuntungan: "<< keuntungan << "\n";
}