#include <stdio.h>
#define SIZE 100
// stack
char stack[SIZE];
int top;
void push_back(char);
char pop_back();


int main(){
    top=0;
    int isvalid=1;
    char c;
    while(isvalid && scanf("%c",&c)==1){
        if(!(c=='(' || c==')' || c=='{' || c=='}' || c=='[' || c==']')) continue;
        if(c=='(' || c=='[' || c=='{')
            push_back(c);
        else {
            char temp = pop_back();
            if(!((c==')' && temp=='(') || 
                (c==']' && temp=='[') ||
                (c=='}' && temp=='{')))
                isvalid=0;
        }
    }
    if(isvalid && top==0) printf("Valid Parentheses\n");
    else printf("Not Valid Parentheses\n");

    return 0;
}

void push_back(char inp){
    stack[top] = inp;
    top++;
}

char pop_back(){
    top--;
    return stack[top];
}