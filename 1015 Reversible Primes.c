#include <stdio.h>
#include <string.h>
#include <math.h>
int CalculateReverseValue(int n, int radix); //�õ���ת���ֵ��ʮ���ƣ�
int IsPrime(int n); //�ж�һ��ʮ�������Ƿ�������
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
    //�ú���Ϊ��ʮ����תΪ��ת���������ƺ���������תΪʮ���Ƶ��ۺ�
    int value = 0;
    //ѭ������ͬʱ���н�ʮ����תΪ��ת���������ƺ���������תΪʮ���Ƶ����ֲ���
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
