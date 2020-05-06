#include <stdio.h>
#include <math.h>
int ToBase(int n, int base); //十进制转为对应的进制返回位数，并将各位数字逆序保存在数组a中
int IsPalindromic(int digitNum); //判断是否回文
int a[32]; //保存十进制数的其他进制的各位数字(逆序)
int main()
{
    int N, b, digitNum;
    scanf("%d %d", &N, &b);
    digitNum = ToBase(N, b);
    if(IsPalindromic(digitNum)){
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    for(int i = 0; i < digitNum; i++){
        printf("%d", a[digitNum -1 -i]);
        if(i != digitNum - 1){
            printf(" ");
        }
    }
    return 0;
}
int ToBase(int n, int base)
{
    int digitNum = 0;
    while(n > 0){
        a[digitNum++] = n % base;
        n /= base;
    }
    return digitNum;
}
int IsPalindromic(int digitNum)
{
    for(int i = 0; i < digitNum / 2; i++){
        if(a[i] != a[digitNum - 1 - i]){
            return 0;
        }
    }
    return 1;
}
