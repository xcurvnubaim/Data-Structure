#include <bits/stdc++.h>
using namespace std;
typedef struct data_t
{
    int num,count;
}Data;

int main(){
    list<Data> mylist;
    Data data;
    int isReversed=0,queue_c=0,x,y;
    int N;
    // scanf("%d",&N);
    cin >> N;
    while(N--){
        // char str[4];
        string str;
        // scanf("%s",str);
        cin >> str;
        if(str[0] == 'a'){
            cin >> data.num >> data.count;
            // scanf("%d%d",&x,&y);
            // data = setData(x,y);
            isReversed ? mylist.push_front(data) : mylist.push_back(data);
            queue_c += data.count;
            printf("%d\n", queue_c);
        }
        else if(str[0] == 'd'){
            cout << (isReversed ? mylist.back().num : mylist.front().num) << "\n";
            // scanf("%d",&x);
            cin >> x;
            if(queue_c){
                queue_c -= x;
                if(queue_c < 0) {
                    x += queue_c;
                    queue_c = 0;
                }

                while (x)
                {
                    if(isReversed){
                        if(x >= mylist.back().count){
                            x-= mylist.back().count;
                            mylist.pop_back();
                        } else {
                            mylist.back().count -= x;
                            x=0;
                        }
                    } else {
                        if(x >= mylist.front().count){
                            x-= mylist.front().count;
                            mylist.pop_front();
                        } else {
                            mylist.front().count -= x;
                            x=0;
                        }
                    }
                }
            }
        }
        else isReversed = !isReversed;
    }
    
    return 0;
}