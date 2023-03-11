#include <stdio.h>

int main(){
    long long s=0,N,arr[100002][2];
    scanf("%d",&N);
    int top_idx=0;
    while (N--){
        long long num,c=1;
        scanf("%d",&num);
        while (top_idx != 0 && arr[top_idx][0]<=num)
        {
            c += arr[top_idx][1];
            top_idx--;
        }
        top_idx++;
        arr[top_idx][0] = num;
        arr[top_idx][1] = c;
        s+=c;
    }
    printf("%lld\n",s);
    return 0;
}