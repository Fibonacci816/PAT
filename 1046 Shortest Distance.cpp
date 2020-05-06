#include <stdio.h>

int cumDistances[100001]; //存放第一个出口到第下标个出口的距离，下标0处存放环路总长度

void swap(int * a, int * b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int N, M;
    int exit1, exit2;
    int distance, shortestDistance;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &distance);
        if(i < N){
            cumDistances[i+1] = cumDistances[i] + distance;
        } else {
            cumDistances[0] = cumDistances[N] + distance;
        }
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &exit1, &exit2);
        if(exit1 > exit2){
            swap(&exit1, &exit2);
        }
        shortestDistance = cumDistances[exit2]-cumDistances[exit1] < cumDistances[0]-(cumDistances[exit2]-cumDistances[exit1]) ? cumDistances[exit2]-cumDistances[exit1] : cumDistances[0]-(cumDistances[exit2]-cumDistances[exit1]);
        printf("%d\n", shortestDistance);
    }
    return 0;
}
