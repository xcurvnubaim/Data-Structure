#include <bits/stdc++.h>
using namespace std;

typedef struct data_t
{
    int num,count;
}Data;

int main(){
    // List list;
    stack<Data> mystack;
    Data data;
    long long s=0;
    // char str[4];
    string str;
    // list_init(&list);
    int N;
    // scanf("%d",&N);
    cin >> N;
    while(N--){
        int num,c=1;
        // scanf("%d",&num);
        cin >> num;
        while (!mystack.empty() && mystack.top().num<=num)
        {
            c += mystack.top().count;
            // pop_back(&list);
            mystack.pop();
        }
        // data = setData(num,c);
        data.num = num; data.count=c;
        mystack.push(data);
        s+=c;
    }
    // printf("%lld\n",s);
    cout << s << endl;
    return 0;
}