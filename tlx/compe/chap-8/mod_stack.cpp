// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void add(vector<int>&);
void adx(vector<int>&);
void del(vector<int>&);
void dex(vector<int>&);

int main(){
    ios::sync_with_stdio(0); cin.tie(0); 
    int n;
    vector<int> setak;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        if(s=="add") add(setak);
        else if(s=="del") del(setak);
        else if(s=="adx") adx(setak);
        else dex(setak);
    }
    return 0;
}

void add(vector<int> &setak){
    int a,x;
    cin >> a >> x;
    while(x--) setak.push_back(a);
    cout << setak.size() << endl;
}

void del(vector<int> &setak){
    int a;
    cout << setak.back() << endl;
    cin >> a;
    while(a--) setak.pop_back();
}

void adx(vector<int> &setak){
    int a;
    cin >> a;
    for(auto i = setak.begin(); i!= setak.end() ; i++) *i+=a;
}
void dex(vector<int> &setak){
    int a;
    cin >> a;
    for(auto i = setak.begin(); i!= setak.end() ; i++) *i-=a;
}