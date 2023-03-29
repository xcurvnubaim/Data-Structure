#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> gedung;
    while(n--){
        int s;
        cin >> s;
        gedung.push_back(s);
    }

    int MAX=-1, stamina = 0, tp;
    for(int i=0; i<gedung.size(); i++){
        tp = stamina = gedung[i];
        for(int j=i+1; j<gedung.size(); j++){
            if(gedung[j]>=tp){
                stamina = stamina ^ gedung[j];
                tp = gedung[j];
            }
        }
        MAX = max(MAX, stamina);
    }
    cout << MAX << endl;
    return 0;
}