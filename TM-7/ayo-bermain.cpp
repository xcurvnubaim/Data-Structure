#include <bits/stdc++.h>
#define endl "\n"
using namespace std;


int main(){
    string player[4];
    deque<int> loc[4];
    for(int i=0; i<4; i++)
        cin >> player[i];
    
    int n,lp;
    string jaga;
    cin >> n >> jaga;
    while(n--){
        int u,v;
        cin >> u >> v;
        u--;
        loc[u].push_back(v);
    }

    for(int i=0; i<4; i++){
        if(jaga==player[i]){
            lp=i;
            break;
        }
    }
    bool kalah[] = {0,0,0,0};
    for(int i=0; i<loc[lp].size(); i++){
        if(!kalah[0] && 
            i < loc[0].size() && loc[lp][i] == loc[0][i])
            kalah[0] = 1;
        if(!kalah[1] && 
            i < loc[1].size() && loc[lp][i] == loc[1][i])
            kalah[1] = 1;
        if(!kalah[2] &&
            i < loc[2].size() && loc[lp][i] == loc[2][i])
            kalah[2] = 1;
        if(!kalah[3] &&
            i < loc[3].size() && loc[lp][i] == loc[3][i])
            kalah[3] = 1;
    }
    kalah[lp]=0;
    vector<string> sikalah;
    int yangkalah = kalah[0] + kalah[1] + kalah[2] + kalah[3];
    if(yangkalah==0)
        cout << jaga << " jaga lagi";
    else{
        for(int i=0; i<4; i++)
            if(kalah[i]) sikalah.push_back(player[i]);
    }
    if(sikalah.size()==1)
        cout << sikalah[0] << " ditangkap oleh " << jaga;
    else if(sikalah.size()==2)
        cout << sikalah[0] << ", dan " << sikalah[1]
         << " ditangkap oleh " << jaga;
    else if(sikalah.size()==3)
        cout << sikalah[0] << ", " << sikalah[1] << ", dan " << sikalah[2]
         << " ditangkap oleh " << jaga;

    return 0;
}
// for(auto i:loc[0]){
//     cout << i << " ";
// }
// cout << endl;
// for(auto i:loc[1]){
//     cout << i << " ";
// }
// cout << endl;
// for(auto i:loc[2]){
//     cout << i << " ";
// }
// cout << endl;
// for(auto i:loc[3]){
//     cout << i << " ";
// }
// cout << endl;