#include <bits/stdc++.h>
using namespace std;

int main(){
    // List list;
    stack<int> mystack;
    // Data data;
    // char str[4];
    string str;
    // list_init(&list);
    int N,x;
    long long sum=0;
    mystack.push(10001); //sentinel
    scanf("%d",&N);
    while(N--){
        scanf("%d",&x);
        while (mystack.size()>0 && mystack.top()<x)
        {
            // pop_back(&stack);
            mystack.pop();
            sum+=min(mystack.top(),x);
        }
        // push_back(&list,x);
        mystack.push(x);
    }
    // for(Nodes *i=list.tail->prev; i->data!=10001; i = i->prev)
    //     sum+= i->data;
    mystack.pop();
    while(mystack.size()>1){
        sum += mystack.top();
        mystack.pop();
    }
    // printf("%lld\n",sum);
    cout << sum << "\n";
    return 0;
}