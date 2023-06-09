#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#define max_size 3002
double PI = acos(-1.0);


int n;
typedef struct {
    long long x,y,r;
} circle;

circle CIRCLES[max_size];  

double key[max_size], temp;
int main(){
    while(scanf("%d",&n)==1 && n!=-1){
        for(int i=0; i<n; i++){
            scanf("%lld%lld%lld", &CIRCLES[i].x, &CIRCLES[i].y, &CIRCLES[i].r);         
        }
        int mstSet[n];
        for (int i = 0; i < n; i++)
            key[i] = 1e18, mstSet[i] = 0;
        key[0] = 0;
        for (int count = 0; count < n; count++) {
            double min = 1e18;
            int u;
            for (int k = 0; k < n; k++)
                if (mstSet[k] == 0 && key[k] < min)
                    min = key[k], u = k;
            
            mstSet[u] = 1;
            double x,y,d, tali=0;
            for (int v = 0; v < n; v++){
                if (mstSet[v] == 0){
                    d = (CIRCLES[u].x-CIRCLES[v].x)*(CIRCLES[u].x-CIRCLES[v].x) 
                        + (CIRCLES[u].y-CIRCLES[v].y)*(CIRCLES[u].y-CIRCLES[v].y);
                    x = acos((CIRCLES[u].r - CIRCLES[v].r)/ sqrt(d));
                    y = PI-x;
                    tali = 
                        2*(y*CIRCLES[u].r + x*CIRCLES[v].r) + 2*sqrt(
                            -(CIRCLES[u].r-CIRCLES[v].r)*(CIRCLES[u].r-CIRCLES[v].r) + d
                        );
                    if(tali < key[v])
                        key[v] = tali;
                }
            }
        }
    
        
        double res;
        res = 0.0;
        for(int i=0; i<n; i++){
            res += key[i];
        }
        printf("%.3lf\n", res);

    }
    return 0;
}