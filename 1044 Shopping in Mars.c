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
    int curTotal;
    int flag = 1;
    for(int i = 1; i <= N; i++){
        curTotal = 0;
        for(int j = i; j <= N; j++){
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
        for(int i = 1; i <= N; i++){
            curTotal = 0;
            for(int j = i; j <= N; j++){
                curTotal += diamonds[j];
                if(curTotal == minTotal){
                    printf("%d-%d\n", i, j);
                    break;
                }
            }
        }
    }
    return 0;
}
