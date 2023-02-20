#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int stack[1002];
    int top = -1;
    while(n--){
        int x;
        scanf("%d",&x);
        while(x){
            top++;
            stack[top] = x % 2;
            if(top > 0 && stack[top]==stack[top-1]) top-=2;
            x >>= 1;
        }
        int sum = 0;
        while (top >= 0)
        {
            sum += (1<<top)*stack[top];
            top--;
        }
        printf("%d\n",sum);
    }
    return 0;
}