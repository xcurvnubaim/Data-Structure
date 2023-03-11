#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(a,b) (a<b) ? (a) : (b);
// typedef struct data_t
// {
//     int num,count;
// }Data;


typedef struct _nodes_t
{
    int data;
    struct _nodes_t *prev;
}Nodes;


typedef struct list_t
{
    Nodes *tail;
    unsigned _size;
}List;

void list_init(List*);
void push_back(List*,int);
// void push_front(List*,Data);
// void pop_front(List*);
void pop_back(List*);
int isEmpty(List*);
Nodes *create_nodes(int);

int isEmpty(List *list){
    return(
        list->tail==NULL
    );
}

Nodes *create_nodes(int value){
    Nodes *new_nodes = (Nodes*) malloc(sizeof(Nodes));
    new_nodes->data = value;
    new_nodes->prev = NULL;
    return new_nodes;
}

void list_init(List* list){
    list->tail = NULL;
    list->_size = 0;
}

void push_back(List* list, int value){
    Nodes *temp = create_nodes(value);
    if(isEmpty(list)){
        list->tail = temp;
    } else {
        temp->prev = list->tail;
        list->tail = temp;
    }
    list->_size++;
    }

void pop_back(List *list){
    Nodes *temp = list->tail;
    if(list->_size==1){
        list->tail = NULL;
    } else {
        list->tail = list->tail->prev;
    }
    free(temp);
    list->_size--;
}

// Data setData(int num,int count){
//     Data newData;
//     newData.num = num;
//     newData.count = count;
//     return newData;
// }

int main(){
    List list;
    // Data data;
    char str[4];
    list_init(&list);
    int N,x;
    long long sum=0;
    push_back(&list,10001); //sentinel
    scanf("%d",&N);
    while(N--){
        scanf("%d",&x);
        while (list._size>0 && list.tail->data<x)
        {
            pop_back(&list);
            sum+=min(list.tail->data,x);
        }
        push_back(&list,x);
    }
    for(Nodes *i=list.tail->prev; i->data!=10001; i = i->prev)
        sum+= i->data;
    
    printf("%lld\n",sum);
    return 0;
}