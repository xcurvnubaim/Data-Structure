#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int main(){
    stack<int> stac;
    stac.push(2);
    cout << stac.top() << "\n";
    stac.pop();
    cout << stac.top() << "\n";
    return 0;
}