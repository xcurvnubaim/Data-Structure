#include <bits/stdc++.h>
using namespace std;

struct nd{
    int data,idx;
};

bool comparator(nd a, nd b){
    return (a.data < b.data);
}

void q_insert(int x, list<nd> &set){
    auto i = set.begin();
    while(i->data < x && i!=set.end())
        i++;
    int id = set.size();
    set.insert(i,{x,id});
}

void q_delete(int x, list<nd> &set){
    for(auto i=set.begin(); i!=set.end(); i++)
        if(i->idx == x)
            set.erase(i);
}

int main(){
    int n,q,m,temp,target;
    cin >> n >> q;
    list<nd> set[n+1];
    for(int i=1; i<=n; i++){
        cin >> m;
        for(int j=0; j<m; j++){
            cin >> temp;
            set[i].push_back({temp,j});
        }
        set[i].sort(comparator);
    }
    
    while(q--){
        string str;
        cin >> str;
        if(str=="tambah"){
            cin >> temp >> target;
            q_insert(temp, set[target]);
        } else if(str=="hilang"){
            cin >> temp >> target;
            q_delete(temp, set[target]);
        } else if(str=="tukar"){
            cin >> temp >> target;
            list<nd> v = set[target];
            set[target] = set[temp];
            set[temp] = v;
        } else if(str=="b_atas"){
            cin >> temp >> target;
            auto itr = set[target].begin();
            for(int i=0; i<temp; i++)
                itr++;
            cout << itr->data + 1 << "\n";
        } else if(str=="b_bawah"){
            cin >> temp >> target;
            auto itr = set[target].begin();
            for(int i=0; i<temp; i++)
                itr++;
            cout << itr->data - 1 << "\n";
        } else if(str=="banyak"){
            cin >> target;
            cout << set[target].size() << "\n";
        } else if(str=="mean"){
            cin >> target;
            double mean=0;
            for(auto i=set[target].begin(); i!=set[target].end(); i++)
                mean += i->data;
            cout << mean/set[target].size() << "\n";
        } else if(str=="median"){
            cin >> target;
            int num = set[target].size();
            auto itr = set[target].begin();
            if(num & 1){
                for(int i=0; i<temp/2; i++)
                    itr++;
            } else {
                auto itr = set[target].begin();
                for(int i=0; i<temp/2; i++)
                    itr++;
                cout << 1.0*(itr->data + (++itr->data))/2 << "\n";
            }
        } else if(str=="modus"){
            int nowNum=-1, count=0;
            struct {
                int val, c=-1;
            } MAX;
            for(auto i=set[target].begin(); i!=set[target].end(); i++){
                if(i==set[target].begin()){
                    nowNum = i->data;
                    count=1;
                    MAX = {i->data,1};
                } else {
                    if(i->data != nowNum){
                        nowNum = i->data;
                        count = 0;
                    } 
                    count++;
                }
                if(MAX.c < count){
                    MAX.c = count;
                    MAX.val = nowNum;
                }
            }
            cout << MAX.val << "\n";
        } else {
            cin >> target;
            for(auto i=set[target].begin(); i!=set[target].end(); i++)
                cout << i->data << " ";
            cout << "\n";
        }
    }
    return 0;
}