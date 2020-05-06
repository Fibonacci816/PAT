#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void * a, const void *b){
    int i = 0, j = 0;
    while(*((char *)a+i) != '\0' || *((char *)b+j) != '\0'){
        if(*((char *)a+i) == '\0'){
            i = 0;
        }
        if(*((char *)b+j) == '\0'){
            j = 0;
        }
        if(*((char *)a+i) != *((char *)b+j)){
            return *((char *)a+i) - *((char *)b+j);
        }
        i++;
        j++;
    }
    return 0;
}
int main()
{
    int N;
    scanf("%d", &N);
    char numberSegments[N][9];
    for(int i = 0; i < N; i++){
        scanf("%s", numberSegments[i]);
    }
    qsort(numberSegments, N, sizeof(numberSegments[0]), cmp);
    int index1 = 0, index2 = 0;
    int flag = 1;
    for(index1 = 0; index1 < N; index1++){
        for(index2 = 0; numberSegments[index1][index2] != '\0'; index2++){
            if(numberSegments[index1][index2] != '0'){
                printf("%s", numberSegments[index1]+index2);
                flag = 0;
                break;
            }
        }
    }
    for(int i = index1 + 1; i < N; i++){
        printf("%s", numberSegments[i]);
    }
    if(flag){
        printf("%d", 0);
    }
    return 0;
}
