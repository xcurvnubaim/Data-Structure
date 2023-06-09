#include <bits/stdc++.h>
using namespace std;

char board[5][5], temp[5][5];
bool isfound=false;

void reset_board(vector<vector<bool>> &visited){
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++){
            // board[i][j] = temp[i][j];
            visited[i][j] = false;
        }
}

void solve(deque<char> q, int i, int j, vector<vector<bool>> visited){
    visited[i][j] = true;
    // board[i][j] = '#';
    if(q.empty()) isfound = true;
    if(isfound) return;
    char u = q.front(); q.pop_front();
    if(i!=0 && board[i-1][j]==u && !visited[i-1][j]){
        solve(q, i-1, j, visited);
    }
    if(j!=0 && board[i][j-1]==u && !visited[i][j-1]){
        solve(q, i, j-1, visited);
    }
    if(i!=4 && board[i+1][j]==u && !visited[i+1][j]){
        solve(q, i+1, j, visited);
    }
    if(j!=4 && board[i][j+1]==u && !visited[i][j+1]){
        solve(q, i, j+1, visited);
    }
}

int main(){
    string str;
    for(int i=0; i<5; i++){
        cin >> str;
        for(int j=0; j<5; j++){
            temp[i][j] = board[i][j] = str[j];
        }
    }

    cin >> str;
    deque<char> text;
    for(int i=0; i<str.size(); i++)
        text.push_back(str[i]);
    vector<vector<bool>> visited(5,vector<bool>(5, false));
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            char temp = text.front();
            if(board[i][j]==temp){
                // reset_board(visited);
                text.pop_front();
                solve(text, i, j, visited);
                text.push_front(temp);
            }
        }
    }

    if(isfound)
        cout << "Me have big brain." << endl;
    else
        cout << "I find myself unable to locate the desired word, shame on me." << endl;
    return 0;
}