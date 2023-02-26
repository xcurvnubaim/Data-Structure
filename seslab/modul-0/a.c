#include <stdio.h>
#include <stdlib.h>


typedef struct _nodes_t
{
    int data;
    struct _nodes_t *next,*prev;
}Nodes;


typedef struct list_t
{
    Nodes *head,*tail;
    unsigned _size;
}List;

void list_init(List*);
void push_back(List*,int);
void push_front(List*,int);
void pop_front(List*);
void pop_back(List*);
int isEmpty(List*);
Nodes *create_nodes(int);

int isEmpty(List *list){
    return(
        list->head==NULL && list->tail==NULL
    );
}

Nodes *create_nodes(int value){
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

void push_back(List* list, int value){
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

void push_front(List* list, int value){
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


void forEachElement(List *list, void (*func)(int*)){
    for (Nodes* i = list->head; i != NULL; i = i->next)
    {
        func(&i->data);
    }
}

void printElement(int *elem){
    printf("%d ",*elem);
}

void multiply2(int *elem){
    (*elem)<<=1;
}

void reverseEach(int *elem){
    int temp=0;
    while (*elem)
    {
        temp = temp*10 + *elem%10;
        *elem/=10;
    }
    *elem = temp;
}

void sumDigit(int *elem){
    int temp=0;
    while (*elem)
    {
        temp += *elem%10;
        *elem/=10;
    }
    *elem = temp;
}

int main(){
    List list;
    list_init(&list);
    push_back(&list, 12);
    push_back(&list, 23);
    push_back(&list, 34);
    push_back(&list, 45);
    push_back(&list, 56);

    forEachElement(&list,printElement);
    puts("");
    forEachElement(&list,multiply2);
    forEachElement(&list,printElement);
    puts("");
    forEachElement(&list,reverseEach);
    forEachElement(&list,printElement);
    puts("");
    forEachElement(&list,sumDigit);
    forEachElement(&list,printElement);
    puts("");
    return 0;
}