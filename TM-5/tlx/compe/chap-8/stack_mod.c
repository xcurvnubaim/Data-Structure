#include <stdio.h>
#include <string.h>

int main(){
    int top,stack_c,n,x,y,stack[1002][2];
    char str[4];
    stack_c=0;
    top=-1;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%s",str);
        if(strcmp("add",str)==0){
            scanf("%d%d",&x,&y);
            top++;
            stack[top][0] = x;
            stack[top][1] = y;
            stack_c += y;
            printf("%d\n", stack_c);
        } else {
            scanf("%d",&x);
            if(strcmp("del",str)==0){
                printf("%d\n", stack[top][0]);
                stack_c -= x;
                if(stack_c < 0) {
                    x += stack_c;
                    stack_c = 0;
                }
                while (x)
                {
                    if(x >= stack[top][1]){
                        x-= stack[top][1];
                        top--;
                    } else {
                        stack[top][1] -= x;
                        x=0;
                    }
                }
            } else if(strcmp("adx",str)==0)
                for(int i=0;i<=top;i++)
                    stack[i][0]+=x;
              else
                for(int i=0;i<=top;i++)
                    stack[i][0]-=x;
        }
    }
    return 0;
}