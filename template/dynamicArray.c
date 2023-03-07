#include <stdio.h>
#include <stdlib.h>

typedef struct{
    long long *arr;
    unsigned __size;
} DynamicArray;

void dyArr_init(DynamicArray*);
// void dyArr_push_back(DynamicArray*, int);
void dyArr_get_idx(DynamicArray*, int);
void dyArr_increment(DynamicArray*, int, long long);

void dyArr_init(DynamicArray *dyArr){
    dyArr->arr = NULL;
    dyArr->__size = 0;
}

void dyArr_increment(DynamicArray* dyArr, int index, long long data){
    if(index < dyArr->__size){
        dyArr->arr[index] += data;
    }
}