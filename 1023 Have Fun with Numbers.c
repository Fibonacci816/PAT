#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int riginal[21]; //������������ĸ�λ
int doubled[21]; //�����������2���ĸ�λ
char doubledStr[22]; //��������2�����ַ�����ʽ
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
        //�������ٱȽ�ÿһλ��Ҳ���Ա���ÿλ���ֳ��ֵĴ������Ƚ�0~9�������ֳ��ֵĴ����Ƿ���ͬ
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
