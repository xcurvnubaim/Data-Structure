#include <stdio.h>
#include <string.h>

int arr[20002];
int begin,end,is_empty;

void push_front();
void push_back();
void pop_front();
void pop_back();

int main(){
    is_empty = 1;
    int N;
    char c[20];
    scanf("%d",&N);
    while(N--){
        scanf("%s",c);
        if(strcmp(c,"push_front")==0){
            push_front();
            is_empty=0;
        } else if (strcmp(c,"push_back")==0) {
            push_back();
            is_empty=0;
        } else if (strcmp(c,"pop_front")==0) {
            pop_front();
        } else {
            pop_back();
        }
    }
    
    for (int i = begin; i < end; i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}

void push_front(){
    int x;
    scanf("%d",&x);
    if(is_empty){
        begin=10001;
        end = 10002;
        arr[begin] = x;
    } else {
        begin--;
        arr[begin] = x;
    }
}

void push_back(){
    int x;
    scanf("%d",&x);
    if(is_empty){
        begin=10001;
        end=10002;
        arr[begin] = x;
    } else {
        arr[end] = x;
        end++;
    }
}

void pop_back(){
    if(!is_empty)
        end--;
    if(begin==end) is_empty=1;
}

void pop_front(){
    if(!is_empty)
        begin++;
    if(begin==end) is_empty=1;
}