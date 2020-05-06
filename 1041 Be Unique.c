#include <stdio.h>

int numbers[100000];
int IsUnique(int n, int index)
{
    for(int i = 0; i < n; i++){
        if(i != index && numbers[i] == numbers[index]){
            return 0;
        }
    }
    return 1;
}
int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &numbers[i]);
    }
    int flag = 1;
    for(int i = 0; i < N; i++){
        if(IsUnique(N, i)){
            printf("%d", numbers[i]);
            flag = 0;
            break;
        }
    }
    if(flag){
        printf("None");
    }
}
