#include <stdio.h>
#define INF 0x3f3f3f3f
int diamonds[100001];
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++){
        scanf("%d", &diamonds[i]);
    }
    int minTotal = INF;
    int curTotal = 0;
    int flag = 1; //If it is impossible to pay the exact amount
    for(int i = 1, j = 1; i <= N; i++){
        if(i > 1){
            curTotal -= diamonds[i-1];
            curTotal -= diamonds[j];
        }
        for(; j <= N; j++){
            curTotal += diamonds[j];
            if(curTotal == M){
                flag = 0;
                printf("%d-%d\n", i, j);
                break;
            } else if(curTotal > M){
                if(minTotal > curTotal){
                    minTotal = curTotal;
                }
                break;
            }
        }
    }
    if(flag){
        curTotal = 0;
        for(int i = 1, j = 1; i <= N; i++){
            if(i > 1){
                curTotal -= diamonds[i-1];
                curTotal -= diamonds[j];
            }
            for(; j <= N; j++){
                curTotal += diamonds[j];
                if(curTotal == minTotal){
                    printf("%d-%d\n", i, j);
                    break;
                } else if(curTotal > M){
                    break;
                }
            }
        }
    }
    return 0;
}
