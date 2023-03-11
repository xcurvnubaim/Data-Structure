#include <bits/stdc++.h>
using namespace std;

typedef struct data_t
{
    int num,count;
}Data;

int main(){
    // List list;
    list<Data> mylist;
    Data data;
    int stack_c=0,x,y;
    // char str[4];
    string str;
    // list_init(&list);
    int N;
    // scanf("%d",&N);
    cin >> N;
    while(N--){
        // scanf("%s",str);
        cin >> str;
        if(str=="add"){
            // scanf("%d%d",&x,&y);
            // data = setData(x,y);
            cin >> data.num >> data.count;
            mylist.push_back(data);
            stack_c += data.count;
            // printf("%d\n", stack_c);
            cout << stack_c << "\n";
        } else {
            cin >> x;
            if(str=="del"){
                if(mylist.empty()) continue;
                // printf("%d\n", list.tail->data.num);
                cout << mylist.back().num << endl;
                stack_c -= x;
                if(stack_c < 0) {
                    x += stack_c;
                    stack_c = 0;
                }
                while (x)
                {
                    if(x >= mylist.back().count){
                        x-= mylist.back().count;
                        // pop_back(&list);
                        mylist.pop_back();
                    } else {
                        mylist.back().count -= x;
                        x=0;
                    }
                }
            } else if(str=="adx")
                for(auto i=mylist.begin() ; i!=mylist.end();i++)
                    i->num+=x;
              else
                for(auto i=mylist.begin() ; i!=mylist.end();i++)
                    i->num-=x;
        }
    }
    
    return 0;
}