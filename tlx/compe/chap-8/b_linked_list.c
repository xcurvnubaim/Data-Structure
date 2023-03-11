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
    struct _nodes_t *next,*prev;
}Nodes;


typedef struct list_t
{
    Nodes *head,*tail;
    unsigned _size;
}List;

void list_init(List*);
void push_back(List*,Data);
void push_front(List*,Data);
void pop_front(List*);
void pop_back(List*);
int isEmpty(List*);
Nodes *create_nodes(Data);

int isEmpty(List *list){
    return(
        list->head==NULL && list->tail==NULL
    );
}

Nodes *create_nodes(Data value){
    Nodes *new_nodes = (Nodes*) malloc(sizeof(Nodes));
    new_nodes->data = value;
    new_nodes->next = NULL;
    new_nodes->prev = NULL;
    return new_nodes;
}

void list_init(List* list){
    list->head = list->tail = NULL;
    list->_size = 0;
}

void push_back(List* list, Data value){
    Nodes *temp = create_nodes(value);
    if(isEmpty(list)){
        list->head = list->tail = temp;
    } else {
        temp->prev = list->tail;
        list->tail->next = temp;
        list->tail = temp;
    }
    list->_size++;
    }

void push_front(List* list, Data value){
    Nodes *temp = create_nodes(value);
    if(isEmpty(list)){
        list->head = list->tail = temp;
        return;
    } else {
        temp->next = list->head;
        list->head->prev = temp;
        list->head = temp;
    }
    list->_size++;
}

void pop_back(List *list){
    Nodes *temp = list->tail;
    if(list->head==list->tail){
        list->head = list->tail = NULL;
    } else {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    free(temp);
    list->_size--;
}

void pop_front(List *list){
    Nodes *temp = list->head;
    if(list->head==list->tail){
        list->head = list->tail = NULL;
    } else {
        list->head = list->head->next;
        list->head->prev = NULL;
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
    int isReversed=0,queue_c=0,x,y;
    list_init(&list);
    int N;
    scanf("%d",&N);
    while(N--){
        char str[4];
        scanf("%s",str);
        if(*str == 'a'){
            scanf("%d%d",&x,&y);
            data = setData(x,y);
            isReversed ? push_front(&list, data) : push_back(&list, data);
            queue_c += y;
            printf("%d\n", queue_c);
        }
        else if(*str == 'd'){
            printf("%d\n", isReversed ? list.tail->data.num : list.head->data.num);
            scanf("%d",&x);
            if(queue_c){
                queue_c -= x;
                if(queue_c < 0) {
                    x += queue_c;
                    queue_c = 0;
                }

                while (x)
                {
                    if(isReversed){
                        if(x >= list.tail->data.count){
                            x-= list.tail->data.count;
                            pop_back(&list);
                        } else {
                            list.tail->data.count -= x;
                            x=0;
                        }
                    } else {
                        if(x >= list.head->data.count){
                            x-= list.head->data.count;
                            pop_front(&list);
                        } else {
                            list.head->data.count -= x;
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