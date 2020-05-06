#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int riginal[21]; //存放输入整数的各位
int doubled[21]; //存放输入整数2倍的各位
char doubledStr[22]; //输入整数2倍的字符串形式
int cmpfunc (const void * a, const void * b)
{
   return ( *(int *)a - *(int *)b );
}
int main()
{
    char number[21];
    int digit, flag = 0;
    scanf("%s", number);
    for(int i = 0; i < strlen(number); i++){
        riginal[i] = number[i] - '0';
    }
    if(riginal[0] >= 5){
        doubledStr[strlen(number)+1] = '\0';
        for(int i = strlen(number)-1; i >= 0; i--){
            digit = riginal[i] * 2 + flag;
            doubled[i+1] = digit % 10;
            doubledStr[i+1] = digit % 10 + '0';
            flag = digit / 10;
        }
        doubledStr[0] = flag + '0';
        printf("No\n");
    } else {
        doubledStr[strlen(number)] = '\0';
        for(int i = strlen(number)-1; i >= 0; i--){
            digit = riginal[i] * 2 + flag;
            doubled[i] = digit % 10;
            doubledStr[i] = digit % 10 + '0';
            flag = digit / 10;
        }
        //先排序再比较每一位；也可以保存每位数字出现的次数，比较0~9所有数字出现的次数是否相同
        qsort(riginal, strlen(number), sizeof(int), cmpfunc);
        qsort(doubled, strlen(number), sizeof(int), cmpfunc);
        flag = 1;
        for(int i = 0; i < strlen(number); i++){
            if(riginal[i] != doubled[i]){
                flag = 0;
                break;
            }
        }
        if(flag){
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    printf("%s", doubledStr);
    return 0;
}
