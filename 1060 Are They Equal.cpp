#include <stdio.h>
#include <string.h>

typedef struct StandardFloat{
	char digits[101];
	int exponent10;
} StandardFloat;

int N;
char A[101];
char B[101];

StandardFloat Standard(char f[])
{
	StandardFloat standardFloat;
	int exponent10 = 0; //10的指数 
	char digits[101];  //有效数字 
	int i = 0, zeroNum = 0, zeroNum2 = 0, flag = 0; //zeroNum为开头0和.的位数，zeroNum2为.之前包括.一共有几位 
    while(f[i] == '0' || f[i] == '.'){
    	zeroNum++;
		if(f[i] == '.'){
    		flag =1;
            zeroNum2 = zeroNum;
		}
        i++; 
    }
    if(flag == 1 && f[i] != '\0'){ //小于1的非零数 
    	exponent10 = zeroNum2 - zeroNum;
	} else {
		for(i = zeroNum; f[i] != '\0'; i++){
	        if(f[i] == '.'){
	            break;
	        }
	        exponent10++;
	    }
	}    
	flag = 0;
    for(i = zeroNum; f[i] != '\0' && i-zeroNum-flag < N; i++){
        if(f[i] == '.'){
            flag = 1;
            continue;
        }
        digits[i-zeroNum-flag] = f[i];
    }
	while(i-zeroNum-flag < N){
		digits[i-zeroNum-flag] = '0';
        i++;
	}
	digits[N] = '\0';
	strcpy(standardFloat.digits, digits);
	standardFloat.exponent10 = exponent10;
	return standardFloat;
}

int main()
{
	scanf("%d %s %s", &N, A, B);
	StandardFloat resultA = Standard(A);
	StandardFloat resultB = Standard(B);
	if(strcmp(resultA.digits, resultB.digits)==0 && resultA.exponent10==resultB.exponent10){
		printf("YES 0.%s*10^%d", resultA.digits, resultA.exponent10);
	} else {
		printf("NO 0.%s*10^%d 0.%s*10^%d", resultA.digits, resultA.exponent10, resultB.digits, resultB.exponent10);
	}
	return 0;
}
