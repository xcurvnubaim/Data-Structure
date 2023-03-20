#include <stdio.h>

void add();
void del();
void rev();
void debug();

int queue[2002][2];
int front,rear,queue_c,is_reversed;

int main(){
    is_reversed= queue_c=0;
    front = rear = 1000;
    int n;
    scanf("%d",&n);
    while (n--)
    {
        char str[4];
        scanf("%s",str);
        if(*str == 'a') add();
        else if(*str == 'd') del();
        else rev();
        // debug();
    }
    return 0;
}

void add(){
    int x,y;
    scanf("%d%d",&x,&y);
    if(queue_c){
        is_reversed ? rear-- : rear++;
        queue[rear][0] = x;
        queue[rear][1] = y;  
    }else {
        queue[front][0] = x;
        queue[front][1] = y;  
    }
    queue_c += y;
    printf("%d\n", queue_c);
}

void del(){
    printf("%d\n", queue[front][0]);
    int x;
    scanf("%d",&x);
    if(queue_c){
        queue_c -= x;
        if(queue_c < 0) {
            x += queue_c;
            queue_c = 0;
        }

        while (x)
        {
            if(x >= queue[front][1]){
                x-= queue[front][1];
                if(is_reversed){
                    front--;
                } else {
                    front++;
                }
            } else {
                queue[front][1] -= x;
                x=0;
            }
        }
    }
}

void rev(){
    int temp;
    temp = front;
    front = rear;
    rear = temp;
    is_reversed = !is_reversed;
}

void debug(){
    printf("\n%d %d %d %d\nqueue: ", front, rear, is_reversed,queue_c);
    for (int i = front; i <= rear; i++) printf("%d-%d ",queue[i][0],queue[i][1]);
    printf("\n");
    for (int i = front; i >= rear; i--) printf("%d-%d ",queue[i][0],queue[i][1]);
    printf("\n");
}