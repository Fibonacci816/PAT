#include <stdio.h>
#include <math.h>
int ToBase(int n, int base); //ʮ����תΪ��Ӧ�Ľ��Ʒ���λ����������λ�������򱣴�������a��
int IsPalindromic(int digitNum); //�ж��Ƿ����
int a[32]; //����ʮ���������������Ƶĸ�λ����(����)
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
