#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    string str;
    cin >> n >> m;
    char mp[n][m];
    for(int i=0; i<n; i++){
        cin >> str;
        for(int j=0; j<m; j++){
            mp[i][j] = str[j];
        }
    }
    cin >> str;
    for(int a=0; a<str.size(); a++){
        char cmd;
        cmd = str[a];
        pair<int,int> temp;
        if(cmd == 'w'){
            for(int i=0; i<n; i++)
                for(int j=0; j<m; j++){
                temp = make_pair(i,j);
                if(mp[temp.first][temp.second]=='*'){
                    if(temp.first==0 || 
                        mp[temp.first-1][temp.second]=='o' ) 
                        continue;
                    else if(mp[temp.first-1][temp.second]=='*'){
                        mp[temp.first][temp.second] = '.';
                        mp[temp.first-1][temp.second] = '.';
                    } else {
                        mp[temp.first][temp.second] = '.';
                        mp[temp.first-1][temp.second] = '*';
                    }
                }
            }
        } else if(cmd == 'a'){
           for(int j=0; j<m; j++)
                for(int i=0; i<n; i++){
                temp = make_pair(i,j);
                if(mp[temp.first][temp.second]=='*'){
                    if(temp.second==0 || 
                        mp[temp.first][temp.second-1]=='o' ) 
                        continue;
                    else if(mp[temp.first][temp.second-1]=='*'){
                        mp[temp.first][temp.second] = '.';
                        mp[temp.first][temp.second-1] = '.';
                    } else {
                        mp[temp.first][temp.second] = '.';
                        mp[temp.first][temp.second-1] = '*';
                    }
                }
            }
        } else if(cmd == 's'){
           for(int i=n-1; i>=0; i--)
                for(int j=0; j<m; j++){
                temp = make_pair(i,j);
                if(mp[temp.first][temp.second]=='*'){
                    if(temp.first==n-1 || 
                        mp[temp.first+1][temp.second]=='o' ) 
                        continue;
                    else if(mp[temp.first+1][temp.second]=='*'){
                        mp[temp.first][temp.second] = '.';
                        mp[temp.first+1][temp.second] = '.';
                    } else {
                        mp[temp.first][temp.second] = '.';
                        mp[temp.first+1][temp.second] = '*';
                    }
                }
            }
        } else if(cmd == 'd') {
            for(int j=m-1; j>=0; j--)
                for(int i=0; i<n; i++){
                temp = make_pair(i,j);
                if(mp[temp.first][temp.second]=='*'){
                    if(temp.second==m-1 || 
                        mp[temp.first][temp.second+1]=='o' ) 
                        continue;
                    else if(mp[temp.first][temp.second+1]=='*'){
                        mp[temp.first][temp.second] = '.';
                        mp[temp.first][temp.second+1] = '.';
                    } else {
                        mp[temp.first][temp.second] = '.';
                        mp[temp.first][temp.second+1] = '*';
                    }
                }
            }
        }
        // for(auto e:btg)
        //     cout << e.first << " " << e.second << endl;
        // cout << endl;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << mp[i][j];
        }
        cout << endl;
    }
    return 0;
}