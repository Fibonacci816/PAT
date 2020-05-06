#include <stdio.h>
#include <string.h>
#include <math.h>
int CalculateReverseValue(int n, int radix); //得到反转后的值（十进制）
int IsPrime(int n); //判断一个十进制数是否是素数
int main()
{
    int N, D;
    int reverseValue;
    scanf("%d", &N);
    while(N >= 0){
        scanf("%d", &D);
        reverseValue = CalculateReverseValue(N, D);
        if(IsPrime(N) && IsPrime(reverseValue)){
            printf("Yes\n");
        } else {
            printf("No\n");
        }
        scanf("%d", &N);
    }
    return 0;
}
int CalculateReverseValue(int n, int radix)
{
    //该函数为将十进制转为反转的其他进制和其他进制转为十进制的综合
    int value = 0;
    //循环体内同时进行将十进制转为反转的其他进制和其他进制转为十进制的两种操作
    while(n > 0){
        value = value * radix + n % radix;
        n /= radix;
    }
    return value;
}
int IsPrime(int n)
{
    if(n < 2){
        return 0;
    }
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}
