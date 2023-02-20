#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
    int max,min;
} Stack;

void stack_init(Stack *stack){
    stack->max = 1<<31;
    stack->min = ~(stack->max);
}

int stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;
        stack->_top = newNode;
    }
    if(value > stack->max) stack->max = value;
    if(value < stack->min) stack->min = value;
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

int main(){
    Stack stack;
    stack_init(&stack);
    int n,x; 
    char str[5];
    scanf("%d",&n);
    while(n--){
        scanf("%s",str);
        if(strcmp(str,"push")==0){
            scanf("%d",&x);
            stack_push(&stack,x);
        } else if(strcmp(str,"pop")==0){
            stack_pop(&stack);
        } else if(strcmp(str,"top")==0){
            x = stack_top(&stack);
            if(x) printf("%d\n",x);
        } else if(strcmp(str,"min")==0){
            printf("%d\n",stack.min);
        } else {
            printf("%d\n",stack.max);
        }
    }
    return 0;
}