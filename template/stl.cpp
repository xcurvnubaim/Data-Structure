#include <iostream>
#include <stack>
#include <list>

using namespace std;
int main(){
    stack<int> stac;
    stac.push(2);
    cout << stac.top() << "\n";
    stac.pop();
    cout << stac.top() << "\n";
    return 0;
}