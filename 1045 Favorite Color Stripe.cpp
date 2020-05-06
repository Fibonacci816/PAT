#include <stdio.h>

int given[10001];
int favorite[201];
int dynamicLens[201][10001];

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int N, M, L;
    scanf("%d", &N);
    scanf("%d", &M);
    for(int i = 1; i <= M; i++){
        scanf("%d", &favorite[i]);
    }
    scanf("%d", &L);
    for(int i = 1; i <= L; i++){
        scanf("%d", &given[i]);
    }
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= L; j++){
            if(favorite[i] == given[j]){
                dynamicLens[i][j] = max(dynamicLens[i-1][j], dynamicLens[i][j-1]) + 1;
            } else {
                dynamicLens[i][j] = max(dynamicLens[i-1][j], dynamicLens[i][j-1]);
            }
        }
    }
    printf("%d", dynamicLens[M][L]);
    return 0;
}
