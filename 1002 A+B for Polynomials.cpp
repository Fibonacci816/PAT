#include <stdio.h>
int main(void)
{
    int termNum;
    int exp;
    float coef;
    float result[1001];
    int resultNum = 0;
    for(int i = 0; i < 1001; i++){
    	result[i] = 0.0;
	}
    for(int i = 0; i < 2; i++){
        scanf("%d", &termNum);
        for(int j = 0; j < termNum; j++){
            scanf("%d %f", &exp, &coef);
            if(result[exp] == 0){
                resultNum++;
                result[exp] = coef;
            } else {
                result[exp] += coef;
                if(result[exp] == 0){
                    resultNum--;
                }
            }
        }
    }
    printf("%d", resultNum);
    for(int k = 1000; k >= 0; k--){
        if(result[k] != 0){
            printf(" %d", k);
            printf(" %.1f", result[k]);
        }
    }
    return 0;
}
