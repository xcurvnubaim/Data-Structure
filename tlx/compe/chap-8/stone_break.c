#include <stdio.h>
#define min(a,b) (a<b) ? (a) : (b);

int main(){
    long long n,x,stack[10002],top=0,sum=0;
    
    //sentinel
    stack[0] = 10001;

    scanf("%lld",&n);
    while(n--){
        scanf("%d",&x);
        while (~top && stack[top]<x)
        {
            top--;
            sum+=min(stack[top],x);
        }
        stack[++top] = x;
    }
    for(int i=1; i<top; i++) sum+=stack[i];
    printf("%lld\n",sum);
    return 0;
}