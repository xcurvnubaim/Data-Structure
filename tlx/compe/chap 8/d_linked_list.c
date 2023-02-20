#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data_t
{
    int num,count;
}Data;


typedef struct _nodes_t
{
    Data data;
    struct _nodes_t *prev;
}Nodes;


typedef struct list_t
{
    Nodes *tail;
    unsigned _size;
}List;

void list_init(List*);
void push_back(List*,Data);
// void push_front(List*,Data);
// void pop_front(List*);
void pop_back(List*);
int isEmpty(List*);
Nodes *create_nodes(Data);

int isEmpty(List *list){
    return(
        list->tail==NULL
    );
}

Nodes *create_nodes(Data value){
    Nodes *new_nodes = (Nodes*) malloc(sizeof(Nodes));
    new_nodes->data = value;
    new_nodes->prev = NULL;
    return new_nodes;
}

void list_init(List* list){
    list->tail = NULL;
    list->_size = 0;
}

void push_back(List* list, Data value){
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

Data setData(int num,int count){
    Data newData;
    newData.num = num;
    newData.count = count;
    return newData;
}

int main(){
    List list;
    Data data;
    long long s=0;
    char str[4];
    list_init(&list);
    int N;
    scanf("%d",&N);
    while(N--){
        int num,c=1;
        scanf("%d",&num);
        while (!isEmpty(&list) && list.tail->data.num<=num)
        {
            c += list.tail->data.count;
            pop_back(&list);
        }
        data = setData(num,c);
        push_back(&list, data);
        s+=c;
    }
    printf("%lld\n",s);
    return 0;
}