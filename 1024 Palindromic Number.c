#include <stdio.h>
#include <string.h>
char digits[50];
char digits2[50];
int IsPalindromic(char digits[]); //判断是否回文
int main()
{
    int M;
    int digitNum;
    int carryBit;
    int i;
    scanf("%s %d", digits, &M);
    for(i = 0; i <= M; i++){
        if(IsPalindromic(digits) || i == M){
            break;
        }
        carryBit = 0; //进位数
        digitNum = strlen(digits);
        for(int j = 0; j < digitNum; j++){
            digits2[j] = ((digits[j] - '0') + (digits[digitNum - 1 - j] - '0') + carryBit) % 10 + '0';
            carryBit = ((digits[j] - '0') + (digits[digitNum - 1 - j] - '0') + carryBit) / 10;
        }
        if(carryBit > 0){
            digits2[digitNum] = carryBit + '0';
            digits2[digitNum+1] = '\0';
            //更新digits
            digits[digitNum+1] = '\0';
            for(int j = 0; j < digitNum+1; j++){
                digits[digitNum - j] = digits2[j];
            }
        } else {
            digits2[digitNum] = '\0';
            //更新digits
            digits[digitNum] = '\0';
            for(int j = 0; j < digitNum; j++){
                digits[digitNum - 1 - j] = digits2[j];
            }
        }
    }
    printf("%s\n", digits);
    printf("%d", i);
    return 0;
}
int IsPalindromic(char digits[])
{
    int digitNum = strlen(digits);
    for(int i = 0; i < digitNum / 2; i++){
        if(digits[i] != digits[digitNum - 1 - i]){
            return 0;
        }
    }
    return 1;
}
